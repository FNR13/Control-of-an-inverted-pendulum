clear
clc
close all

load("matfiles\IP_MODEL.mat")

%% Controller tuning
% State = [alpha(x), alpha rate, Beta(z), Beta rate, motor current]
Qr = diag([10,0,1,0,0]); %Weight Matrix for x 

Rr = 1; %Weight for the input variable (Motor voltage)

K = lqr(A, B, Qr, Rr); %Calculate feedback gain 

%% Simulation parameters 
x0=[0.3 0 0.1 0 0].'; 
% D=[0 0 0 0 0].'; % For identity matrix 

% Noise
use_output_noise = 1;
use_input_noise = 1;

T=2; % Time duration of the simulation 
out = sim("SimulatorLQRmodel",T);

gg=plot(out.t,out.y); 
set(gg,"LineWidth",1.5) 

gg=xlabel("Time (s9"); 
set(gg,"Fontsize",14); 

gg=ylabel("beta (rad)"); 
set(gg,"Fontsize",14); 

legend
legend("alpha(x)","beta(z)")

figure
plot(out.t,out.u,"LineWidth",1.5)
xlabel("Time","Fontsize",14)
ylabel("Input(Volts)","Fontsize",14)
