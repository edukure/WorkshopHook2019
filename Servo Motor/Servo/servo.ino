/* WORKSHOP HOOK 2019 
 * Como mover um servo motor de 0º a 180º e depois de 180º a 0º com steps de 1º
 */


#include <Servo.h>

//Declaração de um Servo Motor
Servo servo;

//ângulo inicial
int angle = 90;

void setup() {
  servo.attach(9);
  servo.write(angle);
}

void loop() 
{  
  // De 0º a 180º com step de 1º
  for(angle = 0; angle < 180; angle++)  
  {                                  
    servo.write(angle);               
    delay(15);                   
  }
  // De 180º a 0º com step de 1º
  for(angle = 180; angle > 0; angle--)    
  {                                
    servo.write(angle);           
    delay(15);       
  } 
}
