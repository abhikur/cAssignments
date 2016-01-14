typedef struct {
	void *base;
	int typeSize;
	int length;
} arrayUtil;

typedef int (MatchFunc)(void *, void*);
typedef void (ConvertFunc)(void *, void *, void*);
typedef void (OperationFunc)(void* , void*);
typedef void* (ReducerFunc)(void* , void* , void* );

arrayUtil create(int , int);
int areEqual(arrayUtil,arrayUtil);
arrayUtil resize(arrayUtil , int);
void dispose(arrayUtil);
int findIndex(arrayUtil , void *);
void * findFirst(arrayUtil, MatchFunc*, void*);
void * findLast(arrayUtil, MatchFunc*, void*);
int isDivisibleBy(void *hint , void *item);
int count(arrayUtil util, MatchFunc* match, void* hint);
int isLessThan(void *hint , void *item);
int filter(arrayUtil, MatchFunc*, void*, void**, int );

