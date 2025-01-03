#include<stdio.h>
#define SIZE 5
int* distinct(int a[SIZE]);
int exists(int a,int b[]);
int main(){
    int a[SIZE];
    int *c;
    int i;
    for(i=0;i<SIZE;i++){
        scanf("%d",&a[i]);
    }

    c = distinct(a);

    for(i=0;i<SIZE;i++){
        printf("%d",a[i]);
    }



}
 int* distinct(int a[SIZE]){
     int i;
     int b[SIZE];
     int j=-1;
     for(i=0;i<SIZE;i++){
         if(!exists(a[i],b))
         {
             j=j+1;
             b[j]=a[i];

         }
     }
     return b;
 }
 int exists(int a,int b[]){
     int i;
     for(i=0;i<SIZE;i++){
          if(a==b[i]){
              return 1;
          }
     }
     return 0;
 }
