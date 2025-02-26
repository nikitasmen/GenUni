cd("C:\Users\menou\OneDrive\Desktop\sxolh\simata_sistimata")

n = 0:20;
x = n.*(unit_func(0,0,20) - unit_func(10,0,20)) + 10.*exp(-0.3.*(n-10)).*( unit_func(10,0,20) - unit_func(20,0,20));
nz = 0:10;
enerx = sum(abs(x(1:11)).^2);
stem(nz,z);
stem(n,x);

