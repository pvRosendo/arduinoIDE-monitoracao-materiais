/*
  Arquivo responsável por contar as funções dos sensores DHT
    
*/

#include <Adafruit_Sensor.h>                       // Biblioteca DHT Sensor Adafruit 
#include <DHT.h>
#include <DHT_U.h>


// Define os tipos dos sensores - para trocar de sensor basta apenas colocar DHT11
#define DHTTYPE1     DHT22
#define DHTTYPE2     DHT22
#define DHTTYPE3     DHT22

// Definição dos pinos que serão utilizados para os sensores
#define DHTPIN1 2
#define DHTPIN2 3
#define DHTPIN3 4

// Instanciando os objetos e configurando os sensores com o pino e o tipo
DHT dht1(DHTPIN1, DHTTYPE1);
DHT dht2(DHTPIN2, DHTTYPE2);
DHT dht3(DHTPIN3, DHTTYPE3);

// Instanciando os objetos para recolher as informações básicas
DHT_Unified informacoesDHT1(DHTPIN1, DHTTYPE1);
DHT_Unified informacoesDHT2(DHTPIN2, DHTTYPE2);
DHT_Unified informacoesDHT3(DHTPIN3, DHTTYPE3);

// Instanciando os tipos dos sensores
sensor_t sensor1;
sensor_t sensor2;
sensor_t sensor3;


void iniciarSensoresDHT(){
  dht1.begin();
  dht2.begin();
  dht3.begin();
}


/**
* @brief Função responsável por imprimir as informações básicas
* @param sensor Objeto sensor_t que armazena as informações básicas do sensor
*/
void imprimirConfiguracoesBasicas(sensor_t sensor, int numeroSensor) {

  // Coleta e imprime as informações básicas de temperatura do sensor
  informacoesDHT1.temperature().getSensor(&sensor);
  informacoesDHT2.temperature().getSensor(&sensor);
  informacoesDHT3.temperature().getSensor(&sensor);

  // Coleta e imprime as informações básicas de umidade do sensor
  informacoesDHT1.humidity().getSensor(&sensor);
  informacoesDHT2.humidity().getSensor(&sensor);
  informacoesDHT3.humidity().getSensor(&sensor);


  // Imprime as informações básicas de temperatura do sensor
  Serial.println("----------- Sensor Número " + (String) numeroSensor + "-----------");
  Serial.println("Temperatura");
  Serial.print  ("Tipo do Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Valor max:            "); Serial.print(sensor.max_value);   Serial.println("*C");
  Serial.print  ("Valor min:            "); Serial.print(sensor.min_value);   Serial.println("*C");
  Serial.print  ("Resolucao:            "); Serial.print(sensor.resolution);  Serial.println("*C");

  // Imprime as informações básicas de umidade do sensor
  Serial.println("------------------------------------");
  Serial.println("Umidade");
  Serial.print  ("Tipo do Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Valor max:            "); Serial.print(sensor.max_value);   Serial.println("%");
  Serial.print  ("Valor min:            "); Serial.print(sensor.min_value);   Serial.println("%");
  Serial.print  ("Resolucao:            "); Serial.print(sensor.resolution);  Serial.println("%");
  Serial.println("");

}


void leituraSensor(DHT dht, int numeroSensor){

  // Fazendo a leitura dos valores  
  float umidade = dht.readHumidity();
  float temperaturaCelsius = dht.readTemperature();
  float temperaturaFahrenheit = dht.readTemperature(true);

  // Verifica se os valores estão nulos ou se tem algum problema com os atributos
  if (isnan(umidade) || isnan(temperaturaCelsius) || isnan(temperaturaFahrenheit)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Computando o indice de aquecimento para cada temperatura
  float indiceAquecimentoFahrenheit = dht.computeHeatIndex(temperaturaFahrenheit, umidade);
  float indiceAquecimentoCelsius = dht.computeHeatIndex(temperaturaCelsius, umidade, false);

  Serial.println("Sensor: " + String(numeroSensor));
  Serial.println("---------------------------------");

  Serial.print(F("Humidity: "));
  Serial.print(umidade);

  Serial.print(F("%  Temperature: "));
  Serial.print(temperaturaCelsius);
  Serial.print(F("°C "));

  Serial.print(temperaturaFahrenheit);
  Serial.print(F("°F  Heat index: "));

  Serial.print(indiceAquecimentoCelsius);
  Serial.print(F("°C "));

  Serial.print(indiceAquecimentoFahrenheit);
  Serial.println(F("°F"));

  Serial.print("-------------------------------------");

}