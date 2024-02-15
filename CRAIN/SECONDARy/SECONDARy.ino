#include <Servo.h>
Servo s1;//Motor A
// Servo s2;//Motor B
// Servo s3;//Motor C

//Arm Original Position
const int original_m1=0;// In degree For Motor A
const int original_m2=0;// In degree For Motor B
const int original_m3=0;// In degree For Motor C

// Farm Motor Controls data variables
int farm_m1=90;// In degree For Motor A
int farm_m2=90;// In degree For Motor B
int farm_m3=90;// In degree For Motor C

//In Air controls Data
int air_m1=145;// In degree For Motor A
int air_m2=145;// In degree For Motor B
int air_m3=145;// In degree For Motor C

// Bot Motor control data variables
int bot_m1=360;// In degree For Motor A
int bot_m2=360;// In degree For Motor B
int bot_m3=360;// In degree For Motor C

//  Variables and data assigning  for LDR resistor
const int ldr_pin=A0;
const int ldr_midvalue=500;//ny analog reading from the LDR that is greater than 500 will be considered 
// as indicating a light condition, and any reading less than or equal to 500 will be considered as
// indicating a dark condition.
int ldr_sensorvalue;
int ldr_binaryvalue;


//variables for electro Magnet
int electro_magnet_pin=13;


void setup() 
{
  // put your setup code here, to run once:
  // Serial.begin();
  Serial.begin(9600); // Initialize serial communication
  s1.attach(9);
  // s2.attach(10);
  // s3.attach(11);
  pinMode(electro_magnet_pin,OUTPUT);
}
void loop()
{
    // put your main code here, to run repeatedly:
  ldr_sensorvalue = analogRead(ldr_pin); // Read analog value from LDR
  ldr_binaryvalue = ((ldr_sensorvalue >ldr_midvalue) ? 1 : 0); // Convert to digital
  Serial.println(ldr_binaryvalue); // Gives binary value of LDR resistor
  Serial.println(ldr_sensorvalue);
  delay(2000);
}
