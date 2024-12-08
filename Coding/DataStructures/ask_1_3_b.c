#include<stdio.h>
int stringCompare(char *a,char *b);



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

int stringCompare(char *a,char *b){
                
    while(*a!='\0' || *b!='\0'){
        if(*a=='\0'){
            return 1;
        }
        else if(*b=='\0'){
            return -1;
        }
        else if(*a>*b){
            return -1;
        }
        else if(*a<*b){
            return 1;
        }
        a++;
        b++;
        
        
    }
    return 0;
}

