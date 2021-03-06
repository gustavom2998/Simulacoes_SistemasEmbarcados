# Laboratório 2: Entradas e Saídas Digitais e Analógicas

## Objetivo:
O objetivo desta prática é compreender o funcionamento de entradas e saídas digitais e analógicas em microcontroladores. Para cumprir este objetivo, a ferramenta TinkerCad foi utilizada para simumlar o funcionamento de uma placa Arduino Uno, que utiliza um microcontrolador ATMega328.

Uma observação que deve ser feita é que os valores das resistências precisam ser ajustados para a implementação física dos circuitos. 

## 1 - Piscador de LED com Botão
Neste primeiro circuito, montamos um circuito que aciona um LED quando um botão é pressionado. Quando o botão está em sua posição padrão, o LED permanece aceso.

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/9RhJAjg3li6)).

Abaixo temos o funcionamento do circuito.

![alt text](1_Teste_Entrada/1_Teste_Entrada.gif)


## 2 - LED com Botão com Inversão em Software
Agora, montamos um circuito semelhante ao anterior, entretanto inverteremos a lógica, ou seja, quando o botão estiver em sua posição padrão, o LED deve estar aceso. Quando o usuário interagir com o botão, o LED deve apagar. Para isso, realizamos uma pequena mudança no código executado pela placa mudando o sinal que é transmitido na saída que aciona o LED.

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/73VSqo06Csj)).

Abaixo temos o funcionamento do circuito.

![alt text](2_Inversao_Software/2_inversao_software.gif)

## 3 - LED com Botão com Inversão em Hardware
Semelhante ao passo anterior, queremos que o LED esteja aceso com o LED em sua posição padrão, e apague quando o usuário interagir com o botão. Desta vez, ao invés de mudar o código, iremos mudar o circuito. Utilizou-se um transistor NPN para realizar a inversão do sinal do botão. O sinal do botão foi utilizado na base do resistor, o emissor aterrado, e o coletor ligado ao sinal de 5V com um resistor. O sinal utilizado invertido foi obtido através do nó após o resistor. Note que para a aplicação, na prática (física) deste circuito, seria necessário ajustar os valores das resistências e possivelmente das tensões.

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/7fpPclx8rPp)).

Abaixo temos o funcionamento do circuito.

![alt text](3_Inversao_Hardware/3_Inversao_Hardware.gif)

## 4 - LED com Potenciômetro
Desta vez, ao invés de utilizar um simples botão de 4 terminais, utilizamos um potenciômetro para poder ajustar o brilho do LED. A perna do meio é utilizada como entrada analógica para o Arduino. O valor é então convertido para um valor digital e o sinal é enviado para o LED. 

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/ew9F9p8g695)).

Abaixo temos o funcionamento do circuito.

![alt text](4_Potenciometro/4_Potenciometro.gif)

## 5 - LED com Potenciômetro com Inversão em Software
Para realizar a inversão da lógica em software, utilizamos uma simples operação matemática. Segundo o roteiro seguido para o experimento, a entrada analógica gera um valor no intervalo de 0 até 1023. Então, subtraímos o valor pelo máximo do intervalo e pegamos o módulo para transmitir para o LED. O valor transmitido foi divido por quatro, pois, segundo o roteiro seguido, a saída digital deve estar no intervalo de 0 até 255.

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/1FWihajhMpo)).

Abaixo temos o funcionamento do circuito.

![alt text](5_Potenciometro_InversaoSoftware/5_Potenciometro_InversaoSoftware.gif)

## 6 - LED com Potenciômetro com Inversão em Hardware
Para a inversão em hardware, poderíamos utilizar um transistor como feito para a inversão do botão, entretanto, é mais fácil trocar a ordem da alimentação do potenciômetro. 

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/6wLZ5X7YTOW)).

Abaixo temos o funcionamento do circuito.

![alt text](6_Potenciometro_InversaoHardware/6_Potenciometro_InversaoHardware.gif)
