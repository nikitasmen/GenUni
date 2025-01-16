
#include <stdio.h>
#include <stdlib.h>

char str[100];

//Δήλωση σύναρτησης num_of_times. Η συναρτηση επιστρέφει τον αριθμό των φορών που εμφανίζεται ο δοσμένος χαρακτήρας στην συμβολοσειρα
int num_of_times(char str[] , char a );

//αρχή της κύριας συνάρτησης του προγράμματος 
int main(int argv , char* argc[])
{
	
	char a ; 
	
	printf("Enter string");
	//χρήση της συνάρτησης fgets για την αποθήκευση της σειβμολοσειρας στην μεταβλητη str
	fgets(str , sizeof(str),stdin );

	printf("\nEnter character"); 
	scanf("%c", &a);

	printf("\nThe character repeats in the string: %d times.", num_of_times( str,  a));
	
	system("pause");
	
	return 0;
}

//Αρχή σύναρτησης num_of_times. Η συναρτηση επιστρέφει τον αριθμό των φορών που εμφανίζεται ο δοσμένος χαρακτήρας στην συμβολοσειρα
int num_of_times(char str[] , char a)
{
	int count = 0 ;
	//επαναληπτική δομή for για να πάρουμε εναν προς έναν τους χαρακτήρες της συμβολοσειράς
	for(int i = 0 ; str[i]!='\0';  ++i)
	{
		//έλενχος για το άν ο δοσμένος χαρακτήρας ειναι ίσος με τον i χαρακτήρα της  συμβολοσειράς και άν ναι τότε ο μετρητής αυξάνει κατα ένα
		count +=(a==str[i])?1:0;
	}

	return count;
}