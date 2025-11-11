
#ifndef USB_H
#define USB_H

/*------------------------------- USB1_OTG_HS --------------------------------*/

/* --- Global registers --- */
#define USB1_OTG_HS_OTG_GOTGCTL        (volatile unsigned int *)(USB1_OTG_HS + 0x000)
#define USB1_OTG_HS_OTG_GOTGINT        (volatile unsigned int *)(USB1_OTG_HS + 0x004)
#define USB1_OTG_HS_OTG_GAHBCFG        (volatile unsigned int *)(USB1_OTG_HS + 0x008)
#define USB1_OTG_HS_OTG_GUSBCFG        (volatile unsigned int *)(USB1_OTG_HS + 0x00C)
#define USB1_OTG_HS_OTG_GRSTCTL        (volatile unsigned int *)(USB1_OTG_HS + 0x010)
#define USB1_OTG_HS_OTG_GINTSTS        (volatile unsigned int *)(USB1_OTG_HS + 0x014)
#define USB1_OTG_HS_OTG_GINTMSK        (volatile unsigned int *)(USB1_OTG_HS + 0x018)
#define USB1_OTG_HS_OTG_GRXSTSR_Device (volatile unsigned int *)(USB1_OTG_HS + 0x01C)
#define USB1_OTG_HS_OTG_GRXSTSR_Host   (volatile unsigned int *)(USB1_OTG_HS + 0x01C)
#define USB1_OTG_HS_OTG_GRXSTSP_Device (volatile unsigned int *)(USB1_OTG_HS + 0x020)
#define USB1_OTG_HS_OTG_GRXSTSP_Host   (volatile unsigned int *)(USB1_OTG_HS + 0x020)
#define USB1_OTG_HS_OTG_GRXFSIZ        (volatile unsigned int *)(USB1_OTG_HS + 0x024)
#define USB1_OTG_HS_OTG_HNPTXFSIZ      (volatile unsigned int *)(USB1_OTG_HS + 0x028)
#define USB1_OTG_HS_OTG_DIEPTXF0       (volatile unsigned int *)(USB1_OTG_HS + 0x028)
#define USB1_OTG_HS_OTG_HNPTXSTS       (volatile unsigned int *)(USB1_OTG_HS + 0x02C)
#define USB1_OTG_HS_OTG_GCCFG          (volatile unsigned int *)(USB1_OTG_HS + 0x038)
#define USB1_OTG_HS_OTG_CID            (volatile unsigned int *)(USB1_OTG_HS + 0x03C)
#define USB1_OTG_HS_OTG_GLPMCFG        (volatile unsigned int *)(USB1_OTG_HS + 0x054)
#define USB1_OTG_HS_OTG_HPTXFSIZ       (volatile unsigned int *)(USB1_OTG_HS + 0x100)
#define USB1_OTG_HS_OTG_DIEPTXF1       (volatile unsigned int *)(USB1_OTG_HS + 0x104)
#define USB1_OTG_HS_OTG_DIEPTXF2       (volatile unsigned int *)(USB1_OTG_HS + 0x108)
#define USB1_OTG_HS_OTG_DIEPTXF7       (volatile unsigned int *)(USB1_OTG_HS + 0x120)

/* --- Host-mode core --- */
#define USB1_OTG_HS_OTG_HCFG           (volatile unsigned int *)(USB1_OTG_HS + 0x400)
#define USB1_OTG_HS_OTG_HFIR           (volatile unsigned int *)(USB1_OTG_HS + 0x404)
#define USB1_OTG_HS_OTG_HFNUM          (volatile unsigned int *)(USB1_OTG_HS + 0x408)
#define USB1_OTG_HS_OTG_HPTXSTS        (volatile unsigned int *)(USB1_OTG_HS + 0x410)
#define USB1_OTG_HS_OTG_HAINT          (volatile unsigned int *)(USB1_OTG_HS + 0x414)
#define USB1_OTG_HS_OTG_HAINTMSK       (volatile unsigned int *)(USB1_OTG_HS + 0x418)
#define USB1_OTG_HS_OTG_HFLBADDR       (volatile unsigned int *)(USB1_OTG_HS + 0x41C)
#define USB1_OTG_HS_OTG_HPRT           (volatile unsigned int *)(USB1_OTG_HS + 0x440)

/* --- Host channel 0 --- */
#define USB1_OTG_HS_OTG_HCCHAR0        (volatile unsigned int *)(USB1_OTG_HS + 0x500)
#define USB1_OTG_HS_OTG_HCSPLT0        (volatile unsigned int *)(USB1_OTG_HS + 0x504)
#define USB1_OTG_HS_OTG_HCINT0         (volatile unsigned int *)(USB1_OTG_HS + 0x508)
#define USB1_OTG_HS_OTG_HCINTMSK0      (volatile unsigned int *)(USB1_OTG_HS + 0x50C)
#define USB1_OTG_HS_OTG_HCTSIZ0        (volatile unsigned int *)(USB1_OTG_HS + 0x510)
#define USB1_OTG_HS_OTG_HCDMA0         (volatile unsigned int *)(USB1_OTG_HS + 0x514)
#define USB1_OTG_HS_OTG_HCDMAB0        (volatile unsigned int *)(USB1_OTG_HS + 0x51C)

/* --- Host channel 1 --- */
#define USB1_OTG_HS_OTG_HCCHAR1        (volatile unsigned int *)(USB1_OTG_HS + 0x520)
#define USB1_OTG_HS_OTG_HCSPLT1        (volatile unsigned int *)(USB1_OTG_HS + 0x524)
#define USB1_OTG_HS_OTG_HCINT1         (volatile unsigned int *)(USB1_OTG_HS + 0x528)
#define USB1_OTG_HS_OTG_HCINTMSK1      (volatile unsigned int *)(USB1_OTG_HS + 0x52C)
#define USB1_OTG_HS_OTG_HCTSIZ1        (volatile unsigned int *)(USB1_OTG_HS + 0x530)
#define USB1_OTG_HS_OTG_HCDMA1         (volatile unsigned int *)(USB1_OTG_HS + 0x534)
#define USB1_OTG_HS_OTG_HCDMAB1        (volatile unsigned int *)(USB1_OTG_HS + 0x53C)

/* --- Host channel 2 --- */
#define USB1_OTG_HS_OTG_HCCHAR2    (volatile unsigned int *)(USB1_OTG_HS + 0x540)
#define USB1_OTG_HS_OTG_HCSPLT2    (volatile unsigned int *)(USB1_OTG_HS + 0x544)
#define USB1_OTG_HS_OTG_HCINT2     (volatile unsigned int *)(USB1_OTG_HS + 0x548)
#define USB1_OTG_HS_OTG_HCINTMSK2  (volatile unsigned int *)(USB1_OTG_HS + 0x54C)
#define USB1_OTG_HS_OTG_HCTSIZ2    (volatile unsigned int *)(USB1_OTG_HS + 0x550)
#define USB1_OTG_HS_OTG_HCDMA2     (volatile unsigned int *)(USB1_OTG_HS + 0x554)
#define USB1_OTG_HS_OTG_HCDMAB2    (volatile unsigned int *)(USB1_OTG_HS + 0x55C)

/* --- Host channel 3 --- */
#define USB1_OTG_HS_OTG_HCCHAR3    (volatile unsigned int *)(USB1_OTG_HS + 0x560)
#define USB1_OTG_HS_OTG_HCSPLT3    (volatile unsigned int *)(USB1_OTG_HS + 0x564)
#define USB1_OTG_HS_OTG_HCINT3     (volatile unsigned int *)(USB1_OTG_HS + 0x568)
#define USB1_OTG_HS_OTG_HCINTMSK3  (volatile unsigned int *)(USB1_OTG_HS + 0x56C)
#define USB1_OTG_HS_OTG_HCTSIZ3    (volatile unsigned int *)(USB1_OTG_HS + 0x570)
#define USB1_OTG_HS_OTG_HCDMA3     (volatile unsigned int *)(USB1_OTG_HS + 0x574)
#define USB1_OTG_HS_OTG_HCDMAB3    (volatile unsigned int *)(USB1_OTG_HS + 0x57C)

