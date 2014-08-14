#define CONFIG_AIC79XX_CMDS_PER_DEVICE 32

#define CONFIG_AIC79XX_DEBUG_MASK 0

#define CONFIG_AIC79XX_RESET_DELAY_MS 5000

#define CONFIG_AIC7XXX_CMDS_PER_DEVICE 32

#define CONFIG_AIC7XXX_DEBUG_MASK 0

#define CONFIG_AIC7XXX_RESET_DELAY_MS 5000

#define CONFIG_ARCH "blackfin"

#define CONFIG_ATMEL_TCB_CLKSRC_BLOCK 0

#define CONFIG_ATM_FORE200E_DEBUG 0

#define CONFIG_ATM_FORE200E_TX_RETRY 16

#define CONFIG_BANK_0 0x7BB0

#define CONFIG_BANK_1 0x7BB0

#define CONFIG_BANK_2 0x7BB0

#define CONFIG_BANK_3 0x99B3

#undef CONFIG_BASE_SMALL
#if defined(CONFIG_BASE_FULL)
  #define CONFIG_BASE_SMALL 0
#endif
#if !defined(CONFIG_BASE_FULL)
  #define CONFIG_BASE_SMALL 1
#endif

#define CONFIG_BFIN_RX_DESC_NUM 20

#define CONFIG_BFIN_TX_DESC_NUM 10

#undef CONFIG_BF_REV_MAX
#if (defined(CONFIG_BF52x) || (defined(CONFIG_BF54x) && !defined(CONFIG_BF54xM)) || defined(CONFIG_BF51x))
  #define CONFIG_BF_REV_MAX 2
#endif
#if (!defined(CONFIG_BF52x) && (!defined(CONFIG_BF54x) || defined(CONFIG_BF54xM)) && !defined(CONFIG_BF51x) && (defined(CONFIG_BF534) || defined(CONFIG_BF54xM) || defined(CONFIG_BF536) || defined(CONFIG_BF537)))
  #define CONFIG_BF_REV_MAX 3
#endif
#if (!defined(CONFIG_BF537) && !defined(CONFIG_BF536) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF54xM) && (defined(CONFIG_BF538) || defined(CONFIG_BF539) || defined(CONFIG_BF561)) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534) && (!defined(CONFIG_BF54x) || defined(CONFIG_BF54xM)))
  #define CONFIG_BF_REV_MAX 5
#endif
#if (!defined(CONFIG_BF537) && !defined(CONFIG_BF538) && !defined(CONFIG_BF536) && !defined(CONFIG_BF561) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF539) && !defined(CONFIG_BF54xM) && (defined(CONFIG_BF532) || defined(CONFIG_BF531) || defined(CONFIG_BF533)) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534) && (!defined(CONFIG_BF54x) || defined(CONFIG_BF54xM)))
  #define CONFIG_BF_REV_MAX 6
#endif

#undef CONFIG_BF_REV_MIN
#if (defined(CONFIG_BF52x) || (defined(CONFIG_BF54x) && !defined(CONFIG_BF54xM)) || defined(CONFIG_BF51x))
  #define CONFIG_BF_REV_MIN 0
#endif
#if (!defined(CONFIG_BF52x) && (!defined(CONFIG_BF54x) || defined(CONFIG_BF54xM)) && !defined(CONFIG_BF51x) && (defined(CONFIG_BF534) || defined(CONFIG_BF536) || defined(CONFIG_BF537)))
  #define CONFIG_BF_REV_MIN 2
#endif
#if (!defined(CONFIG_BF537) && (defined(CONFIG_BF532) || defined(CONFIG_BF533) || defined(CONFIG_BF561) || defined(CONFIG_BF54xM) || defined(CONFIG_BF531)) && !defined(CONFIG_BF536) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534) && (!defined(CONFIG_BF54x) || defined(CONFIG_BF54xM)))
  #define CONFIG_BF_REV_MIN 3
#endif
#if (!defined(CONFIG_BF537) && !defined(CONFIG_BF532) && !defined(CONFIG_BF531) && !defined(CONFIG_BF536) && !defined(CONFIG_BF561) && (defined(CONFIG_BF538) || defined(CONFIG_BF539)) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF533) && !defined(CONFIG_BF54xM) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534) && (!defined(CONFIG_BF54x) || defined(CONFIG_BF54xM)))
  #define CONFIG_BF_REV_MIN 4
#endif

#define CONFIG_BLK_DEV_RAM_COUNT 16

#define CONFIG_BLK_DEV_RAM_SIZE 4096

#undef CONFIG_BOOTPARAM_HUNG_TASK_PANIC_VALUE
#if (defined(CONFIG_DETECT_HUNG_TASK) && !defined(CONFIG_BOOTPARAM_HUNG_TASK_PANIC))
  #define CONFIG_BOOTPARAM_HUNG_TASK_PANIC_VALUE 0
#endif
#if (defined(CONFIG_DETECT_HUNG_TASK) && defined(CONFIG_BOOTPARAM_HUNG_TASK_PANIC) && (!defined(CONFIG_DETECT_HUNG_TASK) || defined(CONFIG_BOOTPARAM_HUNG_TASK_PANIC)))
  #define CONFIG_BOOTPARAM_HUNG_TASK_PANIC_VALUE 1
#endif

#undef CONFIG_BOOTPARAM_SOFTLOCKUP_PANIC_VALUE
#if (defined(CONFIG_DETECT_SOFTLOCKUP) && !defined(CONFIG_BOOTPARAM_SOFTLOCKUP_PANIC))
  #define CONFIG_BOOTPARAM_SOFTLOCKUP_PANIC_VALUE 0
#endif
#if (defined(CONFIG_DETECT_SOFTLOCKUP) && defined(CONFIG_BOOTPARAM_SOFTLOCKUP_PANIC) && (!defined(CONFIG_DETECT_SOFTLOCKUP) || defined(CONFIG_BOOTPARAM_SOFTLOCKUP_PANIC)))
  #define CONFIG_BOOTPARAM_SOFTLOCKUP_PANIC_VALUE 1
#endif

#define CONFIG_BOOT_LOAD 0x1000

#define CONFIG_CDROM_PKTCDVD_BUFFERS 8

#define CONFIG_CFAG12864B_RATE 20

#undef CONFIG_CLKIN_HZ
#if (!defined(CONFIG_BFIN532_IP0X) && !defined(CONFIG_BFIN533_STAMP) && !defined(CONFIG_PNAV10))
  #define CONFIG_CLKIN_HZ 25000000
#endif
#if (!defined(CONFIG_BFIN532_IP0X) && !defined(CONFIG_BFIN533_STAMP) && defined(CONFIG_PNAV10))
  #define CONFIG_CLKIN_HZ 24576000
#endif
#if defined(CONFIG_BFIN532_IP0X)
  #define CONFIG_CLKIN_HZ 10000000
#endif
#if (defined(CONFIG_BFIN533_STAMP) && !defined(CONFIG_BFIN532_IP0X))
  #define CONFIG_CLKIN_HZ 11059200
#endif

#define CONFIG_CMDLINE "console=ttyBF0,57600"

#define CONFIG_CS5535_MFGPT_DEFAULT_IRQ 7

#define CONFIG_DE2104X_DSL 0

#undef CONFIG_DEBUG_BFIN_HWTRACE_COMPRESSION
#if (defined(CONFIG_DEBUG_BFIN_HWTRACE_ON) && defined(CONFIG_DEBUG_BFIN_HWTRACE_COMPRESSION_OFF))
  #define CONFIG_DEBUG_BFIN_HWTRACE_COMPRESSION 0
#endif
#if (defined(CONFIG_DEBUG_BFIN_HWTRACE_ON) && defined(CONFIG_DEBUG_BFIN_HWTRACE_COMPRESSION_ONE) && (!defined(CONFIG_DEBUG_BFIN_HWTRACE_ON) || !defined(CONFIG_DEBUG_BFIN_HWTRACE_COMPRESSION_OFF)))
  #define CONFIG_DEBUG_BFIN_HWTRACE_COMPRESSION 1
#endif
#if (defined(CONFIG_DEBUG_BFIN_HWTRACE_ON) && defined(CONFIG_DEBUG_BFIN_HWTRACE_COMPRESSION_TWO) && (!defined(CONFIG_DEBUG_BFIN_HWTRACE_ON) || !defined(CONFIG_DEBUG_BFIN_HWTRACE_COMPRESSION_ONE)) && (!defined(CONFIG_DEBUG_BFIN_HWTRACE_ON) || !defined(CONFIG_DEBUG_BFIN_HWTRACE_COMPRESSION_OFF)))
  #define CONFIG_DEBUG_BFIN_HWTRACE_COMPRESSION 2
#endif

#define CONFIG_DEBUG_BFIN_HWTRACE_EXPAND_LEN 1

#define CONFIG_DEBUG_KMEMLEAK_EARLY_LOG_SIZE 400

#define CONFIG_DEBUG_OBJECTS_ENABLE_DEFAULT 1

#undef CONFIG_DEFAULT_IOSCHED
#if (defined(CONFIG_BLOCK) && defined(CONFIG_DEFAULT_DEADLINE))
  #define CONFIG_DEFAULT_IOSCHED "deadline"
#endif
#if (defined(CONFIG_BLOCK) && defined(CONFIG_DEFAULT_CFQ) && (!defined(CONFIG_BLOCK) || !defined(CONFIG_DEFAULT_DEADLINE)))
  #define CONFIG_DEFAULT_IOSCHED "cfq"
#endif
#if (defined(CONFIG_BLOCK) && defined(CONFIG_DEFAULT_NOOP) && (!defined(CONFIG_BLOCK) || !defined(CONFIG_DEFAULT_CFQ)) && (!defined(CONFIG_BLOCK) || !defined(CONFIG_DEFAULT_DEADLINE)))
  #define CONFIG_DEFAULT_IOSCHED "noop"
#endif

#define CONFIG_DEFAULT_MMAP_MIN_ADDR 4096

#undef CONFIG_DEFAULT_SECURITY
#if defined(CONFIG_DEFAULT_SECURITY_SELINUX)
  #define CONFIG_DEFAULT_SECURITY "selinux"
#endif
#if (defined(CONFIG_DEFAULT_SECURITY_SMACK) && !defined(CONFIG_DEFAULT_SECURITY_SELINUX))
  #define CONFIG_DEFAULT_SECURITY "smack"
#endif
#if (!defined(CONFIG_DEFAULT_SECURITY_SELINUX) && !defined(CONFIG_DEFAULT_SECURITY_SMACK) && defined(CONFIG_DEFAULT_SECURITY_TOMOYO))
  #define CONFIG_DEFAULT_SECURITY "tomoyo"
#endif
#if (!defined(CONFIG_DEFAULT_SECURITY_SELINUX) && !defined(CONFIG_DEFAULT_SECURITY_SMACK) && !defined(CONFIG_DEFAULT_SECURITY_TOMOYO) && defined(CONFIG_DEFAULT_SECURITY_DAC))
  #define CONFIG_DEFAULT_SECURITY ""
#endif

#undef CONFIG_DEFAULT_TCP_CONG
#if (defined(CONFIG_NET) && defined(CONFIG_DEFAULT_WESTWOOD) && (!defined(CONFIG_INET) || !defined(CONFIG_DEFAULT_CUBIC) || !defined(CONFIG_NET)) && (!defined(CONFIG_INET) || !defined(CONFIG_DEFAULT_HTCP) || !defined(CONFIG_NET)) && (!defined(CONFIG_INET) || !defined(CONFIG_DEFAULT_VEGAS) || !defined(CONFIG_NET)) && defined(CONFIG_INET) && (!defined(CONFIG_INET) || !defined(CONFIG_DEFAULT_BIC) || !defined(CONFIG_NET)))
  #define CONFIG_DEFAULT_TCP_CONG "westwood"
#endif
#if (defined(CONFIG_NET) && defined(CONFIG_DEFAULT_HTCP) && (!defined(CONFIG_INET) || !defined(CONFIG_DEFAULT_CUBIC) || !defined(CONFIG_NET)) && defined(CONFIG_INET) && (!defined(CONFIG_INET) || !defined(CONFIG_DEFAULT_BIC) || !defined(CONFIG_NET)))
  #define CONFIG_DEFAULT_TCP_CONG "htcp"
#endif
#if (defined(CONFIG_INET) && defined(CONFIG_DEFAULT_BIC) && defined(CONFIG_NET))
  #define CONFIG_DEFAULT_TCP_CONG "bic"
