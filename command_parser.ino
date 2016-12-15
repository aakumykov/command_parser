#include "CommandParser.cpp"

CommandParser cmdParser(":", ",");

void setup() {
  Serial.begin(9600); while(!Serial);
  Serial.println("setup()");
  delay(100);

  cmdParser.parse("command:11,22,33");
}

void loop() {
  
}
