#include <stdio.h>
#include <stdlib.h>

// Συνάρτηση foo
void foo(int A[][2], int num, int** B, int* unique_students_count) {
    int i, j;

    int* unique_students = malloc(num * sizeof(int));
    int unique_count = 0;

    for (i = 0; i < num; i++) {
        int exists = 0;
        for (j = 0; j < unique_count; j++) {
            if (unique_students[j] == A[i][0]) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            unique_students[unique_count++] = A[i][0];
        }
    }

    *B = malloc(unique_count * 2 * sizeof(int));

    for (i = 0; i < unique_count; i++) {
        int student_id = unique_students[i];
        int total_grades = 0, count = 0;

        for (j = 0; j < num; j++) {
            if (A[j][0] == student_id) {
                total_grades += A[j][1];
                count++;
            }
        }

        (*B)[i * 2] = student_id;
        (*B)[i * 2 + 1] = total_grades / count;
    }

    int grade_count[101] = {0};
    for (i = 0; i < num; i++) {
        grade_count[A[i][1]]++;
    }

    for (i = 0; i <= 100; i++) {
        if (grade_count[i] > 0) {
            printf("O vathmos %d , yparxei %d fores \n", i, grade_count[i]);
        }
    }

    *unique_students_count = unique_count;
}

int main() {
    int A[][2] = {
        {101, 85}, {102, 90}, {101, 75}, {103, 60}, {102, 95},
        {101, 80}, {103, 60}, {102, 85}, {101, 90}, {103, 70}
    };
    int num = sizeof(A) / sizeof(A[0]);

    int* B;
    int unique_students_count;
    foo(A, num, &B, &unique_students_count);

    for (int i = 0; i < unique_students_count; i++) {
        printf("Mathitis: %d, mesos oros: %d\n", B[i * 2], B[i * 2 + 1]);
    }


    return 0;
}
