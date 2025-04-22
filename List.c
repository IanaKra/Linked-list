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


// ������������� ������
void initList(CyclicList* list) {
    list->current = NULL;
    list->head = NULL;      // �������������� ������
    list->size = 0;
}

// ���������� ������ ������
void freeList(CyclicList* list) {
    while (list->current != NULL) {
        removeCurrent(list);
    }
}

