clear
clc
close all
load("matfiles\IP_MODEL.mat")

%% Controller tuning
%  LQR gains
% State = [alpha(x), alpha rate, Beta(z), Beta rate, motor current]
%Qr = diag([10,0,1,0,0]); %Weight Matrix for x
%Qr = diag([100,1,10,2,0]); %Weight Matrix for x

alpha = 0;
best_alpha = 0;
alpha_dot = 0;
best_alpha_dot = 0;
beta = 0;
best_beta = 0;
beta_dot = 0;
best_beta_dot = 0;
i = 0;
best_i = 0;
best_value = 1000000;
best_value_temp = 0;
N = 0;

%{
for alpha = [1 10 100]
    for alpha_dot = [0 1 10 100]
        for beta = [0 1 10 100]
            for beta_dot = [0 1 10 100]
                for i = [0 1 2 3 4 5]
                    for T = 5
                        %Qr = diag([alpha,alpha_dot,beta,beta_dot,i]); %Weight Matrix for x
                        %Qr = diag([10,0,1,0,0]); %Weight Matrix for x
    
                        Rr = 0.1; %Weight for the input variable (Motor voltage) 
                        % Lower bound = 0.01
                        % Upper bound = 10 (it doesnt change anymore)
                        
                        K = lqr(A, B, Qr, Rr); %Calculate feedback gain  
                        
                        % Calculate observer gains
                        G = eye(size(A)); %Gain of the process noise 
                        
                        % State = [alpha(x), alpha rate, Beta(z), Beta rate, motor current]
                        we = 10;
                        rv = 1;
                        
                        %Qe = we*diag([1,1,1,1,1]); %Variance of process errors
                        Qe = we*diag([1,1,1,1,1]); %Variance of process errors
                        
                        % Output= [alpha(x), Beta(z)]
                        Re = rv*diag([1,1]); %Variance of measurement errors 
                        
                        L = lqe(A, G, C, Qe, Re); %Calculate estimator gains
                        
                        %---------------------------------------------------------------------- 
                        %% Simulation parameters 
                        x0=[pi/2 0 0.1 0 0].'; 
                        D_O= zeros(1,2); % For identity matrix 
                        
                        % Noise
                        use_output_noise = 10;
                        output_noise_power = 100;
                        
                        use_input_noise = 0;
                        input_noise_power = 1;
                        
                        %T=10; % Time duration of the simulation 
                        out = sim("SimulatorLQGmodel",T);
    
                        N = N + 1;
                    end
                    disp(alpha)
                    disp(alpha_dot)
                    disp(beta)
                    disp(beta_dot)
                    disp(i)
                    best_value_temp = mean(abs(out.y(:, 1))) + mean(abs(out.y(:, 2)));
                    best_value_temp = (best_value_temp^2)/N;

                    if best_value_temp < best_value
                        best_value = best_value_temp;
                        best_alpha = alpha;
                        best_alpha_dot = alpha_dot;
                        best_beta = beta;
                        best_beta_dot = beta_dot;
                        best_i = i;
                    end
                    disp(best_value_temp)
                    best_value_temp = 0;
                    N = 0;
                end
            end
        end
    end
end

disp(best_value)
disp(best_alpha)
disp(best_alpha_dot)
disp(best_beta)
disp(best_beta_dot)
disp(best_i)

%}
                        



                    



Qr = diag([100,1,100,0,2]); %Weight Matrix for x

Rr = 0.1; %Weight for the input variable (Motor voltage) 
% Lower bound = 0.01
% Upper bound = 10 (it doesnt change anymore)

K = lqr(A, B, Qr, Rr); %Calculate feedback gain  

% Calculate observer gains
G = eye(size(A)); %Gain of the process noise 

% State = [alpha(x), alpha rate, Beta(z), Beta rate, motor current]
we = 10;
rv = 1;

%Qe = we*diag([1,1,1,1,1]); %Variance of process errors
Qe = we*diag([1,1,1,1,1]); %Variance of process errors

% Output= [alpha(x), Beta(z)]
Re = rv*diag([1,1]); %Variance of measurement errors 

L = lqe(A, G, C, Qe, Re); %Calculate estimator gains

%---------------------------------------------------------------------- 
%% Simulation parameters 
x0=[pi/2 0 0.1 0 0].'; 
D_O= zeros(1,2); % For identity matrix 

% Noise
use_output_noise = 1;
output_noise_power = 10;

use_input_noise = 0;
input_noise_power = 1;

T=5; % Time duration of the simulation 
out = sim("SimulatorLQGmodel",T);

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

figure
plot(out.t,out.x,out.t,out.x_estimated,"LineWidth",1.5)
yline(0,'-')
title("Estimation comparison")
xlabel("Time","Fontsize",14)
ylabel("States comparison","Fontsize",14)

