#include <Servo.h>

Servo myServo;
#define PIN_SERVO 2
#define PULSO_MIN 700 /*Probar con el servo en la mano si se nota vibración para ir ajustando los valoress min y máx del pulso.*/
#define PULSO_MAX 2350

#define POT 0
int valuePOT;

void setup() {
  myServo.attach(PIN_SERVO, PULSO_MIN, PULSO_MAX);
}

void loop() {
  myServo.write(0);
  delay(5000);
  myServo.write(180);
  delay(5000);
}
