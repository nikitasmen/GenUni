%declare constans 
Ts = 0.001; %sampling period 
A1 = 4 ; %amplitude 
A2 = 0.3;
f1 = 3 ; %frequency 
f2 = 10;
tinit = 0.001;  %initial time 
tfinal = 2;     %final time 
t = tinit:Ts:tfinal;    %vector of time 
fs = 1./Ts ;    %sampling frequency 

N = length(t);  %length of samples length of x
x = A1.*sin(2*pi*f1.*t)+ A2.*cos(2*pi*f2.*t);  %signal x 

%plot of signal x(t)
figure(1)
plot(t,x)
xlabel('time (s)')
ylabel('amplitude')
title('x(t)')

X = fft(x,N); %Discrete Fourier Transform of x with N points 

Power_spectrum_X = abs(X);  %power spectrum of X 
Power_spectrum = Power_spectrum_X(1:N/2+1); %power spectrum is symmetric about zero 
df = fs/N;      %time between two consecutive frequencies
freq = 0:df:fs/2;   %frequency of X start from 0 up to Nyquist frequency 

%plot of signal X
figure(2)
stem(freq,Power_spectrum)
xlabel('frequency')
ylabel('magnitude ')
title('X(w)')
