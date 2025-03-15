%create constants 
a = 1;      %amplitude
w = 10 ;    %frequency
N = 1000;  %number of samples 
n = [1:1:N]; %discrete time 

x = a*sin((2*pi*w*n)/N); %create equation x[n]

figure(1)
stem(n,x)   %plot x[n] using stem in figure 1 
xlabel('sample number (discrete time n)')
ylabel('x[n]')
grid on
grid minor
title('signal using stem')

figure(2)
plot(n,x)   %plot x[n] using plot in figure 2 
xlabel('sample number (discrete time n)')
ylabel('x[n]')
grid on
grid minor
title('signal using plot')
