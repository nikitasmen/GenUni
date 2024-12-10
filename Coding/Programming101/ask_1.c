#include<stdio.h>
#define fpa1 100
#define fpa2 200
#define fpa3 300

int main(){
    int fpa;
    float k;
    int flag;
    do{
        flag = 0 ; 
        scanf("%d",&fpa);
        scanf("%f",&k);
        if(k>0){
            switch(fpa){
                case fpa1:
                    k+=k*0.13;
                    printf("%f",k);
                    break;
                case fpa2:
                    k+= k*0.24;
                    printf("%f",k);
                    break;
                case fpa3:
                    k+= k*0.10;
                    printf("%f",k);

                    break;
                default:
                    printf("lathos kathgoria");
                    flag=1;
                    break;

            }
        }
        else{
            flag=1;
            printf("lathos kostos");
        }
    }
    while(flag=1);
    return 0;
}
