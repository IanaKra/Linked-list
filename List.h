#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* current;
    Node* head;
    int size;
} CyclicList;

#define MAX_LISTS 100

typedef struct {
    CyclicList lists[MAX_LISTS];
    int currentIndex;
    int listCount;
} ListManager;

void initList(CyclicList* list);
void freeList(CyclicList* list);

void initListManager(ListManager* manager);
void createNewList(ListManager* manager);
void nextList(ListManager* manager);
void previousList(ListManager* manager);
void returnToOriginalList(ListManager* manager);
void copyCurrentList(ListManager* manager);

void insertAfter(CyclicList* list, int value);
void insertBefore(CyclicList* list, int value);
void removeCurrent(CyclicList* list);

CyclicList copyList(CyclicList* original);
int getCurrentIndex(CyclicList* list);
void previous(CyclicList* list);
void next(CyclicList* list);
void displayList(CyclicList* list);
void printStatus(ListManager* manager);
void waitForKey();
void clearScreen();

#endif // LIST_H_INCLUDED
