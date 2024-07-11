#include <IRremoteESP8266.h>
#include <IRsend.h>

const uint16_t kIrLed = 4;  // GPIO utilisé pour l'émetteur IR

IRsend irsend(kIrLed);

void setup() {
  Serial.begin(115200);
  irsend.begin();
}

void loop() {
  // Hexadécimal à envoyer
  unsigned long data = 0xABC;  // Remplacez par votre code hexadécimal

  // Envoyer le signal IR
  irsend.sendNEC(data, 32);  // Envoi du code NEC (32 bits)

  Serial.println("Signal IR envoyé");
  delay(5000);  // Pause de 5 secondes entre les envois
}