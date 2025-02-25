syms t s Y 
X = laplace(exp(-3*t),t,s); 
y0 = 1 ; 
yp0 = 1 ; 
Y1 = s*Y - y0;
Y2 = s*Y1 - yp0; 

G = Y2 + 2*Y1 + 5*Y - X
SOL = solve(G , Y) 

yt = ilaplace(SOL , s , t ) 

check = simplify(diff(yt , 2) + 2*diff(yt,1) + 5*yt - exp(-3*t))