/* --- Host channel 4 --- */
#define USB1_OTG_HS_OTG_HCCHAR4    (volatile unsigned int *)(USB1_OTG_HS + 0x580)
#define USB1_OTG_HS_OTG_HCSPLT4    (volatile unsigned int *)(USB1_OTG_HS + 0x584)
#define USB1_OTG_HS_OTG_HCINT4     (volatile unsigned int *)(USB1_OTG_HS + 0x588)
#define USB1_OTG_HS_OTG_HCINTMSK4  (volatile unsigned int *)(USB1_OTG_HS + 0x58C)
#define USB1_OTG_HS_OTG_HCTSIZ4    (volatile unsigned int *)(USB1_OTG_HS + 0x590)
#define USB1_OTG_HS_OTG_HCDMA4     (volatile unsigned int *)(USB1_OTG_HS + 0x594)
#define USB1_OTG_HS_OTG_HCDMAB4    (volatile unsigned int *)(USB1_OTG_HS + 0x59C)

/* --- Host channel 5 --- */
#define USB1_OTG_HS_OTG_HCCHAR5    (volatile unsigned int *)(USB1_OTG_HS + 0x5A0)
#define USB1_OTG_HS_OTG_HCSPLT5    (volatile unsigned int *)(USB1_OTG_HS + 0x5A4)
#define USB1_OTG_HS_OTG_HCINT5     (volatile unsigned int *)(USB1_OTG_HS + 0x5A8)
#define USB1_OTG_HS_OTG_HCINTMSK5  (volatile unsigned int *)(USB1_OTG_HS + 0x5AC)
#define USB1_OTG_HS_OTG_HCTSIZ5    (volatile unsigned int *)(USB1_OTG_HS + 0x5B0)
#define USB1_OTG_HS_OTG_HCDMA5     (volatile unsigned int *)(USB1_OTG_HS + 0x5B4)
#define USB1_OTG_HS_OTG_HCDMAB5    (volatile unsigned int *)(USB1_OTG_HS + 0x5BC)

/* --- Host channel 6 --- */
#define USB1_OTG_HS_OTG_HCCHAR6    (volatile unsigned int *)(USB1_OTG_HS + 0x5C0)
#define USB1_OTG_HS_OTG_HCSPLT6    (volatile unsigned int *)(USB1_OTG_HS + 0x5C4)
#define USB1_OTG_HS_OTG_HCINT6     (volatile unsigned int *)(USB1_OTG_HS + 0x5C8)
#define USB1_OTG_HS_OTG_HCINTMSK6  (volatile unsigned int *)(USB1_OTG_HS + 0x5CC)
#define USB1_OTG_HS_OTG_HCTSIZ6    (volatile unsigned int *)(USB1_OTG_HS + 0x5D0)
#define USB1_OTG_HS_OTG_HCDMA6     (volatile unsigned int *)(USB1_OTG_HS + 0x5D4)
#define USB1_OTG_HS_OTG_HCDMAB6    (volatile unsigned int *)(USB1_OTG_HS + 0x5DC)

/* --- Host channel 7 --- */
#define USB1_OTG_HS_OTG_HCCHAR7    (volatile unsigned int *)(USB1_OTG_HS + 0x5E0)
#define USB1_OTG_HS_OTG_HCSPLT7    (volatile unsigned int *)(USB1_OTG_HS + 0x5E4)
#define USB1_OTG_HS_OTG_HCINT7     (volatile unsigned int *)(USB1_OTG_HS + 0x5E8)
#define USB1_OTG_HS_OTG_HCINTMSK7  (volatile unsigned int *)(USB1_OTG_HS + 0x5EC)
#define USB1_OTG_HS_OTG_HCTSIZ7    (volatile unsigned int *)(USB1_OTG_HS + 0x5F0)
#define USB1_OTG_HS_OTG_HCDMA7     (volatile unsigned int *)(USB1_OTG_HS + 0x5F4)
#define USB1_OTG_HS_OTG_HCDMAB7    (volatile unsigned int *)(USB1_OTG_HS + 0x5FC)

/* --- Host channel 8 --- */
#define USB1_OTG_HS_OTG_HCCHAR8    (volatile unsigned int *)(USB1_OTG_HS + 0x600)
#define USB1_OTG_HS_OTG_HCSPLT8    (volatile unsigned int *)(USB1_OTG_HS + 0x604)
#define USB1_OTG_HS_OTG_HCINT8     (volatile unsigned int *)(USB1_OTG_HS + 0x608)
#define USB1_OTG_HS_OTG_HCINTMSK8  (volatile unsigned int *)(USB1_OTG_HS + 0x60C)
#define USB1_OTG_HS_OTG_HCTSIZ8    (volatile unsigned int *)(USB1_OTG_HS + 0x610)
#define USB1_OTG_HS_OTG_HCDMA8     (volatile unsigned int *)(USB1_OTG_HS + 0x614)
#define USB1_OTG_HS_OTG_HCDMAB8    (volatile unsigned int *)(USB1_OTG_HS + 0x61C)

/* --- Host channel 9 --- */
#define USB1_OTG_HS_OTG_HCCHAR9    (volatile unsigned int *)(USB1_OTG_HS + 0x620)
#define USB1_OTG_HS_OTG_HCSPLT9    (volatile unsigned int *)(USB1_OTG_HS + 0x624)
#define USB1_OTG_HS_OTG_HCINT9     (volatile unsigned int *)(USB1_OTG_HS + 0x628)
#define USB1_OTG_HS_OTG_HCINTMSK9  (volatile unsigned int *)(USB1_OTG_HS + 0x62C)
#define USB1_OTG_HS_OTG_HCTSIZ9    (volatile unsigned int *)(USB1_OTG_HS + 0x630)
#define USB1_OTG_HS_OTG_HCDMA9     (volatile unsigned int *)(USB1_OTG_HS + 0x634)
#define USB1_OTG_HS_OTG_HCDMAB9    (volatile unsigned int *)(USB1_OTG_HS + 0x63C)

/* --- Host channel 10 --- */
#define USB1_OTG_HS_OTG_HCCHAR10   (volatile unsigned int *)(USB1_OTG_HS + 0x640)
#define USB1_OTG_HS_OTG_HCSPLT10   (volatile unsigned int *)(USB1_OTG_HS + 0x644)
#define USB1_OTG_HS_OTG_HCINT10    (volatile unsigned int *)(USB1_OTG_HS + 0x648)
#define USB1_OTG_HS_OTG_HCINTMSK10 (volatile unsigned int *)(USB1_OTG_HS + 0x64C)
#define USB1_OTG_HS_OTG_HCTSIZ10   (volatile unsigned int *)(USB1_OTG_HS + 0x650)
#define USB1_OTG_HS_OTG_HCDMA10    (volatile unsigned int *)(USB1_OTG_HS + 0x654)
#define USB1_OTG_HS_OTG_HCDMAB10   (volatile unsigned int *)(USB1_OTG_HS + 0x65C)

/* --- Host channel 11 --- */
#define USB1_OTG_HS_OTG_HCCHAR11   (volatile unsigned int *)(USB1_OTG_HS + 0x660)
#define USB1_OTG_HS_OTG_HCSPLT11   (volatile unsigned int *)(USB1_OTG_HS + 0x664)
#define USB1_OTG_HS_OTG_HCINT11    (volatile unsigned int *)(USB1_OTG_HS + 0x668)
#define USB1_OTG_HS_OTG_HCINTMSK11 (volatile unsigned int *)(USB1_OTG_HS + 0x66C)
#define USB1_OTG_HS_OTG_HCTSIZ11   (volatile unsigned int *)(USB1_OTG_HS + 0x670)
#define USB1_OTG_HS_OTG_HCDMA11    (volatile unsigned int *)(USB1_OTG_HS + 0x674)
#define USB1_OTG_HS_OTG_HCDMAB11   (volatile unsigned int *)(USB1_OTG_HS + 0x67C)

/* --- Host channel 12 --- */
#define USB1_OTG_HS_OTG_HCCHAR12   (volatile unsigned int *)(USB1_OTG_HS + 0x680)
#define USB1_OTG_HS_OTG_HCSPLT12   (volatile unsigned int *)(USB1_OTG_HS + 0x684)
#define USB1_OTG_HS_OTG_HCINT12    (volatile unsigned int *)(USB1_OTG_HS + 0x688)
#define USB1_OTG_HS_OTG_HCINTMSK12 (volatile unsigned int *)(USB1_OTG_HS + 0x68C)
#define USB1_OTG_HS_OTG_HCTSIZ12   (volatile unsigned int *)(USB1_OTG_HS + 0x690)
#define USB1_OTG_HS_OTG_HCDMA12    (volatile unsigned int *)(USB1_OTG_HS + 0x694)
#define USB1_OTG_HS_OTG_HCDMAB12   (volatile unsigned int *)(USB1_OTG_HS + 0x69C)

