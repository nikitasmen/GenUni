function [s] = func_s(t,k1,k2)

s = [(t-k1)==0 | (t-k2)==0]; %if t is equal to k1 or k2 the vector has a value of 1, else 0 

end