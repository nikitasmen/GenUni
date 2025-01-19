#include <stdio.h>
#include <stdlib.h>
//δήλωση της τιμής max που εκφράζει το μέγεθος της ουράς
#define max 5 

//δήλωση της ουράς
struct queue{
	float elements[max]; 
	int front , rear ; 
};

//δήλωση της συνάρτησης add. Η συνάρτηση εισάγει τιμή στην ουρά 
void add(struct queue *st , float info); 
//δήλωση της συνάρτησης delete. Η συνάρτηση επιστρέφει την τιμή της ουράς στην θέση front
float delete(struct queue *st); 
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
	float info ; 
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
				if (!isfull(&q))
				{
					printf("Enter data: \t");
					scanf("%f", &info);
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
					printf("The element %f deleted succesfully\n",delete(&q)); 
				}
				//αλλιώς εμφανίζεται κατάλληλο μύνημα 
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

			case 4:
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
	//Αν η τιμή rear ειναι μεγαλύτερη απο την max -1 
	if (st->rear>=max-1)
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
	if(st->front==-1)
	{
		//τοτε επιστρέφει 1 
		return 1 ; 
	}
	else 
	{	
		//αλλιως επιστρέφει 0 
		return 0 ; 
	}
}

//Αρχή της συνάρτησης add()
void add(struct queue *st , float info)
{

	//τοτε αρχικοποιούμε την ουρα δινοντας στην μεταβλητή front την τιμή 0 
	if(st->front == -1)
	{
		//αυξανουμε την τιμή front σε 0 
		//δηλαδή η ουρα έχει στοιχειο
		st->front = 0; 
	}
	//αυξηση της τιμής rear κατα 1 
	st->rear++;

	//αποθηκευση της τιμής που έδωσε ο χρήστης στην θέση rear της ουρας 
	st->elements[(st->rear)]=info;
	
}

//Αρχη της συνάρτησης delete()
float delete(struct queue *st)
{		
	float tmp ; 

	//ελενχος για το αν η ουρα ειναι αδεια 
	if(isempty(st))
	{
		//τοτε ενφανίζεται το καταλληλο μυνημα 
		printf("Queue underflow\n"); 

		return 0;
	}

	else 
	{
		//αλλιως επιστρέφουμε την τιμη που έχει η ουρα στην θεση front 
		tmp = st->elements[(st->front)] ; 
		//και αυξάνουμε την τιμή front κατα 1 
		st->front ++ ; 
		/*αν η τιμή front ειναι μεγαλύτερη απο την τιμη rear τοτε η ουρα έχει αδειάσει.
		Αυτο γινεται γιατι αν στην περίπτωση που αδειάσουμε μια γεμάτη ουρά και θέλουμε να 
		ξαναβάλουμε στοιχεία αυτο να ειναι εφικτό.
		Αν δεν γινει η επανρικοποίηση της ουράς η τιμές front και rear θα μείνουν για πάντα ίσες με την τιμή max,
		και δεν θα μπορούμε να αποθηκευσουμε νεα στοιχεία ακόμα και οταν η ουρα ειναι στην πραγματικότητα αδεια.
		*/
		if (st->front>st->rear)
		{
			//τοτε επαναρχηκοποιούμε την ουρα κανοντας τις τιμες rear και front ισες με -1 
			st->front = st->rear = -1 ; 
		}
		//επιστοφή της τιμης tmp 
		return tmp ; 
	}
}
