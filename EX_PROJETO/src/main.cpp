/*
 Projeto exemplo: Controle de Motor
 por Fábio Souza
 Para o curso: Introdução a programação Arduino com VSCODE e PlatformIO,
 publicado na Udemy: https://www.udemy.com/user/fabiosouza/
*/

#include <Arduino.h>

#define MOTOR 9
#define BUZZER 6
#define POT A1
#define BT1 7
#define BT2 8

#define PRESSIONADO HIGH
#define SOLTO LOW

char debouncingBT1 = 100;
bool statusBT1;

bool statusMOTOR = 0;

void beep(void);

const byte tabela_7seg[11][7] =
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
  {1,1,0,0,1,1,1},  //P
};

void converteValorDisplay(byte valor){

  byte pino = 13;

  for(byte x = 0;x<7;x++){
    digitalWrite(pino,tabela_7seg[valor][x]);
    pino--;
    if(pino == 10) pino = 5;
  }

}

void setup() {
  pinMode(BT1,INPUT_PULLUP);
  pinMode(BT2,INPUT_PULLUP);
  pinMode(BUZZER,OUTPUT);
  pinMode(MOTOR,OUTPUT);

  for(int i = 2;i<14;i++){
    pinMode(i,OUTPUT);
    if(i==5) i = 10;
  }
}

void loop() {

  int valor = analogRead(POT);
  
  if(digitalRead(BT1)==LOW){
    debouncingBT1--;
    if(debouncingBT1 == 0 && statusBT1 == SOLTO){
      beep();
      statusMOTOR ^= 1;

      if(statusMOTOR){
        for(int i = 0;i<valor/4;i++){
          analogWrite(MOTOR,i);
          delay(10);
        }
      }
      else{
        for(int i = valor/4;i>0;i--){
          analogWrite(MOTOR,i);
          delay(10);
        }
      }

      statusBT1 = PRESSIONADO;
    }
  }
  else{
    debouncingBT1 = 100;
    statusBT1 = SOLTO;
  }

  if(statusMOTOR){
    analogWrite(MOTOR,map(valor,0,1023,0,255));
    converteValorDisplay(map(valor,0,1023,0,9));
  }
  else{
    analogWrite(MOTOR,0);
    converteValorDisplay(10);
  }


}

void beep(void){
  digitalWrite(BUZZER,HIGH);
  delay(100);
  digitalWrite(BUZZER,LOW);
  delay(100);
}