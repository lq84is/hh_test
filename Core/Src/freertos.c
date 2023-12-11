/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId TFT_taskHandle;
uint32_t TFT_taskBuffer[ 1024 ];
osStaticThreadDef_t TFT_taskControlBlock;
osThreadId SensorsHandle;
uint32_t SensorsBuffer[ 256 ];
osStaticThreadDef_t SensorsControlBlock;
osThreadId Remout_taskHandle;
uint32_t Remout_taskBuffer[ 128 ];
osStaticThreadDef_t Remout_taskControlBlock;
osThreadId NVMDataWatcherHandle;
uint32_t NVMDataWatcherBuffer[ 128 ];
osStaticThreadDef_t NVMDataWatcherControlBlock;
osThreadId BoilerControlHandle;
uint32_t BoilerControl_tBuffer[ 256 ];
osStaticThreadDef_t BoilerControl_tControlBlock;
osThreadId ResourceCounterHandle;
uint32_t ResourceCounterBuffer[ 128 ];
osStaticThreadDef_t ResourceCounterControlBlock;
osThreadId BKPDataWatcherHandle;
uint32_t BKPDataWatcherBuffer[ 128 ];
osStaticThreadDef_t BKPDataWatcherControlBlock;
osMessageQId EncoderAddSubHandle;
uint8_t EncoderAddSubBuffer[ 16 * sizeof( int8_t ) ];
osStaticMessageQDef_t EncoderAddSubControlBlock;
osMutexId BKPRegMutexHandle;
osStaticMutexDef_t BKPRegMutexControlBlock;
osSemaphoreId NVMSaveHandle;
osStaticSemaphoreDef_t NVMSaveControlBlock;
osSemaphoreId BKPSaveHandle;
osStaticSemaphoreDef_t BKPSaveControlBlock;
osSemaphoreId BoilerAlgoRunningToggleHandle;
osStaticSemaphoreDef_t BoilerAlgoRunningToggleControlBlock;
osSemaphoreId PumpAlgoToggleHandle;
osStaticSemaphoreDef_t PumpAlgoToggleControlBlock;
osSemaphoreId initFlashParamDefaultCompleteHandle;
osStaticSemaphoreDef_t initFlashParamDefaultCompleteControlBlock;
osSemaphoreId initFlashParamStorageCompleteHandle;
osStaticSemaphoreDef_t initFlashParamStorageCompleteControlBlock;
osSemaphoreId parameterSavedHandle;
osStaticSemaphoreDef_t parameterSavedControlBlock;
osSemaphoreId initBkpParamDefaultCompleteHandle;
osStaticSemaphoreDef_t initBkpParamDefaultCompleteControlBlock;
osSemaphoreId initBkpParamStorageCompleteHandle;
osStaticSemaphoreDef_t initBkpParamStorageCompleteControlBlock;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void StartTFT(void const * argument);
void StartSensors(void const * argument);
void StartRemout(void const * argument);
void StartNVMDataWatcher(void const * argument);
void StartBoilerControl_task(void const * argument);
void StartResourceCounter_Task(void const * argument);
void StartBKPDataWatcher(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* Hook prototypes */
void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName);

