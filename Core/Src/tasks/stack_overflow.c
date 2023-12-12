#include "AuxFunctions/printf.h"
#include "FreeRTOS.h"
#include "task.h"

void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName ){
    const char* separator = "\r\n==================================\r\n";
    printf("%sStack overflow: %s%s", separator, pcTaskName, separator);
}

