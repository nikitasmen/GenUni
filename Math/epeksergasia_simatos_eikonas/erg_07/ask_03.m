n = [ 0 : 1 : 19] ; 
N = length(n) ; 
x = zeros(N,1); 
x(1:3) = 1 ;

k = -(N/2 ) : (N/2)-1; 
X = fft(x);
X = fftshift(X); 
Xm = abs(X) ; 
Xp = angle(X);

figure(1);
stem(n,x)
xlabel('time')
ylabel('amplitude')

figure(2)
stem(k,Xm)
xlabel('freq')
ylabel('amplitude')

figure(3) 
stem(k,Xp)
xlabel('freq')
ylabel('phase')

%inverse Fourier 
x1 = ifftshift(X) ; 
x1 = ifft(x1); 

figure(4)
stem(x1)
xlabel('time')
ylabel('amplitude')

xreal = real(x1); 
ximag = imag(x1);
figure(5)
p1 = stem(xreal);
hold on 
p2 =stem(ximag);
xlabel('time')
ylabel('amplitude')
legend([p1,p2],{'real(x)', 'imaginary(x)'})