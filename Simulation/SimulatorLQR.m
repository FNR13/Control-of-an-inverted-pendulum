clear
clc
close all

load("matfiles\IP_MODEL.mat")

%% Controller tuning
% State = [alpha(x), alpha rate, Beta(z), Beta rate, motor current]
Qr = diag([10,1,10,1,0]); %Weight Matrix for x
%Qr = diag([100,1,100,10,0.1]); %Weight Matrix for x

Rr = 0.1; %Weight for the input variable (Motor voltage)
% Lower bound = 0.01
% Upper bound = 10 (it doesnt change anymore)

K = lqr(A, B, Qr, Rr); %Calculate feedback gain 

%% Simulation parameters 
alpha = 90;
beta = 35;
x0=[deg2rad(alpha) 0 deg2rad(beta) 0 0].'; 
% D=[0 0 0 0 0].'; % For identity matrix 

% Noise
use_output_noise = 1;
output_noise_power = 10;

use_input_noise = 1;
input_noise_power = 10;

% Deadzone
use_deadzone = 1;
use_deadzone_compensation = 0;

if use_deadzone
    deadzone_lower = -0.38;
    deadzone_higher = 0.25;
else
    deadzone_lower = 0;
    deadzone_higher = 0;
end

deadzone_parameters = [deadzone_lower,deadzone_higher, use_deadzone_compensation];

T=10; % Time duration of the simulation 
out = sim("SimulatorLQRmodel",T);

%% Plotting
y_degrees = rad2deg(out.y);

figure
plot(out.t,y_degrees,'LineWidth',1.5); 
title('Output behavior')
yline(0,'-')
xlabel('Time (s)','Fontsize',14); 
ylabel('Output (degrees)','Fontsize',14); 
legend
legend('alpha(x)','beta(z)')

figure
plot(out.t,out.u,out.t,out.u_sat,"LineWidth",1.5)
yline(0,'-')
title("Input behavior")
xlabel("Time (s)","Fontsize",14)
ylabel("Input (Volts)","Fontsize",14)
legend
legend("Controller u","Saturated u")

%% Error 
t_steady = out.t > 5; 
error = y_degrees(t_steady,:);

RMSE = sqrt(sum(error.^2)/size(error,1))

action = out.u_sat(t_steady,:);

RMSE_action = sqrt(sum(action.^2)/size(action,1))
