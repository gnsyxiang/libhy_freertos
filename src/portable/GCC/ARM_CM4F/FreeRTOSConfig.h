/* USER CODE BEGIN Header */
/*
 * FreeRTOS Kernel V10.3.1
 * Portion Copyright (C) 2017 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 * Portion Copyright (C) 2019 StMicroelectronics, Inc.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */
/* USER CODE END Header */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * These parameters and more are described within the 'configuration' section of the
 * FreeRTOS API documentation available on the FreeRTOS.org web site.
 *
 * See http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/

/*
 * @brief 头文件定义，方便移植
 */
#ifndef CMSIS_device_header
#define CMSIS_device_header <hy_hal_mcu/stm32h7xx.h>
#endif

#define configENABLE_FPU                            0
#define configENABLE_MPU                            0

/*
 * @brief 系统节拍时钟
 *
 * @note 宏定义判断是确保定义仅被编译器使用，而不被汇编器使用
 */
#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
  #include <stdint.h>
  extern uint32_t SystemCoreClock;
#endif
#define configCPU_CLOCK_HZ                          (SystemCoreClock)       ///< 
#define configTICK_RATE_HZ                          ((TickType_t)1000)      ///< 滴答定时器定义为1ms
#define configUSE_TICK_HOOK                         0                       ///< 是否开启滴答定时器钩子函数
#define configUSE_16_BIT_TICKS                      0                       ///< 是否使用16bit作为滴答定时器的计数位数，开启后可以减少内存的使用，但是在65.5秒回回绕
#define USE_CUSTOM_SYSTICK_HANDLER_IMPLEMENTATION   0                       ///< 是否使用自定义的中断处理函数

/*
 * @brief 系统相关
 */
#define configMESSAGE_BUFFER_LENGTH_TYPE            size_t                  ///< 设置消息缓冲区长度类型，
                                                                            ///< size_t 是一个无符号整数类型，适合表示内存大小，并且与平台的字长相关，通常可以更好地处理不同平台的内存需求。
#define vPortSVCHandler                             SVC_Handler             ///< 处理系统服务调用（SVC）异常
#define xPortPendSVHandler                          PendSV_Handler          ///< 处理挂起的系统服务请求（PendSV）异常

/*
 * @brief 堆栈相关
 */
#define configTOTAL_HEAP_SIZE                       ((size_t)15360)         ///< 用于动态内存分配的总堆大小

/*
 * @brief 任务相关
 */
#define configSUPPORT_STATIC_ALLOCATION             1                       ///< 开启静态分配任务，开启时空闲任务和软件定时器任务优先使用静态创建
#define configSUPPORT_DYNAMIC_ALLOCATION            1                       ///< 开启动态分配任务
#define configMAX_TASK_NAME_LEN                     (16)                    ///< 任务名字最长长度
#define configUSE_PREEMPTION                        1                       ///< 打开任务抢占功能
#define configMAX_PRIORITIES                        (32)                    ///< 最大任务优先级
#define configUSE_PORT_OPTIMISED_TASK_SELECTION     1                       ///< 打开硬件计算前导零指令，最大支持32位的数，即configMAX_PRIORITIES 的值不能超过 32，支持的级越多，消耗的资源也越多
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS     10                      ///< 任务本地储存功能

/*
 * @brief 协程
 */
#define configUSE_CO_ROUTINES                       0                       ///< 不开启协程
#define configMAX_CO_ROUTINE_PRIORITIES             (2)                     ///< 协程最大优先级

/*
 * @brief 空闲任务
 */
#define configUSE_IDLE_HOOK                         0                       ///< 是否开启空闲任务的钩子函数
#define configMINIMAL_STACK_SIZE                    ((uint16_t)128)         ///< 空闲任务的栈大小

/*
 * @brief 软件定时器任务
 */
#define configUSE_TIMERS                            1                       ///< 启用软件定时器
#define configTIMER_TASK_PRIORITY                   (2)                     ///< 软件定时器任务优先级
#define configTIMER_QUEUE_LENGTH                    10                      ///< 定时器队列的长度，最大容纳的回调函数个数
#define configTIMER_TASK_STACK_DEPTH                256                     ///< 栈深度
#define INCLUDE_xTimerPendFunctionCall              1                       ///< 

/*
 * @brief 互斥量，保护临界区或共享资源
 */
#define configUSE_MUTEXES                           1                       ///< 一般情况下启用，有助于提高系统的稳定性和可靠性，尤其是在需要复杂资源访问控制的应用场景中
#define configUSE_RECURSIVE_MUTEXES                 1                       ///< 递归互斥量

/*
 * @brief 计数信号量
 */
#define configUSE_COUNTING_SEMAPHORES               1                       ///< 计数信号量是一种同步机制，可以用于限制访问共享资源的任务数量或实现任务间的通知。

/*
 * @brief 调试监控
 */
#define configUSE_TRACE_FACILITY                    1                       ///< 启用跟踪功能
#define configUSE_STATS_FORMATTING_FUNCTIONS        1
#define configQUEUE_REGISTRY_SIZE                   8                       ///< 队列注册表的大小，通过队列注册表可以方便地监控和诊断系统中的队列
#define configASSERT( x ) if ((x) == 0) {taskDISABLE_INTERRUPTS(); for( ;; );}

/* Set the following definitions to 1 to include the API function, or zero to exclude the API function. */
#define INCLUDE_vTaskPrioritySet             1
#define INCLUDE_uxTaskPriorityGet            1
#define INCLUDE_vTaskDelete                  1
#define INCLUDE_vTaskCleanUpResources        0
#define INCLUDE_vTaskSuspend                 1
#define INCLUDE_vTaskDelayUntil              1
#define INCLUDE_vTaskDelay                   1
#define INCLUDE_xTaskGetSchedulerState       1
#define INCLUDE_xQueueGetMutexHolder         1
#define INCLUDE_uxTaskGetStackHighWaterMark  1
#define INCLUDE_xTaskGetCurrentTaskHandle    1
#define INCLUDE_eTaskGetState                1

/* Cortex-M specific definitions. */
#ifdef __NVIC_PRIO_BITS
 /* __BVIC_PRIO_BITS will be specified when CMSIS is being used. */
 #define configPRIO_BITS         __NVIC_PRIO_BITS
#else
 #define configPRIO_BITS         4
#endif

/* The lowest interrupt priority that can be used in a call to a "set priority" function. */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY   15

/* The highest interrupt priority that can be used by any interrupt service
routine that makes calls to interrupt safe FreeRTOS API functions.  DO NOT CALL
INTERRUPT SAFE FREERTOS API FUNCTIONS FROM ANY INTERRUPT THAT HAS A HIGHER
PRIORITY THAN THIS! (higher priorities are lower numeric values. */
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY 5

/* Interrupt priorities used by the kernel port layer itself.  These are generic
to all Cortex-M ports, and do not rely on any particular library functions. */
#define configKERNEL_INTERRUPT_PRIORITY 		( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

/* !!!! configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!
See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

#endif /* FREERTOS_CONFIG_H */
