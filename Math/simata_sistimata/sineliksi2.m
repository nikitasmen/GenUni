st = 0.01 ;
t =0 : st : 6;
t1 =  4+st: st :6;
t2 =  0: st : 1.5;
t3 = 1.5+st : st : 4  ;
x1 = zeros(size(t1));
x2 = (ones(size(t2)))-0.4;
x3 = (ones(size(t3)))-0.7 ; 
x =[x2 x3 x1]; 

h = exp(-t);
figure(1); 
plot(t,h);
hold on ;
plot(t,x,'color','r');
hold off;


figure(2);
ty = 0: st :12;

y = conv(x,h).*st;
ty = ty-1 ;  
plot(ty,y);