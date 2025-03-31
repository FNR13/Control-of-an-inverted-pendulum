y_degrees = rad2deg(y);

figure
plot(time,y_degrees,'LineWidth',1.5); 
title('Output behavior')
yline(0,'-')
xlabel('Time (s)','Fontsize',14); 
ylabel('Output (degrees)','Fontsize',14); 
legend
legend('alpha(x)','beta(z)')

figure
plot(time,u,'LineWidth',1.5)
yline(0,'-')
title('Input behavior')
xlabel('Time (s)','Fontsize',14)
ylabel('Input (Volts)','Fontsize',14)
ylim([-5 5])

%% Error 
t_steady = time > 10; 
error = y_degrees(t_steady,:);

RMSE = sqrt(sum(error.^2)/size(error,1))

action = u(t_steady,:);

RMSE_action = sqrt(sum(action.^2)/size(action,1))
