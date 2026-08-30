void setup() {
    pinMode(7, OUTPUT);
    pinMode(1, OUTPUT);
}

void loop() {
    digitalWrite(1, LOW);
    digitalWrite(7, HIGH);
    delay(1000);

    digitalWrite(7, LOW);
    digitalWrite(1, HIGH);
    delay(1000);
}