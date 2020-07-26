/*
 Exemplo para demonstrar o uso de display de 7 segmentos
 por Fábio Souza
 Para o curso: Introdução a programação Arduino com VSCODE e PlatformIO,
 publicado na Udemy: https://www.udemy.com/user/fabiosouza/
*/
#include <Arduino.h>

//mapeamento dos pinos
#define A 13
#define B 12
#define C 11
#define D 5
#define E 4
#define F 3
#define G 2

//variável global
int valor = 0;

//cosntante para conversão
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

//funão para conversão de valor em 7 segmentos
void converteValorDisplay(byte valor){

  byte pino = 13; //variável para varredura dos pinos

  for(byte x = 0;x<7;x++){  //varre tabela
    digitalWrite(pino,tabela_7seg[valor][x]);//atualiza segmento
    pino--; //decrementa pino
    if(pino == 10) pino = 5;  //se chegou em 10 pula para 5
  }
}


void setup() {
  //configura pinos do display como saidas
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(E,OUTPUT);
  pinMode(F,OUTPUT);
  pinMode(G,OUTPUT);
}

void loop() {
  converteValorDisplay(valor++);  //atualiza display e incrementa valor
  delay(1000);                    //espera 1 seg
  if(valor>9)valor=0;             //se chegou em 10 reinicia
}