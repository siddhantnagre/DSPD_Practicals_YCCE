#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNo;
    float AvgMarks;
    char grade;
};

void bubbleSort(struct Student s[], int n) {
    struct Student temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(s[j].AvgMarks < s[j + 1].AvgMarks) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];
    for(int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Roll No: ");
        scanf("%d", &s[i].rollNo);
        printf("Average Marks: ");
        scanf("%f", &s[i].AvgMarks);
        printf("Grade: ");
        scanf(" %c", &s[i].grade);
    }

    bubbleSort(s, n);

    printf("\nStudents sorted by Average Marks (Descending):\n");
    for(int i = 0; i < n; i++) {
        printf("%s\t%d\t%.2f\t%c\n", s[i].name, s[i].rollNo, s[i].AvgMarks, s[i].grade);
    }

    return 0;
}
