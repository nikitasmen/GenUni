#include <stdio.h>
#include <stdlib.h>

//Δήλωση συναρτήσεων
void enterData(int a[][4], int b[][4]);
void sum(int a[][4], int b[][4], int s[][4]);
void display(int a[][4], int b[][4], int s[][4]);

//Αρχή της κύριας συνάρτησης 
int main()
{
	//δήλωση των πινάκων
	int firstMatrix[3][4], secondMatrix[3][4], s[3][4];

		//κλήση συναρτήσεων

        enterData(firstMatrix, secondMatrix);  //συνάρτηση για την είσοδο δεδομένων
        sum(firstMatrix, secondMatrix, s);     //συνάρτηση για την πρόσθεση των δύο πινάκων
        display(firstMatrix, secondMatrix, s); //συνάρτηση για την εμφάνιση των πινάκων

        system("pause");

	return 0;
}


void enterData(int a[][4], int b[][4])
{

	for(int i = 0; i <=2 ; ++i)
	{
		for(int j = 0; j <=3 ; ++j)
		{
			// τα στοιχεία του 2ου πίνακα πέρνουν τυχαία τιμη με την βοήθεια της συνάρτησης rand()
			//το εύρος των τυχαίων τιμών βρισκεται ως εξής :το ακαίρεο υπόλυπο του τυχαίου αριθμου προς τη (μεγιστη τιμη -ελάχιστη τιμη +1). Σε αυτό το αποτέλεσμα προσθέτουμε +15 
			b[i][j] = rand()%(25-15+1)+15;

			//ο χρήστης δίνει ένα ένα τα στοιχεία του πίνακα 1 
			printf("Enter element a[%d][%d]: ", i + 1, j + 1);
			scanf("%d", &a[i][j]);
		}
	}
}

void sum(int a[][4], int b[][4], int s[][4])
{

	//Πρόσθεση των στοιχείων του πίνακα a και b 
	for(int i = 0; i <=2; ++i)
	{
		for(int j = 0; j <=3; ++j)
		{
			s[i][j] = a[i][j] + b[i][j];
		}
	}
}

void display(int a[][4], int b[][4],int s[][4])
{
	int i, j;

	//εμφάνιση των τριών πινάκων
	printf("\nMatrix 1:\n");
	for(i = 0; i <=2; ++i)
	{
		for(j = 0; j <=3; ++j)
		{
			printf("%d  ", a[i][j]);
			if(j == 3)
			printf("\n\n");
		}
	}
	printf("\nMatrix 2:\n");
	for(i = 0; i <=2; ++i)
	{
		for(j = 0; j <=3; ++j)
		{
			printf("%d  ", b[i][j]);
			if(j == 3)
				printf("\n\n");
		}
	}
	printf("\nMatrix 3(sum of matrix 1 and matrix 2):\n");
	for(i = 0; i <=2; ++i)
	{
		for(j = 0; j <=3; ++j)
		{
			printf("%d  ", s[i][j]);
			if(j == 3)
				printf("\n\n");
		}
	}
}
