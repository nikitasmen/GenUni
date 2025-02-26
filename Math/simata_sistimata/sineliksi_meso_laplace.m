syms t s ; 
x1 = heaviside(t) - heaviside(t-2);

x2 = (1-t)*(heaviside(t) - heaviside(t-1));

X1 = laplace(x1 , t ,s ); 
X2 = laplace(x2 , t , s); 

ans = ilaplace(X1*X2,s,t); 
figure('Color' , [1 1 1]);
f = ezplot(ans,[0 4]);
xlabel('\tau' , 'FontSize' , 24);
ylabel('x*y' , 'FontSize' , 10);
set (gca , 'FontSize' , 18);
set (f , 'Color' , 'k' , 'LineWidth' , 2 ); 
title('');