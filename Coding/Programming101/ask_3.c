#include<stdio.h>
int main(){
int x;
scanf("%d",&x);
 while(x<3 || x%2==0){
     printf("lathos");
     scanf("%d",&x);
 }
 printf("*\n");
 int i ; 
 for(i=3;i<=x;i+=2){
     int tmp=(i-1)/2;
     int j;
     for(j=0;j<tmp;j++){
         printf("/");
     }

     printf("|");
     for(j=0;j<tmp;j++){
         printf("\\");

     }
     printf("\n");

 }

return 0;
}