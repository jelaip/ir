#include "IRremote.h"
IRrecv irrecv(2);
decode_results results;

void setup() {
   Serial.begin(9600); // ouvre le port série
   irrecv.enableIRIn();
   Serial.println("ok");
   pinMode(21,OUTPUT);
   pinMode(1,OUTPUT);
   pinMode(0,OUTPUT);
   digitalWrite(0,LOW);
   digitalWrite(1,LOW);
   digitalWrite(21,LOW);
}

void loop() {
  //Serial.println("ok");
   if (irrecv.decode()) {
      int val =  irrecv.decodedIRData.decodedRawData;
      Serial.println(val,HEX);
      if(val == 0x55500000) digitalWrite(0,HIGH);
      if(val == 0xDD500000) digitalWrite(0,LOW);
      irrecv.resume();
      
      //delay(4000);
  }
}