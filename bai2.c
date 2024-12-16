//
//  bai2.c
//  codeC
//
//  Created by USED on 16/12/24.
//
#include <stdio.h>

#define MAX 100

// Hàm khởi tạo ma trận kề với tất cả phần tử là 0
void initializeMatrix(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
}

// Hàm kiểm tra tính đối xứng của ma trận kề
int isSymmetric(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0;
            }
        }
    }
    return 1; // Đối xứng
}

// Hàm in ma trận kề
void printMatrix(int matrix[MAX][MAX], int n) {
    printf("\nMa trận kề của đồ thị:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Hàm chính
int main() {
    int matrix[MAX][MAX];
    int n, edges;
    int u, v;

    // Nhập số lượng đỉnh và số lượng cạnh
    printf("Nhập số lượng đỉnh của đồ thị: ");
    scanf("%d", &n);

    printf("Nhập số lượng cạnh của đồ thị: ");
    scanf("%d", &edges);

    // Khởi tạo ma trận kề
    initializeMatrix(matrix, n);

    // Nhập danh sách các cạnh
    printf("Nhập danh sách các cạnh (đỉnh1 đỉnh2):\n");
    for (int i = 0; i < edges; i++) {
        printf("Cạnh %d: ", i + 1);
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < n && v >= 0 && v < n) {
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        } else {
            printf("Cạnh không hợp lệ! Vui lòng nhập lại.\n");
            i--; 
        }
    }

    // In ma trận kề
    printMatrix(matrix, n);

    // Kiểm tra tính đối xứng
    if (isSymmetric(matrix, n)) {
        printf("\nMa trận kề đối xứng. Đồ thị là vô hướng.\n");
    } else {
        printf("\nMa trận kề không đối xứng.\n");
    }

    return 0;
}

