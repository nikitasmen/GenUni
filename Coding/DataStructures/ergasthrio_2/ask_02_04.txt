#include <stdio.h>
#include <stdlib.h>

// Δημιουργεία στοίβας κόμβων
struct sNode {
	char data;
	struct sNode* next;
};

// Δήλωση συνάρτησης push() για την εκχώριση τιμής στην στοίβα
void push(struct sNode** top_ref, int new_data);

// Δήλωση συνάρτησης pop() για την αφαίρεση στοιχείου απο την στοίβα
int pop(struct sNode** top_ref);

/*Δήλωση της συνάρτησης pai(). Η συνάρτηση ελένχει αν οι δύο χαρακτήρες ταιριάζουν
επιστρέφοντας την καταλληλη τιμή */
int pair(char character1, char character2);
/*Δήλωση συνάρτησης validation(). Η συνάρτηση ελένχει αν η έκφραση ειναι έγκυρη 
επιστρέφοντας την κατάλληλη τιμή. */
int validation(char exp[]);

// Αρχή της κύριας συνάρτησης main()
int main()
{
	char exp[100] ;
	int i = 0;

	//Είσοδος μαθηματικής εκφρασης από τον χρήστη
	printf("Enter mathematical expression:  ");
	while ((exp[i]=getchar())!=EOF)
	{
		i++;
	}

	//Εμφάνιση καταλλήλου μηνύματος στον χρήστη για το αν η στοίβα ειναι σωστή
	if (validation(exp))
		printf("The mathematical expression is Correct\n");
	else
		printf("The mathematical expression is Wrong\n");

	system("pause");
	return 0;
}

// Αρχή της συνάρτησης push()
void push(struct sNode** top_ref, int new_data)
{
	//Δημιουργεία νέου κόμβου
	struct sNode* new_node = (struct sNode*)malloc(sizeof(struct sNode));

	//Εμφάνιση κατάλληλου μηνύματος αν η στοίβα ειναι γεμάτη
	if (new_node == NULL)
	 {
		printf("Stack overflow n");
		getchar();
		exit(0);
	}

	//Εκχώριση της τιμής στην στοίβα
	new_node->data = new_data;

	//Σύνδεση της παλιάς λίστας με τον νέο κόμβο
	new_node->next = (*top_ref);

	//μεταφορά της αρχής της λίστας δείχνοντας τον νεο κόμβο
	(*top_ref) = new_node;
}

//Αρχή της συνάρτησης pair()
int pair(char character1, char character2)
{
	if (character1 == '(' && character2 == ')')
		return 1;
	else if (character1 == '{' && character2 == '}')
		return 1;
	else if (character1 == '[' && character2 == ']')
		return 1;
	else
		return 0;
}

//Αρχή της συνάτυησης validation()
int validation(char exp[])
{
	int i = 0;

	// Δήλωση καινής στοίβας
	struct sNode* stack = NULL;



	//Διαβασμα των στοιχείων της δοσμένης εκφρασης, ελένχοντας οτι τα σύμβολα ταιρίαζουν
	while (exp[i]) 
	{
		
		//Αν το στοιχείο ειναι '(' ή '{' ή '{' τοτε προστήθεται στην στοίβα stack
		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
			push(&stack, exp[i]);

		/*Αn το στοιχείο είναι ')' ή '}' ή ']' τοτε εξάγεται από την στοίβα stack
		ελενχοντας ότι ταιρίαζει με το αντίστοιχο στοιχειο*/
		if (exp[i] == '}' || exp[i] == ')'|| exp[i] == ']') 
		{

			//Αν η στοιβα ειναι άδεια η συναρτηση επιστρέφει 0 λόγο ανισότητας  
			if (stack == NULL)
				return 0;


			/* Αν το εξαγόμενο στοιχείο απο την στοίβα δεν ταίριάζει τότε,
			η συναρτηση επιστρέφει 0 */
			else if (!pair(pop(&stack), exp[i]))
				return 0;
		}
		i++;
	}

	//Αν η στοίβα είναι άδεια τοτέ η εκφραση ειναι σωστή και η συνάρτηση επιστρεφει 1 
	//Αλλιώς επιστρέφει 0
	if (stack == NULL)
		return 1; 
	else
		return 0; 
}

//Αρχή συνάρτησης pop()
int pop(struct sNode** top_ref)
{
	char res;
	struct sNode* top;

	//Αν η στοίβα είναι άδεια τότε εμφανίζεται σχετικό μήνυμα
	if (*top_ref == NULL) 
	{
		printf("Stack underrflow n");
		getchar();
		exit(0);
	}
	//αλλιώς εξάγουμε το στοιχείο
	else 
	{
		top = *top_ref;
		res = top->data;
		*top_ref = top->next;
		free(top);
		return res;
	}
}
