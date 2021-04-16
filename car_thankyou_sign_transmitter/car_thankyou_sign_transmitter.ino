#include <Arduino.h>

#include <SPI.h>
#include <LoRa.h>

const int trig_btn = 10;
int data_to_send = 7;

int trig_btn_status = 0;

boolean development = false; // set this value to true during debugging and development to get serial output

void setup(){
  if(development){
   Serial.begin(9600);
  }
  pinMode(trig_btn, INPUT);

  while (!Serial)
    ;
  Serial.println("LoRa Sender");
  if (!LoRa.begin(433E6))
  {
    Serial.println("Starting LoRa failed!");
    while (1)
      ;
  }
}

void loop(){
  send_signal(); // sends wireless signal to the receiver 
}


void take_reading(){
  trig_btn_status = digitalRead(trig_btn);
  Serial.println(trig_btn_status);
}

void send_signal(){
  take_reading();
  if(trig_btn_status == 1){
      Serial.print("Sending packet: ");
      Serial.println(data_to_send);

      // send packet
      LoRa.beginPacket();
      //  LoRa.print("4");
      LoRa.print(data_to_send);
      LoRa.endPacket();
  }
}
