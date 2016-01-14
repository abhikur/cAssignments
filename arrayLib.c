#include <stdlib.h>
#include <stdio.h>
typedef struct {
	void *base;
	int typeSize;
	int length;
} arrayUtil;

typedef int (MatchFunc)(void *, void*);
typedef void (ConvertFunc)(void *, void *, void*);
typedef void (OperationFunc)(void* , void*);
typedef void* (ReducerFunc)(void* , void* , void* );


arrayUtil create(int typeSize , int length) {
	arrayUtil array;
	array.base = calloc(length , typeSize);
	array.typeSize = typeSize;
	array.length = length;
	return array;
}

int areEqual(arrayUtil a , arrayUtil b) {
	char *each_byte_of_a = a.base;
	char *each_byte_of_b = b.base;
	int result=0;
	if(a.length == b.length){
		for(int i=0; i< (a.length); i++){
			if(each_byte_of_a[i] == each_byte_of_b[i])
				result = 1;
			else return 0;
		}
	}
	return result;
}

arrayUtil resize(arrayUtil util , int length) {
	util.base = realloc(util.base , length);
	util.length = length;
	return util;
}

void dispose(arrayUtil util) {
	free(util.base);
}

int findIndex(arrayUtil util, void * element) {
	int index = -1;
	for(int i=0; i<util.length; i++) {
		if(((int *)(util.base))[i] == *((int *)element))
			index = i;
	}
	return index;
}

int isDivisibleBy(void *hint , void *item) {
	return (*((int *)(item)) % *((int *)(hint)) == 0);
}

int isLessThan(void *hint , void *item) {
	return (*((int *)(item)) < *((int *)(hint)));
}

void * findFirst(arrayUtil util, MatchFunc* match, void* hint){
	int a = 0;
	void *result = &a;
	for(int i=0; i<util.length; i++){
		if(match(hint , util.base + i*util.typeSize))
			return (util.base + i*util.typeSize);
	}
	return result;
}


void * findLast(arrayUtil util, MatchFunc* match, void* hint){
	int a = 0;
	int *result = &a;
	for(int i=0; i<util.length; i++){
		if(match( hint , util.base + i*util.typeSize)){
			result = (util.base + i*util.typeSize);
		}
	}
	return result;
}


int count(arrayUtil util, MatchFunc* match, void* hint) {
	int count = 0;
	for(int i=0; i<util.length; i++){
		if((*match)( hint , util.base + i*util.typeSize))
			count++;
	}
	return count;
}

int filter(arrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems ) {
	int count=0;
	void *ptr;
	for(int i=0; i<util.length; i++){
		if(match( hint, util.base + i*util.typeSize)){
			if(count<maxItems){
				destination[count*util.typeSize] = &ptr;
				*(int *)destination[count*util.typeSize] = util.base + i*util.typeSize;
				++count;
			}
		}
	}
	return count;
}

int main() {
	arrayUtil a = create(4,4);
	arrayUtil b = create(4,4);
	((int *)(a.base))[0] = 3;
	((int *)(a.base))[1] = 5;
	((int *)(a.base))[2] = 9; 
	((int *)(a.base))[3] = 7;

	int hint = 7;
	printf("%d\n",filter(a , isLessThan , &hint , b.base , b.length));
	printf("%d\n", ((int *)(b.base))[0]);
	printf("%d\n", ((int *)(a.base))[0]);
	printf("%p %p\n", a.base,b.base);
}

// void increamentOne(void* hint, void* sourceItem, void* destinationItem) {
// 	*(int *)destinationItem = *(int *)hint + *(int *)sourceItem;
// }

// void map(arrayUtil source, arrayUtil destination, ConvertFunc* convert, void* hint) {
// 	void * dest_Base = destination.base;
// 	for(int i=0; i<source.length; i++){
// 		increamentOne(hint , source.base+i*source.typeSize , dest_Base+i*destination.typeSize);
// 	}
// }

// void multiplyByAnyNum(void *hint , void *item) {
// 	*(int *)item = *(int *)hint * *(int *)item;
// }

// void forEach(arrayUtil util, OperationFunc* operation, void* hint){
// 	void *base = util.base;
// 	for(int i=0; i<util.length; i++) {
// 		operation( hint , base+i*util.typeSize);
// 	}
// }

// void *sumOfArray(void* hint, void* previousItem, void* item) {
// 	*(int *)previousItem = *(int *)previousItem + *(int *)item;
// 	return previousItem;
// }

// void* reduce(arrayUtil util, ReducerFunc* reducer, void* hint, void* initialValue) {
// 	int *sum;
// 	for(int i=0;i <util.length; i++){
// 		sum = reducer(initialValue , util.base , util.base+4);
// 	}
// 	return sum;
// }
