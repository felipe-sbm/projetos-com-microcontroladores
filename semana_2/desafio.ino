int estado = 0;

void setup() {
    pinMode(13, OUTPUT);
    pinMode(A0, INPUT_PULLUP);
}

void loop() {
    switch (estado) {
        case 0:
            digitalWrite(13, LOW);

            if (digitalRead(A0) == 0) {
                estado = 1;
                digitalWrite(13, HIGH);
                delay(100);
            }
        break;

        case 1:
            if (digitalRead(A0) == 1) {
                estado = 2;
                digitalWrite(13, HIGH);
            }
        break;

        case 2:
            if (digitalRead(A0) == 0) {
                estado = 3;
                digitalWrite(13, LOW);
            }
        break;

        case 3:
            if (digitalRead(A0) == 1) {
                estado = 0;
                digitalWrite(13, LOW);
            }
        break;


    }
}