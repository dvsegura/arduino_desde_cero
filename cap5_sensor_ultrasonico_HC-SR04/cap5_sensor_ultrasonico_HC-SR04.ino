#define PIN_TRIG 10
#define PIN_ECHO 9
#define PIN_LED 3

int duracion;
int distancia;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  digitalWrite(PIN_TRIG, HIGH);
  delay(1);
  digitalWrite(PIN_TRIG, LOW);
  duracion = pulseIn(PIN_TRIG, HIGH);
  distancia = duracion / 58.2;
  Serial.println(distancia); // valor negativo indica que el sensor esta fuera de rango
  delay(200);
  if(distancia <= 20 && distancia >= 0){
      digitalWrite(PIN_LED,HIGH);
      delay(distancia * 10);
      digitalWrite(PIN_LED,LOW);
    }
  ;
}
