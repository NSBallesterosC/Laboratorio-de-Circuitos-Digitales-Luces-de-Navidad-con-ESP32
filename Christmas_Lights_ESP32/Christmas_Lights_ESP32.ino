
 // E0: All LEDs off
// E1: Blinking every 500 ms
// E2: Running lights from left to right every 150 ms
// E3: Alternating even and odd LEDs every 300 ms
// E4: Back and forth

// ---------- Variable declaration ----------

int PreviousState = LOW;
int PulseCounts = 0;

unsigned long PreviousAnimationTime = 0;
int SequenceState = 0;

const int LEDs[] = { 18, 19, 21, 22, 23 };
const int Total = 5;

const int ControlChange = 4;

// Timing variables
unsigned long LastBounceTime = 0;
const unsigned long DebounceTime = 50;

int directionE4 = 1;


void setup() {

  Serial.begin(115200);

  for (int i = 0; i < Total; i++) {
    pinMode(LEDs[i], OUTPUT);
  }
  pinMode(ControlChange, INPUT);

  Serial.println("Current state: E0 - All LEDs off");
  TurnOffLEDs();
}

void loop() {

  int ButtonState = digitalRead(ControlChange);

  // Rising edge detection with debounce
  if (ButtonState == HIGH && PreviousState == LOW) {
    if ((millis() - LastBounceTime) > DebounceTime) {
      PulseCounts++;
      if (PulseCounts > 4) {
        PulseCounts = 0;
      }

      // Reset variables when changing states
      SequenceState = 0;
      PreviousAnimationTime = millis();
      directionE4 = 1;
      TurnOffLEDs();
      PrintStates(PulseCounts);

      LastBounceTime = millis();
    }
  }
  PreviousState = ButtonState;

  switch (PulseCounts) {

    case 0 : TurnOffLEDs();
    break;

    case 1 : if ((millis() - PreviousAnimationTime) >= 500) {
      PreviousAnimationTime = millis();
      SequenceState = !SequenceState;
    }
    if (SequenceState == 1) {
      TurnOnLEDs();
    } else {
      TurnOffLEDs();
    }
    break;

    case 2 : if ((millis() - PreviousAnimationTime) >= 150) {
      PreviousAnimationTime = millis();

      for (int i = 0; i < Total; i++) {
        if (i == SequenceState) {
          digitalWrite(LEDs[i], HIGH);
        } else {
          digitalWrite(LEDs[i], LOW);
        }
      }

      SequenceState++;
      if (SequenceState >= Total) {
        SequenceState = 0;
      }
    }
    break;

    case 3 : if ((millis() - PreviousAnimationTime) >= 300) {
      PreviousAnimationTime = millis();
      SequenceState = !SequenceState;
    }
    for (int i = 0; i < Total; i++) {
      if ((i % 2 == 0) == SequenceState) {
        digitalWrite(LEDs[i], HIGH);
      } else {
        digitalWrite(LEDs[i], LOW);
      }
    }
    break;

    case 4: if ((millis() - PreviousAnimationTime) >= 80) {
      PreviousAnimationTime = millis();

      for (int i = 0; i < Total; i++) {
        if (i == SequenceState) {
          digitalWrite(LEDs[i], HIGH);
        } else {
          digitalWrite(LEDs[i], LOW);
        }
      }

      SequenceState += directionE4;

      if (SequenceState == Total - 1 || SequenceState == 0) {
        directionE4 = -directionE4;
      }
    }
    break;
  }
}


// ---------- Functions ----------

void TurnOnLEDs() {
  for (int i = 0; i < Total; i++) {
    digitalWrite(LEDs[i], HIGH);
  }
}

void TurnOffLEDs() {
  for (int i = 0; i < Total; i++) {
    digitalWrite(LEDs[i], LOW);
  }
}

void PrintStates(int state) {
  switch (state) {
    case 0: Serial.println("Current state: E0 - All LEDs off"); break;
    case 1: Serial.println("Current state: E1 - Blinking"); break;
    case 2: Serial.println("Current state: E2 - Running lights"); break;
    case 3: Serial.println("Current state: E3 - Alternating"); break;
    case 4: Serial.println("Current state: E4 - Back and forth"); break;
  }
}
