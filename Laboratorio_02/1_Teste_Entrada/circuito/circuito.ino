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
    // LED é ligado
  	digitalWrite(12, HIGH);
  }
  // Se o botão está em high, ele está solto
  else{
    // LED segue desligado
  	digitalWrite(12, LOW);
  }
}