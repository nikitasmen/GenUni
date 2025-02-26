cd('C:\Users\menou\OneDrive\Desktop\sxolh\simata_sistimata')
[x,n] = delta_func(-4,-5,5);
[y,d] = (delta_func(-3,-5,5));
[z,t] = delta_func(0,-5,5);
[w,f] = delta_func(1,-5,5); 
[c,m] = delta_func(2,-5,5);

full = x+(3.*y)+z+(2.*w)-c ; 

stem(n,full)


