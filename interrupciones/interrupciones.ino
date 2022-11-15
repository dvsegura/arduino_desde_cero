/*
  Pines: 2,3 Arduino UNO
  Interruption Service Rutine(ISR) Rutinas de Servicio de Interrupción -> callback
  Estados:
    LOW
    RISING (LOW -> HIGH)
    FALLING (HIGH -> LOW)
    CHANGE (cambio de nivel)
    HIGH(No está disponible para todas las placas)

    Importante función ISR
    -> No devuelve ni recibe parámetros
    -> func.como millis, delay no funcionan
    -> no usar Serial.print
    -> Debe durar lo menos posible(contadores, flags).Estas variables deben tener el calificador "volatile"
*/
volatile int count = 0;  /* https://www.arduino.cc/reference/es/language/variables/variable-scope-qualifiers/volatile/  */
int count_before = 0;
void setup() {
  Serial.begin(9600);
  delay(10);
  pinMode(13, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), interrupt, FALLING);
}

void loop() {
  if (count_before != count) {
    Serial.print(count);
    count_before = count;
  }

  changeLED();
}

void interrupt() {
  count ++;
}

void changeLED() {
  digitalWrite(13, HIGH);
  delay(count);
  digitalWrite(13, LOW);
  if (count < 1000) {
    count = 1000;
  }
}
