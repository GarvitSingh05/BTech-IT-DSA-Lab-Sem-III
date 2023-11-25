#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NODES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int numNodes;
    struct Node* adjacencyList[MAX_NODES];
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int n) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numNodes = n;
    for (int i = 0; i < n; i++) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

void BFS(struct Graph* graph, int startNode) {
    bool visited[MAX_NODES] = {false};
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    visited[startNode] = true;
    queue[rear++] = startNode;
    printf("BFS Traversal starting from node %d: ", startNode);
    while (front < rear) {
        int currentNode = queue[front++];
        printf("%d ", currentNode);
        struct Node* temp = graph->adjacencyList[currentNode];
        while (temp != NULL) {
            int neighbor = temp->data;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void DFSRecursive(struct Graph* graph, int currentNode, bool visited[]) {
    visited[currentNode] = true;
    printf("%d ", currentNode);
    struct Node* temp = graph->adjacencyList[currentNode];
    while (temp != NULL) {
        int neighbor = temp->data;
        if (!visited[neighbor]) {
            DFSRecursive(graph, neighbor, visited);
        }
        temp = temp->next;
    }
}

void DFS(struct Graph* graph, int startNode) {
    bool visited[MAX_NODES] = {false};
    printf("DFS Traversal starting from node %d: ", startNode);
    DFSRecursive(graph, startNode, visited);
    printf("\n");
}

int main() {
    int numNodes = 6;
    struct Graph* graph = createGraph(numNodes);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);
    int startNode = 0;
    BFS(graph, startNode);
    DFS(graph, startNode);
    for (int i = 0; i < numNodes; i++) {
        struct Node* current = graph->adjacencyList[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph);
    return 0;
}
