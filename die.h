/* Public domain
 *
 * Just a implmentation of 'die' function.
 *
 * Usage:
 *     void die(const char *fmt, ...);
 *         Just like 'printf' but it will call 'exit(1)' to end your program.
 */
#ifndef UTILSH_DIE_H
#define UTILSH_DIE_H

extern void die(const char *fmt, ...);

#endif

#ifdef UTILSH_DIE_IMPL
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void
die(const char *msg, ...)
{
	va_list ap;

	va_start(ap, msg);
	vfprintf(stderr, msg, ap);
	va_end(ap);

	exit(1);
}
#endif /* UTILSH_DIE_IMPL */
