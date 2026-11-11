/*
 * ============================================================================
 *  Projeto      : Controle da Mão Robótica
 *  Arquivo      : WebServerManager.h
 *  Autor        : Felipe SBM
 *  Criado em    : 09 de novembro de 2026
 *  Descrição    : Arquivo de cabeçalho do gerenciador do servidor web.
 *
 *  Copyright (c) 2026 Felipe Samuel.
 *  Todos os direitos reservados.
 * ============================================================================
 */

#pragma once

#include <WebServer.h>
#include "Gestures.h"
#include "WebPage.h"

class WebServerManager {
public:
    /**
     * @brief Construtor da classe WebServerManager.
     * @param gestures Referência ao gerenciador de gestos.
     */
    explicit WebServerManager(Gestures& gestures);

    /**
     * @brief Inicializa o servidor HTTP.
     */
    void begin();

    /**
     * @brief Processa as requisições do cliente.
     */
    void handleClient();

private:
    WebServer server;
    Gestures& gestures;

    /**
     * @brief Envia a página inicial.
     */
    void handleRoot();

    /**
     * @brief Processa a requisição de execução de gesto.
     */
    void handleGesture();

    /**
     * @brief Trata rotas não encontradas.
     */
    void handleNotFound();
};
