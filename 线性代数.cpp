#include <stdio.h>

#define MAX 10 // ������ά��

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("����������Ԫ�أ��� %d �� %d �У���\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Ԫ�� [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("��������\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];
    int rows1, cols1, rows2, cols2;
    int choice;

    printf("�������һ������������������������� %d����", MAX);
    scanf("%d %d", &rows1, &cols1);
    inputMatrix(mat1, rows1, cols1);

    printf("������ڶ�������������������������� %d����", MAX);
    scanf("%d %d", &rows2, &cols2);
    inputMatrix(mat2, rows2, cols2);

    printf("��ѡ��������ͣ�\n1. ����ӷ�\n2. �������\n3. ����˷�\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (rows1 == rows2 && cols1 == cols2) {
                addMatrices(mat1, mat2, result, rows1, cols1);
                printMatrix(result, rows1, cols1);
            } else {
                printf("����ӷ�Ҫ�����������ά����ͬ��\n");
            }
            break;
        case 2:
            if (rows1 == rows2 && cols1 == cols2) {
                subtractMatrices(mat1, mat2, result, rows1, cols1);
                printMatrix(result, rows1, cols1);
            } else {
                printf("�������Ҫ�����������ά����ͬ��\n");
            }
            break;
        case 3:
            if (cols1 == rows2) {
                multiplyMatrices(mat1, mat2, result, rows1, cols1, cols2);
                printMatrix(result, rows1, cols2);
            } else {
                printf("����˷�Ҫ���һ��������������ڵڶ��������������\n");
            }
            break;
        default:
            printf("��Ч��ѡ��\n");
    }

    return 0;
}
