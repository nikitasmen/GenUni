
clear all, close all, clc
%system's constants
k = 2 ; m1 = 50+k ; m2 = 40-k; k1 = 500-(10*k); k2 = 600+(10*k); c1 = 50-(3*k); c2= 80+(3*k);
%matrix A 
A = [ 0             0           1           0;
      0             0           0           1;
      (-k1-k2)/m1   k1/m1       (-c1-c2)/m2 c2/m1;
      k2/m2         -k2/m2      c2/m2       -c2/m2];
%matrix B   
B = [ 0     0;
      0     0; 
      1/m1  0;
      0     1/m2];
%matrix C   
C = [ 1    0   0   0;
      0    1   0   0;
      k1   0   0   0;
      0    0  c1   0;
      -k2  k2  0   0;
      0    0   c2  -c2];
%matrix D    
D = [ 0 0 ; 0 0; 0 0; 0 0; 0 0; 0 0];

% Characteristic polynomial of the system
char_poly = poly(A)
% System poles
p = roots(char_poly)
%transfer functions 
[num1 , den1]= ss2tf(A,B,C,D,1);%input f1
[num2 , den2]= ss2tf(A,B,C,D,2);%unput f2
%show the tfs 
printsys(num1,den1,'s') 
printsys(num2,den2,'s')
% Gains
[zeros1,poles1,kapa1] = tf2zp(num1,den1)
[zeros2,poles2,kapa2] = tf2zp(num2,den2)
%DC Gain
K = dcgain(A,B,C,D)
%time constant
taf = 1./abs(real(p))
%natural frequencies and damping ratio for every pole 
[omega_n,zeta] = damp(char_poly)
%damping frequencies
omega_d = omega_n.*sqrt(1-zeta.^2)

% Define the 4 systems TFs
sys_x1f1 = tf(num1(1,:),den1);%x1/f1
sys_x1f2 = tf(num2(1,:),den2);%x1/f2
sys_x2f2 = tf(num2(2,:),den2);%x2/f2
sys_x2f1 = tf(num1(2,:),den1);%x2/f1
%presentation of frequency response functions of
%x1/f1
figure(1),step(sys_x1f1)
S1 = stepinfo(sys_x1f1)
%x1/f2
figure(2),step(sys_x1f2)
S2 = stepinfo(sys_x2f2)
%x2/f2
figure(3),step(sys_x2f2)
S3 = stepinfo(sys_x1f2)
%x2/f1
figure(4),step(sys_x2f1)
S4 = stepinfo(sys_x2f1)

%create f1 input signal 
t1 = 0:0.02:10;
f1 = 4*1*2.*sin(2.*t1);
%Plot simulated time response of x1 and x2 
figure(7),lsim(sys_x1f1,f1,t1)
figure(8),lsim(sys_x2f1,f1,t1)

%create f2 input signal 
f2(1) = 2*randn();
t2 = 0:0.02:100;
for i = 2:1:length(t2)
    f2(i) = f2(i-1)+2*randn();
end 
%Plot simulated time response of x1 and x2 
figure(9),lsim(sys_x1f2,f2,t2)
figure(10),lsim(sys_x2f2,f2,t2)
