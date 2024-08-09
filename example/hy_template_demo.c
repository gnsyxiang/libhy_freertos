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

#define _TASK_CNT   (4)

typedef struct {
    TaskHandle_t    task_h;
    char            name[16];
} _task_s;

static _task_s task_h[_TASK_CNT];

static void _task_loop_cb(void *args)
{
    hy_s32_t cnt = 0;
    _task_s *task = (_task_s *)args;

    while (1) {
        os_printf("this is %s, idle-%d", task->name, cnt++);

        vTaskDelay(1000);

        if (cnt >= 5) {
            break;
        }
    }

    os_printf("delete %s", task->name);

    vTaskDelete(task->task_h);
}

int main(void)
{
    BaseType_t ret = pdPASS;

    os_printf("Freertos v10.2.1 start ");

    taskENTER_CRITICAL();
    taskEXIT_CRITICAL();

    for (hy_s32_t i = 0; i < _TASK_CNT; i++) {
        _task_s *task = &task_h[i];
        memset(task, 0, sizeof(*task));
        snprintf(task->name, sizeof(task->name), "task%d", i);

        ret = xTaskCreate(_task_loop_cb, task->name, 128, task, 1, &task->task_h);
        if (pdPASS != ret) {
            return -1;
        }
    }

    vTaskStartScheduler();

    os_printf("-1-here");
    while (1) {
        os_printf("-2-here");
    }
    os_printf("-3-here");

    return 0;
}
