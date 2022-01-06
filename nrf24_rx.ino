/* Author - Prem Kumar R
 *  Written at E-Mobility LAB in 2021
 *  CHRIST(Deemed To Be University)
 *  email - premraja671@gmail.com
 */


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00009";
const char test[] = "Antenna OK";
int led = 5;

void makesound() {
  analogWrite(led,255);
  delay(500);
  analogWrite(led,0);
  delay(500);
  Serial.println("equals");
}

void nosound() {
  analogWrite(led,0);
  Serial.println("Lost Link!!");
}

void setup() {
  Serial.begin(9600);
  radio.begin();
  pinMode(led,OUTPUT);
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  analogWrite(led,255);
  delay(500);
  analogWrite(led,0);
}
void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    if(strcmp(text,"Antenna OK")==0) {
      makesound();
      
    }
    else {
      analogWrite(led, 0);
    }
    Serial.println(text);
  }
  
    
}
