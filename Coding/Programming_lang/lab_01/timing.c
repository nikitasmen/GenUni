#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000  // Μέγεθος πίνακα

void initialize_by_rows(int *matrix, int size); 
void initialize_by_columns(int *matrix, int size);

int main() {
    int *arr = (int*)malloc(N * N * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    clock_t start, end;
    double time_taken;

    // Αρχικοποίηση κατά γραμμές
    start = clock();
    initialize_by_rows(arr, N);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for row-wise initialization: %f seconds\n", time_taken);

    // Αρχικοποίηση κατά στήλες
    start = clock();
    initialize_by_columns(arr, N);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for column-wise initialization: %f seconds\n", time_taken);

    free(arr);
    return 0;
}

void initialize_by_rows(int *matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i * size + j] = 0;
        }
    }
}

void initialize_by_columns(int *matrix, int size) {
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            matrix[i * size + j] = 0;
        }
    }
}