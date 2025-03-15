n1 = [-1:1:2];  %create discrete time vector n1 for x1[n]
n2 = [1:1:3];   %create discrete time vector n2 for x2[n]

x1 = [4 5 6 7]; %create a vector x1 with the amplitudes of x1[n]  
x2 = [3 2 1];   %create a vector x2 with the amplitudes of x2[n]  

figure(1)       %create figure 1 
subplot(2,1,1); 
stem(n1,x1);    %in figure 1 plot x1[n]
title('x1[n]');
xlabel('n');
ylabel('amplitude');

subplot(2,1,2);
stem(n2,x2);    %and x2[n]
title('x2[n]');
xlabel('n');
ylabel('amplitude');

x = conv(x1,x2); %x <- concolution of x1 and x2
n = [n1(1)+n2(1): 1 :n1(end)+n2(end)]; %create the discrete time vector n for x[n]

figure(2)       %in figure 2 
stem(n,x)       %plot x[n]
title('x[n]= x1[n]*x2[n]');
xlabel('n');
ylabel('amplitude');
