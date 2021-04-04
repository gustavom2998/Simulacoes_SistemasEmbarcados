// Definicao das portas utilizadas para cada entrada do display 1
#define A_1 11
#define B_1 10
#define C_1 7
#define D_1 8
#define E_1 9
#define F_1 12
#define G_1 5
#define H_1 6

// Definicao das portas utilizadas para cada entrada do display 2
#define A_2 2
#define B_2 A4
#define C_2 A1
#define D_2 A0
#define E_2 A3
#define F_2 3
#define G_2 4
#define H_2 A2

// Configuracao dos pinos e do serial para debug
void setup()
{
  pinMode(A_1, OUTPUT);
  pinMode(B_1, OUTPUT);
  pinMode(C_1, OUTPUT);
  pinMode(D_1, OUTPUT);
  pinMode(E_1, OUTPUT);
  pinMode(F_1, OUTPUT);
  pinMode(G_1, OUTPUT);
  pinMode(H_1, OUTPUT);
  pinMode(A_2, OUTPUT);
  pinMode(B_2, OUTPUT);
  pinMode(C_2, OUTPUT);
  pinMode(D_2, OUTPUT);
  pinMode(E_2, OUTPUT);
  pinMode(F_2, OUTPUT);
  pinMode(G_2, OUTPUT);
  pinMode(H_2, OUTPUT);
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
void updateDisplay(byte _7seg,int display){
  
  if(display == 1){
  	digitalWrite(A_1,bitRead(_7seg,0));
    digitalWrite(B_1,bitRead(_7seg,1));
    digitalWrite(C_1,bitRead(_7seg,2));
    digitalWrite(D_1,bitRead(_7seg,3));
    digitalWrite(E_1,bitRead(_7seg,4));
    digitalWrite(F_1,bitRead(_7seg,5));
    digitalWrite(G_1,bitRead(_7seg,6));
    digitalWrite(H_1,bitRead(_7seg,7));
  }
  else{
    digitalWrite(A_2,bitRead(_7seg,0));
    digitalWrite(B_2,bitRead(_7seg,1));
    digitalWrite(C_2,bitRead(_7seg,2));
    digitalWrite(D_2,bitRead(_7seg,3));
    digitalWrite(E_2,bitRead(_7seg,4));
    digitalWrite(F_2,bitRead(_7seg,5));
    digitalWrite(G_2,bitRead(_7seg,6));
    digitalWrite(H_2,bitRead(_7seg,7));
  }
  
}

// Mostra os digitos de 0-9 infinitamente.
void loop()
{
  for(int bcd1=0; bcd1<=9; bcd1++){
    byte dig7seg1 = bcdTo7Seg(bcd1);
    updateDisplay(dig7seg1,1);
    for(int bcd2=0; bcd2<=9; bcd2++){
      byte dig7seg2 = bcdTo7Seg(bcd2);
      //Serial.println(bcd2);
      updateDisplay(dig7seg2,2);
      
      delay(250);
    }
  }
}