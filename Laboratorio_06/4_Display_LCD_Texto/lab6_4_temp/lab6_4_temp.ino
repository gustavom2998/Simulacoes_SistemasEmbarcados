#include <LiquidCrystal.h>

// Configurado de acordo com a documentação da biblioteca
LiquidCrystal lcd(12,11,5,4,3,2);

// Inicializando o LCD
void setup()
{
  lcd.begin(16,2);
}

// Funcao para mover texto para direita, dando a impressao
// que a tela esta sendo movida para a esquerda.
void scrollLeft(int passos){
  for(int posicao = 0; posicao < passos; posicao++){
  	lcd.scrollDisplayLeft();
    delay(300);
  }
}

// Funcao para mover texto para esquerda, dando a impressao
// que a tela esta sendo movida para a direita.
void scrollRight(int passos){
  for(int posicao = 0; posicao < passos; posicao++){
  	lcd.scrollDisplayRight();
    delay(300);
  }
}

// Funcao principal
void loop()
{
  // Reinitializa o LCD
  lcd.clear();
  
  // Escreve a temperatura alvo na linha de cima
  lcd.setCursor(3,0);
  lcd.print("Temp Alvo: 20C");
  
  // Escreve a temperatura ambiente na linha de baixo
  lcd.setCursor(3,1);
  lcd.print("Temp Amb.: 27C");
  
  delay(1000);
  
  // Animacao da tela
  scrollLeft(3);
  scrollRight(6);
}
