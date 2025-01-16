#include <stdio.h>
#include <stdlib.h>



//Δήλωση συναρτήσεων
int sum(int number,int s); 
float mo(int number , int count);
int max(int number,int  M); 
int min(int number,int  m);

//Αρχή της κύριας συνάρτησης 
int main(int argc , char *argv[])
{
	//count = 0 (αρχηκοποίηση του μετρητή), sum = 0 (αρχηκοποίηση του αθροισματος)

	int num , count = 0 , s = 0 , ma , mi;	
	
	//Είσοδος αριθμού από τον χρήστη
	printf("Enter number");
	scanf("%d",&num);

	//αρχηκοποίηση του ελαχίστου και μέγιστου αριθμού
	mi = num;
	ma = num;

	//επαναληπτική δομή while μέχρις ότου  χρήστης να δόσει 0 
	while (num!=0)
	{	
		//Αυξησή του μετριτή 
		count +=1;
		//Αυξηση του αθροίσματος 
		s=sum(num,s);
		//ενημέρωση του μεγαλύτερου και μικρότερου όρου
		ma = max(num, ma);
		mi = min(num,mi);

		printf("Enter number");
		scanf("%d",&num);
	}
	//αν δόθηκε ένας τουλάχιστον αριθμός διαφορετικός του 0 τότε εμφανείζει το αθροισμά και τον μέσο όρο τους, τον μεγαλύτερο και τον μικρότερο αυτών
	if (count>=1)
	{
		printf("The sum of all numbers is :%d",s);
		printf("\nThe average of all numbers is : %f",mo(s,count));
		printf("\n The biggest number of all is :%d", ma);
		printf("\n The smallest number of all is :%d", mi); 
		system("pause");
	}

	else 
	{
		printf("No numbers added");
	}
	return 0 ;
}

//συνάρτηση αθροίσματος 
int sum(int number,int s)
{
	return s+=number ; 
}

//συνάρτηση έυρεσης μεγίστου αριθμού
int max (int number,int M)
{
	if (number>M)
	{
		M = number;
	}
	return M;
}

//συνάρτηση έυρεσης ελαχίστου αριθμού
int min(int number ,int m)
{
	return m = (number<m)?number:m ; 
}

//συνάρτηση εύρεσης μέσου όρου των δοσμένων αριθμών
float mo(int number ,int  count)
{
	float m = (number/count); 
	return m;
}
