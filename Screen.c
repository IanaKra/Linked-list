#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>
#include "List.h"

// ����� �����
void displayList(CyclicList* list) {
    if (list->head == NULL) {
        printf("������ ����\n");
        return;
    }

    Node* temp = list->head;
    for (int i = 0; i < list->size; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


// ����� �������� ���������
void printStatus(ListManager* manager) {
    if (manager->listCount == 0) {
        printf("������ �� �������.\n");
        return;
    }

    printf("\n������� ���������:\n");

    // ������ ���� �������
    for (int i = 0; i < manager->listCount; i++) {
        printf("[������ %d] \t", i + 1);
        displayList(&manager->lists[i]);

        // ������ �������� �������� ������, ���� �� ����������
        if (manager->lists[i].current != NULL) {
            int idx = getCurrentIndex(&manager->lists[i]);
            printf("������� �������: %d (������ %d)\n", manager->lists[i].current->data, idx);
        } else {
            printf("������ ���� ��� ������� ������� �� ����������.\n");
        }

        // ����������� ����� ��������
        printf("\n");
    }

    // ������ ���������� � ������� ������
    printf("������� �������� ������: %d\n", manager->currentIndex + 1);
}

// �������� ������� �������
void waitForKey() {
    printf("\n������� ����� ������� ��� �����������...");
    getchar(); // ������� ������� �������
    // ��������� ��� ���� getchar() ��� ������� ������� ����� ������
    getchar();
}
// ������� �������
void clearScreen() {
    printf("\033[H\033[J"); // ������� �������
}
