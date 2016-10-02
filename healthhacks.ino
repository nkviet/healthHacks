/* YourDuino.com Example Software Sketch
   Small Stepper Motor and Driver V1.4 11/30/2013
   http://arduino-direct.com/sunshop/index.php?l=product_detail&p=126
   Steps one revolution of output shaft, then back
   terry@yourduino.com */

/*-----( Import needed libraries )-----*/
#include <Stepper.h>

/*-----( Declare Variables )-----*/
int  Steps2Take;
const int motorRev = 32;
const int outputRev = 2048;
boolean reader = false;

//The pin connections need to be 4 pins connected
// to Motor Driver In1, In2, In3, In4  and then the pins entered
// here in the sequence 1-3-2-4 for proper sequencing
Stepper sstepper(motorRev, 8, 10, 9, 11);

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
}/*--(end setup )---*/

void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  int degree;
  degree= analogRead(A0);
  int val;
  val = degree*300/1023;
  Serial.println(val);
  if(val>=60&&val<=150)
  {
    Steps2Take  =  outputRev ;  // Rotate CW 1 turn
    sstepper.setSpeed(500);   
    sstepper.step(Steps2Take);
    //delay(1000);
    
    Steps2Take  =  - outputRev;  // Rotate CCW 1 turn  
    sstepper.setSpeed(500);  // 700 a good max speed??
    sstepper.step(Steps2Take);
    //delay(2000);
  }
}
