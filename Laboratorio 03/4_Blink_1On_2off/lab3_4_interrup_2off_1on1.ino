#define LED_ALARME 12
#define LED_SINAL 7
#define BOTAO 2

bool sinal_on_off = false;
const uint16_t meu_zero = 0;

void setup(){
	pinMode(12, OUTPUT);
  	pinMode(2, INPUT);
  	pinMode(7, OUTPUT);
}
  
// Rotina de Interrupção externa - Chamada quando o usuario deseja ativar/desativar o sinal
void ledOn(){
  	// Se ocorreu a interrupcao, usuario ativou/desativou sinal.
  	sinal_on_off = !sinal_on_off;
  
  	// Atualiza o LED vermelho com a situacao do sinal
  	digitalWrite(LED_ALARME, sinal_on_off);
  
  	// Se o sinal foi desligado e o LED verde estiver aceso, desatva ele
  	if(!sinal_on_off && PORTD==0b10000000) PORTD=0b00000000;

}

// Rotina de interrupção interna
// Timer/Counter1 de interrupcao Compare Match A
// Rotina executada quando o contador atinge o valor no registrador A
// Neste caso acende o LED apos 2s
ISR(TIMER1_COMPA_vect){
	if(sinal_on_off){
    	PORTD = 0b10000000; // Altera o valor do pino 7 da porta D
  	}
}

// Rotina executada quando o contador atinge o valor no registrador B
// Apaga o LED apos 3s do inicio do contador
ISR(TIMER1_COMPB_vect){
  	if(sinal_on_off){
      	PORTD = 0b00000000; // Altera o valor do pino 7 da porta D
  	}
  	TCNT1 = meu_zero; // Reinicia o contador
}

int main(void){
	// Registrador de controle do Timer1 - Resetando (Analog Pins param de funcionar). 
  	// Utilizamos em operacao normal. Ver pagina 170.
	TCCR1A = 0b00000000;
  	
	// Registrador de controle do Timer1 - aqui selecionamos o prescaler modificando os 3 ultimos bits.
  	// De acordo com a pagina 173 do Atmel-42735B-ATmega328/P_Datasheet_Complete-11/2016, utilizamos um prescaler de 1024.
  	// Por padrao o clock do arduino eh 16MHz. Como utilizamos um prescaler para ajustar o valor, temos um periodo de 1024/16MHz = 64us.
    // Para este periodo, precisamos de 1s/64us = 15625 contagens do contador para ter aproximadamente 1s. 
  	// O 4o bit alterado eh para 0, diferente dos casos anteriores. Pois nao queremos clear apos a comparacao.
  	TCCR1B = 0b00000101;
  
  	// Valor de comparaaco utilizado - Ver Pagina 180.
  	// Quando for igual, um compare match interrupt é gerado. Toda vez que bater o valor, ISR eh chamado com um COMPA.
  	// Capaz de armazenar valores de ate 16 bits. 
  	OCR1A = 31250; // Momemento erm que o contador atinge 2s - Liga o bit
  	OCR1B = 46875; // Atingiu 3s - desliga o bit - reseta contador
  	
  	// Ver Pagina 184. Controla as diferentes habilitacoes de interrupcoes para as funcoes de interrupcoes associados ao timer1.
  	// Ativamos o segundo e terceiro para habilitar uma interrupcao por match com o valor OCR1A e OCR1B.
  	TIMSK1 = 0b00000110; // Máscara do Timer1: habilita a interrupção por overflow
  	
  	//Registrador de Controle de Interrupções externas
  	EICRA = 0b00000010;
  
  	//Máscara das interrupções externas
  	// Habilita Interrupcao por pinos
  	EIMSK = 0b00000001;
  	
  	// Habilita a interrupção global
  	sei();
  
  	// Torna o pino 7 da Porta D uma saída digital
  	DDRD = 0b10000000;

  	attachInterrupt(digitalPinToInterrupt(2),ledOn,RISING);
  	while(1){}
}