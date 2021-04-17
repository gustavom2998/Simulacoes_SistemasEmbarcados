// Os valores de RC foram configurados para gerar um valor
// acima de 3V para frequencias menor que 1000Hz.
int debounceDelay = 10;
int state = LOW;
unsigned long lastDebounceTime = 10;  // the last time the output pin was toggled

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(3, INPUT);
}

void changeState(int newState, int diff, unsigned long newDebounceTime){
 
  Serial.println(diff);
  if(diff >= debounceDelay){
	state=!state;
  }
  lastDebounceTime = newDebounceTime;
  
}

// Funcao para mapeamento de floats
float mapFloat(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
}

void loop()
{
  int updatedState = analogRead(A0);
  
  float tensao_1 = mapFloat(updatedState,0,1023,0,5);
  
  if(tensao_1 >= 3) updatedState = HIGH;
  else updatedState = LOW;
  
 
  if((updatedState==HIGH && state==LOW) || (updatedState==LOW && state==HIGH)){
    unsigned long newDebounceTime = millis();
    int diff = newDebounceTime-lastDebounceTime;
  	changeState(updatedState, diff,newDebounceTime);
  }
  // Se ambas tensoes sao altas (Acima de 3V) e sao iguais
  if(state == HIGH){
    // Escreve valor alto na saida
    digitalWrite(13,HIGH);
  }
  // Se nao, escreve um valor baixo
  else{
    digitalWrite(13,LOW);
  }
 //}
}