/* USER CODE BEGIN 4 */
__weak void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName)
{
   /* Run time stack overflow checking is performed if
   configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2. This hook function is
   called if a stack overflow is detected. */
}
/* USER CODE END 4 */

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */
  /* Create the mutex(es) */
  /* definition and creation of BKPRegMutex */
  osMutexStaticDef(BKPRegMutex, &BKPRegMutexControlBlock);
  BKPRegMutexHandle = osMutexCreate(osMutex(BKPRegMutex));

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* definition and creation of NVMSave */
  osSemaphoreStaticDef(NVMSave, &NVMSaveControlBlock);
  NVMSaveHandle = osSemaphoreCreate(osSemaphore(NVMSave), 1);

  /* definition and creation of BKPSave */
  osSemaphoreStaticDef(BKPSave, &BKPSaveControlBlock);
  BKPSaveHandle = osSemaphoreCreate(osSemaphore(BKPSave), 1);

  /* definition and creation of BoilerAlgoRunningToggle */
  osSemaphoreStaticDef(BoilerAlgoRunningToggle, &BoilerAlgoRunningToggleControlBlock);
  BoilerAlgoRunningToggleHandle = osSemaphoreCreate(osSemaphore(BoilerAlgoRunningToggle), 1);

  /* definition and creation of PumpAlgoToggle */
  osSemaphoreStaticDef(PumpAlgoToggle, &PumpAlgoToggleControlBlock);
  PumpAlgoToggleHandle = osSemaphoreCreate(osSemaphore(PumpAlgoToggle), 1);

  /* definition and creation of initFlashParamDefaultComplete */
  osSemaphoreStaticDef(initFlashParamDefaultComplete, &initFlashParamDefaultCompleteControlBlock);
  initFlashParamDefaultCompleteHandle = osSemaphoreCreate(osSemaphore(initFlashParamDefaultComplete), 4);

  /* definition and creation of initFlashParamStorageComplete */
  osSemaphoreStaticDef(initFlashParamStorageComplete, &initFlashParamStorageCompleteControlBlock);
  initFlashParamStorageCompleteHandle = osSemaphoreCreate(osSemaphore(initFlashParamStorageComplete), 3);

  /* definition and creation of parameterSaved */
  osSemaphoreStaticDef(parameterSaved, &parameterSavedControlBlock);
  parameterSavedHandle = osSemaphoreCreate(osSemaphore(parameterSaved), 2);

  /* definition and creation of initBkpParamDefaultComplete */
  osSemaphoreStaticDef(initBkpParamDefaultComplete, &initBkpParamDefaultCompleteControlBlock);
  initBkpParamDefaultCompleteHandle = osSemaphoreCreate(osSemaphore(initBkpParamDefaultComplete), 3);

  /* definition and creation of initBkpParamStorageComplete */
  osSemaphoreStaticDef(initBkpParamStorageComplete, &initBkpParamStorageCompleteControlBlock);
  initBkpParamStorageCompleteHandle = osSemaphoreCreate(osSemaphore(initBkpParamStorageComplete), 3);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* definition and creation of EncoderAddSub */
  osMessageQStaticDef(EncoderAddSub, 16, int8_t, EncoderAddSubBuffer, &EncoderAddSubControlBlock);
  EncoderAddSubHandle = osMessageCreate(osMessageQ(EncoderAddSub), NULL);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of TFT_task */
  osThreadStaticDef(TFT_task, StartTFT, osPriorityIdle, 0, 1024, TFT_taskBuffer, &TFT_taskControlBlock);
  TFT_taskHandle = osThreadCreate(osThread(TFT_task), NULL);

  /* definition and creation of Sensors */
  osThreadStaticDef(Sensors, StartSensors, osPriorityIdle, 0, 256, SensorsBuffer, &SensorsControlBlock);
  SensorsHandle = osThreadCreate(osThread(Sensors), NULL);

  /* definition and creation of Remout_task */
  osThreadStaticDef(Remout_task, StartRemout, osPriorityIdle, 0, 128, Remout_taskBuffer, &Remout_taskControlBlock);
  Remout_taskHandle = osThreadCreate(osThread(Remout_task), NULL);

  /* definition and creation of NVMDataWatcher */
  osThreadStaticDef(NVMDataWatcher, StartNVMDataWatcher, osPriorityIdle, 0, 128, NVMDataWatcherBuffer, &NVMDataWatcherControlBlock);
  NVMDataWatcherHandle = osThreadCreate(osThread(NVMDataWatcher), NULL);

  /* definition and creation of BoilerControl */
  osThreadStaticDef(BoilerControl, StartBoilerControl_task, osPriorityNormal, 0, 256, BoilerControl_tBuffer, &BoilerControl_tControlBlock);
  BoilerControlHandle = osThreadCreate(osThread(BoilerControl), NULL);

  /* definition and creation of ResourceCounter */
  osThreadStaticDef(ResourceCounter, StartResourceCounter_Task, osPriorityIdle, 0, 128, ResourceCounterBuffer, &ResourceCounterControlBlock);
  ResourceCounterHandle = osThreadCreate(osThread(ResourceCounter), NULL);

  /* definition and creation of BKPDataWatcher */
  osThreadStaticDef(BKPDataWatcher, StartBKPDataWatcher, osPriorityIdle, 0, 128, BKPDataWatcherBuffer, &BKPDataWatcherControlBlock);
  BKPDataWatcherHandle = osThreadCreate(osThread(BKPDataWatcher), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartTFT */
/**
* @brief Function implementing the TFT_task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTFT */
__weak void StartTFT(void const * argument)
{
  /* USER CODE BEGIN StartTFT */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTFT */
}

/* USER CODE BEGIN Header_StartSensors */
/**
* @brief Function implementing the Sensors thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartSensors */
__weak void StartSensors(void const * argument)
{
  /* USER CODE BEGIN StartSensors */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartSensors */
}

/* USER CODE BEGIN Header_StartRemout */
/**
* @brief Function implementing the Remout_task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartRemout */
__weak void StartRemout(void const * argument)
{
  /* USER CODE BEGIN StartRemout */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartRemout */
}

/* USER CODE BEGIN Header_StartNVMDataWatcher */
/**
* @brief Function implementing the NVMDataWatcher thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartNVMDataWatcher */
__weak void StartNVMDataWatcher(void const * argument)
{
  /* USER CODE BEGIN StartNVMDataWatcher */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartNVMDataWatcher */
}

/* USER CODE BEGIN Header_StartBoilerControl_task */
/**
* @brief Function implementing the BoilerControl thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartBoilerControl_task */
__weak void StartBoilerControl_task(void const * argument)
{
  /* USER CODE BEGIN StartBoilerControl_task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartBoilerControl_task */
}

/* USER CODE BEGIN Header_StartResourceCounter_Task */
/**
* @brief Function implementing the ResourceCounter thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartResourceCounter_Task */
__weak void StartResourceCounter_Task(void const * argument)
{
  /* USER CODE BEGIN StartResourceCounter_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartResourceCounter_Task */
}

/* USER CODE BEGIN Header_StartBKPDataWatcher */
/**
* @brief Function implementing the BKPDataWatcher thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartBKPDataWatcher */
__weak void StartBKPDataWatcher(void const * argument)
{
  /* USER CODE BEGIN StartBKPDataWatcher */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartBKPDataWatcher */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

