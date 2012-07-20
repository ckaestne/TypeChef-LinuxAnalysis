#ifdef CONFIG_SMP
#define CONFIG_NR_CPUS 8
#else
#define CONFIG_NR_CPUS 1
#endif

//encode numeric parameter
#ifdef CONFIG_ZONE_DMA
#define CONFIG_ZONE_DMA_FLAG 1
#else
#define CONFIG_ZONE_DMA_FLAG 0
#endif

#define CONFIG_X86

#ifdef CONFIG_NEED_MULTIPLE_NODES
	#define CONFIG_NODES_SHIFT 3
#endif

//from scripts/Makefile.lib 
#ifdef CONFIG_DYNAMIC_DEBUG
	#define DEBUG_HASH 1
	#define DEBUG_HASH2 2
#endif

#ifdef CONFIG_MTRR_SANITIZER
	#define CONFIG_MTRR_SANITIZER_ENABLE_DEFAULT 0
	#define CONFIG_MTRR_SANITIZER_SPARE_REG_NR_DEFAULT 1
#endif

#ifdef CONFIG_CONFIG_CMDLINE
	#define CONFIG_CMDLINE ""
#endif

#define OBJTREE="";
#define SRCTREE="";

#ifdef CONFIG_BOOTPARAM_HUNG_TASK_PANIC_VALUE
	#ifdef CONFIG_BOOTPARAM_HUNG_TASK_PANIC	
		#define CONFIG_BOOTPARAM_HUNG_TASK_PANIC_VALUE 1
	#else
		#define CONFIG_BOOTPARAM_HUNG_TASK_PANIC_VALUE 0
	#endif
#endif

//Defines a 'if' macro, which triggers a bug: The preprocessor incorrectly
//expands this macro within "#if".
#undef CONFIG_TRACE_BRANCH_PROFILING
//Needs header provided by the user:
#undef CONFIG_ACPI_CUSTOM_DSDT

//Is always true on x86. If it's false it causes an error in
//arch/x86/include/asm/paravirt.h.
#define CONFIG_TRACE_IRQFLAGS_SUPPORT

/////////////////////////////////////
//All the following macros are always false on x86, even if defined or anyhow included in the feature model:
#undef CONFIG_SBUS
#undef CONFIG_ATA_NONSTANDARD

#undef CONFIG_ARCH_HAS_ASYNC_TX_FIND_CHANNEL
#undef CONFIG_OF
#undef CONFIG_OF_DEVICE
#undef CONFIG_LEDS_GPIO_OF
#undef CONFIG_MISDN_HFCMULTI_8xx //Depends on 8xx
#undef CONFIG_MTD_XIP
#undef CONFIG_MVME16x_NET //Depends on MVME16x
#undef CONFIG_TULIP_DM910X //Depends on SPARC
#undef CONFIG_SSB_PCICORE_HOSTMODE //Depends on MIPS
#undef CONFIG_USB_EHCI_MXC
#undef CONFIG_USB_OHCI_HCD_PPC_OF //Depends on PPC_OF
#undef CONFIG_ADB_PMU 

//Second & last round of disabling:
#undef CONFIG_OF_GPIO
#undef CONFIG_PMAC_BACKLIGHT
#undef CONFIG_BVME6000_NET
#undef CONFIG_VME
#undef CONFIG_BVME6000
#undef CONFIG_USB_EHCI_HCD_PPC_OF
#undef CONFIG_XPS_USB_HCD_XILINX
/////////////////////////////////////

//Non-boolean features
#define AUTOCONF_INCLUDED