#endif
#if ((defined(CONFIG_INET) && defined(CONFIG_DEFAULT_CUBIC) && defined(CONFIG_NET) && (!defined(CONFIG_INET) || !defined(CONFIG_DEFAULT_BIC) || !defined(CONFIG_NET))) || (defined(CONFIG_NET) && (!defined(CONFIG_INET) || !defined(CONFIG_DEFAULT_WESTWOOD) || !defined(CONFIG_NET)) && (!defined(CONFIG_INET) || !defined(CONFIG_DEFAULT_RENO) || !defined(CONFIG_NET)) && (!defined(CONFIG_INET) || !defined(CONFIG_DEFAULT_CUBIC) || !defined(CONFIG_NET)) && (!defined(CONFIG_INET) || !defined(CONFIG_DEFAULT_HTCP) || !defined(CONFIG_NET)) && (!defined(CONFIG_INET) || !defined(CONFIG_DEFAULT_VEGAS) || !defined(CONFIG_NET)) && defined(CONFIG_INET) && (!defined(CONFIG_INET) || !defined(CONFIG_DEFAULT_BIC) || !defined(CONFIG_NET))))
  #define CONFIG_DEFAULT_TCP_CONG "cubic"
#endif
#if (defined(CONFIG_DEFAULT_RENO) && defined(CONFIG_NET) && (!defined(CONFIG_INET) || !defined(CONFIG_DEFAULT_WESTWOOD) || !defined(CONFIG_NET)) && (!defined(CONFIG_INET) || !defined(CONFIG_DEFAULT_CUBIC) || !defined(CONFIG_NET)) && (!defined(CONFIG_INET) || !defined(CONFIG_DEFAULT_HTCP) || !defined(CONFIG_NET)) && (!defined(CONFIG_INET) || !defined(CONFIG_DEFAULT_VEGAS) || !defined(CONFIG_NET)) && defined(CONFIG_INET) && (!defined(CONFIG_INET) || !defined(CONFIG_DEFAULT_BIC) || !defined(CONFIG_NET)))
  #define CONFIG_DEFAULT_TCP_CONG "reno"
#endif
#if (defined(CONFIG_NET) && (!defined(CONFIG_INET) || !defined(CONFIG_DEFAULT_CUBIC) || !defined(CONFIG_NET)) && (!defined(CONFIG_INET) || !defined(CONFIG_DEFAULT_HTCP) || !defined(CONFIG_NET)) && defined(CONFIG_DEFAULT_VEGAS) && defined(CONFIG_INET) && (!defined(CONFIG_INET) || !defined(CONFIG_DEFAULT_BIC) || !defined(CONFIG_NET)))
  #define CONFIG_DEFAULT_TCP_CONG "vegas"
#endif

#define CONFIG_DEFCONFIG_LIST "/lib/modules/$UNAME_RELEASE/.config"

#define CONFIG_DLCI_MAX 8

#define CONFIG_DM9000_DEBUGLEVEL 4

#define CONFIG_DMA0_PPI 8

#define CONFIG_DMA1_SPORT0RX 9

#define CONFIG_DMA2_SPORT0TX 9

#define CONFIG_DMA3_SPORT1RX 9

#define CONFIG_DMA4_SPORT1TX 9

#define CONFIG_DMA5_SPI 10

#define CONFIG_DMA6_UARTRX 10

#define CONFIG_DMA7_UARTTX 10

#define CONFIG_DMA_ERROR 7

#undef CONFIG_DUMMY_CONSOLE_COLUMNS

#undef CONFIG_DUMMY_CONSOLE_ROWS

#define CONFIG_DVB_MAX_ADAPTERS 8

#define CONFIG_EBIU_FCTLVAL 6

#define CONFIG_EBIU_MBSCTLVAL 0

#define CONFIG_EBIU_MODEVAL 1

#undef CONFIG_EXTRA_FIRMWARE

#define CONFIG_EXTRA_FIRMWARE_DIR "firmware"

#define CONFIG_FAT_DEFAULT_CODEPAGE 437

#define CONFIG_FAT_DEFAULT_IOCHARSET "iso8859-1"

#define CONFIG_FB_GBE_MEM 4

#define CONFIG_FB_OMAP2_NUM_FBS 3

#define CONFIG_FB_OMAP_CONSISTENT_DMA_SIZE 2

#define CONFIG_FB_PS3_DEFAULT_SIZE_M 9

#define CONFIG_FORCE_MAX_ZONEORDER 14

#define CONFIG_FRAME_WARN 1024

#define CONFIG_FUSION_MAX_SGE 128

#define CONFIG_HISAX_MAX_CARDS 8

#undef CONFIG_HZ
#if defined(CONFIG_HZ_100)
  #define CONFIG_HZ 100
#endif
#if (defined(CONFIG_HZ_250) && !defined(CONFIG_HZ_100))
  #define CONFIG_HZ 250
#endif
#if (!defined(CONFIG_HZ_100) && !defined(CONFIG_HZ_250) && defined(CONFIG_HZ_300))
  #define CONFIG_HZ 300
#endif
#if (!defined(CONFIG_HZ_100) && !defined(CONFIG_HZ_250) && !defined(CONFIG_HZ_300) && defined(CONFIG_HZ_1000))
  #define CONFIG_HZ 1000
#endif

#define CONFIG_I2C_BLACKFIN_TWI_CLK_KHZ 50

#define CONFIG_IBM_NEW_EMAC_POLL_WEIGHT 32

#define CONFIG_IBM_NEW_EMAC_RXB 128

#define CONFIG_IBM_NEW_EMAC_RX_COPY_THRESHOLD 256

#define CONFIG_IBM_NEW_EMAC_RX_SKB_HEADROOM 0

#define CONFIG_IBM_NEW_EMAC_TXB 64

#define CONFIG_IMA_MEASURE_PCR_IDX 10

#define CONFIG_INITRAMFS_ROOT_GID 0

#define CONFIG_INITRAMFS_ROOT_UID 0

#define CONFIG_INITRAMFS_SOURCE ""

#define CONFIG_INIT_ENV_ARG_LIMIT 32

#define CONFIG_INPUT_MOUSEDEV_SCREEN_X 1024

#define CONFIG_INPUT_MOUSEDEV_SCREEN_Y 768

#define CONFIG_IP_DCCP_CCID3_RTO 100

#define CONFIG_IP_VS_TAB_BITS 12

#define CONFIG_IRQ_ATAPI_ERR 7

#define CONFIG_IRQ_ATAPI_RX 10

#define CONFIG_IRQ_ATAPI_TX 10

#define CONFIG_IRQ_CAN0_ERR 7

#define CONFIG_IRQ_CAN0_RX 11

#define CONFIG_IRQ_CAN0_TX 11

#define CONFIG_IRQ_CAN1_ERR 7

#define CONFIG_IRQ_CAN1_RX 11

#define CONFIG_IRQ_CAN1_TX 11

#define CONFIG_IRQ_CAN_ERROR 7

#define CONFIG_IRQ_CAN_RX 11

#define CONFIG_IRQ_CAN_TX 11

#undef CONFIG_IRQ_CNT
#if (defined(CONFIG_BF52x) || defined(CONFIG_BF51x))
  #define CONFIG_IRQ_CNT 11
#endif
#if (!defined(CONFIG_BF52x) && !defined(CONFIG_BF51x) && defined(CONFIG_BF54x))
  #define CONFIG_IRQ_CNT 8
#endif

#define CONFIG_IRQ_DMA0_ERROR 7

#define CONFIG_IRQ_DMA1_0 8

#define CONFIG_IRQ_DMA1_1 8

#define CONFIG_IRQ_DMA1_10 8

#define CONFIG_IRQ_DMA1_11 8

#define CONFIG_IRQ_DMA1_2 8

#define CONFIG_IRQ_DMA1_3 8

#define CONFIG_IRQ_DMA1_4 8

#define CONFIG_IRQ_DMA1_5 8

#define CONFIG_IRQ_DMA1_6 8

#define CONFIG_IRQ_DMA1_7 8

#define CONFIG_IRQ_DMA1_8 8

#define CONFIG_IRQ_DMA1_9 8

#define CONFIG_IRQ_DMA1_ERROR 7

#define CONFIG_IRQ_DMA1_WRRD0 8

#define CONFIG_IRQ_DMA1_WRRD1 8

#define CONFIG_IRQ_DMA2_0 9

#define CONFIG_IRQ_DMA2_1 9

#define CONFIG_IRQ_DMA2_10 9

#define CONFIG_IRQ_DMA2_11 9

#define CONFIG_IRQ_DMA2_2 9

#define CONFIG_IRQ_DMA2_3 9

#define CONFIG_IRQ_DMA2_4 9

#define CONFIG_IRQ_DMA2_5 9

#define CONFIG_IRQ_DMA2_6 9

#define CONFIG_IRQ_DMA2_7 9

#define CONFIG_IRQ_DMA2_8 9

#define CONFIG_IRQ_DMA2_9 9

#define CONFIG_IRQ_DMA2_ERROR 7

#define CONFIG_IRQ_DMA2_WRRD0 9

#define CONFIG_IRQ_DMA2_WRRD1 9

#define CONFIG_IRQ_DMAC0_ERR 7

#define CONFIG_IRQ_DMAC1_ERR 7

#define CONFIG_IRQ_DMAR0_BLK 7

#define CONFIG_IRQ_DMAR0_OVR 7

#define CONFIG_IRQ_DMAR1_BLK 7

#define CONFIG_IRQ_DMAR1_OVR 7

#define CONFIG_IRQ_DMA_ERROR 7

#define CONFIG_IRQ_EPPI0 8

#define CONFIG_IRQ_EPPI0_ERR 7

#define CONFIG_IRQ_EPPI1 9

#define CONFIG_IRQ_EPPI1_ERR 7

#define CONFIG_IRQ_EPPI2 9

#define CONFIG_IRQ_EPPI2_ERR 7

#define CONFIG_IRQ_ERROR 7

#define CONFIG_IRQ_HDMA 7

#define CONFIG_IRQ_HDMA_ERROR 7

#define CONFIG_IRQ_HOST_ERR 7

#define CONFIG_IRQ_HS_DMA_ERR 7

#define CONFIG_IRQ_IMDMA_ERROR 7

#define CONFIG_IRQ_IMDMA_WRRD0 12

#define CONFIG_IRQ_IMDMA_WRRD1 12

#define CONFIG_IRQ_KEY 8

#define CONFIG_IRQ_MAC_ERROR 7

#define CONFIG_IRQ_MAC_RX 11

#define CONFIG_IRQ_MAC_TX 11

#define CONFIG_IRQ_MDMAS0 13

#define CONFIG_IRQ_MDMAS1 13

#define CONFIG_IRQ_MDMAS2 13

#define CONFIG_IRQ_MDMAS3 13

#define CONFIG_IRQ_MEM0_DMA0 13

#define CONFIG_IRQ_MEM0_DMA1 13

#define CONFIG_IRQ_MEM1_DMA0 13

#define CONFIG_IRQ_MEM1_DMA1 13

#define CONFIG_IRQ_MEM_DMA0 13

#define CONFIG_IRQ_MEM_DMA1 13

#define CONFIG_IRQ_MXVR_DATA 7

#define CONFIG_IRQ_MXVR_ERR 11

#define CONFIG_IRQ_MXVR_MSG 11

#define CONFIG_IRQ_MXVR_PKT 11

#define CONFIG_IRQ_NFC_ERR 7

#define CONFIG_IRQ_NFC_ERROR 7

#define CONFIG_IRQ_OPTSEC 11

#define CONFIG_IRQ_OTPSEC 11

#define CONFIG_IRQ_PINT0 12

#define CONFIG_IRQ_PINT1 12

#define CONFIG_IRQ_PINT2 11

#define CONFIG_IRQ_PINT3 11

#define CONFIG_IRQ_PIXC_ERR 7

#define CONFIG_IRQ_PIXC_IN0 8

#define CONFIG_IRQ_PIXC_IN1 8

#define CONFIG_IRQ_PIXC_OUT 8

#define CONFIG_IRQ_PLL_WAKEUP 7

#undef CONFIG_IRQ_PORTF_INTA
#if (defined(CONFIG_BF52x) || defined(CONFIG_BF51x))
  #define CONFIG_IRQ_PORTF_INTA 13
#endif
#if ((!defined(CONFIG_BF52x) && !defined(CONFIG_BF51x) && (defined(CONFIG_BF538) || defined(CONFIG_BF539))) || (!defined(CONFIG_BF538) && (defined(CONFIG_BF538) || defined(CONFIG_BF539)) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF539) && !defined(CONFIG_BF52x)))
  #define CONFIG_IRQ_PORTF_INTA 12
#endif

#undef CONFIG_IRQ_PORTF_INTB
#if (defined(CONFIG_BF52x) || defined(CONFIG_BF51x))
  #define CONFIG_IRQ_PORTF_INTB 13
#endif
#if ((!defined(CONFIG_BF52x) && !defined(CONFIG_BF51x) && (defined(CONFIG_BF538) || defined(CONFIG_BF539))) || (!defined(CONFIG_BF538) && (defined(CONFIG_BF538) || defined(CONFIG_BF539)) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF539) && !defined(CONFIG_BF52x)))
  #define CONFIG_IRQ_PORTF_INTB 12
