/*
  Project 1 – Sprints
  Da Xu
  VDES29207 3D Design 2: Modeling
  Winter 2021 / Bachelor of Interaction Design
  
  This code is based on Adafruit NeoPixel library Example
  https://electropeak.com/learn/

*/
#include <Adafruit_NeoPixel.h>
#define PIN 2          
#define NUMPIXELS      1 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int redColor = 0;
int greenColor = 0;
int blueColor = 0;

#include <Servo.h>
Servo myservo;  
int pos = 0;
  
void setup() 
{
  pixels.begin(); 
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() 
{ 
  for (pos = 0; pos <= 180; pos += 1) 
  { 
    setColor();   
    pixels.setPixelColor(0, pixels.Color(redColor, greenColor, blueColor)); 
    pixels.show();
    myservo.write(pos);            
    delay(20);                     
  }
  for (pos = 180; pos >= 0; pos -= 1) 
  {
    setColor();  
    pixels.setPixelColor(0, pixels.Color(redColor, greenColor, blueColor)); 
    pixels.show();  
    myservo.write(pos);             
    delay(20);                      
  }
    
}



void setColor()                      
{
  redColor = random(0, 255);         
  greenColor = random(0,255); 
  blueColor = random(0, 255); 
  Serial.print("red: ");
  Serial.println(redColor);
  Serial.print("green: ");
  Serial.println(greenColor);
  Serial.print("blue: ");
  Serial.println(blueColor);
  
}