/* --- Host channel 13 --- */
#define USB1_OTG_HS_OTG_HCCHAR13   (volatile unsigned int *)(USB1_OTG_HS + 0x6A0)
#define USB1_OTG_HS_OTG_HCSPLT13   (volatile unsigned int *)(USB1_OTG_HS + 0x6A4)
#define USB1_OTG_HS_OTG_HCINT13    (volatile unsigned int *)(USB1_OTG_HS + 0x6A8)
#define USB1_OTG_HS_OTG_HCINTMSK13 (volatile unsigned int *)(USB1_OTG_HS + 0x6AC)
#define USB1_OTG_HS_OTG_HCTSIZ13   (volatile unsigned int *)(USB1_OTG_HS + 0x6B0)
#define USB1_OTG_HS_OTG_HCDMA13    (volatile unsigned int *)(USB1_OTG_HS + 0x6B4)
#define USB1_OTG_HS_OTG_HCDMAB13   (volatile unsigned int *)(USB1_OTG_HS + 0x6BC)

/* --- Host channel 14 --- */
#define USB1_OTG_HS_OTG_HCCHAR14   (volatile unsigned int *)(USB1_OTG_HS + 0x6C0)
#define USB1_OTG_HS_OTG_HCSPLT14   (volatile unsigned int *)(USB1_OTG_HS + 0x6C4)
#define USB1_OTG_HS_OTG_HCINT14    (volatile unsigned int *)(USB1_OTG_HS + 0x6C8)
#define USB1_OTG_HS_OTG_HCINTMSK14 (volatile unsigned int *)(USB1_OTG_HS + 0x6CC)
#define USB1_OTG_HS_OTG_HCTSIZ14   (volatile unsigned int *)(USB1_OTG_HS + 0x6D0)
#define USB1_OTG_HS_OTG_HCDMA14    (volatile unsigned int *)(USB1_OTG_HS + 0x6D4)
#define USB1_OTG_HS_OTG_HCDMAB14   (volatile unsigned int *)(USB1_OTG_HS + 0x6DC)

/* --- Host channel 15 --- */
#define USB1_OTG_HS_OTG_HCCHAR15   (volatile unsigned int *)(USB1_OTG_HS + 0x6E0)
#define USB1_OTG_HS_OTG_HCSPLT15   (volatile unsigned int *)(USB1_OTG_HS + 0x6E4)
#define USB1_OTG_HS_OTG_HCINT15    (volatile unsigned int *)(USB1_OTG_HS + 0x6E8)
#define USB1_OTG_HS_OTG_HCINTMSK15 (volatile unsigned int *)(USB1_OTG_HS + 0x6EC)
#define USB1_OTG_HS_OTG_HCTSIZ15   (volatile unsigned int *)(USB1_OTG_HS + 0x6F0)
#define USB1_OTG_HS_OTG_HCDMA15    (volatile unsigned int *)(USB1_OTG_HS + 0x6F4)
#define USB1_OTG_HS_OTG_HCDMAB15   (volatile unsigned int *)(USB1_OTG_HS + 0x6FC)

/* --- Device-mode core --- */
#define USB1_OTG_HS_OTG_DCFG           (volatile unsigned int *)(USB1_OTG_HS + 0x800)
#define USB1_OTG_HS_OTG_DCTL           (volatile unsigned int *)(USB1_OTG_HS + 0x804)
#define USB1_OTG_HS_OTG_DSTS           (volatile unsigned int *)(USB1_OTG_HS + 0x808)
#define USB1_OTG_HS_OTG_DIEPMSK        (volatile unsigned int *)(USB1_OTG_HS + 0x810)
#define USB1_OTG_HS_OTG_DOEPMSK        (volatile unsigned int *)(USB1_OTG_HS + 0x814)
#define USB1_OTG_HS_OTG_DAINT          (volatile unsigned int *)(USB1_OTG_HS + 0x818)
#define USB1_OTG_HS_OTG_DAINTMSK       (volatile unsigned int *)(USB1_OTG_HS + 0x81C)
#define USB1_OTG_HS_OTG_DVBUSDIS       (volatile unsigned int *)(USB1_OTG_HS + 0x828)
#define USB1_OTG_HS_OTG_DVBUSPULSE     (volatile unsigned int *)(USB1_OTG_HS + 0x82C)
#define USB1_OTG_HS_OTG_DTHRCTL        (volatile unsigned int *)(USB1_OTG_HS + 0x830)
#define USB1_OTG_HS_OTG_DIEPEMPMSK     (volatile unsigned int *)(USB1_OTG_HS + 0x834)
#define USB1_OTG_HS_OTG_DEACHINT       (volatile unsigned int *)(USB1_OTG_HS + 0x838)
#define USB1_OTG_HS_OTG_DEACHINTMSK    (volatile unsigned int *)(USB1_OTG_HS + 0x83C)
#define USB1_OTG_HS_OTG_HS_DIEPEACHMSK1 (volatile unsigned int *)(USB1_OTG_HS + 0x844)
#define USB1_OTG_HS_OTG_HS_DOEPEACHMSK1 (volatile unsigned int *)(USB1_OTG_HS + 0x884)

/* --- Device IN endpoint 0 --- */
#define USB1_OTG_HS_OTG_DIEPCTL0       (volatile unsigned int *)(USB1_OTG_HS + 0x900)
#define USB1_OTG_HS_OTG_DIEPINT0       (volatile unsigned int *)(USB1_OTG_HS + 0x908)
#define USB1_OTG_HS_OTG_DIEPTSIZ0      (volatile unsigned int *)(USB1_OTG_HS + 0x910)
#define USB1_OTG_HS_OTG_DIEPDMA0       (volatile unsigned int *)(USB1_OTG_HS + 0x914)
#define USB1_OTG_HS_OTG_DTXFSTS0       (volatile unsigned int *)(USB1_OTG_HS + 0x918)

/* --- Device IN endpoint 1 --- */
#define USB1_OTG_HS_OTG_DIEPCTL1       (volatile unsigned int *)(USB1_OTG_HS + 0x920)
#define USB1_OTG_HS_OTG_DIEPINT1       (volatile unsigned int *)(USB1_OTG_HS + 0x928)
#define USB1_OTG_HS_OTG_DIEPTSIZ1      (volatile unsigned int *)(USB1_OTG_HS + 0x930)
#define USB1_OTG_HS_OTG_DIEPDMA1       (volatile unsigned int *)(USB1_OTG_HS + 0x934)
#define USB1_OTG_HS_OTG_DTXFSTS1       (volatile unsigned int *)(USB1_OTG_HS + 0x938)

/* --- Device IN endpoint 2 --- */
#define USB1_OTG_HS_OTG_DIEPCTL2       (volatile unsigned int *)(USB1_OTG_HS + 0x940)
#define USB1_OTG_HS_OTG_DIEPINT2       (volatile unsigned int *)(USB1_OTG_HS + 0x948)
#define USB1_OTG_HS_OTG_DIEPTSIZ2      (volatile unsigned int *)(USB1_OTG_HS + 0x950)
#define USB1_OTG_HS_OTG_DIEPDMA2       (volatile unsigned int *)(USB1_OTG_HS + 0x954)
#define USB1_OTG_HS_OTG_DTXFSTS2       (volatile unsigned int *)(USB1_OTG_HS + 0x958)

/* --- Device IN endpoint 3 --- */
#define USB1_OTG_HS_OTG_DIEPCTL3       (volatile unsigned int *)(USB1_OTG_HS + 0x960)
#define USB1_OTG_HS_OTG_DIEPINT3       (volatile unsigned int *)(USB1_OTG_HS + 0x968)
#define USB1_OTG_HS_OTG_DIEPTSIZ3      (volatile unsigned int *)(USB1_OTG_HS + 0x970)
#define USB1_OTG_HS_OTG_DIEPDMA3       (volatile unsigned int *)(USB1_OTG_HS + 0x974)
#define USB1_OTG_HS_OTG_DTXFSTS3       (volatile unsigned int *)(USB1_OTG_HS + 0x978)

