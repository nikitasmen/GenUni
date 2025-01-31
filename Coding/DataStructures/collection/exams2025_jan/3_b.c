
int* searchFloatIndexes(const float arr[], int N, float x) {
    int* positions = (int*)malloc(N * sizeof(int)); // Allocate memory for result array
    int count = 0;

    // Initialize all positions to -1
    for (int i = 0; i < N; i++) {
        positions[i] = -1;
    }

    // Search for x in the array
    for (int i = 0; i < N; i++) {
        if (arr[i] == x) {
            positions[count++] = i;
        }
    }

    return positions; // Return pointer to the array
}

int main() {
    float arr[] = {1.2, 3.4, 5.6, 1.2, 7.8, 1.2};
    int N = sizeof(arr) / sizeof(arr[0]);
    float x = 1.2;

    int* result = searchFloatIndexes(arr, N, x);

    printf("Indexes where %.1f appears: ", x);
    for (int i = 0; i < N && result[i] != -1; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result); // Free allocated memory
    return 0;
}
