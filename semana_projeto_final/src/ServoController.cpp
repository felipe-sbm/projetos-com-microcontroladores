/*
 * ============================================================================
 *  Projeto      : Controle da Mão Robótica
 *  Arquivo      : ServoController.cpp
 *  Autor        : Felipe SBM
 *  Criado em    : 10 de novembro de 2026
 *  Descrição    : Implementação do controlador de servos da mão robótica.
 *
 *  Copyright (c) 2026 Felipe Samuel.
 *  Todos os direitos reservados.
 * ============================================================================
 */

#include "ServoController.h"

static const int PIN_POLEGAR = 13;
static const int PIN_INDICADOR = 12;
static const int PIN_MEDIO = 14;
static const int PIN_ANELAR = 27;
static const int PIN_MINDINHO = 26;
static const int PIN_PULSO = 25;

/**
 * @brief Inicializa os servos e define a pose inicial com a mão fechada.
 */
void ServoController::begin()
{
    servoPolegar.attach(PIN_POLEGAR);
    servoIndicador.attach(PIN_INDICADOR);
    servoMedio.attach(PIN_MEDIO);
    servoAnelar.attach(PIN_ANELAR);
    servoMindinho.attach(PIN_MINDINHO);
    servoPulso.attach(PIN_PULSO);

    setPose(0, 0, 0, 0, 0, 0);
}

/**
 * @brief Define a pose dos servos da mão.
 * @param polegar Ângulo do servo do polegar.
 * @param indicador Ângulo do servo do indicador.
 * @param medio Ângulo do servo do dedo médio.
 * @param anelar Ângulo do servo do anelar.
 * @param mindinho Ângulo do servo do mindinho.
 * @param pulso Ângulo do servo do pulso.
 */
void ServoController::setPose(int polegar, int indicador, int medio, int anelar, int mindinho, int pulso)
{
    servoPolegar.write(polegar);
    servoIndicador.write(indicador);
    servoMedio.write(medio);
    servoAnelar.write(anelar);
    servoMindinho.write(mindinho);
    servoPulso.write(pulso);
}
