// Inversão em hardware - Fazer o LED apagar quando o botão for pressionado modificando o software
void setup()
{
  pinMode(12, OUTPUT);
  pinMode(2, INPUT);
}

void loop()
{
  int val = digitalRead(2);
  // Se o botão está em low, ele está pressionado
  if(val == LOW){
    // LED é desligado
  	digitalWrite(12, LOW);
  }
  // Se o botão está em high, ele está solto
  else{
    // LED segue ligado
  	digitalWrite(12, HIGH);
  }
}
