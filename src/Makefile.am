# ===============================================================
# 
# Release under GPLv-3.0.
# 
# @file    Makefile.am
# @brief   
# @author  gnsyxiang <gnsyxiang@163.com>
# @date    06/05 2024 09:41
# @version v0.0.1
# 
# @since    note
# @note     note
# 
#     change log:
#     NO.     Author              Date            Modified 00      zhenquan.qiu        06/05 2024      create the file
#     last modified: 06/05 2024 09:41
# ===============================================================

SUBDIRS = portable

lib_LTLIBRARIES = lib@project_name@.la

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

_include_com    += \
                   -I$(top_srcdir)/include \
                   -I$(top_srcdir)/src/portable/GCC/$(porting_platform)

_sources_com    += \
                   croutine.c \
                   event_groups.c \
                   list.c \
                   queue.c \
                   stream_buffer.c \
                   tasks.c \
                   timers.c

_cppflags_com   += \
                   $(_no_error_com) \
                   $(_include_com) \
                   $(_define_com)

_cflags_com     +=

_cxxflags_com   +=

_ldflags_com    += -version-info @current@:@revision@:@age@

_ldadd_com      += $(ldadd_com)

_ldadd_com      += \
                   $(top_builddir)/src/portable/GCC/$(porting_platform)/libfreertos_portable_gcc_@porting_platform@.la \
                   $(top_builddir)/src/portable/MemMang/libfreertos_portable_mem.la

lib@project_name@_la_SOURCES    = $(_sources_com)
lib@project_name@_la_CPPFLAGS   = $(_cppflags_com)
lib@project_name@_la_CFLAGS     = $(_cflags_com)
lib@project_name@_la_CXXFLAGS   = $(_cxxflags_com)
lib@project_name@_la_LDFLAGS    = $(_ldflags_com)
lib@project_name@_la_LIBADD     = $(_ldadd_com)