#endif

#define CONFIG_IRQ_PORTG_INTA 12

#define CONFIG_IRQ_PORTG_INTB 12

#define CONFIG_IRQ_PORTH_INTA 11

#define CONFIG_IRQ_PORTH_INTB 11

#define CONFIG_IRQ_PPI 8

#define CONFIG_IRQ_PPI0_ERROR 7

#define CONFIG_IRQ_PPI1_ERROR 7

#define CONFIG_IRQ_PPI_ERROR 7

#define CONFIG_IRQ_PROG0_INTA 11

#define CONFIG_IRQ_PROG0_INTB 11

#define CONFIG_IRQ_PROG1_INTA 11

#define CONFIG_IRQ_PROG1_INTB 11

#define CONFIG_IRQ_PROG2_INTA 11

#define CONFIG_IRQ_PROG2_INTB 11

#define CONFIG_IRQ_PROG_INTA 12

#define CONFIG_IRQ_PTP_ERROR 7

#define CONFIG_IRQ_PTP_STAT 10

#define CONFIG_IRQ_PWM_SYNC 10

#define CONFIG_IRQ_PWM_TRIP 10

#define CONFIG_IRQ_RESERVED_ERROR 7

#define CONFIG_IRQ_RSI_INT0 7

#define CONFIG_IRQ_RSI_INT1 7

#define CONFIG_IRQ_RTC 8

#define CONFIG_IRQ_SDH 8

#define CONFIG_IRQ_SDH_MASK0 11

#define CONFIG_IRQ_SDH_MASK1 11

#define CONFIG_IRQ_SPI 10

#define CONFIG_IRQ_SPI0 10

#define CONFIG_IRQ_SPI0_ERR 7

#define CONFIG_IRQ_SPI0_ERROR 7

#define CONFIG_IRQ_SPI1 10

#define CONFIG_IRQ_SPI1_ERR 7

#define CONFIG_IRQ_SPI1_ERROR 7

#define CONFIG_IRQ_SPI2 10

#define CONFIG_IRQ_SPI2_ERR 7

#define CONFIG_IRQ_SPI2_ERROR 7

#define CONFIG_IRQ_SPI_ERROR 7

#define CONFIG_IRQ_SPORT0_ERR 7

#define CONFIG_IRQ_SPORT0_ERROR 7

#define CONFIG_IRQ_SPORT0_RX 9

#define CONFIG_IRQ_SPORT0_TX 9

#define CONFIG_IRQ_SPORT1_ERR 7

#define CONFIG_IRQ_SPORT1_ERROR 7

#define CONFIG_IRQ_SPORT1_RX 9

#define CONFIG_IRQ_SPORT1_TX 9

#define CONFIG_IRQ_SPORT2_ERR 7

#define CONFIG_IRQ_SPORT2_ERROR 7

#define CONFIG_IRQ_SPORT2_RX 9

#define CONFIG_IRQ_SPORT2_TX 9

#define CONFIG_IRQ_SPORT3_ERR 7

#define CONFIG_IRQ_SPORT3_ERROR 7

#define CONFIG_IRQ_SPORT3_RX 9

#define CONFIG_IRQ_SPORT3_TX 9

#undef CONFIG_IRQ_TIMER0
#if ((!defined(CONFIG_BF537) && defined(CONFIG_TICKSOURCE_GPTMR0) && (!defined(CONFIG_BF561) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && !defined(CONFIG_BF538) && !defined(CONFIG_BF536) && (!defined(CONFIG_BF54x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && (!defined(CONFIG_TICKSOURCE_GPTMR0) || (!defined(CONFIG_BF534) && !defined(CONFIG_BF536) && !defined(CONFIG_BF537))) && !defined(CONFIG_BF561) && (!defined(CONFIG_BF52x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF539) && (defined(CONFIG_BF534) || defined(CONFIG_BF536) || defined(CONFIG_BF537)) && (!defined(CONFIG_TICKSOURCE_GPTMR0) || (!defined(CONFIG_BF538) && !defined(CONFIG_BF539))) && (!defined(CONFIG_BF51x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && !defined(CONFIG_BF54x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534)) || (defined(CONFIG_TICKSOURCE_GPTMR0) && (!defined(CONFIG_BF561) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && !defined(CONFIG_BF561) && (!defined(CONFIG_BF52x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && !defined(CONFIG_BF51x) && (defined(CONFIG_BF534) || defined(CONFIG_BF536) || defined(CONFIG_BF537)) && !defined(CONFIG_BF52x)) || (defined(CONFIG_BF51x) && defined(CONFIG_TICKSOURCE_GPTMR0)) || (!defined(CONFIG_BF537) && defined(CONFIG_TICKSOURCE_GPTMR0) && (!defined(CONFIG_BF561) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && !defined(CONFIG_BF536) && (!defined(CONFIG_TICKSOURCE_GPTMR0) || (!defined(CONFIG_BF534) && !defined(CONFIG_BF536) && !defined(CONFIG_BF537))) && !defined(CONFIG_BF561) && (!defined(CONFIG_BF52x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && (defined(CONFIG_BF538) || defined(CONFIG_BF539)) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534)) || (defined(CONFIG_TICKSOURCE_GPTMR0) && (!defined(CONFIG_BF52x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && !defined(CONFIG_BF51x) && defined(CONFIG_BF561) && !defined(CONFIG_BF52x)) || (!defined(CONFIG_BF537) && defined(CONFIG_TICKSOURCE_GPTMR0) && (!defined(CONFIG_BF561) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && !defined(CONFIG_BF538) && !defined(CONFIG_BF536) && (!defined(CONFIG_TICKSOURCE_GPTMR0) || (!defined(CONFIG_BF534) && !defined(CONFIG_BF536) && !defined(CONFIG_BF537))) && !defined(CONFIG_BF561) && (!defined(CONFIG_BF52x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF539) && defined(CONFIG_BF54x) && (!defined(CONFIG_TICKSOURCE_GPTMR0) || (!defined(CONFIG_BF538) && !defined(CONFIG_BF539))) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534)) || (!defined(CONFIG_BF537) && defined(CONFIG_TICKSOURCE_GPTMR0) && (!defined(CONFIG_BF561) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && !defined(CONFIG_BF538) && !defined(CONFIG_BF536) && (!defined(CONFIG_BF54x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && (!defined(CONFIG_TICKSOURCE_GPTMR0) || (!defined(CONFIG_BF534) && !defined(CONFIG_BF536) && !defined(CONFIG_BF537))) && !defined(CONFIG_BF561) && (!defined(CONFIG_BF52x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && (defined(CONFIG_BF538) || defined(CONFIG_BF539)) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF539) && (!defined(CONFIG_TICKSOURCE_GPTMR0) || (!defined(CONFIG_BF538) && !defined(CONFIG_BF539))) && (!defined(CONFIG_BF51x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && !defined(CONFIG_BF54x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534)) || (defined(CONFIG_BF52x) && defined(CONFIG_TICKSOURCE_GPTMR0) && !defined(CONFIG_BF51x)))
  #define CONFIG_IRQ_TIMER0 7
#endif
#if ((!defined(CONFIG_BF537) && (!defined(CONFIG_BF561) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && !defined(CONFIG_BF538) && !defined(CONFIG_BF536) && (!defined(CONFIG_BF54x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && (!defined(CONFIG_TICKSOURCE_GPTMR0) || (!defined(CONFIG_BF534) && !defined(CONFIG_BF536) && !defined(CONFIG_BF537))) && !defined(CONFIG_BF561) && (!defined(CONFIG_BF52x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF539) && (defined(CONFIG_BF534) || defined(CONFIG_BF536) || defined(CONFIG_BF537)) && (!defined(CONFIG_TICKSOURCE_GPTMR0) || (!defined(CONFIG_BF538) && !defined(CONFIG_BF539))) && (!defined(CONFIG_BF51x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && !defined(CONFIG_BF54x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534)) || (defined(CONFIG_BF51x) && !defined(CONFIG_TICKSOURCE_GPTMR0)) || ((!defined(CONFIG_BF561) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && (!defined(CONFIG_TICKSOURCE_GPTMR0) || (!defined(CONFIG_BF534) && !defined(CONFIG_BF536) && !defined(CONFIG_BF537))) && !defined(CONFIG_BF561) && (!defined(CONFIG_BF52x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && !defined(CONFIG_BF51x) && (defined(CONFIG_BF534) || defined(CONFIG_BF536) || defined(CONFIG_BF537)) && !defined(CONFIG_BF52x)) || (!defined(CONFIG_BF537) && (!defined(CONFIG_BF561) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && !defined(CONFIG_BF536) && (!defined(CONFIG_TICKSOURCE_GPTMR0) || (!defined(CONFIG_BF534) && !defined(CONFIG_BF536) && !defined(CONFIG_BF537))) && !defined(CONFIG_BF561) && (!defined(CONFIG_BF52x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && (defined(CONFIG_BF538) || defined(CONFIG_BF539)) && !defined(CONFIG_BF51x) && (!defined(CONFIG_TICKSOURCE_GPTMR0) || (!defined(CONFIG_BF538) && !defined(CONFIG_BF539))) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534)) || ((!defined(CONFIG_BF561) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && (!defined(CONFIG_BF52x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && !defined(CONFIG_BF51x) && defined(CONFIG_BF561) && !defined(CONFIG_BF52x)) || (!defined(CONFIG_BF51x) && (!defined(CONFIG_BF52x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && defined(CONFIG_BF52x)) || (!defined(CONFIG_BF537) && (!defined(CONFIG_BF561) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && !defined(CONFIG_BF538) && !defined(CONFIG_BF536) && (!defined(CONFIG_BF54x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && (!defined(CONFIG_TICKSOURCE_GPTMR0) || (!defined(CONFIG_BF534) && !defined(CONFIG_BF536) && !defined(CONFIG_BF537))) && !defined(CONFIG_BF561) && (!defined(CONFIG_BF52x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF539) && defined(CONFIG_BF54x) && (!defined(CONFIG_TICKSOURCE_GPTMR0) || (!defined(CONFIG_BF538) && !defined(CONFIG_BF539))) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534)) || (!defined(CONFIG_BF537) && (!defined(CONFIG_BF561) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && !defined(CONFIG_BF538) && !defined(CONFIG_BF536) && (!defined(CONFIG_BF54x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && (!defined(CONFIG_TICKSOURCE_GPTMR0) || (!defined(CONFIG_BF534) && !defined(CONFIG_BF536) && !defined(CONFIG_BF537))) && !defined(CONFIG_BF561) && (!defined(CONFIG_BF52x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && (defined(CONFIG_BF538) || defined(CONFIG_BF539)) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF539) && (!defined(CONFIG_TICKSOURCE_GPTMR0) || (!defined(CONFIG_BF538) && !defined(CONFIG_BF539))) && (!defined(CONFIG_BF51x) || !defined(CONFIG_TICKSOURCE_GPTMR0)) && !defined(CONFIG_BF54x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534)))
  #define CONFIG_IRQ_TIMER0 8
#endif

#undef CONFIG_IRQ_TIMER1
#if (defined(CONFIG_BF52x) || defined(CONFIG_BF51x) || (!defined(CONFIG_BF52x) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF561) && (defined(CONFIG_BF534) || defined(CONFIG_BF536) || defined(CONFIG_BF537))) || (!defined(CONFIG_BF537) && !defined(CONFIG_BF538) && !defined(CONFIG_BF536) && !defined(CONFIG_BF561) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF539) && (defined(CONFIG_BF534) || defined(CONFIG_BF536) || defined(CONFIG_BF537)) && !defined(CONFIG_BF54x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534)))
  #define CONFIG_IRQ_TIMER1 12
#endif
#if (!defined(CONFIG_BF52x) && !defined(CONFIG_BF51x) && defined(CONFIG_BF561))
  #define CONFIG_IRQ_TIMER1 10
#endif
#if ((!defined(CONFIG_BF537) && !defined(CONFIG_BF536) && !defined(CONFIG_BF561) && (defined(CONFIG_BF538) || defined(CONFIG_BF539)) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534)) || (!defined(CONFIG_BF537) && !defined(CONFIG_BF538) && !defined(CONFIG_BF536) && !defined(CONFIG_BF561) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF539) && defined(CONFIG_BF54x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534)) || (!defined(CONFIG_BF537) && !defined(CONFIG_BF538) && !defined(CONFIG_BF536) && !defined(CONFIG_BF561) && (defined(CONFIG_BF538) || defined(CONFIG_BF539)) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF539) && !defined(CONFIG_BF54x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534)))
  #define CONFIG_IRQ_TIMER1 11
#endif

