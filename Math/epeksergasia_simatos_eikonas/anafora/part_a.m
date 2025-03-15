clear
clc 
close all

n = -5:5 ;  %-5<=n<=5
k1 = 0 ;    %tl20412 , tl20411
k2 = 4 ;    
s = func_s(n , k1 ,k2) 

stem(n,s) %plot the vector s 
xlabel('n')
ylabel('amplitude')