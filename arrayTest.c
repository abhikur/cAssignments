#include "arrayLib.c"
#include <assert.h>
#include <stdio.h>

int main(){
	arrayUtil a1 = create(4,4);
	arrayUtil a2 = create(4,4);

	((int *)(a1.base))[0] = 2;
	((int *)(a1.base))[1] = 3;
	((int *)(a1.base))[2] = 4;
	((int *)(a1.base))[3] = 6;

	((int *)(a2.base))[0] = 2;
	((int *)(a2.base))[1] = 3;
	((int *)(a2.base))[2] = 4;
	((int *)(a2.base))[3] = 6;
	
	int a = 4, b = 2, c = 6;
	
	arrayUtil new_array = resize(a1 , 5);
	
	int index1 = findIndex(a1 , &a);
	int index2 = findIndex(a1 , &b);
	int index3 = findIndex(a2 , &c);
	int hint1 = 2;
	int hint2 = 1;

	void *first_found_in_array = findFirst(a1 , isDivisibleBy , &hint1);
	void *first_found_in_second_array = findFirst(a2 , isDivisibleBy , &hint2);
	void *last_found_in_array = findLast(a1 , isDivisibleBy , &hint1);
	void *last_found_in_second_array = findLast(a2 , isDivisibleBy , &hint2);

	int matching_elements_in_first_array = count(a1 , isDivisibleBy , &hint1);
	int matching_elements_in_second_array = count(a2 , isDivisibleBy , &hint2);

	assert(areEqual(a1,a2) == 1);
	printf("Test 1 -> areEqual : passed\n");
	assert(new_array.length == 5);
	printf("Test 2 -> length of array : passed\n");
	assert(index1 == 2);
	assert(index2 == 0);
	assert(index3 == 3);
	printf("Test 3 -> findIndex : passed\n");
	assert(*(int *)first_found_in_array == 2);
	assert(*(int *)first_found_in_second_array == 2);
	printf("Test 4 -> findFirst : passed\n");
	assert(*(int *)last_found_in_array == 6);
	assert(*(int *)last_found_in_second_array == 6);
	printf("Test 5 -> findLast : passed\n");
	assert(matching_elements_in_first_array == 3);
	assert(matching_elements_in_second_array == 4);
	printf("Test 6 -> count : passed\n");
	
	return 0;
}
