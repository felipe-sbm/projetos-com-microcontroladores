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

private:
    TFT_eSPI tft;
};
