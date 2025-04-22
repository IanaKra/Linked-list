#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

// Определение структуры узла двусвязного циклического списка
typedef struct Node {
    int data;           // Значение, хранящееся в узле (целое число)
    struct Node* prev;  // Указатель на предыдущий узел в списке
    struct Node* next;  // Указатель на следующий узел в списке
} Node;

// Определение структуры циклического списка
typedef struct {
    Node* current;      // Указатель на текущий выбранный узел
    Node* head;         // Указатель на "голову" списка (обычно первый добавленный элемент)
    int size;           // Количество элементов в списке (размер списка)
} CyclicList;

#define MAX_LISTS 100  // Максимальное количество списков, которые можно создать

typedef struct {
    CyclicList lists[MAX_LISTS]; // Массив всех списков
    int currentIndex;            // Индекс текущего списка
    int listCount;               // Количество созданных списков
} ListManager;

//List
void initList(CyclicList* list);                    // Инициализация списка
void freeList(CyclicList* list);                    // Освободить память списка

//CurrentList
ListManager manager;                                // Менеджер для работы с несколькими списками
void initListManager(ListManager* manager);         // Инициализация менеджера списков
void createNewList(ListManager* manager);           // Создание нового списка
void nextList(ListManager* manager);                // Переход к следующему списку
void previousList(ListManager* manager);            // Переход к предыдущему списку
void returnToOriginalList(ListManager* manager);    // Возврат к оригинальному списку


//Editor
void insertAfter(CyclicList* list, int value);      // Вставка после текущего элемента
void insertBefore(CyclicList* list, int value);     // Вставка перед текущим элементом
void removeCurrent(CyclicList* list);               // Удаление текущего

//Copy
CyclicList copyList(CyclicList* original);          // Создание копии

//CurrentEl
int getCurrentIndex(CyclicList* list);              // Получение индекса текущего элемента
void previous(CyclicList* list);                    // Изменение текущего элемента на предыдущий
void next(CyclicList* list);                        // Изменение текущего элемента на следующий

//Screen
void displayList(CyclicList* list);                 // Вывод цикла
void printStatus(ListManager* manager);             // Вывод текущего состояния
void waitForKey();                                  // Ожидание нажатия клавиши
void clearScreen();                                 // Очистка консоли

#endif // LIST_H_INCLUDED
