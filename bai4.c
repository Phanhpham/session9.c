//
//  bai4.c
//  codeC
//
//  Created by USED on 16/12/24.
//
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node cho danh sách kề
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Định nghĩa cấu trúc đồ thị
typedef struct Graph {
    int numVertices;     // Số đỉnh
    Node** adjLists;     // Mảng các danh sách kề
    int* visited;        // Mảng đánh dấu các đỉnh đã duyệt
} Graph;

// Hàm tạo một đỉnh mới trong danh sách kề
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Hàm tạo đồ thị
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Hàm thêm cạnh vào đồ thị
void addEdge(Graph* graph, int src, int dest) {
    // Thêm đỉnh dest vào danh sách kề của đỉnh src
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Thêm đỉnh src vào danh sách kề của đỉnh dest (đồ thị vô hướng)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Hàm thực hiện BFS
void BFS(Graph* graph, int startVertex) {
    int queue[100];  // Hàng đợi để lưu các đỉnh đang chờ xử lý
    int front = 0, rear = 0;

    // Đánh dấu đỉnh bắt đầu là đã duyệt và thêm vào hàng đợi
    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("Thứ tự duyệt BFS: ");

    while (front < rear) {
        int currentVertex = queue[front++];  // Lấy đỉnh từ hàng đợi
        printf("%d ", currentVertex);

        // Duyệt tất cả các đỉnh kề của đỉnh hiện tại
        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;

            // Nếu đỉnh kề chưa được duyệt, thêm vào hàng đợi
            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Hàm in danh sách kề
void printGraph(Graph* graph) {
    printf("\nDanh sách kề của đồ thị:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        printf("Đỉnh %d: ", i);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Hàm chính
int main() {
    int vertices, edges, startVertex;
    int src, dest;

    // Nhập số lượng đỉnh và cạnh
    printf("Nhập số lượng đỉnh: ");
    scanf("%d", &vertices);
    printf("Nhập số lượng cạnh: ");
    scanf("%d", &edges);

    // Tạo đồ thị
    Graph* graph = createGraph(vertices);

    // Nhập danh sách các cạnh
    printf("Nhập danh sách các cạnh (đỉnh1 đỉnh2):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // In danh sách kề
    printGraph(graph);

    // Nhập đỉnh bắt đầu và thực hiện BFS
    printf("\nNhập đỉnh bắt đầu để thực hiện BFS: ");
    scanf("%d", &startVertex);
    BFS(graph, startVertex);

    return 0;
}
