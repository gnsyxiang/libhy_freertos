/**
 * 
 * Release under GPLv-3.0.
 * 
 * @file    hy_template_demo.c
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    08/08 2024 15:22
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        08/08 2024      create the file
 * 
 *     last modified: 08/08 2024 15:22
 */
#include <stdio.h>
#include <string.h>

#include <hy_os_type/hy_type.h>

#include "FreeRTOS.h"
#include "task.h"

#define __FILENAME__ (strrchr(__FILE__, '/') ? (strrchr(__FILE__, '/') + 1):__FILE__)
#define os_printf(_fmt_, ...) printf("[log ] %s:%d | "_fmt_"\r\n", __FILENAME__, __LINE__, ##__VA_ARGS__)

static TaskHandle_t xTask_creat = NULL;

static void creat_task(void *p)
{
    os_printf("%s", __FUNCTION__);

    hy_s32_t cnt = 0;

    taskENTER_CRITICAL();
    taskEXIT_CRITICAL();

    while (1) {
        os_printf("this is creat task:idle-%d", cnt++);
        vTaskDelay(1000);

        if (cnt >= 10) {
            break;
        }
    }

    os_printf("delete creat task");

    vTaskDelete(xTask_creat);
}

int main(void)
{
    BaseType_t ret = pdPASS;

    os_printf("Freertos v10.2.1 start ");

    ret = xTaskCreate((TaskFunction_t )creat_task,
                      (const char *   )"creat_task",
                      (unsigned short )128,
                      (void *         )NULL,
                      (UBaseType_t    )1,
                      (TaskHandle_t * )&xTask_creat);
    if (pdPASS != ret) {
        return -1;
    }

    vTaskStartScheduler();

    while (1) {
    }

    return 0;
}
