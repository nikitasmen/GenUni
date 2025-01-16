#include <stdio.h>
#include <stdlib.h>
#define MAX 5

//Δωμή stack για την υλοποίηση της στοίβας 
struct stack {
  int items[MAX];
  int top;
};

//Δήλωση συναρτησης menu(). H συνάρτηση menu() εμφανίζει το κεντρικό μενού του προγράμματος, δέχεται ακαίρεα τιμή από τον χρήστη για την καταλλληλη εντολή του μενου
int menu(); 

//Δήλωση συνάρτησης που ελένχει αν η στοίβα ειναι γεμάτη 
int is_full(struct stack *s);

//Δήλωση συνάρτησης που ελένχει αν η στοίβα ειναι άδεια
int is_empty(struct stack *s); 

//Δήλωση συνάρτησης για την εκχώριση καινούργιου στοιχείου στην στοίβα 
void push(struct stack *s , int element); 

//Δήλωση συνάρτησης για την διαγραφή τιμής απο την στοίβα
void pop(struct stack *s ); 

//Δήλωση συνάρτησης που εμφανίζει στον χρήστη την κορυφαία τιμή της στοίβας
void stack_top(struct stack *s);



//Αρχή της κύριας συναρτησης του προγραμματος main()
int main() 
{
	//Δεσμευση μνήμης για την στοιβα   
 	struct stack *s = (struct stack *)malloc(sizeof(struct stack));

 	//Δημιουργεία στοιβας 
  s->top = -1;
	
	int x  ,el;
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
				//Αν η στοίβα ειναι γεμάτη δεν μπορούμε να βάλουμε στοιχεία και εμφανίζεται το κατάλληλο μύνημα 
				//Αλλιώς δέχεται την είσοδο νέου στοιχείου απο τον χρήστη 
				if(is_full(s))
				{
					printf("Stack is full\n");
					break;
				}
				else
				{
					printf("Enter new element\n"); 
					scanf("%d", &el);
					printf("\n");
					push(s , el);
				}
				break;

			case 2:
				//εμφανίση στον χρήστη της κορυφαίας τιμής της στοίβας
				stack_top(s);
				break;

			case 3:
				//διαγραφή τιμής απο την κορυφή της στοίβας
				pop(s);
				break; 
			
			case 0:
				//Εξοδος προγράμματος
				printf("Exit");
				break;
		}


	}while(x>0);

	system("pause");
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
		printf("1.Push \n2.Show top \n3.Pop \n0.Exit\n");
		scanf("%d", &x); 
		//Εμφάνιση κατάλληλου μυνήματος αν η τιμη του x ειναι μη αποδεκτή 
		if ((x<0) || (x>4))
			printf("\nWrong input\n");

	}while((x<0) || (x>4));

	return x ;
}


//Αρχή της συνάρτησης is_full 
int is_full(struct stack *s) 
{
	//H συνάρτηση επιστρέφει 1 αν η στοίβα ειναι γεμάτη αλλιώς επιστρέφει 0 
  return (s->top == MAX - 1)? 1 : 0 ;
}


//Αρχή συνάρτησης is_empty
int is_empty(struct stack *s) 
{
	//H συνάρτηση επιστρέφει 1 αν η στοίβα ειναι άδεια αλλιώς επιστρέφει 0 
  return (s->top == -1)? 1 : 0 ; 
}


//Αρχή της συνάρτησης push 
void push(struct stack  *s, int element)
{
	//Προσθέτει το στοιχείο που έδωσε ο χρήστης στην στοίβα  
  s->top++;
  s->items[s->top] = element;
}


//Αρχή της συνάρτησης pop
void pop(struct stack *s)
{
	//Αν η στοίβα ειναι άδεια δεν μπορούμε να εξάγουμε στοιχεία και εμφανίζεται το κατάλληλο μύνημα 
	//Αλλίώς διαγράφεται το στοιχείο στην κορυφή της στοίβας 
  if (is_empty(s)) 
    printf("Stack is empty \n");
  else 
  {
    printf("Item popped= %d\n", s->items[s->top]);
    s->top--;
  } 
}


//Αρχή της συνάρτησης stacktop
void stack_top(struct stack *s)
{
	//Αν η στοίβα ειναι άδεια δεν μπορούμε να εξάγουμε στοιχεία και εμφανίζεται το κατάλληλο μύνημα 
	//Αλλίώς εμφανίζεται το στοιχείο στην κορυφή της στοίβας 
	if(is_empty(s))
	{
		printf("Stack is empty\n"); 
	}
	else 
	{
		printf("Element in top of stack is :  %d\n", s->items[s->top]);
	}
}