/*
  Arquivo responsável por conter as funções do sensor GUVA-S12SD
*/


// Pino do sensor de UV
int pinoSensorUV = A3;

// Variável que armazena o nível ultravioleta de acordo com a tabela
int nivelUV;


/**
 * @brief Função responsável por iniciar o sensor ultravioleta
 * 
*/
void iniciarSensorUV() {
  pinMode(pinoSensorUV, INPUT);
}

/**
 * @brief Função responsável por ler o nível ultravioleta
 * 
*/
void lerSensorUV(){
  
  // Guarda na variável a leitura do sensor
  float valorSensorUV = analogRead(pinoSensorUV);
  
  // Pega o valor recebido pelo pino do sensor e armazena na variavel
  // definindo o nivel de acordo com a tabela de indice UV
  if (valorSensorUV <= 10) {nivelUV = 0;} 
  else if (valorSensorUV > 10   && valorSensorUV <=  46) {nivelUV = 1;} 
  else if (valorSensorUV > 46   && valorSensorUV <=  65) {nivelUV = 2;} 
  else if (valorSensorUV > 65   && valorSensorUV <=  83) {nivelUV = 3;} 
  else if (valorSensorUV > 83   && valorSensorUV <= 103) {nivelUV = 4;} 
  else if (valorSensorUV > 103  && valorSensorUV <= 124) {nivelUV = 5;} 
  else if (valorSensorUV > 124  && valorSensorUV <= 142) {nivelUV = 6;} 
  else if (valorSensorUV > 142  && valorSensorUV <= 162) {nivelUV = 7;} 
  else if (valorSensorUV > 162  && valorSensorUV <= 180) {nivelUV = 8;} 
  else if (valorSensorUV > 180  && valorSensorUV <= 200) {nivelUV = 9;} 
  else if (valorSensorUV > 200  && valorSensorUV <= 221) {nivelUV = 10;}
  else {nivelUV = 11;}

  
  Serial.println("************************************");
  Serial.println("Leitura do sensor: " + (String) valorSensorUV);
  Serial.println("Índice UV: "         + (String) nivelUV);
  Serial.println("************************************");
}