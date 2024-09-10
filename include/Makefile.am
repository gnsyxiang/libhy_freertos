# ===============================================================
# 
# Release under GPLv-3.0.
# 
# @file    Makefile.am
# @brief   
# @author  gnsyxiang <gnsyxiang@163.com>
# @date    09/08 2024 09:06
# @version v0.0.1
# 
# @since    note
# @note     note
# 
#     change log:
#     NO.     Author              Date            Modified
#     00      zhenquan.qiu        09/08 2024      create the file
# 
#     last modified: 09/08 2024 09:06
# ===============================================================

# ------------------
# defining variables
# ------------------
_no_install_headers_com =
_install_headers_com    =

install_includedir      = $(includedir)/$(project_name)

# ---------------------
# add necessary content
# ---------------------
_no_install_headers_com +=

_install_headers_com    += \
                           FreeRTOS.h \
                           StackMacros.h \
                           atomic.h \
                           croutine.h \
                           deprecated_definitions.h \
                           event_groups.h \
                           list.h \
                           message_buffer.h \
                           mpu_prototypes.h \
                           mpu_wrappers.h \
                           portable.h \
                           projdefs.h \
                           queue.h \
                           semphr.h \
                           stack_macros.h \
                           stream_buffer.h \
                           task.h \
                           timers.h \
                           \
                           hy_freertos.h

# ------------------
# make install files
# ------------------
noinst_HEADERS          = $(_no_install_headers_com)
install_include_HEADERS = $(_install_headers_com)
