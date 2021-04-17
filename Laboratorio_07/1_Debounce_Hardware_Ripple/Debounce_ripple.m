% Tensao Maxima da Onda quadrada - Note que o valor minimo é 0.
Vcc = 5;

% Valor minimo que meu capacitor pode atingir enquanto esta descarregando
VLimit = Vcc-0.8;

% Frequencia do sinal de entrada
freq = 1000;

% Periodo do sinal de entrada
periodo = 1/freq

% Pontos de tempo para simulacao
t = 0:periodo/100:periodo;

% Capacitancia para o circuito RC
C = 10*(10^(-6));

% Resistencia para o circuito RC
R = 1000;

% Tensao quando a onda quadrada esta em seu valor alto
Vopen = Vcc*(1-exp(-t/(C*R)));

% Tensao quando a onda quadrada esta em seu valor baixo
Vclose = Vcc*exp(-t/(C*R));

% Grafico
plot(t,Vopen,t,Vclose);
line([0,periodo],[VLimit,VLimit],'Color','black','LineStyle','--');
legend('Carregamento','Descarregamento','Tensão minima de descarregamento')