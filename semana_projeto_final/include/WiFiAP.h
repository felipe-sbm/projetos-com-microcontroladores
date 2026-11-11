/*
 * ============================================================================
 *  Projeto      : Controle da Mão Robótica
 *  Arquivo      : WiFiAP.h
 *  Autor        : Felipe SBM
 *  Criado em    : 09 de novembro de 2026
 *  Descrição    : Arquivo de cabeçalho do ponto de acesso Wi-Fi do ESP32.
 *
 *  Copyright (c) 2026 Felipe Samuel.
 *  Todos os direitos reservados.
 * ============================================================================
 */

#pragma once

#include <WiFi.h>

class WiFiAP {
public:
    /**
     * @brief Inicializa o ponto de acesso Wi-Fi.
     */
    void begin();

    /**
     * @brief Retorna o endereço IP do ponto de acesso.
     * @return Endereço IP atual.
     */
    IPAddress ip() const { return WiFi.softAPIP(); }

    static const char* SSID;
    static const char* PASSWORD;
};
