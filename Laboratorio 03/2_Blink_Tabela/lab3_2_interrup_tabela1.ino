#define LED_ALARME 12
#define LED_SINAL 7
#define BOTAO 2

bool sinal_on_off = false;

void setup(){
	pinMode(12, OUTPUT);
  	pinMode(2, INPUT);
}
// Rotina de interrupção interna
// Primeira rotina de 
ISR(INT0_vect){
  	// Atualiza o LED vermelho com a situacao do sinal
  	sinal_on_off = !sinal_on_off;
  
  	// Se ocorreu a interrupcao, usuario ativou/desativou sinal.
	digitalWrite(LED_ALARME, sinal_on_off);
}

// Timer/Counter1 de interrupcao Compare Match A
// Rotina executada quando o timer atinge o valor no registrador A
ISR(TIMER1_COMPA_vect){
	if(sinal_on_off)
      PORTD ^= 0b10000000; // Altera o valor do pino 7 da porta D
  	else 
      PORTD = 0b00000000;
}

int main(void){
	// Registrador de controle do Timer1 - Resetando (Analog Pins param de funcionar). 
  	// Utilizamos em operacao normal. Ver pagina 170.
	TCCR1A = 0b00000000;
  	
	// Registrador de controle do Timer1 - aqui selecionamos o prescaler modificando os 3 ultimos bits.
  	// De acordo com a pagina 173 do Atmel-42735B-ATmega328/P_Datasheet_Complete-11/2016, utilizamos um prescaler de 256.
  	// Por padrao o clock do arduino eh 16MHz. Como utilizamos um prescaler para ajustar o valor, temos um periodo de 256/16MHz = 16us.
    // Para este periodo, precisamos de 1s/16us 62500 contagens do contador para ter aproximadamente 1s. 
  	// O 4o bit alterado eh para geracao de onda (Ver Tabela 20.6). Isto define uma operacao CTC.
  	TCCR1B = 0b00001100;
  
  	// Tabela 13-4 - Valor maximo do Timer1 - Valor de comparaaco utilizado
  	// Quando for igual, um compare match interrupt é gerado. Toda vez que bater o valor, ISR eh chamado com um COMPA.
  	// Capaz de armazenar valores de ate 16 bits. 
  	OCR1A = 65535; 
  	
  	// Ver Pagina 184. Controla as diferentes habilitacoes de interrupcoes para as funcoes de interrupcoes associados ao timer1.
  	// Ativamos o segundo para habilitar uma interrupcao por match com o valor OCR1A.
  	TIMSK1 = 0b00000010; // Máscara do Timer1: habilita a interrupção por overflow
  	
  	//Registrador de Controle de Interrupções externas
  	EICRA = 0b00000010;
  
  	//Máscara das interrupções externas
  	EIMSK = 0b00000001;
  
   	// Habilita a interrupção global
  	sei();
   	// Torna o pino 7 da Porta D uma saída digital
  	DDRD = 0b10000000;
  	pinMode(7, OUTPUT);
 
  	while(1){}
}