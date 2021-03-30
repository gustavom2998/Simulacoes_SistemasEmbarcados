// Placa que recebe comandos (sequencia de caracteres) do monitor serial
// do tinkercad para habilitar e desabilitar diferentes LEDS atraves
// do protocolo de comunicação serial UART. Basta digitar uma string
// no monitor serial do tinkercad e clicar em enviar para usar.
char caractere;
String buffer = "";
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
    buffer = "";
    
    // Le caractere por caractere do serial e cria uma string
    while(Serial.available() > 0){
      caractere = Serial.read();
      if(caractere !='\n'){
        buffer.concat(caractere);
      }
    }
    
	// Transformando a string em minusculo
    buffer.toLowerCase();
    
    // Se a string for red, toggle no LED vermelho
    if(buffer == "red"){
      digitalWrite(RED,!digitalRead(RED));
    }
    // Se a string for green, toggle no LED verde
    else if(buffer == "green"){
      digitalWrite(GREEN,!digitalRead(GREEN));
    }
    // Se a string for yellow, toggle no LED amarelo
    else if(buffer == "yellow"){
      digitalWrite(YELLOW,!digitalRead(YELLOW));
    }
    // Caso contrario, impprime que o comando é invalido
    else{
      Serial.println("Comando Invalido:" );
    }
      
    Serial.println(buffer);
  }
  delay(500);
}