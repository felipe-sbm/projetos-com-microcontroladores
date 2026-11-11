/*
 * ============================================================================
 *  Projeto      : Controle da Mão Robótica
 *  Arquivo      : WebPage.cpp
 *  Autor        : Felipe SBM
 *  Criado em    : 10 de novembro de 2026
 *  Descrição    : Implementação da página web servida pelo ESP32.
 *
 *  Copyright (c) 2026 Felipe Samuel.
 *  Todos os direitos reservados.
 * ============================================================================
 */

#include "WebPage.h"

/**
 * @brief Retorna o HTML da página web.
 * @return Conteúdo HTML da interface.
 */
String WebPage::html()
{
  return R"rawliteral(
<!DOCTYPE html>
<html lang="pt-BR">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Power Ranger Rosa — IoT</title>
<style>
  * { box-sizing: border-box; }
  body {
    margin: 0;
    min-height: 100vh;
    background: #FF1493;
    font-family: "Segoe UI Emoji", "Apple Color Emoji", sans-serif;
    display: flex;
    flex-direction: column;
    align-items: center;
    padding: 24px 16px;
  }
  h1 {
    color: #ffffff;
    text-shadow: 0 3px 6px rgba(0,0,0,0.35);
    margin-bottom: 24px;
    font-size: 1.6rem;
    text-align: center;
  }
  .grid {
    display: grid;
    grid-template-columns: repeat(2, 1fr);
    gap: 18px;
    width: 100%;
    max-width: 420px;
  }
  .btn {
    background: #ffffff;
    border: none;
    border-radius: 18px;
    aspect-ratio: 1 / 1;
    font-size: 72px;
    line-height: 1;
    cursor: pointer;
    display: flex;
    align-items: center;
    justify-content: center;
    box-shadow: 0 8px 16px rgba(0,0,0,0.25);
    transition: transform 0.12s ease, box-shadow 0.12s ease;
    text-decoration: none;
    color: #000;
  }
  .btn:active {
    transform: scale(0.92);
    box-shadow: 0 4px 8px rgba(0,0,0,0.2);
  }
  .status {
    margin-top: 20px;
    color: #fff;
    font-size: 1rem;
    min-height: 1.2em;
  }
</style>
</head>
<body>
  <h1>Power Ranger Rosa — IoT</h1>
  <div class="grid">
    <button class="btn" onclick="send('close')" aria-label="Fechar mao">✊</button>
    <button class="btn" onclick="send('open')" aria-label="Abrir mao">✋</button>
    <button class="btn" onclick="send('rock')" aria-label="Rock and roll">🤘</button>
    <button class="btn" onclick="send('loose')" aria-label="Hang loose">🤙</button>
    <button class="btn" onclick="send('peace')" aria-label="Paz e amor">✌️</button>
    <button class="btn" onclick="send('thumbs')" aria-label="Joinha">👍</button>
    <button class="btn" onclick="send('l')" aria-label="Fazendo o L">🤟</button>
    <button class="btn" onclick="send('wave')" aria-label="Acenando">👋</button>
  </div>
  <div class="status" id="status"></div>
<script>
function send(name) {
  const st = document.getElementById('status');
  st.textContent = 'Enviando...';
  fetch('/g?name=' + encodeURIComponent(name))
    .then(r => { st.textContent = r.ok ? 'Gesto executado!' : 'Erro'; })
    .catch(() => { st.textContent = 'Sem conexao'; });
}
</script>
</body>
</html>
)rawliteral";
}