#define CONFIG_FRAME_WARN 1024
#define CONFIG_ARCH_DEFCONFIG "arch/x86/configs/i386_defconfig"
#define CONFIG_RCU_FANOUT 32
#define CONFIG_OUTPUT_FORMAT "elf32-i386"
#define CONFIG_DEFCONFIG_LIST "/lib/modules/$UNAME_RELEASE/.config"
#define CONFIG_PHYSICAL_ALIGN 0x1000000
#define CONFIG_IO_DELAY_TYPE_UDELAY 2
#define CONFIG_INPUT_MOUSEDEV_SCREEN_X 1024
#define CONFIG_INPUT_MOUSEDEV_SCREEN_Y 768
#define CONFIG_X86_L1_CACHE_SHIFT 5
#define CONFIG_EXTRA_FIRMWARE ""
#define CONFIG_PAGE_OFFSET 0xC0000000
#define CONFIG_PHYSICAL_START 0x1000000
#define CONFIG_DEFAULT_MMAP_MIN_ADDR 4096
#define CONFIG_SPLIT_PTLOCK_CPUS 4
#define CONFIG_IO_DELAY_TYPE_0X80 0
#define CONFIG_IO_DELAY_TYPE_0XED 1
#define CONFIG_ILLEGAL_POINTER_VALUE 0x0
#define CONFIG_X86_INTERNODE_CACHE_SHIFT 5
#define CONFIG_DEFAULT_IOSCHED "noop"
#define CONFIG_DEFAULT_IO_DELAY_TYPE 0
#define CONFIG_UEVENT_HELPER_PATH "/sbin/hotplug"
#define CONFIG_LOCALVERSION ""
#define CONFIG_INIT_ENV_ARG_LIMIT 32
#define CONFIG_IO_DELAY_TYPE_NONE 3
#define CONFIG_HZ 250
#define CONFIG_X86_MINIMUM_CPU_FAMILY 5
#define CONFIG_DEFAULT_SECURITY ""
#define CONFIG_BASE_SMALL 0
#define CONFIG_LOG_BUF_SHIFT 17
#undef CONFIG_PANEL_BOOT_MESSAGE

#define KBUILD_STR(s) #s



#define CONFIG_CMDLINE ""

#ifdef CONFIG_KMEMCHECK
	#define CONFIG_KMEMCHECK_SHADOW_COPY_SHIFT 5
	#define CONFIG_KMEMCHECK_QUEUE_SIZE 64
#endif
#ifdef CONFIG_ATM_FORE200E
	#define CONFIG_ATM_FORE200E_TX_RETRY 16
#endif
#ifdef CONFIG_CFAG12864B
	#define CONFIG_CFAG12864B_RATE 20
#endif
#ifdef CONFIG_KS0108
	#define CONFIG_KS0108_PORT 0x378
	#define CONFIG_KS0108_DELAY 2
#endif
#ifdef CONFIG_BLK_DEV_RAM
	#define CONFIG_BLK_DEV_RAM_SIZE 4096
	#define CONFIG_BLK_DEV_RAM_COUNT 16
#endif
#ifdef CONFIG_CDROM_PKTCDVD
	#define CONFIG_CDROM_PKTCDVD_BUFFERS 8
#endif
#ifdef CONFIG_LEGACY_PTYS
	#define CONFIG_LEGACY_PTY_COUNT 256
#endif
#ifdef CONFIG_RAW_DRIVER
	#define CONFIG_MAX_RAW_DEVS 256
#endif
#if defined(CONFIG_I2C_BLACKFIN_TWI)
  #define CONFIG_I2C_BLACKFIN_TWI_CLK_KHZ 50
#endif
#if defined(CONFIG_SCx200_I2C)
  #define CONFIG_SCx200_I2C_SCL 12
#endif
#if defined(CONFIG_SCx200_I2C)
  #define CONFIG_SCx200_I2C_SDA 13
#endif

#define CONFIG_HISAX_MAX_CARDS 8

#if defined(CONFIG_RADIO_RTRACK)
  #define CONFIG_RADIO_RTRACK_PORT 0x20f
#endif
#if defined(CONFIG_RADIO_RTRACK2)
  #define CONFIG_RADIO_RTRACK2_PORT 0x30c
#endif
#if defined(CONFIG_RADIO_AZTECH)
  #define CONFIG_RADIO_AZTECH_PORT 0x350
#endif
#if defined(CONFIG_RADIO_GEMTEK)
  #define CONFIG_RADIO_GEMTEK_PORT 0x34c
#endif
#if defined(CONFIG_RADIO_TERRATEC)
  #define CONFIG_RADIO_TERRATEC_PORT 0x590
#endif
#if defined(CONFIG_RADIO_TRUST)
  #define CONFIG_RADIO_TRUST_PORT 0x350
