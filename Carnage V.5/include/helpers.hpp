#include "main.h"



void setIntake(int intakePower);
void setlift(int liftpower);

//lift
extern ez::PID liftPID;
void liftWait();
void lift_task();
void init();
void CS_task();
extern bool isRed;
extern int IntakeSpeed;
