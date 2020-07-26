/*
 Exemplo para demonstrar o uso de comunicação serial para comandar placa
 por Fábio Souza
 Para o curso: Introdução a programação Arduino com VSCODE e PlatformIO,
 publicado na Udemy: https://www.udemy.com/user/fabiosouza/
*/

#include <Arduino.h>

#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define LED5 11
#define LED6 12
#define LED7 13


void setup() {
  Serial.begin(9600);
  for (int i = 2; i < 14; i++)
  {
    pinMode(i,OUTPUT);
    if(i==5) i=10;
  }
  
}

void loop() {
  
  if(Serial.available()>0){   //se chegou caracter

    char c = Serial.read();   //faz a leitura

    switch (c)  //verifica qual caracter chegou
    {
    case '1':
      digitalWrite(LED1,!digitalRead(LED1));
      break;
    case '2':
      digitalWrite(LED2,!digitalRead(LED2));
      break;
    case '3':
      digitalWrite(LED3,!digitalRead(LED3));
      break;
    case '4':
      digitalWrite(LED4,!digitalRead(LED4));
      break;
    case '5':
      digitalWrite(LED5,!digitalRead(LED5));
      break;
    case '6':
      digitalWrite(LED6,!digitalRead(LED6));
      break;
    case '7':
      digitalWrite(LED7,!digitalRead(LED7));
      break;
    }
  }
}