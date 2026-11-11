/*
 * ============================================================================
 *  Projeto      : Controle da Mão Robótica
 *  Arquivo      : ServoController.h
 *  Autor        : Felipe SBM
 *  Criado em    : 09 de novembro de 2026
 *  Descrição    : Arquivo de cabeçalho do módulo de controle dos servos da mão robótica.
 *
 *  Copyright (c) 2026 Felipe Samuel.
 *  Todos os direitos reservados.
 * ============================================================================
 */

#pragma once

#include <ESP32Servo.h>

class ServoController {
public:
    /**
     * @brief Inicializa os servos nos pinos configurados.
     */
    void begin();

    /**
     * @brief Define a pose dos servos da mão.
     * @param polegar Ângulo do servo do polegar.
     * @param indicador Ângulo do servo do indicador.
     * @param medio Ângulo do servo do dedo médio.
     * @param anelar Ângulo do servo do anelar.
     * @param mindinho Ângulo do servo do mindinho.
     * @param pulso Ângulo do servo do pulso.
     */
    void setPose(int polegar, int indicador, int medio, int anelar, int mindinho, int pulso);

private:
    Servo servoPolegar;
    Servo servoIndicador;
    Servo servoMedio;
    Servo servoAnelar;
    Servo servoMindinho;
    Servo servoPulso;
};
