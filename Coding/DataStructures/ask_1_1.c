//Some refactor 
#include<stdio.h>

int retSum(int sum,int x);
float retAvg(int sum,int count);
int retMax(int max,int x);
int retMin(int min,int x);


int main(){
    int x, sum=0, count=0;    
    float avg= 0;   

    scanf("%d \n",&x);
    int max= x, min= x;   

    while(x!=0){
        sum=retSum(sum,x);
        count++;
        avg = retAvg(sum, count); 
        max=retMax(max,x);
        min=retMin(min,x);
        scanf("%d",&x);
    
    }
    printf("%d %f %d %d ", sum, avg, max, min);
    return 0;
}


 int retSum(int sum,int x){
    sum=sum+x;
    return sum;
}  

 float retAvg(int sum,int count){
    float mo = (float) sum/count;
    return mo;
}
 
 int retMax(int max,int x){
    if(max<x){
        max=x;
    }
    return max;
}  
 int retMin(int min,int x){
    if(min>x){
        min=x;
    }
    return min;
}  
 