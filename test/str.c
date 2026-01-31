#include <stdio.h>

#define UTILSH_STR_IMPL
#include "../str.h"

int
main()
{
	struct str s0, s1, s2;

	/* -- test 's0' -- BEGIN */
	if (str_from_cstr(&s0, "hello world!") == NULL)
		return 1;
	printf("s0: '%s'\n", s0.s);
	/* -- test 's0' -- END */

	/* -- test 's1' -- BEGIN */
	if (str_empty(&s1) == NULL)
		return 1;
	if (str_append_cstr(&s1, "this is str.h, ") == NULL)
		return 1;
	if (str_append_cstr(&s1, "so ") == NULL)
		return 1;
	if (str_append_str(&s1, &s0) == NULL)
		return 1;
	printf("s1: '"STR_FMT"'\n", STR_ARG(s1));
	/* or just printf("s1: %s", s1.s) */
	/* -- test 's1' -- END */

	/* -- test 's2' -- BEGIN */
	if (str_empty(&s2) == NULL)
		return 1;
	if (str_expand_siz(&s2, 8) == NULL)
		return 1;
	snprintf(s2.s, s2.siz, "%d", 114514);
	printf("s2: '%s'\n", s2.s);
	/* -- test 's2' -- END */

	return 0;
}
