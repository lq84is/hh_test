#ifndef ITMPRINT_H
#define ITMPRINT_H
#include <stdarg.h>
#include "AuxFunctions/printf.h"

#define USE_UART
//#define USE_ITM

#if defined(USE_UART) && defined(USE_ITM)
#error USE_UART and USE_ITM defined, choose one
#endif    

void ITMPrint_init(void);
int tsprintf(const char *format, ...);

int tssprintf(char* out, const char *format, ...);

#define ENABLE_DISPLAY_WARNING  (0)
#define ENABLE_FLASH_WARNING    (1)


#define PRINT(...)             tsprintf(__VA_ARGS__)
#define PRINT_POSITION(...)    tsprintf("[%s:%d]:%s\t", __MODULE__, __LINE__, __FUNCTION__);tsprintf(__VA_ARGS__);tsprintf("\r\n");
#define PRNT_FBEGIN()          PRINT_POSITION("BEGIN")
#define PRNT_FEND()            PRINT_POSITION("END")
#define PRINT_DEBUG_TRACE(...) PRINT_POSITION(__VA_ARGS__)

#if ENABLE_DISPLAY_WARNING
#define DISPLAY_WARN()   tsprintf("(%s:%d):\t%s:\tDRAWING ON GLCD\r\n", __MODULE__, __LINE__, __FUNCTION__);
#else
#define DISPLAY_WARN()  do {}while(0);
#endif

#if ENABLE_FLASH_WARNING
#define FLASH_WARN()   tsprintf("(%s:%d):\t%s:\tWRITING FLASH\r\n", __MODULE__, __LINE__, __FUNCTION__);
#else
#define FLASH_WARN()  do {}while(0);
#endif
    
typedef const char* translations_t[][2];    

    
#endif
