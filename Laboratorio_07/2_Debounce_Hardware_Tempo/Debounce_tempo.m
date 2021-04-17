% Tensao Maxima da Onda quadrada - Note que o valor minimo é 0.
Vcc = 5;

% Frequencia do sinal de entrada
freq = 10;

% Periodo do sinal de entrada
periodo = 1/freq;

% Tempo Limite para satisfazer a condicao
TLimit = 0.1*periodo;

% Pontos de tempo para simulacao
t = 0:periodo/100:periodo;

% Capacitancia para o circuito RC
C = 2.5*(10^(-6));

% Resistencia para o circuito RC
R = 1000;

% Tensao quando a onda quadrada esta em seu valor alto
Vopen = Vcc*(1-exp(-t/(C*R)));

% Tensao quando a onda quadrada esta em seu valor baixo
Vclose = Vcc*exp(-t/(C*R));

% Grafico
plot(t,Vopen,t,Vclose);
line([TLimit,TLimit],[0,5],'Color','black','LineStyle','--');
legend('Carregamento','Descarregamento','Tempo maximo de carregamento')