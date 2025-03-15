fc = 2000;
fs = 8000; 
wn = fc /(fs/2);
n = 5 ; 
b = fir1(n,wn,'low')
figure(1);
freqz(b);
[H1,w1] = freqz(b,1,512,fs);
figure(2);
freqz(H1)
n=[0 : 1 : 5];
figure(3);
stem(n,b);


n = 6; 
fc1 = 5000; 
fs1 = 12000;
wn = fc1 /(fs1/2);
b2 = fir1(n,wn,'high')
figure(4);
freqz(b2);
[H2,w2] = freqz(b2,1,512,fs1);
figure(5);
freqz(H2)
n=[0 : 1 : 6];
figure(6);
stem(n,b2);


fs2 = 10000;
fc2 = 2000;
fc3 = 4000;
wn1 = fc2 /(fs2/2);
wn2 = fc3 /(fs2/2);
wn = [wn1  wn2];
n = 8 ; 
b3 = fir1(n,wn,'bandpass')
figure(7);
freqz(b3);
[H3,w3] = freqz(b2,1,512,fs2);
figure(8);
freqz(H3)
n=[0 : 1 : 8];
figure(9);
stem(n,b3);


