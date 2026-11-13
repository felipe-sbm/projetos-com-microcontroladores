/*
 * ============================================================================
 *  Projeto      : Controle da Mão Robótica
 *  Arquivo      : DisplayTFT.h
 *  Autor        : Felipe SBM
 *  Criado em    : 09 de novembro de 2026
 *  Descrição    : Arquivo de cabeçalho do módulo de display TFT.
 *
 *  Copyright (c) 2026 Felipe Samuel.
 *  Todos os direitos reservados.
 * ============================================================================
 */

#pragma once

#include <Arduino.h>
#include <TFT_eSPI.h>

class DisplayTFT {
public:
    /**
     * @brief Inicializa o display TFT.
     */
    void begin();

    /**
     * @brief Exibe o QR Code de conexão Wi-Fi e as informações de acesso.
     * @param ssid Nome da rede Wi-Fi.
     * @param password Senha da rede Wi-Fi.
     * @param url Endereço de acesso ao servidor web.
     */
    void showWifiQR(const char* ssid, const char* password, const char* url);
    void update();

private:
    TFT_eSPI tft;
    unsigned long lastSwitch = 0;
    uint8_t screenState = 0; // 0: wifi, 1: url, 2: background
    char ssidBuf[64];
    char passBuf[64];
    char urlBuf[128];

    void drawQR();
    void showWifiScreen();
    void showUrlScreen();
    void showBackground();
};
