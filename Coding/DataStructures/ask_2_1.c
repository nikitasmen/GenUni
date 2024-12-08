#include<stdio.h>

int menu(); 

int main(){
    int choise;
    do{
        choise = menu(); 
         switch(choise){
             case 1:
                 printf("eisagogh\n");
                 break;
             case 2:
                 printf("diagrafh\n");
                 break;
             case 3:
                 printf("emfanish\n");
                 break;
             case 4:
                 printf("anazitish\n");
                 break;
             case 0:
                 printf("ejodos\n"); 
                 exit(0);

                 break;
         }

    }while(choise!=0);

    return 0 ; 

}

int menu(){
    int i ; 
    printf("1.eisagogh\n");
    printf("2.diagrafh\n");
    printf("3.emfanish\n");
    printf("4.anazitish\n");
    printf("0.ejodos\n");
    printf("dose epilogh \n");
    scanf("%d",&i);

    return  i;
}