/* --- Device IN endpoint 4 --- */
#define USB1_OTG_HS_OTG_DIEPCTL4       (volatile unsigned int *)(USB1_OTG_HS + 0x980)
#define USB1_OTG_HS_OTG_DIEPINT4       (volatile unsigned int *)(USB1_OTG_HS + 0x988)
#define USB1_OTG_HS_OTG_DIEPTSIZ4      (volatile unsigned int *)(USB1_OTG_HS + 0x990)
#define USB1_OTG_HS_OTG_DIEPDMA4       (volatile unsigned int *)(USB1_OTG_HS + 0x994)
#define USB1_OTG_HS_OTG_DTXFSTS4       (volatile unsigned int *)(USB1_OTG_HS + 0x998)

/* --- Device IN endpoint 5 --- */
#define USB1_OTG_HS_OTG_DIEPCTL5       (volatile unsigned int *)(USB1_OTG_HS + 0x9A0)
#define USB1_OTG_HS_OTG_DIEPINT5       (volatile unsigned int *)(USB1_OTG_HS + 0x9A8)
#define USB1_OTG_HS_OTG_DIEPTSIZ5      (volatile unsigned int *)(USB1_OTG_HS + 0x9B0)
#define USB1_OTG_HS_OTG_DIEPDMA5       (volatile unsigned int *)(USB1_OTG_HS + 0x9B4)
#define USB1_OTG_HS_OTG_DTXFSTS5       (volatile unsigned int *)(USB1_OTG_HS + 0x9B8)

/* --- Device IN endpoint 6 --- */
#define USB1_OTG_HS_OTG_DIEPCTL6       (volatile unsigned int *)(USB1_OTG_HS + 0x9C0)
#define USB1_OTG_HS_OTG_DIEPINT6       (volatile unsigned int *)(USB1_OTG_HS + 0x9C8)
#define USB1_OTG_HS_OTG_DIEPTSIZ6      (volatile unsigned int *)(USB1_OTG_HS + 0x9D0)
#define USB1_OTG_HS_OTG_DIEPDMA6       (volatile unsigned int *)(USB1_OTG_HS + 0x9D4)
#define USB1_OTG_HS_OTG_DTXFSTS6       (volatile unsigned int *)(USB1_OTG_HS + 0x9D8)

/* --- Device IN endpoint 7 --- */
#define USB1_OTG_HS_OTG_DIEPCTL7       (volatile unsigned int *)(USB1_OTG_HS + 0x9E0)
#define USB1_OTG_HS_OTG_DIEPINT7       (volatile unsigned int *)(USB1_OTG_HS + 0x9E8)
#define USB1_OTG_HS_OTG_DIEPTSIZ7      (volatile unsigned int *)(USB1_OTG_HS + 0x9F0)
#define USB1_OTG_HS_OTG_DIEPDMA7       (volatile unsigned int *)(USB1_OTG_HS + 0x9F4)
#define USB1_OTG_HS_OTG_DTXFSTS7       (volatile unsigned int *)(USB1_OTG_HS + 0x9F8)

/* --- Device OUT Endpoint 0 --- */
#define USB1_OTG_HS_OTG_DOEPCTL0       (volatile unsigned int *)(USB1_OTG_HS + 0xB00)
#define USB1_OTG_HS_OTG_DOEPINT0       (volatile unsigned int *)(USB1_OTG_HS + 0xB08)
#define USB1_OTG_HS_OTG_DOEPTSIZ0      (volatile unsigned int *)(USB1_OTG_HS + 0xB10)
#define USB1_OTG_HS_OTG_DOEPDMA0       (volatile unsigned int *)(USB1_OTG_HS + 0xB14)

/* --- Device OUT Endpoint 1 --- */
#define USB1_OTG_HS_OTG_DOEPCTL1       (volatile unsigned int *)(USB1_OTG_HS + 0xB20)
#define USB1_OTG_HS_OTG_DOEPINT1       (volatile unsigned int *)(USB1_OTG_HS + 0xB28)
#define USB1_OTG_HS_OTG_DOEPTSIZ1      (volatile unsigned int *)(USB1_OTG_HS + 0xB30)
#define USB1_OTG_HS_OTG_DOEPDMA1       (volatile unsigned int *)(USB1_OTG_HS + 0xB34)

/* --- Device OUT Endpoint 2 --- */
#define USB1_OTG_HS_OTG_DOEPCTL2       (volatile unsigned int *)(USB1_OTG_HS + 0xB40)
#define USB1_OTG_HS_OTG_DOEPINT2       (volatile unsigned int *)(USB1_OTG_HS + 0xB48)
#define USB1_OTG_HS_OTG_DOEPTSIZ2      (volatile unsigned int *)(USB1_OTG_HS + 0xB50)
#define USB1_OTG_HS_OTG_DOEPDMA2       (volatile unsigned int *)(USB1_OTG_HS + 0xB54)

/* --- Device OUT Endpoint 3 --- */
#define USB1_OTG_HS_OTG_DOEPCTL3       (volatile unsigned int *)(USB1_OTG_HS + 0xB60)
#define USB1_OTG_HS_OTG_DOEPINT3       (volatile unsigned int *)(USB1_OTG_HS + 0xB68)
#define USB1_OTG_HS_OTG_DOEPTSIZ3      (volatile unsigned int *)(USB1_OTG_HS + 0xB70)
#define USB1_OTG_HS_OTG_DOEPDMA3       (volatile unsigned int *)(USB1_OTG_HS + 0xB74)

/* --- Device OUT Endpoint 4 --- */
#define USB1_OTG_HS_OTG_DOEPCTL4       (volatile unsigned int *)(USB1_OTG_HS + 0xB80)
#define USB1_OTG_HS_OTG_DOEPINT4       (volatile unsigned int *)(USB1_OTG_HS + 0xB88)
#define USB1_OTG_HS_OTG_DOEPTSIZ4      (volatile unsigned int *)(USB1_OTG_HS + 0xB90)
#define USB1_OTG_HS_OTG_DOEPDMA4       (volatile unsigned int *)(USB1_OTG_HS + 0xB94)

/* --- Device OUT Endpoint 5 --- */
#define USB1_OTG_HS_OTG_DOEPCTL5       (volatile unsigned int *)(USB1_OTG_HS + 0xBA0)
#define USB1_OTG_HS_OTG_DOEPINT5       (volatile unsigned int *)(USB1_OTG_HS + 0xBA8)
#define USB1_OTG_HS_OTG_DOEPTSIZ5      (volatile unsigned int *)(USB1_OTG_HS + 0xBB0)
#define USB1_OTG_HS_OTG_DOEPDMA5       (volatile unsigned int *)(USB1_OTG_HS + 0xBB4)

/* --- Device OUT Endpoint 6 --- */
#define USB1_OTG_HS_OTG_DOEPCTL6       (volatile unsigned int *)(USB1_OTG_HS + 0xBC0)
#define USB1_OTG_HS_OTG_DOEPINT6       (volatile unsigned int *)(USB1_OTG_HS + 0xBC8)
#define USB1_OTG_HS_OTG_DOEPTSIZ6      (volatile unsigned int *)(USB1_OTG_HS + 0xBD0)
#define USB1_OTG_HS_OTG_DOEPDMA6       (volatile unsigned int *)(USB1_OTG_HS + 0xBD4)

/* --- Device OUT Endpoint 7 --- */
#define USB1_OTG_HS_OTG_DOEPCTL7       (volatile unsigned int *)(USB1_OTG_HS + 0xBE0)
#define USB1_OTG_HS_OTG_DOEPINT7       (volatile unsigned int *)(USB1_OTG_HS + 0xBE8)
#define USB1_OTG_HS_OTG_DOEPTSIZ7      (volatile unsigned int *)(USB1_OTG_HS + 0xBF0)
#define USB1_OTG_HS_OTG_DOEPDMA7       (volatile unsigned int *)(USB1_OTG_HS + 0xBF4)

/* --- Device OUT Endpoint 8 --- */
#define USB1_OTG_HS_OTG_DOEPCTL8       (volatile unsigned int *)(USB1_OTG_HS + 0xC00)
#define USB1_OTG_HS_OTG_DOEPINT8       (volatile unsigned int *)(USB1_OTG_HS + 0xC08)
#define USB1_OTG_HS_OTG_DOEPTSIZ8      (volatile unsigned int *)(USB1_OTG_HS + 0xC10)
#define USB1_OTG_HS_OTG_DOEPDMA8       (volatile unsigned int *)(USB1_OTG_HS + 0xC14)

/* --- Power and clock gating --- */
#define USB1_OTG_HS_OTG_PCGCCTL        (volatile unsigned int *)(USB1_OTG_HS + 0xE00)

