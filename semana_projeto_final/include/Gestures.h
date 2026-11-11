/*
 * ============================================================================
 *  Projeto      : Controle da Mão Robótica
 *  Arquivo      : Gestures.h
 *  Autor        : Felipe SBM
 *  Criado em    : 09 de novembro de 2026
 *  Descrição    : Arquivo de cabeçalho do módulo de gestos da mão robótica.
 *
 *  Copyright (c) 2026 Felipe Samuel.
 *  Todos os direitos reservados.
 * ============================================================================
 */

#pragma once

#include <Arduino.h>
#include "ServoController.h"

class Gestures {
public:
    /**
     * @brief Construtor da classe Gestures.
     * @param servo Referência ao controlador de servos.
     */
    explicit Gestures(ServoController& servo);

    /**
     * @brief Fecha a mão.
     */
    void closeHand();

    /**
     * @brief Abre a mão.
     */
    void openHand();

    /**
     * @brief Executa o gesto rock and roll.
     */
    void rockAndRoll();

    /**
     * @brief Executa o gesto hang loose.
     */
    void hangLoose();

    /**
     * @brief Executa o gesto de paz e amor.
     */
    void peace();

    /**
     * @brief Executa o gesto de joinha.
     */
    void thumbsUp();

    /**
     * @brief Executa o gesto fazendo o L.
     */
    void makeL();

    /**
     * @brief Executa o gesto de acenar.
     */
    void wave();

    /**
     * @brief Executa um gesto a partir do nome informado.
     * @param name Nome do gesto solicitado.
     * @return Verdadeiro se o gesto foi executado com sucesso.
     */
    bool perform(const String& name);

private:
    ServoController& servo;
};
