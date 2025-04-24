#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>
#include "List.h"

// Создание копии
CyclicList copyList(CyclicList* original) {
    CyclicList newList;
    initList(&newList);

    if (original->current == NULL) return newList;

    Node* temp = original->head;
    do {
        insertAfter(&newList, temp->data);
        temp = temp->next;
    } while (temp != original->head);

    int idx = getCurrentIndex(original);
    if (idx != -1) {
        Node* curr = newList.head;
        for (int i = 0; i < idx; i++) curr = curr->next;
        newList.current = curr;
    }
    return newList;
}


// Копирование текущего списка
void copyCurrentList(ListManager* manager) {
    if (manager->listCount < MAX_LISTS) {
        manager->lists[manager->listCount] = copyList(&manager->lists[manager->currentIndex]);
        manager->currentIndex = manager->listCount;
        manager->listCount++;
        printf("Копия текущего списка создана.\n");
    } else {
        printf("Достигнут предел максимального количества списков.\n");
    }
}
