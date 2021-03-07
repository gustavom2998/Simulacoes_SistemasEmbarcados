// Inversao em software com potenciometro:
// Sabemos que o valor de entrada analogica varia de 0 ate 1023
// Logo subtraimos o valor por 1023 e tiramos o modulo.
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
  val = abs(val - 1023);
  
  // Emite a tensao para o LED (que so pode escrever de 0 ate 255)
  analogWrite(3,val/4);
}
