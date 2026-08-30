int const TAM = 500;

void setup() {
    pinMode(7, OUTPUT);
    pinMode(1, OUTPUT);
}

void loop() {
    for (int i = TAM; i > 0; i -=50) {
        digitalWrite(1, LOW);
        digitalWrite(7, HIGH);
        delay(i);

        digitalWrite(1, HIGH);
        digitalWrite(7, LOW);
        delay(i);
    }
}