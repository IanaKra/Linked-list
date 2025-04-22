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

// ������� ����� ��������
void insertAfter(CyclicList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (list->current == NULL) {
        newNode->prev = newNode;
        newNode->next = newNode;
        list->current = newNode;
        list->head = newNode;
    } else {
        newNode->next = list->current->next;
        newNode->prev = list->current;
        list->current->next->prev = newNode;
        list->current->next = newNode;
    }
    list->size++;
}

// ������� ����� �������
void insertBefore(CyclicList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (list->current == NULL) {
        newNode->prev = newNode;
        newNode->next = newNode;
        list->current = newNode;
        list->head = newNode; // ������������� ������
    } else {
        newNode->prev = list->current->prev;
        newNode->next = list->current;
        list->current->prev->next = newNode;
        list->current->prev = newNode;

        // ��������� ������ ���� ��������� ����� ���
        if (list->current == list->head) {
            list->head = newNode;
        }
    }
    list->size++;
}

// �������� ��������
void removeCurrent(CyclicList* list) {
    if (list->current == NULL) return;

    if (list->size == 1) {
        free(list->current);
        list->current = NULL;
        list->head = NULL; // ���������� ������
    } else {
        Node* toDelete = list->current;

        // ��������� ������ ���� ������� ��
        if (toDelete == list->head) {
            list->head = toDelete->next;
        }

        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;
        list->current = toDelete->next;
        free(toDelete);
    }
    list->size--;
}
