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

// Вставка после текущего
void insertAfter(CyclicList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (list->current == NULL) {
        newNode->prev = newNode;
        newNode->next = newNode;
        list->current = newNode;
        list->head = newNode;
    } else {
        newNode->next = list->current->next;
        newNode->prev = list->current;
        list->current->next->prev = newNode;
        list->current->next = newNode;
    }
    list->size++;
}

// Вставка перед текущим
void insertBefore(CyclicList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (list->current == NULL) {
        newNode->prev = newNode;
        newNode->next = newNode;
        list->current = newNode;
        list->head = newNode; // Устанавливаем голову
    } else {
        newNode->prev = list->current->prev;
        newNode->next = list->current;
        list->current->prev->next = newNode;
        list->current->prev = newNode;

        // Обновляем голову если вставляем перед ней
        if (list->current == list->head) {
            list->head = newNode;
        }
    }
    list->size++;
}

// Удаление текущего
void removeCurrent(CyclicList* list) {
    if (list->current == NULL) return;

    if (list->size == 1) {
        free(list->current);
        list->current = NULL;
        list->head = NULL; // Сбрасываем голову
    } else {
        Node* toDelete = list->current;

        // Обновляем голову если удаляем ее
        if (toDelete == list->head) {
            list->head = toDelete->next;
        }

        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;
        list->current = toDelete->next;
        free(toDelete);
    }
    list->size--;
}
