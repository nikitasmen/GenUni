
syms t  s ; 
x = exp(t) ; 
f = (-t)^4*x ; 
ans1 = laplace(f,t,s) 
X = laplace(x,t,s)
ans2 = diff(X,4)
X = ilaplace(X,s,t)
ezplot(X , [0 100])