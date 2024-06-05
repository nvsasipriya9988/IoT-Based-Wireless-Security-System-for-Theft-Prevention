#include <Wire.h>  // Wire library - used for I2C communication
#include<SoftwareSerial.h>
SoftwareSerial gps(2,3);
#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);
int lock=A0;
int relay1=7;
int relay2=6;
int buz=5;
int val=0;
int i=0,k=0;
int  gps_status=0;
float latitude=0; 
float logitude=0;                       
String Speed="";
String gpsString="";
char *test="$GPRMC";

void setup() 
{
  Serial.begin(9600);
  pinMode(lock,INPUT);
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(buz,OUTPUT);
  lcd.begin(16,2);
  lcd.print("Theft detection");
  lcd.setCursor(0,1);
  lcd.print(" Alert System  ");
  delay(2000);
  lcd.clear();
  lcd.print("Initializing");
  lcd.setCursor(0,1);
  lcd.print("Please Wait...");
  delay(1000);
  lcd.clear();
  lcd.print("Initialized");
  lcd.setCursor(0,1);
  lcd.print("Successfully");
  delay(2000);
  lcd.clear();
  lcd.print("Callibrating ");
  lcd.setCursor(0,1);
  lcd.print("Acceleromiter");
  delay(1000);
  lcd.clear();
  lcd.print("Waiting For GPS");
  lcd.setCursor(0,1);
  lcd.print("     Signal    ");
  delay(2000);
  lcd.clear();
  lcd.print("GPS is Ready");
  delay(1000);
  lcd.clear();
  lcd.print("System Ready");
  Serial.println("System Ready..");
}


void loop() 
{
  val = analogRead(A0);
  //Serial.println(val);
  if(val < 10)
  {
    lcd.clear();
    lcd.print("Theft Detection");
    lcd.setCursor(0,1);
    lcd.print("Trig Activated");
    digitalWrite(buz,HIGH);
    delay(2000);
    lcd.clear();
    lcd.print("Alerting Sysem");
    lcd.setCursor(0,1);
    lcd.print("Sms Sending");
    delay(2000);
    lcd.clear();
    Send();
    digitalWrite(buz,LOW);
  }
}



void Send()

{ 
  Serial.print("Your vehical is theft location alerts Latitude:15.433494, longitude:80.046095");
  delay(2000);
  Serial.print("http://maps.google.com/maps?&z=15&mrt=yp&t=k&q=");
  delay(2000);
}
