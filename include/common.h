/**
 * Author......: See docs/credits.txt
 * License.....: MIT
 */

#ifndef _COMMON_H
#define _COMMON_H

#define PROGNAME "hashcat"

#if defined (__unix__) || defined (__APPLE__)
#define _POSIX
#elif defined (__WINNT__)
#define _WIN 1
#else
#error Your Operating System is not supported or detected
#endif

#if defined (__BYTE_ORDER__) && defined (__ORDER_BIG_ENDIAN__)
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#error "compiling for big-endian architecture not supported"
#endif
#endif

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

// needed for *time_r functions under MinGW
#ifndef _POSIX_THREAD_SAFE_FUNCTIONS
#define _POSIX_THREAD_SAFE_FUNCTIONS 200809L
#endif

// needed for 64-bit off_t on 32-bit OSes
#ifndef _FILE_OFFSET_BITS
#define _FILE_OFFSET_BITS 64
#endif

#ifndef _FORTIFY_SOURCE
#define _FORTIFY_SOURCE 2
#endif

#define NOMINMAX 1

#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

#define CEIL(a) ((a - (int) (a)) > 0 ? a + 1 : a)
#define CEILDIV(a,b) (((a) + (b) - 1) / (b))

#if defined (__APPLE__)
#define __stdcall
#endif

#if defined (__MSC_VER)
#define HC_API_CALL __cdecl
#elif defined (_WIN32) || defined (__WIN32__)
#define HC_API_CALL __stdcall
#else
#define HC_API_CALL
#endif

#if defined (_WIN)
#define WIN32_LEAN_AND_MEAN
#endif

/* The C++ standard denies redefinition of keywords,
but this is nededed for VS compiler which doesn't have inline keyword but has __inline
*/
#ifndef __cplusplus
#if defined (_MSC_VER)
#define inline __inline
#endif
#endif

#define MAYBE_UNUSED __attribute__((unused))

/*
 * Check if the system uses nanoseconds for file timestamps.
 * In case the system uses nanoseconds we set some custom macros here,
 * e.g. the (nanosecond) access time macros for dictstat
 */

#if defined (__linux__)
#include <linux/version.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,5,48)
#define STAT_NANOSECONDS_ACCESS_TIME st_atim.tv_nsec
#endif
#endif

#if defined (__APPLE__)
#define STAT_NANOSECONDS_ACCESS_TIME st_atimespec.tv_nsec
#endif

// config section
// do not try to simply change this, it will not work

#define PW_MIN              0
#define PW_MAX              256
#define PW_MAX_OLD          55

#define SALT_MIN            0
#define SALT_MAX            256
#define SALT_MAX_OLD        51

#define HCBUFSIZ_TINY       0x1000
#define HCBUFSIZ_LARGE      0x50000

#define CPT_CACHE           0x20000
#define PARAMCNT            64
#define DEVICES_MAX         128
#define EXEC_CACHE          128
#define SPEED_CACHE         128
#define SPEED_MAXAGE        4096
#define EXPECTED_ITERATIONS 10000

#if defined (_WIN)
#define EOL "\r\n"
#else
#define EOL "\n"
#endif

#endif // _COMMON_H
