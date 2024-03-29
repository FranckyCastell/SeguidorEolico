//#include <Servo.h>
#include <ESP32Servo.h>
#define __DEBUG__

// OBJETOS SERVO
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  // Inicializar cada servomotor en su respectivo pin
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
}

void loop() {
  // Mover los servomotores de 0 a 180 grados
  for (int pos = 0; pos <= 180; pos++) {
    servo1.write(pos);
    servo2.write(pos);
    servo3.write(pos);
    servo4.write(pos);
    delay(15); 
  }

  // Mover los servomotores de 180 a 0 grados
  for (int pos = 180; pos >= 0; pos--) {
    servo1.write(pos);
    servo2.write(pos);
    servo3.write(pos);
    servo4.write(pos);
    delay(15);
  }
}
