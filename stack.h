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
		T *base; \
		utilsh_stack_siz_t siz; \
		/* not top, it's the top next */ \
		utilsh_stack_siz_t topn; \
	}

#define utilsh_stack_init(STACK, SIZ) \
	do { \
		(STACK)->siz = (SIZ); \
		(STACK)->base = utilsh_stack_calloc(\
				(STACK)->siz,\
				sizeof(*(STACK)->base)); \
		(STACK)->topn = (utilsh_stack_siz_t)0; \
	} while (0)

#define utilsh_stack_pop(STACK) \
	((STACK)->base \
	 ? ((STACK)->topn == 0 \
		 ? 0 \
		 : ((STACK)->topn--, (STACK)->base[(STACK)->topn])) \
	 : 0)

#define utilsh_stack_push(STACK, ELEM) \
	do { \
		(STACK)->base[(STACK)->topn] = (ELEM); \
		(STACK)->topn++; \
	} while (0)

#define utilsh_stack_resize(STACK, SIZ) \
	do { \
		(STACK)->siz = (SIZ); \
		(STACK)->base = utilsh_stack_realloc( \
				(STACK)->base, \
				(STACK)->siz * sizeof(*(STACK)->base)); \
		if ((STACK)->topn >= (STACK)->siz) \
			(STACK)->topn = (STACK)->siz; \
	} while (0)

#define utilsh_stack_top(STACK) \
	((STACK)->topn == 0 ? 0 : (STACK)->base[(STACK)->topn - 1])

#ifdef UTILSH_STACK_STRIP
#define stack        utilsh_stack
#define stack_init   utilsh_stack_init
#define stack_pop    utilsh_stack_pop
#define stack_push   utilsh_stack_push
#define stack_resize utilsh_stack_resize
#define stack_top    utilsh_stack_top
#endif

#endif