#endif
#if defined(CONFIG_RADIO_TYPHOON)
  #define CONFIG_RADIO_TYPHOON_PORT 0x316
#endif
#if defined(CONFIG_RADIO_TYPHOON)
  #define CONFIG_RADIO_TYPHOON_MUTEFREQ 87500
#endif
#if defined(CONFIG_RADIO_ZOLTRIX)
  #define CONFIG_RADIO_ZOLTRIX_PORT 0x20c
#endif

#if defined(CONFIG_MTD_DEBUG)
  #define CONFIG_MTD_DEBUG_VERBOSE 0
#endif
#if defined(CONFIG_MTD_REDBOOT_PARTS)
  #define CONFIG_MTD_REDBOOT_DIRECTORY_BLOCK -1
#endif

#if defined(CONFIG_BFIN_MAC)
  #define CONFIG_BFIN_TX_DESC_NUM 10
#endif
#if defined(CONFIG_BFIN_MAC)
  #define CONFIG_BFIN_RX_DESC_NUM 20
#endif
#if defined(CONFIG_DM9000)
  #define CONFIG_DM9000_DEBUGLEVEL 4
#endif
#if defined(CONFIG_RIONET)
  #define CONFIG_RIONET_TX_SIZE 128
#endif
#if defined(CONFIG_RIONET)
  #define CONFIG_RIONET_RX_SIZE 128
#endif

#if defined(CONFIG_WIMAX_I2400M)
  #define CONFIG_WIMAX_I2400M_DEBUG_LEVEL 8
#endif

#if defined(CONFIG_RTC_HCTOSYS) 
  #define CONFIG_RTC_HCTOSYS_DEVICE "rtc0"
#endif
#if defined(CONFIG_RTC_DRV_AT91SAM9)
  #define CONFIG_RTC_DRV_AT91SAM9_RTT 0
#endif
#if defined(CONFIG_RTC_DRV_AT91SAM9)
  #define CONFIG_RTC_DRV_AT91SAM9_GPBR 0
#endif

#if defined(CONFIG_SCSI_EATA)
  #define CONFIG_SCSI_EATA_MAX_TAGS 16
#endif
#if defined(CONFIG_SCSI_SYM53C8XX_2)
  #define CONFIG_SCSI_SYM53C8XX_DMA_ADDRESSING_MODE 1
#endif
#if defined(CONFIG_SCSI_SYM53C8XX_2)
  #define CONFIG_SCSI_SYM53C8XX_DEFAULT_TAGS 16
#endif
#if defined(CONFIG_SCSI_SYM53C8XX_2)
  #define CONFIG_SCSI_SYM53C8XX_MAX_TAGS 64
#endif
#if defined(CONFIG_SCSI_ZALON) || defined(CONFIG_SCSI_NCR_Q720)
  #define CONFIG_SCSI_NCR53C8XX_DEFAULT_TAGS 8
#endif
#if defined(CONFIG_SCSI_ZALON) || defined(CONFIG_SCSI_NCR_Q720)
  #define CONFIG_SCSI_NCR53C8XX_MAX_TAGS 32
#endif
#if defined(CONFIG_SCSI_ZALON) || defined(CONFIG_SCSI_NCR_Q720)
  #define CONFIG_SCSI_NCR53C8XX_SYNC 20
#endif
#if defined(CONFIG_SCSI_U14_34F)
  #define CONFIG_SCSI_U14_34F_MAX_TAGS 8
#endif
#if defined(CONFIG_SCSI_MESH)
  #define CONFIG_SCSI_MESH_SYNC_RATE 5
#endif
#if defined(CONFIG_SCSI_MESH)
  #define CONFIG_SCSI_MESH_RESET_DELAY_MS 4000
#endif

#if defined(CONFIG_SMB_NLS_DEFAULT)
  #define CONFIG_SMB_NLS_REMOTE "cp437"
#endif

#if defined(CONFIG_SQUASHFS)
  #define CONFIG_SQUASHFS_FRAGMENT_CACHE_SIZE 3
#endif

#define CONFIG_IP_VS_TAB_BITS 12

#if defined(CONFIG_WIMAX)
  #define CONFIG_WIMAX_DEBUG_LEVEL 8
