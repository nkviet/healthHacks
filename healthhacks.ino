// import stepper library
#include <Stepper.h>

// variable declaration
int  Steps2Take;
const int motorRev = 32;
const int outputRev = 2048;
boolean reader = false;

//stepper motor object
Stepper sstepper(motorRev, 8, 10, 9, 11);
//Stepper sstepper(motorRev, 8, 10, 9, 11);

void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop()
{
  int degree;
  degree= analogRead(A0);
  int val;
  val = degree*300/1023;
  Serial.println(val);
  if(val>=60&&val<=150)
  {
    while(val<60||val>150)
    {
      break;
    }
      Steps2Take  =  outputRev ;  // Rotate Clockwise 1 turn
      sstepper.setSpeed(500);   
      sstepper.step(Steps2Take);
    //delay(1000);
    
    //Steps2Take  =  - outputRev;  // Rotate counterclockwise 1 turn  
    //sstepper.setSpeed(500);
    //sstepper.step(Steps2Take);
    //delay(2000);
  }
}
