/*
 Exemplo para demonstrar o uso de entradas e saídas digitais
 por Fábio Souza
 Para o curso: Introdução a programação Arduino com VSCODE e PlatformIO,
 publicado na Udemy: https://www.udemy.com/user/fabiosouza/
*/
#include <Arduino.h>

//mapeamento dos pinos
#define LED1 2
#define LED2 3
#define BT1 7
#define BT2 8
#define BUZZER 6

//constantes
#define PRESSIONADO HIGH
#define SOLTO LOW

//Variáveis auxiliares
char debouncingBT1 = 100;
bool statusBT1;
char debouncingBT2 = 100;
bool statusBT2;

//Protótipo de funções
void beep(void);

void setup() {

  pinMode(BT1,INPUT_PULLUP);//configura BT1 como entrada com resistor de pull up interno habilitado
  pinMode(BT2,INPUT_PULLUP);//configura BT2 como entrada com resistor de pull up interno habilitado
  pinMode(LED1,OUTPUT);     //configura LED1 como saída
  pinMode(LED2,OUTPUT);     //configura LED2 como saída
  pinMode(BUZZER,OUTPUT);   //configura BUZZZER como saída
  //gera sinal sonoro incial
  beep(); //chama função beep
  beep();
  beep();
}

void loop() {
  
  if(digitalRead(BT1)==LOW){  //se botão pressionado
    debouncingBT1--;          //decrementa variável de Debouncing
    if(debouncingBT1 == 0 && statusBT1 == SOLTO){ //se Debouncing chegou a zeero e botão estava solto
      beep();                                 //faz beep sonoro
      digitalWrite(LED1,!digitalRead(LED1));  //inverte estado do LED1
      statusBT1 = PRESSIONADO;                //sinaliza botão pressionado
    }
  }
  else{                   //se não
    debouncingBT1 = 100;  //reinicia variável debouncing
    statusBT1 = SOLTO;    //sinaliza botão solto
  }


  if(digitalRead(BT2)==LOW){ //se botão pressionado
    debouncingBT2--;          //decrementa variável de Debouncing
    if(debouncingBT2 == 0 && statusBT2 == SOLTO){ //se Debouncing chegou a zeero e botão estava solto
      beep();                                     //faz beep sonoro
      digitalWrite(LED2,!digitalRead(LED2));      //inverte estado do LED2
      statusBT2 = PRESSIONADO;                    //sinaliza botão pressionado
    }
  }
  else{                   //se não
    debouncingBT2 = 100;  //reinicia debouncing
    statusBT2 = SOLTO;    //sinaliza solto
  }
}

/*
  Função beep: Faz sinal sonoro
  retorno: nada
  parâmetros:nada
*/
void beep(void){
  digitalWrite(BUZZER,HIGH);  //liga buzzer 
  delay(100);                 //espera 0.1 s
  digitalWrite(BUZZER,LOW);   //desliga buzzer
  delay(100);                 //espera 0.1 s
}