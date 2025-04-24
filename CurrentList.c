#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>
#include "List.h"

// Инициализация менеджера списков
void initListManager(ListManager* manager) {
    manager->currentIndex = 0;
    manager->listCount = 1; // Начнем с одного списка
    initList(&manager->lists[0]); // Инициализируем первый список
}

// Создание нового списка
void createNewList(ListManager* manager) {
    if (manager->listCount < MAX_LISTS) {
        initList(&manager->lists[manager->listCount]);
        manager->currentIndex = manager->listCount;
        manager->listCount++;
        printf("Создан новый список.\n");
    } else {
        printf("Достигнут предел максимального количества списков.\n");
    }
}

// Переход к следующему списку
void nextList(ListManager* manager) {
    if (manager->currentIndex < manager->listCount - 1) {
        manager->currentIndex++;
        printf("Теперь выбран следующий список.\n");
    } else {
        printf("Это последний список.\n");
    }
    printf("\nОкно обновится через 3 секунды");
    sleep(3000); // Пауза 3с (3000 миллисекунд)
}

// Переход к предыдущему списку
void previousList(ListManager* manager) {
    if (manager->currentIndex > 0) {
        manager->currentIndex--;
        printf("Теперь выбран предыдущий список.\n");
    } else {
        printf("Это первый список.\n");
    }
    printf("\nОкно обновится через 3 секунды");
    sleep(3000); // Пауза 3с (3000 миллисекунд)
}

// Возврат к оригинальному списку
void returnToOriginalList(ListManager* manager) {
    manager->currentIndex = 0;
    printf("Возвращаемся к оригинальному списку.\n");
}
