# ===============================================================
# 
# Release under GPLv-3.0.
# 
# @file    Makefile.am
# @brief   
# @author  gnsyxiang <gnsyxiang@163.com>
# @date    06/05 2024 11:17
# @version v0.0.1
# 
# @since    note
# @note     note
# 
#     change log:
#     NO.     Author              Date            Modified
#     00      zhenquan.qiu        06/05 2024      create the file
# 
#     last modified: 06/05 2024 11:17
# ===============================================================

noinst_LTLIBRARIES = libfreertos_portable_mem.la

# ------------------
# defining variables
# ------------------
_no_error_com   =
_define_com     =
_include_com    = $(include_com)
_sources_com    =
_cppflags_com   =
_cflags_com     =
_cxxflags_com   =
_ldflags_com    =
_ldadd_com      =

# ---------------------
# add necessary content
# ---------------------
_no_error_com   +=

_define_com     +=

if COMPILE_SELECT_CHIP_STM32H7XX
_include_com    += \
                   -I$(top_srcdir)/include \
                   -I$(top_srcdir)/src/portable/GCC/$(porting_platform)
_sources_com    += heap_4.c
endif

_cppflags_com   += \
                   $(_no_error_com) \
                   $(_include_com) \
                   $(_define_com)

_cflags_com     +=

_cxxflags_com   +=

_ldadd_com      += $(ldadd_com)

libfreertos_portable_mem_la_SOURCES     = $(_sources_com)
libfreertos_portable_mem_la_CPPFLAGS    = $(_cppflags_com)
libfreertos_portable_mem_la_CFLAGS      = $(_cflags_com)
libfreertos_portable_mem_la_CXXFLAGS    = $(_cxxflags_com)
libfreertos_portable_mem_la_LDFLAGS     = $(_ldflags_com)
libfreertos_portable_mem_la_LIBADD      = $(_ldadd_com)
