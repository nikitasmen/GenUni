#include <stdio.h>
#include <stdlib.h>

typedef struct  node {
	
	float data ; 
	struct node *prev ; 
	struct node *next ; 
}Node;

//Δήλωση συνάρτησης menu()
int menu();
void show_end();
void show_start();
void add(float item );
float delete() ; 

//Αρχικοποίηση λίστας 
Node *head = NULL ; 
Node *last = NULL ; 
Node *current = NULL ; 

//Αρχή συνάρτησης main()
int main()
{

	int x ;
	float item;
	

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
			{
				//Εισαγωγή δεδωμένων απο τον χρηστη 
				printf("Enter data : "); 
				scanf(" %f", &item);
				add(item); 
				x = 1 ; 
				break ; 
			} 

			case 2:
			{
				if((item = delete())==0)
					printf("The list is empty\n");
				else
					printf("last element %f deleted\n",item);
				x = 2 ;
				break ;
			}

			case 3 :
			{
				//Εμφάνιση όλων των στοιχείων της λιστας απο την αρχή της 
				show_start();
				x = 3 ; 
				break; 
			}

			case 4: 
			{
				//Εμφάνιση όλων των στοιχείων της λιστας απο το τέλος της 
				show_end();
				x = 4 ; 
				break;
			}
			case 0 :
			{
				//έξοδος απο το πρόγραμμα
				printf("EXIT\n\n"); 
				break;
			}
		}

	}while(x);

	system("pause"); 
	return 0 ; 

}
//Αρχή συνάρτησης delete()
float delete()
{
	float element ; 
	//Δήμιουργεία κόμβου ξεκινόντας απο τo τελος της λίστας 
	Node *temp = last ; 
	element = temp ->data;  
	//Αν η λίστα ειναι αδεια επιστρέφει 0 
	if((head == NULL))
		return 0 ;	
	else 
		//άλλιως διαγράφει το τελευταιο στοιχείο 
		last ->prev->next = NULL ; 
	
	last = last->prev ; 

	return temp ->data; 
}
//Αρχή συνάρτησης add()
void add(float item)
{


	//Δημιουργεία νέου στοιχείου για την λίστα
	Node *new = malloc(sizeof(struct node));
	new->data = item;//Εκχώριση τιμής 
	
	if(head ==NULL)
	{
		head = new ; 
		last = NULL;
	}
	else 
	{
		last->next = new;
		new->prev = last ;
	}
	last = new;
}
//Αρχή συνάστησης show_start()
void show_start()
{
	//Δήμιουργεία κόμβου ξεκινόντας απο την αρχή της λίστας 
	Node *node = head ; 
	//Οσο έχει στοιχεία ο κόμβος 
	while(node!= NULL)
	{
		//Εμφανίζουμε το στοχείο του 
		printf("%f->",node->data);
		//μεταφορά στον επόμενο κόμβο
		node= node->next ; 
	}
	//Εμφάνιση οτι η λίστα άδειασε
	printf("NULL\n");
}

//Αρχή συνάστησης show_end()
void show_end()
{
	//Δήμιουργεία κόμβου ξεκινόντας απο το τέλος της λίστας 
	Node *node = last ;
	//Οσο έχει στοιχεία ο κόμβος 
	while(node != NULL)
	{
		//Εμφάνιση στοιχείου
		printf("%f->",node->data);
		//Μεταφορά στον επόμενο κόμβο
		node = node->prev ; 
	}
	//Εμφάνιση οτι η λίστα άδειασε
	printf("NULL\n");
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
		printf("1.Enter\n2.Delete\n3.Show all from start\n4.Show all from end\n0.Exit\n");
		scanf("%d", &x);

		//Εμφάνιση κατάλληλου μυνήματος αν η τιμη του x ειναι μη αποδεκτή 
		if ((x<0) || (x>4))
			printf("\nWrong input\n");

	}while((x<0) || (x>4));

	return x ;
}