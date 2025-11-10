#include <stdio.h>
#define MAX 100

char queue[MAX];
int front = -1, rear = -1;

// Insert operation
void insert(char ch) {
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = ch;
    printf("Inserted '%c' into queue.\n", ch);
}

// Delete operation
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Deleted '%c' from queue.\n", queue[front++]);
}

// Display queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = front; i <= rear; i++)
        printf("%c ", queue[i]);
    printf("\n");
}

// Overflow and Underflow demo
void demoOverflowUnderflow() {
    rear = MAX - 1;
    printf("Trying to insert on full queue:\n");
    insert('X'); // Should trigger overflow

    front = rear + 1;
    printf("Trying to delete from empty queue:\n");
    delete(); // Should trigger underflow

    // Reset for normal use
    front = rear = -1;
}

int main() {
    int choice;
    char ch;

    do {
        printf("\n--- Queue Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Overflow/Underflow Demo\n4. Display Queue\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &ch);
                insert(ch);
                break;
            case 2:
                delete();
                break;
            case 3:
                demoOverflowUnderflow();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
