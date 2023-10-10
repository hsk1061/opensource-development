#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 3

// 행렬 출력 함수
void printMatrix(float mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f ", mat[i][j]);
        }
        printf("\n");
    }
}

// 두 행렬의 덧셈
void addMatrices(float mat1[N][N], float mat2[N][N], float result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// 두 행렬의 뺄셈
void subtractMatrices(float mat1[N][N], float mat2[N][N], float result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// 두 행렬의 곱셈
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

// 첫 번째 행렬의 제곱
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

// 두 번째 행렬의 제곱
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

// 행렬의 전치
void transposeMatrix(float mat[N][N], float result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = mat[j][i];
        }
    }
}

// 행렬식 계산
float determinant(float mat[N][N]) {
    float det = 0;

    for (int i = 0; i < N; i++) {
        det += (mat[0][i] * (mat[1][(i + 1) % 3] * mat[2][(i + 2) % 3] - mat[1][(i + 2) % 3] * mat[2][(i + 1) % 3]));
    }

    return det;
}

// 역행렬 계산
void inverseMatrix(float mat[N][N], float result[N][N]) {
    float det = determinant(mat);

    if (det == 0) {
        printf("역행렬이 존재하지 않습니다.\n");
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = ((mat[(j + 1) % 3][(i + 1) % 3] * mat[(j + 2) % 3][(i + 2) % 3]) - (mat[(j + 1) % 3][(i + 2) % 3] * mat[(j + 2) % 3][(i + 1) % 3])) / det;
        }
    }
}

// mat1^(-1)이 역행렬이 맞는지 체크
// 역행렬이 맞다면,mat1*mat1^(-1)은 단위 행렬이 출력되어야 한다.
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

// mat2^(-1)이 역행렬이 맞는지 체크
// 역행렬이 맞다면,mat2*mat2^(-1)은 단위 행렬이 출력되어야 한다.
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

    printf("***** 3X3 행렬식 계산기 *****\n");
    
    printf("\n");
    printf("첫 번째 3x3 행렬을 입력하세요:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%f", &mat1[i][j]);
        }
    }

    printf("\n");
    printf("두 번째 3x3 행렬을 입력하세요:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%f", &mat2[i][j]);
        }
    }

    float result[N][N]; // 결과 행렬
    float result1[N][N], result2[N][N]; // 결과1, 2 행렬

    printf("\n");
    printf("두 행렬의 덧셈 결과:\n");
    addMatrices(mat1, mat2, result);
    printMatrix(result);

    printf("\n");
    printf("두 행렬의 뺄셈 결과:\n");
    subtractMatrices(mat1, mat2, result);
    printMatrix(result);

    printf("\n");
    printf("두 행렬의 곱셈 결과:\n");
    multiplyMatrices(mat1, mat2, result);
    printMatrix(result);

    printf("\n");
    printf("첫 번째 행렬의 제곱 결과:\n");
    squareMatrices_1(mat1, result);
    printMatrix(result);

    printf("\n");
    printf("두 번째 행렬의 제곱 결과:\n");
    squareMatrices_2(mat2, result);
    printMatrix(result);

    printf("\n");
    printf("첫 번째 행렬의 전치 행렬:\n");
    transposeMatrix(mat1, result);
    printMatrix(result);

    printf("\n");
    printf("두 번째 행렬의 전치 행렬:\n");
    transposeMatrix(mat2, result);
    printMatrix(result);

    printf("\n");
    printf("첫 번째 행렬의 행렬식: %.2f\n", determinant(mat1));

    printf("\n");
    printf("두 번째 행렬의 행렬식: %.2f\n", determinant(mat2));

    printf("\n");
    printf("첫 번째 행렬의 역행렬:\n");
    inverseMatrix(mat1, result);
    printMatrix(result);

    printf("\n");
    printf("두 번째 행렬의 역행렬:\n");
    inverseMatrix(mat2, result);
    printMatrix(result);

    printf("\n");
    printf("첫 번째 행렬의 역행렬 확인:\n");
    inverseMatrix(mat1, result);
    check_1(mat1, result, result1);
    printMatrix(result1);

    printf("\n");
    printf("두 번째 행렬의 역행렬 확인:\n");
    inverseMatrix(mat2, result);
    check_2(mat2, result, result2);
    printMatrix(result2);

    return 0;
}