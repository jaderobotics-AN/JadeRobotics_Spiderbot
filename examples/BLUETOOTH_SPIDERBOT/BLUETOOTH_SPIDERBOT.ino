#include <Servo.h>
#include "movements.h"

// Pins for the 8 servos
int servoPins[NUM_SERVOS] = {2,3,4,5,6,7,8,9};

void setup() {

  Serial.begin(9600);    // Works for Bluetooth (HC-05) & USB
  initServos(servoPins); // Initialize servos from library

  delay(300);
  neutralStand();        // Start in neutral pose
}

void processCommand(char cmd) {

  switch (cmd) {

    case 'S': neutralStand();   break;
    case 'F': walkForward();    break;
    case 'B': walkBackward();   break;
    case 'A': rotateLeft();     break;
    case 'C': rotateRight();    break;

    case 'U': lieDownPose();    break;
    case 'H': sayHiMotion();    break;
    case 'V': fightMotion();    break;
    case 'P': pushUpMotion();   break;

    case 'Y': danceMove1();     break;
    case 'Z': danceMove2();     break;

    default:
      break;
  }
}

void loop() {

  if (Serial.available()) {
    char cmd = Serial.read();
    processCommand(cmd);
  }
}
