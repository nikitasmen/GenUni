#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(int argc, char const *argv[])
{
    clock_t start , end ; 
    double full_time ; 

    const int arraySize = 200000;
    int a[arraySize];
    int b[arraySize];
    int c[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        a[i] = rand()%100;
        b[i] = rand()%100;
        c[i] = 0;
    }
    start = clock(); 
    for (int i = 0 ; i<arraySize ; i++)
    {
        c[i] = a[i] + b[i];
    }

    end = clock(); 
    full_time = (double) (end-start)/CLOCKS_PER_SEC;

    printf("%lf",full_time);
    system("pause");
    return 0;
}

