// Definicao das portas utilizadas para cada entrada do display
#define A 11
#define B 10
#define C 7
#define D 8
#define E 9
#define F 12
#define G 5
#define H 6

// Configuracao dos pinos e do serial para debug
void setup()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);
  Serial.begin(9600);
}

// Conversao de um inteiro de 0-9 para uma cadeia de bits
// que representa quais segementos ativar. Da direita para
// esquerda nos digitos temos ABCDEFGH.
byte bcdTo7Seg(int bcd){
  switch(bcd){
  	case 0: return 0b00111111;
    case 1: return 0b00000110;
    case 2: return 0b01011011;
    case 3: return 0b01001111;
    case 4: return 0b01100110;
    case 5: return 0b01101101;
    case 6: return 0b01111100;
    case 7: return 0b00000111;
    case 8: return 0b01111111;
    case 9: return 0b01100111;
  }
}

// Atualizacao de todas as saidas para o display utilizando
// o byte que diz quais segmentos deve ou nao devem ser acesos.
void updateDisplay(byte _7seg){
  digitalWrite(A,bitRead(_7seg,0));
  digitalWrite(B,bitRead(_7seg,1));
  digitalWrite(C,bitRead(_7seg,2));
  digitalWrite(D,bitRead(_7seg,3));
  digitalWrite(E,bitRead(_7seg,4));
  digitalWrite(F,bitRead(_7seg,5));
  digitalWrite(G,bitRead(_7seg,6));
  digitalWrite(H,bitRead(_7seg,7));
}

// Mostra os digitos de 0-9 infinitamente.
void loop()
{
  for(int bcd=0; bcd<=9; bcd++){
    byte _7seg = bcdTo7Seg(bcd);
    updateDisplay(_7seg);
    Serial.println(bitRead(_7seg,6));
    delay(1000);
  }
}