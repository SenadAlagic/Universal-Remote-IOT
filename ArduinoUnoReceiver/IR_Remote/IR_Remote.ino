#include "IRremote.hpp"
//#include <IRSend.hpp>

int receiverPin=2;
IRrecv receiver(receiverPin);
IRsend irsend;
decode_results results;

String readString;

void setup() {
  Serial.begin(9600);
  receiver.enableIRIn();
  while(!Serial)
    delay(50);
  Serial.println();
  Serial.print("IRrecvDemo is now running and waiting for IR message on Pin");
  Serial.println(receiverPin);
  irsend.setSendPin(9);
}

void loop() {
  while (Serial.available() == 0) {
    delay(100);
    //Serial.println("Waiting for data");
  }
  char c = Serial.read();
  if (c == ',') 
  {
    if (readString.length() > 1) 
    {
      Serial.print("Data received is ");
      Serial.println(readString);

      char* sendString=(char*) malloc(sizeof(char)*(readString.length()+1));
      readString.toCharArray(sendString, readString.length()+1);

      irsend.sendNEC(strtoul(sendString,NULL,16),32);
      //irsend.sendNEC(readString, 32);
      readString = "";
    }
  }
  else
  {
    readString+=c;
  }
  //Serial.print("Data is ");
  //Serial.println(Serial.read());
  //irsend.sendNEC(Serial.read(),HEX);
  //irsend.sendNEC(0xFF30CF,32);
  //irsend.sendNEC(0x6F905583,32);
  if(receiver.decode(&results))
  {
    Serial.println(results.value, HEX);
    Serial.println("");
    receiver.resume();
  }
  delay(100);
}
