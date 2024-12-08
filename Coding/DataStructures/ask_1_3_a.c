#include<stdio.h>
int stringCompare(char a[],char b[]);



int main(){
 char a[100],b[100];
 fgets(a, 100 , stdin);
 fgets(b, 100 , stdin);
 
 int c=stringCompare(a,b);
 switch (c) {
    case 1:
    printf("to a einai mikrotero: %s",a);
    break;
    case -1:
    printf("to b einai mikrotero: %s",b);
    break;
    case 0:
    printf("to a kai to b einai idia");
   break;
 }
   return 0;
}

int stringCompare(char a[],char b[]){

    for(int i=0;i<100;i++){
        if(a[i]=='\0' && b[i]=='\0'){
            return 0;
        }
        if(a[i]=='\0'){
            return 1;
        }
        else if(b[i]=='\0'){
            return -1;
        }
        else if(a[i]>b[i]){
            return -1;
        }
        else if(a[i]<b[i]){
            return 1;
        }
        
        
    }
    return 0;
}

