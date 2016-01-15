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
typedef int MatchFunc(void*, void*);


LinkedList createList(void);
int add_to_list(LinkedList *,void *);
void *get_first_element(LinkedList);
void *get_last_element(LinkedList list);
void increament(void *ele);
void forEach(LinkedList, ElementProcessor e);
void * getElementAt(LinkedList, int );
int indexOf(LinkedList, void *);
void * deleteElementAt(LinkedList *, int);
int asArray(LinkedList, void **, int);

