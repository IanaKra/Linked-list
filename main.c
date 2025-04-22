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

/* 26.2
 * Программа для работы со списками
 * Автор: Я.Д.Кращенко, 2025
 */

int main() {
    setlocale(LC_ALL, "Russian");
    printf("26.2\n");

    initListManager(&manager); // Инициализация менеджера

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
        printf("7. Следующий список\n");
        printf("8. Предыдущий список\n");
        printf("9. Вернуться к оригиналу\n");
        printf("10. Вывести все элементы\n");
        printf("11. Выход\n");

        // Вывод текущего состояния
        printStatus(&manager);  // Используем новую функцию для отображения состояния

        printf("\nВыберите опцию: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                // Работа с текущим списком
                displayList(&manager.lists[manager.currentIndex]);
                next(&manager.lists[manager.currentIndex]);
                break;
            }
            case 2: {
                // Работа с текущим списком
                previous(&manager.lists[manager.currentIndex]);
                break;
            }
            case 3: {
                printf("Введите значение: ");
                scanf("%d", &value);
                insertAfter(&manager.lists[manager.currentIndex], value);
                break;
            }
            case 4: {
                printf("Введите значение: ");
                scanf("%d", &value);
                insertBefore(&manager.lists[manager.currentIndex], value);
                break;
            }
            case 5: {
                removeCurrent(&manager.lists[manager.currentIndex]);
                break;
            }
            case 6: {
                createNewList(&manager); // Создание нового списка
                break;
            }
            case 7: {
                nextList(&manager); // Переход к следующему списку
                break;
            }
            case 8: {
                previousList(&manager); // Переход к предыдущему списку
                break;
            }
            case 9: {
                returnToOriginalList(&manager); // Возврат к оригинальному списку
                break;
            }
            case 10: {
                // Печать элементов всех списков
                for (int i = 0; i < manager.listCount; i++) {
                    printf("Список %d: ", i + 1);
                    displayList(&manager.lists[i]);
                }
                printf("\nОкно обновится через 5 секунд");
                Sleep(5000); // Пауза 5с (5000 миллисекунд)
                break;
            }
            case 11: {
                for (int i = 0; i < manager.listCount; i++) {
                    freeList(&manager.lists[i]);
                }
                printf("Выход...\n");
                return 0;
            }
            default: {
                printf("Неверный выбор!\n");
            }
        }
    }

    return 0;
}
