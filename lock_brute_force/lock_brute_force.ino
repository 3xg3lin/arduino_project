#include <Keyboard.h>

void setup() {
  // Initialize the Keyboard
  Keyboard.begin();
  delay(1000);  // Give the system time to recognize the device

  // Start sending PIN combinations from 1111 to 1234
  for (int pin = 1111; pin <= 1234; pin++) {
    enterPin(pin);
    delay(5000);  // Wait 5 seconds before trying the next PIN (to simulate a wait)
  }

  Keyboard.end();
}

void loop() {
  // Nothing to do in the loop
}

void enterPin(int pin) {
  String pinString = String(pin);  // Convert the pin number to a string
  for (int i = 0; i < pinString.length(); i++) {
    Keyboard.press(pinString[i]);  // Press each number
    delay(200);                    // Small delay between each keypress
    Keyboard.releaseAll();
  }
  
  // Press Enter (or equivalent action) to submit the PIN
  Keyboard.press(KEY_RETURN);
  delay(200);
  Keyboard.releaseAll();
}