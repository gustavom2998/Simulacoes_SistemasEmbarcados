// Comunicacao utilizando I2C
// Codigo do microcontrolador "Slave"

// Importacao de biblioteca que permite a comunicacao
#include<Wire.h>                         

// Byte recebido pelo Slave.
byte SlaveReceived = 0;

// Funcao chamada quando o slave (este) recebe algo do master (outro)
void receiveEvent (int howMany)    
{
   SlaveReceived = Wire.read();
  
}

// Funcao chamada quando o slave (este) precisa transmitir algo para o master (outro)
void requestEvent()
{
  // Pelo fato do pino esta no modo pullup - quero invertido para enviar 1 quando o botao estiver pressionado
  char value = !digitalRead(2);
  
  // Envia um byte para o master.
  Wire.write(value);                          
}

// Configuracao
void setup() 

{ 
  // Pino de entrada do botao - alto quando nao apertado
  pinMode(2, INPUT_PULLUP);
  
  // Pino de saida para o LED
  pinMode(13, OUTPUT);
  //Delay de 1 segundo para iniciar a comunicacao
  delay(1000);
  
  // Comunicacao serial para mostrar o que esta sendo recebido
  Serial.begin(9600);
  
  // Inicio da comunicacao - utiliza pino A4 e A5 e slave eh 8
  Wire.begin(8);    
  
  // Quando receber do master - deve fazer isso
  Wire.onReceive(receiveEvent);         
  
  // Quando tiver que enviar para o mestre - deve fazer isso
  Wire.onRequest(requestEvent);          
} 



void loop(void) 
{  
  
  // Monitor serial para debug
  Serial.println("Slave recebeu do Master:");
  Serial.println(SlaveReceived); 
  
  // Se receber 1 - acende o LED
  if(SlaveReceived == 1){
  	digitalWrite(13,HIGH);
  }
  // Se receber 0 - apaga o LED
  if(SlaveReceived == 0){
    digitalWrite(13,LOW);
  }
  
  delay(500);
  
}


