cd("C:\Users\menou\OneDrive\Desktop\sxolh\simata_sistimata")

t = [-2:.01:4];
x = unit_func( 0,-2,4,0.01)-unit_func(2,-2,4,0.01);

y2 = unit_func(2,-2,4,0.01);
plot(t,x);

hold on; 
plot(t , y2 , 'color' , 'r');
