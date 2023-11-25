#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int numNodes;
    int adjacencyMatrix[MAX_NODES][MAX_NODES];
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
        for (int j = 0; j < n; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

void displayMatrix(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numNodes; i++) {
        for (int j = 0; j < graph->numNodes; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void displayList(struct Graph* graph) {
    printf("Adjacency List:\n");
    for (int i = 0; i < graph->numNodes; i++) {
        printf("Node %d: ", i);
        struct Node* current = graph->adjacencyList[i];
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

void deleteGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        struct Node* current = graph->adjacencyList[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph);
}

int main() {
    int numNodes, numEdges;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);
    struct Graph* graph = createGraph(numNodes);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    displayMatrix(graph);
    displayList(graph);
    deleteGraph(graph);
    return 0;
}
