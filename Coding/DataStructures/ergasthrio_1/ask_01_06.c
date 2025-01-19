#include <stdio.h>
#include <stdlib.h>

//Δήλωση συναρτήσεων copy και change_num_and_symbols
void copy(char str[50]);
void changenum_and_symbols(char cstr[]);

//Αρχή της κύριας συνάρτησης main()
int main(int argc , char *argv[])
{
	char str[50]; 

	//Έισοδος συμβολοσειράς από τον χρήστη 
	printf("Enter a string");
	gets(str);
	
	//κλήση συνάρτησης copy
	copy(str); 

	system("pause");
	return 0 ; 
}
//Αρχή συναρτησης copy.
//Η συνάρτηση παίρνει ως όρισμα τον πίνακα str[50] (σύμβολοσειρα)
void copy(char str[50])
{

	char cstr[50]; 
	int i = 0 ; 
	//αντιγραφή της δοσμένης συμβολοσειράς str[] στον πίνακα χαρακτήρων cstr[50]
	for(i;i<=50 ; i++)
	{
		cstr[i]=str[i]; 
		if (cstr[i]=='\0')
			break;
	}
	//κλήση συνάρτησης changenum_and_symbols
	changenum_and_symbols(cstr);
	//Εμφάνιση της αντιγραμένης σειμβολοσειρας μετά τις αλλαγές
	printf("\n%s",cstr);
}
//Αρχή της συνάρτησης changenum_and_symbols
//Η συνάρτηση παίρνει την αντιγραμένη συμβολοσειρά και αλλάζει τους κατάληλους χαρακτήρες
void changenum_and_symbols(char cstr[])
{
	int i = 0 ;
	
	//επαναληπτική δομή που ελέχει μέχρι να τελειώσουν τα στοιχεία της συμβολοσειράς
	while(cstr[i]!= '\0')
	{
	

		switch (cstr[i])
		{
			//Τα στοιχεία 0,1,2,3,4,5,6,7,8 αυξάνονται κατά 1 
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
				cstr[i]+=1;
				break;
			//Το στοιχείο 9 μετατρέπεται σε 0 
			case '9':
				cstr[i]= '0'; 
				break; 
			//Τα στοιχεία *,+,-,/ μετατρέπονται σε κενό χαρακτήρα(space)' '
			case '*' :
			case '+' :
			case '-' :
			case '/' :
				cstr[i] = ' ';
				break;
		}
		//Μεταφορά στο επόμενο στοιχείο της συμβολοσειράς
		i++;
	}
}
