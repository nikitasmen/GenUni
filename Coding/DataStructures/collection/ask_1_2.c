//Writen by my student 
//Mine refatctor
#include<stdio.h>

int charcount(char a[],char b);

int main(){
    char a[100];
    char b;
    scanf("%c \n",&b);

    fgets(a, 100 , stdin);
    
    printf("%d",charcount(a, b));
}

int charcount(char a[],char b){
    int c=0;
    for(int i=0; a[i]!='\0'; i++){
        if(a[i]==b){
            c=c+1;
        }
    }
    return c;
}
