#include <stdio.h>
#define LAB_FEE 2000
#define CREDIT_FEE 5000

int main() {
    int id, credits, total_students = 0;
    double cgpa, fee, total_fees = 0, max_fee = 0, min_fee = 99999999;
    double semester_fees[1000]; // assuming no more than 1000 students
    printf("Enter Student ID, CGPA and Credits enrolled: ");
    scanf("%d %lf %d", &id, &cgpa, &credits);

    while (id != -1 && cgpa != -1 && credits != -1) {
        if (credits >= 12) {
            fee = credits * CREDIT_FEE + LAB_FEE;
            if (cgpa >= 3.75) {
                fee = fee * 0.25;
            } else if (cgpa >= 3.5) {
                fee = fee * 0.6;
            }
        } else {
            fee = credits * CREDIT_FEE + LAB_FEE;
        }
        semester_fees[total_students] = fee;
        total_fees += fee;
        if (fee > max_fee) {
            max_fee = fee;
        }
        if (fee < min_fee) {
            min_fee = fee;
        }
        total_students++;
        printf("Enter Student ID, CGPA and Credits enrolled: ");
        scanf("%d %lf %d", &id, &cgpa, &credits);
    }
    printf("Total amount paid by all students: %.2lf\n", total_fees);
    printf("Average amount paid by students : %.2lf\n", total_fees / total_students);
    printf("Highest amount paid by a student: %.2lf\n", max_fee);
    printf("Lowest amount paid by a student : %.2lf\n", min_fee);
    return 0;
}

