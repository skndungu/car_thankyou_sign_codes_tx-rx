  #include <Arduino.h>
  #include <FastLED.h>
  
  #include <SPI.h>
  #include <LoRa.h>
  
  
  #define NUM_LEDS 16 // defines the number of leds we have 
  #define DATA_PIN 10 // data pin on the MCU
  
  CRGB leds[NUM_LEDS];// Defines the array of led
  
  int data_recevied = 0; // reveived data from the transmitter
  boolean development = false; // set this value to true during debugging and development to get serial output
  
  void setup() { 
    if(development){
         Serial.begin(9600); 
    }
    
    FastLED.addLeds<SK6812, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  }
  
  void loop(){
    receive_signal();
  }
  
  void receive_signal(){
          // try to parse packet
        int packetSize = LoRa.parsePacket();
        if (packetSize)
        {
          // received a packet
          Serial.print("Received packet '");
  
          // read packet
          while (LoRa.available())
          {
            data_recevied = LoRa.read();
            Serial.print((char)data_recevied);
            //      Serial.print((char)LoRa.read());
            (data_recevied == '7') ? power_on_led_indicators() : power_off_led_indicators();
          }
  
          //         print RSSI of packet
          Serial.print("' with RSSI ");
          Serial.println(LoRa.packetRssi());
        }
  }
  
 void power_on_led_indicators(){
      leds[0] = CRGB::Red; // Turns LED 1 ON which is index 0
      FastLED.show();
      leds[1] = CRGB::Red; // Turns LED 2 ON which is index 1
      FastLED.show();
      leds[2] = CRGB::Red; // Turns LED 3 ON which is index 2
      FastLED.show();
      leds[3] = CRGB::Red; // Turns LED 4 ON which is index 3
      FastLED.show();
      leds[4] = CRGB::Red; // Turns LED 5 ON which is index 4
      FastLED.show();
      leds[5] = CRGB::Red; // Turns LED 6 ON which is index 5
      FastLED.show();
      leds[6] = CRGB::Red; // Turns LED 7 ON which is index 6
      FastLED.show();
      leds[7] = CRGB::Red; // Turns LED 8 ON which is index 7
      FastLED.show();
      leds[8] = CRGB::Red; // Turns LED 9 ON which is index 8
      FastLED.show();
      leds[9] = CRGB::Red; // Turns LED 10 ON which is index 9
      FastLED.show();
      leds[10] = CRGB::Red; // Turns LED 11 ON which is index 10
      FastLED.show();
      leds[11] = CRGB::Red; // Turns LED 11 ON which is index 10
      FastLED.show();
      leds[12] = CRGB::Red; // Turns LED 11 ON which is index 10
      FastLED.show();
      leds[13] = CRGB::Red; // Turns LED 11 ON which is index 10
      FastLED.show();
      leds[14] = CRGB::Red; // Turns LED 11 ON which is index 10
      FastLED.show();
      leds[15] = CRGB::Red; // Turns LED 11 ON which is index 10
      FastLED.show();
      
      delay(5000); // keeps the leds on for 5 secs 
  }
void  power_off_led_indicators(){
      leds[0] = CRGB::Black; // Turns LED 1 ON which is index 0
      FastLED.show();
      leds[1] = CRGB::Black; // Turns LED 2 ON which is index 1
      FastLED.show();
      leds[2] = CRGB::Black; // Turns LED 3 ON which is index 2
      FastLED.show();
      leds[3] = CRGB::Black; // Turns LED 4 ON which is index 3
      FastLED.show();
      leds[4] = CRGB::Black; // Turns LED 5 ON which is index 4
      FastLED.show();
      leds[5] = CRGB::Black; // Turns LED 6 ON which is index 5
      FastLED.show();
      leds[6] = CRGB::Black; // Turns LED 7 ON which is index 6
      FastLED.show();
      leds[7] = CRGB::Black; // Turns LED 8 ON which is index 7
      FastLED.show();
      leds[8] = CRGB::Black; // Turns LED 9 ON which is index 8
      FastLED.show();
      leds[9] = CRGB::Black; // Turns LED 10 ON which is index 9
      FastLED.show();
      leds[10] = CRGB::Black; // Turns LED 11 ON which is index 10
      FastLED.show();
      leds[11] = CRGB::Black; // Turns LED 11 ON which is index 10
      FastLED.show();
      leds[12] = CRGB::Black; // Turns LED 11 ON which is index 10
      FastLED.show();
      leds[13] = CRGB::Black; // Turns LED 11 ON which is index 10
      FastLED.show();
      leds[14] = CRGB::Black; // Turns LED 11 ON which is index 10
      FastLED.show();
      leds[15] = CRGB::Black; // Turns LED 11 ON which is index 10
      FastLED.show();
      delay(2000);
  }
