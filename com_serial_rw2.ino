#include <stdio.h>
#include <stdlib.h>
#include "U8glib.h"

float T=0;
String string;
int temp;
float temperatura; 
int pinoLed = 13; //DEFINE O PINO EM QUE O LED ESTÁ CONECTADO
int status = 0; //VARIÁVEL QUE CONTROLA O STATUS (LIGADO / DESLIGADO)
U8GLIB_SSD1306_128X64_2X u8g(U8G_I2C_OPT_NONE);

void draw()
{
    //Comandos graficos para o display devem ser colocados aqui
  //Seleciona a fonte de texto
  u8g.setFont(u8g_font_8x13B);
  //Linha superior - temperatura
  u8g.drawStr( 5, 15, "23");
  u8g.drawCircle(28,8,3);
  u8g.drawStr( 34, 15, "C");
    

}
void setup() 
{
  pinMode(pinoLed, OUTPUT); //DECLARA O PINO COMO SAÍDA
  digitalWrite(pinoLed, LOW); //LED INICIA DESLIGADO
  Serial.begin(9600);
}

void loop() 
{
  temp = analogRead(A1);
  temperatura = (1.4*temp*100.0/1023.0);
  Serial.print("T= ");
  Serial.println(temperatura);
  delay(10000);
  
  if(Serial.available()>0)string="";
    while(Serial.available()>0)
    {
      char c = Serial.read();
      if(c==';')
      {
        break; 
      }else
      {
        string +=c; //String = String+c; 
      }
      delay(100);  
    }
    
 }
