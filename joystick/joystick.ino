/*Modulo Joystick KY-
  Pin SW 0=> conectar con resitencia pullup 10K

  Practica con 5 LEDs que se enciende segun posicion del Joystick
*/

int X;
int Y;
int SW;
/*int x_reposo = 480;
int y_reposo = 520;*/

#define PIN_LED_LEFT   10
#define PIN_LED_RIGHT 5
#define PIN_LED_UP 6
#define PIN_LED_DOWN 9
#define PIN_LED_BUTTON 3

#define PIN_SW_JOYSTICK 11
#define PIN_VRx A0
#define PIN_VRy A1

void setup() {
  Serial.begin(9600);
  delay(10);

  pinMode(PIN_LED_LEFT, OUTPUT);
  pinMode(PIN_LED_RIGHT, OUTPUT);
  pinMode(PIN_LED_UP, OUTPUT);
  pinMode(PIN_LED_DOWN, OUTPUT);
  pinMode(PIN_LED_BUTTON, OUTPUT);
}

void loop() {
  X = analogRead(PIN_VRx);
  Y = analogRead(PIN_VRy);
  SW = digitalRead(PIN_SW_JOYSTICK);
  /*Serial.print("X: ");
    Serial.println(X);
    Serial.print("Y: ");
    Serial.println(Y);
    delay(500);*/

  if (X >= 0 && X < 480) {
    digitalWrite(PIN_LED_LEFT, map(X, 0, 480, 255, 0)); /*orden invertivo. 0 esta mas a la izquierda, es decir el LED debe tener brillo máximo por eso invertimos orden de 255, 0*/
  } else {
    digitalWrite(PIN_LED_LEFT, LOW);
  }

  if (X >= 520 && X < 1023) {
    digitalWrite(PIN_LED_RIGHT, map(X, 520, 1023, 0, 255));
  } else {
    digitalWrite(PIN_LED_RIGHT, LOW);
  }

  if (Y >= 0 && Y < 480) {
    digitalWrite(PIN_LED_UP, map(Y, 0, 480, 255, 0));
  } else {
    digitalWrite(PIN_LED_UP, LOW);
  }

  if (Y >= 520 && Y < 1023) {
    digitalWrite(PIN_LED_DOWN, map(Y, 520, 1023, 0, 255));
  } else {
    digitalWrite(PIN_LED_DOWN, LOW);
  }

  digitalWrite(PIN_LED_BUTTON, !SW);
  
}
