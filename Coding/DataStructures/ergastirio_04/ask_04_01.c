#include <stdio.h>
#include <stdlib.h>

//Δήλωση λίστας 
typedef struct node{
	char data; 
	struct node* next;
}Node;

//Δήλωση συνάρτησης menu()
int menu();
//Δήλωση συνάρτησης add()
void add(char item);
//Δήλωση συνάρτησης del_last()
char del_last();
//Δήλωση συνάρτησης delete()
char delete(char item);
//Δήλωση συνάρτησης show()
void show(); 
//Δήλωση συνάρτησης search()
int search(char item);

//Αρχικοποιηση λιστας θέτωντας την αρχή και το τέλος NULL
Node *head = NULL; 
Node *tail  = NULL; 

//Αρχή συνάρτησης main()
int main()
{

	int x ;
	char item;

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
				scanf(" %c", &item);
				add(item); 
				break ; 
			} 

			case 2:
			{
				//Επιλογή απο τον χρήστη για το ποιο δεδομένο θα διαγραφει
				//Η επιλογή ctrl-Z διαγράφει το τελευταίο στοιχείο της ουράς
				printf("Enter element to delete or ctrl-z for last element : ");
				scanf(" %c", &item);
				if(item == '\0')
				{
					//Αν δοθει cntl-z ελένχουμε αν η λίστα έχει στοιχεία και εμφανίζουμε το κατάλληλο μυνημα
					if(del_last()=='\0')
						printf("The list is empty\n");
					else
						printf("last element %c deleted",del_last());
				}

				else 
				{	
					//Αλλιώς ελένχουμε αν το στοιχείο που δόθηκε υπάρχει στην λίστα
					//εμφανίζοντας το κατάλληλο μύνημα 
					if(search(item))
						printf("element : %c deleted\n",delete(item));
					else
						printf("Element not found\n");
				}
					x = 2 ;
				break ;
			}

			case 3 :
			{
				//Εμφάνιση όλων των στοιχείων της λιστας 
				show();
				break; 
			}

			case 4 :
			{
				//Είσοδος απο τον χρήστη και εμφανίζει αν το στοιχείο που δόθηκε υπάρχει στην λίστα
				//Εμφανίζοντας το κατάλληλο μύνημα
				printf("Enter data"); 
				scanf(" %c", &item); 
				if(search(item))
					printf("item %c found\n",item);
				else 
					printf("item %c not found\n",item);
				break ; 
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

//Αρχή συνάρτησης add()
void add(char item)
{
	//Δημιουργεία νέου στοιχείου για την λίστα
	Node *newNode = malloc(sizeof(struct node));
	newNode->data = item;//Εκχώριση τιμής 
	newNode->next = NULL;//Το στοιχείο που δείχνει ο παρρόν κόβμος ειναι NULL

	//Αν δέν έχει δήμιουργηθει λίστα 
	if (head == NULL)
	{
		//τοτε η αρχή και το τέλος δείχνουν στον νέο κόμβο 
		head = tail = newNode;
	}
	else 
	{
		//αλλιώς το τέλος δείχνει στον νέο κόμβο
		tail->next = newNode;
		tail = newNode ; 
	}
	
}
//Αρχή συνάρτησης del_last()
char del_last()
{
	
	char el ; 
	//Δήμιουργεία κόμβου
	Node *ptr ; 
	//ξεκινόντας απο την αρχή της λίστας 
	ptr = head ; 
	//Αν ο κομβος ειναι κενός 
	if(ptr == NULL)
	{
		//τότε η λίστα ειναι αδεια και εμφανίεται το καταλληλο μυνημα 
		printf("list is empty\n");
		return '\0' ;
	}
	else 
	{	//αλλιώς παμε στον επόμενο κόμβο οσο υπάρχει αυτος υπάρχει 
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		//διαγράφουμε τον τελαιυταίο κόμβο
		el = ptr->data ; 
		free(ptr); 
		//επιστροφή της τιμής του 	
		return el ;

	}
}

//Αρχη συναρτησης delete()
char delete(char item)
{
	char el ; 
	//Δήμιουργεία κόμβου ptr και temp
	Node  *ptr , *temp ; 
	//Ο temp δείχνει στην αρχή της λίστας
	temp = head ; 

	//Αν ο πρώτος κόμβος δεν ειναι κενός και το δεδομένο του ειναι ίδιο με αυτο του χρήστη
	if (temp != NULL && temp->data == item)
	{
		//διαγραφή του κόμβου και επιστροφή της τιμής του 
        el = temp->data;
        head = temp->next;
        free(temp); 
        return el;
    }

    //Όσο ο κόμβος δεν ειναι άδειος και δεν εχει το στοιχείο του χρήστη
    while (temp != NULL && temp->data != item) 
    {
    	//μεταφορα στον επόμενο κόμβο
        ptr = temp;
        temp = temp->next;
    }
	
	//διαγραφή του κόμβου και επιστροφή της τιμής του 
  	el = temp->data ; 
    ptr->next = temp->next;
    free(temp); 

    return el ; 
}


//Αρχη συνάρτησης show()
void show ()
{
	//Δήμιουργεία κόμβου	
	Node *ptr;
	//ξεκινόντας απο την αρχή της λίστας 
	ptr = head ; 

	//Οσο ο κόμβος δέν ειναι κενός
	while(ptr!= NULL)
	{
		//Εμφανίζουμε το στοχείο του 
		printf("%c->",ptr->data);
		//μεταφορά στον επόμενο κόμβο
		ptr= ptr->next ; 
	}
	//Εμφάνιση οτι η λίστα άδειασε
	printf("NULL\n");

}

//Αρχή συνάρτησης search()
int search(char item)
{
	//Δήμιουργεία κόμβου
	Node *ptr ; 
	//ξεκινόντας απο την αρχή της λίστας 
	ptr = head ; 
	
	//Όσο η next του κόμβου δεν ειναι NULL
	//Δήλαδή υπάρχει το επόμενο στοιχείο
	while (ptr != NULL)
	{
		//Αν το στοιχείο της λίστας ειναι το ίδιο με το στοιχείο που έδωσε ο χρήστης 
		if(ptr->data == item)
		{
			//επιστρέφει 1 
			return 1 ; 
		}
		else 
			//Αλλιώς προχοράμε στον επόμενο κόμβο
			ptr = ptr->next;
	}
	//Επιστρέφουμε 0 
	return 0 ;
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
		printf("1.Enter\n2.Delete\n3.Show all\n4.Search\n0.Exit\n");
		scanf("%d", &x);

		//Εμφάνιση κατάλληλου μυνήματος αν η τιμη του x ειναι μη αποδεκτή 
		if ((x<0) || (x>4))
			printf("\nWrong input\n");

	}while((x<0) || (x>4));

	return x ;
}