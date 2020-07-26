/*
 Exemplo para demonstrar o uso de saídas digitais
 por Fábio Souza
 Para o curso: Introdução a programação Arduino com VSCODE e PlatformIO,
 publicado na Udemy: https://www.udemy.com/user/fabiosouza/
*/
#include <Arduino.h>

void setup() {
  //configura pinos dos LEDs como saídas
  pinMode(2,OUTPUT);  
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  
  //Acende LEDs em ordem crescente
  for (int i = 2; i < 14; i++)
  {
    digitalWrite(i,HIGH); //coloca nível alto no pino i
    delay(100);           //aguarda 100 ms
    if(i== 5) i = 10; //se chegou no pino 5, pula para 10
  }
  //Apaga LEDs em ordem decrescente
  for(int i = 13;i> 1;i--){ //varre pinos de 13 a 2
    digitalWrite(i,LOW);  //coloca nível baixo no pino i
    delay(100);           //delay 100 ms
    if(i== 11) i = 6;//se chegou no pino 11, pula para 6
  }

  delay(1000);  //aghaurda 1 segundo


}