#include<stdio.h>
#define SIZE 5
int menu();

struct queue{
    float data[SIZE];
      int end;
};
void diagrafi(struct queue *q);
void init(struct queue *q);
void eisagogi(struct queue *q);
void elexos(struct queue *q);
void emfanisi(struct queue *q);
int main(){
int x;
struct queue q;
struct queue *ptr = &q;

 x=menu();
 init(ptr);
 do{

 switch(x){
     case 1:
     eisagogi(ptr);
     break;
     case 2:
     diagrafi(ptr);
     break;
     case 3:
     elexos(ptr);
     break;
     case 4 :
         emfanisi(ptr);
         break;
     case 0 :
     return 0 ;
     default:
     printf("lathos aritmos");
 }
}while(x=menu());

}

void diagrafi(struct queue *q){
    int i;
    for(i=1;i<SIZE;i++){
        q->data[i-1]=q->data[i];
    }


    q->end=q->end-1;
}
void init (struct queue *q){
    q->end = -1;
}
void eisagogi(struct queue *q){
    q->end=q->end+1;
    scanf("%f", &q->data[q->end]);
}
void elexos(struct queue *q){
    if(q->end==-1){
        printf("einai adia");

    }
    else if(q->end==SIZE-1){
        printf("einai gemati");

    }
}
void emfanisi(struct queue *q){
    int i;
    for(i=0;i<=q->end;i++){
        printf("%f",q->data[i]);
    }
}
int menu(){
    int x;
    printf("1.eisagogi 2.diagrafi 3.elexos 4.emfanisi 0.ejodos");
    scanf("%d",&x);
    return x;

}
