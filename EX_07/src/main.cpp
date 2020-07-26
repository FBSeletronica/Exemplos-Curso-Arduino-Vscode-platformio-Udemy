/*
 Exemplo para demonstrar o uso de display LDC alfanumérico
 por Fábio Souza
 Para o curso: Introdução a programação Arduino com VSCODE e PlatformIO,
 publicado na Udemy: https://www.udemy.com/user/fabiosouza/
*/
#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 11, 12);

void setup() {
  lcd.begin(16,2);
  lcd.print("VALOR: ");
}

void loop() {
  int valor = analogRead(A1);
  lcd.setCursor(7,0);
  lcd.print("    ");
  lcd.setCursor(7,0);
  lcd.print(valor);

  if(valor > 511){
    lcd.setCursor(0,1);
    lcd.print("ALARME");
  }
  else
  {
    lcd.setCursor(0,1);
    lcd.print("      ");
  }
  

  delay(100);
}