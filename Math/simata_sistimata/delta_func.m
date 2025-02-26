function[x,n] = delta_func(n0,n1,n2)

if((n0<n1)|(n0>n2)|(n1>n2))
    error('arguments must be n1<=n0<=n2')
end

n = [n1:n2];
x = [(n-n0)==0]
end