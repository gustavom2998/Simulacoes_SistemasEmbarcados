# Laboratório 5: Comunicação, Armazenamento e Recuperação de Dados

## Objetivo:
O objetivo desta prática é compreender e aplicar procedimentos de comunicação, armazenamento e recuperação de dados em sistemas embarcados. Neste caso, simulamos o controle remoto de um microcontrolador através da comunicação serial.

Uma observação que deve ser feita é que os valores das resistências precisam ser ajustados para a implementação física dos circuitos. 

## 1 - Comunicação Serial de 1 caractere
Neste primeiro circuito, montamos um circuito que pode acionar ou desabilitar três LEDs de diferentes cores. Para isso, o usuário deve inserir, através de comunicação serial, um caractere que representa a cor que deseja ativar/desativar. Os três caracteres aceitos são "r" para vermelho, "y" para amarelo e "g" para green. Note que a comunicação que ocorre entre o dispositivo de entrada serial (teoricamente remoto) controla o nosso sistema embarcado que simula um semáforo.

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/3Y5fuC4jVBv)).

Abaixo temos o funcionamento do circuito.

![alt text](https://i.imgur.com/kgfAQ7R.gif)


## 2 - Comunicação Serial de uma string
Agora, modificamos o código do circuito para que ele seja capaz de receber uma string dada através de comunicação serial. Para isso, primeiro inserimos um delay no loop do código principal para permitir que todos os dados estejam disponíveis. Então, enquanto existirem informações na entrada serial, os caracteres são lidos até encontrar um fim de linha. Cada caractere é lido e inserido no final de uma string vazia. No fim, tem-se uma string que representa a string original inserida no barramento. Então, analisamos a string para decidir qual LED deve ter ativado/desativado. Desta vez, a comunicação utiliza strings, que requer um código mais complexo para controlar a leitura dos dados comunicados. 

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/hpWTvQdjXcA)).

Abaixo temos o funcionamento do circuito.

![alt text](https://i.imgur.com/hmR4Njj.gif)

## 3 - Comunicação de Strings com Armazenamento em EEPROM
Por último, estendemos o nosso código de leitura de strings para ser capaz de armazenar valores na memória EEPROM que representam se o LED da respectiva cor deve estar aceso ou apagado. Utilizamos um endereço para cada cor, que inicialmente possuí o valor zero. Então, quando o usuário entra com uma cor, o valor no endereço da memória EEPROM para a respectiva cor é invertido e a saída do pino é atualizada. Algo interessante é que em uma aplicação real, o nosso EEPROM não seria apagado ao desligar o Arduino, logo, ao reiniciar o Arduino , os pinos manteriam os estados.

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/5xSQiq7HJvG)).

Abaixo temos o funcionamento do circuito.

![alt text](https://i.imgur.com/Ne8w8Mo.gif)