#undef CONFIG_IRQ_TIMER10
#if defined(CONFIG_BF561)
  #define CONFIG_IRQ_TIMER10 10
#endif
#if (defined(CONFIG_BF54x) && !defined(CONFIG_BF561))
  #define CONFIG_IRQ_TIMER10 11
#endif

#define CONFIG_IRQ_TIMER11 10

#undef CONFIG_IRQ_TIMER2
#if (defined(CONFIG_BF52x) || defined(CONFIG_BF51x) || (!defined(CONFIG_BF52x) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF561) && (defined(CONFIG_BF534) || defined(CONFIG_BF536) || defined(CONFIG_BF537))) || (!defined(CONFIG_BF537) && !defined(CONFIG_BF538) && !defined(CONFIG_BF536) && !defined(CONFIG_BF561) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF539) && (defined(CONFIG_BF534) || defined(CONFIG_BF536) || defined(CONFIG_BF537)) && !defined(CONFIG_BF54x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534)))
  #define CONFIG_IRQ_TIMER2 12
#endif
#if (!defined(CONFIG_BF52x) && !defined(CONFIG_BF51x) && defined(CONFIG_BF561))
  #define CONFIG_IRQ_TIMER2 10
#endif
#if ((!defined(CONFIG_BF537) && !defined(CONFIG_BF536) && !defined(CONFIG_BF561) && (defined(CONFIG_BF538) || defined(CONFIG_BF539)) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534)) || (!defined(CONFIG_BF537) && !defined(CONFIG_BF538) && !defined(CONFIG_BF536) && !defined(CONFIG_BF561) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF539) && defined(CONFIG_BF54x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534)) || (!defined(CONFIG_BF537) && !defined(CONFIG_BF538) && !defined(CONFIG_BF536) && !defined(CONFIG_BF561) && (defined(CONFIG_BF538) || defined(CONFIG_BF539)) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF539) && !defined(CONFIG_BF54x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534)))
  #define CONFIG_IRQ_TIMER2 11
#endif

#undef CONFIG_IRQ_TIMER3
#if (defined(CONFIG_BF52x) || defined(CONFIG_BF51x) || (!defined(CONFIG_BF52x) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF561) && (defined(CONFIG_BF534) || defined(CONFIG_BF536) || defined(CONFIG_BF537))) || (!defined(CONFIG_BF537) && !defined(CONFIG_BF536) && !defined(CONFIG_BF561) && !defined(CONFIG_BF51x) && (defined(CONFIG_BF534) || defined(CONFIG_BF536) || defined(CONFIG_BF537)) && !defined(CONFIG_BF54x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534)))
  #define CONFIG_IRQ_TIMER3 12
#endif
#if (!defined(CONFIG_BF52x) && !defined(CONFIG_BF51x) && defined(CONFIG_BF561))
  #define CONFIG_IRQ_TIMER3 10
#endif
#if (!defined(CONFIG_BF537) && !defined(CONFIG_BF536) && !defined(CONFIG_BF561) && !defined(CONFIG_BF51x) && defined(CONFIG_BF54x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534))
  #define CONFIG_IRQ_TIMER3 11
#endif

#undef CONFIG_IRQ_TIMER4
#if (defined(CONFIG_BF52x) || defined(CONFIG_BF51x) || (!defined(CONFIG_BF52x) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF561) && (defined(CONFIG_BF534) || defined(CONFIG_BF536) || defined(CONFIG_BF537))) || (!defined(CONFIG_BF537) && !defined(CONFIG_BF536) && !defined(CONFIG_BF561) && !defined(CONFIG_BF51x) && (defined(CONFIG_BF534) || defined(CONFIG_BF536) || defined(CONFIG_BF537)) && !defined(CONFIG_BF54x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534)))
  #define CONFIG_IRQ_TIMER4 12
#endif
#if (!defined(CONFIG_BF52x) && !defined(CONFIG_BF51x) && defined(CONFIG_BF561))
  #define CONFIG_IRQ_TIMER4 10
#endif
#if (!defined(CONFIG_BF537) && !defined(CONFIG_BF536) && !defined(CONFIG_BF561) && !defined(CONFIG_BF51x) && defined(CONFIG_BF54x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534))
  #define CONFIG_IRQ_TIMER4 11
#endif

#undef CONFIG_IRQ_TIMER5
#if (defined(CONFIG_BF52x) || defined(CONFIG_BF51x) || (!defined(CONFIG_BF52x) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF561) && (defined(CONFIG_BF534) || defined(CONFIG_BF536) || defined(CONFIG_BF537))) || (!defined(CONFIG_BF537) && !defined(CONFIG_BF536) && !defined(CONFIG_BF561) && !defined(CONFIG_BF51x) && (defined(CONFIG_BF534) || defined(CONFIG_BF536) || defined(CONFIG_BF537)) && !defined(CONFIG_BF54x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534)))
  #define CONFIG_IRQ_TIMER5 12
#endif
#if (!defined(CONFIG_BF52x) && !defined(CONFIG_BF51x) && defined(CONFIG_BF561))
  #define CONFIG_IRQ_TIMER5 10
#endif
#if (!defined(CONFIG_BF537) && !defined(CONFIG_BF536) && !defined(CONFIG_BF561) && !defined(CONFIG_BF51x) && defined(CONFIG_BF54x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534))
  #define CONFIG_IRQ_TIMER5 11
#endif

#undef CONFIG_IRQ_TIMER6
#if (defined(CONFIG_BF52x) || defined(CONFIG_BF51x) || (!defined(CONFIG_BF52x) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF561) && (defined(CONFIG_BF534) || defined(CONFIG_BF536) || defined(CONFIG_BF537))) || (!defined(CONFIG_BF537) && !defined(CONFIG_BF536) && !defined(CONFIG_BF561) && !defined(CONFIG_BF51x) && (defined(CONFIG_BF534) || defined(CONFIG_BF536) || defined(CONFIG_BF537)) && !defined(CONFIG_BF54x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534)))
  #define CONFIG_IRQ_TIMER6 12
#endif
#if (!defined(CONFIG_BF52x) && !defined(CONFIG_BF51x) && defined(CONFIG_BF561))
  #define CONFIG_IRQ_TIMER6 10
#endif
#if (!defined(CONFIG_BF537) && !defined(CONFIG_BF536) && !defined(CONFIG_BF561) && !defined(CONFIG_BF51x) && defined(CONFIG_BF54x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534))
  #define CONFIG_IRQ_TIMER6 11
#endif

#undef CONFIG_IRQ_TIMER7
#if (defined(CONFIG_BF52x) || defined(CONFIG_BF51x) || (!defined(CONFIG_BF52x) && !defined(CONFIG_BF51x) && !defined(CONFIG_BF561) && (defined(CONFIG_BF534) || defined(CONFIG_BF536) || defined(CONFIG_BF537))) || (!defined(CONFIG_BF537) && !defined(CONFIG_BF536) && !defined(CONFIG_BF561) && !defined(CONFIG_BF51x) && (defined(CONFIG_BF534) || defined(CONFIG_BF536) || defined(CONFIG_BF537)) && !defined(CONFIG_BF54x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534)))
  #define CONFIG_IRQ_TIMER7 12
#endif
#if (!defined(CONFIG_BF52x) && !defined(CONFIG_BF51x) && defined(CONFIG_BF561))
  #define CONFIG_IRQ_TIMER7 10
#endif
#if (!defined(CONFIG_BF537) && !defined(CONFIG_BF536) && !defined(CONFIG_BF561) && !defined(CONFIG_BF51x) && defined(CONFIG_BF54x) && !defined(CONFIG_BF52x) && !defined(CONFIG_BF534))
  #define CONFIG_IRQ_TIMER7 11
#endif

#undef CONFIG_IRQ_TIMER8
#if defined(CONFIG_BF561)
  #define CONFIG_IRQ_TIMER8 10
#endif
#if (defined(CONFIG_BF54x) && !defined(CONFIG_BF561))
  #define CONFIG_IRQ_TIMER8 11
#endif

#undef CONFIG_IRQ_TIMER9
#if defined(CONFIG_BF561)
  #define CONFIG_IRQ_TIMER9 10
#endif
#if (defined(CONFIG_BF54x) && !defined(CONFIG_BF561))
  #define CONFIG_IRQ_TIMER9 11
#endif

#define CONFIG_IRQ_TWI 10

#define CONFIG_IRQ_TWI0 11

#define CONFIG_IRQ_TWI1 11

#define CONFIG_IRQ_UART0_ERR 7

#define CONFIG_IRQ_UART0_ERROR 7

#define CONFIG_IRQ_UART0_RX 10

#define CONFIG_IRQ_UART0_TX 10

#define CONFIG_IRQ_UART1_ERR 7

#define CONFIG_IRQ_UART1_ERROR 7

#define CONFIG_IRQ_UART1_RX 10

#define CONFIG_IRQ_UART1_TX 10

#define CONFIG_IRQ_UART2_ERR 7

#define CONFIG_IRQ_UART2_ERROR 7

#define CONFIG_IRQ_UART2_RX 10

#define CONFIG_IRQ_UART2_TX 10

#define CONFIG_IRQ_UART3_ERR 7

#define CONFIG_IRQ_UART_ERROR 7

#undef CONFIG_IRQ_USB_DMA
#if defined(CONFIG_BF52x)
  #define CONFIG_IRQ_USB_DMA 10
#endif
#if (defined(CONFIG_BF54x) && !defined(CONFIG_BF52x))
  #define CONFIG_IRQ_USB_DMA 11
#endif

#define CONFIG_IRQ_USB_EINT 10

#undef CONFIG_IRQ_USB_INT0
#if defined(CONFIG_BF52x)
  #define CONFIG_IRQ_USB_INT0 10
#endif
#if (defined(CONFIG_BF54x) && !defined(CONFIG_BF52x))
  #define CONFIG_IRQ_USB_INT0 11
#endif

#undef CONFIG_IRQ_USB_INT1
#if defined(CONFIG_BF52x)
  #define CONFIG_IRQ_USB_INT1 10
#endif
#if (defined(CONFIG_BF54x) && !defined(CONFIG_BF52x))
  #define CONFIG_IRQ_USB_INT1 11
#endif

#undef CONFIG_IRQ_USB_INT2
#if defined(CONFIG_BF52x)
  #define CONFIG_IRQ_USB_INT2 10
#endif
#if (defined(CONFIG_BF54x) && !defined(CONFIG_BF52x))
  #define CONFIG_IRQ_USB_INT2 11
#endif

#define CONFIG_IRQ_WATCH 13

#define CONFIG_IRQ_WATCHDOG 13

#define CONFIG_IRQ_WDTIMER 13

#define CONFIG_JFFS2_FS_DEBUG 0

#define CONFIG_KERNELVERSION "2.6.30-vamos"

#define CONFIG_KGDB_TESTS_BOOT_STRING "V1F100"

#define CONFIG_KMEMCHECK_QUEUE_SIZE 64

#define CONFIG_KMEMCHECK_SHADOW_COPY_SHIFT 5

#define CONFIG_KS0108_DELAY 2

#define CONFIG_KS0108_PORT 0x378

#define CONFIG_LEGACY_PTY_COUNT 256

#undef CONFIG_LOCALVERSION

#define CONFIG_LOG_BUF_SHIFT 17

#define CONFIG_LSM_MMAP_MIN_ADDR 65536

#undef CONFIG_M32R_CFC_NUM

#undef CONFIG_MAC80211_RC_DEFAULT
#if ((defined(CONFIG_MAC80211) && defined(CONFIG_MAC80211_RC_DEFAULT_MINSTREL) && defined(CONFIG_WIRELESS) && defined(CONFIG_NET)) || (defined(CONFIG_NET) && ((defined(CONFIG_MAC80211) && defined(CONFIG_MAC80211_RC_DEFAULT_MINSTREL) && defined(CONFIG_WIRELESS)) || (defined(CONFIG_WIRELESS) && ((defined(CONFIG_MAC80211) && defined(CONFIG_MAC80211_RC_DEFAULT_MINSTREL)) || (defined(CONFIG_MAC80211_RC_DEFAULT_MINSTREL) && (defined(CONFIG_MAC80211) || defined(CONFIG_MAC80211_MODULE))))))))
  #define CONFIG_MAC80211_RC_DEFAULT "minstrel"
