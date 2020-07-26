/*
 Exemplo para demonstrar o uso de saídas PWM
 por Fábio Souza
 Para o curso: Introdução a programação Arduino com VSCODE e PlatformIO,
 publicado na Udemy: https://www.udemy.com/user/fabiosouza/
*/

#include <Arduino.h>

#define LED1 11
#define LED2 5
#define LED3 3

void setup() {
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
}

void loop() {
  int valor = analogRead(A1)/4;   //faz a leitura da Entrada A1 e ajusta valor para escala de 0 a 255
  analogWrite(LED1,valor);        //atualiza LED 1 com o valor lido
  analogWrite(LED2,255 - valor);  //atualiza LED 1 com o inverso do valor lido 
  analogWrite(LED3,valor);        //atualiza LED 1 com o valor lido
  
}