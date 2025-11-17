#include <movements.h>

int servoPins[NUM_SERVOS] = {2,3,4,5,6,7,8,9};

void setup() {
  initServos(servoPins);
  neutralStand();
  delay(1000);
}

void loop() {

  // Walk forward
  walkForward();
  delay(600);

  // Walk backward
  walkBackward();
  delay(600);

  // Turn left
  rotateLeft();
  delay(600);

  // Turn right
  rotateRight();
  delay(600);

  // Neutral pause
  neutralStand();
  delay(1000);
}
