#include <Servo.h>
Servo s1;//Motor A
Servo s2;//Motor B
Servo s3;//Motor C


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

void setup() 
{
  // put your setup code here, to run once:
  // Serial.begin();
  s1.attach(9);
  s2.attach(10);
  s3.attach(11);
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
  container_in_farm();
  container_in_air();
  container_in_bot();
}
