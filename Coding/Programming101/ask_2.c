#include<stdio.h>

int main(){
    int x;
    int max=-1;
    int n=0;
    int z=0;
    float mo;

    do{
        scanf("%d",&x);
        if(x>max){
            max=x;
        }
        if(x%2==0 && x>0){
            z+=x;
            n+=1;

        }

    }while(x>-1);
    mo=(float) z/n;
    printf("%d\n",max);
    printf("%f",mo);

    return 0;

}