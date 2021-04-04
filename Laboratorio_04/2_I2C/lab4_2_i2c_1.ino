// Comunicacao utilizando I2C
// Codigo do microcontrolador "Master"

// Importacao de biblioteca que permite a comunicacao
#include<Wire.h>

// Configuracao
void setup()
{
  // Defino pino do botao - alto quando nao apertado
  pinMode(2, INPUT_PULLUP);
  
  // Pino de saida para o LED
  pinMode(13, OUTPUT);
  
  // Inicia o LED como LOW
  digitalWrite(13, LOW);
  
  // Delay para iniciar a comunicacao
  delay(1000);
  
  // Serial para debug
  Serial.begin(9600);
  
  // Estabelece conexao com slaves
  Wire.begin();
}

void loop()
{
  // Solicita 1 byte do Slave no endereço x08
  Wire.requestFrom(8,1); 
  
  // Le o byte recebido do slave
  byte MasterReceive = Wire.read(); 
  
  // Le o sinal do botao como char
  char value = !digitalRead(2);
  
  // Comeca tranmistir para o Slave no endereço x08
  Wire.beginTransmission(8); 
  
  // Envia o char que representa o valor lido no botao
  Wire.write(value);  
  
  // Finaliza comunicacao
  Wire.endTransmission();
  
  // Logging do que foi recebido
  Serial.println("Master recebeu do Slave");
  Serial.println(MasterReceive);
  
  // Acende o LED se tiver recebido 1
  if(MasterReceive == 1){
  	digitalWrite(13,HIGH);
  }
  // Apaga o LED se tiver recebido 0
  if(MasterReceive == 0){
    digitalWrite(13,LOW);
  }
  delay(500);                                     
}