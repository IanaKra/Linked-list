#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>
#include <conio.h> // ��� getch() � Windows
#include <windows.h> // ��� ������ � �������� � Windows
#include "List.h"

// ������������� ��������� �������
void initListManager(ListManager* manager) {
    manager->currentIndex = 0;
    manager->listCount = 1; // ������ � ������ ������
    initList(&manager->lists[0]); // �������������� ������ ������
}

// �������� ������ ������
void createNewList(ListManager* manager) {
    if (manager->listCount < MAX_LISTS) {
        initList(&manager->lists[manager->listCount]);
        manager->currentIndex = manager->listCount;
        manager->listCount++;
        printf("������ ����� ������.\n");
    } else {
        printf("��������� ������ ������������� ���������� �������.\n");
    }
    printf("\n���� ��������� ����� 3 �������");
    Sleep(3000); // ����� 3� (3000 �����������)
}

// ������� � ���������� ������
void nextList(ListManager* manager) {
    if (manager->currentIndex < manager->listCount - 1) {
        manager->currentIndex++;
        printf("������ ������ ��������� ������.\n");
    } else {
        printf("��� ��������� ������.\n");
    }
    printf("\n���� ��������� ����� 3 �������");
    Sleep(3000); // ����� 3� (3000 �����������)
}

// ������� � ����������� ������
void previousList(ListManager* manager) {
    if (manager->currentIndex > 0) {
        manager->currentIndex--;
        printf("������ ������ ���������� ������.\n");
    } else {
        printf("��� ������ ������.\n");
    }
    printf("\n���� ��������� ����� 3 �������");
    Sleep(3000); // ����� 3� (3000 �����������)
}

// ������� � ������������� ������
void returnToOriginalList(ListManager* manager) {
    manager->currentIndex = 0;
    printf("������������ � ������������� ������.\n");
}
