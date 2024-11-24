#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

const byte botaoQuarto = 2;
const byte ledQuarto = 8;
byte valorBotaoQuarto;
byte valorBotaoQuartoAnterior;
boolean ledQuartoLigado = true;

const byte botaoSala = 3;
const byte ledSala = 9;
byte valorBotaoSala;
byte valorBotaoSalaAnterior;
boolean ledSalaLigado = true;

const byte botaoBanheiro = 4;
const byte ledBanheiro = 10;
byte valorBotaoBanheiro;
byte valorBotaoBanheiroAnterior;
boolean ledBanheiroLigado = true;

const byte botaoCozinha = 5;
const byte ledCozinha = 11;
byte valorBotaoCozinha;
byte valorBotaoCozinhaAnterior;
boolean ledCozinhaLigado = true;

void setup() {
  lcd.init();
  lcd.setBacklight(HIGH);

  pinMode(botaoQuarto, INPUT_PULLUP);
  pinMode(ledQuarto, OUTPUT);

  pinMode(botaoSala, INPUT_PULLUP);
  pinMode(ledSala, OUTPUT);

  pinMode(botaoBanheiro, INPUT_PULLUP);
  pinMode(ledBanheiro, OUTPUT);

  pinMode(botaoCozinha, INPUT_PULLUP);
  pinMode(ledCozinha, OUTPUT);
}

void loop() {
  // Verificar se o estado do botão foi alterado e fazer debounce
  valorBotaoQuarto = digitalRead(botaoQuarto);
  if (valorBotaoQuarto != valorBotaoQuartoAnterior) {
    if (valorBotaoQuarto == LOW) { // Detecta pressionamento do botão
      ledQuartoLigado = !ledQuartoLigado;
      digitalWrite(ledQuarto, ledQuartoLigado);
      atualizarLCD(0, "Luz quarto", ledQuartoLigado);
    }
    valorBotaoQuartoAnterior = valorBotaoQuarto;
    delay(200); // Delay de debounce
  }

  valorBotaoSala = digitalRead(botaoSala);
  if (valorBotaoSala != valorBotaoSalaAnterior) {
    if (valorBotaoSala == LOW) {
      ledSalaLigado = !ledSalaLigado;
      digitalWrite(ledSala, ledSalaLigado);
      atualizarLCD(1, "Luz sala", ledSalaLigado);
    }
    valorBotaoSalaAnterior = valorBotaoSala;
    delay(200); // Delay de debounce
  }

  valorBotaoBanheiro = digitalRead(botaoBanheiro);
  if (valorBotaoBanheiro != valorBotaoBanheiroAnterior) {
    if (valorBotaoBanheiro == LOW) {
      ledBanheiroLigado = !ledBanheiroLigado;
      digitalWrite(ledBanheiro, ledBanheiroLigado);
      atualizarLCD(2, "Luz banheiro", ledBanheiroLigado);
    }
    valorBotaoBanheiroAnterior = valorBotaoBanheiro;
    delay(200); // Delay de debounce
  }

  valorBotaoCozinha = digitalRead(botaoCozinha);
  if (valorBotaoCozinha != valorBotaoCozinhaAnterior) {
    if (valorBotaoCozinha == LOW) {
      ledCozinhaLigado = !ledCozinhaLigado;
      digitalWrite(ledCozinha, ledCozinhaLigado);
      atualizarLCD(3, "Luz cozinha", ledCozinhaLigado);
    }
    valorBotaoCozinhaAnterior = valorBotaoCozinha;
    delay(200); // Delay de debounce
  }
}

// Função para atualizar o LCD com a mensagem de estado de cada luz
void atualizarLCD(int linha, String ambiente, boolean estado) {
  lcd.setCursor(0, linha);   // Volta para o início da linha
  if (estado) {
    lcd.print(ambiente + " acesa");
  } else {
    lcd.print("                    ");
  }
}
