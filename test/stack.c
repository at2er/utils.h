#include <stdio.h>
#include <stdlib.h>
#include "../stack.h"

typedef utilsh_stack(int) stack_t;

int main() {
	stack_t s;
	utilsh_stack_init(&s, 128);
	utilsh_stack_push(&s, 123);
	utilsh_stack_push(&s, 456);
	// utilsh_stack_resize(&s, 1);
	int a = utilsh_stack_pop(&s);
	printf("base:%p, top:%p\n", (void*)s.base, (void*)s.top);
	int b = utilsh_stack_pop(&s);
	printf("base:%p, top:%p\n", (void*)s.base, (void*)s.top);
	int c = utilsh_stack_pop(&s);
	printf("a:%d\nb:%d\nc:%d\n", a, b, c);
	return 0;
}
