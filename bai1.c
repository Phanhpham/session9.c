//
//  bai1.c
//  codeC
//
//  Created by USED on 16/12/24.
//

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

// bien toan cuc
int matrix[MAX][MAX];
int numVertices=0;

// danh sach ke - moi dinh luu 1 danh sach cac canh
typedef struct Node {
    int vertex;
    struct Node* next;
}Node;

Node* adjList[MAX];

// ham khoi tao do thi
void initGraph(){
    for (int i=0;i< MAX; i++) {
        adjList[i]=NULL;
        for (int j=0; j<MAX; j++) {
            matrix[i][j]=0;
        }
    }
}

// ham them dinh
void addVertex(){
    if (numVertices<MAX) {
        numVertices++;
        printf("Đã thêm đỉnh %d vào đồ thị.\n", numVertices - 1);
    } else {
           printf("Không thể thêm đỉnh mới, đã đạt giới hạn.\n");
       }
   }
//ham tao nut moi danh sach ke
Node* createNode(int vertex){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->vertex=vertex;
    newNode->next=NULL;
    return newNode;
}

// Hàm thêm cạnh vào đồ thị
void addEdge(int src, int dest, int isDirected) {
    if (src >= numVertices || dest >= numVertices) {
        printf("Đỉnh không hợp lệ.\n");
        return;
    }

    // Thêm vào ma trận kề
    matrix[src][dest] = 1;
    if (!isDirected) {
        matrix[dest][src] = 1; // Nếu là đồ thị vô hướng
    }

    // Thêm vào danh sách kề
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    if (!isDirected) { // Nếu là đồ thị vô hướng, thêm cạnh ngược lại
        newNode = createNode(src);
        newNode->next = adjList[dest];
        adjList[dest] = newNode;
    }
}

// Hàm hiển thị ma trận kề
void displayMatrix() {
    printf("\nMa trận kề của đồ thị:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Hàm hiển thị danh sách kề
void displayAdjList() {
    printf("\nDanh sách kề của đồ thị:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("Đỉnh %d: ", i);
        Node* temp = adjList[i];
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Hàm main
int main() {
    int choice, src, dest, isDirected;

    initGraph();

    while (1) {
        printf("\n========== Menu ==========\n");
        printf("1. Thêm đỉnh\n");
        printf("2. Thêm cạnh\n");
        printf("3. Hiển thị ma trận kề\n");
        printf("4. Hiển thị danh sách kề\n");
        printf("5. Thoát\n");
        printf("Chọn thao tác: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addVertex();
                break;
            case 2:
                printf("Nhập đỉnh nguồn: ");
                scanf("%d", &src);
                printf("Nhập đỉnh đích: ");
                scanf("%d", &dest);
                printf("Đồ thị có hướng? (1: Có, 0: Không): ");
                scanf("%d", &isDirected);
                addEdge(src, dest, isDirected);
                break;
            case 3:
                displayMatrix();
                break;
            case 4:
                displayAdjList();
                break;
            case 5:
                printf("Kết thúc chương trình.\n");
                exit(0);
            default:
                printf("Lựa chọn không hợp lệ. Vui lòng thử lại!\n");
        }
    }
    return 0;
}
  
