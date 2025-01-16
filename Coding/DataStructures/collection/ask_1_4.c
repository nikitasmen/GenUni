#include <stdio.h>
#include <stdlib.h>

void enterData(int a[][4], int b[][4]);
void sum(int a[][4], int b[][4], int s[][4]);
void display(int a[][4], int b[][4], int s[][4]);

int main(){
	int firstMatrix[3][4], secondMatrix[3][4], s[3][4];
    enterData(firstMatrix, secondMatrix);  
    sum(firstMatrix, secondMatrix, s);     
    display(firstMatrix, secondMatrix, s); 
	return 0;
}


void enterData(int a[][4], int b[][4]){

	for(int i = 0; i <=2 ; ++i){
		for(int j = 0; j <=3 ; ++j){
			b[i][j] = rand()%(25-15+1)+15;

			printf("Enter element a[%d][%d]: ", i + 1, j + 1);
			scanf("%d", &a[i][j]);
		}
	}
}

void sum(int a[][4], int b[][4], int s[][4]){
	for(int i = 0; i <=2; ++i){
		for(int j = 0; j <=3; ++j){
			s[i][j] = a[i][j] + b[i][j];
		}
	}
}

void display(int a[][4], int b[][4],int s[][4]){
	int i, j;
	printf("\nMatrix 1:\n");
	for(i = 0; i <=2; ++i){
		for(j = 0; j <=3; ++j){
			printf("%d  ", a[i][j]);
			if(j == 3)
				printf("\n\n");
		}
	}
	printf("\nMatrix 2:\n");
	for(i = 0; i <=2; ++i){
		for(j = 0; j <=3; ++j){
			printf("%d  ", b[i][j]);
			if(j == 3)
				printf("\n\n");
		}
	}
	printf("\nMatrix 3(sum of matrix 1 and matrix 2):\n");
	for(i = 0; i <=2; ++i){
		for(j = 0; j <=3; ++j){
			printf("%d  ", s[i][j]);
			if(j == 3)
				printf("\n\n");
		}
	}
}