
const byte MAIN_LED = 6;
const byte MAIN_BUTTON = 3;
const byte DATA_BUTTON = 2;
const int DATA_LED = A2;

boolean mainLedLast = LOW;
boolean mainLedCurrent = LOW;
boolean mainLedOn = false;

boolean dataLedLast = LOW;
boolean dataLedCurrent = LOW;
boolean dataLedOn = false;

typedef void (*ButtonPressHandler) (void);


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin MAIN_LED as an output.
  pinMode(MAIN_LED, OUTPUT);
  pinMode(MAIN_BUTTON, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  checkButton(MAIN_BUTTON, mainLedLast,mainLedCurrent, setMainLed);
  checkButton(DATA_BUTTON, dataLedLast, dataLedCurrent,setDataLed);
}

void setMainLed(){
  digitalWrite(MAIN_LED, mainLedCurrent); 
}

void setDataLed(){
  if (dataLedCurrent){
    analogWrite(DATA_LED, 255);
    }
    else{
      analogWrite(DATA_LED, 0);
    }
}

void checkButton(int BUTTON,  bool &last, bool &current, ButtonPressHandler handler ){
  current = debounce(last, BUTTON);              // Read debounced state
  if (last == LOW && current == HIGH)    // If it was pressed…
  {
     handler();                                 // Toggle the LED value
  }
  last = current;                        // Reset button value
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
