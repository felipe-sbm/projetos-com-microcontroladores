/*
 * ============================================================================
 *  Projeto      : Controle da Mão Robótica
 *  Arquivo      : WebPage.h
 *  Autor        : Felipe SBM
 *  Criado em    : 09 de novembro de 2026
 *  Descrição    : Arquivo de cabeçalho da página web servida pelo ESP32.
 *
 *  Copyright (c) 2026 Felipe Samuel.
 *  Todos os direitos reservados.
 * ============================================================================
 */

#pragma once

#include <Arduino.h>

class WebPage {
public:
    /**
     * @brief Retorna o HTML da página web.
     * @return Conteúdo HTML da interface.
     */
    static String html();
};
