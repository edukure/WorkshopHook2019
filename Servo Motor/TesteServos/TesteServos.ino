//zoomkat 7-30-10 serial servo test
//type servo position 0 to 180 in serial monitor

/* Conecte o servo motor no pino 9
 * Abra o monitor serial e coloque na velocidade 9600
 * Digite o valor do ângulo (0º a 180º)
 * Utilize este código para verificar os limites
 * de angulação dos servos motores em cada parte da garra
 */

String readString;
#include <Servo.h>
Servo myservo;  // create servo object to control a servo

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  Serial.println("servo-test");
}

void loop() {

  while (Serial.available()) {
    char c = Serial.read();  //gets one byte from serial buffer
    readString += c; //makes the String readString
    delay(2);  //slow looping to allow buffer to fill with next character
  }

  if (readString.length() >0) {
    Serial.println(readString);  //so you can see the captured String
    int n = readString.toInt();  //convert readString into a number
    Serial.println(n); //so you can see the integer
    myservo.write(n);
    readString="";
  }
}
