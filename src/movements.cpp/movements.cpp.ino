#include "movements.h"
#include <Arduino.h>

Servo servo[NUM_SERVOS];
int servoCal[NUM_SERVOS]  = {0,0,0,0,0,0,0,0};
int servoPos[NUM_SERVOS]  = {90,90,90,90,90,90,90,90};

// --------------------------------------------------
// Servo Initialization
// --------------------------------------------------
void initServos(const int servoPins[NUM_SERVOS]) {
    for (int i = 0; i < NUM_SERVOS; i++) {
        servo[i].attach(servoPins[i]);
        delay(30);
        servo[i].write(90 + servoCal[i]);
    }
}

void neutralStand() {
    for (int i = 0; i < NUM_SERVOS; i++) {
        servo[i].write(90 + servoCal[i]);
    }
}

// --------------------------------------------------
// Servo Program Runner
// --------------------------------------------------
inline void runServoPrg(const int servoPrg[][ACE], int step) {

  for(int i=0;i<step;i++){
    int totalTime = pgm_read_word(&servoPrg[i][ACE-1]);

    for(int s=0;s<NUM_SERVOS;s++)
      servoPos[s] = servo[s].read() - servoCal[s];

    for(int t=0;t<totalTime/SERVO_PERIOD;t++){
      for(int k=0;k<NUM_SERVOS;k++){
        int target = pgm_read_word(&servoPrg[i][k]);
        servo[k].write(
            map(t,0,totalTime/SERVO_PERIOD,servoPos[k],target)
            + servoCal[k]
        );
      }
      delay(SERVO_PERIOD);
    }
  }
}

// --------------------------------------------------
// Movement wrappers
// --------------------------------------------------
void walkForward()   { runServoPrg(servoPrg02, servoPrg02step); }
void walkBackward()  { runServoPrg(servoPrg03, servoPrg03step); }
void rotateLeft()    { runServoPrg(servoPrg06, servoPrg06step); }
void rotateRight()   { runServoPrg(servoPrg07, servoPrg07step); }
void lieDownPose()   { runServoPrg(servoPrg08, servoPrg08step); }
void sayHiMotion()   { runServoPrg(servoPrg09, servoPrg09step); }
void fightMotion()   { runServoPrg(servoPrg10, servoPrg10step); }
void pushUpMotion()  { runServoPrg(servoPrg11, servoPrg11step); }
void danceMove1()    { runServoPrg(servoPrg13, servoPrg13step); }
void danceMove2()    { runServoPrg(servoPrg14, servoPrg14step); }
