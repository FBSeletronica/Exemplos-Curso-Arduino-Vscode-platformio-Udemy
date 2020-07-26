/*
 Exemplo para demonstrar o uso de entradas analógicas
 por Fábio Souza
 Para o curso: Introdução a programação Arduino com VSCODE e PlatformIO,
 publicado na Udemy: https://www.udemy.com/user/fabiosouza/
*/

#include <Arduino.h>

#define POT_PIN A1
#define BUZZER 6
#define A 13
#define B 12
#define C 11
#define D 5
#define E 4
#define F 3
#define G 2

#define ALARME 800

const byte tabela_7seg[10][7] =
{//A B C D E F G
  {1,1,1,1,1,1,0},  //0
  {0,1,1,0,0,0,0},  //1
  {1,1,0,1,1,0,1},  //2
  {1,1,1,1,0,0,1},  //3
  {0,1,1,0,0,1,1},  //4
  {1,0,1,1,0,1,1},  //5
  {1,0,1,1,1,1,1},  //6
  {1,1,1,0,0,0,0},  //7
  {1,1,1,1,1,1,1},  //8
  {1,1,1,1,0,1,1},  //9
};

void converteValorDisplay(byte valor){

  byte pino = 13;

  for(byte x = 0;x<7;x++){
    digitalWrite(pino,tabela_7seg[valor][x]);
    pino--;
    if(pino == 10) pino = 5;
  }

}

void beep(void){
  digitalWrite(BUZZER,HIGH);
  delay(100);
  digitalWrite(BUZZER,LOW);
  delay(100);
}

void setup() {
  Serial.begin(9600);
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(E,OUTPUT);
  pinMode(F,OUTPUT);
  pinMode(G,OUTPUT);

  pinMode(BUZZER,OUTPUT);
}

void loop() {
  int valor = analogRead(POT_PIN);
  Serial.println(valor);
  converteValorDisplay(map(valor, 0, 1023, 0, 9));

  if (valor>ALARME)
  {
    beep();
  }
  

  delay(300);

}