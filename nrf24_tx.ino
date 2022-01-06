/*  Author - Prem Kumar R
 *  Written at E-Mobility LAB in 2021
 *  CHRIST(Deemed To Be University)
 *  email - premraja671@gmail.com
 */


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00009";
void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
  const char text[] = "Antenna OK";
  radio.write(&text, sizeof(text));
  delay(1000);
}
