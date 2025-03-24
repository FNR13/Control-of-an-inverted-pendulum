clear
clc
close all
load('matfiles\IP_MODEL.mat')

% Question 1
fprintf('Q1 - Open loop System eigen values: ');
fprintf('%f ', eig(A).');
fprintf('\n');

% Question 2
fprintf('Q2 - Rank of observability matrix: %f \n',rank(ctrb(A,B)));

% Question 3
C1 = [0 0 1 0 0];  % C matrix for measuring only the pendulum angle (x3)
fprintf('Q3: \n')
fprintf('Observability matrix for case 1 (C = [0 0 1 0 0]): %f \n',rank(obsv(A, C1)));

C2 = [1 0 0 0 0; 0 0 1 0 0];  % C matrix for measuring x1 and x3
fprintf('Observability matrix for case 2 (C = [1 0 0 0 0; 0 0 1 0 0]): %f \n',rank(obsv(A, C2)));

% Question 4
sys = ss(A,B,C,D);
bode(sys)
% sys = ss(A,B,C1,0);
% rlocus(sys)
% [num, den] = ss2tf(A,B,C,D);
% G = tf(num,den);

% Question 5
% Regulator parameters
% State = [alpha(x), alpha rate, Beta(z), Beta rate, motor current]
Qr = diag([10,1,10,1,0]); %Weight Matrix for x
Rr = 0.005; %Weight for the input variable
K = lqr(A, B, Qr, Rr); %Calculate feedback gain
fprintf('Q5 - Regulator gains: ');
fprintf('%f ', K.');
fprintf('\n');