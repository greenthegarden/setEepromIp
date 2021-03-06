#include <Arduino.h>

#include <SPI.h>
#include <Ethernet.h>
#include <NetEEPROM.h>


byte mac[6] = { 0xCA, 0xFE, 0xBA, 0xBE, 0x00, 0x01 };


void setMac() {
  Serial.print("Setting mac address ...");
  NetEeprom.writeDhcpConfig(mac);
}

void setManualIpConfiguration() {
  // additional parameters
  byte ip[4] = { 192, 168, 1, 100 };
  byte dns[4] = { 8, 8, 8, 8 };
  byte gw[4] = { 192, 168, 1, 1 };
  byte subnet[4] = { 255, 255, 255, 0 };

  Serial.println("Configuring network settings ...");
  NetEeprom.writeManualConfig(mac, ip, dns, gw, subnet);
}

void testNetwork() {
  NetEeprom.begin();
  Serial.print("IP Address: ");
  Serial.println(Ethernet.localIP());
}

void setup() {
  // put your setup code here, to run once:
  setMac();
  testNetwork();
}

void loop() {
  // put your main code here, to run repeatedly:
}
