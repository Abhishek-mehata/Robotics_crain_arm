#include <Servo.h>
Servo s1;//Motor A
Servo s2;//Motor B
Servo s3;//Motor C

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
  s2.attach(10);
  s3.attach(11);
  pinMode(13,OUTPUT);
}

void container_in_original_position()
{
    s1.write(original_m1);
    delay(1000);
    s2.write(original_m2);
    delay(1000);
    s3.write(original_m3);
    delay(1000);
}
void container_in_farm()
{
    s1.write(farm_m1);
    delay(1000);
    s2.write(farm_m2);
    delay(1000);
    s3.write(farm_m3);
    delay(1000);
}

void container_in_air()
{
    s1.write(air_m1);
    delay(1000);
    s2.write(air_m2);
    delay(1000);
    s3.write(air_m3);
    delay(1000);


}

void container_in_bot()
{
    s1.write(bot_m1);
    delay(1000);
    s2.write(bot_m2);
    delay(1000);
    s3.write(bot_m3);
    delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  ldr_sensorvalue = analogRead(ldr_pin); // Read analog value from LDR
  ldr_binaryvalue = ((ldr_sensorvalue >ldr_midvalue) ? 0 : 1); // Convert to digital
  Serial.println(ldr_binaryvalue); // Gives binary value of LDR resistor
  Serial.println(ldr_sensorvalue);
  if(ldr_binaryvalue==1)
  {
      Serial.println("Bot Has been Reached at farm");
      container_in_air();
      Serial.println("Putting Arm in air");
      delay(2000);
      container_in_farm();
      Serial.println("Putting Arm From air to the farm to attach with container");
      digitalWrite(electro_magnet_pin,HIGH);
      Serial.println("Electromagnet Turns ON");
      delay(2000);
      container_in_air();
      Serial.println("Again keeping container attached arm in air");
      delay(2000);
      container_in_bot();
      Serial.println("Putting container attached arm from air to bot");
      delay(3000);
      digitalWrite(electro_magnet_pin,LOW);
      Serial.println("Electro Magnet Turns OFF");
      delay(1000);
      container_in_original_position();
      Serial.println("Finally putting Arm in it's Original Position");
      delay(1000);
  }
  else{
    Serial.println("Bot Not Reached Yet In Farm");
    container_in_original_position();
  }
}