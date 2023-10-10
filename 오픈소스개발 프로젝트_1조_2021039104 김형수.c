#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 3

// ��� ��� �Լ�
void printMatrix(float mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f ", mat[i][j]);
        }
        printf("\n");
    }
}

// �� ����� ����
void addMatrices(float mat1[N][N], float mat2[N][N], float result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// �� ����� ����
void subtractMatrices(float mat1[N][N], float mat2[N][N], float result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// �� ����� ����
void multiplyMatrices(float mat1[N][N], float mat2[N][N], float result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// ù ��° ����� ����
void squareMatrices_1(float mat1[N][N], float result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += mat1[i][k] * mat1[k][j];
            }
        }
    }
}

// �� ��° ����� ����
void squareMatrices_2(float mat2[N][N], float result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += mat2[i][k] * mat2[k][j];
            }
        }
    }
}

// ����� ��ġ
void transposeMatrix(float mat[N][N], float result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = mat[j][i];
        }
    }
}

// ��Ľ� ���
float determinant(float mat[N][N]) {
    float det = 0;

    for (int i = 0; i < N; i++) {
        det += (mat[0][i] * (mat[1][(i + 1) % 3] * mat[2][(i + 2) % 3] - mat[1][(i + 2) % 3] * mat[2][(i + 1) % 3]));
    }

    return det;
}

// ����� ���
void inverseMatrix(float mat[N][N], float result[N][N]) {
    float det = determinant(mat);

    if (det == 0) {
        printf("������� �������� �ʽ��ϴ�.\n");
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = ((mat[(j + 1) % 3][(i + 1) % 3] * mat[(j + 2) % 3][(i + 2) % 3]) - (mat[(j + 1) % 3][(i + 2) % 3] * mat[(j + 2) % 3][(i + 1) % 3])) / det;
        }
    }
}

// mat1^(-1)�� ������� �´��� üũ
// ������� �´ٸ�,mat1*mat1^(-1)�� ���� ����� ��µǾ�� �Ѵ�.
void check_1(float mat1[N][N], float result[N][N], float result1[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result1[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result1[i][j] += mat1[i][k] * result[k][j];
            }
        }
    }
}

// mat2^(-1)�� ������� �´��� üũ
// ������� �´ٸ�,mat2*mat2^(-1)�� ���� ����� ��µǾ�� �Ѵ�.
void check_2(float mat2[N][N], float result[N][N], float result2[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result2[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result2[i][j] += mat2[i][k] * result[k][j];
            }
        }
    }
}

int main() {
    float mat1[N][N], mat2[N][N];

    printf("***** 3X3 ��Ľ� ���� *****\n");
    
    printf("\n");
    printf("ù ��° 3x3 ����� �Է��ϼ���:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%f", &mat1[i][j]);
        }
    }

    printf("\n");
    printf("�� ��° 3x3 ����� �Է��ϼ���:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%f", &mat2[i][j]);
        }
    }

    float result[N][N]; // ��� ���
    float result1[N][N], result2[N][N]; // ���1, 2 ���

    printf("\n");
    printf("�� ����� ���� ���:\n");
    addMatrices(mat1, mat2, result);
    printMatrix(result);

    printf("\n");
    printf("�� ����� ���� ���:\n");
    subtractMatrices(mat1, mat2, result);
    printMatrix(result);

    printf("\n");
    printf("�� ����� ���� ���:\n");
    multiplyMatrices(mat1, mat2, result);
    printMatrix(result);

    printf("\n");
    printf("ù ��° ����� ���� ���:\n");
    squareMatrices_1(mat1, result);
    printMatrix(result);

    printf("\n");
    printf("�� ��° ����� ���� ���:\n");
    squareMatrices_2(mat2, result);
    printMatrix(result);

    printf("\n");
    printf("ù ��° ����� ��ġ ���:\n");
    transposeMatrix(mat1, result);
    printMatrix(result);

    printf("\n");
    printf("�� ��° ����� ��ġ ���:\n");
    transposeMatrix(mat2, result);
    printMatrix(result);

    printf("\n");
    printf("ù ��° ����� ��Ľ�: %.2f\n", determinant(mat1));

    printf("\n");
    printf("�� ��° ����� ��Ľ�: %.2f\n", determinant(mat2));

    printf("\n");
    printf("ù ��° ����� �����:\n");
    inverseMatrix(mat1, result);
    printMatrix(result);

    printf("\n");
    printf("�� ��° ����� �����:\n");
    inverseMatrix(mat2, result);
    printMatrix(result);

    printf("\n");
    printf("ù ��° ����� ����� Ȯ��:\n");
    inverseMatrix(mat1, result);
    check_1(mat1, result, result1);
    printMatrix(result1);

    printf("\n");
    printf("�� ��° ����� ����� Ȯ��:\n");
    inverseMatrix(mat2, result);
    check_2(mat2, result, result2);
    printMatrix(result2);

    return 0;
}