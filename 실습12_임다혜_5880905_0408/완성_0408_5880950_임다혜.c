#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int row;
    int col;
    int value;
} MatrixElement;

typedef struct {
    MatrixElement items[MAX_SIZE];
    int size;
} LinearList;

void initList(LinearList* list) {
    list->size = 0;
}

void addElement(LinearList* list, int row, int col, int value) {
    if (list->size < MAX_SIZE) {
        list->items[list->size].row = row;
        list->items[list->size].col = col;
        list->items[list->size].value = value;
        list->size++;
    }
}

void inputMatrix(LinearList* list) {
    int row, col, value;
    while (1) {
        printf("행렬을 입력하시오? (-1입력 시 행렬의 입력이 종료됨)\n");
        scanf_s("%d", &row);
        if (row == -1) {
            break;
        }
        scanf_s("%d", &col);
        scanf_s("%d", &value);
        addElement(list, row, col, value);
    }
}



