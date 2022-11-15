/*
  Etradas/Salidas con LED y Pulsador
*/

#define pulsador 2
#define led 3

void setup() {
  Serial.begin(9600);
  pinMode(pulsador, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  if (digitalRead(pulsador) == HIGH) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
