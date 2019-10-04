#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,5,4,3,2);

int grp[4],count;
byte back,add,next;
byte addState,backState,nextState,scrnState;
String names[4]={"Group A","Group B","Group C","Group D"};

void setup() {
  // put your setup code here, to run once:


  count=0;
  
  for(byte a=0;a<4;a++)
  {
    grp[a]=0;
  }
  
  backState=nextState=addState=scrnState=false;
  back=add=next=0;
  
  lcd.begin(16,2);
  lcd.print("   Electronic   ");
  lcd.setCursor(0,1);
  lcd.print(" Voting Machine ");
  
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  back=digitalRead(A3);
  add=digitalRead(A4);
  next=digitalRead(A5);

  if(add==HIGH&&addState==false)
  {
    addState=true;
  }

  if(back==HIGH&&backState==false)
  {
    backState=true;
  }

  if(next==HIGH&&nextState==false)
  {
    nextState=true;
  }
  
  if(add==LOW&&addState==true&&scrnState==false)
  {
    lcd.clear();
    lcd.print(names[count]);
    lcd.setCursor(0,1);
    lcd.print(grp[count]);
    scrnState=true;
    addState=false;
  }

  if(add==LOW&&addState==true)
  {
      grp[count]++;
      lcd.clear();
      lcd.print(names[count]);
      lcd.setCursor(0,1);
      lcd.print(grp[count]);
      addState=false;
  
  }

  if(back==LOW&&backState==true)
  {
      count--;
      if(count<0)
      {
        count=3;
      }
      lcd.clear();
      lcd.print(names[count]);
      lcd.setCursor(0,1);
      lcd.print(grp[count]);
      backState=false;
  
  }


  if(next==LOW&&nextState==true)
  {
      count++;
      if(count>3)
      {
        count=0;
      }
      lcd.clear();
      lcd.print(names[count]);
      lcd.setCursor(0,1);
      lcd.print(grp[count]);
      nextState=false;
  
  }
  
}
