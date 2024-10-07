#ifndef ShsykaaPushButton_h
#define ShsykaaPushButton_h

#include "Arduino.h"

class ShsykaaPushButton {
  public:
    // Constructor
    ShsykaaPushButton(int pin);

    // Fungsi untuk memperbarui status tombol
    void update();

    // Fungsi untuk mendeteksi klik
    bool isClick();
    bool isDoubleClick();
    bool isLongPress();
    
    // Fungsi untuk memeriksa apakah tombol sedang ditekan
    bool isPressed(); // Tambahkan deklarasi fungsi isPressed

  private:
    int _pin;                 // Pin untuk push button
    int _buttonState;         // Status tombol saat ini
    int _lastButtonState;     // Status tombol sebelumnya
    unsigned long _lastDebounceTime; // Waktu debounce terakhir
    unsigned long _debounceDelay;    // Delay debounce
    unsigned long _lastClickTime;    // Waktu klik terakhir
    unsigned long _doubleClickDelay; // Delay untuk double click
    unsigned long _longPressTime;    // Batas waktu untuk long press
    bool _clickDetected;             // Deteksi single click
    bool _doubleClickDetected;       // Deteksi double click
    bool _longPressDetected;         // Deteksi long press
    bool _longPressHandled;          // Penanganan long press
    bool _waitForDoubleClick;        // Flag menunggu double click
    bool _longPressActive;           // Flag long press aktif
};

#endif
