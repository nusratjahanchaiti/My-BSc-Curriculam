#include <stdio.h>

int main() {
    int numSubjects, totalMarks = 0;
    printf("Enter the number of subjects: ");
    scanf("%d", &numSubjects);

    int marks[numSubjects];
    for (int i = 0; i < numSubjects; i++) {
        printf("Enter the marks for subject %d: ", i+1);
        scanf("%d", &marks[i]);
        totalMarks += marks[i];
    }
    printf("Subject-wise marks:\n");
    for (int i = 0; i < numSubjects; i++) {
        printf("Subject %d: %d\n", i+1, marks[i]);
    }

    printf("Total marks: %d\n", totalMarks);

    return 0;
}



