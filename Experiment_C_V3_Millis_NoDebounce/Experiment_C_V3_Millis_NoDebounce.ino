const int led = 18;
const int boton = 4;

int estadoAnterior = LOW;
int contador = 0;
bool estadoLED = LOW;

unsigned long tiempoAnterior = 0;
const unsigned long intervalo = 500;

void setup() {
  Serial.begin(115200);

  pinMode(led, OUTPUT);
  pinMode(boton, INPUT);

  Serial.println("VERSION 3 - MILLIS SIN ANTIRREBOTE");
  Serial.println("Contador: 0");
}

void loop() {
  unsigned long ahora = millis();

  // Parpadeo del LED cada 500 ms
  if (ahora - tiempoAnterior >= intervalo) {
    tiempoAnterior = ahora;

    estadoLED = !estadoLED;
    digitalWrite(led, estadoLED);
  }

  // Lectura del botón
  int lectura = digitalRead(boton);

  if (lectura == HIGH && estadoAnterior == LOW) {
    contador++;
    Serial.println(contador);
  }

  estadoAnterior = lectura;
}
