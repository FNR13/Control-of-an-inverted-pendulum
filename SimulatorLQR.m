clear
clc
close all

load("matfiles\IP_MODEL.mat")

%% Controller tuning
% State = [alpha(x), alpha rate, Beta(z), Beta rate, motor current]
Qr = diag([10,0,1,0,0]); %Weight Matrix for x
%Qr = diag([100,1,100,10,0.1]); %Weight Matrix for x

Rr = 0.1; %Weight for the input variable (Motor voltage)
% Lower bound = 0.01
% Upper bound = 10 (it doesnt change anymore)

K = lqr(A, B, Qr, Rr); %Calculate feedback gain 

%% Simulation parameters 
x0=[pi/2 0 0.1 0 0].'; 
% D=[0 0 0 0 0].'; % For identity matrix 

% Noise
use_output_noise = 1;
output_noise_power = 10;

use_input_noise = 1;
input_noise_power = 10;

T=5; % Time duration of the simulation 
out = sim("SimulatorLQRmodel",T);

gg=plot(out.t,out.y); 
set(gg,"LineWidth",1.5) 

title("Output behavior")
yline(0,'-')

gg=xlabel("Time (s9"); 
set(gg,"Fontsize",14); 

gg=ylabel("beta (rad)"); 
set(gg,"Fontsize",14); 

legend
legend("alpha(x)","beta(z)")

figure
plot(out.t,out.u,out.t,out.u_sat,"LineWidth",1.5)
yline(0,'-')
title("Input behavior")
xlabel("Time","Fontsize",14)
ylabel("Input(Volts)","Fontsize",14)
legend
legend("Controller u","Saturated u")
