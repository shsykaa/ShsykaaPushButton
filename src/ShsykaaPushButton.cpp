#include "ShsykaaPushButton.h"

// Constructor
ShsykaaPushButton::ShsykaaPushButton(int pin) {
  _pin = pin;
  pinMode(_pin, INPUT_PULLUP);
  _buttonState = HIGH;
  _lastButtonState = HIGH;
  _lastDebounceTime = 0;
  _debounceDelay = 50;
  _lastClickTime = 0;
  _doubleClickDelay = 500;
  _longPressTime = 1000;
  _clickDetected = false;
  _doubleClickDetected = false;
  _longPressDetected = false;
  _longPressHandled = false;
  _waitForDoubleClick = false;
  _longPressActive = false;
}

// Fungsi update untuk memperbarui status tombol
void ShsykaaPushButton::update() {
  int reading = digitalRead(_pin);

  // Jika status tombol berubah, set waktu debounce
  if (reading != _lastButtonState) {
    _lastDebounceTime = millis();
  }

  // Jika debounce sudah melewati delay
  if ((millis() - _lastDebounceTime) > _debounceDelay) {
    if (reading != _buttonState) {
      _buttonState = reading;

      if (_buttonState == LOW) {
        if (_waitForDoubleClick && (millis() - _lastClickTime) < _doubleClickDelay) {
          _doubleClickDetected = true;
          _waitForDoubleClick = false;
        } else {
          _clickDetected = true;
          _waitForDoubleClick = true;
          _longPressActive = true;
        }
        _lastClickTime = millis();
      }
    }
  }

  // Deteksi long press
  if (_buttonState == LOW && (millis() - _lastClickTime) > _longPressTime && !_longPressHandled) {
    _longPressDetected = true;
    _longPressHandled = true;
    _waitForDoubleClick = false;
    _clickDetected = false;
    _longPressActive = false;
  }

  // Reset long press ketika tombol dilepas
  if (_buttonState == HIGH) {
    _longPressHandled = false;
    _longPressActive = false;
  }

  _lastButtonState = reading;
}

// Fungsi untuk mendeteksi single click
bool ShsykaaPushButton::isClick() {
  if (_clickDetected && !_longPressActive && (millis() - _lastClickTime) > _doubleClickDelay) {
    _clickDetected = false;
    _waitForDoubleClick = false;
    return true;
  }
  return false;
}

// Fungsi untuk mendeteksi double click
bool ShsykaaPushButton::isDoubleClick() {
  if (_doubleClickDetected) {
    _doubleClickDetected = false;
    return true;
  }
  return false;
}

// Fungsi untuk mendeteksi long press
bool ShsykaaPushButton::isLongPress() {
  if (_longPressDetected) {
    _longPressDetected = false;
    return true;
  }
  return false;
}

// Fungsi untuk memeriksa apakah tombol sedang ditekan
bool ShsykaaPushButton::isPressed() {
  return _buttonState == LOW; // Mengembalikan true jika tombol ditekan
}
