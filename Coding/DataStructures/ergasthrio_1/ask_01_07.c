#include <stdio.h>
#include <stdlib.h>

//Δομή που αποθηκεύει τα στοιχεία του μαθητη
struct Data{ 
	char name[15] ; 
	char secname[15] ; 
	int id;
	float grade ; 

};

//δήλωση συναρτήσεων enterdata και showdata
void enterdata(struct Data d1[]);
void showdata(struct Data d1[]);

//Αρχή σύναρτησης main
int main(int argc, char *argv[])
{
	struct Data d1[8];

	//Κλήση συνάρτησης enterdata
	enterdata(d1);
	//Κλήση συνάρτησης showdata
	showdata(d1);

	system("pause");
	return 0 ;
}
//Αρχή συνάρτησης enterdata
//Η συνάρτηση παιρνει ως ορίσμα τον αναφερόμενο σε δομή πίνακα d1[] 
void enterdata(struct Data d1[])
{

	for(int i=0 ; i<=7;i++)
	{
		//Είσοδος ονόματος μαθητή
		printf("\nEnter the first name of the student %d: ",i);
	   	scanf("%s",&d1[i].name);
	   	//Είσοδος επιθέτου μαθητή
	   	printf("\nEnter the second name of the student %d: ",i);
	   	scanf("%s",&d1[i].secname);
	   	//Είσοδος Αριθμού Μυτρώου μαθητή
	   	printf("\nEnter the id of the student %d:",i); 
	   	scanf("%d",&d1[i].id);
	   	//Είσοδος βαθμού μαθητή
	   	printf("\nEnter the average grade of the student %d:",i);
	   	scanf("%f",&d1[i].grade);

	}
	
}
//Αρχή συνάρτησης shodata
//Η συνάρτηση παιρνει ως ορίσμα τοναναφερόμενο σε δομή πίνακα d1[] 
void showdata(struct Data d1[])
{
	printf("A/A\t\tONOMA\t\tEPITHETO\tARITHM.MHTROOY\tBATHMOS\n");
	printf("-------------------------------------------------------------------\n");
	//Εμφάνηση των στοιχείων της δομής 
	for(int i = 0; i<=7;i++)
	{
		printf("%d\t%13s\t%15s\t\t%5d\t\t%g\n",i,d1[i].name,d1[i].secname,d1[i].id,d1[i].grade);
	}


}