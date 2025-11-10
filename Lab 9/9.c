#include <stdio.h>
#define SIZE 7

int main() {
    int hashTable[SIZE];
    int keys[] = {10, 20, 5, 15, 7, 32}; // Example keys
    int n = sizeof(keys) / sizeof(keys[0]);

    // Initialize table
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    // Insert keys
    for (int i = 0; i < n; i++) {
        int key = keys[i];
        int index = key % SIZE;

        // Linear probing for collision resolution
        while (hashTable[index] != -1) {
            index = (index + 1) % SIZE;
        }
        hashTable[index] = key;
    }

    // Display final hash table
    printf("Final Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            printf("Slot %d: Empty\n", i);
        else
            printf("Slot %d: %d\n", i, hashTable[i]);
    }

    return 0;
}
