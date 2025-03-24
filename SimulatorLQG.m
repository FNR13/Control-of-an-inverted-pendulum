clear
clc
close all
load('matfiles\IP_MODEL.mat')

%% Controller tuning
%  LQR gains
% State = [alpha(x), alpha rate, Beta(z), Beta rate, motor current]
Qr = diag([10, 1, 10, 1, 0]); %Weight Matrix for x

Rr = 0.005; %Weight for the input variable (Motor voltage) 
% Lower bound = 0.01
% Upper bound = 10 (it doesnt change anymore)

K = lqr(A, B, Qr, Rr); %Calculate feedback gain  

%% Calculate observer gains
G = eye(size(A)); %Gain of the process noise 

% State = [alpha(x), alpha rate, Beta(z), Beta rate, motor current]
we = 10;
rv = 1;

Qe = we*diag([1,1,1,1,1]); %Variance of process errors

% Output= [alpha(x), Beta(z)]
Re = rv*diag([1,1]); %Variance of measurement errors 

L = lqe(A, G, C, Qe, Re); %Calculate estimator gains

%---------------------------------------------------------------------- 
%% Simulation parameters 
x0=[0.1 0 0 0 0].'; 
D_O= zeros(1,2); % For identity matrix 

% Noise
use_output_noise = 0;
output_noise_power = 10;

use_input_noise = 0;
input_noise_power = 1;

use_deadzone = 0;
use_deadzone_compensation = 1;

if use_deadzone
    deadzone_lower = -0.38;
    deadzone_higher = 0.25;
else
    deadzone_lower = 0;
    deadzone_higher = 0;
end

deadzone_parameters = [deadzone_lower,deadzone_higher, use_deadzone_compensation];

T=30; % Time duration of the simulation 
out = sim('SimulatorLQGmodel',T);

gg=plot(out.t,out.y); 
set(gg,'LineWidth',1.5) 

title('Output behavior')
yline(0,'-')

gg=xlabel('Time (s9'); 
set(gg,'Fontsize',14); 

gg=ylabel('beta (rad)'); 
set(gg,'Fontsize',14); 

legend
legend('alpha(x)','beta(z)')

figure
plot(out.t,out.u,out.t,out.u_sat,'LineWidth',1.5)
yline(0,'-')
title('Input behavior')
xlabel('Time','Fontsize',14)
ylabel('Input(Volts)','Fontsize',14)
ylim([-5 5])
legend
legend('Controller u','Saturated u')

figure
plot(out.t,out.x,out.t,out.x_estimated,'LineWidth',1.5)
yline(0,'-')
title('Estimation comparison')
xlabel('Time','Fontsize',14)
ylabel('States comparison','Fontsize',14)

