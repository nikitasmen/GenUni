cd("C:\Users\menou\OneDrive\Desktop\sxolh\simata_sistimata")

t = [-10 : .01: 10 ] ; 
x = unit_func(0,-10,10,0.01) - unit_func(1,-10,10,0.01); 

y = t.*exp(-t).*(unit_func(0,-10,10,0.01)- unit_func(5,-10,10,0.01));

figure(1)

plot(t,x,'color', 'r');
hold on ; 
plot(t,y,'color' , 'b');

t = t-1;
x = unit_func(1,-10,10,0.01) - unit_func(2,-10,10,0.01); 
y = t.*exp(-t).*(unit_func(1,-10,10,0.01)- unit_func(6,-10,10,0.01));



figure(2)
plot(t,x,'color', 'r');
hold on ; 
plot(t,y,'color' , 'b');