#endif

#if defined(CONFIG_SND_AC97_POWER_SAVE)
  #define CONFIG_SND_AC97_POWER_SAVE_DEFAULT 0
#endif

#if defined(CONFIG_SND_HDA_INPUT_BEEP)
  #define CONFIG_SND_HDA_INPUT_BEEP_MODE 1
#endif
#if defined(CONFIG_SND_HDA_POWER_SAVE)
  #define CONFIG_SND_HDA_POWER_SAVE_DEFAULT 0
#endif

#if defined(CONFIG_RADIO_GEMTEK)
	#define CONFIG_RADIO_GEMTEK_PROBE 1
#endif
#if defined(CONFIG_ATMEL_TCB_CLKSRC)
  #define CONFIG_ATMEL_TCB_CLKSRC_BLOCK 0
#endif
#if defined(CONFIG_CS5535_MFGPT)
  #define CONFIG_CS5535_MFGPT_DEFAULT_IRQ 7
#endif

#if defined(CONFIG_SOUND_MSNDCLAS)
  #define CONFIG_MSNDCLAS_INIT_FILE "/etc/sound/msndinit.bin"
#endif
#if defined(CONFIG_SOUND_MSNDCLAS)
  #define CONFIG_MSNDCLAS_PERM_FILE "/etc/sound/msndperm.bin"
#endif
#if defined(CONFIG_SOUND_MSNDCLAS)
  #define CONFIG_MSNDCLAS_IRQ 5
#endif
#if defined(CONFIG_SOUND_MSNDCLAS)
  #define CONFIG_MSNDCLAS_MEM 0xD0000
#endif
#if defined(CONFIG_SOUND_MSNDCLAS)
  #define CONFIG_MSNDCLAS_IO 0x290
#endif
#if defined(CONFIG_SOUND_MSNDPIN)
  #define CONFIG_MSNDPIN_INIT_FILE "/etc/sound/pndspini.bin"
#endif
#if defined(CONFIG_SOUND_MSNDPIN)
  #define CONFIG_MSNDPIN_PERM_FILE "/etc/sound/pndsperm.bin"
#endif
#if defined(CONFIG_SOUND_MSNDPIN)
  #define CONFIG_MSNDPIN_IRQ 5
#endif
#if defined(CONFIG_SOUND_MSNDPIN)
  #define CONFIG_MSNDPIN_MEM 0xD0000
#endif
#if defined(CONFIG_SOUND_MSNDPIN)
  #define CONFIG_MSNDPIN_IO 0x290
#endif
#if defined(CONFIG_MSNDPIN_NONPNP)
  #define CONFIG_MSNDPIN_CFG 0x250
#endif
#if defined(CONFIG_MSNDPIN_NONPNP)
  #define CONFIG_MSNDPIN_MPU_IO 0x0
#endif
#if defined(CONFIG_MSNDPIN_NONPNP)
  #define CONFIG_MSNDPIN_MPU_IRQ 0
#endif
#if defined(CONFIG_MSNDPIN_NONPNP)
  #define CONFIG_MSNDPIN_IDE_IO0 0x0
#endif
#if defined(CONFIG_MSNDPIN_NONPNP)
  #define CONFIG_MSNDPIN_IDE_IO1 0x0
#endif
#if defined(CONFIG_MSNDPIN_NONPNP)
  #define CONFIG_MSNDPIN_IDE_IRQ 0
#endif
#if defined(CONFIG_MSNDPIN_NONPNP)
  #define CONFIG_MSNDPIN_JOYSTICK_IO 0x0
#endif
#if defined(CONFIG_SOUND_MSNDPIN) || defined(CONFIG_SOUND_MSNDCLAS)
  #define CONFIG_MSND_FIFOSIZE 128
#endif
#if defined(CONFIG_TRIX_HAVE_BOOT)
  #define CONFIG_TRIX_BOOT_FILE "/etc/sound/trxpro.hex"
#endif
#if defined(CONFIG_PSS_HAVE_BOOT)
  #define CONFIG_PSS_BOOT_FILE "/etc/sound/dsp001.ld"
