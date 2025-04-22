#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>
#include <conio.h> // Для getch() в Windows
#include <windows.h> // Для работы с консолью в Windows
#include "List.h"


// Инициализация списка
void initList(CyclicList* list) {
    list->current = NULL;
    list->head = NULL;      // Инициализируем голову
    list->size = 0;
}

// Освободить память списка
void freeList(CyclicList* list) {
    while (list->current != NULL) {
        removeCurrent(list);
    }
}

