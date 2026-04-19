#include <stdio.h>
#include <stdlib.h>
#include "../stack.h"

typedef utilsh_stack(int) stack_t;

int main() {
	stack_t s;
	utilsh_stack_init(&s, 2);
	utilsh_stack_push(&s, 123);
	utilsh_stack_push(&s, 456);

	printf("=== before resize ===\nbase:%p, topn:%d\n", (void*)s.base, s.topn);
	utilsh_stack_resize(&s, 256);
	printf("=== after resize ===\nbase:%p, topn:%d\n", (void*)s.base, s.topn);

	int a = utilsh_stack_pop(&s);
	printf("utilsh_stack_pop(a:%d): topn:%d\n", a, s.topn);

	int b1 = utilsh_stack_top(&s);
	printf("utilsh_stack_top(b1:%d): topn:%d\n", b1, s.topn);

	int b2 = utilsh_stack_pop(&s);
	printf("utilsh_stack_pop(b2:%d): topn:%d\n", b2, s.topn);

	int c = utilsh_stack_pop(&s);
	printf("utilsh_stack_pop(c:%d): topn:%d\n", c, s.topn);

	return 0;
}
