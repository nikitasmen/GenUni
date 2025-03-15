%create constants 
a = 1;      %amplitude
w = 10 ;    %frequency
N = 1000;  %number of samples 
n = [1:1:N]; %discrete time 
h1 = [0.1 0.8 0.1]; %create h1 
h2 = [0.05 0.1 0.2 0.3 0.2 0.1 0.05]; %create h2 

x = a*sin((2*pi*w*n)/N); %create equation x[n]

xnoise = x + (0.8*(rand(1,N)-0.5)); %add noise in x[n]

d = x-xnoise; 
RMSE = sqrt(dot(d,d)/N) %Root Mean Squared Error calculation for noise 

xsmoothed1 = conv(xnoise , h1); %smoothing of xnoise 
d1 = x-xsmoothed1(1:N); %x - xsmooth is not equal because of conv, so change the range (1:N)
RMSE1 = sqrt(dot(d1,d1)/N) %Root Mean Squared Error calculation for smoothing  


xsmoothed2 = conv(xnoise , h2); %smoothing of xnoise 
d1 = x-xsmoothed2(1:N); %x - xsmooth is not equal because of conv, so change the range (1:N)
RMSE2 = sqrt(dot(d1,d1)/N) %Root Mean Squared Error calculation for smoothing  

figure(1)
hold on 
stem(xnoise,'g')
stem(xsmoothed1(1:N),'r')   %plot smoothed1 from 1 to N 
stem(xsmoothed2(1:N),'bl')                 %plot x 
grid on 
grid minor 
legend('xnoise','xsmoothed1','xsmoothed2')
