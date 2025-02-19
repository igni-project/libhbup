/* hbup_preproc.h
 * Compiler agnostic C pre-processor macros */

#ifndef _LIBHBUP_HBUP_PREPROC_H
#define _LIBHBUP_HBUP_PREPROC_H 1

/* PACK__ & __PACK */
#ifdef __GNUC__
#define __PACK __attribute__((__packed__))
#define PACK__
#elif defined _MSC_VER
#define __PACK __pragma( pack(push, 1)
#define PACK__ __pragma( pack(pop))
#endif

#endif


