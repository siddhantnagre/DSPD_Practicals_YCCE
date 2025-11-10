#include <stdio.h>
#include <string.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = value;
    printf("%d pushed to stack.\n", value);
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("%d popped from stack.\n", stack[top--]);
}

// Display stack
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

// Palindrome check using stack
void checkPalindrome() {
    char str[100], rev[100];
    int i, len;
    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);
    top = -1;

    for (i = 0; i < len; i++)
        stack[++top] = str[i];

    for (i = 0; i < len; i++)
        rev[i] = stack[top--];
    rev[len] = '\0';

    if (strcmp(str, rev) == 0)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");
}

// Overflow and Underflow demo
void demoOverflowUnderflow() {
    top = MAX - 1;
    printf("Trying to push on full stack:\n");
    push(999); // Should trigger overflow

    top = -1;
    printf("Trying to pop from empty stack:\n");
    pop(); // Should trigger underflow
}

int main() {
    int choice, value;

    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Check Palindrome\n4. Overflow/Underflow Demo\n5. Display Stack\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                demoOverflowUnderflow();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
