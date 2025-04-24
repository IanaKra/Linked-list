#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>
#include "List.h"

// Вывод цикла
void displayList(CyclicList* list) {
    if (list->head == NULL) {
        printf("Список пуст\n");
        return;
    }

    Node* temp = list->head;
    for (int i = 0; i < list->size; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


// Вывод текущего состояния
void printStatus(ListManager* manager) {
    if (manager->listCount == 0) {
        printf("Списки не созданы.\n");
        return;
    }

    printf("\nТекущее состояние:\n");

    // Печать всех списков
    for (int i = 0; i < manager->listCount; i++) {
        printf("[Список %d] \t", i + 1);
        displayList(&manager->lists[i]);

        // Печать текущего элемента списка, если он существует
        if (manager->lists[i].current != NULL) {
            int idx = getCurrentIndex(&manager->lists[i]);
            printf("Текущий элемент: %d (индекс %d)\n", manager->lists[i].current->data, idx);
        } else {
            printf("Список пуст или текущий элемент не установлен.\n");
        }

        // Разделитель между списками
        printf("\n");
    }

    // Печать информации о текущем списке
    printf("Текущий активный список: %d\n", manager->currentIndex + 1);
}

// Ожидание нажатия клавиши
void waitForKey() {
    printf("\nНажмите любую клавишу для продолжения...");
    getchar(); // Ожидаем нажатия клавиши
    // Добавляем еще один getchar() для захвата символа новой строки
    getchar();
}
// Очистка консоли
void clearScreen() {
    printf("\033[H\033[J"); // Очистка консоли
}
