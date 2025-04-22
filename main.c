#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>
#include <conio.h> // ��� getch() � Windows
#include <windows.h> // ��� ������ � �������� � Windows
#include "List.h"

/* 26.2
 * ��������� ��� ������ �� ��������
 * �����: �.�.��������, 2025
 */

int main() {
    setlocale(LC_ALL, "Russian");
    printf("26.2\n");

    initListManager(&manager); // ������������� ���������

    int choice, value;

    while (true) {
        clearScreen();
        printf("����:\n");
        printf("1. ��������� �������\n");
        printf("2. ���������� �������\n");
        printf("3. �������� ����� ��������\n");
        printf("4. �������� ����� �������\n");
        printf("5. ������� ������� �������\n");
        printf("6. ������� ����� ������\n");
        printf("7. ��������� ������\n");
        printf("8. ���������� ������\n");
        printf("9. ��������� � ���������\n");
        printf("10. ������� ��� ��������\n");
        printf("11. �����\n");

        // ����� �������� ���������
        printStatus(&manager);  // ���������� ����� ������� ��� ����������� ���������

        printf("\n�������� �����: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                // ������ � ������� �������
                displayList(&manager.lists[manager.currentIndex]);
                next(&manager.lists[manager.currentIndex]);
                break;
            }
            case 2: {
                // ������ � ������� �������
                previous(&manager.lists[manager.currentIndex]);
                break;
            }
            case 3: {
                printf("������� ��������: ");
                scanf("%d", &value);
                insertAfter(&manager.lists[manager.currentIndex], value);
                break;
            }
            case 4: {
                printf("������� ��������: ");
                scanf("%d", &value);
                insertBefore(&manager.lists[manager.currentIndex], value);
                break;
            }
            case 5: {
                removeCurrent(&manager.lists[manager.currentIndex]);
                break;
            }
            case 6: {
                createNewList(&manager); // �������� ������ ������
                break;
            }
            case 7: {
                nextList(&manager); // ������� � ���������� ������
                break;
            }
            case 8: {
                previousList(&manager); // ������� � ����������� ������
                break;
            }
            case 9: {
                returnToOriginalList(&manager); // ������� � ������������� ������
                break;
            }
            case 10: {
                // ������ ��������� ���� �������
                for (int i = 0; i < manager.listCount; i++) {
                    printf("������ %d: ", i + 1);
                    displayList(&manager.lists[i]);
                }
                printf("\n���� ��������� ����� 5 ������");
                Sleep(5000); // ����� 5� (5000 �����������)
                break;
            }
            case 11: {
                for (int i = 0; i < manager.listCount; i++) {
                    freeList(&manager.lists[i]);
                }
                printf("�����...\n");
                return 0;
            }
            default: {
                printf("�������� �����!\n");
            }
        }
    }

    return 0;
}
