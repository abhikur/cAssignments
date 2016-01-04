#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arrayUtil.h"

int main() {
	arrayUtil a1 = create(4,2);
	arrayUtil a2 = create(4,2);
	*(a1.base) = 1;
	*(a1.base+1) = 2;
	*(a2.base) = 1;
	*(a2.base+1) = 2;
	int a = 1, b = 2;
	assert(areEqual(a1,a2) == 1);
	arrayUtil new_array = resize(a1 , 3);
	assert(new_array.length == 3);
	int index1 = findIndex(a1 , &a);
	int index2 = findIndex(a1 , &b);
	assert(index1 == 0);
	assert(index2 == 1);
	dispose(a1);
}
