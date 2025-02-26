function [x,n]  = sima( n0 , n1 , n2 , n3 , n4)

if (n3>n4)
      error('arguments must be n3<=n4')
      
end

n = [n3:n4];
x = n0.*cos(n1 .*n +n2);

end 