#endif
#if ((!defined(CONFIG_NET) || ((!defined(CONFIG_WIRELESS) || ((!defined(CONFIG_MAC80211_RC_DEFAULT_MINSTREL) || (!defined(CONFIG_MAC80211) && !defined(CONFIG_MAC80211_MODULE))) && (!defined(CONFIG_MAC80211) || !defined(CONFIG_MAC80211_RC_DEFAULT_MINSTREL)))) && (!defined(CONFIG_MAC80211) || !defined(CONFIG_MAC80211_RC_DEFAULT_MINSTREL) || !defined(CONFIG_WIRELESS)))) && (!defined(CONFIG_MAC80211) || !defined(CONFIG_MAC80211_RC_DEFAULT_MINSTREL) || !defined(CONFIG_WIRELESS) || !defined(CONFIG_NET)) && ((defined(CONFIG_MAC80211) && defined(CONFIG_MAC80211_RC_DEFAULT_PID) && defined(CONFIG_WIRELESS) && defined(CONFIG_NET)) || (defined(CONFIG_NET) && ((defined(CONFIG_MAC80211) && defined(CONFIG_MAC80211_RC_DEFAULT_PID) && defined(CONFIG_WIRELESS)) || (defined(CONFIG_WIRELESS) && ((defined(CONFIG_MAC80211) && defined(CONFIG_MAC80211_RC_DEFAULT_PID)) || (defined(CONFIG_MAC80211_RC_DEFAULT_PID) && (defined(CONFIG_MAC80211) || defined(CONFIG_MAC80211_MODULE)))))))))
  #define CONFIG_MAC80211_RC_DEFAULT "pid"
#endif
#if ((!defined(CONFIG_NET) || ((!defined(CONFIG_WIRELESS) || ((!defined(CONFIG_MAC80211_RC_DEFAULT_MINSTREL) || (!defined(CONFIG_MAC80211) && !defined(CONFIG_MAC80211_MODULE))) && (!defined(CONFIG_MAC80211) || !defined(CONFIG_MAC80211_RC_DEFAULT_MINSTREL)))) && (!defined(CONFIG_MAC80211) || !defined(CONFIG_MAC80211_RC_DEFAULT_MINSTREL) || !defined(CONFIG_WIRELESS)))) && (!defined(CONFIG_NET) || ((!defined(CONFIG_WIRELESS) || ((!defined(CONFIG_MAC80211_RC_DEFAULT_PID) || (!defined(CONFIG_MAC80211) && !defined(CONFIG_MAC80211_MODULE))) && (!defined(CONFIG_MAC80211) || !defined(CONFIG_MAC80211_RC_DEFAULT_PID)))) && (!defined(CONFIG_MAC80211) || !defined(CONFIG_MAC80211_RC_DEFAULT_PID) || !defined(CONFIG_WIRELESS)))) && (!defined(CONFIG_MAC80211) || !defined(CONFIG_MAC80211_RC_DEFAULT_MINSTREL) || !defined(CONFIG_WIRELESS) || !defined(CONFIG_NET)) && ((defined(CONFIG_WIRELESS) && defined(CONFIG_MAC80211) && defined(CONFIG_NET)) || (defined(CONFIG_NET) && ((defined(CONFIG_WIRELESS) && defined(CONFIG_MAC80211)) || (defined(CONFIG_WIRELESS) && (defined(CONFIG_MAC80211) || defined(CONFIG_MAC80211_MODULE)))))) && (!defined(CONFIG_MAC80211) || !defined(CONFIG_MAC80211_RC_DEFAULT_PID) || !defined(CONFIG_WIRELESS) || !defined(CONFIG_NET)))
  #define CONFIG_MAC80211_RC_DEFAULT ""
#endif

#define CONFIG_MAX_RAW_DEVS 256

#define CONFIG_MAX_SCLK_HZ 133333333

#undef CONFIG_MAX_VCO_HZ
#if ((defined(CONFIG_BF537) && !defined(CONFIG_BF514) && !defined(CONFIG_BF522) && !defined(CONFIG_BF532) && !defined(CONFIG_BF531) && !defined(CONFIG_BF518) && !defined(CONFIG_BF526) && !defined(CONFIG_BF536) && !defined(CONFIG_BF516) && !defined(CONFIG_BF523) && !defined(CONFIG_BF533) && !defined(CONFIG_BF512) && !defined(CONFIG_BF525) && !defined(CONFIG_BF527) && !defined(CONFIG_BF524) && !defined(CONFIG_BF534)) || (!defined(CONFIG_BF514) && !defined(CONFIG_BF522) && !defined(CONFIG_BF518) && !defined(CONFIG_BF516) && !defined(CONFIG_BF523) && !defined(CONFIG_BF512) && defined(CONFIG_BF525) && !defined(CONFIG_BF524)) || (!defined(CONFIG_BF514) && !defined(CONFIG_BF522) && defined(CONFIG_BF523) && !defined(CONFIG_BF518) && !defined(CONFIG_BF516) && !defined(CONFIG_BF512)) || (!defined(CONFIG_BF537) && !defined(CONFIG_BF514) && !defined(CONFIG_BF522) && !defined(CONFIG_BF538) && !defined(CONFIG_BF532) && !defined(CONFIG_BF544) && !defined(CONFIG_BF531) && !defined(CONFIG_BF518) && !defined(CONFIG_BF526) && !defined(CONFIG_BF536) && !defined(CONFIG_BF516) && !defined(CONFIG_BF523) && defined(CONFIG_BF547) && !defined(CONFIG_BF539) && !defined(CONFIG_BF533) && !defined(CONFIG_BF512) && !defined(CONFIG_BF525) && !defined(CONFIG_BF527) && !defined(CONFIG_BF542) && !defined(CONFIG_BF524) && !defined(CONFIG_BF534)) || (!defined(CONFIG_BF537) && !defined(CONFIG_BF514) && !defined(CONFIG_BF522) && !defined(CONFIG_BF538) && !defined(CONFIG_BF532) && !defined(CONFIG_BF544) && !defined(CONFIG_BF531) && !defined(CONFIG_BF518) && !defined(CONFIG_BF526) && !defined(CONFIG_BF536) && !defined(CONFIG_BF516) && !defined(CONFIG_BF523) && !defined(CONFIG_BF547) && !defined(CONFIG_BF549) && !defined(CONFIG_BF539) && !defined(CONFIG_BF533) && defined(CONFIG_BF561) && !defined(CONFIG_BF512) && !defined(CONFIG_BF525) && !defined(CONFIG_BF527) && !defined(CONFIG_BF542) && !defined(CONFIG_BF524) && !defined(CONFIG_BF534) && !defined(CONFIG_BF548)) || (!defined(CONFIG_BF537) && !defined(CONFIG_BF514) && !defined(CONFIG_BF522) && !defined(CONFIG_BF538) && !defined(CONFIG_BF532) && !defined(CONFIG_BF531) && !defined(CONFIG_BF518) && !defined(CONFIG_BF526) && !defined(CONFIG_BF536) && !defined(CONFIG_BF516) && !defined(CONFIG_BF523) && !defined(CONFIG_BF539) && !defined(CONFIG_BF533) && defined(CONFIG_BF542) && !defined(CONFIG_BF512) && !defined(CONFIG_BF525) && !defined(CONFIG_BF527) && !defined(CONFIG_BF524) && !defined(CONFIG_BF534)) || (!defined(CONFIG_BF537) && !defined(CONFIG_BF514) && !defined(CONFIG_BF522) && !defined(CONFIG_BF538) && !defined(CONFIG_BF532) && !defined(CONFIG_BF544) && !defined(CONFIG_BF531) && !defined(CONFIG_BF518) && !defined(CONFIG_BF526) && !defined(CONFIG_BF536) && !defined(CONFIG_BF516) && !defined(CONFIG_BF523) && !defined(CONFIG_BF547) && !defined(CONFIG_BF539) && !defined(CONFIG_BF533) && !defined(CONFIG_BF512) && !defined(CONFIG_BF525) && !defined(CONFIG_BF527) && !defined(CONFIG_BF542) && !defined(CONFIG_BF524) && !defined(CONFIG_BF534) && defined(CONFIG_BF548)) || (!defined(CONFIG_BF514) && !defined(CONFIG_BF522) && !defined(CONFIG_BF518) && !defined(CONFIG_BF526) && !defined(CONFIG_BF516) && !defined(CONFIG_BF523) && !defined(CONFIG_BF512) && !defined(CONFIG_BF525) && defined(CONFIG_BF527) && !defined(CONFIG_BF524)))
  #define CONFIG_MAX_VCO_HZ 600000000
#endif
#if (!defined(CONFIG_BF514) && !defined(CONFIG_BF522) && !defined(CONFIG_BF532) && !defined(CONFIG_BF531) && !defined(CONFIG_BF518) && !defined(CONFIG_BF526) && !defined(CONFIG_BF516) && !defined(CONFIG_BF523) && defined(CONFIG_BF533) && !defined(CONFIG_BF512) && !defined(CONFIG_BF525) && !defined(CONFIG_BF527) && !defined(CONFIG_BF524))
  #define CONFIG_MAX_VCO_HZ 750000000
#endif
#if ((!defined(CONFIG_BF514) && !defined(CONFIG_BF518) && !defined(CONFIG_BF516) && !defined(CONFIG_BF512) && defined(CONFIG_BF522)) || (defined(CONFIG_BF524) && !defined(CONFIG_BF514) && !defined(CONFIG_BF522) && !defined(CONFIG_BF518) && !defined(CONFIG_BF516) && !defined(CONFIG_BF523) && !defined(CONFIG_BF512)) || (!defined(CONFIG_BF514) && !defined(CONFIG_BF522) && !defined(CONFIG_BF518) && !defined(CONFIG_BF526) && !defined(CONFIG_BF516) && !defined(CONFIG_BF523) && !defined(CONFIG_BF512) && !defined(CONFIG_BF525) && !defined(CONFIG_BF527) && !defined(CONFIG_BF524) && defined(CONFIG_BF531)) || (!defined(CONFIG_BF514) && !defined(CONFIG_BF522) && !defined(CONFIG_BF532) && !defined(CONFIG_BF531) && !defined(CONFIG_BF518) && !defined(CONFIG_BF526) && !defined(CONFIG_BF516) && !defined(CONFIG_BF523) && defined(CONFIG_BF536) && !defined(CONFIG_BF533) && !defined(CONFIG_BF512) && !defined(CONFIG_BF525) && !defined(CONFIG_BF527) && !defined(CONFIG_BF524) && !defined(CONFIG_BF534)) || (defined(CONFIG_BF532) && !defined(CONFIG_BF514) && !defined(CONFIG_BF522) && !defined(CONFIG_BF531) && !defined(CONFIG_BF518) && !defined(CONFIG_BF526) && !defined(CONFIG_BF516) && !defined(CONFIG_BF523) && !defined(CONFIG_BF512) && !defined(CONFIG_BF525) && !defined(CONFIG_BF527) && !defined(CONFIG_BF524)) || (!defined(CONFIG_BF512) && !defined(CONFIG_BF514) && !defined(CONFIG_BF516) && defined(CONFIG_BF518)) || (!defined(CONFIG_BF514) && !defined(CONFIG_BF522) && !defined(CONFIG_BF518) && !defined(CONFIG_BF516) && !defined(CONFIG_BF523) && !defined(CONFIG_BF512) && !defined(CONFIG_BF525) && !defined(CONFIG_BF524) && defined(CONFIG_BF526)) || defined(CONFIG_BF514) || defined(CONFIG_BF512) || (!defined(CONFIG_BF512) && !defined(CONFIG_BF514) && defined(CONFIG_BF516)))
  #define CONFIG_MAX_VCO_HZ 400000000
#endif
#if ((!defined(CONFIG_BF537) && !defined(CONFIG_BF514) && !defined(CONFIG_BF522) && !defined(CONFIG_BF532) && !defined(CONFIG_BF531) && defined(CONFIG_BF538) && !defined(CONFIG_BF518) && !defined(CONFIG_BF526) && !defined(CONFIG_BF536) && !defined(CONFIG_BF516) && !defined(CONFIG_BF523) && !defined(CONFIG_BF533) && !defined(CONFIG_BF512) && !defined(CONFIG_BF525) && !defined(CONFIG_BF527) && !defined(CONFIG_BF524) && !defined(CONFIG_BF534)) || (!defined(CONFIG_BF537) && !defined(CONFIG_BF514) && !defined(CONFIG_BF522) && !defined(CONFIG_BF538) && !defined(CONFIG_BF532) && !defined(CONFIG_BF531) && !defined(CONFIG_BF518) && defined(CONFIG_BF539) && !defined(CONFIG_BF526) && !defined(CONFIG_BF536) && !defined(CONFIG_BF516) && !defined(CONFIG_BF523) && !defined(CONFIG_BF533) && !defined(CONFIG_BF512) && !defined(CONFIG_BF525) && !defined(CONFIG_BF527) && !defined(CONFIG_BF524) && !defined(CONFIG_BF534)) || (!defined(CONFIG_BF537) && !defined(CONFIG_BF514) && !defined(CONFIG_BF522) && !defined(CONFIG_BF538) && !defined(CONFIG_BF532) && !defined(CONFIG_BF531) && !defined(CONFIG_BF518) && !defined(CONFIG_BF526) && !defined(CONFIG_BF536) && !defined(CONFIG_BF516) && !defined(CONFIG_BF523) && !defined(CONFIG_BF539) && !defined(CONFIG_BF533) && !defined(CONFIG_BF512) && !defined(CONFIG_BF525) && !defined(CONFIG_BF527) && !defined(CONFIG_BF542) && !defined(CONFIG_BF524) && !defined(CONFIG_BF534) && defined(CONFIG_BF544)) || (!defined(CONFIG_BF537) && !defined(CONFIG_BF514) && !defined(CONFIG_BF522) && !defined(CONFIG_BF538) && !defined(CONFIG_BF532) && !defined(CONFIG_BF544) && !defined(CONFIG_BF531) && !defined(CONFIG_BF518) && !defined(CONFIG_BF526) && !defined(CONFIG_BF536) && !defined(CONFIG_BF516) && !defined(CONFIG_BF523) && !defined(CONFIG_BF547) && !defined(CONFIG_BF539) && !defined(CONFIG_BF533) && !defined(CONFIG_BF512) && !defined(CONFIG_BF525) && !defined(CONFIG_BF527) && defined(CONFIG_BF549) && !defined(CONFIG_BF542) && !defined(CONFIG_BF524) && !defined(CONFIG_BF534) && !defined(CONFIG_BF548)))
  #define CONFIG_MAX_VCO_HZ 533333333
