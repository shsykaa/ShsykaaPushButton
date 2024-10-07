#include <ShsykaaPushButton.h>

// Pin untuk push button
const int buttonPin = 2;

// Inisialisasi ShsykaaPushButton
ShsykaaPushButton button(buttonPin);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Update status tombol
  button.update();

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
}
