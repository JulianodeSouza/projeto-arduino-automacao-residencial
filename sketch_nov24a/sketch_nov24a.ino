#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

String inputSerial = "";

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

  Serial.begin(9600);

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

  if (Serial.available() > 0) {
    inputSerial = Serial.readString();
    Serial.print("O QUE ESCREVERAM " + inputSerial);


    if (inputSerial == "porta") {
      digitalWrite(ledQuarto, HIGH);
    } else if (inputSerial == "porta quebrada") {
      digitalWrite(ledQuarto, LOW);
    }

     if (inputSerial == "pasta") {
      digitalWrite(ledSala, HIGH);
    } else if (inputSerial == "pasta de amendoim") {
      digitalWrite(ledSala, LOW);
    }

     if (inputSerial == "lasanha") {
      digitalWrite(ledCozinha, HIGH);
    } else if (inputSerial == "lasanha queimada") {
      digitalWrite(ledCozinha, LOW);
    }

     if (inputSerial == "frutas") {
      digitalWrite(ledBanheiro, HIGH);
    } else if (inputSerial == "frutas estragada") {
      digitalWrite(ledBanheiro, LOW);
    }
  }

  valorBotaoQuarto = digitalRead(botaoQuarto);
  if (valorBotaoQuarto != valorBotaoQuartoAnterior) {
    if (valorBotaoQuarto) {
      ledQuartoLigado = !ledQuartoLigado;
      digitalWrite(ledQuarto, ledQuartoLigado);
    }
  }
  valorBotaoQuartoAnterior = valorBotaoQuarto;
  delay(10);

  valorBotaoSala = digitalRead(botaoSala);
  if (valorBotaoSala != valorBotaoSalaAnterior) {
    if (valorBotaoSala) {
      ledSalaLigado = !ledSalaLigado;
      digitalWrite(ledSala, ledSalaLigado);
    }
  }
  valorBotaoSalaAnterior = valorBotaoSala;
  delay(10);

  valorBotaoBanheiro = digitalRead(botaoBanheiro);
  if (valorBotaoBanheiro != valorBotaoBanheiroAnterior) {
    if (valorBotaoBanheiro) {
      ledBanheiroLigado = !ledBanheiroLigado;
      digitalWrite(ledBanheiro, ledBanheiroLigado);
    }
  }
  valorBotaoBanheiroAnterior = valorBotaoBanheiro;
  delay(10);

  valorBotaoCozinha = digitalRead(botaoCozinha);
  if (valorBotaoCozinha != valorBotaoCozinhaAnterior) {
    if (valorBotaoCozinha) {
      ledCozinhaLigado = !ledCozinhaLigado;
      digitalWrite(ledCozinha, ledCozinhaLigado);
    }
  }
  valorBotaoCozinhaAnterior = valorBotaoCozinha;
  delay(10);


  if (ledQuartoLigado == true) {
    lcd.setCursor(0, 0);
    lcd.print("Luz quarto acesa  ");
  } else if (ledQuartoLigado == false) {
    lcd.setCursor(0, 0);
    lcd.print("                    ");
  }

  if (ledSalaLigado == true) {
    lcd.setCursor(0, 1);
    lcd.print("Luz sala acesa  ");
  } else if (ledSalaLigado == false) {
    lcd.setCursor(0, 1);
    lcd.print("                    ");
  }

  if (ledBanheiroLigado == true) {
    lcd.setCursor(0, 2);
    lcd.print("Luz banheiro acesa  ");
  } else if (ledBanheiroLigado == false) {
    lcd.setCursor(0, 2);
    lcd.print("                    ");
  }

  if (ledCozinhaLigado == true) {
    lcd.setCursor(0, 3);
    lcd.print("Luz cozinha acesa  ");
  } else if (ledCozinhaLigado == false) {
    lcd.setCursor(0, 3);
    lcd.print("                    ");
  }
}
