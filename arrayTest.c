#include "arrayLib.c"
#include <assert.h>

int main(){
	arrayUtil a1 = create(4,2);
	arrayUtil a2 = create(4,2);
	((int *)(a1.base))[0] = 1;
	((int *)(a1.base))[1] = 3;
	((int *)(a2.base))[0] = 1;
	((int *)(a2.base))[1] = 3;
	
	int a = 1, b = 2, c = 4;
	
	arrayUtil new_array = resize(a1 , 3);
	
	int index1 = findIndex(a1 , &a);
	int index2 = findIndex(a1 , &b);
	int index3 = findIndex(a2 , &c);
	
	assert(areEqual(a1,a2) == 1);
	assert(new_array.length == 3);
	assert(index1 == 0);
	assert(index2 == -1);
	assert(index3 == -1);
	
	return 0;
}
