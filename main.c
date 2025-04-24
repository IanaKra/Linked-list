#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>
#include "List.h"

/* 26.2
 * Программа для работы со списками
 * Автор: Я.Д.Кращенко, 2025
 */

int main() {
    setlocale(LC_ALL, "Russian");
    printf("26.2\n");

    ListManager manager;
    initListManager(&manager);

    int choice, value;

    while (true) {
        clearScreen();
        printf("Меню:\n");
        printf("1. Следующий элемент\n");
        printf("2. Предыдущий элемент\n");
        printf("3. Вставить после текущего\n");
        printf("4. Вставить перед текущим\n");
        printf("5. Удалить текущий элемент\n");
        printf("6. Создать новый список\n");
        printf("7. Копировать текущий список\n"); // Добавили опцию для копирования
        printf("8. Следующий список\n");
        printf("9. Предыдущий список\n");
        printf("10. Вернуться к оригиналу\n");
        printf("11. Вывести все элементы\n");
        printf("12. Выход\n");

        // Вывод текущего состояния
        printStatus(&manager);  // Используем новую функцию для отображения состояния

        printf("\nВыберите опцию: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Работа с текущим списком
                displayList(&manager.lists[manager.currentIndex]);
                next(&manager.lists[manager.currentIndex]);
                break;
            case 2:
                // Работа с текущим списком
                previous(&manager.lists[manager.currentIndex]);
                break;
            case 3:
                printf("Введите значение: ");
                scanf("%d", &value);
                insertAfter(&manager.lists[manager.currentIndex], value);
                break;
            case 4:
                printf("Введите значение: ");
                scanf("%d", &value);
                insertBefore(&manager.lists[manager.currentIndex], value);
                break;
            case 5:
                removeCurrent(&manager.lists[manager.currentIndex]);
                break;
            case 6:
                createNewList(&manager);    // Создание нового списка
                break;
            case 7: // Обработка нового выбора
                copyCurrentList(&manager);  // Переход к следующему списку
                break;
            case 8:
                nextList(&manager);  // Переход к предыдущему списку
                break;
            case 9:
                previousList(&manager); // Возврат к оригинальному списку
                break;
            case 10:
                returnToOriginalList(&manager); // Возврат к оригинальному списку
                break;
            case 11:
                for (int i = 0; i < manager.listCount; i++) {
                    printf("Список %d: ", i + 1);
                    displayList(&manager.lists[i]);
                }
                printf("\nОкно обновится через 5 секунд\n");
                sleep(5); // 5 секунд ожидания (Linux)
                break;
            case 12:
                for (int i = 0; i < manager.listCount; i++) {
                    freeList(&manager.lists[i]);
                }
                printf("Выход...\n");
                return 0;
            default:
                printf("Неверный выбор!\n");
        }
    }

    return 0;
}
