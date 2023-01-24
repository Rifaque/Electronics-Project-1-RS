// Automatic Room Light Controller with bidirectional visitor counter
// Project 1 Electronics
// Code by Rifaque

#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

#define in 14 //IR sensor for enter
#define out 19 //IR sensor for exit
#define relay 2 

int count = 0; //number of people in the room 

void IN()
{
  count++;
  lcd.clear();
  lcd.print("People in Room:");
  lcd.setCursor(0,1);
  lcd.print(count);
  delay(1000);
}

void OUT()
{
  count--;
  lcd.clear();
  lcd.print("People in Room:");
  lcd.setCursor(0,1);
  lcd.print(count);
  delay(1000);
}

void setup()
{
  lcd.begin(16,2);
  lcd.print("Visitor Counter");
  delay(2000);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  pinMode(relay, OUTPUT);
  lcd.clear();
  lcd.print("People in Room:");
  lcd.setCursor(0,1);
  lcd.print(count);
}

void loop()
{
  if(digitalRead(in))
  IN();
  if(digitalRead(out))
  OUT();

  if(count<=0)
  {
    lcd.clear();
    digitalWrite(relay, LOW);
    lcd.clear();
    lcd.print("Nobody in Room");
    lcd.setCursor(0,1);
    lcd.print("Light is OFF");
    delay(200);
  }
  else
    digitalWrite(relay,HIGH);
}
