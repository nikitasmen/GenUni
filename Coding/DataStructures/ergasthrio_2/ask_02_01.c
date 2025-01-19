#include<stdio.h>
#include<stdlib.h>
//Δήλωση συναρτησης menu(). H συνάρτηση menu() εμφανίζει το κεντρικό μενού του προγράμματος, δέχεται ακαίρεα τιμή από τον χρήστη για την καταλλληλη εντολή του μενου
int menu();

//αρχή της κύριας συναρτησης του προγραμματος main()
int main(int argc, char const *argv[])
{

	int x ;
	// δομή επανάλληψης do while 
	// η δομή τερματίζει οταν ο χρήστης δώσει την τιμή 0 
	do
	{	
		//αποθήκευση της επολογής του χρήστη στην μεταβλητή x
		x = menu();

		//εμφάνιση των κατάλληλων μυνημάτων στον χρήστη
		switch(x)
		{

			case 1:
				printf("Enter\n\n");
				break;
			case 2:
				printf("Delete\n\n");
				break;
			case 3:
				printf("Show\n\n"); 
				break; 
			case 4:
				printf("Search\n\n");
				break;
			case 0:
				printf("Exit\n\n");
				break;
		}


	}while(x>0);

	system("pause");
	return 0;
}

//Αρχή της συνάρτησης menu()
int menu()
{
	int x ;
	// δομή επανάλληψης do while 
	// η δομή τερματίζει οταν ο χρήστης δώσει έγκυρη τιμή
	do
	{
		//εμφάνιση του κεντρικού μενού στον χρήστη και εκχώριση της επιλογής του στην μεταβλητή x  
		printf("1.Enter\n2.Delete\n3.Show\n4.Search\n0.Exit\n");
		scanf("%d", &x);

		//Εμφάνιση κατάλληλου μυνήματος αν η τιμη του x ειναι μη αποδεκτή 
		if ((x<0) || (x>4))
			printf("\nWrong input\n");

	}while((x<0) || (x>4));

	return x ;
}