#endif
#if (!defined(CONFIG_BF514) && !defined(CONFIG_BF522) && !defined(CONFIG_BF532) && !defined(CONFIG_BF531) && !defined(CONFIG_BF518) && !defined(CONFIG_BF526) && !defined(CONFIG_BF516) && !defined(CONFIG_BF523) && !defined(CONFIG_BF533) && !defined(CONFIG_BF512) && !defined(CONFIG_BF525) && !defined(CONFIG_BF527) && defined(CONFIG_BF534) && !defined(CONFIG_BF524))
  #define CONFIG_MAX_VCO_HZ 500000000
#endif

#define CONFIG_MEMDMA0 13

#define CONFIG_MEMDMA1 13

#define CONFIG_MEM_DDRCTL0 0x0

#define CONFIG_MEM_DDRCTL1 0x0

#define CONFIG_MEM_DDRCTL2 0x0

#define CONFIG_MEM_EBIU_DDRQUE 0x0

#define CONFIG_MEM_SDGCTL 0x0

#define CONFIG_MEM_SDRRC 0x0

#define CONFIG_MG_DISK_RES 0

#define CONFIG_MIN_SCLK_HZ 27000000

#define CONFIG_MIN_VCO_HZ 50000000

#define CONFIG_MSNDCLAS_INIT_FILE "/etc/sound/msndinit.bin"

#define CONFIG_MSNDCLAS_IO 290

#define CONFIG_MSNDCLAS_IRQ 5

#define CONFIG_MSNDCLAS_MEM D0000

#define CONFIG_MSNDCLAS_PERM_FILE "/etc/sound/msndperm.bin"

#define CONFIG_MSNDPIN_CFG 250

#define CONFIG_MSNDPIN_IDE_IO0 0

#define CONFIG_MSNDPIN_IDE_IO1 0

#define CONFIG_MSNDPIN_IDE_IRQ 0

#define CONFIG_MSNDPIN_INIT_FILE "/etc/sound/pndspini.bin"

#define CONFIG_MSNDPIN_IO 290

#define CONFIG_MSNDPIN_IRQ 5

#define CONFIG_MSNDPIN_JOYSTICK_IO 0

#define CONFIG_MSNDPIN_MEM D0000

#define CONFIG_MSNDPIN_MPU_IO 0

#define CONFIG_MSNDPIN_MPU_IRQ 0

#define CONFIG_MSNDPIN_PERM_FILE "/etc/sound/pndsperm.bin"

#define CONFIG_MSND_FIFOSIZE 128

#define CONFIG_MSP_FLASH_MAP_LIMIT 0x02000000

#define CONFIG_MTDRAM_ABS_POS 0

#define CONFIG_MTDRAM_ERASE_SIZE 128

#define CONFIG_MTDRAM_TOTAL_SIZE 4096

#define CONFIG_MTD_DEBUG_VERBOSE 0

#define CONFIG_MTD_DILNETPC_BOOTSIZE 0x80000

#undef CONFIG_MTD_DOCPROBE_ADDRESS
#if ((defined(CONFIG_MTD_DOCPROBE) && defined(CONFIG_MTD_DOCPROBE_ADVANCED) && defined(CONFIG_MTD)) || (((defined(CONFIG_MTD_DOCPROBE) && defined(CONFIG_MTD_DOCPROBE_ADVANCED)) || (defined(CONFIG_MTD_DOCPROBE_ADVANCED) && (defined(CONFIG_MTD_DOCPROBE) || defined(CONFIG_MTD_DOCPROBE_MODULE)))) && (defined(CONFIG_MTD_MODULE) || defined(CONFIG_MTD))))
  #define CONFIG_MTD_DOCPROBE_ADDRESS 0x0000
#endif
#if ((((!defined(CONFIG_MTD_DOCPROBE_ADVANCED) || (!defined(CONFIG_MTD_DOCPROBE) && !defined(CONFIG_MTD_DOCPROBE_MODULE))) && (!defined(CONFIG_MTD_DOCPROBE) || !defined(CONFIG_MTD_DOCPROBE_ADVANCED))) || (!defined(CONFIG_MTD_MODULE) && !defined(CONFIG_MTD))) && (!defined(CONFIG_MTD_DOCPROBE) || !defined(CONFIG_MTD_DOCPROBE_ADVANCED) || !defined(CONFIG_MTD)) && ((defined(CONFIG_MTD_DOCPROBE) && !defined(CONFIG_MTD_DOCPROBE_ADVANCED) && defined(CONFIG_MTD)) || (((defined(CONFIG_MTD_DOCPROBE) && !defined(CONFIG_MTD_DOCPROBE_ADVANCED)) || (!defined(CONFIG_MTD_DOCPROBE_ADVANCED) && (defined(CONFIG_MTD_DOCPROBE) || defined(CONFIG_MTD_DOCPROBE_MODULE)))) && (defined(CONFIG_MTD_MODULE) || defined(CONFIG_MTD)))))
  #define CONFIG_MTD_DOCPROBE_ADDRESS 0
#endif

#define CONFIG_MTD_NAND_DISKONCHIP_PROBE_ADDRESS 0

#define CONFIG_MTD_PHYSMAP_BANKWIDTH 2

#define CONFIG_MTD_PHYSMAP_LEN 0

#define CONFIG_MTD_PHYSMAP_START 0x8000000

#define CONFIG_MTD_REDBOOT_DIRECTORY_BLOCK -1

#define CONFIG_MTD_UBI_BEB_RESERVE 1

#define CONFIG_MTD_UBI_WL_THRESHOLD 4096

#define CONFIG_MX3_IPU_IRQS 4

#define CONFIG_NET_EMATCH_STACK 32

#define CONFIG_NLS_DEFAULT "iso8859-1"

#define CONFIG_NOMMU_INITIAL_TRIM_EXCESS 1

#define CONFIG_NR_CPUS 2

#undef CONFIG_NR_QUICK

#define CONFIG_OMAP2_DSS_MIN_FCK_PER_PCK 0

#define CONFIG_OMAP2_VRAM_SIZE 0

#define CONFIG_PANEL_BOOT_MESSAGE ""

#define CONFIG_PANEL_KEYPAD 0

#define CONFIG_PANEL_LCD 0

#define CONFIG_PANEL_LCD_BWIDTH 40

#define CONFIG_PANEL_LCD_CHARSET 0

#define CONFIG_PANEL_LCD_HEIGHT 2

#define CONFIG_PANEL_LCD_HWIDTH 64

#define CONFIG_PANEL_LCD_PIN_BL 0

#define CONFIG_PANEL_LCD_PIN_E 14

#define CONFIG_PANEL_LCD_PIN_RS 17

#define CONFIG_PANEL_LCD_PIN_RW 16

#define CONFIG_PANEL_LCD_PIN_SCL 1

#define CONFIG_PANEL_LCD_PIN_SDA 2

#define CONFIG_PANEL_LCD_PROTO 0

#define CONFIG_PANEL_LCD_WIDTH 40

#define CONFIG_PANEL_PARPORT 0

#define CONFIG_PANEL_PROFILE 5

#define CONFIG_PFA 12

#define CONFIG_PFB 12

#define CONFIG_PINT0_ASSIGN 0x00000101

#define CONFIG_PINT1_ASSIGN 0x01010000

#define CONFIG_PINT2_ASSIGN 0x07000101

#define CONFIG_PINT3_ASSIGN 0x02020303

#define CONFIG_PLLWAKE_ERROR 7

#define CONFIG_PM_STD_PARTITION ""

#define CONFIG_PM_WAKEUP_GPIO_NUMBER 2

#define CONFIG_PPI_ERROR 7

#define CONFIG_PSS_BOOT_FILE "/etc/sound/dsp001.ld"

#define CONFIG_RADIO_AZTECH_PORT 350

#define CONFIG_RADIO_GEMTEK_PORT 34c

#define CONFIG_RADIO_RTRACK2_PORT 30c

#define CONFIG_RADIO_RTRACK_PORT 20f

#define CONFIG_RADIO_TERRATEC_PORT 590

#define CONFIG_RADIO_TRUST_PORT 350

#define CONFIG_RADIO_TYPHOON_MUTEFREQ 87500

#define CONFIG_RADIO_TYPHOON_PORT 316

#define CONFIG_RADIO_ZOLTRIX_PORT 20c

#define CONFIG_RCU_FANOUT 32

#define CONFIG_RIONET_RX_SIZE 128

#define CONFIG_RIONET_TX_SIZE 128

#define CONFIG_ROM_BASE 0x20040000

#define CONFIG_RTC_DRV_AT91SAM9_GPBR 0

#define CONFIG_RTC_DRV_AT91SAM9_RTT 0

#define CONFIG_RTC_ERROR 8

#define CONFIG_RTC_HCTOSYS_DEVICE "rtc0"

#define CONFIG_SC6600_CDROM 4

#define CONFIG_SC6600_CDROMBASE 0

#define CONFIG_SCLK_DIV 5

#define CONFIG_SCSI_EATA_MAX_TAGS 16

#define CONFIG_SCSI_MESH_RESET_DELAY_MS 4000

#define CONFIG_SCSI_MESH_SYNC_RATE 5

#define CONFIG_SCSI_MPT2SAS_MAX_SGE 128

#define CONFIG_SCSI_NCR53C8XX_DEFAULT_TAGS 8

#define CONFIG_SCSI_NCR53C8XX_MAX_TAGS 32

#define CONFIG_SCSI_NCR53C8XX_SYNC 20

#define CONFIG_SCSI_OSD_DPRINT_SENSE 1

#define CONFIG_SCSI_SYM53C8XX_DEFAULT_TAGS 16

#define CONFIG_SCSI_SYM53C8XX_DMA_ADDRESSING_MODE 1

#define CONFIG_SCSI_SYM53C8XX_MAX_TAGS 64

#define CONFIG_SCSI_U14_34F_MAX_TAGS 8

#define CONFIG_SCx200_I2C_SCL 12

#define CONFIG_SCx200_I2C_SDA 13

#define CONFIG_SECURITY_SELINUX_BOOTPARAM_VALUE 1

#define CONFIG_SECURITY_SELINUX_CHECKREQPROT_VALUE 1

#define CONFIG_SECURITY_SELINUX_POLICYDB_VERSION_MAX_VALUE 19

#define CONFIG_SERIAL_8250_NR_UARTS 4

#define CONFIG_SERIAL_8250_RUNTIME_UARTS 4

#define CONFIG_SERIAL_MCF_BAUDRATE 19200

#define CONFIG_SERIAL_MPC52xx_CONSOLE_BAUD 9600

#undef CONFIG_SERIAL_SAMSUNG_UARTS

#define CONFIG_SERIAL_SH_SCI_NR_UARTS 2

#define CONFIG_SERIAL_TXX9_NR_UARTS 6

#define CONFIG_SMB_NLS_REMOTE "cp437"

#define CONFIG_SND_AC97_POWER_SAVE_DEFAULT 0

#define CONFIG_SND_AT73C213_TARGET_BITRATE 48000

#undef CONFIG_SND_BF5XX_RESET_GPIO_NUM
#if ((defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET) && defined(CONFIG_SND_SOC) && defined(CONFIG_SND) && defined(CONFIG_BFIN548_EZKIT) && defined(CONFIG_SOUND)) || (((defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET) && defined(CONFIG_BFIN548_EZKIT) && defined(CONFIG_SND_SOC) && defined(CONFIG_SND)) || (((defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET) && defined(CONFIG_BFIN548_EZKIT) && defined(CONFIG_SND_SOC)) || (defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET) && defined(CONFIG_BFIN548_EZKIT) && (defined(CONFIG_SND_SOC) || defined(CONFIG_SND_SOC_MODULE)))) && (defined(CONFIG_SND) || defined(CONFIG_SND_MODULE)))) && (defined(CONFIG_SOUND) || defined(CONFIG_SOUND_MODULE))))
  #define CONFIG_SND_BF5XX_RESET_GPIO_NUM 19
