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

void addMatrices(LinearList* list1, LinearList* list2, LinearList* result) {
    int i = 0, j = 0;
    while (i < list1->size && j < list2->size) {
        if (list1->items[i].row < list2->items[j].row) {
            addElement(result, list1->items[i].row, list1->items[i].col, list1->items[i].value);
            i++;
        }
        else if (list1->items[i].row > list2->items[j].row) {
            addElement(result, list2->items[j].row, list2->items[j].col, list2->items[j].value);
            j++;
        }
        else {
            if (list1->items[i].col < list2->items[j].col) {
                addElement(result, list1->items[i].row, list1->items[i].col, list1->items[i].value);
                i++;
            }
            else if (list1->items[i].col > list2->items[j].col) {
                addElement(result, list2->items[j].row, list2->items[j].col, list2->items[j].value);
                j++;
            }
            else {
                addElement(result, list1->items[i].row, list1->items[i].col,
                    list1->items[i].value + list2->items[j].value);
                i++;
                j++;
            }
        }
    }
    while (i < list1->size) {
        addElement(result, list1->items[i].row, list1->items[i].col, list1->items[i].value);
        i++;
    }
    while (j < list2->size) {
        addElement(result, list2->items[j].row, list2->items[j].col, list2->items[j].value);
        j++;
    }
}

void printList(LinearList* list) {
    printf("두 행렬의 합\n");
    printf("List : size = %d, last = %d\n", list->size, list->size - 1);
    printf("Items :\n");
    for (int i = 0; i < list->size; i++) {
        printf(" [%d] %d, %d, %d\n", i, list->items[i].row, list->items[i].col, list->items[i].value);
    }
}

int main() {
    LinearList matrix1, matrix2, result;

    initList(&matrix1);
    initList(&matrix2);
    initList(&result);

    inputMatrix(&matrix1);
    inputMatrix(&matrix2);

    addMatrices(&matrix1, &matrix2, &result);

    printList(&result);//

    return 0;
}



