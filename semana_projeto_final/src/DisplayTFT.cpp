/*
 * ============================================================================
 *  Projeto      : Controle da Mão Robótica
 *  Arquivo      : DisplayTFT.cpp
 *  Autor        : Felipe SBM
 *  Criado em    : 10 de novembro de 2026
 *  Descrição    : Implementação do módulo de display TFT.
 *
 *  Copyright (c) 2026 Felipe Samuel.
 *  Todos os direitos reservados.
 * ============================================================================
 */

#include "DisplayTFT.h"

#include <qrcode.h>

/**
 * @brief Inicializa o display TFT.
 */
void DisplayTFT::begin()
{
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_WHITE);
    tft.setTextColor(TFT_BLACK, TFT_WHITE);
}

/**
 * @brief Exibe o QR Code de conexão Wi-Fi e as informações de acesso.
 * @param ssid Nome da rede Wi-Fi.
 * @param password Senha da rede Wi-Fi.
 * @param url Endereço de acesso ao servidor web.
 */
void DisplayTFT::showWifiQR(const char *ssid, const char *password, const char *url)
{
    char payload[256];
    snprintf(payload, sizeof(payload), "WIFI:T:WPA;S:%s;P:%s;;", ssid, password);

    QRCode qrcode;
    uint8_t qrcodeData[qrcode_getBufferSize(7)];
    qrcode_initText(&qrcode, qrcodeData, 7, ECC_LOW, payload);

    tft.fillScreen(TFT_WHITE);

    const int scale = 4;
    const int qrPixels = qrcode.size * scale;
    const int startX = (tft.width() - qrPixels) / 2;
    const int startY = 10;

    for (int y = 0; y < qrcode.size; y++)
    {
        for (int x = 0; x < qrcode.size; x++)
        {
            uint16_t color = qrcode_getModule(&qrcode, x, y) ? TFT_BLACK : TFT_WHITE;
            tft.fillRect(startX + x * scale, startY + y * scale, scale, scale, color);
        }
    }

    int textY = startY + qrPixels + 12;
    tft.setTextDatum(TC_DATUM);
    tft.drawString("Escaneie para conectar ao Wi-Fi", tft.width() / 2, textY, 2);
    textY += 18;
    tft.drawString("Rede: Power Ranger Rosa - IoT", tft.width() / 2, textY, 2);
    textY += 18;
    tft.drawString("Acesse: http://192.168.4.1", tft.width() / 2, textY, 2);
}
