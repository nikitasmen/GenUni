#include <stdio.h>
#include <stdlib.h>

/*Δήλωση συνάρτησης count
 Η συνάρτηση παίρνει ως ορισμα ένα χαρακτήρα x[i] απο την συμβολοσειρα x
*/
int count(char x);

//Αρχή της κύριας συνάρτησης main()
int main(int argc, char const *argv[])
{

	char x[100]; 
	int i , sum = 0 ; 

	//Εισοδος της σημβολοσειράς από τον χρήστη 
	printf("Enter mathematical expression");
	gets(x);

	//Δομή επανάληψης do while 
	//Η δομή τερματίζει όταν τελειώσει η συμβολοσειρα ή όταν η μεταβλητή sum πάρει τιμή -1
	do
	{	
	
		sum+=count(x[i]);
		i++;
		
	}while((x[i]!= '\0')&&(sum>-1));
	
	//Αν το sum ειναι < 0 τότε λείπει απο την συμβολοσειρα ο χαρακτηρας '('
	//Αν το sum ειναι < 0 τότε λείπει απο την συμβολοσειρα ο χαρακτηρας '('
	//Αλλιώς το sum ειναι 0 οπότε η μαθηματική έκφραση ειναι σωστή 
	if(sum<0)
		printf("\nThe expression is Wrong. Right parenthesis found first\n");
	else if (sum>0)
		printf("\nThe expression is Wrong. One Left parenthesis missing\n");
	else 
		printf("\nThe expression is correct\n");


	system("pause");
	return 0;
}

//Αρχή της συνάρτησης count
int count(char x)
{
	//Έλενχος του χαρακτήρα επιστρέφοντας την κατάλληλη τιμή 
	if(x=='(')
		return 1 ; 
	else if (x==')')
		return -1 ; 
	return 0;
}