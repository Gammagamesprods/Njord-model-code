#include <Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  const float sver = 0.5;
  const float hver = 0.2;
  const float fver = 0.3;
  pinMode(13,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(4,INPUT);
  pinMode(12,OUTPUT);
  myservo.attach(10);
  digitalWrite(13,LOW);
  Serial.begin(9600);
  Serial.println("init...");
  delay(2000);
  Serial.print("software version ");
  Serial.println(sver);
  delay(500);
  Serial.print("hardware version ");
  Serial.println(hver);
  delay(500);
  Serial.print("firmware version ");
  Serial.println(fver);
  delay(500);
  Serial.println("Made by Ben Sprowl for use by Future City Team Njord");
  Serial.println("All Rights Reserved");
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(600);
  digitalWrite(13,HIGH);
  delay(300);
  digitalWrite(13,LOW);
  delay(300);
  digitalWrite(13,HIGH);
  delay(300);
  digitalWrite(13,LOW);
  Serial.println("[INFO] Waiting for user key input");
  digitalWrite(2,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(8) == HIGH) {
    Serial.println("[INFO] Keyswitch confirmed. awaiting power switch.");
    goto one;
    one:
      if (digitalRead(7) == HIGH) {
        Serial.println("[INFO] Power received. starting mainprogram.ino...");
        digitalWrite(2,LOW);
        delay(1000);
        digitalWrite(3,HIGH);
        delay(2000);
        goto two;
      }
       else {
         goto one;
       }
        two:
          if (digitalRead(4) == HIGH) {
            Serial.println("[INFO] Switch triggered! running servo...");
            myservo.write(50);
            goto three;
            three:
              if (digitalRead(4) == LOW) {
                myservo.write(-50);
              }
                else {
                  goto three;
                }
              
      }
  }
}