/*------------------------------- USB2_OTG_HS --------------------------------*/

/* --- Global registers --- */
#define USB2_OTG_HS_OTG_GOTGCTL        (volatile unsigned int *)(USB2_OTG_HS + 0x000)
#define USB2_OTG_HS_OTG_GOTGINT        (volatile unsigned int *)(USB2_OTG_HS + 0x004)
#define USB2_OTG_HS_OTG_GAHBCFG        (volatile unsigned int *)(USB2_OTG_HS + 0x008)
#define USB2_OTG_HS_OTG_GUSBCFG        (volatile unsigned int *)(USB2_OTG_HS + 0x00C)
#define USB2_OTG_HS_OTG_GRSTCTL        (volatile unsigned int *)(USB2_OTG_HS + 0x010)
#define USB2_OTG_HS_OTG_GINTSTS        (volatile unsigned int *)(USB2_OTG_HS + 0x014)
#define USB2_OTG_HS_OTG_GINTMSK        (volatile unsigned int *)(USB2_OTG_HS + 0x018)
#define USB2_OTG_HS_OTG_GRXSTSR_Device (volatile unsigned int *)(USB2_OTG_HS + 0x01C)
#define USB2_OTG_HS_OTG_GRXSTSR_Host   (volatile unsigned int *)(USB2_OTG_HS + 0x01C)
#define USB2_OTG_HS_OTG_GRXSTSP_Device (volatile unsigned int *)(USB2_OTG_HS + 0x020)
#define USB2_OTG_HS_OTG_GRXSTSP_Host   (volatile unsigned int *)(USB2_OTG_HS + 0x020)
#define USB2_OTG_HS_OTG_GRXFSIZ        (volatile unsigned int *)(USB2_OTG_HS + 0x024)
#define USB2_OTG_HS_OTG_HNPTXFSIZ      (volatile unsigned int *)(USB2_OTG_HS + 0x028)
#define USB2_OTG_HS_OTG_DIEPTXF0       (volatile unsigned int *)(USB2_OTG_HS + 0x028)
#define USB2_OTG_HS_OTG_HNPTXSTS       (volatile unsigned int *)(USB2_OTG_HS + 0x02C)
#define USB2_OTG_HS_OTG_GCCFG          (volatile unsigned int *)(USB2_OTG_HS + 0x038)
#define USB2_OTG_HS_OTG_CID            (volatile unsigned int *)(USB2_OTG_HS + 0x03C)
#define USB2_OTG_HS_OTG_GLPMCFG        (volatile unsigned int *)(USB2_OTG_HS + 0x054)
#define USB2_OTG_HS_OTG_HPTXFSIZ       (volatile unsigned int *)(USB2_OTG_HS + 0x100)
#define USB2_OTG_HS_OTG_DIEPTXF1       (volatile unsigned int *)(USB2_OTG_HS + 0x104)
#define USB2_OTG_HS_OTG_DIEPTXF2       (volatile unsigned int *)(USB2_OTG_HS + 0x108)
#define USB2_OTG_HS_OTG_DIEPTXF7       (volatile unsigned int *)(USB2_OTG_HS + 0x120)

/* --- Host-mode core --- */
#define USB2_OTG_HS_OTG_HCFG           (volatile unsigned int *)(USB2_OTG_HS + 0x400)
#define USB2_OTG_HS_OTG_HFIR           (volatile unsigned int *)(USB2_OTG_HS + 0x404)
#define USB2_OTG_HS_OTG_HFNUM          (volatile unsigned int *)(USB2_OTG_HS + 0x408)
#define USB2_OTG_HS_OTG_HPTXSTS        (volatile unsigned int *)(USB2_OTG_HS + 0x410)
#define USB2_OTG_HS_OTG_HAINT          (volatile unsigned int *)(USB2_OTG_HS + 0x414)
#define USB2_OTG_HS_OTG_HAINTMSK       (volatile unsigned int *)(USB2_OTG_HS + 0x418)
#define USB2_OTG_HS_OTG_HFLBADDR       (volatile unsigned int *)(USB2_OTG_HS + 0x41C)
#define USB2_OTG_HS_OTG_HPRT           (volatile unsigned int *)(USB2_OTG_HS + 0x440)

/* --- Host channel 0 --- */
#define USB2_OTG_HS_OTG_HCCHAR0        (volatile unsigned int *)(USB2_OTG_HS + 0x500)
#define USB2_OTG_HS_OTG_HCSPLT0        (volatile unsigned int *)(USB2_OTG_HS + 0x504)
#define USB2_OTG_HS_OTG_HCINT0         (volatile unsigned int *)(USB2_OTG_HS + 0x508)
#define USB2_OTG_HS_OTG_HCINTMSK0      (volatile unsigned int *)(USB2_OTG_HS + 0x50C)
#define USB2_OTG_HS_OTG_HCTSIZ0        (volatile unsigned int *)(USB2_OTG_HS + 0x510)
#define USB2_OTG_HS_OTG_HCDMA0         (volatile unsigned int *)(USB2_OTG_HS + 0x514)
#define USB2_OTG_HS_OTG_HCDMAB0        (volatile unsigned int *)(USB2_OTG_HS + 0x51C)

/* --- Host channel 1 --- */
#define USB2_OTG_HS_OTG_HCCHAR1        (volatile unsigned int *)(USB2_OTG_HS + 0x520)
#define USB2_OTG_HS_OTG_HCSPLT1        (volatile unsigned int *)(USB2_OTG_HS + 0x524)
#define USB2_OTG_HS_OTG_HCINT1         (volatile unsigned int *)(USB2_OTG_HS + 0x528)
#define USB2_OTG_HS_OTG_HCINTMSK1      (volatile unsigned int *)(USB2_OTG_HS + 0x52C)
#define USB2_OTG_HS_OTG_HCTSIZ1        (volatile unsigned int *)(USB2_OTG_HS + 0x530)
#define USB2_OTG_HS_OTG_HCDMA1         (volatile unsigned int *)(USB2_OTG_HS + 0x534)
#define USB2_OTG_HS_OTG_HCDMAB1        (volatile unsigned int *)(USB2_OTG_HS + 0x53C)

/* --- Host channel 2 --- */
#define USB2_OTG_HS_OTG_HCCHAR2    (volatile unsigned int *)(USB2_OTG_HS + 0x540)
#define USB2_OTG_HS_OTG_HCSPLT2    (volatile unsigned int *)(USB2_OTG_HS + 0x544)
#define USB2_OTG_HS_OTG_HCINT2     (volatile unsigned int *)(USB2_OTG_HS + 0x548)
#define USB2_OTG_HS_OTG_HCINTMSK2  (volatile unsigned int *)(USB2_OTG_HS + 0x54C)
#define USB2_OTG_HS_OTG_HCTSIZ2    (volatile unsigned int *)(USB2_OTG_HS + 0x550)
#define USB2_OTG_HS_OTG_HCDMA2     (volatile unsigned int *)(USB2_OTG_HS + 0x554)
#define USB2_OTG_HS_OTG_HCDMAB2    (volatile unsigned int *)(USB2_OTG_HS + 0x55C)

/* --- Host channel 3 --- */
#define USB2_OTG_HS_OTG_HCCHAR3    (volatile unsigned int *)(USB2_OTG_HS + 0x560)
#define USB2_OTG_HS_OTG_HCSPLT3    (volatile unsigned int *)(USB2_OTG_HS + 0x564)
#define USB2_OTG_HS_OTG_HCINT3     (volatile unsigned int *)(USB2_OTG_HS + 0x568)
#define USB2_OTG_HS_OTG_HCINTMSK3  (volatile unsigned int *)(USB2_OTG_HS + 0x56C)
#define USB2_OTG_HS_OTG_HCTSIZ3    (volatile unsigned int *)(USB2_OTG_HS + 0x570)
#define USB2_OTG_HS_OTG_HCDMA3     (volatile unsigned int *)(USB2_OTG_HS + 0x574)
#define USB2_OTG_HS_OTG_HCDMAB3    (volatile unsigned int *)(USB2_OTG_HS + 0x57C)

