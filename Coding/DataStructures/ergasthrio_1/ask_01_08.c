#include <stdio.h>
#include <stdlib.h>

//δήλωση συναρτήσεων enterdata και showdata
void enterdata();
void showdata();

//Αρχή σύναρτησης main
int main(int argc , char *argv[])
{
	int choise;
	//Κύριο μενού λειτουργειών προγράμματος
	//Το πρόγραμμα απαναλμβάνεται μέχρις ότου ο χρήστης δώσει την τιμή 3 
	do
	{
		//Εμφάνιση μενού και είσοδος επιλογή από τον χρήστη
		printf("\nPress :");
		printf("\n1. to add a student's record");
		printf("\n2. to show all" );
		printf("\n3. to exit");
		scanf("%d",&choise);

		switch (choise)
		{
			case 1:
				//Αν ο χρήστης δώσει 1 τότε καλείτε η συνάρτηση enterdata
				enterdata();
				break;
			case 2:
				//Αν ο χρήστης δώσει 2 τότε καλείτε η συνάρτηση showdata
				showdata();
				break;
		}

	}while(choise !=3);

	system("pause");
	return 0 ;
}

//Αρχή συνάρτησης enterdata
void enterdata()
{
	int id ; 
	float grade ; 
	char name[15] , secname[15];

	FILE *fptr;
	//Ανοιγμα αρχείου student.txt ως append και read
	//Αν το αρχείο δεν υπάρχει τότε δημηουργείται στο ίδιο path του εκτελέσιμου αρχείου
	fptr = fopen("student.txt","a+");
	//Εαν το ανοιγμα/δημιουργεία του αρχείου δεν είναι εφικτή τότε εμφανίζεαται μύνημα λάθους
	//τερματίζοντας το προγραμμα
	if(fptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	//Είσοδος ονόματος μαθητή
	printf("\nEnter the first name of the student : ");
	scanf("%s",&name);
	//Είσοδος επιθέτου μαθητή
   	printf("\nEnter the second name of the student : ");
   	scanf("%s",&secname);
	//Είσοδος Αριθμού Μυτρώου μαθητή
   	printf("\nEnter the id of the student :"); 
   	scanf("%d",&id);
   	//Είσοδος βαθμού μαθητή
	printf("\nEnter the average grade of the student :");
   	scanf("%f",&grade);
	//Εγγραφή των στοιχείων που έδοσε ο χρήστης στην κατάλληλη μορφή στο αρχείο student.txt
   	fprintf(fptr, "\t%13s\t%15s\t\t%5d\t\t%g\n",name,secname,id,grade );
   	fclose(fptr);

}
//Αρχή συνάρτησης shodata
void showdata()
{
	int i = 1;
	char str[150];

	printf("A/A\t\tONOMA\t\tEPITHETO\tARITHM.MHTROOY\tBATHMOS\n");
	printf("-------------------------------------------------------------------\n");
	FILE *fptr; 

	//Εαν το ανοιγμα του αρχείου δεν είναι εφικτή τότε εμφανίζεαται μύνημα λάθους
	//τερματίζοντας το προγραμμα
	if((fptr = fopen("student.txt","r"))==NULL)
	{
		printf("Error!");
		exit(1);
	}
	//Η κάθε γραμμή αντιγράφετε στην μεταβλητή str όσο η γραμμή του αρχείου δεν ειναι κενή (NULL)
	while( fgets (str, 150, fptr)!=NULL )
	{	
		//Eμφάνιση του αριθμού της γραμμής του αρχείου και της γραμμής του αρχείου
		printf("%d%s",i,str);
		i++;
	}

}