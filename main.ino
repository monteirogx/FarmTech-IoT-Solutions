#include "DHTesp.h"

// Definição dos pinos
const int PIN_DHT = 15;
const int PIN_N = 12;
const int PIN_P = 14;
const int PIN_K = 27;
const int PIN_LDR = 34;
const int PIN_RELE = 2;

DHTesp dhtSensor;

void setup() {
  Serial.begin(115200);
  dhtSensor.setup(PIN_DHT, DHTesp::DHT22);
  
  // Configura os botões
  pinMode(PIN_N, INPUT_PULLUP);
  pinMode(PIN_P, INPUT_PULLUP);
  pinMode(PIN_K, INPUT_PULLUP);
  
  // Configura o Relé
  pinMode(PIN_RELE, OUTPUT);
  digitalWrite(PIN_RELE, LOW); // Começa desligado
}

void loop() {
  // Lê umidade e temperatura
  TempAndHumidity data = dhtSensor.getTempAndHumidity();
  
  // Lê o LDR (pH simulado)
  int ldrValue = analogRead(PIN_LDR);
  float ph = map(ldrValue, 0, 4095, 0, 14); // Converte para escala 0-14

  // Lê os botões (NPK) - LOW significa que o botão está apertado
  bool temN = digitalRead(PIN_N) == LOW;
  bool temP = digitalRead(PIN_P) == LOW;
  bool temK = digitalRead(PIN_K) == LOW;

  // Exibe no Monitor Serial
  Serial.print("Umidade: "); Serial.print(data.humidity); Serial.print("% | ");
  Serial.print("pH: "); Serial.println(ph);

  // LÓGICA DE DECISÃO:
  // Se a umidade for baixa (menos de 40%) OU faltar algum nutriente com pH ruim
  if (data.humidity < 40 || (ph < 6.0 && (!temN || !temP || !temK))) {
    digitalWrite(PIN_RELE, HIGH); // Liga a bomba
    Serial.println(">>> IRRIGANDO...");
  } else {
    digitalWrite(PIN_RELE, LOW); // Desliga a bomba
  }

  delay(2000); // Espera 2 segundos para ler de novo
}