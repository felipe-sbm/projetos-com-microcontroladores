/*
 * ============================================================================
 *  Projeto      : Controle da Mão Robótica
 *  Arquivo      : WiFiAP.cpp
 *  Autor        : Felipe SBM
 *  Criado em    : 10 de novembro de 2026
 *  Descrição    : Implementação do ponto de acesso Wi-Fi.
 *
 *  Copyright (c) 2026 Felipe Samuel.
 *  Todos os direitos reservados.
 * ============================================================================
 */

#include "WiFiAP.h"

const char *WiFiAP::SSID = "Power Ranger Rosa — IoT";
const char *WiFiAP::PASSWORD = "88888888";

/**
 * @brief Inicializa o ponto de acesso Wi-Fi.
 */
void WiFiAP::begin()
{
    WiFi.mode(WIFI_AP);
    WiFi.softAP(SSID, PASSWORD);
    Serial.print("AP IP: ");
    Serial.println(WiFi.softAPIP());
}
