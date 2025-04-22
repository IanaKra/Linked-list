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


// ��������� ������� �������� ��������
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

// ��������� �������� �������� �� ����������
void previous(CyclicList* list) {
    if (list->current) {
        list->current = list->current->prev;
    }
}

// ��������� �������� �������� �� ���������
void next(CyclicList* list) {
    if (list->current) {
        list->current = list->current->next;
    }
}

