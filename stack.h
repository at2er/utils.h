/* Public domain
 *
 * Just a stack. */
#ifndef UTILSH_STACK_H
#define UTILSH_STACK_H
#include <stddef.h>

#ifndef utilsh_stack_calloc
#define utilsh_stack_calloc calloc
#include <stdlib.h>
#endif

#ifndef utilsh_stack_realloc
#define utilsh_stack_realloc realloc
#include <stdlib.h>
#endif

#ifndef utilsh_stack_siz_t
#define utilsh_stack_siz_t int
#endif

#define utilsh_stack(T) \
	struct { \
		T *top; \
		T *base; \
		utilsh_stack_siz_t siz; \
	}

#define utilsh_stack_init(STACK, SIZ) \
	do { \
		(STACK)->siz = (SIZ); \
		(STACK)->base = utilsh_stack_calloc(\
				(STACK)->siz,\
				sizeof(*(STACK)->base)); \
		(STACK)->top = NULL; \
	} while (0)

#define utilsh_stack_resize(STACK, SIZ) \
	do { \
		utilsh_stack_siz_t orig_off = (STACK)->top == NULL \
				? 0 : (STACK)->top - (STACK)->base; \
		(STACK)->siz = (SIZ); \
		(STACK)->base = utilsh_stack_realloc( \
				(STACK)->base, \
				(STACK)->siz * sizeof(*(STACK)->base)); \
		if (orig_off >= (STACK)->siz) \
			(STACK)->top = (STACK)->base + (STACK)->siz - 1; \
		else \
			(STACK)->top = (STACK)->base + orig_off; \
	} while (0)

#define utilsh_stack_push(STACK, ELEM) \
	if ((STACK)->top) { \
		(STACK)->top++; \
		*(STACK)->top = (ELEM); \
	} else { \
		(STACK)->top = (STACK)->base; \
		*(STACK)->top = (ELEM); \
	}

#define utilsh_stack_pop(STACK) \
	((STACK)->top == (STACK)->base \
	 ? ((STACK)->top = NULL, *(STACK)->base) \
	 : ((STACK)->top == NULL ? 0 : ((STACK)->top--, (STACK)->top[1])))

#ifdef UTILSH_STACK_STRIP
#define stack utilsh_stack
#endif

#endif
