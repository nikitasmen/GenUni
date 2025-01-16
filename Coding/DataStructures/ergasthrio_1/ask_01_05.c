#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//δήλωση συναρτήσεων circle και square
void circle();
void square();

//Αρχή σύναρτησης main
int main(int argv , int *argc[])
{
	int choise; 

	//Επαναληπτική δομή do while.
	//Επαναληψη μέχρις ότου ο χρήστης να δώσει αποδεκτές τιμές (1 ή 2) 
	do 
	{
		//Είσοδος επολιγής από τον χρήστη
		printf("Press :\n1. to calculate the area of a circle\n2. to calculate the area of a square \n\n: ");
		scanf("%d",&choise);

	}while((choise!= 1)&&(choise!=2));

	switch (choise){

		case 1: 
			//Αν ο χρήστης δώσει 1 το πρόγραμμα υπολογίζει εμβαδόν κύκλου
			circle();
			break;

		case 2 : 
			//Αν ο χρήστης δώσει 2 το πρόγραμμα υπολογίζει εμβαδόν τετραγώνου
			square();
			break;
	}

	system("pause");
	return 0;

}

//Αρχη συνάρτησης υπολογισμού εμβαδού του τετραγώνου 
void square()
{
	float side ; 
	//Είσοδος μήκους πλεύρας τετραγώνου από τον χρήστη
	printf("\nEnter the lenght of a side of the square:"); 
	scanf("%f", &side);
	
	//Εμφάνιση αποτελέσματος προς τον χρήστη 
	printf("\nThe area of the square is %g * %g = %g meters^2\n\n", side , side , (side *side));
}

//Αρχη συνάρτησης υπολογισμού εμβαδού του κύκλου
void circle()
{
	float rad; 

	//Είσοδος ακτίνας του κύκλου από τον χρήστη
	printf("\nEnter the radius of the circle :"); 
	scanf("%f", &rad);
	
	//Εμφάνιση αποτελέσματος προς τον χρήστη 
	printf("The area of the circle is %g^2 pi = %g\n\n", rad,(M_PI*(rad*rad)));

}