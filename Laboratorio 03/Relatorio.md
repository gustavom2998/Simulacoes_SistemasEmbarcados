# Laboratório 3: Interrupção, Registrador Status e Temporizadores

## Objetivo:
O objetivo desta prática é compreender o potencial das interrupções de hardware usando os temporizadores como exemplo.

Uma observação que deve ser feita é que os valores das resistências precisam ser ajustados para a implementação física dos circuitos. 

Para este relatório, utilizamo o datasheet do ATmega328/P na versão 11/2016 (Atmel-42735B-ATmega328/P_Datasheet_Complete-11/20160 - [link](https://cdn.sparkfun.com/assets/c/a/8/e/4/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf)). Escolhemos utilizar o Timer1 que possuí 16 bits para contagem. As informações podem ser vista no datasheet anexo a partir do capítulo 20.

## 1 - Piscador de LED com Registradores
Neste primeiro circuito, montamos um circuito que aciona um oscilador quando um botão é pressionado. Ao clicar novamente no botão, o oscilador é desativado. O "oscilador" é um temporizador que ativa e desativa o sinal após um intervalo fixo de tempo. Utilizamos o registrador A do Timer1 para definir um valor OCR que causa a interrupção quando a contagem for atingida. Toda vez que este valor for atingido, a rotina de interrupção interna do Counter1 para o match com o valor A é executada, e após isso, o contador é resetado. É válido ressaltar que há um segundo registrador para armazenar outro valor de comparação, com uma rotina de interrupação paralela. Neste caso só foi necessário utilizar um.

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/cUBpiHehU08)).

Abaixo temos o funcionamento do circuito.

![alt text](https://i.imgur.com/fH6ak8N.gif)


## 2 - Piscador de LED  com Registradores utilizando duas rotinas
Montamos o mesmo circuito, com o mesmo oscilador. Entretanto, ao  invés de definir uma função separada para inverter o sinal, definimos uma segunda rotina de interrupção interna. Isto difere do exemplo anterior, que definimos uma função normal e adicionamos uma interrupção do botão para acionar a função. Na teoria, este código faz a mesma coisa.

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/bVszswyu2h1)).

Abaixo temos o funcionamento do circuito.

![alt text](https://i.imgur.com/HJNlAGa.gif)

## 3 - Piscador de LED com Registradores a 1Hz
Neste caso, foi necessário alterar o funcionamento do temporizador. Reconfiguramos o oscilador de acordo com as especificações do Arduino Uno. Para o ajuste, modificamos o prescaler (ver pagina 170) que muda o intervalo de tempos que podemos "esperar". Por padrão, o Arduino possui um clock de 16MHz. Ao definir um prescaler de valor 256, é possível obter um periodo de 256/16MHz = 16us. Assim, para saber qual tempo seria equivalente a 1s, elevamos o período por -1, obtendo um valor de 62500 contagens necessárias para atingir o valor de 1s. Logo, simplesmente colocamos o contador para usar este valor como comparador para interrupção, e quando isto ocorrer, modificamos o estado do oscilador.

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/7SPvhzHFsah)).

Abaixo temos o funcionamento do circuito.

![alt text](https://i.imgur.com/JvpHz5W.gif)

## 4 - Piscador de LED - 1 segundo aceso 2 segundos apagados
Neste caso, foi necessário mudar novamente o funcionamento do temporizador. Em primeiro lugar, foi necessário desabilitar mudar a configuração do contador de tal forma que ele não "resetasse" após atingir o valor da contagem (COM1B0 - pagina 170). Assim, primeiro ocorria uma interrupção após passar 1s, e então uma segunda interrupção após passar 3s (do início da contagem). Também foi necessário ajustar o contador para que ele fosse capaz de contar até 3 segundos. Para isso, o Prescaler foi alterado para um valor de 1024. Como utilizamos um prescaler para ajustar o valor, temos um período de 1024/16MHz = 64us. Para este período, precisamos de 1s/64us = 15625 contagens do contador para ter cerca de 1s e 46875 contagens para passar 3s. Duas rotinas de interrupções diferentes foram definidas, uma parada desativar o LED após 1s de contagem e depois outro para desativar o LED por 2s. Então, reiniciamos o contador e o ciclo se repete. 

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/aMnT99JPJO2)).

Abaixo temos o funcionamento do circuito.

![alt text](https://i.imgur.com/KrNs8WM.gif)