#include <stdio.h>
#include <stdlib.h>
typedef struct element{
	void *value;
	struct element *next;
} Element;

typedef struct {
	Element *first;
	Element *last;
	int length;
} LinkedList;

typedef void (*ElementProcessor)(void *);

LinkedList initiator() {
	LinkedList List;
	List.length = 0;
	return List;
}

Element *makeElement() {
	Element *ele = (Element *)calloc(1,sizeof(int));
	ele->next = NULL;
	return ele;
}

LinkedList createList(void) {
	LinkedList List;
	List.first = NULL;
	List.last = NULL;
	List.length = 0;
	return List;
} 

int add_to_list(LinkedList *list,void *ele) {
	Element *element = makeElement();
	element->value = ele;
	if(list->length <1)
		list->first = list->last = element;
	list->last->next = element;
	list->last = element;
	list->length++;
	return list->length;
}

void *get_first_element(LinkedList list) {
	return (list.first->value);
}

void *get_last_element(LinkedList list){
	return list.last->value;
}

void increament(void *ele) {
	++(*(int *)ele);
}

void forEach(LinkedList list, ElementProcessor e) {
	for(int i=0; i<list.length; i++){
		e(list.first->value);
		list.first = list.first->next;
	}
}

void * getElementAt(LinkedList list, int index) {
	void *addOfValue;
	for(int i=0; i<=index; i++){
		addOfValue = list.first;
		list.first = list.first->next;
	}
	return addOfValue;
}

int indexOf(LinkedList list, void *num) {
	for(int i=0; i<list.length; i++){
		if(num == list.first->value)
			return i;
		list.first = list.first->next;
	}
	return -1;
}

void * deleteElementAt(LinkedList *list, int index) {
	void *deletedElement;
	Element *element = getElementAt(*list , index);
	for(int i=0 i<list->length; i++){
		if(list)
	}
	deletedElement = element;
	element = element->next;
	list->length = list->length-1;
	return deletedElement;
}

int asArray(LinkedList list, void **emptyList, int maxElements) {
	return 0;
}

// int main() {
// 	int a = 1,b=2;
// 	LinkedList list = createList();
// 	add_to_list(&list , &a);
// 	add_to_list(&list , &b);
// 	getElementAt(list, 1);
// 	printf("Original add : %p\n", list.first);
// }


int main() {
	int a = 1,b=2,c=4,d=8;
	LinkedList list = createList();
	add_to_list(&list , &a);
	add_to_list(&list , &b);
	add_to_list(&list , &c);
	add_to_list(&list , &d);
	Element *deleted = deleteElementAt(&list,2);
	printf("%d\n", *(int *)deleted->value);
	printf("%d\n", *(int *)list.first->value);
	printf("%d\n", *(int *)list.last->value);
}