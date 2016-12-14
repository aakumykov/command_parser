#include "CommandParser.cpp"

CommandParser cmdParser(":", ",");

void setup() {
  Serial.begin(9600); while(!Serial);
  Serial.println("setup()");
  delay(100);

  cmdParser.parse("command:1,22,333,4444,55555,6666,777,88,1,qwerty");
//  Serial.println("-------------");
//  cmdParser.parse("command:0,0,0,100,100,100,100,0,");
}

void loop() {
  
}
