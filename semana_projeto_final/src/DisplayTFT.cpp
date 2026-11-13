#include "DisplayTFT.h"
#include "bg_image.h"

#include <qrcode.h>

static const unsigned long SCREEN_INTERVAL = 7000;

void DisplayTFT::begin()
{
    tft.init();
    tft.setRotation(1); // paisagem: 320x240
    tft.fillScreen(TFT_RED);
    delay(800);
    tft.fillScreen(TFT_WHITE);
    tft.setTextColor(TFT_BLACK, TFT_WHITE);

    ssidBuf[0] = '\0';
    passBuf[0] = '\0';
    urlBuf[0] = '\0';

    lastSwitch = millis();
    screenState = 0;
}

void DisplayTFT::showWifiQR(const char *ssid, const char *password, const char *url)
{
    strncpy(ssidBuf, ssid, sizeof(ssidBuf) - 1);
    ssidBuf[sizeof(ssidBuf) - 1] = '\0';
    strncpy(passBuf, password, sizeof(passBuf) - 1);
    passBuf[sizeof(passBuf) - 1] = '\0';
    strncpy(urlBuf, url, sizeof(urlBuf) - 1);
    urlBuf[sizeof(urlBuf) - 1] = '\0';

    lastSwitch = millis();
    screenState = 0;
    showWifiScreen();
}

void DisplayTFT::update()
{
    unsigned long now = millis();
    if (now - lastSwitch < SCREEN_INTERVAL)
    {
        return;
    }
    lastSwitch = now;
    if (screenState == 0)
    {
        screenState = 1;
        showUrlScreen();
    }
    else if (screenState == 1)
    {
        screenState = 2;
        showBackground();
    }
    else
    {
        screenState = 0;
        showWifiScreen();
    }
}

void DisplayTFT::drawQR()
{
    char payload[256];
    snprintf(payload, sizeof(payload), "WIFI:T:WPA;S:%s;P:%s;;", ssidBuf, passBuf);

    QRCode qrcode;
    uint8_t qrcodeData[qrcode_getBufferSize(7)];
    qrcode_initText(&qrcode, qrcodeData, 7, ECC_LOW, payload);

    const int scale = 4;
    const int qrPixels = qrcode.size * scale;
    const int startX = (tft.width() - qrPixels) / 2;
    const int startY = 10;

    // fundo branco
    tft.fillRect(startX, startY, qrPixels, qrPixels, TFT_WHITE);

    for (int y = 0; y < qrcode.size; y++)
    {
        for (int x = 0; x < qrcode.size; x++)
        {
            uint16_t color = qrcode_getModule(&qrcode, x, y) ? TFT_BLACK : TFT_WHITE;
            tft.fillRect(startX + x * scale, startY + y * scale, scale, scale, color);
        }
    }
}

void DisplayTFT::showWifiScreen()
{
    tft.fillScreen(TFT_WHITE);
    drawQR();

    int textY = 10 + 4 * 37 + 12; // aproximado
    // recalcula com tamanho real do QR (versao 7 -> 45 modulos)
    int qrPixels = 45 * 4;
    textY = 10 + qrPixels + 12;

    tft.setTextDatum(TC_DATUM);
    tft.drawString("Escaneie para conectar ao Wi-Fi.", tft.width() / 2, textY, 2);
    textY += 18;
    tft.drawString("Rede: Power Ranger Rosa - IoT", tft.width() / 2, textY, 2);
}

void DisplayTFT::showUrlScreen()
{
    tft.fillScreen(TFT_WHITE);
    drawQR();

    int qrPixels = 45 * 4;
    int textY = 10 + qrPixels + 12;

    tft.setTextDatum(TC_DATUM);
    tft.drawString("Para fazer os gestos na mão robótica,", tft.width() / 2, textY, 2);
    textY += 18;
    tft.drawString("acesse: http://192.168.4.1", tft.width() / 2, textY, 2);
}

void DisplayTFT::showBackground()
{
    tft.setSwapBytes(true);
    tft.pushImage(0, 0, BG_IMG_WIDTH, BG_IMG_HEIGHT, bgImage);
    tft.setSwapBytes(false);
}