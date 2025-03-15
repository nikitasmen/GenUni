a = 1;     
w = 10 ;    
N = 1000;  
n = 1:1:N; 
x = a*sin((2*pi*w*n)/N); 
xnoise = x + (0.8*(rand(1,N)-0.5));
d = x-xnoise; 
RMSE = sqrt(dot(d,d)/N)
