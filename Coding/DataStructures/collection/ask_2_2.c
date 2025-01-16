#include<stdio.h>

int menu();
int push(int x[], int i);
int pop(int i);

int main(){
    int x[4];
    int i;
    int stacktop=-1;

    do{
        i = menu();
        switch(i){
            case 1:
                printf("eisagogh\n");
                stacktop++;
                x[stacktop]=push( x,stacktop);
                break;
            case 2:
                printf("diagrafh\n");
                stacktop=pop(stacktop);
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

    }while(i!=0);

    return 0 ;
}


int pop(int i){
    i--;
    return i;
}


int menu(){

    int i;
    printf("1.eisagogh\n");
    printf("2.diagrafh\n");
    printf("3.emfanish\n");
    printf("4.anazitish\n");
    printf("0.ejodos\n");
    printf("dose epilogh \n");
    scanf("%d",&i);
    return i;
}

int push(int x[],int i){

    printf("dose arithmo");
    scanf("%d",&x[i]);
    return x[i];
}
