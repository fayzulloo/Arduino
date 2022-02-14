


// include the library code:
#include <LiquidCrystal.h> //LCD display library

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //LCD pins
int bir1, nol1, i = 6, j = 0, a = 6, sum, but, clc;

int bul[10] = {};

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  pinMode(7, INPUT);
  pinMode(A0, INPUT);
  
  lcd.begin(16, 2);

  lcd.setCursor(0,0);
  lcd.print("ikki. "); 

  lcd.setCursor(0,1);
  lcd.print("o'nli ");
}

void loop() {
  clc = digitalRead(A0);
  delay(10);
  if(clc == 1)
  {
    i = 6;
    j = 0;
    a = 6;
    sum = 0;

    lcd.clear();
    
    lcd.setCursor(0,0);
    lcd.print("bin ");  //bin => binary

    lcd.setCursor(0,1);
    lcd.print("dec "); //dec => decimal
  }
  bir1 = digitalRead(9);
  delay(70);
  
  lcd.setCursor(i,0);
   if(bir1 == 1)
   {
     lcd.print('1');
     i++;
     bul[j] = 1;
     j++;
   }
 
  nol1 = digitalRead(8);
  delay(70);
  lcd.setCursor(i,0);
   if(nol1 == 1)
   {
     lcd.print('0');
     i++;
     bul[j] = 0;
     j++;
   }
   delay(50);

   but = digitalRead(7);

   int k = 0;
   if(but == 1)
   {
    for(int i = j - 1; i >= 0; i--)
    {
     sum = sum + (bul[i] * Pow(2, k));
     k++; 
    }
    lcd.setCursor(6,1);
    lcd.print(sum);
   }

   
  
}

double Pow(double x, double y) //function to get the degree of a number
{
  double ans = 1;
  for(double i = y; i > 0; i--)
  {
    ans = x * ans;
  }
  return ans;
}


