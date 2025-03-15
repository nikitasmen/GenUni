fc = 2000;
fs = 8000;
wn = fc /(fs/2);
n = 8 ; 
b = fir1(n , wn , 'low')

figure(1)
freqz(b)
title('n= 8')
[H1,w1] = freqz(b,1,512,fs);

n2 = 32 ;
b2 = fir1(n2 , wn , 'low')
figure(2)
freqz(b2)
title('n= 32')
[H2,w2] = freqz(b2,1,512,fs);

n3 = 128;
b3 = fir1(n3 , wn , 'low') 
figure(3)
freqz(b3)
title('n= 128')
[H3,w3] = freqz(b3,1,512,fs);
figure(4)
freqz(H1)
hold on;
freqz(H2)
freqz(H3)

lines = findall(gcf , 'type','line');
lines(1).Color = 'red';
lines(2).Color = 'green';
lines(3).Color = 'blue';
legend('H1','H2','H3');