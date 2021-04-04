// Inversao em Hardware com potenciometro:
// So foi necessario trocar a order a tensao de 5V com o aterramento
// e vice versa para o potenciometro. É possível fazer isso usando um TBJ também.

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