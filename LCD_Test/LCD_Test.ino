#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 13, 9, 4, 5, 6, 7);

byte customChar[8] =
{

B00000,  
B01010,
B11111,
B11111,
B01110,
B00100,
B00000

};

void setup() {
  
  lcd.begin(16,2);
  lcd.clear();
  lcd.createChar(1, customChar);
}

void loop(){
  
  lcd.setCursor(0,0);
  for (int i=0; i <= 16; i++){ 
    lcd.leftToRight();   
    lcd.write(1);
    delay(100);
  }
  
  lcd.setCursor(16,1);
  for (int i=0; i <= 16; i++){    
    lcd.rightToLeft();
    lcd.write(1);
    delay(100);
  }  
  
  for (int positionCounter = 0; positionCounter < 16; positionCounter++){    
    lcd.scrollDisplayRight();
    delay(100);
  }  
  for (int positionCounter = 0; positionCounter < 16; positionCounter++){    
    lcd.scrollDisplayLeft();
    delay(100); 
  } 
  
  /*
  delay(1600);
  
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Hello Friend");
  lcd.blink();
  
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0,1);  
  lcd.print("FUUUUUUUUUUUUUU");
  
  delay(2000);
  
  lcd.clear();
  lcd.noBlink();
  lcd.noCursor();
  lcd.print("Bye bye... :( ");
  
  delay(1000);
  */
  
  lcd.noDisplay();  
  lcd.clear();  
  delay(2000);  
  lcd.display();  
}
  
  
  
  
