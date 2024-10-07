//Jika ingin menggunaka ini diharapkan disaat double klik tidak terlalu cepat

#include <ShsykaaPushButton.h>

// Pin untuk push button dan LED
const int buttonPin = 2;
const int ledPin = 4; // Ganti dengan pin LED yang sesuai

// Inisialisasi ShsykaaPushButton
ShsykaaPushButton button(buttonPin);

void setup() {
  Serial.begin(9600);
  
  // Set pin LED sebagai output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Update status tombol
  button.update();

  // Cek apakah tombol ditekan
  if (button.isPressed()) {
    digitalWrite(ledPin, HIGH); // Nyalakan LED saat tombol ditekan
  } else {
    digitalWrite(ledPin, LOW); // Matikan LED saat tombol dilepas
  }

  // Cek apakah single click terdeteksi
  if (button.isClick()) {
    Serial.println("Single Click Detected");
  }

  // Cek apakah double click terdeteksi
  if (button.isDoubleClick()) {
    Serial.println("Double Click Detected");
  }

  // Cek apakah long press terdeteksi
  if (button.isLongPress()) {
    Serial.println("Long Press Detected");
  }

  // Tunggu sebentar sebelum memeriksa kembali untuk menghindari pembacaan yang berlebihan
  delay(50);
}
