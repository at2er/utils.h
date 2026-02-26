#include <stdio.h>
#include <stdlib.h>
#define UTILSH_DARR_STRIP
#include "../darr2.h"

int main() {
	darr(int, arr);
	darr_push(arr, 114);
	darr_foreach(i, arr)
		printf("[%d] = %d\n", i, arr[i]);
	return 0;
}
