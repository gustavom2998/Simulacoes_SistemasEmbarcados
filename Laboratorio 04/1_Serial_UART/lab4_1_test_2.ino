// Configuracao
void setup()
{
  // Pino de entrada - Baixo quando o botao eh pressionado
  pinMode(2, INPUT_PULLUP);
  
  // Saida para o LED
  pinMode(13, OUTPUT);
  
  // LED inicialmente desligado
  digitalWrite(13, LOW);
  
  // Inicio da comunicacao serial
  Serial.begin(9600);
}

void loop()
{
  // Se tiver chegado algo na comunicacao serial
  if(Serial.available()){
    // Le o que chegou
  	char data_rcvd = Serial.read();
   	
    // Se tiver chegado 1, acende o LED
    if(data_rcvd == '1'){
      digitalWrite(13, HIGH);
    }
    // Se nao, apaga o LED
    if(data_rcvd == '0'){
      digitalWrite(13,LOW);
      
    }

  }
  
  // Se o botao nao estiver pressionado - 0
  if(digitalRead(2) == HIGH){
  	Serial.write('0');
  }
  // Se o botao foi pressionado - 1
  else{
  	Serial.write('1');
  }
  // Delay para evitar spam no serial monitor
  delay(500);
}