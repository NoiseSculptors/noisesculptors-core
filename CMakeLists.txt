
cmake_minimum_required(VERSION 3.16)

project(noisesculptors_core C ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---- knobs --------------------------------------------------
set(BOARD ""     CACHE STRING "Board name (maps to an MCU); leave empty to set MCU directly")
set(MCU   "h750" CACHE STRING "Target MCU (one of: h750, l431)")
set(RUN   "axi"  CACHE STRING "Run profile: flash | axi | dtcm")
set(MPU   "${MCU}" CACHE STRING "Alias for MCU used by include layout")

# ---- BOARD → MCU map + guards --------------------------------
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

# ---- per-MCU flags -------------------------------------------
if(MCU STREQUAL "h750")
  set(ARCH_FLAGS -mthumb -mcpu=cortex-m7)
  set(FPU_FLAGS  -mfpu=fpv5-d16 -mfloat-abi=hard -fsingle-precision-constant)
elseif(MCU STREQUAL "l431")
  set(ARCH_FLAGS -mthumb -mcpu=cortex-m4)
  set(FPU_FLAGS  )
endif()
set(CPUFLAGS ${ARCH_FLAGS} ${FPU_FLAGS})

# ---- RUN profile → startup, linker, defines -------------------
if(RUN STREQUAL "flash")
  set(STARTUP startup/${MCU}/startup_flash.c)
  set(LINKER  ldscripts/${MCU}/linker_flash.ld)
  set(PROFILE_DEFS RUN_FROM_FLASH)
elseif(RUN STREQUAL "axi")
  set(STARTUP startup/${MCU}/startup_sram.c)
  set(LINKER  ldscripts/${MCU}/linker_axi.ld)
  set(PROFILE_DEFS RUN_AXI)
elseif(RUN STREQUAL "dtcm")
  set(STARTUP startup/${MCU}/startup_sram.c)
  set(LINKER  ldscripts/${MCU}/linker_dtcm.ld)
  set(PROFILE_DEFS RUN_DTCM)
else()
  message(FATAL_ERROR "RUN must be one of: flash, axi, dtcm (got '${RUN}')")
endif()

# ---- source discovery ----------------------------------------
file(GLOB_RECURSE SRCS_MCU
  CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/${MCU}/*.c
)
set(CORE_SRCS ${SRCS_MCU} ${CMAKE_CURRENT_SOURCE_DIR}/${STARTUP})

# ---- include paths -------------------------------------------
set(PUBLIC_INC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include/${MPU}
)

set(MCU_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/${MCU})
file(GLOB MCU_INC_DIRS LIST_DIRECTORIES true ${MCU_SRC_DIR}/*)
foreach(_p IN LISTS MCU_INC_DIRS)
  if(NOT IS_DIRECTORY "${_p}")
    list(REMOVE_ITEM MCU_INC_DIRS "${_p}")
  endif()
endforeach()
list(INSERT MCU_INC_DIRS 0 ${MCU_SRC_DIR})

# ---- OBJECT "core" -------------------------------------------
add_library(noisesculptors_${MCU} OBJECT ${CORE_SRCS})
add_library(noisesculptors::core ALIAS noisesculptors_${MCU})

target_include_directories(noisesculptors_${MCU}
  PUBLIC
    ${PUBLIC_INC}
    ${MCU_INC_DIRS}
)

set(WARN_FLAGS
  -Wall -Wextra -Wshadow -Wdouble-promotion -Wformat=2 -Wundef
  -Wstrict-prototypes -Wmissing-prototypes -Wredundant-decls
  -Wpointer-arith -Wcast-align -Wwrite-strings -Wstrict-overflow
)

# Compile options for these objects; export the same to consumers
target_compile_options(noisesculptors_${MCU}
  PUBLIC
    ${CPUFLAGS}
    ${WARN_FLAGS}
    -Os
    -flto
    -ffunction-sections
    -fdata-sections
    -fno-builtin
)

# Link-time LTO for final firmware consumers
target_link_options(noisesculptors_${MCU}
  PUBLIC
    -flto
    ${CPUFLAGS}
)

# Startup/profile defines: startup-only are PRIVATE; profile defs PUBLIC
target_compile_definitions(noisesculptors_${MCU}
  PRIVATE
    __STARTUP_CLEAR_BSS
    __START=main
    __NO_SYSTEM_INIT
  PUBLIC
    ${PROFILE_DEFS}
)

# Expose absolute linker script path as a property on the target
set(_LDS_ABS "${CMAKE_CURRENT_SOURCE_DIR}/${LINKER}")
set_property(TARGET noisesculptors_${MCU} PROPERTY NOISESCULPTORS_LDSCRIPT "${_LDS_ABS}")

