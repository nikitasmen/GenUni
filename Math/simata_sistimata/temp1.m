t = 0: .1 : 10; 
z = t+pi./2;
s = 10.*exp(i*z);
figure(1);
hold on;
plot(t,s, 'color', "r");
hold on ;
plot(t,real(s),'color',"b");

hold on;
plot(t,imag(s), 'color',"b");
