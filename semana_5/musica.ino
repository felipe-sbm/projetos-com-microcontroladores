/**
  FÜR ELISE - BEETHOVEN

    Feita na aula de Projetos com Microcontroladores;
    Local: Escola de Ciências & Tecnologia;
    Lecionada por:  Marcelo Borges Nogueira;
    Desenvolvido por:   Felipe Samuel;
    Arranjo de: um relógio que meu irmão tinha quando criança,
                que tinha essa mesma melodia, neste mesmo arranjo,
                me deu uma grande nostalgia quando estava desenvolvendo
                (esse relógio era da revista da AVON).


    Obrigado aos meus amigo Davi e Fernando que me acompanharam no desenvolvimento.
**/

#define NOTA_C4  262
#define NOTA_E4  330
#define NOTA_F4  349
#define NOTA_G4  392
#define NOTA_GS4 415
#define NOTA_A4  440
#define NOTA_B4  494
#define NOTA_C5  523
#define NOTA_D5  587
#define NOTA_DS5 622
#define NOTA_E5  659
#define NOTA_F5  698
#define PAUSA      0

// Poco moto, que é 80 BPM
int andamento = 80;

// Pino que o alto-falante está
int pino_alto_falante = 8;

const int musica[] PROGMEM = {
  // O compasso é 3/8
  // notas da composição
  //
  // 4  = semínima
  // 8  = colcheia
  // 16 = semicolcheia
  // -8 = colcheia pontuada

  // === SEÇÃO A ===
  // Compasso 1
  NOTA_E5,  16,
  NOTA_DS5, 16,

  // Compasso 2
  NOTA_E5,  16,
  NOTA_DS5, 16,
  NOTA_E5,  16,
  NOTA_B4,  16,
  NOTA_D5,  16,
  NOTA_C5,  16,

  // Compasso 3
  NOTA_A4,  -8,
  NOTA_C4,  16,
  NOTA_E4,  16,
  NOTA_A4,  16,

  // Compasso 4
  NOTA_B4,  -8,
  NOTA_E4,  16,
  NOTA_GS4, 16,
  NOTA_B4,  16,

  // Compasso 5
  NOTA_C5,   8,
  PAUSA,    16,
  NOTA_E4,  16,
  NOTA_E5,  16,
  NOTA_DS5, 16,

  // Compasso 6
  NOTA_E5,  16,
  NOTA_DS5, 16,
  NOTA_E5,  16,
  NOTA_B4,  16,
  NOTA_D5,  16,
  NOTA_C5,  16,

  // Compasso 7
  NOTA_A4,  -8,
  NOTA_C4,  16,
  NOTA_E4,  16,
  NOTA_A4,  16,

  // Compasso 8
  NOTA_B4,   8,
  PAUSA,    16,
  NOTA_E4,  16,
  NOTA_C5,  16,
  NOTA_B4,  16,

  // Compasso 9
  NOTA_A4,   8,
  PAUSA,    16,
  NOTA_B4,  16,
  NOTA_C5,  16,
  NOTA_D5,  16,

  // === SEÇÃO B ===
  // Compasso 10
  NOTA_E5,  -8,
  NOTA_G4,  16,
  NOTA_F5,  16,
  NOTA_E5,  16,

  // Compasso 11
  NOTA_D5,  -8,
  NOTA_F4,  16,
  NOTA_E5,  16,
  NOTA_D5,  16,

  // Compasso 12
  NOTA_C5,  -8,
  NOTA_E4,  16,
  NOTA_D5,  16,
  NOTA_C5,  16,

  // Compasso 13
  NOTA_B4,   8,
  PAUSA,    16,
  NOTA_E4,  16,
  NOTA_E5,  16,
  NOTA_DS5, 16,

  // Compasso 14
  NOTA_E5,  16,
  NOTA_DS5, 16,
  NOTA_E5,  16,
  NOTA_B4,  16,
  NOTA_D5,  16,
  NOTA_C5,  16,

  // Compasso 15
  NOTA_A4,   8,
  PAUSA,    16,
  NOTA_C4,  16,
  NOTA_E4,  16,
  NOTA_A4,  16,

  // Compasso 16
  NOTA_B4,   8,
  PAUSA,    16,
  NOTA_E4,  16,
  NOTA_C5,  16,
  NOTA_B4,  16,

  // Compasso 17
  NOTA_A4,    8
};

// Número de notas
int numero_notas = sizeof(musica) / sizeof(musica[0]) / 2;

// Duração de uma semibreve em ms
int duracao_semibreve = (60000 * 4) / andamento;

int divisor = 0;
int duracao_nota = 0;

void setup() {

  for (int indice_nota = 0; indice_nota < numero_notas * 2; indice_nota += 2) {

    // Lê a duração
    divisor = pgm_read_word_near(musica + indice_nota + 1);

    if (divisor > 0) {

      // Nota normal
      duracao_nota = duracao_semibreve / divisor;

    } else if (divisor < 0) {

      // Nota pontuada
      duracao_nota = duracao_semibreve / abs(divisor);
      duracao_nota *= 1.5;
    }

    // Toca a nota por 90% da duração
    tone(
      pino_alto_falante,
      pgm_read_word_near(musica + indice_nota),
      duracao_nota * 0.9
    );

    // Espera a duração completa
    delay(duracao_nota);

    // Para antes da próxima nota
    noTone(pino_alto_falante);
  }
}

void loop() {
  // Não repete

  // Seria bom ter um botão que repete a música,
  // fica como uma correção futura.
}