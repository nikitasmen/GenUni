#include <stdio.h>
#include <stdlib.h>

//Δήλωση δεντρου
struct node{
	float key ; 
	struct node* left;
    struct node* right;
};

//Δήλωση συνάρτησης menu()
int menu(); 
//Δήλωση συνάρτησης search()
int search(struct node* root, float item);
//Δήλωση συνάρτησης newnode()
struct node *newnode(float val);
//Δήλωση συνάρτησης minnode()
struct node* minnode(struct node* node);
//Δήλωση συνάρτησης add()
struct node *add(struct node *root, float val);
//Δήλωση συνάρτησης delete()
struct node *delete(struct node *root, float key);
//Δήλωση συνάρτησης show()
void show(struct node* root) ;


//Αρχή συνάρτησης main()
int main()
{
	//Δήλωση NULL κόμβου 
	struct node *root = NULL ; 
	int x ;
	float num ; 

	do 
	{
		//αποθήκευση της επολογής του χρήστη στην μεταβλητή x
		x = menu();

		//εμφάνιση των κατάλληλων μυνημάτων στον χρήστη
		switch(x)
		{
			case 1: 
			{
				//Εισαγωγή νέου κόμβου
				printf("Enter integer to add"); 
				scanf(" %f", &num);
				root = add(root , num);
				break ; 
			} 

			case 2:
			{
				//Εμφάνιση όλων των κόμβων
				show(root);
				printf("\n");
				break ;
			}

			case 3 :
			{
				//Διαγραφή κόμβου αν το στοιχείο υπάρχει εμφανίζοντας το κατάλληλο μύνημα 
				printf("Enter integer to delete"); 
				scanf(" %f", &num);
				if (search(root , num))
				{
					delete(root,num);	
					printf("Integer deleted \n");
				}
				else 
					printf("Integer does not exist\n");
				break; 
			}

			case 4: 
			{
				//Έλενχος για το αν υπάρχει το στοιχείο που θα δόσει ο χρήστης  
				printf("Enter integer to search"); 
				scanf("%f", &num);
				if (search(root , num)) printf("Integer found\n");
				else printf("Integer not found \n"); 
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
		printf("1.Enter\n2.Show all inorder\n3.Delete\n4.Searcchs\n0.Exit\n");
		scanf("%d", &x);

		//Εμφάνιση κατάλληλου μυνήματος αν η τιμη του x ειναι μη αποδεκτή 
		if ((x<0) || (x>4))
			printf("\nWrong input\n");

	}while((x<0) || (x>4));

	return x ;
}

//Συνάρτηση search()
int search(struct node* root, float item)
{
	//Αν ο κομβος root ειναι NULL τοτε το δέντρο ειναι αδειο
	if(root == NULL) return 0;
	//Αν η τιμή του κόμβου ειναι μικροτερη απο αυτή του χρήστη 
	//Μεταφορα δέξια 
	else if (root->key <item) search(root->right,item);
	//Αν η τιμή του κόμβου ειναι μεγαλύτερη απο αυτή του χρήστη 
	//μεταφορα αριστερά  
	else if (root->key>item) search(root->left , item);
	//Αλλιώς βρέθηκε το στοιχείο 
	else return 1 ; 
}

//Συνάρτηση getNewNode για την δημιουργεία νέου κόμβου 
struct node *newnode(float val)
{
    struct node *newNode = malloc(sizeof(struct node)); //Δημιουργεία κόμβου
    newNode->key   = val; //Αποθήευση τιμής του χρήστη
    newNode->left  = NULL; //Δεν δείχνει πουθένα
    newNode->right = NULL;

    return newNode;
}

//Συνάρτηση ευρεσης κόμβου με την μικρότερη τιμή 
struct node* minnode(struct node* node)
{
    struct node* current = node;

	//Η ελάχιστη τιμή βρίσκεται στο αρίστερότερο φύλλο του δέντρου	
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

// Συνάρτηση για την εισαγωγή νεου στοιχείου στο δεντρο
struct node *add(struct node *root, float val)
{
	//αν το δεντρο ειναι άδειο 
    if(root == NULL)
        return newnode(val);
    
	//αν η τιμή του χρήστη ειναι μεγαλύτερη απο τον παρρόν κόμβο πηγαίνει δεξειά 
    if(root->key < val)
        root->right = add(root->right,val);

    //Αλλιώς δεξια 
    else if(root->key >= val)
        root->left = add(root->left,val);
   
    return root;
}

//Συνάρτηση για την διαγραφή κόμβου
struct node* delete(struct node* root, float key)
{
    // Αν το δέντρο ειναι άδειο
    if (root == NULL)
        return root;
		
	//Αν η τιμή του χρήστη ειναι μικρότερη απο αυτή του κόμβου root
	//μεταφόρα αριστερά
    if (key < root->key)
        root->left = delete(root->left, key);
 
    //Αν η τιμή του χρήστη ειναι μεγαλύτερη απο αυτή του κόμβου root
	//μεταφόρα δεξιά
    else if (key > root->key)
        root->right = delete(root->right, key);
 
 
	//Αλλιώς διαγράφουμε τον κόμβο
    else {
        
        //Αν ο κομβος έχει ενα ή κανένα child
		if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        //Κόμβος με δύο children:
		//Βρισκούμε τον inorder διαδοχο 
		struct node* temp = minnode(root->right);
 
		//Μεταφορά του διαδόχου στην θέση του κόμβου που διαγράφουμε
        root->key = temp->key;
 
		//Διαγραφή του κόμβου αυτου
        root->right = delete(root->right, temp->key);
    }
    return root;
}

//Συνάρτηση show()
void show(struct node* root) 
{
 
	//Αν δεν ειναι άδειο το δεντρο 
 	if (root != NULL) 
  	{
		//εμφάνιση σε inorder
		show(root->left);
	  	printf("%f ->", root->key);
	  	show(root->right);
	}
}


