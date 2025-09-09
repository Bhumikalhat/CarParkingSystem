int count = 0;
char input[12];
#include <LiquidCrystal.h>// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
#include <Servo.h> 
Servo myservo1;

int ir_s1 = 2;
int ir_s2 = 4;

int Total = 5;
int Space;

int flag1 = 0;
int flag2 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ir_s1, INPUT);
pinMode(ir_s2, INPUT);

myservo1.attach(3);
myservo1.write(100);

lcd.begin(16, 2);  
lcd.setCursor (0,0);
lcd.print("  Car  Parking  ");
lcd.setCursor (0,1);
lcd.print("     System     ");
delay (2000);
lcd.clear();  

Space = Total;
}

void loop() {
  if(digitalRead (ir_s1) == LOW && flag1==0){
if(Space>0){flag1=1;
if(flag2==0){myservo1.write(0); Space = Space-1;}
}else{
lcd.setCursor (0,0);
lcd.print(" Sorry not Space ");  
lcd.setCursor (0,1);
lcd.print("    Available    "); 
delay (1000);
lcd.clear(); 
}
}

if(digitalRead (ir_s2) == LOW && flag2==0){flag2=1;
if(flag1==0){myservo1.write(0); Space = Space+1;}
}

if(flag1==1 && flag2==1){
delay (1000);
myservo1.write(100);
flag1=0, flag2=0;
}

lcd.setCursor (0,0);
lcd.print("Total Space: ");
lcd.print(Total);

lcd.setCursor (0,1);
lcd.print("Have  Space: ");
lcd.print(Space);

  if(Serial.available())
  {
    count = 0;
    while(Serial.available() && count < 12)
    {
      input[count] = Serial.read();
      count++;
      delay(5);
    }
    if(input[0] == '4' && input[1] == 'C' && input[2] == '0' && input[3] == '0' &&
       input[4] == '9' && input[5] == 'E' && input[6] == 'A' && input[7] == 'D' &&
       input[8] == 'B' && input[9] == 'A' && input[10] == 'C' && input[11] == '5' )
    {
      myservo1.write(100);
      delay(1000);
      myservo1.write(0);
    }
  }
  if(Serial.available())
  {
    count = 0;
    while(Serial.available() && count < 12)
    {
      input[count] = Serial.read();
      count++;
      delay(5);
    }
    if(input[0] == '4' && input[1] == 'C' && input[2] == '0' && input[3] == '0' &&
       input[4] == 'A' && input[5] == 'A' && input[6] == '3' && input[7] == 'F' &&
       input[8] == 'D' && input[9] == '5' && input[10] == '0' && input[11] == 'C' )
    {
      myservo1.write(100);
      delay(1000);
      myservo1.write(0);
    }
  }
  if(Serial.available())
  {
    count = 0;
    while(Serial.available() && count < 12)
    {
      input[count] = Serial.read();
      count++;
      delay(5);
    }
    if(input[0] == '4' && input[1] == 'C' && input[2] == '0' && input[3] == '0' &&
       input[4] == 'A' && input[5] == '9' && input[6] == 'A' && input[7] == '9' &&
       input[8] == 'D' && input[9] == '4' && input[10] == '9' && input[11] == '8' )
    {
      myservo1.write(100);
      delay(1000);
      myservo1.write(0);
    }
  }if(Serial.available())
  {
    count = 0;
    while(Serial.available() && count < 12)
    {
      input[count] = Serial.read();
      count++;
      delay(5);
    }
    if(input[0] == '4' && input[1] == 'C' && input[2] == '0' && input[3] == '0' &&
       input[4] == '9' && input[5] == 'F' && input[6] == 'B' && input[7] == '4' &&
       input[8] == '1' && input[9] == '1' && input[10] == '7' && input[11] == '6' )
    {
      myservo1.write(100);
      delay(1000);
      myservo1.write(0);
    }
  }
  }
