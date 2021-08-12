
const byte MAIN_LED = 6;
const byte MAIN_BUTTON = 3;
boolean mainLedLast = LOW;
boolean mainLedCurrent = LOW;
boolean mainLedOn = false;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin MAIN_LED as an output.
  pinMode(MAIN_LED, OUTPUT);
  pinMode(MAIN_BUTTON, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  checkButton(MAIN_LED, MAIN_BUTTON, mainLedLast, mainLedCurrent,mainLedOn);
}

void checkButton(int LED, int BUTTON,  bool &last,bool &current, bool &ledOn ){
  current = debounce(last, BUTTON);              // Read debounced state
  if (last == LOW && current == HIGH)    // If it was pressed…
  {
    ledOn = !ledOn;                                  // Toggle the LED value
  }
  last = current;                        // Reset button value
  
  digitalWrite(LED, ledOn);                          // Change the LED state
}

boolean debounce(boolean last,int BUTTON)
{
  boolean current = digitalRead(BUTTON);       // Read the button state
  if (last != current)                         // If it's different…
  {
    delay(5);                                  // Wait 5ms
    current = digitalRead(BUTTON);             // Read it again
  }
  return current;                              // Return the current value
}
