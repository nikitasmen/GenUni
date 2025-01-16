#include <stdlib.h>
#include <stdio.h>
//δήλωση της τιμής max που εκφράζει το μέγεθος της ουράς
#define max 7 

//δήλωση της ουράς
struct queue{
	double elements[max]; 
	int front , rear ; 
};

//δήλωση της συνάρτησης add. Η συνάρτηση εισάγει τιμή στην ουρά 
void add(struct queue *st , double info); 
//δήλωση της συνάρτησης delete. Η συνάρτηση επιστρέφει την τιμή της ουράς στην θέση front
double delete(struct queue *st); 
//δήλωση της συνάρτησης isempty. Η συνάρτηση ελένχει αν η ουρά ειναι αδεια 
int isempty(struct queue *st ); 
//δήλωση της συνάρτησης isfull. Η συνάρτηση ελένχει αν η ουρά ειναι γεμάτη
int isfull(struct queue *st); 
//δήλωση της συνάρτησης menu. Η συνάρτηση εμφανίζει το menu στον χρήστη και επιστρέφει την επιλογή του 
int menu(); 

//Αρχη της συναρτησης main()
int main()
{

	int x ;
	double info ; 
	struct queue q; 

	//αρχικοποιηση της ουράς στο -1 (κενή ουρά)
	q.front = -1 ; 
	q.rear = -1 ; 
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
				//αν η ουρά δεν ειναι γεμάτη τοτε μπορούμε να εισάγουμε δεδομένα 
				if(!isfull(&q))
				{
					printf("Enter data: \t");
					scanf("%lf", &info);
					add(&q , info); 
				}
				//αλλιως εμφανίζεται κατάλληλο μύνημα 
				else 
				{
					printf("Stack is full\n\n");
				}
				break;

			case 2:

				//αν η ουρά δεν είναι άδεια τότε μπορούμε να εξάγουμε το κατάλληλο στοιχείο
				if(!isempty(&q))
				{
					info = delete(&q);
					printf("The element %lf deleted succesfully\n",info); 
				}
				//αλλιως εμφανίζεται κατάλληλο μύνημα 
				else 
				{
					printf("Stack is empty\n\n");
				}
				break;
			
			case 3:

				//έλενχος για το αν η ουρά ειναι άδεια ή όχι για τον χρήστη
				if(isempty(&q))
					printf("Stack is empty\n\n");
				else 
					printf("Stack is not empty\n\n");
				break;
			case 4 : 

				//έλενχος για το αν η ουρά ειναι γεμάτη ή όχι για τον χρήστη
				if (isfull(&q))
					printf("Stack is full\n\n"); 
				else 
					printf("Stack is not full\n\n");
				break; 

			case 0:

				//έξοδος απο το πρόγραμμα
				printf("Exit\n\n");
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
		printf("1.Enter\n2.Delete\n3.Check if is empty\n4.Check if is full\n0.Exit\n");
		scanf("%d", &x);

		//Εμφάνιση κατάλληλου μυνήματος αν η τιμη του x ειναι μη αποδεκτή 
		if ((x<0) || (x>4))
			printf("\nWrong input\n");

	}while((x<0) || (x>4));

	return x ;
}

//Αρχή της συνάρτησης isfull()
int isfull(struct queue *st)
{
	//Αν η τιμή front ειναι ίση με την τιμή rear+1 ή (η τιμή της front ειναι ίση με 0 και η τιμή της rear ειναι ίση με το max-1)
	if ((st->front == st->rear + 1) || (st->front == 0 && st->rear == max - 1))
		//τότε επιστρέφει 1 
		return 1 ; 
	else 
		//αλλιώς 0 
		return 0 ; 
}

//Αρχή της συνάρτησης isempty()
int isempty(struct queue *st)
{
	//Αν η τιμή front ειναι ίση με -1 τοτε η στοίβα ειναι αδεια 
	if(st->front == -1)			
		//τότε επιστρέφει 1 
		return 1 ; 
	else 			
		//αλλιώς 0 
		return 0 ; 
}


//Αρχη της συναρτησης delete()
double delete(struct queue *st)
{		
	double item ; 
	//η μεταβλητη item παιρνει την τιμή του στειχείου της ουράς στην θέση front 
	item = st->elements[st->front]; 
	//Αν η τιμή της front ειναι ίδια με αυτή της rear τοτε η ουρά εχει αδειάσει 
	if (st->front == st->rear)
	{
		//Τοτε επαναχρηκοποιούμε την ουρα
		st->rear = st->front = -1 ; 
	}
	else 
	{
		//αλλιώς αυξάνουμε την τιμή της front κατα 1 
		//απο το αποτέλεσμα αυτο αποθηκευουμε το ακαιρεο υπόλυπο της (front +1 ) % max
		//ώστε όταν το front+1 παρει τιμη π.χ. 8 τοτε, η τελική της τιμή θα ειναι 1  
		st->front = (st->front+1) % max;
	}
	return item ; 
}


//Αρχή της συνάρτησης add()
void add(struct queue *st, double info)
{ 	
	//Αν η τιμή front έχει την τιμή -1 τοτε η ουρά ειναι άδεια 
	if (st->front == -1) 
	{
		//την δημιουργούμε θέτοντας την μεταβλητή front ίση με 0 
		st->front = 0 ; 
	}
	//Αυξάνουμε την τιμή rear κατα 1 και αν το αποτέλεσμα της προσθεσης αυτής ειναι μεγαλύτερο του max το αποτέλεσμα θα παρει τιμή (rear+1) % max
	st->rear = (st->rear+1)% max ; 
	//Αποθηκευουμε την τιμή που έδωσε ο χρήστης στην θέση rear της ουράς
	st->elements[st->rear] = info ; 
}
