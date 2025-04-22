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

// Создание копии
CyclicList copyList(CyclicList* original) {
    CyclicList newList;
    initList(&newList);

    if (original->current == NULL) return newList;

    // Копируем все элементы
    Node* temp = original->head;
    do {
        insertAfter(&newList, temp->data);
        temp = temp->next;
    } while (temp != original->head);

    // Восстанавливаем позицию current
    int idx = getCurrentIndex(original);
    if (idx != -1) {
        Node* curr = newList.head;
        for (int i = 0; i < idx; i++) curr = curr->next;
        newList.current = curr;
    }

    return newList;
}
