#include <stdlib.h>

typedef struct array
{
	int *base;
	int typeSize;
	int length;
} arrayUtil;

arrayUtil create(int typeSize , int length) {
	arrayUtil array;
	array.base = calloc(length , typeSize);
	array.typeSize = typeSize;
	array.length = length;
	return array;
}

int areEqual(arrayUtil a , arrayUtil b) {
	int result=0;
	if(a.length == b.length){
		for(int i=0; i<a.length; i++){
			if(a.base[i] == b.base[i])
				result = 1;
			else return 0;
		}
	}
	return result;
}

arrayUtil resize(arrayUtil util , int length) {
	util.length = length;
	return util;
}

void dispose(arrayUtil util) {
	for(int i=0; i<util.length; i++)
		free(util.base[i]);
	free(util.base);
}

int findIndex(arrayUtil util, void * element) {
	int index = -1;
	for(int i=0; i<util.length; i++){
		if(util.base[i] == *((int *)element))
			index = i;
	}
	return index;
}