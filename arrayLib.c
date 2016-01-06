#include <stdlib.h>
#include <stdio.h>
typedef struct {
	void *base;
	int typeSize;
	int length;
} arrayUtil;

typedef int (MatchFunc)(void *, void*);

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
		for(int i=0; i< ((a.length) * a.typeSize); i++){
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
	if(*((int *)(item)) % *((int *)(hint)) == 0)
		return 1;
	return 0;
}

void * findFirst(arrayUtil util, MatchFunc* match, void* hint){
	int *result = NULL;
	for(int i=0; i<util.length; i++){
		if((*match)( hint , util.base + i*util.typeSize))
			return (util.base + i*util.typeSize);
	}
	return result;
}

void * findLast(arrayUtil util, MatchFunc* match, void* hint){
	int *result = NULL;
	for(int i=0; i<util.length; i++){
		if((*match)( hint , util.base + i*util.typeSize))
			result = (util.base + i*util.typeSize);
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

}
