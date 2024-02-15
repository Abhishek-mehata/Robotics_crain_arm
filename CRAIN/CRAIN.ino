
#include<Servo.h>
Servo s1;
Servo s2;
Servo s3;

//Variables For normal Condition of arm;
 int nrm_s1=0;
 int nrm_s2=0;
 int nrm_s3=0;

// variables to attach container from farm;
 int farm_s1;
 int farm_s2;
 int farm_s3;

// // variables to take container from farm to the air;
//   int air_s1;
//   int air_s2;
//   int air_s3;

//variables to take container from air to the Truck;
  int bot_s1;
  int bot_s2;
  int bot_s3;


//Variables for reverse to original;
  int rev_orig_s1;
  int rev_orig_s2;
  int rev_orig_s3;

//variables for electro Magnet
int electro_magnet_pin=4;

//For IR sensor
int i;//for IR sensor's  digital data input

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(3,INPUT);
  pinMode(electro_magnet_pin,OUTPUT);

}

void arm_in_original_position()
{
  s1.write(nrm_s1);
  delay(3000);
  s2.write(nrm_s2);
  delay(3000);
  s3.write(nrm_s3);
  delay(3000);
}

void arm_in_farm()
{
  s1.write(farm_s1);
  delay(2000);
  s2.write(farm_s2);
  delay(2000);
  s3.write(farm_s3);
  // digitalWrite(electro_magnet_pin,HIGH);
  delay(2000);
}

// void arm_in_air()
// {
//   s1.write(air_s1);
//   delay(2000);
//   s2.write(air_s2);
//   delay(2000);
//   s3.write(air_s3);
//   delay(2000);
// }

void arm_in_bot()
{
  s1.write(bot_s1);
  delay(1000);
  s2.write(bot_s2);
  delay(1000);
  s3.write(bot_s3);
  delay(1000);
}


void loop() {
  // digitalWrite(13,HIGH);
  // delay(1000);
  // digitalWrite(13,LOW);
  // delay(1000);
  // put your main code here, to run repeatedly:
  i=digitalRead(3);
  if(i == LOW) //means there is obstacle
  {
    digitalWrite(13,HIGH);
    delay(10);
    Serial.println("Bot has been Arrived.");
    arm_in_original_position();
    Serial.println("Bot is going to its original Position");
    delay(1000);
    arm_in_farm();
    Serial.println("Crain has Been Arrived at Farm to attach crain");
    digitalWrite(electro_magnet_pin,HIGH);
    Serial.println("Container is attached and magnet in ON");
    delay(1000);
    // arm_in_air();
    Serial.println("Crain is in air");
    delay(1000);
    arm_in_bot();
    Serial.println("Crain is in Bot");
    Serial.println("Container is dropped and magnetic property is loosed (magnet is OFF)");
    delay(1000);                                     

  }
  else if(i==HIGH) //means no any obstacle
  {
    digitalWrite(13,LOW);
    delay(10);

  }

}
