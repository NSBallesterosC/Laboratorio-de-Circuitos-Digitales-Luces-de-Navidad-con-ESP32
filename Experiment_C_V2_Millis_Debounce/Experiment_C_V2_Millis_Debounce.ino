
const int led = 18;
const int button = 4;

int buttonState = LOW;
int lastReading = LOW;
int counter = 0;

bool ledState = LOW;

unsigned long previousTime = 0;
unsigned long debounceTime = 0;

const unsigned long interval = 500;
const unsigned long debounce = 50;

void setup() {
  Serial.begin(115200);

  pinMode(led, OUTPUT);
  pinMode(button, INPUT);

  Serial.println("VERSION 2 - MILLIS WITH DEBOUNCE");
  Serial.println("Counter: 0");
}

void loop() {

  unsigned long now = millis();

  // LED blinking control
  if (now - previousTime >= interval) {

    previousTime = now;

    ledState = !ledState;

    digitalWrite(led, ledState);
  }

  // Button reading
  int reading = digitalRead(button);

  if (reading != lastReading) {
    debounceTime = now;
  }

  if (now - debounceTime >= debounce) {

    if (reading != buttonState) {

      buttonState = reading;

      if (buttonState == HIGH) {
        counter++;
        Serial.println(counter);
      }
    }
  }

  lastReading = reading;
}
