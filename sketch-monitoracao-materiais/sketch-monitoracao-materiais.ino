/*
  Autor: Paulo Vitor Rosendo
  GitHub: https://github.com/pvRosendo/monitoracao-de-materiais
*/

#include "sensorDHT.h"
#include "sensorUV.h"

void setup(){

  // Inicia o Monitor Serial
  Serial.begin(9600);
  
  // Inicia o sensor ultravioleta
  iniciarSensorUV();

  // Inicia e imprime as configurações básicas dos sensores DHT
  iniciarSensoresDHT();
  imprimirConfiguracoesBasicas(sensor1, 1);
  imprimirConfiguracoesBasicas(sensor2, 2);
  imprimirConfiguracoesBasicas(sensor3, 3);

}


void loop(){

  // Intervalo de 2 segundos necessários para precisão dos sensores DHT
  delay(2000);

  // Realiza a leitura e impressão dos dados do sensor UV
  lerSensorUV();

  // Realiza a leitura e impressão dos dados dos sensores DHT
  leituraSensor(dht1, 1);
  leituraSensor(dht2, 2);
  leituraSensor(dht3, 3);

}
