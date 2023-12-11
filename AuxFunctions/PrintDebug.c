#include "AuxFunctions/printf.h"
#include "PrintDebug.h"
#include "cmsis_os.h"
#include "FreeRTOS.h"

#include "main.h"

// Thread-safe printf implementation
// using semaphore

#define USE_SEMAPHORE
SemaphoreHandle_t printfSem = NULL;
SemaphoreHandle_t sprintfSem = NULL;



void _putchar(char ch){
    while(!(UART_PRINTF->SR & USART_SR_TXE));
    UART_PRINTF->DR = ch;
    //while(!(UART->SR & USART_SR_TXE));
    while(!(UART_PRINTF->SR & USART_SR_TC));
    UART_PRINTF->SR |= USART_SR_TC;
    //return ch;
}


void ITMPrint_init(void){
    // Create the mutex during initialization
    printfSem = xSemaphoreCreateMutex();
    sprintfSem = xSemaphoreCreateMutex();
    if (printfSem == NULL) {
        Error_Handler();
    }
    if (sprintfSem == NULL) {
        Error_Handler();
    }
}



int tsprintf(const char *format, ...) {
    if (xSemaphoreTake(printfSem, portMAX_DELAY) == pdTRUE) {
        int result;
        va_list args;
        // Take the mutex to protect the critical section
        va_start(args, format);
        result = vprintf(format, args);
        //fflush(stdout);
        va_end(args);
        // Release the mutex
        xSemaphoreGive(printfSem);
        return result;
    } 
    else{
        // Failed to take the mutex, handle the error here
        //xSemaphoreGive(printfSem);
        Error_Handler();
        return -1;
    }
}

int stdin_getchar (void){
    return 0;
}

int tssprintf(char* out, const char *format, ...){
    if (xSemaphoreTake(sprintfSem, portMAX_DELAY) == pdTRUE) {
        int result;
        va_list args;
        // Take the mutex to protect the critical section
        va_start(args, format);
        result = vsnprintf(out, 0xfff, format, args);
        va_end(args);
        // Release the mutex
        xSemaphoreGive(sprintfSem);
        return result;
    } 
    else{
        // Failed to take the mutex, handle the error here
        //xSemaphoreGive(printfSem);
        Error_Handler();
        return -1;
    }
}
