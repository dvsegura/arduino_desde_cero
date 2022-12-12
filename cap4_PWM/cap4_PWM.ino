#define LED = 3
#define POT = A0
int brillo;

void setup() {
  pinMode(LED, OUTPUT);
  //las entradas analógicas no necesitan inicialización
}

void loop() {
  brillo = analogRead(POT)/4;  // dividir por 4 para garantizar un valor menor de 255. Mejro usar función map(brillo,0,1023,0,255)
  digitalWrite(LED,brillo);
}