/* --- Host channel 4 --- */
#define USB2_OTG_HS_OTG_HCCHAR4    (volatile unsigned int *)(USB2_OTG_HS + 0x580)
#define USB2_OTG_HS_OTG_HCSPLT4    (volatile unsigned int *)(USB2_OTG_HS + 0x584)
#define USB2_OTG_HS_OTG_HCINT4     (volatile unsigned int *)(USB2_OTG_HS + 0x588)
#define USB2_OTG_HS_OTG_HCINTMSK4  (volatile unsigned int *)(USB2_OTG_HS + 0x58C)
#define USB2_OTG_HS_OTG_HCTSIZ4    (volatile unsigned int *)(USB2_OTG_HS + 0x590)
#define USB2_OTG_HS_OTG_HCDMA4     (volatile unsigned int *)(USB2_OTG_HS + 0x594)
#define USB2_OTG_HS_OTG_HCDMAB4    (volatile unsigned int *)(USB2_OTG_HS + 0x59C)

/* --- Host channel 5 --- */
#define USB2_OTG_HS_OTG_HCCHAR5    (volatile unsigned int *)(USB2_OTG_HS + 0x5A0)
#define USB2_OTG_HS_OTG_HCSPLT5    (volatile unsigned int *)(USB2_OTG_HS + 0x5A4)
#define USB2_OTG_HS_OTG_HCINT5     (volatile unsigned int *)(USB2_OTG_HS + 0x5A8)
#define USB2_OTG_HS_OTG_HCINTMSK5  (volatile unsigned int *)(USB2_OTG_HS + 0x5AC)
#define USB2_OTG_HS_OTG_HCTSIZ5    (volatile unsigned int *)(USB2_OTG_HS + 0x5B0)
#define USB2_OTG_HS_OTG_HCDMA5     (volatile unsigned int *)(USB2_OTG_HS + 0x5B4)
#define USB2_OTG_HS_OTG_HCDMAB5    (volatile unsigned int *)(USB2_OTG_HS + 0x5BC)

/* --- Host channel 6 --- */
#define USB2_OTG_HS_OTG_HCCHAR6    (volatile unsigned int *)(USB2_OTG_HS + 0x5C0)
#define USB2_OTG_HS_OTG_HCSPLT6    (volatile unsigned int *)(USB2_OTG_HS + 0x5C4)
#define USB2_OTG_HS_OTG_HCINT6     (volatile unsigned int *)(USB2_OTG_HS + 0x5C8)
#define USB2_OTG_HS_OTG_HCINTMSK6  (volatile unsigned int *)(USB2_OTG_HS + 0x5CC)
#define USB2_OTG_HS_OTG_HCTSIZ6    (volatile unsigned int *)(USB2_OTG_HS + 0x5D0)
#define USB2_OTG_HS_OTG_HCDMA6     (volatile unsigned int *)(USB2_OTG_HS + 0x5D4)
#define USB2_OTG_HS_OTG_HCDMAB6    (volatile unsigned int *)(USB2_OTG_HS + 0x5DC)

/* --- Host channel 7 --- */
#define USB2_OTG_HS_OTG_HCCHAR7    (volatile unsigned int *)(USB2_OTG_HS + 0x5E0)
#define USB2_OTG_HS_OTG_HCSPLT7    (volatile unsigned int *)(USB2_OTG_HS + 0x5E4)
#define USB2_OTG_HS_OTG_HCINT7     (volatile unsigned int *)(USB2_OTG_HS + 0x5E8)
#define USB2_OTG_HS_OTG_HCINTMSK7  (volatile unsigned int *)(USB2_OTG_HS + 0x5EC)
#define USB2_OTG_HS_OTG_HCTSIZ7    (volatile unsigned int *)(USB2_OTG_HS + 0x5F0)
#define USB2_OTG_HS_OTG_HCDMA7     (volatile unsigned int *)(USB2_OTG_HS + 0x5F4)
#define USB2_OTG_HS_OTG_HCDMAB7    (volatile unsigned int *)(USB2_OTG_HS + 0x5FC)

/* --- Host channel 8 --- */
#define USB2_OTG_HS_OTG_HCCHAR8    (volatile unsigned int *)(USB2_OTG_HS + 0x600)
#define USB2_OTG_HS_OTG_HCSPLT8    (volatile unsigned int *)(USB2_OTG_HS + 0x604)
#define USB2_OTG_HS_OTG_HCINT8     (volatile unsigned int *)(USB2_OTG_HS + 0x608)
#define USB2_OTG_HS_OTG_HCINTMSK8  (volatile unsigned int *)(USB2_OTG_HS + 0x60C)
#define USB2_OTG_HS_OTG_HCTSIZ8    (volatile unsigned int *)(USB2_OTG_HS + 0x610)
#define USB2_OTG_HS_OTG_HCDMA8     (volatile unsigned int *)(USB2_OTG_HS + 0x614)
#define USB2_OTG_HS_OTG_HCDMAB8    (volatile unsigned int *)(USB2_OTG_HS + 0x61C)

/* --- Host channel 9 --- */
#define USB2_OTG_HS_OTG_HCCHAR9    (volatile unsigned int *)(USB2_OTG_HS + 0x620)
#define USB2_OTG_HS_OTG_HCSPLT9    (volatile unsigned int *)(USB2_OTG_HS + 0x624)
#define USB2_OTG_HS_OTG_HCINT9     (volatile unsigned int *)(USB2_OTG_HS + 0x628)
#define USB2_OTG_HS_OTG_HCINTMSK9  (volatile unsigned int *)(USB2_OTG_HS + 0x62C)
#define USB2_OTG_HS_OTG_HCTSIZ9    (volatile unsigned int *)(USB2_OTG_HS + 0x630)
#define USB2_OTG_HS_OTG_HCDMA9     (volatile unsigned int *)(USB2_OTG_HS + 0x634)
#define USB2_OTG_HS_OTG_HCDMAB9    (volatile unsigned int *)(USB2_OTG_HS + 0x63C)

/* --- Host channel 10 --- */
#define USB2_OTG_HS_OTG_HCCHAR10   (volatile unsigned int *)(USB2_OTG_HS + 0x640)
#define USB2_OTG_HS_OTG_HCSPLT10   (volatile unsigned int *)(USB2_OTG_HS + 0x644)
#define USB2_OTG_HS_OTG_HCINT10    (volatile unsigned int *)(USB2_OTG_HS + 0x648)
#define USB2_OTG_HS_OTG_HCINTMSK10 (volatile unsigned int *)(USB2_OTG_HS + 0x64C)
#define USB2_OTG_HS_OTG_HCTSIZ10   (volatile unsigned int *)(USB2_OTG_HS + 0x650)
#define USB2_OTG_HS_OTG_HCDMA10    (volatile unsigned int *)(USB2_OTG_HS + 0x654)
#define USB2_OTG_HS_OTG_HCDMAB10   (volatile unsigned int *)(USB2_OTG_HS + 0x65C)

/* --- Host channel 11 --- */
#define USB2_OTG_HS_OTG_HCCHAR11   (volatile unsigned int *)(USB2_OTG_HS + 0x660)
#define USB2_OTG_HS_OTG_HCSPLT11   (volatile unsigned int *)(USB2_OTG_HS + 0x664)
#define USB2_OTG_HS_OTG_HCINT11    (volatile unsigned int *)(USB2_OTG_HS + 0x668)
#define USB2_OTG_HS_OTG_HCINTMSK11 (volatile unsigned int *)(USB2_OTG_HS + 0x66C)
#define USB2_OTG_HS_OTG_HCTSIZ11   (volatile unsigned int *)(USB2_OTG_HS + 0x670)
#define USB2_OTG_HS_OTG_HCDMA11    (volatile unsigned int *)(USB2_OTG_HS + 0x674)
#define USB2_OTG_HS_OTG_HCDMAB11   (volatile unsigned int *)(USB2_OTG_HS + 0x67C)

/* --- Host channel 12 --- */
#define USB2_OTG_HS_OTG_HCCHAR12   (volatile unsigned int *)(USB2_OTG_HS + 0x680)
#define USB2_OTG_HS_OTG_HCSPLT12   (volatile unsigned int *)(USB2_OTG_HS + 0x684)
#define USB2_OTG_HS_OTG_HCINT12    (volatile unsigned int *)(USB2_OTG_HS + 0x688)
#define USB2_OTG_HS_OTG_HCINTMSK12 (volatile unsigned int *)(USB2_OTG_HS + 0x68C)
#define USB2_OTG_HS_OTG_HCTSIZ12   (volatile unsigned int *)(USB2_OTG_HS + 0x690)
#define USB2_OTG_HS_OTG_HCDMA12    (volatile unsigned int *)(USB2_OTG_HS + 0x694)
#define USB2_OTG_HS_OTG_HCDMAB12   (volatile unsigned int *)(USB2_OTG_HS + 0x69C)

