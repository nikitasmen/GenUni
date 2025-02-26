cd("C:\Users\menou\OneDrive\Desktop\sxolh\simata_sistimata")
t = [-5:0.01:5] ; 

x = unit_func(0,-5,5,0.01) - unit_func(2,-5,5,0.01);
y1 = 3.*x;
y2 = x +( unit_func(2,-5,5,0.01) - unit_func(4,-5,5,0.01));

figure(1)
plot(t,x,'color' , 'r');
hold on ;
plot(t,y1,'color' , 'g');

plot(t,y2,'color','b'); 