load("matfiles\IP_MODEL.mat")

% Calcualte LQR gains
Qr = diag([10,0,1,0,0]); %Weight Matrix for x 
Rr = 1; %Weight for the input variable 

K = lqr(A, B, Qr, Rr); %Calculate feedback gain 

% Calculate observer gains
G = eye(size(A)); %Gain of the process noise 
Qe = eye(size(A))*10; %Variance of process errors 
Re = eye(2); %Variance of measurement errors 

L = lqe(A, G, C, Qe, Re); %Calculate estimator gains

%---------------------------------------------------------------------- 
% Simulate controller 
x0=[0.1 0 0 0 0].'; 
y0 = C * x0;
% D=[0 0 0 0 0].'; % For identity matrix 
D_O = zeros(1,2);
T=10; % Time duration of the simulation 
sim("SimulatorLQGmodel",T); 

gg=plot(out.t,out.y); 
set(gg,"LineWidth",1.5) 

gg=xlabel("Time (s9"); 
set(gg,"Fontsize",14); 

gg=ylabel("\beta (rad)"); 
set(gg,"Fontsize",14); 