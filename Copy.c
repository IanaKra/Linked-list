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

// �������� �����
CyclicList copyList(CyclicList* original) {
    CyclicList newList;
    initList(&newList);

    if (original->current == NULL) return newList;

    // �������� ��� ��������
    Node* temp = original->head;
    do {
        insertAfter(&newList, temp->data);
        temp = temp->next;
    } while (temp != original->head);

    // ��������������� ������� current
    int idx = getCurrentIndex(original);
    if (idx != -1) {
        Node* curr = newList.head;
        for (int i = 0; i < idx; i++) curr = curr->next;
        newList.current = curr;
    }

    return newList;
}
