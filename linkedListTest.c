#include "linkedList.h"
#include <string.h>
#include <assert.h>

void test_createList() {
	LinkedList List = createList();
	assert(List.length == 0);
	assert(List.first == NULL);
	assert(List.last == NULL);
}

void test_add_to_list() {
	LinkedList list = createList();
	int a = 5;
	int length_of_list = add_to_list(&list, &a);
	int pushedNum = *((int *)(list.last->value));
	assert(length_of_list == 1);
	assert(pushedNum == 5);
}

void test_get_first_element() {
	int a = 8;
	LinkedList list = createList();
	add_to_list(&list , &a);
	int firstEle = *((int *)(get_first_element(list)));
	assert(firstEle == 8);
}

void test_get_last_element() {
	int a = 8,b=2;
	LinkedList list = createList();
	add_to_list(&list , &a);
	add_to_list(&list , &b);
	int lastEle = *((int *)(get_last_element(list)));
	assert(lastEle == 2);
}

void test_forEach() {
	int a = 2,b=4;
	LinkedList list = createList();
	add_to_list(&list , &a);
	add_to_list(&list , &b);
	forEach(list , increament);
	int firstEle = *((int *)(list.first->value));
	int lastEle = *((int *)(list.last->value));
	assert(firstEle == 3);
	assert(lastEle == 5);
}

void test_getElementAt() {
	int a = 2,b=4;
	LinkedList list = createList();
	add_to_list(&list , &a);
	add_to_list(&list , &b);
	void *value = ((Element *)getElementAt(list, 1))->value;
	assert(*(int *)value == 4);
}
 
void test_indexOf() {
	int a = 2,b=4;
	LinkedList list = createList();
	add_to_list(&list , &a);
	add_to_list(&list , &b);
	assert(indexOf(list , &a) == 0); 
	assert(indexOf(list , &b) == 1); 
}

// void test_deleteElementAt() {
// 	int a = 2,b=4;
// 	LinkedList list = createList();
// 	add_to_list(&list , &a);
// 	add_to_list(&list , &b);
// 	assert(*((int *)deleteElementAt(&list , 0)) == 2);
// 	assert(list.length == 1);
// 	assert(*(int *)list.first->value == 2);
// }

// void test_asArray() {
// 	int a = 2,b=4;
// 	LinkedList list = createList();
// 	LinkedList emptyList = createList();
// 	add_to_list(&list , &a);
// 	add_to_list(&list , &b);
// 	assert(asArray(list , &emptyList , 5) == 2);
// }