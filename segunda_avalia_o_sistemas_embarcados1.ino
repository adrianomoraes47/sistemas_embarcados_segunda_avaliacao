
#include <Servo.h> // Biblioteca do Servo

Servo meuservo;  // Objeto Servo

int val;         // Variável de leitura analógica do sensor

int pot = 0;     // Pino usado para conectar o sensor 

void setup() {
  meuservo.attach(9);  // Pino usado para conectar o servo
  Serial.begin(9600);  // Começamos a comunicação serial a uma taxa de transmissão de 9600.
  
}
void loop() {
  val = analogRead(pot);           // Lê o valor analógico do sensor (0 a 1023)
  
  float voltage = val * (5000 / 1024.0);
  
  float temperatura = (voltage - 500) / 10;
  
  Serial.print(temperatura);
  Serial.print(" \xC2\xB0"); // mostra o símbolo de grau
  Serial.println("C");
  delay(1000); // espere um segundo entre as leituras
  
  temperatura = map(temperatura, 0, 120, 0, 180);    // Transforma em um valor em graus 0º a 180º
  meuservo.write(temperatura);                // Comando que envia o sinal para o servo rotacionar
  delay(15);                          // Espera 15ms 
}