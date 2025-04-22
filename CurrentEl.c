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


// Получение индекса текущего элемента
int getCurrentIndex(CyclicList* list) {
    if (!list->head || !list->current) return -1;

    int index = 0;
    Node* temp = list->head;
    while (temp != list->current && index < list->size) {
        temp = temp->next;
        index++;
    }
    return (temp == list->current) ? index : -1;
}

// Изменение текущего элемента на предыдущий
void previous(CyclicList* list) {
    if (list->current) {
        list->current = list->current->prev;
    }
}

// Изменение текущего элемента на следующий
void next(CyclicList* list) {
    if (list->current) {
        list->current = list->current->next;
    }
}

