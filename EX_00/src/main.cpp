/*
 Exemplo para Hello World com Arduino
 por Fábio Souza
 Para o curso: Introdução a programação Arduino com VSCODE e PlatformIO,
 publicado na Udemy: https://www.udemy.com/user/fabiosouza/
*/
#include <Arduino.h>

void setup() {
  pinMode(13,OUTPUT);   //configura pino 13 como saída
  Serial.begin(115200); //Configura comunicação serial para bauda rate de 115200 bps
}

void loop() {
  digitalWrite(13,HIGH);  //coloca pino em nível alto
  delay(500);             //espera 0,5 s
  digitalWrite(13,LOW);   //coloca pino em nível baixo
  delay(500);             //espera 0,5 s
  Serial.println("Hello");//imprime "Hello" e pula uma linha
}