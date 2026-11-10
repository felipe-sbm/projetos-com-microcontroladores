/*
 * ============================================================================
 *  Project      : Robotic Hand Control
 *  File         : final_project.c
 *  Author       : Felipe SBM
 *  Created      : 09 November 2026
 *  Description  : Creates a robotic hand controlled by servos, allowing for individual finger movements and wrist rotation.
 *
 *  Copyright (c) 2026 Felipe Samuel.
 *  All rights reserved.
 * ============================================================================
 */

#include <Servo.h>

Servo servo_polegar;
Servo servo_indicador;
Servo servo_medio;
Servo servo_anelar;
Servo servo_mindinho;
Servo servo_pulso;

void setup()
{
    servo_pulso.attach(7);          // Pino de controle do servo do pulso
    servo_polegar.attach(2);        // //   // //       // //    // polegar
    servo_indicador.attach(3);      // //   // //       // //    // indicador
    servo_medio.attach(4);          // //   // //       // //    // médio
    servo_anelar.attach(5);         // //   // //       // //    // anelar
    servo_mindinho.attach(6);       // //   // //       // //    // mindinho

    // Inicializa os servos na posição inicial
    servo_pulso.write(0);
    servo_polegar.write(0);
    servo_indicador.write(0);
    servo_medio.write(0);
    servo_anelar.write(0);
    servo_mindinho.write(0);
}

void loop()
{
    fechar_mao();
    delay(2000);
    abrir_mao();
    delay(2000);
    rock_and_roll();
    delay(2000);
    hang_loose();
    delay(2000);
    paz_e_amor();
    delay(2000);
    joinha();
    delay(2000);
    fazendo_o_l();
    delay(2000);
    acenando();
    delay(2000);
}

void fechar_mao()
{
    servo_polegar.write(0);
    servo_indicador.write(0);
    servo_medio.write(0);
    servo_anelar.write(0);
    servo_mindinho.write(0);
}

void abrir_mao()
{
    servo_polegar.write(180);
    servo_indicador.write(180);
    servo_medio.write(180);
    servo_anelar.write(180);
    servo_mindinho.write(180);
}

void rock_and_roll()
{
    servo_polegar.write(0);
    servo_indicador.write(180);
    servo_medio.write(0);
    servo_anelar.write(0);
    servo_mindinho.write(180);
}

void hang_loose()
{
    servo_polegar.write(180);
    servo_indicador.write(0);
    servo_medio.write(0);
    servo_anelar.write(0);
    servo_mindinho.write(180);
}

void paz_e_amor()
{
    servo_polegar.write(0);
    servo_indicador.write(180);
    servo_medio.write(180);
    servo_anelar.write(0);
    servo_mindinho.write(0);
}

void joinha()
{
    servo_polegar.write(180);
    servo_indicador.write(0);
    servo_medio.write(0);
    servo_anelar.write(0);
    servo_mindinho.write(0);
}

void fazendo_o_l()
{
    servo_polegar.write(180);
    servo_indicador.write(180);
    servo_medio.write(0);
    servo_anelar.write(0);
    servo_mindinho.write(0);
}

void acenando()
{
    abrir_mao();
    for (int i = 0; i < 3; i++)
    {
        servo_pulso.write(0);
        delay(500);

        servo_pulso.write(180);
        delay(500);
    }
    fechar_mao();
}