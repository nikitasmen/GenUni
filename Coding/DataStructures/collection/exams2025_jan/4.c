#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int main() {
    FILE *file = fopen("struct.dat", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int numbers[SIZE];
    size_t readCount = fread(numbers, sizeof(int), SIZE, file);
    if (readCount < SIZE) {
        printf("Warning: Only %zu integers were read from the file.\n", readCount);
    }

    fclose(file);

    printf("Read numbers:\n");
    for (size_t i = 0; i < readCount; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
