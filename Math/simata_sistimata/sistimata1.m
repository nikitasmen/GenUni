cd("C:\Users\menou\OneDrive\Desktop\sxolh\simata_sistimata")
t = [0:.1:5] ; 
x1 = unit_func(0,0,5,0.1);
x2 = 2.*unit_func(1,0,5,0.1);
y1 = unit_func(0,0,5,0.1) +2.*unit_func(1,0,5,0.1) ;
y2 = unit_func(0,0,5,0.1) -2.*unit_func(1,0,5,0.1) ;

figure(1) ; 
hold on;
plot(t,x1, 'color', "r");
hold on ;
plot(t,x2,'color',"b");

figure(2);
 
hold on;
plot(t,y1, 'color', "r");
hold on ;
plot(t,y2,'color',"b");
