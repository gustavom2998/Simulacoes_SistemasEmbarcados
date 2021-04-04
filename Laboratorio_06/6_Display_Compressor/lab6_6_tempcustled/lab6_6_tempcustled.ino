#include <LiquidCrystal.h>

// Definindo os pinos dos dois potenciometros e do compressor
#define POT1 A0
#define POT2 A1
#define COMPRESSOR 13

// Configurado de acordo com a documentação da biblioteca
LiquidCrystal lcd(12,11,5,4,3,2);

// Inicializando o LCD
void setup()
{
  lcd.begin(16,2);
  pinMode(COMPRESSOR, OUTPUT); 
}

// Funcao principal
void loop()
{
  // Reinitializa o LCD
  lcd.clear();
  
  // Prepara para escrever na linha de cima
  lcd.setCursor(0,0);
  // Le a tensao do potenciometro 1 e produz um valor de [0,1023]
  int val_pot1 = analogRead(POT1);
   // Converte o intervalo de [0,1023] para [0,50]
  val_pot1 = map(val_pot1, 0, 1023, 0, 50);
  // Escreve a temperatura ambiente do primeiro potenciometro
  lcd.print("Temp Alvo: " + String(val_pot1) + "C");
  
  // Prepara para escrever na linha de baixo
  lcd.setCursor(0,1);
  // Le a tensao do potenciometro 2 e produz um valor de [0,1023]
  int val_pot2 = analogRead(POT2);
  // Converte o intervalo de [0,1023] para [0,50]
  val_pot2 = map(val_pot2, 0, 1023, 0, 50);
  // Escreve a temperatura ambiente do segundo potenciometro
  // na linha de baixo
  lcd.print("Temp Amb.: " + String(val_pot2) +"C");
  
  // Se a temperatura ambiente for maior que a desejada
  // Ativa o compressor para resfriar o ambiente.
  if(val_pot1 < val_pot2){
  	digitalWrite(COMPRESSOR, HIGH);
  }
  else{
  	digitalWrite(COMPRESSOR, LOW);
  }
  
  delay(1000);
  
}