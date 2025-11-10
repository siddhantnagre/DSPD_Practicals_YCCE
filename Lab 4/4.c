#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int num, count = 0;

    printf("Enter integers (0 to stop):\n");
    while (1) {
        scanf("%d", &num);
        if (num == 0)
            break;

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = num;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    printf("\nLinked List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d => ", temp->data);
        count++;
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Total number of nodes: %d\n", count);

    return 0;
}
