#include <stdio.h>

int binarySearch(int SearchList[], int n, int target) {
    if (SearchList == NULL || n == 0)
        return 0;  // Changed from NULL to 0

    int start = 0, end = n - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        printf("Middle value: %d\n", SearchList[mid]);

        if (SearchList[mid] == target)
            return 1;

        if (target > SearchList[mid]) {
            start = mid + 1;
            printf("Adjusting start to index: %d\n", start);
        } else {
            end = mid - 1;
            printf("Adjusting end to index: %d\n", end);
        }
    }

    return 0;  // Changed from NULL to 0
}

int main() {
    int SearchList[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(SearchList) / sizeof(SearchList[0]);
    int target = 10;

    int result = binarySearch(SearchList, n, target);
    if (result)
        printf("Value found!\n");
    else
        printf("Value not found or invalid input.\n");

    return 0;
}
