cd("C:\Users\menou\OneDrive\Desktop\sxolh\simata_sistimata")

t = 0 : 0.01 : 2 ; 

x = ones(size(t)) ; 

t1 = 0:0.01 : 1 ; 
t2 = 1.01:0.01 :2 ; 

h1 = 1 - t1 ; 
h2 = zeros(size(t2)); 

h = [h1 h2] ; 
plot(t,h);
hold on ;
plot(t,x,'color' ,'r');

%%convolution
ty = 0:0.01:4 ;
y = conv(x,h).*0.01;
hold off;
figure(2);
plot(ty,y,'color' , 'g');

%%deconvolution
figure(3); 
yy = deconv(y,x).*(1/0.01);
plot(t,yy);