/* --- Host channel 13 --- */
#define USB2_OTG_HS_OTG_HCCHAR13   (volatile unsigned int *)(USB2_OTG_HS + 0x6A0)
#define USB2_OTG_HS_OTG_HCSPLT13   (volatile unsigned int *)(USB2_OTG_HS + 0x6A4)
#define USB2_OTG_HS_OTG_HCINT13    (volatile unsigned int *)(USB2_OTG_HS + 0x6A8)
#define USB2_OTG_HS_OTG_HCINTMSK13 (volatile unsigned int *)(USB2_OTG_HS + 0x6AC)
#define USB2_OTG_HS_OTG_HCTSIZ13   (volatile unsigned int *)(USB2_OTG_HS + 0x6B0)
#define USB2_OTG_HS_OTG_HCDMA13    (volatile unsigned int *)(USB2_OTG_HS + 0x6B4)
#define USB2_OTG_HS_OTG_HCDMAB13   (volatile unsigned int *)(USB2_OTG_HS + 0x6BC)

/* --- Host channel 14 --- */
#define USB2_OTG_HS_OTG_HCCHAR14   (volatile unsigned int *)(USB2_OTG_HS + 0x6C0)
#define USB2_OTG_HS_OTG_HCSPLT14   (volatile unsigned int *)(USB2_OTG_HS + 0x6C4)
#define USB2_OTG_HS_OTG_HCINT14    (volatile unsigned int *)(USB2_OTG_HS + 0x6C8)
#define USB2_OTG_HS_OTG_HCINTMSK14 (volatile unsigned int *)(USB2_OTG_HS + 0x6CC)
#define USB2_OTG_HS_OTG_HCTSIZ14   (volatile unsigned int *)(USB2_OTG_HS + 0x6D0)
#define USB2_OTG_HS_OTG_HCDMA14    (volatile unsigned int *)(USB2_OTG_HS + 0x6D4)
#define USB2_OTG_HS_OTG_HCDMAB14   (volatile unsigned int *)(USB2_OTG_HS + 0x6DC)

/* --- Host channel 15 --- */
#define USB2_OTG_HS_OTG_HCCHAR15   (volatile unsigned int *)(USB2_OTG_HS + 0x6E0)
#define USB2_OTG_HS_OTG_HCSPLT15   (volatile unsigned int *)(USB2_OTG_HS + 0x6E4)
#define USB2_OTG_HS_OTG_HCINT15    (volatile unsigned int *)(USB2_OTG_HS + 0x6E8)
#define USB2_OTG_HS_OTG_HCINTMSK15 (volatile unsigned int *)(USB2_OTG_HS + 0x6EC)
#define USB2_OTG_HS_OTG_HCTSIZ15   (volatile unsigned int *)(USB2_OTG_HS + 0x6F0)
#define USB2_OTG_HS_OTG_HCDMA15    (volatile unsigned int *)(USB2_OTG_HS + 0x6F4)
#define USB2_OTG_HS_OTG_HCDMAB15   (volatile unsigned int *)(USB2_OTG_HS + 0x6FC)

/* --- Device-mode core --- */
#define USB2_OTG_HS_OTG_DCFG           (volatile unsigned int *)(USB2_OTG_HS + 0x800)
#define USB2_OTG_HS_OTG_DCTL           (volatile unsigned int *)(USB2_OTG_HS + 0x804)
#define USB2_OTG_HS_OTG_DSTS           (volatile unsigned int *)(USB2_OTG_HS + 0x808)
#define USB2_OTG_HS_OTG_DIEPMSK        (volatile unsigned int *)(USB2_OTG_HS + 0x810)
#define USB2_OTG_HS_OTG_DOEPMSK        (volatile unsigned int *)(USB2_OTG_HS + 0x814)
#define USB2_OTG_HS_OTG_DAINT          (volatile unsigned int *)(USB2_OTG_HS + 0x818)
#define USB2_OTG_HS_OTG_DAINTMSK       (volatile unsigned int *)(USB2_OTG_HS + 0x81C)
#define USB2_OTG_HS_OTG_DVBUSDIS       (volatile unsigned int *)(USB2_OTG_HS + 0x828)
#define USB2_OTG_HS_OTG_DVBUSPULSE     (volatile unsigned int *)(USB2_OTG_HS + 0x82C)
#define USB2_OTG_HS_OTG_DTHRCTL        (volatile unsigned int *)(USB2_OTG_HS + 0x830)
#define USB2_OTG_HS_OTG_DIEPEMPMSK     (volatile unsigned int *)(USB2_OTG_HS + 0x834)
#define USB2_OTG_HS_OTG_DEACHINT       (volatile unsigned int *)(USB2_OTG_HS + 0x838)
#define USB2_OTG_HS_OTG_DEACHINTMSK    (volatile unsigned int *)(USB2_OTG_HS + 0x83C)
#define USB2_OTG_HS_OTG_HS_DIEPEACHMSK1 (volatile unsigned int *)(USB2_OTG_HS + 0x844)
#define USB2_OTG_HS_OTG_HS_DOEPEACHMSK1 (volatile unsigned int *)(USB2_OTG_HS + 0x884)

/* --- Device IN endpoint 0 --- */
#define USB2_OTG_HS_OTG_DIEPCTL0       (volatile unsigned int *)(USB2_OTG_HS + 0x900)
#define USB2_OTG_HS_OTG_DIEPINT0       (volatile unsigned int *)(USB2_OTG_HS + 0x908)
#define USB2_OTG_HS_OTG_DIEPTSIZ0      (volatile unsigned int *)(USB2_OTG_HS + 0x910)
#define USB2_OTG_HS_OTG_DIEPDMA0       (volatile unsigned int *)(USB2_OTG_HS + 0x914)
#define USB2_OTG_HS_OTG_DTXFSTS0       (volatile unsigned int *)(USB2_OTG_HS + 0x918)

/* --- Device IN endpoint 1 --- */
#define USB2_OTG_HS_OTG_DIEPCTL1       (volatile unsigned int *)(USB2_OTG_HS + 0x920)
#define USB2_OTG_HS_OTG_DIEPINT1       (volatile unsigned int *)(USB2_OTG_HS + 0x928)
#define USB2_OTG_HS_OTG_DIEPTSIZ1      (volatile unsigned int *)(USB2_OTG_HS + 0x930)
#define USB2_OTG_HS_OTG_DIEPDMA1       (volatile unsigned int *)(USB2_OTG_HS + 0x934)
#define USB2_OTG_HS_OTG_DTXFSTS1       (volatile unsigned int *)(USB2_OTG_HS + 0x938)

/* --- Device IN endpoint 2 --- */
#define USB2_OTG_HS_OTG_DIEPCTL2       (volatile unsigned int *)(USB2_OTG_HS + 0x940)
#define USB2_OTG_HS_OTG_DIEPINT2       (volatile unsigned int *)(USB2_OTG_HS + 0x948)
#define USB2_OTG_HS_OTG_DIEPTSIZ2      (volatile unsigned int *)(USB2_OTG_HS + 0x950)
#define USB2_OTG_HS_OTG_DIEPDMA2       (volatile unsigned int *)(USB2_OTG_HS + 0x954)
#define USB2_OTG_HS_OTG_DTXFSTS2       (volatile unsigned int *)(USB2_OTG_HS + 0x958)

/* --- Device IN endpoint 3 --- */
#define USB2_OTG_HS_OTG_DIEPCTL3       (volatile unsigned int *)(USB2_OTG_HS + 0x960)
#define USB2_OTG_HS_OTG_DIEPINT3       (volatile unsigned int *)(USB2_OTG_HS + 0x968)
#define USB2_OTG_HS_OTG_DIEPTSIZ3      (volatile unsigned int *)(USB2_OTG_HS + 0x970)
#define USB2_OTG_HS_OTG_DIEPDMA3       (volatile unsigned int *)(USB2_OTG_HS + 0x974)
#define USB2_OTG_HS_OTG_DTXFSTS3       (volatile unsigned int *)(USB2_OTG_HS + 0x978)

