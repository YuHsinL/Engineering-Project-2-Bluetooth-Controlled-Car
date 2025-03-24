#include <AFMotor.h>
#include <SoftwareSerial.h>

AF_DCMotor motor_L(1);
AF_DCMotor motor_R(2);
AF_DCMotor motor_F(3);
SoftwareSerial btSerial(A4, A5); //RX, TX

void setup() {
  Serial.begin(9600);
  btSerial.begin(9600);
}

void loop() {
  motor_F.setSpeed(250);
  motor_F.run(FORWARD);
  if (btSerial.available()){
    char i = btSerial.read();
    Serial.println(i);
    if(i == 'w'){
      Serial.println("forward");
      motor_R.setSpeed(200);
      motor_L.setSpeed(200);
      motor_R.run(FORWARD);
      motor_L.run(FORWARD);
    }
    if(i == 'd'){
      Serial.println("right");
      motor_R.setSpeed(60);
      motor_L.setSpeed(200);
      motor_R.run(FORWARD);
      motor_L.run(FORWARD);
    }
    if(i == 'a'){
      Serial.println("left");
      motor_R.setSpeed(200);
      motor_L.setSpeed(60);
      motor_R.run(FORWARD);
      motor_L.run(FORWARD);
    }
    if(i == 's'){
      Serial.println("backward");
      motor_R.setSpeed(200);
      motor_L.setSpeed(200);
      motor_R.run(BACKWARD);
      motor_L.run(BACKWARD);
    }
    if(i == '0'){
      Serial.println("stop");
      motor_R.setSpeed(0);
      motor_L.setSpeed(0);
    }
  }
}

