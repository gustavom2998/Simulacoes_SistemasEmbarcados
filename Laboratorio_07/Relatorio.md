# Laboratório 7: Debounce

## Objetivo:
O objetivo desta prática é compreender e aplicar mecanismos de debounce com hardware e com software. Para isso, analisamos a resposta de um circuito RC atuando como filtro passa baixa. Além disto, utilizamos o Arduino Uno para analisar a tensão de saída sobre o capacitor e adicionar um mecanismo de debounce por software. Construímos diferentes tipos de debouncers, para diferentes frequências. Além disso, também ajustamos a sensibilidade a determinadas tensões conforme necessário nos projetos. 

Uma observação que deve ser feita é que os valores das resistências precisam ser ajustados para a implementação física dos circuitos. 

## 1 - Atenuação de trepidação em mudança de estado
Para esta tarefa, configuramos um gerador de frequência para gerar uma onda quadrada com frequência de 1KHz de 5V. Desejamos que a tensão sobre o capacitor esteja no máximo abaixo de 0.8V da tensão de entrada, ou seja, ser maior que 4.2V no momento de descarregamento.

Utilizando as equações de resposta de tensão sobre um capacitor em um circuito RC, e tomando como base um capacitor de 10uF, montamos um script de Matlab para identificar qual a tensão no momento de carregamento (linha azul) e descarregamento (linha laranja) do capacitor para um período de onda. Para o valor de 1K Ohms, encontramos o gráfico abaixo, que está no limite desejado de 0.8V abaixo da tensão de entrada.

![alt text](1_Debounce_Hardware_Ripple/Grafico.png)

Em sequência, montamos um circuito RC e adicionamos osciloscópios na saída do gerador de onda e sobre o capacitor, com o intuito de comparar o sinal de entrada e o sinal filtrado, utilizando os valores de resistência e capacitância encontrados. Quando a frequência é menor que 1KHz, a tensão é maior que 4.2V, e quando a frequência é maior, ela fica menor que 4.2V. Para o teste com 1KHz, observe que o valor do osciloscópio sobre o capacitor é em torno de 5V conforme esperado, entretanto, quando mudamos a frequência para 100KHz, a tensão máxima registrada pelo osciloscópio cai.

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/aSLGFEqVqYV)).

Abaixo temos o funcionamento do circuito.
![alt text](1_Debounce_Hardware_Ripple/lab7_1_Debounce_Ripple.gif)

## 2 - Velocidade de resposta em mudança de estado

Mantendo uma configuração semelhante ao anterior, diminuímos a frequência do sinal para 10Hz. Então, buscamos ajustar a configuração do circuito RC para que o tempo de subida/descida seja menor que 10% do nosso período, ou seja, menor que 0,01s. 

Ajustamos o código em Matlab para encontrar o valor do capacitor que satisfazia esse objetivo. Com um valor de capacitância de 2.5uF e uma resistência de 1K Ohms encontramos a seguinte resposta.

![alt text](2_Debounce_Hardware_Tempo/Grafico.png)

Então, montamos o circuito RC no tinkercad para analisar as tensões sobre o circuito utilizando um osciloscópio.

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/b1R4lkPc7ju)).

Abaixo temos o funcionamento do circuito.

![alt text](2_Debounce_Hardware_Tempo/lab7_2_Debounce_Tempo.gif)

## 3 - Projetando um debouncer de hardware de 1KHz

Para esta parte, montamos o circuito de debounce por hardware para gerar uma tensão maior que 3V para frequências menores que 1KHz. Assim, o nosso debounce por hardware atenua sinais maiores que 1KHz. O ajuste de R e C foi feito por tentativa e erro, após montar o circuito. Então, montamos um circuito de teste utilizando um Arduino, onde emitimos um sinal alto para o pino 13 quando a tensão sobre o capacitor é maior que 3V. Note que utilizamos uma medida analógica e não digital, pois queríamos especificar qual valor interpretaríamos como tensão alta.

Uma observação é que a entrada analógica produz um valor entre 0 até 1023 para uma tensão entre 0 e 5V, logo, precisamos mapear esse valor de volta para o valor de tensão. Escrevemos uma função que transforma valores inteiros de intervalos para valores de ponto flutuante, e utilizamos 1 casa decimal para avaliar se os valores são maiores que 3V. 

O teste do funcionamento foi feito com um sinal de 1Hz, e ele não é atenuado conforme esperado. Então, aumentamos a frequência e vemos que o LED desliga. Algo que vale comentar é que caso o último estado com frequência "aceitável" do LED seja alto, ele vai permanecer alto, pois as frequências que não estão na faixa aceita não podem  atualizar o estado, ou seja, desligar o LED. 

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/hmUEuWv8vaw)).

Abaixo temos o funcionamento do circuito.

![alt text](3_Debounce_Hardware_1000Hz/lab7_3_teste_1hz.gif)

## 4 -  Testando o debounce de hardware com 200Hz

Após montar o circuito anterior, testamos o circuito desta vez com uma frequência de 200Hz. Conforme esperado, ele também não atenua a entrada e o LED fica aceso devido à alta frequência do sinal. Ao diminuir a frequência, ele econtinua aceso, e ao aumentar para um valor superior a 1KHz, o LED permanace com estado desligado ao reativar o circuito. 

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/8SnpjSrRiTK)).

Abaixo temos o funcionamento do circuito.

![alt text](4_Debounce_Hardware_Teste_200Hz/lab7_4_teste_200hz.gif)

## 5 - Adicionando um debounce por software de 100Hz

Agora, modificamos o código do nosso Arduino para adicionar um debounce por software, para que permita apenas sinais com frequência menor que 100Hz. Isto foi feito adicionando código para verificar se o tempo desde a última mudança de estado foi maior que 10ms. Para isso, armazenamos o estado atual e o tempo (usando o contador do Arduino) em que isso aconteceu. Caso o estado seja alterado no capacitor (de baixo para alto ou alto para baixo), analisamos quanto tem desde a última tentativa de mudança de estado. Se o tempo for maior que 10ms, então permitimos a mudança de estado, se não, descartamos a atualização de estado. Em ambos os casos, atualizamos o tempo da última mudança de estado, para ignorar sinais que não sejam constantes por 10ms ou mais.

Iniciamos os testes com uma frequência de 5Hz e vemos que o LED acende normalmente. Ao aumentar a frequência para 200Hz o LED não acende. Para ele acender, precisamos ajustar o tempo de debounce de software. Diminuímos ele para 1ms (desta vez a frequência de corte de torna 1000Hz), e vemos que ele acende normalmente para 200Hz. Ao aumentar a frequência para um valor maior que 1KHz o LED não acende mais.

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/bj3p3axcik5)).

Abaixo temos o funcionamento do circuito.
![alt text](5_Debounce_Hardware_Software/lab7_5_debounce_software_100hz.gif)