# Laboratório 4: Comunicação Serial

## Objetivo:
O objetivo desta prática é compreender e aplicar os recursos de comunicação serial, normalmente disponíveis em microcontroladores. Neste exemplo, utilizamos um circuito com dois botões e dois LEDS, cada um conectado a uma placa. O objetivo é fazer o LED da placa B acender quando o botão da placa A for apertado e vice-versa.

Uma observação que deve ser feita é que os valores das resistências precisam ser ajustados para a implementação física dos circuitos. 

## 1 - Comunicação Serial UART

Após montar a protoboard, ligamos os pinos de comunicação serial (0 e 1) entre às duas placas Arduino. Utilizando a comunicação serial, transmitimos o caractere "0" quando o botão não está pressionado, e transmitimos o caractere "1" quando o botão está pressionado. Também adicionamos a lógica de leitura da comunicação serial (caso o outro Arduino Uno esteja transmitindo) para acender e apagar o LED conforme o que for recebido através da comunicação serial. Ambos placas utilizam o mesmo código. Este código aparentemente apresenta bugs com o TinkerCad, mas basta clicar em iniciar a simulação múltiplas vezes que o circuito funciona.

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/kWPJPaILGJa)).

Abaixo temos o funcionamento do circuito.

![alt text](https://i.imgur.com/6AvF6BY.gif)


## 2 - Comunicação TWI (I2C)

Neste caso, modificamos os pinos utilizados para comunicação entre os dois Arduinos para o A4 e A5, que são os pinos utilizados por este protocolo. Como esta configuração utiliza um Arduino como master e outro como slave, temos códigos diferentes nas placas. A placa mais a direita atua como Slave, e é responsável por conectar ao master informando qual é o seu endereço e transmitindo a informação quando for necessário. A placa master aguarda uma solicitação de conexão com endereço 8 e então lê o conteúdo recebido. Ambas placas tem um código para lidar com a necessidade de enviar e receber dados, entretanto, o código da placa master é um pouco mais simples. Adicionamos delays em ambas as placas para evitar repetição na troca de mensagens. 

O circuito foi disponibilizado através do TinkerCad ([link](https://www.tinkercad.com/things/a5Ih4259Vt0)).

Abaixo temos o funcionamento do circuito.

![alt text](https://i.imgur.com/zGgATRv.gif)
