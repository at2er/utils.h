/* Public domain
 *
 * @important: developing and very unstable.
 *
 * Just a dynamic array. */
#ifndef UTILSH_DARR_H
#define UTILSH_DARR_H
#include <stdlib.h>

struct utilsh_darr_header_t {
	int cap, len;
};

#define utilsh_darr(T, NAME) T* NAME = NULL
#define utilsh_darr_foreach(INDEX, DARR) for (int INDEX = 0; INDEX < utilsh_darr_header(DARR)->len; INDEX++)
#define utilsh_darr_header(DARR) (((struct utilsh_darr_header_t*)(DARR)) - 1)
#define utilsh_darr_push(DARR, V) \
	do { \
		if ((DARR) == NULL) { \
			(DARR) = malloc(sizeof(*(DARR)) + sizeof(struct utilsh_darr_header_t)); \
			((struct utilsh_darr_header_t*)(DARR))->cap = 1; \
			((struct utilsh_darr_header_t*)(DARR))->len = 0; \
			(DARR) = (void*)(((struct utilsh_darr_header_t*)(DARR)) + 1); \
		} else if (utilsh_darr_header(DARR)->len >= utilsh_darr_header(DARR)->cap) { \
			utilsh_darr_header(DARR)->cap *= 2; \
			(DARR) = realloc(utilsh_darr_header(DARR), \
					sizeof(*(DARR)) * utilsh_darr_header(DARR)->cap \
					+ sizeof(struct utilsh_darr_header_t)); \
			(DARR) = (void*)(((struct utilsh_darr_header_t*)(DARR)) + 1); \
		} \
		(DARR)[utilsh_darr_header(DARR)->len++] = (V); \
	} while (0)

#ifdef UTILSH_DARR_STRIP
#define darr utilsh_darr
#define darr_foreach utilsh_darr_foreach
#define darr_header_t utilsh_darr_header_t
#define darr_push utilsh_darr_push
#endif

#endif