#endif
#if defined(CONFIG_SC6600)
  #define CONFIG_SC6600_CDROM 4
#endif
#if defined(CONFIG_SC6600)
  #define CONFIG_SC6600_CDROMBASE 0x0
#endif
#if defined(CONFIG_SOUND_SH_DAC_AUDIO)
  #define CONFIG_SOUND_SH_DAC_AUDIO_CHANNEL 1
#endif

#if defined(CONFIG_KGDB_TESTS_ON_BOOT)
  #define CONFIG_KGDB_TESTS_BOOT_STRING "V1F100"
#endif

#if defined(CONFIG_MTD_MTDRAM)
  #define CONFIG_MTDRAM_TOTAL_SIZE 4096
#endif
#if defined(CONFIG_MTD_MTDRAM)
  #define CONFIG_MTDRAM_ERASE_SIZE 128
#endif
#if defined(CONFIG_MTD_MTDRAM)
  #define CONFIG_MTDRAM_ABS_POS 0x0
#endif
#if defined(CONFIG_MTD_DOCPROBE)
  #define CONFIG_MTD_DOCPROBE_ADDRESS 0x0 
#endif

#if defined(CONFIG_MTD_NAND_DISKONCHIP)
  #define CONFIG_MTD_NAND_DISKONCHIP_PROBE_ADDRESS 0x0
#endif

#if defined(CONFIG_MTD_UBI)
  #define CONFIG_MTD_UBI_WL_THRESHOLD 4096
#endif
#if defined(CONFIG_MTD_UBI)
  #define CONFIG_MTD_UBI_BEB_RESERVE 1
#endif

//lib/KConfig.debug
#ifdef CONFIG_DEBUG_OBJECTS
  #define CONFIG_DEBUG_OBJECTS_ENABLE_DEFAULT 1
#endif
#if defined(CONFIG_DEBUG_KMEMLEAK)
  #define CONFIG_DEBUG_KMEMLEAK_EARLY_LOG_SIZE 400
#endif

//mm/KConfig
#define CONFIG_SPLIT_PTLOCK_CPUS 4
#define CONFIG_ZONE_DMA_FLAG 1
#if defined(CONFIG_QUICKLIST)
  #define CONFIG_NR_QUICK 1
#endif
#if defined(CONFIG_MMU)
  #define CONFIG_DEFAULT_MMAP_MIN_ADDR 4096
#endif
#if !defined(CONFIG_MMU)
  #define CONFIG_NOMMU_INITIAL_TRIM_EXCESS 1
#endif

//[kaestner@kananga linux]$ ./run.sh de.fosd.typechef.linux.KConfigReader l/net/dccp/ccids/Kconfig
#if defined(CONFIG_IP_DCCP_CCID3) && defined(CONFIG_EXPERIMENTAL)
  #define CONFIG_IP_DCCP_CCID3_RTO 100
#endif

#define CONFIG_DEFAULT_TCP_CONG "cubic"
#define CONFIG_MAC80211_RC_DEFAULT ""

#if defined(CONFIG_NET_EMATCH)
  #define CONFIG_NET_EMATCH_STACK 32
#endif

#if defined(CONFIG_TIPC_ADVANCED)
  #define CONFIG_TIPC_ZONES 3
#endif
#if defined(CONFIG_TIPC_ADVANCED)
  #define CONFIG_TIPC_CLUSTERS 1
#endif
#if defined(CONFIG_TIPC_ADVANCED)
  #define CONFIG_TIPC_NODES 255
#endif
#if defined(CONFIG_TIPC_ADVANCED)
  #define CONFIG_TIPC_SLAVE_NODES 0
#endif
#if defined(CONFIG_TIPC_ADVANCED)
  #define CONFIG_TIPC_PORTS 8191
#endif
#if defined(CONFIG_TIPC_ADVANCED)
  #define CONFIG_TIPC_LOG 0
#endif
#if defined(CONFIG_SC6600)
  #define CONFIG_SC6600_CDROM 4
#endif
#if defined(CONFIG_SC6600)
  #define CONFIG_SC6600_CDROMBASE 0x0
#endif
#if defined(CONFIG_SC6600_JOY)
  #define CONFIG_SC6600_JOY 1
#endif
