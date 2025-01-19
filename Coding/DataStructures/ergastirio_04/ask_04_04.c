#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Δήλωση λίστας
typedef struct  node {
	
	int phone ; 
	char name [15]; 
	struct node *prev ; 
	struct node *next ; 
}Node;


//Αρχικποίηση λίστας 
Node *head = NULL ; 
Node *last = NULL ; 

//Δήλωση συνάρτησης search()
int search(int data);
//Δήλωση συνάρτησης show_end()
void show_end();
//Δήλωση συνάρτησης show_start()
void show_start();
//Δήλωση συνάρτησης menu()
int menu();
//Δήλωση συνάρτησης add()
void add(int num , char str[15]);
//Δήλωση συνάρτησης delete()
int delete() ; 

//Αρχή συνάρτησης main()
int main()
{

	int x ,phone;
	char name[15];
	

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
				printf("Enter phone : "); 
				scanf(" %d", &phone);
				printf("\nEnter name : ");
				scanf(" %s", &name[15]);
				add(phone , name); 
				x = 1 ; 
				break ; 
			} 

			case 2:
			{
				//Αν υπάρχει το τηλέφωνο διαγράφεται εμφανίζοντας το κατάλληλο μύνημα
				if(phone = delete())
					printf("last user with phone %d deleted\n",phone);
				else
					printf("The list is empty\n");
				
				break ;
			}

			case 3 :
			{
				//Εμφάνιση όλων των στοιχείων της λιστας απο την αρχή της 
				show_start();
				 
				break; 
			}

			case 4: 
			{
				//Εμφάνιση όλων των στοιχείων της λιστας απο το τέλος της 
				show_end();
				 
				break;
			}
			case 5 : 
			{
				//Είσοδος απο τον χρήστη για το τηλέφωνο 
				printf("Enter phone : ");
				scanf("%d",&phone); 
				//Αν υπάρχει εμφανίζεται το καταλληλο μύνημα 
				if (search(phone))
					printf("User found");
				else 
					printf("User not found"); 
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

//Αρχή της συνάρτησης add()
void add(int num , char str[15])
{

	//Δημιουργεία νέου στοιχείου για την λίστα
	Node *node = malloc(sizeof(struct node));
	node->phone = num ; //εισαγωγή τηλεφώνου
	strcpy(node->name , str ); //Εισαγωγή ονόματος 

	//Αρχικοποίηση της λίστας αν δεν έχει στοιχεία 
	if(head == NULL||head->name>=node->name)
	{
		node ->next = head ; 
		head = node ; 
		last = NULL ;
	} 	
	else 
	{

		//Δήμιουργεία κόμβου ξεκινόντας απο την αρχή της λίστας 
		Node *temp = head ; 
		//Οσο το όνομα του υπάρχοντος κόμβου ειναι μικρότερο απο αυτό του χρήστη 
		//Και το επόμενο στοιχείο δεν ειναι NULL
		while((temp->name <node->name)&&(temp->next != NULL))
		{
			//Μεταφορά στο επόμενο στοιχειο της λιστας 
			temp = temp->next;
		}
		//Τοποθέτηση του νέου κόμβου στην λιστα
		node ->prev = temp  ; 
		temp->next = node ; 
	}

	last = node ; 
}

//Αρχη συναρτησης delete()
int delete()
{
	int num;

	//Δήμιουργεία κόμβου ξεκινόντας απο το τέλος της λίστας 
	Node *node = last ;
	//Αποθηκεύουμε το τηλέφωνο
	num = node->phone ; 
	//Αν δεν έχει στοιχεία επιστρέφει 0 
	if (head == NULL)
		return 0 ;
	else 
		//αλλιώς αφαιρούμε τον τελαιυταίο κόμβο
		last->prev->next = NULL ;
	last = last->prev;
	free(node);
	//επιστρέφουμε το τηλέφωνο 
	return num; 
}

//Αρχή συνάρτησης search()
int search(int data)
{
	//Δήμιουργεία κόμβου ξεκινόντας απο την αρχή της λίστας 
	Node *node = head ; 
	
		//Σειριακή αναζήτηση μέχρι να βρέχει το στοιχείο 
		while((node->phone != data) && (node!=NULL))
		{
			node = node->next ; 
		}
		//Αν ο κόμβος δεν ειναι άδειος επιστρέφουμε 1 αλλιώς 0  
		if (node!= NULL)
			return 1 ;
		else 
			return 0 ;  
}

//Αρχή συνάστησης show_start()
void show_start()
{
	//Δήμιουργεία κόμβου ξεκινόντας απο την αρχή της λίστας 
	Node *node = head ; 
	//Οσο έχει στοιχεία ο κόμβος 
	while(node!= NULL)
	{
		//Εμφανίζουμε τα στοχεία του 
		printf("[%s : %d]->",node->name , node->phone);
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
		//Εμφανίζουμε τα στοχεία του 
		printf("[%s : %d]->",node->name , node->phone);
		//μεταφορά στον επόμενο κόμβο
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

