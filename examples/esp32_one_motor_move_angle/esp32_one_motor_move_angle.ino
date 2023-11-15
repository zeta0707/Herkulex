#include <Herkulex.h>
int n = 1;  //motor ID - verify your ID !!!!

void setup() {
  delay(2000);           //a delay to have time for serial monitor opening
  Serial.begin(115200);  // Open serial communications
  Serial.println("Begin");
  Herkulex.beginSerial1(115200, 16, 17);  //open serial port 1

  Herkulex.reboot(1);
  Herkulex.reboot(2);
  Herkulex.reboot(3);
  delay(500);
  Herkulex.initialize();  //initialize motors
  delay(200);
}

void loop() {
  while(1) {
    Serial.println("Move Angle: -60 degrees");
    Herkulex.moveOneAngle(n, -30, 100, LED_BLUE);  //move motor with 300 speed
    delay(1200);
    Serial.print("Get servo Angle:");
    Serial.println(Herkulex.getAngle(n));
    Serial.println("Move Angle: 60 degrees");
    Herkulex.moveOneAngle(n, 30, 100, LED_BLUE);  //move motor with 300 speed
    delay(1200);
    Serial.print("Get servo Angle:");
    Serial.println(Herkulex.getAngle(n));
    n++;
    if(n>3) n=1;
  }
}
