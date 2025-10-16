
cmake_minimum_required(VERSION 3.16)

# Cross: tell CMake we're bare-metal and to avoid linking during checks
set(CMAKE_SYSTEM_NAME Generic CACHE STRING "" FORCE)
set(CMAKE_SYSTEM_PROCESSOR arm CACHE STRING "" FORCE)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

project(noisesculptors C ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---- knobs (same as before) --------------------------------------------------
set(BOARD ""     CACHE STRING "Board name (maps to an MCU); leave empty to set MCU directly")
set(MCU   "h750" CACHE STRING "Target MCU (one of: h750, l431)")
set(RUN   "axi"  CACHE STRING "Run profile: flash | axi | dtcm")
set(MPU   "${MCU}" CACHE STRING "Alias for MCU used by include layout")

# If you prefer, pass compilers via toolchain file:
#   -DCMAKE_TOOLCHAIN_FILE=cmake/arm-none-eabi-gcc.cmake

# ---- BOARD → MCU map + guards ------------------------------------------------
set(VALID_MCUS h750 l431)
set(_BOARD_TO_MCU_calibrator750     h750)
set(_BOARD_TO_MCU_rocket_calibrator h750)
set(_BOARD_TO_MCU_herztick          l431)

if(NOT "${BOARD}" STREQUAL "")
  set(_map_var "_BOARD_TO_MCU_${BOARD}")
  if(NOT DEFINED ${_map_var})
    message(FATAL_ERROR "Unknown BOARD='${BOARD}'. Add mapping for it.")
  endif()
  set(MCU "${${_map_var}}" CACHE STRING "MCU derived from BOARD='${BOARD}'" FORCE)
endif()

list(FIND VALID_MCUS "${MCU}" _mcuidx)
if(_mcuidx EQUAL -1)
  message(FATAL_ERROR "MCU '${MCU}' not in [${VALID_MCUS}]")
endif()

if("${MPU}" STREQUAL "")
  set(MPU "${MCU}" CACHE STRING "Alias for MCU used by include layout" FORCE)
endif()

# ---- per-MCU flags -----------------------------------------------------------
if(MCU STREQUAL "h750")
  set(ARCH_FLAGS -mthumb -mcpu=cortex-m7)
  set(FPU_FLAGS  -mfpu=fpv5-d16 -mfloat-abi=hard -fsingle-precision-constant)
elseif(MCU STREQUAL "l431")
  # tweak as needed for L4
  set(ARCH_FLAGS -mthumb -mcpu=cortex-m4)
  set(FPU_FLAGS  ) # many L4 parts have no FPU; add if you use one
endif()
set(CPUFLAGS ${ARCH_FLAGS} ${FPU_FLAGS})

# ---- RUN profile → startup, linker, defines ---------------------------------
if(RUN STREQUAL "flash")
  set(STARTUP startup/${MCU}/startup_flash.c)
  set(LINKER  ldscripts/${MCU}/linker_flash.ld)
  set(PROFILE_DEFS RUN_FROM_FLASH)
elseif(RUN STREQUAL "axi")
  set(STARTUP startup/${MCU}/startup_sram.c)
  set(LINKER  ldscripts/${MCU}/linker_axi.ld)
  set(PROFILE_DEFS BOOTRAM RUN_AXI)
elseif(RUN STREQUAL "dtcm")
  set(STARTUP startup/${MCU}/startup_sram.c)
  set(LINKER  ldscripts/${MCU}/linker_dtcm.ld)
  set(PROFILE_DEFS BOOTRAM RUN_DTCM)
else()
  message(FATAL_ERROR "RUN must be one of: flash, axi, dtcm (got '${RUN}')")
endif()

# ---- source discovery (goodbye sub-Makefiles) --------------------------------
# Grab all .c under src/<MCU> (recursive) and add the chosen startup file.
file(GLOB_RECURSE SRCS_MCU
  CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/${MCU}/*.c
)
# Add STARTUP (can be .c or .S); don’t glob all start-ups to avoid duplicates.
set(CORE_SRCS ${SRCS_MCU} ${CMAKE_CURRENT_SOURCE_DIR}/${STARTUP})

# ---- include paths -----------------------------------------------------------
# 1) public includes (API)
set(PUBLIC_INC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include/${MPU}
)

# 2) per-MCU headers live in subfolders (e.g. src/h750/init/init.h); add first-level dirs.
set(MCU_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/${MCU})
file(GLOB MCU_INC_DIRS LIST_DIRECTORIES true ${MCU_SRC_DIR}/*)
# keep only directories
foreach(_p IN LISTS MCU_INC_DIRS)
  if(NOT IS_DIRECTORY "${_p}")
    list(REMOVE_ITEM MCU_INC_DIRS "${_p}")
  endif()
endforeach()
# also include the MCU root (handy if you place headers directly there)
list(INSERT MCU_INC_DIRS 0 ${MCU_SRC_DIR})

# 3) optional extras (match your old Makefile includes)
set(EXTRA_INC
  ${CMAKE_CURRENT_SOURCE_DIR}/external/UGUI
  ${CMAKE_CURRENT_SOURCE_DIR}/external/printf
  ${CMAKE_CURRENT_SOURCE_DIR}/drivers/display/ssd1315
  ${CMAKE_CURRENT_SOURCE_DIR}/drivers/display/ssd1315_UGUI
)

# ---- the library -------------------------------------------------------------
add_library(noisesculptors_${MCU} STATIC ${CORE_SRCS})
add_library(noisesculptors::core ALIAS noisesculptors_${MCU})

target_include_directories(noisesculptors_${MCU}
  PUBLIC
    ${PUBLIC_INC}
    ${MCU_INC_DIRS}
    ${EXTRA_INC}
)

# Warnings/opts (mirror your GCC flags)
set(WARN_FLAGS
  -Wall -Wextra -Wshadow -Wdouble-promotion -Wformat=2 -Wundef
  -Wstrict-prototypes -Wmissing-prototypes -Wredundant-decls
  -Wpointer-arith -Wcast-align -Wwrite-strings -Wstrict-overflow
)
target_compile_options(noisesculptors_${MCU}
  PRIVATE
    ${CPUFLAGS}
    ${WARN_FLAGS}
    -O3
    -flto
    -ffunction-sections -fdata-sections
    -fno-builtin
)

# Startup & profile defines
target_compile_definitions(noisesculptors_${MCU}
  PRIVATE
    __STARTUP_CLEAR_BSS
    __START=main
    __NO_SYSTEM_INIT
    ${PROFILE_DEFS}
)

