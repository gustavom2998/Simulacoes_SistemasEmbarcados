// Placa que recebe comandos (sequencia de caracteres) do monitor serial
// do tinkercad para habilitar e desabilitar diferentes LEDS atraves
// do protocolo de comunicação serial UART. Desta vez utilizamos a memória
// EEPROM para armazenar uma váriavel booleana para cada LED. Se o valor
// armazenado for true, o LED deve estar aceso, se não, deve estar apagado.
#include <EEPROM.h>

// String para armazenar o comando recebido atraves do serial
char caractere;
String buffer = "";

// Numeracao dos pinos utilizados para cada LED
#define RED 10
#define YELLOW 9
#define GREEN 8

// Endereco de memória onde o estado dos LEDs são armazenados
#define ENDERECO_R 18
#define ENDERECO_Y 19
#define ENDERECO_G 20

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

// Atualizacao nos estados dos LEDs na memoria
void escreve_estado(String buffer){
  // Le os estados atuais de cada LED
  bool estado_R = (bool) EEPROM.read(ENDERECO_R);
  bool estado_G = (bool) EEPROM.read(ENDERECO_G);
  bool estado_Y = (bool) EEPROM.read(ENDERECO_Y);
  
  // Se a string for red, toggle no LED vermelho
  if(buffer == "red"){
    EEPROM.write(ENDERECO_R, !estado_R);
  }
  // Se a string for green, toggle no LED verde
  else if(buffer == "green"){
    EEPROM.write(ENDERECO_G, !estado_G);
  }
  // Se a string for yellow, toggle no LED amarelo
  else if(buffer == "yellow"){
      EEPROM.write(ENDERECO_Y, !estado_Y);
  }
  // Caso contrario, impprime que o comando é invalido
  else{
    Serial.println("Comando Invalido:" );
  }
  
   // Aguarda tempo de escrita
   delay(100);
}

// Apos os estados dos LEDs estarem atualizados, ativa
// os LEDs que devem estar acesos.
void set_leds(){
  // Le os estados
  byte estado_R = EEPROM.read(ENDERECO_R);
  byte estado_G = EEPROM.read(ENDERECO_G);
  byte estado_Y = EEPROM.read(ENDERECO_Y);
  
  // Atualiza os pinos usados para os LEDs
  digitalWrite(RED,(bool)estado_R); 
  digitalWrite(YELLOW,(bool)estado_Y); 
  digitalWrite(GREEN,(bool)estado_G);
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
    
    // Com base na string lida, atualiza os booleanos do EEPROM
    escreve_estado(buffer);
    
    // Print na funcao que foi realizada
    Serial.println(buffer);
  }
  // Le o estado das cores e ativa os LEDs
  set_leds();    
  delay(500);
}