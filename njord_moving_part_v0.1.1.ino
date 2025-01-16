#include <Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  const float sver = 1.5;
  const float hver = 1.0;
  const float fver = 1.2;
  int serstat = 0;
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(4,LOW);
  pinMode(13,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(4,INPUT);
  pinMode(12,OUTPUT);
  pinMode(5, INPUT);
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
  int serstat = 0;
  goto zero;
  // put your main code here, to run repeatedly:
  zero:
    if (digitalRead(8) == HIGH) {
      Serial.println("[INFO] Keyswitch confirmed. awaiting power switch.");
      goto one;
    }
     else {
      goto zero;
     }
      one:
        while (digitalRead(8) == HIGH) {
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
               int serstat = 1;
               digitalWrite(3,LOW);
               delay(500);
               digitalWrite(2,HIGH);
               delay(500);
               myservo.write(50);
               delay(500);
               digitalWrite(2,LOW);
               delay(500);
               digitalWrite(3,HIGH);
               goto three;
               three:
                 if (digitalRead(4) == LOW) {
                   Serial.println("[INFO] Switch turned off! Restoring to default.");
                   int serstat = 0;
                   digitalWrite(3,LOW);
                   delay(500);
                   digitalWrite(2,HIGH);
                   delay(500);
                   myservo.write(-50);
                   digitalWrite(2,LOW);
                   delay(500);
                   digitalWrite(3,HIGH);
                 }
                   else {
                     goto three;
                   }
             }
       } // below: recovery script and error interface control
       if (digitalRead(8) == LOW || digitalRead(7) == LOW || digitalRead(5) == HIGH) {
         digitalWrite(3,LOW);
         delay(500);
         digitalWrite(2,HIGH);
         Serial.println("[WARN] Fatal error. Attempting to fix (0)");
         delay(1000);
         digitalWrite(2,LOW);
         Serial.println("[WARN] Fatal error. Attempting to fix (1)");
         delay(1000);
         digitalWrite(2,HIGH);
         Serial.println("[WARN] Fatal error. Attempting to fix (2)");
         delay(1000);
         digitalWrite(2,LOW);
         Serial.println("[WARN] Fatal error. Attempting to fix (3)");
         delay(1000);
         digitalWrite(2,HIGH);
         Serial.println("[WARN] Fatal error. Attempting to fix (4)");
         delay(1000);
         digitalWrite(2,LOW);
         Serial.println("[WARN] Fatal error. Attempting to fix (5)");
         delay(1000);
         digitalWrite(2,HIGH);
         Serial.println("[WARN] Fatal error. Attempting to fix (6)");
         delay(1000);
         digitalWrite(2,LOW);
         if (digitalRead(8) == HIGH && digitalRead(7) == HIGH && digitalRead(5) == LOW) {
           Serial.println("[INFO] Program recovered. Returning to normal operation.");
           if (serstat == 1) {
             goto three;
           }
           else if (serstat == 0) {
             goto two;
           }
           else {
             Serial.println("[ERROR] Error returning to normal operation! Shutting down.");
             delay(500);
             exit(0);
           }
         }
         Serial.println("[ERROR] Could not fix fatal error!");
         delay(1000);
         Serial.println("[FATAL] Error! Unable to fix! Shutting down.");
         delay(500);
         Serial.println("[SYS] System shut down with exit.code 0. stopping board program.");
         delay(500);
         exit(0);
        }
        else if (digitalRead(5) == HIGH) {
          Serial.println("[WARN] Kernel panic button pressed! Going into Kernel Panic...");
          delay(500);
          exit(0);
        }
 }
