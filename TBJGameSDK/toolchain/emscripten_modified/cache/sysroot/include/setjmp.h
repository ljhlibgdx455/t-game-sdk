#ifndef	_SETJMP_H
#define	_SETJMP_H

#if !defined(__JENOVA_DEFINED_pthread_t) && !defined(JENOVA_SDK)

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#include <bits/setjmp.h>

typedef struct __jmp_buf_tag {
	__jmp_buf __jb;
	unsigned long __fl;
	unsigned long __ss[128/sizeof(long)];
} jmp_buf[1];

#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)
typedef jmp_buf sigjmp_buf;
/* XXX EMSCRIPTEN: No signals support, alias sigsetjmp and siglongjmp to their non-signals counterparts. */
#if __EMSCRIPTEN__
#define sigsetjmp(buf, x) setjmp((buf))
#define siglongjmp(buf, val) longjmp(buf, val)
#else
int sigsetjmp (sigjmp_buf, int);
_Noreturn int siglongjmp (sigjmp_buf, int);
#endif
#endif

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
 || defined(_BSD_SOURCE)
int _setjmp (jmp_buf);
_Noreturn void _longjmp (jmp_buf, int);
#endif

int setjmp (jmp_buf);
_Noreturn void longjmp (jmp_buf, int);

#define setjmp setjmp

#ifdef __cplusplus
}
#endif





#else



#ifdef __cplusplus
extern "C" {
#endif

#include <bits/setjmp.h>

typedef int jmp_buf[74];

int _setjmp_native(jmp_buf buf);
void _longjump_native(jmp_buf buf, int val);

#define sigsetjmp _setjmp_native
#define setjmp _setjmp_native
#define longjmp _longjump_native
#define siglongjmp _longjump_native

#ifdef __cplusplus
}
#endif

#endif

#endif
