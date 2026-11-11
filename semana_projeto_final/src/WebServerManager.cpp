/*
 * ============================================================================
 *  Projeto      : Controle da Mão Robótica
 *  Arquivo      : WebServerManager.cpp
 *  Autor        : Felipe SBM
 *  Criado em    : 10 de novembro de 2026
 *  Descrição    : Implementação do gerenciador do servidor web.
 *
 *  Copyright (c) 2026 Felipe Samuel.
 *  Todos os direitos reservados.
 * ============================================================================
 */

#include "WebServerManager.h"

/**
 * @brief Construtor da classe WebServerManager.
 * @param g Referência ao gerenciador de gestos.
 */
WebServerManager::WebServerManager(Gestures &g) : server(80), gestures(g) {}

/**
 * @brief Inicializa o servidor HTTP.
 */
void WebServerManager::begin()
{
    server.on("/", HTTP_GET, [this]()
              { handleRoot(); });
    server.on("/g", HTTP_GET, [this]()
              { handleGesture(); });
    server.onNotFound([this]()
                      { handleNotFound(); });
    server.begin();
    Serial.println("Servidor HTTP iniciado na porta 80");
}

/**
 * @brief Processa as requisições do cliente.
 */
void WebServerManager::handleClient()
{
    server.handleClient();
}

/**
 * @brief Envia a página inicial.
 */
void WebServerManager::handleRoot()
{
    server.send(200, "text/html; charset=utf-8", WebPage::html());
}

/**
 * @brief Processa a requisição de execução de gesto.
 */
void WebServerManager::handleGesture()
{
    if (!server.hasArg("name"))
    {
        server.send(400, "text/plain", "parametro 'name' ausente");
        return;
    }
    String name = server.arg("name");
    bool ok = gestures.perform(name);
    if (ok)
    {
        server.send(200, "text/plain", "ok");
    }
    else
    {
        server.send(404, "text/plain", "gesto desconhecido");
    }
}

/**
 * @brief Trata rotas não encontradas.
 */
void WebServerManager::handleNotFound()
{
    server.send(404, "text/plain", "nao encontrado");
}
