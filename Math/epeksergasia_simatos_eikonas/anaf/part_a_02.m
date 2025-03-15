%declare constans 
A = 0.3;          %amplitude
N = 1000;         %length of samples length of x
tinit = 0.001;    %initial time 
tfinal = 1;       %final time 
Ts = 0.001;       %sampling period
t = tinit:Ts:tfinal;  %vector of time 
fs = 1./Ts ;      %sampling frequency

y = A.*(rand(1,N)-0.5);    %signal y 

%plot of signal x(t)
figure(1)
plot(t,y)
xlabel('time (s)')
ylabel('amplitude')
title('y(t)')


Y = fft(y,N); %Discrete Fourier Transform of y with N points 

Power_spectrum_Y = abs(Y);  %power spectrum of Y 
Power_spectrum = Power_spectrum_Y(1:N/2+1); %power spectrum is symmetric about zero 
df = fs/N;      %time between two consecutive frequencies
freq = 0:df:fs/2;   %frequency of X start from 0 up to Nyquist frequency 

%plot of signal X
figure(2)
stem(freq,Power_spectrum)
xlabel('frequency')
ylabel('magnitude ')
title('Y(w)')

