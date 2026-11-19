
const int buttonPin = 4;

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);

  delay(2000);

  Serial.println("\n--- STARTING EXPERIMENT A (20 READINGS) ---");
  Serial.println("Taking readings...");

  int highCount = 0;

  for (int i = 1; i <= 20; i++) {
    int reading = digitalRead(buttonPin);

    if (reading == HIGH) {
      highCount++;
    }

    Serial.print("Reading ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(reading);

    delay(100);
  }

  Serial.println("-----------------------------------------");
  Serial.print("RESULT: Out of 20 readings, ");
  Serial.print(highCount);
  Serial.println(" were 1 (HIGH).");
  Serial.println("-----------------------------------------");
}

// Runs only once after reset, so the loop is empty.

void loop() {

}
