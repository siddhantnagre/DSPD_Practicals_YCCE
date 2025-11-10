#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int adj[MAX][MAX]; // Adjacency matrix
int visited[MAX];

// Queue for BFS
int queue[MAX], front = 0, rear = 0;
void enqueue(int val) { queue[rear++] = val; }
int dequeue() { return queue[front++]; }
int isQueueEmpty() { return front == rear; }

// Stack for DFS
int stack[MAX], top = -1;
void push(int val) { stack[++top] = val; }
int pop() { return stack[top--]; }
int isStackEmpty() { return top == -1; }

// Build adjacency matrix for 3x3 grid
void buildGraph() {
    for (int i = 1; i <= 9; i++) {
        if (i - 3 >= 1) adj[i][i - 3] = 1; // Up
        if (i + 3 <= 9) adj[i][i + 3] = 1; // Down
        if (i % 3 != 1) adj[i][i - 1] = 1; // Left
        if (i % 3 != 0) adj[i][i + 1] = 1; // Right
    }
}

// BFS traversal
void bfs(int start) {
    for (int i = 0; i < MAX; i++) visited[i] = 0;
    front = rear = 0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Order: ");
    while (!isQueueEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 1; i <= 9; i++) {
            if (adj[node][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS traversal
void dfs(int start) {
    for (int i = 0; i < MAX; i++) visited[i] = 0;
    top = -1;

    push(start);

    printf("DFS Order: ");
    while (!isStackEmpty()) {
        int node = pop();
        if (!visited[node]) {
            printf("%d ", node);
            visited[node] = 1;

            // Push neighbors in reverse order for correct DFS tie-breaking
            for (int i = 9; i >= 1; i--) {
                if (adj[node][i] && !visited[i]) {
                    push(i);
                }
            }
        }
    }
    printf("\n");
}

int main() {
    buildGraph();
    bfs(1);
    dfs(1);
    return 0;
}
