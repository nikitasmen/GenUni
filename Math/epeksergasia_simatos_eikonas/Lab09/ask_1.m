[y,fs]=audioread('test_sound.wav') ;
%sound(y,fs) 
Ts = 1/fs ; 
t = [0:length(y)-1]*Ts; 
figure(1) 
plot(t, y);

L=length(t);
Y=fft(y);
freq=0:(fs/L):(fs/2);
power_spectrum_Y=abs(Y/L);
P1 = power_spectrum_Y(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);

figure(2)
stem(freq,P1)

z = y ;
ftone= 2000;
n=[1:length(z)]';
noise = 0.2*sin(2*pi*(ftone/fs)*n); 
z_noise=z+noise;
%sound(z_noise,fs)

L=length(t);
Z_noise=fft(z_noise);
freq=0:(fs/L):(fs/2);
power_spectrum_z_noise=abs(Z_noise/L);
P2 = power_spectrum_z_noise(1:L/2+1);
P2(2:end-1) = 2*P2(2:end-1);
figure(3)
stem(freq,P2)


 
n=45;
wn = ftone/(fs/2);
b = fir1(n , wn , 'low');
z_rectified = filter(b,1,z_noise);
sound(z_rectified,fs)

L=length(t);
Z_REC=fft(z_rectified);
freq=0:(fs/L):(fs/2);
power_spectrum_z_rec=abs(Z_REC/L);
P3 = power_spectrum_z_rec(1:L/2+1);
P3(2:end-1) = 2*P3(2:end-1);

figure(4)
stem(freq,P3)

y_rec = ifft(y_rec) ;
figure(5)
plot(t,y_rec);

