#include <stdio.h>  
#include <stdlib.h>

//Δήλωση συνάρτησης stringcompare. Η συνάρτηση επιστρέφει 0 αν οι συμβολοσειρές ειναι ίδιες
//1 αν η πρώτη ειναι μεγαλήτερη
// και -1 αν η πρώτη ειναι μικρότερη 
//Η συνάρτηση πέρνει ως ορίσματα τους δείκτες των σειμβολοσειρών
int stringcompare(char*,char*); 

//αρχή της κύριας συνάρτησης του προγράμματος 
int main()  
{  
    char str1[50]; 
    char str2[50]; 
    
    //Είσοδος απο τον χρήστη της πρώτης σειμβολοσειρας  
    printf("Enter the first string : ");  
    scanf("%s",&str1);  
    
    //Είσοδος απο τον χρήστη της δεύτερης σειμβολοσειρας
    printf("\nEnter the second string : ");  
    scanf("%s",&str2);  

    //Έλενχος των δυο συμβολοσειρών με χρήση της συνάρτησης check
    if(stringcompare(str1,str2)==0)  
        printf("strings are equal");  
    else if(stringcompare(str1,str2)==1)
        printf("string 1 {%s} is greater than string 2 {%s}",str1 , str2);  
    else 
        printf("string 2 {%s} is greater than string 1 {%s}",str2 , str1);  
    
    
    system("pause");
    return 0;  
}  

//Αρχή σύναρτησης stringcompare
int stringcompare(char *a,char *b)  
{  
    //επαναληπτική δομη while οπου ελένχει οτι κανένας απο
    //τους δείκτες των δυο συμβολοσειρώς δεν είναι ίσο με "\0"
    while(*a!='\0' && *b!='\0')   
    {  
        //εάν η τιμή του a ειναι μεγαλύτερη απο του b τοτε η συναρτηση επιστρέφει την τιμή 1 
        if(*a>*b)  
        {  
            return 1;  
        }  
        //αν η τιμή του δείκτη a ειναι μικρότερη απο αυτή του b τοτε η συνάρτηση επιστρέφει -1
        else if(*a<*b)
        {    
            return -1; 
        }
        //αλλιως μεταφέρουμε τους δείκτες στον επόμενο χαρακτήρα
        a++;  
        b++;  
    }  
    //Αν τελειώσει και η επαναληπτική δομή χωρίς να εχεί επιστρέψει η συνάρτηση τιμή,
    //τοτε οι συμβολοσειρές είναι ισες και η συνάρτηση επιστρέφει την τιμή 0 
    return 0;
}  
