clear
clc
close all
load('matfiles\IP_MODEL.mat')

%% Controller tuning
%  LQR gains
% State = [alpha(x), alpha rate, Beta(z), Beta rate, motor current]
Qr = diag([250, 0, 50, 0, 0]); %Weight Matrix for x

Rr = 0.005; %Weight for the input variable (Motor voltage) 
% Lower bound = 0.01
% Upper bound = 10 (it doesnt change anymore)

K = lqr(A, B, Qr, Rr); %Calculate feedback gain  

%% Calculate observer gains
G = eye(size(A)); %Gain of the process noise 

% State = [alpha(x), alpha rate, Beta(z), Beta rate, motor current]
we = 10;
rv = 1;

Qe = we*diag([10,1,1,1,1]); %Variance of process errors

% Output= [alpha(x), Beta(z)]
Re = rv*diag([1,1]); %Variance of measurement errors 

L = lqe(A, G, C, Qe, Re); %Calculate estimator gains

%---------------------------------------------------------------------- 
%% Simulation parameters 
alpha = 20;
beta = 0;
x0=[deg2rad(alpha) 0 deg2rad(beta) 0 0].'; 
D_O= zeros(1,2); % For identity matrix 

% Noise
use_output_noise = 0;
output_noise_power = 1;

use_input_noise = 0;
input_noise_power = 0.1;

use_deadzone = 1;
use_deadzone_compensation = 1;

if use_deadzone
    deadzone_lower = -0.38;
    deadzone_higher = 0.25;
else
    deadzone_lower = 0;
    deadzone_higher = 0;
end

deadzone_parameters = [deadzone_lower,deadzone_higher, use_deadzone_compensation];

T=10; % Time duration of the simulation 
out = sim('SimulatorLQGmodel',T);

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
plot(out.t,out.u,out.t,out.u_sat,'LineWidth',1.5)
yline(0,'-')
title('Input behavior')
xlabel('Time (s)','Fontsize',14)
ylabel('Input (Volts)','Fontsize',14)
ylim([-5 5])
legend
legend('Controller u','Saturated u')

figure
plot(out.t,out.x,out.t,out.x_estimated,'LineWidth',1.5)
yline(0,'-')
title('Estimation comparison')
xlabel('Time','Fontsize',14)
ylabel('States comparison','Fontsize',14)

%% Error 
t_steady = out.t > 5; 
error = y_degrees(t_steady,:);

RMSE = sqrt(sum(error.^2)/size(error,1))

action = out.u_sat(t_steady,:);

RMSE_action = sqrt(sum(action.^2)/size(action,1))
