clear
clc
close all

k2 = 4; %tl20412 , tl20411

n1 = -2*k2:2*k2; 
s1 = func_s_u(n1,4) %create s1

n2 = -k2:k2;
s2 = 2.*func_s_u(n2,4) %create s2

subplot(2,1,1);
stem(n1,s1) %plot s1 in subplot(2,1,1)
xlabel('n');
ylabel('amplitude');

subplot(2,1,2);
stem(n2,s2) %plot s1 in subplot(2,1,2)
xlabel('n');
ylabel('amplitude');