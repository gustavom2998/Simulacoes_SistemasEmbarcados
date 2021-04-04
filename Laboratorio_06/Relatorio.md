# Laboratório 6: Visores de 7 Segmentos e LCDs

## Objetivo:
O objetivo desta prática é compreender e aplicar a visualização de informação através de visores de 7 segmentos e LCD. Fazemos isso através de duas aplicações interessantes, que é a criação de um contador circular de dois dígitos que mostra o valor de contagem atual, e um microcontrolador para controle de um compressor com o objetivo de atingir uma temperatura desejada.

Uma observação que deve ser feita é que os valores das resistências precisam ser ajustados para a implementação física dos circuitos. 

## 1 - Display de 7 Segmentos
Neste primeiro circuito, montamos um exemplo muito simples para acionar um display de 7 segmentos. O funcionamento básico do circuito é percorrer valores de 0 até 9 e atualizar o display de 7 segmentos. Para isso, definimos uma função que dado um inteiro de 0 a 9, retorna a representação em segmentos de display de 7 segmentos. Também definimos uma função que atualiza as saídas de cada pino, para atualizar os segmentos corretos.

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/8xrcP4ZRfjG)).

Abaixo temos o funcionamento do circuito.

![alt text](1_Display_7Segmentos/lab6_1_display7seg.gif)

## 2 - Display Contador 99
Agora modificamos o circuito para fazer um contador até 99. Primeiro, separamos as conexões para ter conexões com os dois displays separados. Então, ajustamos a lógica para poder atualizar o display correto, adicionando um contador que define qual display desejamos atualizar, o primeiro ou o segundo. O primeiro display é para a casa decimal, e o segundo para a casa unitária. Para fazer o ciclo de 0 até 99, utilizamos dois for's. A casa decimal é atualizada através do for mais externo, e o for mais interno atualiza a casa unitária. 


O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/gDFNDDtzirm)).

Abaixo temos o funcionamento do circuito.

![alt text](2_Display_Contador99/lab6_2_contador99.gif)

## 3 - Display LCD
Para utilização do display LCD 16x2, utilizamos a biblioteca LiquidCrystal para configurar o ambiente. Para configurar o uso da biblioteca, utilizamos com referência o exemplo da documentação ([link](https://www.arduino.cc/en/Tutorial/LibraryExamples/HelloWorld)). Na parte superior do display, escrevemos a string embarcados, e logo abaixo, escrevemos a string LCD 16x2. Escrevemos duas funções para moverem o display a esquerda/direita por um determinando numero de passos. Estas duas funções foram utilizadas para animar o texto do display.

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/gMqgXOpPMre)).

Abaixo temos o funcionamento do circuito.

![alt text](3_Display_LCD/lab6_3_lcd.gif)

## 4 - Customizando o texto do LCD
Repetimos o circuito anterior, entretanto, alteramos o texto mostrado no LCD. Neste caso, apenas alteramos as duas strings que são transmitidas para o display LCD. As strings citam temperatura ambiente e temperatura desejada, que serão utilizadas no nosso problema do compressor.

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/aYsaMjAdQLl)).

Abaixo temos o funcionamento do circuito.

![alt text](4_Display_LCD_Texto/lab6_4_temp.gif)

## 5 - Utilizando Potenciômetros com o display LCD
Desta vez, introduzimos dois potenciômetros no circuito. O primeiro potenciômetro é utilizado para identificar a temperatura alvo, ou seja, qual temperatura desejamos atingir. O segundo potenciômetro é utilizado para ajustar a temperatura ambiente. Na prática, este segundo potenciômetro seria substituído por um sensor de temperatura. Então, realizamos a conversão da entrada analógica do potenciômetro para produzir um valor de 0 até 50 graus com a função map. Em seguida, enviamos as duas strings para o LCD que mostram os valores atuais dos potenciômetros.

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/jSna1BrJlTc)).

Abaixo temos o funcionamento do circuito.

![alt text](5_Display_LCD_Pots/lab6_5_tempcust.gif)

## 6 - Acionando um Compressor

Utilizando o circuito anterior, agora propomos implementar a parte lógica para resolução de um problema. Queremos que o nosso Arduino seja utilizado para acionar um compressor quando a temperatura ambiente for maior que a temperatura desejada. Para isso, utilizamos o pino 13 que acende um LED, que seria para ativação do conversor. A lógica para ativação/desativação do pino 13 foi implementada utilizando um IF simples.

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/01y6Fy6Go14)).

Abaixo temos o funcionamento do circuito.

![alt text](6_Display_Compressor/lab6_6_tempcustled.gif)