# ===============================================================
# 
# Release under GPLv-3.0.
# 
# @file    Makefile.am
# @brief   
# @author  gnsyxiang <gnsyxiang@163.com>
# @date    08/08 2024 14:36
# @version v0.0.1
# 
# @since    note
# @note     note
# 
#     change log:
#     NO.     Author              Date            Modified
#     00      zhenquan.qiu        08/08 2024      create the file
# 
#     last modified: 08/08 2024 14:36
# ===============================================================

noinst_LTLIBRARIES = lib@project_name@_mem_mang.la

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

_include_com    += -I$(top_srcdir)/include
_include_com    += -I$(top_srcdir)/src/portable/GCC/Posix

_sources_com    += \
                   heap_3.c

_cppflags_com   += \
                   $(_no_error_com) \
                   $(_include_com) \
                   $(_define_com)

_cflags_com     +=

_cxxflags_com   +=

_ldadd_com      += $(ldadd_com)

lib@project_name@_mem_mang_la_SOURCES  = $(_sources_com)
lib@project_name@_mem_mang_la_CPPFLAGS = $(_cppflags_com)
lib@project_name@_mem_mang_la_CFLAGS   = $(_cflags_com)
lib@project_name@_mem_mang_la_CXXFLAGS = $(_cxxflags_com)
lib@project_name@_mem_mang_la_LDFLAGS  = $(_ldflags_com)
lib@project_name@_mem_mang_la_LIBADD   = $(_ldadd_com)
