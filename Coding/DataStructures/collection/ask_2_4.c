#include<stdio.h>
#include<string.h>

int main(){
    char x[100];
    char y[100];
    char stack[100];
    char *stacktop=stack;
    char *ptry=y;
    int i ;
    fgets(x,100,stdin);
    for( i=0;i<100;i++){
        if(x[i]=='{' || x[i] =='(' || x[i] =='[' || x[i] =='}' || x[i] ==']' || x[i] ==')'){
            *ptry=x[i];
            ptry++;
        }
    }
    for(i=0; i<100 ;i++){
        if(y[i]=='{'|| x[i] =='(' || x[i] =='['){
            stacktop++;
            *stacktop=y[i];
            printf("%c",*stacktop);
        }
        else {
            if(y[i]=='}'&&*stacktop=='{'){
                stacktop--;
            }
            else if(y[i]==')'&&*stacktop=='('){
                stacktop--;
            }
            else if(y[i]==']'&&*stacktop=='['){
                stacktop--;
            }
            else if (y[i]==NULL){
                printf("All good");
                break;  
            }
            else{
                printf("lathos");
                break;
            }
        }
    }

    return 0;
}