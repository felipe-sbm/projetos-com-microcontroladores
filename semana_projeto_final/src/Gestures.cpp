/*
 * ============================================================================
 *  Projeto      : Controle da Mão Robótica
 *  Arquivo      : Gestures.cpp
 *  Autor        : Felipe SBM
 *  Criado em    : 10 de novembro de 2026
 *  Descrição    : Implementação dos gestos da mão robótica.
 *
 *  Copyright (c) 2026 Felipe Samuel.
 *  Todos os direitos reservados.
 * ============================================================================
 */

#include "Gestures.h"

/**
 * @brief Construtor da classe Gestures.
 * @param s Referência ao controlador de servos.
 */
Gestures::Gestures(ServoController &s) : servo(s) {}

/**
 * @brief Fecha a mão.
 */
void Gestures::closeHand() { servo.setPose(0, 0, 0, 0, 0, 0); }

/**
 * @brief Abre a mão.
 */
void Gestures::openHand() { servo.setPose(180, 180, 180, 180, 180, 0); }

/**
 * @brief Executa o gesto rock and roll.
 */
void Gestures::rockAndRoll() { servo.setPose(0, 180, 0, 0, 180, 0); }

/**
 * @brief Executa o gesto hang loose.
 */
void Gestures::hangLoose() { servo.setPose(180, 0, 0, 0, 180, 0); }

/**
 * @brief Executa o gesto de paz e amor.
 */
void Gestures::peace() { servo.setPose(0, 180, 180, 0, 0, 0); }

/**
 * @brief Executa o gesto de joinha.
 */
void Gestures::thumbsUp() { servo.setPose(180, 0, 0, 0, 0, 0); }

/**
 * @brief Executa o gesto fazendo o L.
 */
void Gestures::makeL() { servo.setPose(180, 180, 0, 0, 0, 0); }

/**
 * @brief Executa o gesto de acenar.
 */
void Gestures::wave()
{
    openHand();
    for (int i = 0; i < 3; i++)
    {
        servo.setPose(180, 180, 180, 180, 180, 0);
        delay(400);
        servo.setPose(180, 180, 180, 180, 180, 180);
        delay(400);
    }
    closeHand();
}

/**
 * @brief Executa um gesto a partir do nome informado.
 * @param name Nome do gesto solicitado.
 * @return Verdadeiro se o gesto foi executado com sucesso.
 */
bool Gestures::perform(const String &name)
{
    if (name == "close")
    {
        closeHand();
        return true;
    }
    if (name == "open")
    {
        openHand();
        return true;
    }
    if (name == "rock")
    {
        rockAndRoll();
        return true;
    }
    if (name == "loose")
    {
        hangLoose();
        return true;
    }
    if (name == "peace")
    {
        peace();
        return true;
    }
    if (name == "thumbs")
    {
        thumbsUp();
        return true;
    }
    if (name == "l")
    {
        makeL();
        return true;
    }
    if (name == "wave")
    {
        wave();
        return true;
    }
    return false;
}
