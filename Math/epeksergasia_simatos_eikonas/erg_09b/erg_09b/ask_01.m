fc = 2000;
fs = 20000;
n = 3; 
wn = fc/(fs/2); 

b_fir = fir1(n , wn , 'low');
[h_fir,w] = freqz(b_fir , 1 , 200); 
figure(1) 
plot(w,abs(h_fir)); 
[h_fir,f] = freqz(b_fir , 1 , 200,fs ); 
figure(2) 
plot(f,abs(h_fir)); 

[b_butter , a_butter] = butter(n,wn,'low');
[h_butter,w1]  = freqz(b_butter,a_butter , 200); 
figure(3) 
plot(w1,abs(h_butter));
[h_butter,f1]  = freqz(b_butter,a_butter , 200,fs); 
figure(4) 
plot(f1,abs(h_butter));


[b_cheby1 , a_cheby1] = cheby1(n,0.5,wn,'low');
[h_cheby1,w2]  = freqz(b_cheby1,a_cheby1 , 200); 
figure(5) 
plot(w2,abs(h_cheby1));
[h_cheby1,f2]  = freqz(b_cheby1,a_cheby1 , 200,fs); 
figure(6) 
plot(f2,abs(h_cheby1));


[b_ellip , a_ellip] = ellip(n,0.5,20,wn,'low');
[h_ellip,w3]  = freqz(b_ellip,a_ellip , 200); 
figure(7) 
plot(w3,abs(h_ellip));
[h_ellip,f3]  = freqz(b_ellip,a_ellip, 200,fs); 
figure(8) 
plot(f3,abs(h_ellip));

%plot all fs diagramms together with hold on 
figure(9) 
hold on ; 
plot(f3,abs(h_ellip));
plot(f2,abs(h_cheby1));
plot(f,abs(h_fir));
plot(f1,abs(h_butter));
legend('Elliptical','Chebyschev','FIR','Butterworth')




%EROTHMA E 
n=6;
f1 = 2000; 
f2 = 5000; 
wn = [ f1/(fs/2) f2/(fs/2)];


b_fir = fir1(n , wn , 'bandpass'); 
[h_fir,w] = freqz(b_fir , 1 , 200); 
figure(10) 
plot(w,abs(h_fir)); 
[h_fir,f] = freqz(b_fir , 1 , 200,fs ); 
figure(11) 
plot(f,abs(h_fir)); 

[b_butter , a_butter] = butter(n,wn,'bandpass');
[h_butter,w1]  = freqz(b_butter,a_butter , 200); 
figure(12) 
plot(w1,abs(h_butter));
[h_butter,f1]  = freqz(b_butter,a_butter , 200,fs); 
figure(13) 
plot(f1,abs(h_butter));


[b_cheby1 , a_cheby1] = cheby1(n,0.5,wn,'bandpass');
[h_cheby1,w2]  = freqz(b_cheby1,a_cheby1 , 200); 
figure(14) 
plot(w2,abs(h_cheby1));
[h_cheby1,f2]  = freqz(b_cheby1,a_cheby1 , 200,fs); 
figure(15) 
plot(f2,abs(h_cheby1));


[b_ellip , a_ellip] = ellip(n,0.5,20,wn,'bandpass');
[h_ellip,w3]  = freqz(b_ellip,a_ellip , 200); 
figure(16) 
plot(w3,abs(h_ellip));
[h_ellip,f3]  = freqz(b_ellip,a_ellip, 200,fs); 
figure(17) 
plot(f3,abs(h_ellip));

figure(18)
hold on ; 
plot(f3,abs(h_ellip));
plot(f2,abs(h_cheby1));
plot(f1, abs(h_butter));
plot(f,abs(h_fir)); 
legend('Elliptical','Chebyschev','Butterworth','FIR')


