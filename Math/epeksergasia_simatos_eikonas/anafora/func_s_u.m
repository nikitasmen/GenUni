function [s] = func_s_u(n , k2)

%if n is greater than 0 and k2,or smaller than 0, the vector has a value of 0
%if n is smaller than k2 and bigger than 0 , the vector has a value of 1 
s = [(n>=0)-(n>=k2)]; 

end

