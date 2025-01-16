#include <stdio.h>
#include<stdlib.h>

union un {
    int x;
    char y;
    float z;
};

int menu();
union un push(union un stack[], int i);
int pop(int i);

int main() {
    union un stack[10];
    int i;
    int stacktop = -1;

    do {
        i = menu();

        switch (i) {
            case 1:
                if (stacktop < 9) {  // Check stack overflow
                    printf("eisagogh\n");
                    stacktop++;
                    stack[stacktop] = push(stack, stacktop);
                } else {
                    printf("Stack full\n");
                }
                break;
            case 2:
                if (stacktop >= 0) {  // Check stack underflow
                    printf("diagrafh\n");
                    stacktop = pop(stacktop);
                } else {
                    printf("Stack empty\n");
                }
                break;
            case 3:
                printf("emfanish\n");
                int j ; 
                for ( j = 0; j <= stacktop; j++) {
                    printf("Element %d: x=%d, z=%.2f, y=%c\n", j, stack[j].x, stack[j].z, stack[j].y);
                }
                break;
            case 4:
                printf("anazitish not implemented\n");
                break;
            case 0:
                printf("ejodos\n");
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (i != 0);

    return 0;
}

int pop(int i) {
    return i - 1;
}

int menu() {
    int i;
    printf("1. eisagogh\n");
    printf("2. diagrafh\n");
    printf("3. emfanish\n");
    printf("4. anazitish\n");
    printf("0. ejodos\n");
    printf("dose epilogh \n");
    scanf("%d", &i);
    return i;
}

union un push(union un stack[], int i) {
    printf("dose arithmo: ");
    scanf("%d", &stack[i].x);
    printf("dose dekatiko: ");
    scanf("%f", &stack[i].z);
    getchar();
    printf("dose xaraktira: \n");
    stack[i].y = getchar();
    return stack[i];
}