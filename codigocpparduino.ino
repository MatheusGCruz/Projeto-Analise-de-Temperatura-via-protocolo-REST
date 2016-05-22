#include <SPI.h>
#include <Ethernet.h>
#include <DHT.h>
 
#define DHTPIN A1 // Pino conectado ao sinal do DHT11
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);



//16-03-87-22-11-90 ENDEREÇO MAC DA PLACA
byte mac[] = {0x16, 0x03, 0x87, 0x22, 0x11, 0x90};

//Endereço IP do Shield, último disponível para diminuir conflitos em redes domesticas
byte ip[] = {192,168,1,255};

//Porta de transmissão Telnet
EthernetServer server = EthernetServer(23);

void setup() {
  Serial.begin(9600);

  Ethernet.begin(mac,ip); // inicia o Shield Ethernet
  delay(1000);

  server.begin();
  if(server.available()){
    Serial.println("Raspberry Conectado");
  }
}

void loop() {
float t = dht.readTemperature();
EthernetClient client = server.available();
message = client.read();
server.write(t);
}