#endif
#if ((((((!defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET) || !defined(CONFIG_BFIN548_EZKIT) || (!defined(CONFIG_SND_SOC) && !defined(CONFIG_SND_SOC_MODULE))) && (!defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET) || !defined(CONFIG_BFIN548_EZKIT) || !defined(CONFIG_SND_SOC))) || (!defined(CONFIG_SND) && !defined(CONFIG_SND_MODULE))) && (!defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET) || !defined(CONFIG_BFIN548_EZKIT) || !defined(CONFIG_SND_SOC) || !defined(CONFIG_SND))) || (!defined(CONFIG_SOUND) && !defined(CONFIG_SOUND_MODULE))) && (!defined(CONFIG_SND) || !defined(CONFIG_BFIN548_EZKIT) || !defined(CONFIG_SOUND) || !defined(CONFIG_SND_SOC) || !defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET)) && ((defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET) && defined(CONFIG_SND_SOC) && defined(CONFIG_SND) && defined(CONFIG_BFIN537_STAMP) && defined(CONFIG_SOUND)) || (((defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET) && defined(CONFIG_BFIN537_STAMP) && defined(CONFIG_SND_SOC) && defined(CONFIG_SND)) || (((defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET) && defined(CONFIG_BFIN537_STAMP) && defined(CONFIG_SND_SOC)) || (defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET) && defined(CONFIG_BFIN537_STAMP) && (defined(CONFIG_SND_SOC) || defined(CONFIG_SND_SOC_MODULE)))) && (defined(CONFIG_SND) || defined(CONFIG_SND_MODULE)))) && (defined(CONFIG_SOUND) || defined(CONFIG_SOUND_MODULE)))))
  #define CONFIG_SND_BF5XX_RESET_GPIO_NUM 5
#endif
#if ((((((!defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET) || !defined(CONFIG_BFIN548_EZKIT) || (!defined(CONFIG_SND_SOC) && !defined(CONFIG_SND_SOC_MODULE))) && (!defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET) || !defined(CONFIG_BFIN548_EZKIT) || !defined(CONFIG_SND_SOC))) || (!defined(CONFIG_SND) && !defined(CONFIG_SND_MODULE))) && (!defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET) || !defined(CONFIG_BFIN548_EZKIT) || !defined(CONFIG_SND_SOC) || !defined(CONFIG_SND))) || (!defined(CONFIG_SOUND) && !defined(CONFIG_SOUND_MODULE))) && (!defined(CONFIG_SND) || !defined(CONFIG_BFIN548_EZKIT) || !defined(CONFIG_SOUND) || !defined(CONFIG_SND_SOC) || !defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET)) && (!defined(CONFIG_SND) || !defined(CONFIG_SOUND) || !defined(CONFIG_SND_SOC) || !defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET) || !defined(CONFIG_BFIN537_STAMP)) && ((defined(CONFIG_SND_SOC) && defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET) && defined(CONFIG_SND) && defined(CONFIG_SOUND)) || (((defined(CONFIG_SND_SOC) && defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET) && defined(CONFIG_SND)) || (((defined(CONFIG_SND_SOC) && defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET)) || (defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET) && (defined(CONFIG_SND_SOC) || defined(CONFIG_SND_SOC_MODULE)))) && (defined(CONFIG_SND) || defined(CONFIG_SND_MODULE)))) && (defined(CONFIG_SOUND) || defined(CONFIG_SOUND_MODULE)))) && (((((!defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET) || !defined(CONFIG_BFIN537_STAMP) || (!defined(CONFIG_SND_SOC) && !defined(CONFIG_SND_SOC_MODULE))) && (!defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET) || !defined(CONFIG_BFIN537_STAMP) || !defined(CONFIG_SND_SOC))) || (!defined(CONFIG_SND) && !defined(CONFIG_SND_MODULE))) && (!defined(CONFIG_SND_BF5XX_HAVE_COLD_RESET) || !defined(CONFIG_BFIN537_STAMP) || !defined(CONFIG_SND_SOC) || !defined(CONFIG_SND))) || (!defined(CONFIG_SOUND) && !defined(CONFIG_SOUND_MODULE))))
  #define CONFIG_SND_BF5XX_RESET_GPIO_NUM 0
#endif

#define CONFIG_SND_BF5XX_SPORT_NUM 0

#define CONFIG_SND_BFIN_AD73311_SE 4

#define CONFIG_SND_HDA_INPUT_BEEP_MODE 1

#define CONFIG_SND_HDA_POWER_SAVE_DEFAULT 0

#define CONFIG_SND_PS3_DEFAULT_START_DELAY 2000

#define CONFIG_SOUND_SH_DAC_AUDIO_CHANNEL 1

#define CONFIG_SPI_ERROR 7

#undef CONFIG_SPLIT_PTLOCK_CPUS
#if (defined(CONFIG_DEBUG_SPINLOCK) || defined(CONFIG_DEBUG_LOCK_ALLOC))
  #define CONFIG_SPLIT_PTLOCK_CPUS 999999
#endif
#if (!defined(CONFIG_DEBUG_SPINLOCK) && !defined(CONFIG_DEBUG_LOCK_ALLOC))
  #define CONFIG_SPLIT_PTLOCK_CPUS 4
#endif

#define CONFIG_SPORT0_ERROR 7

#define CONFIG_SPORT1_ERROR 7

#undef CONFIG_SPORT_BAUD_RATE
#if ((defined(CONFIG_SERIAL_BFIN_SPORT) && defined(CONFIG_SERIAL_SPORT_BAUD_RATE_115200) && defined(CONFIG_HAS_IOMEM)) || (defined(CONFIG_HAS_IOMEM) && ((defined(CONFIG_SERIAL_BFIN_SPORT) && defined(CONFIG_SERIAL_SPORT_BAUD_RATE_115200)) || (defined(CONFIG_SERIAL_SPORT_BAUD_RATE_115200) && (defined(CONFIG_SERIAL_BFIN_SPORT) || defined(CONFIG_SERIAL_BFIN_SPORT_MODULE))))))
  #define CONFIG_SPORT_BAUD_RATE 115200
#endif
#if ((!defined(CONFIG_HAS_IOMEM) || ((!defined(CONFIG_SERIAL_SPORT_BAUD_RATE_115200) || (!defined(CONFIG_SERIAL_BFIN_SPORT) && !defined(CONFIG_SERIAL_BFIN_SPORT_MODULE))) && (!defined(CONFIG_SERIAL_BFIN_SPORT) || !defined(CONFIG_SERIAL_SPORT_BAUD_RATE_115200)))) && (!defined(CONFIG_SERIAL_BFIN_SPORT) || !defined(CONFIG_SERIAL_SPORT_BAUD_RATE_115200) || !defined(CONFIG_HAS_IOMEM)) && ((defined(CONFIG_SERIAL_BFIN_SPORT) && defined(CONFIG_SERIAL_SPORT_BAUD_RATE_57600) && defined(CONFIG_HAS_IOMEM)) || (defined(CONFIG_HAS_IOMEM) && ((defined(CONFIG_SERIAL_BFIN_SPORT) && defined(CONFIG_SERIAL_SPORT_BAUD_RATE_57600)) || (defined(CONFIG_SERIAL_SPORT_BAUD_RATE_57600) && (defined(CONFIG_SERIAL_BFIN_SPORT) || defined(CONFIG_SERIAL_BFIN_SPORT_MODULE)))))))
  #define CONFIG_SPORT_BAUD_RATE 57600
#endif
#if (((defined(CONFIG_SERIAL_BFIN_SPORT) && defined(CONFIG_SERIAL_SPORT_BAUD_RATE_38400) && defined(CONFIG_HAS_IOMEM)) || (defined(CONFIG_HAS_IOMEM) && ((defined(CONFIG_SERIAL_BFIN_SPORT) && defined(CONFIG_SERIAL_SPORT_BAUD_RATE_38400)) || (defined(CONFIG_SERIAL_SPORT_BAUD_RATE_38400) && (defined(CONFIG_SERIAL_BFIN_SPORT) || defined(CONFIG_SERIAL_BFIN_SPORT_MODULE)))))) && (!defined(CONFIG_HAS_IOMEM) || ((!defined(CONFIG_SERIAL_SPORT_BAUD_RATE_57600) || (!defined(CONFIG_SERIAL_BFIN_SPORT) && !defined(CONFIG_SERIAL_BFIN_SPORT_MODULE))) && (!defined(CONFIG_SERIAL_BFIN_SPORT) || !defined(CONFIG_SERIAL_SPORT_BAUD_RATE_57600)))) && (!defined(CONFIG_SERIAL_BFIN_SPORT) || !defined(CONFIG_SERIAL_SPORT_BAUD_RATE_115200) || !defined(CONFIG_HAS_IOMEM)) && (!defined(CONFIG_SERIAL_BFIN_SPORT) || !defined(CONFIG_SERIAL_SPORT_BAUD_RATE_57600) || !defined(CONFIG_HAS_IOMEM)) && (!defined(CONFIG_HAS_IOMEM) || ((!defined(CONFIG_SERIAL_SPORT_BAUD_RATE_115200) || (!defined(CONFIG_SERIAL_BFIN_SPORT) && !defined(CONFIG_SERIAL_BFIN_SPORT_MODULE))) && (!defined(CONFIG_SERIAL_BFIN_SPORT) || !defined(CONFIG_SERIAL_SPORT_BAUD_RATE_115200)))))
  #define CONFIG_SPORT_BAUD_RATE 38400
#endif
#if ((!defined(CONFIG_SERIAL_BFIN_SPORT) || !defined(CONFIG_SERIAL_SPORT_BAUD_RATE_38400) || !defined(CONFIG_HAS_IOMEM)) && (!defined(CONFIG_HAS_IOMEM) || ((!defined(CONFIG_SERIAL_SPORT_BAUD_RATE_57600) || (!defined(CONFIG_SERIAL_BFIN_SPORT) && !defined(CONFIG_SERIAL_BFIN_SPORT_MODULE))) && (!defined(CONFIG_SERIAL_BFIN_SPORT) || !defined(CONFIG_SERIAL_SPORT_BAUD_RATE_57600)))) && (!defined(CONFIG_SERIAL_BFIN_SPORT) || !defined(CONFIG_SERIAL_SPORT_BAUD_RATE_115200) || !defined(CONFIG_HAS_IOMEM)) && ((defined(CONFIG_SERIAL_BFIN_SPORT) && defined(CONFIG_SERIAL_SPORT_BAUD_RATE_19200) && defined(CONFIG_HAS_IOMEM)) || (defined(CONFIG_HAS_IOMEM) && ((defined(CONFIG_SERIAL_BFIN_SPORT) && defined(CONFIG_SERIAL_SPORT_BAUD_RATE_19200)) || (defined(CONFIG_SERIAL_SPORT_BAUD_RATE_19200) && (defined(CONFIG_SERIAL_BFIN_SPORT) || defined(CONFIG_SERIAL_BFIN_SPORT_MODULE)))))) && (!defined(CONFIG_SERIAL_BFIN_SPORT) || !defined(CONFIG_SERIAL_SPORT_BAUD_RATE_57600) || !defined(CONFIG_HAS_IOMEM)) && (!defined(CONFIG_HAS_IOMEM) || ((!defined(CONFIG_SERIAL_SPORT_BAUD_RATE_38400) || (!defined(CONFIG_SERIAL_BFIN_SPORT) && !defined(CONFIG_SERIAL_BFIN_SPORT_MODULE))) && (!defined(CONFIG_SERIAL_BFIN_SPORT) || !defined(CONFIG_SERIAL_SPORT_BAUD_RATE_38400)))) && (!defined(CONFIG_HAS_IOMEM) || ((!defined(CONFIG_SERIAL_SPORT_BAUD_RATE_115200) || (!defined(CONFIG_SERIAL_BFIN_SPORT) && !defined(CONFIG_SERIAL_BFIN_SPORT_MODULE))) && (!defined(CONFIG_SERIAL_BFIN_SPORT) || !defined(CONFIG_SERIAL_SPORT_BAUD_RATE_115200)))))
  #define CONFIG_SPORT_BAUD_RATE 19200
