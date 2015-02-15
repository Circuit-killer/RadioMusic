#include <Bounce.h>

//inputs
#define resetBtn 8
#define stationPot A9
#define stationCV A6
#define startPot A7
#define startCV A8
#define resetCV 9

//outputs
#define audioOut A14
#define LED1 3
#define LED2 4
#define LED3 5
#define LED4 6
#define LEDreset 11

Bounce resetSw = Bounce(resetBtn, 20); // Bounce setup for Reset

void setup() {

  //may as well read and write 12-bit values
  analogReadResolution(12);
  analogWriteResolution(12);

  //inputs
  pinMode(resetBtn, INPUT_PULLUP);
  pinMode(stationPot, INPUT);
  pinMode(stationCV, INPUT);
  pinMode(startPot, INPUT);
  pinMode(startCV, INPUT);
  pinMode(resetCV, INPUT_PULLUP);

  //outputs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LEDreset, OUTPUT);
  pinMode(audioOut, OUTPUT);
  
  analogReadResolution(12);
  analogWriteResolution(12);

  Serial.begin(115200);
}

void loop() {

  if (resetSw.update()) {
    //do something when the reset button is pressed
  }

  //just to check it's all working
  //read the pots and cv inputs and output to the LEDs
  analogWrite(LED1, analogRead(stationPot));
  analogWrite(LED2, analogRead(stationCV));
  analogWrite(LED3, analogRead(startPot));
  analogWrite(LED4, analogRead(startCV));
  //read the reset button and output to the reset LED
  digitalWriteFast(LEDreset, digitalRead(resetBtn));
 
}
