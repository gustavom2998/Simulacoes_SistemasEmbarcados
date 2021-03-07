// Circuito para ligar e desligar um LED medindo a tensao sobre um potenciometro.
void setup()
{
  pinMode(3, OUTPUT);
}

void loop()
{
  // Valor analogico a ser lido
  int val = 0;
  
  // Le tensao sob o potenciometro (0 ate 1023)
  val = analogRead(A3);
  
  // Emite a tensao para o LED (que so pode escrever de 0 ate 255)
  analogWrite(3,val/4);
}
