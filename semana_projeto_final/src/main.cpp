/*
 * ============================================================================
 *  Projeto      : Controle da Mão Robótica
 *  Arquivo      : main.cpp
 *  Autor        : Felipe SBM
 *  Criado em    : 10 de novembro de 2026
 *  Descrição    : Ponto de entrada da aplicação da mão robótica.
 *
 *  Copyright (c) 2026 Felipe Samuel.
 *  Todos os direitos reservados.
 * ============================================================================
 */

#include <Arduino.h>

#include "ServoController.h"
#include "Gestures.h"
#include "WiFiAP.h"
#include "WebServerManager.h"
#include "DisplayTFT.h"

ServoController servoController;
Gestures gestures(servoController);
WiFiAP wifiAP;
WebServerManager webServer(gestures);
DisplayTFT display;

/**
 * @brief Configura o sistema e inicializa os módulos.
 */
void setup()
{
    Serial.begin(115200);
    delay(1000);

    servoController.begin();
    wifiAP.begin();
    display.begin();
    display.showWifiQR(WiFiAP::SSID, WiFiAP::PASSWORD, "http://192.168.4.1");
    webServer.begin();

    Serial.println("Sistema pronto.");
    Serial.print("Conecte-se ao Wi-Fi '");
    Serial.print(WiFiAP::SSID);
    Serial.println("' e acesse http://192.168.4.1");
}

/**
 * @brief Executa o laço principal do sistema.
 */
void loop()
{
    webServer.handleClient();
}