#endif
#if ((!defined(CONFIG_SERIAL_BFIN_SPORT) || !defined(CONFIG_SERIAL_SPORT_BAUD_RATE_38400) || !defined(CONFIG_HAS_IOMEM)) && ((defined(CONFIG_SERIAL_BFIN_SPORT) && defined(CONFIG_SERIAL_SPORT_BAUD_RATE_9600) && defined(CONFIG_HAS_IOMEM)) || (defined(CONFIG_HAS_IOMEM) && ((defined(CONFIG_SERIAL_BFIN_SPORT) && defined(CONFIG_SERIAL_SPORT_BAUD_RATE_9600)) || (defined(CONFIG_SERIAL_SPORT_BAUD_RATE_9600) && (defined(CONFIG_SERIAL_BFIN_SPORT) || defined(CONFIG_SERIAL_BFIN_SPORT_MODULE)))))) && (!defined(CONFIG_HAS_IOMEM) || ((!defined(CONFIG_SERIAL_SPORT_BAUD_RATE_57600) || (!defined(CONFIG_SERIAL_BFIN_SPORT) && !defined(CONFIG_SERIAL_BFIN_SPORT_MODULE))) && (!defined(CONFIG_SERIAL_BFIN_SPORT) || !defined(CONFIG_SERIAL_SPORT_BAUD_RATE_57600)))) && (!defined(CONFIG_SERIAL_BFIN_SPORT) || !defined(CONFIG_SERIAL_SPORT_BAUD_RATE_115200) || !defined(CONFIG_HAS_IOMEM)) && (!defined(CONFIG_SERIAL_BFIN_SPORT) || !defined(CONFIG_SERIAL_SPORT_BAUD_RATE_19200) || !defined(CONFIG_HAS_IOMEM)) && (!defined(CONFIG_HAS_IOMEM) || ((!defined(CONFIG_SERIAL_SPORT_BAUD_RATE_19200) || (!defined(CONFIG_SERIAL_BFIN_SPORT) && !defined(CONFIG_SERIAL_BFIN_SPORT_MODULE))) && (!defined(CONFIG_SERIAL_BFIN_SPORT) || !defined(CONFIG_SERIAL_SPORT_BAUD_RATE_19200)))) && (!defined(CONFIG_SERIAL_BFIN_SPORT) || !defined(CONFIG_SERIAL_SPORT_BAUD_RATE_57600) || !defined(CONFIG_HAS_IOMEM)) && (!defined(CONFIG_HAS_IOMEM) || ((!defined(CONFIG_SERIAL_SPORT_BAUD_RATE_38400) || (!defined(CONFIG_SERIAL_BFIN_SPORT) && !defined(CONFIG_SERIAL_BFIN_SPORT_MODULE))) && (!defined(CONFIG_SERIAL_BFIN_SPORT) || !defined(CONFIG_SERIAL_SPORT_BAUD_RATE_38400)))) && (!defined(CONFIG_HAS_IOMEM) || ((!defined(CONFIG_SERIAL_SPORT_BAUD_RATE_115200) || (!defined(CONFIG_SERIAL_BFIN_SPORT) && !defined(CONFIG_SERIAL_BFIN_SPORT_MODULE))) && (!defined(CONFIG_SERIAL_BFIN_SPORT) || !defined(CONFIG_SERIAL_SPORT_BAUD_RATE_115200)))))
  #define CONFIG_SPORT_BAUD_RATE 9600
#endif

#define CONFIG_SQUASHFS_FRAGMENT_CACHE_SIZE 3

#define CONFIG_SYMBOL_PREFIX "_"

#undef CONFIG_TIMER0
#if (defined(CONFIG_TICKSOURCE_GPTMR0) && (defined(CONFIG_BF532) || defined(CONFIG_BF531) || defined(CONFIG_BF533)))
  #define CONFIG_TIMER0 7
#endif
#if (!defined(CONFIG_TICKSOURCE_GPTMR0) && (defined(CONFIG_BF532) || defined(CONFIG_BF531) || defined(CONFIG_BF533)))
  #define CONFIG_TIMER0 8
#endif

#define CONFIG_TIMER1 11

#define CONFIG_TIMER2 11

#define CONFIG_TIPC_CLUSTERS 1

#define CONFIG_TIPC_LOG 0

#define CONFIG_TIPC_NODES 255

#define CONFIG_TIPC_PORTS 8191

#define CONFIG_TIPC_SLAVE_NODES 0

#define CONFIG_TIPC_ZONES 3

#define CONFIG_TRIX_BOOT_FILE "/etc/sound/trxpro.hex"

#define CONFIG_UART0_CTS_PIN 23

#define CONFIG_UART0_RTS_PIN 22

#define CONFIG_UART1_CTS_PIN -1

#define CONFIG_UART1_RTS_PIN -1

#define CONFIG_UART2_CTS_PIN -1

#define CONFIG_UART2_RTS_PIN -1

#define CONFIG_UART3_CTS_PIN -1

#define CONFIG_UART3_RTS_PIN -1

#define CONFIG_UART_ERROR 7

#define CONFIG_UBIFS_FS_DEBUG_MSG_LVL 0

#define CONFIG_UEVENT_HELPER_PATH "/sbin/hotplug"

#define CONFIG_USB_GADGET_VBUS_DRAW 2

#undef CONFIG_VCO_MULT
#if ((!defined(CONFIG_PLL_BYPASS) && defined(CONFIG_BFIN533_EZKIT) && defined(CONFIG_BFIN_KERNEL_CLOCK)) || (defined(CONFIG_BFIN533_BLUETECHNIX_CM) && !defined(CONFIG_PLL_BYPASS) && defined(CONFIG_BFIN_KERNEL_CLOCK) && (defined(CONFIG_PLL_BYPASS) || (!defined(CONFIG_BFIN538_EZKIT) && !defined(CONFIG_BFIN548_EZKIT) && !defined(CONFIG_BFIN527_EZKIT) && !defined(CONFIG_BFIN548_BLUETECHNIX_CM) && !defined(CONFIG_BFIN537_STAMP)) || !defined(CONFIG_BFIN_KERNEL_CLOCK)) && (defined(CONFIG_PLL_BYPASS) || !defined(CONFIG_BFIN533_STAMP) || !defined(CONFIG_BFIN_KERNEL_CLOCK))))
  #define CONFIG_VCO_MULT 22
#endif
#if (!defined(CONFIG_PLL_BYPASS) && defined(CONFIG_BFIN533_STAMP) && defined(CONFIG_BFIN_KERNEL_CLOCK) && (defined(CONFIG_PLL_BYPASS) || !defined(CONFIG_BFIN533_EZKIT) || !defined(CONFIG_BFIN_KERNEL_CLOCK)))
  #define CONFIG_VCO_MULT 45
#endif
#if ((!defined(CONFIG_PLL_BYPASS) && (defined(CONFIG_BFIN538_EZKIT) || defined(CONFIG_BFIN527_EZKIT) || defined(CONFIG_BFIN548_EZKIT) || defined(CONFIG_BFIN537_STAMP) || defined(CONFIG_BFIN548_BLUETECHNIX_CM)) && defined(CONFIG_BFIN_KERNEL_CLOCK) && (defined(CONFIG_PLL_BYPASS) || !defined(CONFIG_BFIN533_EZKIT) || !defined(CONFIG_BFIN_KERNEL_CLOCK)) && (defined(CONFIG_PLL_BYPASS) || !defined(CONFIG_BFIN533_STAMP) || !defined(CONFIG_BFIN_KERNEL_CLOCK))) || ((defined(CONFIG_PLL_BYPASS) || !defined(CONFIG_BFIN533_BLUETECHNIX_CM) || !defined(CONFIG_BFIN_KERNEL_CLOCK)) && (defined(CONFIG_BFIN527_BLUETECHNIX_CM) || defined(CONFIG_BFIN561_BLUETECHNIX_CM) || defined(CONFIG_BFIN537_BLUETECHNIX_CM_U) || defined(CONFIG_BFIN537_BLUETECHNIX_CM_E)) && !defined(CONFIG_PLL_BYPASS) && defined(CONFIG_BFIN_KERNEL_CLOCK) && (defined(CONFIG_PLL_BYPASS) || !defined(CONFIG_BFIN533_EZKIT) || !defined(CONFIG_BFIN_KERNEL_CLOCK)) && (defined(CONFIG_PLL_BYPASS) || (!defined(CONFIG_BFIN538_EZKIT) && !defined(CONFIG_BFIN548_EZKIT) && !defined(CONFIG_BFIN527_EZKIT) && !defined(CONFIG_BFIN548_BLUETECHNIX_CM) && !defined(CONFIG_BFIN537_STAMP)) || !defined(CONFIG_BFIN_KERNEL_CLOCK)) && (defined(CONFIG_PLL_BYPASS) || !defined(CONFIG_BFIN533_STAMP) || !defined(CONFIG_BFIN_KERNEL_CLOCK))) || ((defined(CONFIG_PLL_BYPASS) || !defined(CONFIG_BFIN533_BLUETECHNIX_CM) || !defined(CONFIG_BFIN_KERNEL_CLOCK)) && (defined(CONFIG_PLL_BYPASS) || (!defined(CONFIG_BFIN527_BLUETECHNIX_CM) && !defined(CONFIG_BFIN561_BLUETECHNIX_CM) && !defined(CONFIG_BFIN537_BLUETECHNIX_CM_U) && !defined(CONFIG_BFIN537_BLUETECHNIX_CM_E)) || !defined(CONFIG_BFIN_KERNEL_CLOCK)) && defined(CONFIG_BFIN561_EZKIT) && !defined(CONFIG_PLL_BYPASS) && defined(CONFIG_BFIN_KERNEL_CLOCK) && (defined(CONFIG_PLL_BYPASS) || !defined(CONFIG_BFIN533_EZKIT) || !defined(CONFIG_BFIN_KERNEL_CLOCK)) && (defined(CONFIG_PLL_BYPASS) || (!defined(CONFIG_BFIN538_EZKIT) && !defined(CONFIG_BFIN548_EZKIT) && !defined(CONFIG_BFIN527_EZKIT) && !defined(CONFIG_BFIN548_BLUETECHNIX_CM) && !defined(CONFIG_BFIN537_STAMP)) || !defined(CONFIG_BFIN_KERNEL_CLOCK)) && (defined(CONFIG_PLL_BYPASS) || !defined(CONFIG_BFIN533_STAMP) || !defined(CONFIG_BFIN_KERNEL_CLOCK))))
  #define CONFIG_VCO_MULT 20
#endif
#if ((defined(CONFIG_PLL_BYPASS) || !defined(CONFIG_BFIN533_BLUETECHNIX_CM) || !defined(CONFIG_BFIN_KERNEL_CLOCK)) && (defined(CONFIG_PLL_BYPASS) || (!defined(CONFIG_BFIN527_BLUETECHNIX_CM) && !defined(CONFIG_BFIN561_BLUETECHNIX_CM) && !defined(CONFIG_BFIN537_BLUETECHNIX_CM_U) && !defined(CONFIG_BFIN537_BLUETECHNIX_CM_E)) || !defined(CONFIG_BFIN_KERNEL_CLOCK)) && (defined(CONFIG_BFIN526_EZBRD) || defined(CONFIG_BFIN518F_EZBRD) || defined(CONFIG_BLACKSTAMP) || defined(CONFIG_H8606_HVSISTEMAS)) && !defined(CONFIG_PLL_BYPASS) && (defined(CONFIG_PLL_BYPASS) || !defined(CONFIG_BFIN561_EZKIT) || !defined(CONFIG_BFIN_KERNEL_CLOCK)) && defined(CONFIG_BFIN_KERNEL_CLOCK) && (defined(CONFIG_PLL_BYPASS) || !defined(CONFIG_BFIN533_EZKIT) || !defined(CONFIG_BFIN_KERNEL_CLOCK)) && (defined(CONFIG_PLL_BYPASS) || (!defined(CONFIG_BFIN538_EZKIT) && !defined(CONFIG_BFIN548_EZKIT) && !defined(CONFIG_BFIN527_EZKIT) && !defined(CONFIG_BFIN548_BLUETECHNIX_CM) && !defined(CONFIG_BFIN537_STAMP)) || !defined(CONFIG_BFIN_KERNEL_CLOCK)) && (defined(CONFIG_PLL_BYPASS) || !defined(CONFIG_BFIN533_STAMP) || !defined(CONFIG_BFIN_KERNEL_CLOCK)))
  #define CONFIG_VCO_MULT 16
#endif

#define CONFIG_VGACON_SOFT_SCROLLBACK_SIZE 64

#define CONFIG_WDTIMER 13

#define CONFIG_WIMAX_DEBUG_LEVEL 8

#define CONFIG_WIMAX_I2400M_DEBUG_LEVEL 8

#undef CONFIG_ZONE_DMA_FLAG
#if !defined(CONFIG_ZONE_DMA)
  #define CONFIG_ZONE_DMA_FLAG 0
#endif
#if defined(CONFIG_ZONE_DMA)
  #define CONFIG_ZONE_DMA_FLAG 1
#endif

