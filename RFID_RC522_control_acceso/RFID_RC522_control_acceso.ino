#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

byte LecturaUID[4];
byte Usuario1[4] = {0x32, 0xD2, 0x80, 0xCB};  //  Tarjeta UID: 32 D2 80 CB

void setup() {
  Serial.begin(9600);
  while (!Serial);

  SPI.begin();

  mfrc522.PCD_Init();
  delay(4);
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  Serial.print("UID: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);

    LecturaUID[i] = mfrc522.uid.uidByte[i];    
  }
  Serial.print("\t");
  if (comparaUID(LecturaUID, Usuario1)) {
    Serial.println("Bienvenido Usuario 1");
  } else {
    Serial.println("Acceso Denegado");
  }
  mfrc522.PICC_HaltA();
}

boolean comparaUID(byte lectura[], byte usuario[]) {
  for (byte i = 0; i < mfrc522.uid.size; i++ ) {
    if (lectura[i] != usuario[i]) {
      return false;
    }
    return true;
  }
}
