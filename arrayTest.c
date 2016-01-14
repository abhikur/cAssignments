#include "arrayLib.h"
#include <assert.h>
#include <stdio.h>


void test_create_array_of_string() {
	arrayUtil s1 = create(1,2);
	*(int *)s1.base = 'A';
	assert(s1.length == 2);
	assert(*(char *)s1.base == 'A');
}

void test_areEqual_for_strings() {
	arrayUtil s1 = create(1,2);
	arrayUtil s2 = create(1,2);

	((char *)(s1.base))[0] = 'A';
	((char *)(s1.base))[1] = 'B';
	((char *)(s2.base))[0] = 'A';
	((char *)(s2.base))[1] = 'B';
	char element_to_find = 'B';

	assert(areEqual(s1,s2) == 1);
}

void test_resizing_array() {
	arrayUtil s1 = create(1,4);
	arrayUtil new_array = resize(s1,5);
	assert(new_array.length == 5);
}

void test_findIndex() {
	arrayUtil a = create(1,3);
	((int *)(a.base))[0] = 3;
	((int *)(a.base))[1] = 5;
	((int *)(a.base))[2] = 9;
	int toFind = 5;
	assert(findIndex(a , &toFind) == 1);
}

void test_findFirst() {
	arrayUtil a = create(4,4);
	((int *)(a.base))[0] = 3;
	((int *)(a.base))[1] = 5;
	((int *)(a.base))[2] = 9; 
	((int *)(a.base))[3] = 7;
	int hint = 3;
	assert(*(int *)findFirst(a , isDivisibleBy , &hint) == 3);
}

void test_findLast() {
	arrayUtil a = create(4,4);
	((int *)(a.base))[0] = 3;
	((int *)(a.base))[1] = 5;
	((int *)(a.base))[2] = 9; 
	((int *)(a.base))[3] = 7;
	int hint = 3;
	assert(*(int *)findLast(a , isDivisibleBy , &hint) == 9);
}

void test_count() {
	arrayUtil a = create(4,4);
	((int *)(a.base))[0] = 3;
	((int *)(a.base))[1] = 5;
	((int *)(a.base))[2] = 9; 
	((int *)(a.base))[3] = 7;
	int hint = 7;
	assert(count(a , isLessThan , &hint) == 2);
}

void test_filter() {
	arrayUtil a = create(4,4);
	arrayUtil b = create(4,2);
	((int *)(a.base))[0] = 3;
	((int *)(a.base))[1] = 5;
	((int *)(a.base))[2] = 9; 
	((int *)(a.base))[3] = 7;

	int hint = 7;
	assert(filter(a , isLessThan , &hint , b.base , b.length) == 2);
	// printf('%p %p',a.base,b.base);
	assert(((int *)(b.base))[0] == 3);
	assert(((int *)(b.base))[1] == 5);
	// assert(((int *)(b.base))[2] == 9);
	// assert(((int *)(b.base))[3] == 7);
	assert(b.length == 2);

}
// int main(){

// 	arrayUtil a1 = create(4,4);
// 	arrayUtil a2 = create(4,4);
// 	arrayUtil a3 = create(4,0);
// 	arrayUtil a4 = create(4,5);
// 	arrayUtil a5 = create(4,4);

// 	((int *)(a1.base))[0] = 2;
// 	((int *)(a1.base))[1] = 3;
// 	((int *)(a1.base))[2] = 4;
// 	((int *)(a1.base))[3] = 6;

// 	((int *)(a2.base))[0] = 2;
// 	((int *)(a2.base))[1] = 3;
// 	((int *)(a2.base))[2] = 4;
// 	((int *)(a2.base))[3] = 6;

// 	int a = 4, b = 2, c = 6;
	
// 	arrayUtil new_array = resize(a1 , 5);
	
// 	int index1 = findIndex(a1 , &a);
// 	int index2 = findIndex(a1 , &b);
// 	int index3 = findIndex(a2 , &c);
// 	int hint1 = 2;
// 	int hint2 = 1;
// 	int hint3 = 5;

// 	void *first_found_in_array = findFirst(a1 , isDivisibleBy , &hint1);
// 	void *first_found_in_second_array = findFirst(a2 , isDivisibleBy , &hint2);
// 	void *last_found_in_array = findLast(a1 , isDivisibleBy , &hint1);
// 	void *last_found_in_second_array = findLast(a2 , isDivisibleBy , &hint2);
// 	void *last_found_in_third_array = findLast(a3 , isDivisibleBy , &hint2);

// 	int matching_elements_in_first_array = count(a1 , isDivisibleBy , &hint1);
// 	int matching_elements_in_second_array = count(a2 , isDivisibleBy , &hint2);

// 	int filteredElements = filter(a1 , isLessThan , &hint3 , a4.base , a4.length);
// 	map(a1 , a5 ,increamentOne , &hint2);
// 	forEach(a5 , multiplyByAnyNum , &hint1);
// 	int *sum = reduce(a5 , sumOfArray , &hint1 , &hint2);

// 	int first_element_of_a5 = *((int *)(a5.base));
// 	int second_element_of_a5 = *((int *)(a5.base))+1;
// 	int third_element_of_a5 = *((int *)(a5.base))+2;
// 	int fourth_element_of_a5= *((int *)(a5.base))+3;

//    // ============= Assertions =========================

// 	assert(areEqual(a1,a2) == 1);
// 	printf("Test 1 -> areEqual : passed\n");
// 	assert(new_array.length == 5);
// 	printf("Test 2 -> length of array : passed\n");
// 	assert(index1 == 2);
// 	assert(index2 == 0);
// 	assert(index3 == 3);
// 	printf("Test 3 -> findIndex : passed\n");
// 	assert(*((int *)first_found_in_array) == 2);
// 	assert(*(int *)first_found_in_second_array == 2);
// 	printf("Test 4 -> findFirst : passed\n");
// 	assert(*(int *)last_found_in_array == 6);
// 	assert(*(int *)last_found_in_second_array == 6);
// 	printf("Test 5 -> findLast : passed\n");
// 	assert(matching_elements_in_first_array == 3);
// 	assert(matching_elements_in_second_array == 4);
// 	printf("Test 6 -> count : passed\n");
// 	assert(filteredElements == 3);
// 	printf("Test 7 -> filter : passes\n");
// 	assert(first_element_of_a5 = 3);
// 	assert(second_element_of_a5 = 4);
// 	assert(third_element_of_a5 = 5);
// 	assert(fourth_element_of_a5 = 7);
// 	printf("Test 8 -> map : passed\n");
// 	assert(first_element_of_a5 = 6);
// 	assert(second_element_of_a5 = 8);
// 	assert(third_element_of_a5 = 10);
// 	assert(fourth_element_of_a5 = 14);
// 	printf("Test 9 -> forEach : passed\n");
// 	assert(*sum == 38);
// 	printf("Test 10 -> reduce : passed\n");
// 	areEqual_for_strings();
// 	assert(*(int *)last_found_in_third_array == 0);
// 	printf("Test last -> findLast for zero size array : passed\n");
	
// 	return 0;
// }
