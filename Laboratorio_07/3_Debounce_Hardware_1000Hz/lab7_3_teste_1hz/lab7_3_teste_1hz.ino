// Os valores de RC foram configurados para gerar um valor
// acima de 3V para frequencias menor que 1000Hz (Por tentativa e erro).

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}


// Funcao para mapeamento de floats
float mapFloat(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
}

void loop()
{
   // Leitura do Valor Analogico de 0 ate 5V como 0 ate 1023
  int aux = analogRead(A0);
  // Mapeamento para obter o valor de tensao em float
  float tensao_1 = mapFloat(aux,0,1023,0,5);
  // Conversao para obter a tensao com 1 casa decimal de precisao
  // Ex: 4.212121 -> 42
  int tensao_1_arred = tensao_1*10;
  
  // Se o valor for alto (acima de 3V) ativa o LED
  if(tensao_1_arred >= 30 ){
  	digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }
  
}