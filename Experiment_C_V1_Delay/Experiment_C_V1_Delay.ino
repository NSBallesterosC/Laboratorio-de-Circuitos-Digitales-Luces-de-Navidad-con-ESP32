
const int leds = 18;
const int button = 4;

int counter = 0;

void setup() {
  Serial.begin(115200);

  pinMode(button, INPUT);
  pinMode(leds, OUTPUT);

  Serial.println("VERSION 1 - DELAY");
  Serial.println("Counter: 0");
}

void loop() {
  bool reading = digitalRead(button);

  if (reading)
  {
    counter++;
    Serial.println(counter);
  }

  digitalWrite(leds, HIGH);
  delay(250);
  digitalWrite(leds, LOW);
  delay(250);
}