/* --- Device IN endpoint 4 --- */
#define USB2_OTG_HS_OTG_DIEPCTL4       (volatile unsigned int *)(USB2_OTG_HS + 0x980)
#define USB2_OTG_HS_OTG_DIEPINT4       (volatile unsigned int *)(USB2_OTG_HS + 0x988)
#define USB2_OTG_HS_OTG_DIEPTSIZ4      (volatile unsigned int *)(USB2_OTG_HS + 0x990)
#define USB2_OTG_HS_OTG_DIEPDMA4       (volatile unsigned int *)(USB2_OTG_HS + 0x994)
#define USB2_OTG_HS_OTG_DTXFSTS4       (volatile unsigned int *)(USB2_OTG_HS + 0x998)

/* --- Device IN endpoint 5 --- */
#define USB2_OTG_HS_OTG_DIEPCTL5       (volatile unsigned int *)(USB2_OTG_HS + 0x9A0)
#define USB2_OTG_HS_OTG_DIEPINT5       (volatile unsigned int *)(USB2_OTG_HS + 0x9A8)
#define USB2_OTG_HS_OTG_DIEPTSIZ5      (volatile unsigned int *)(USB2_OTG_HS + 0x9B0)
#define USB2_OTG_HS_OTG_DIEPDMA5       (volatile unsigned int *)(USB2_OTG_HS + 0x9B4)
#define USB2_OTG_HS_OTG_DTXFSTS5       (volatile unsigned int *)(USB2_OTG_HS + 0x9B8)

/* --- Device IN endpoint 6 --- */
#define USB2_OTG_HS_OTG_DIEPCTL6       (volatile unsigned int *)(USB2_OTG_HS + 0x9C0)
#define USB2_OTG_HS_OTG_DIEPINT6       (volatile unsigned int *)(USB2_OTG_HS + 0x9C8)
#define USB2_OTG_HS_OTG_DIEPTSIZ6      (volatile unsigned int *)(USB2_OTG_HS + 0x9D0)
#define USB2_OTG_HS_OTG_DIEPDMA6       (volatile unsigned int *)(USB2_OTG_HS + 0x9D4)
#define USB2_OTG_HS_OTG_DTXFSTS6       (volatile unsigned int *)(USB2_OTG_HS + 0x9D8)

/* --- Device IN endpoint 7 --- */
#define USB2_OTG_HS_OTG_DIEPCTL7       (volatile unsigned int *)(USB2_OTG_HS + 0x9E0)
#define USB2_OTG_HS_OTG_DIEPINT7       (volatile unsigned int *)(USB2_OTG_HS + 0x9E8)
#define USB2_OTG_HS_OTG_DIEPTSIZ7      (volatile unsigned int *)(USB2_OTG_HS + 0x9F0)
#define USB2_OTG_HS_OTG_DIEPDMA7       (volatile unsigned int *)(USB2_OTG_HS + 0x9F4)
#define USB2_OTG_HS_OTG_DTXFSTS7       (volatile unsigned int *)(USB2_OTG_HS + 0x9F8)

/* --- Device OUT Endpoint 0 --- */
#define USB2_OTG_HS_OTG_DOEPCTL0       (volatile unsigned int *)(USB2_OTG_HS + 0xB00)
#define USB2_OTG_HS_OTG_DOEPINT0       (volatile unsigned int *)(USB2_OTG_HS + 0xB08)
#define USB2_OTG_HS_OTG_DOEPTSIZ0      (volatile unsigned int *)(USB2_OTG_HS + 0xB10)
#define USB2_OTG_HS_OTG_DOEPDMA0       (volatile unsigned int *)(USB2_OTG_HS + 0xB14)

/* --- Device OUT Endpoint 1 --- */
#define USB2_OTG_HS_OTG_DOEPCTL1       (volatile unsigned int *)(USB2_OTG_HS + 0xB20)
#define USB2_OTG_HS_OTG_DOEPINT1       (volatile unsigned int *)(USB2_OTG_HS + 0xB28)
#define USB2_OTG_HS_OTG_DOEPTSIZ1      (volatile unsigned int *)(USB2_OTG_HS + 0xB30)
#define USB2_OTG_HS_OTG_DOEPDMA1       (volatile unsigned int *)(USB2_OTG_HS + 0xB34)

/* --- Device OUT Endpoint 2 --- */
#define USB2_OTG_HS_OTG_DOEPCTL2       (volatile unsigned int *)(USB2_OTG_HS + 0xB40)
#define USB2_OTG_HS_OTG_DOEPINT2       (volatile unsigned int *)(USB2_OTG_HS + 0xB48)
#define USB2_OTG_HS_OTG_DOEPTSIZ2      (volatile unsigned int *)(USB2_OTG_HS + 0xB50)
#define USB2_OTG_HS_OTG_DOEPDMA2       (volatile unsigned int *)(USB2_OTG_HS + 0xB54)

/* --- Device OUT Endpoint 3 --- */
#define USB2_OTG_HS_OTG_DOEPCTL3       (volatile unsigned int *)(USB2_OTG_HS + 0xB60)
#define USB2_OTG_HS_OTG_DOEPINT3       (volatile unsigned int *)(USB2_OTG_HS + 0xB68)
#define USB2_OTG_HS_OTG_DOEPTSIZ3      (volatile unsigned int *)(USB2_OTG_HS + 0xB70)
#define USB2_OTG_HS_OTG_DOEPDMA3       (volatile unsigned int *)(USB2_OTG_HS + 0xB74)

/* --- Device OUT Endpoint 4 --- */
#define USB2_OTG_HS_OTG_DOEPCTL4       (volatile unsigned int *)(USB2_OTG_HS + 0xB80)
#define USB2_OTG_HS_OTG_DOEPINT4       (volatile unsigned int *)(USB2_OTG_HS + 0xB88)
#define USB2_OTG_HS_OTG_DOEPTSIZ4      (volatile unsigned int *)(USB2_OTG_HS + 0xB90)
#define USB2_OTG_HS_OTG_DOEPDMA4       (volatile unsigned int *)(USB2_OTG_HS + 0xB94)

/* --- Device OUT Endpoint 5 --- */
#define USB2_OTG_HS_OTG_DOEPCTL5       (volatile unsigned int *)(USB2_OTG_HS + 0xBA0)
#define USB2_OTG_HS_OTG_DOEPINT5       (volatile unsigned int *)(USB2_OTG_HS + 0xBA8)
#define USB2_OTG_HS_OTG_DOEPTSIZ5      (volatile unsigned int *)(USB2_OTG_HS + 0xBB0)
#define USB2_OTG_HS_OTG_DOEPDMA5       (volatile unsigned int *)(USB2_OTG_HS + 0xBB4)

/* --- Device OUT Endpoint 6 --- */
#define USB2_OTG_HS_OTG_DOEPCTL6       (volatile unsigned int *)(USB2_OTG_HS + 0xBC0)
#define USB2_OTG_HS_OTG_DOEPINT6       (volatile unsigned int *)(USB2_OTG_HS + 0xBC8)
#define USB2_OTG_HS_OTG_DOEPTSIZ6      (volatile unsigned int *)(USB2_OTG_HS + 0xBD0)
#define USB2_OTG_HS_OTG_DOEPDMA6       (volatile unsigned int *)(USB2_OTG_HS + 0xBD4)

/* --- Device OUT Endpoint 7 --- */
#define USB2_OTG_HS_OTG_DOEPCTL7       (volatile unsigned int *)(USB2_OTG_HS + 0xBE0)
#define USB2_OTG_HS_OTG_DOEPINT7       (volatile unsigned int *)(USB2_OTG_HS + 0xBE8)
#define USB2_OTG_HS_OTG_DOEPTSIZ7      (volatile unsigned int *)(USB2_OTG_HS + 0xBF0)
#define USB2_OTG_HS_OTG_DOEPDMA7       (volatile unsigned int *)(USB2_OTG_HS + 0xBF4)

/* --- Device OUT Endpoint 8 --- */
#define USB2_OTG_HS_OTG_DOEPCTL8       (volatile unsigned int *)(USB2_OTG_HS + 0xC00)
#define USB2_OTG_HS_OTG_DOEPINT8       (volatile unsigned int *)(USB2_OTG_HS + 0xC08)
#define USB2_OTG_HS_OTG_DOEPTSIZ8      (volatile unsigned int *)(USB2_OTG_HS + 0xC10)
#define USB2_OTG_HS_OTG_DOEPDMA8       (volatile unsigned int *)(USB2_OTG_HS + 0xC14)

/* --- Power and clock gating --- */
#define USB2_OTG_HS_OTG_PCGCCTL        (volatile unsigned int *)(USB2_OTG_HS + 0xE00)

#endif

