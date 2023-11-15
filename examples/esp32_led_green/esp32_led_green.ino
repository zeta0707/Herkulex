#include <Herkulex.h>

void setup() {
  int n;

  delay(2000);           //a delay to have time for serial monitor opening
  Serial.begin(115200);  // Open serial communications
  Serial.println("Begin");
  Herkulex.beginSerial1(115200, 4, 15);
  for (n = 1; n < 4; n++) {
    Herkulex.reboot(n);  //reboot
    delay(500);
  }
  Herkulex.initialize();  //initialize motors

  n=1;
  Serial.println("Set Led Green");
  Herkulex.setLed(n,LED_GREEN2); //set the led to green
  Serial.print("Status:"); 
  Serial.println(Herkulex.stat(n)); //verify error code

  n=2;
  Serial.println("Set Led Blue");
  Herkulex.setLed(n,LED_BLUE); //set the led to green
  Serial.print("Status:"); 
  Serial.println(Herkulex.stat(n)); //verify error code

  n=3;
  Serial.println("Set Led Red");
  Herkulex.setLed(n,LED_RED); //set the led to green
  Serial.print("Status:"); 
  Serial.println(Herkulex.stat(n)); //verify error code
  Herkulex.end();

}

void loop() {
}
