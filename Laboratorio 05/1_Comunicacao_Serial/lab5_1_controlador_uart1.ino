// Placa que recebe comandos (unico caractere) do monitor serial
// do tinkercad para habilitar e desabilitar diferentes LEDS atraves
// do protocolo de comunicação serial UART. Basta digitar um caractere
// no monitor serial do tinkercad e clicar em enviar para usar.
char comando;

// Numeracao dos pinos utilizados para cada LED
#define RED 10
#define YELLOW 9
#define GREEN 8

void setup()
{
  // Inicio da comunicacao serial utilizando 9600 bits/s
  Serial.begin(9600);
  
  // Definicao dos pinos
  pinMode(RED,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  pinMode(GREEN,OUTPUT);
  
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
}

void loop()
{
  // Caso algo tenha sido recebido no serial
  if(Serial.available() > 0){
    // Leitura do que foi escrito no serial
  	comando = Serial.read();
    
    // Possibilidades de comandos recebidos
    switch(comando){
      // Se o comando for R ou r inverte o LED vermelho
      case('r'):
      case('R'):
      	digitalWrite(RED,!digitalRead(RED));
        break;
      // Se o comando for g ou G inverte o LED verde
      case('g'):
      case('G'):
        digitalWrite(GREEN,!digitalRead(GREEN));
        break;
      // Se o comando for y ou Y, inverte o LED amarelo
      case('y'):
      case('Y'):
        digitalWrite(YELLOW,!digitalRead(YELLOW));
        break;
      // Qualquer outro comando é ignorado
      default:
	    Serial.print("Comando invalido: ");
        break;
    }
    Serial.println(comando);
                      
  }
  
}