t = [-10:.01:10] ;

x = sin(2.*pi.*t);

y1 = x.^2 ;

y2 = t.*x ;

figure(1)
plot(t,x);
figure(2)
plot(t,y1); 
figure(3)
plot(t,y2);