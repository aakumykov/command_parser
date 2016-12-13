#include "CommandParser.cpp"

CommandParser cmdParser(",");

void setup() {
  Serial.begin(9600); while(!Serial);

  cmdParser.parse("command,0,0,0,100,100,100,100,0");
//  Serial.println("-------------");
//  cmdParser.parse("command:0,0,0,100,100,100,100,0,");
}

void loop() {
  
}
