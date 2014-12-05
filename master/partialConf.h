#ifdef CONFIG_DYNAMIC_DEBUG
 #define DEBUG_HASH 1
 #define DEBUG_HASH2 2
#endif

#define AUTOCONF_INCLUDED

#define OBJTREE ""
#define SRCTREE ""

#define KBUILD_STR(s) #s

//Non-boolean features
#define CONFIG_X86_L1_CACHE_SHIFT 5
#define CONFIG_X86_INTERNODE_CACHE_SHIFT 5
#define CONFIG_IO_DELAY_TYPE_0X80 0
#define CONFIG_IO_DELAY_TYPE_0XED 1
#define CONFIG_DEFAULT_IO_DELAY_TYPE 0
#define CONFIG_IO_DELAY_TYPE_NONE 3

#define CONFIG_HZ 250
#define HZ 250

#define CONFIG_X86_MINIMUM_CPU_FAMILY 5

#undef ACPI_CUSTOM_DSDT //triggers invalid include otherwise
