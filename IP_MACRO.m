% ------------------------------
% CMNO 2024/2025 - Alberto Vale
% ------------------------------
clear 
clc
% Load state model
load('matfiles\IP_MODEL.mat')

% Constraints
V_MAX = 5; % Maximum motor voltage
V_MIN = -5; % Minimum motor voltage

ALPHA_MAX = 90 * pi/180; % Maximum angle accepted for motor shaft
BETA_MAX = 15 * pi/180; % Maximum angle before falling
TIME_DELAY = 6; % seconds before start

T = 30; % Time duration of the simulation
Ts = 0.001; % Sampling time

% Regulator parameters
% State = [alpha(x), alpha rate, Beta(z), Beta rate, motor current]
Qr = diag([10,1,10,1,0]); %Weight Matrix for x
Rr = 0.005; %Weight for the input variable
K = lqr(A, B, Qr, Rr); %Calculate feedback gain

% Estimator parameters
G = eye(size(A)); %
Qe = eye(size(A))*10; %Variance of process errors
Re = eye(2); %Variance of measurement errors
L = lqe(A, G, C, Qe, Re); %Calculate estimator gains

% Deadzone parameters
deadzone_low = -0.38;
deadzone_high = 0.25;
use_deadzone = 1;

deadzone_parameters = [deadzone_low,deadzone_high,use_deadzone];

