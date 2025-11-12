#ifndef SYSTICK_h
#define SYSTICK_h

#define SYSTICK_CTRL   SYST_CSR
#define SYSTICK_LOAD   SYST_RVR
#define SYSTICK_VAL    SYST_CVR
#define SYSTICK_CALIB  SYST_CALIB

#define SYST_CSR_COUNTFLAG 16
#define SYST_CSR_CLKSOURCE 3
#define SYST_CSR_TICKINT   1
#define SYST_CSR_ENABLE    0

#define SYST_CSR     (volatile unsigned int *)(0xE000E010)
#define SYST_RVR     (volatile unsigned int *)(0xE000E014)
#define SYST_CVR     (volatile unsigned int *)(0xE000E018)
#define SYST_CALIB   (volatile unsigned int *)(0xE000E01C)

#endif
