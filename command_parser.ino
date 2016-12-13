#include "CommandParser.cpp"

void setup() {
  Serial.begin(9600); while(!Serial);

  qwerty("command;data;3245234;23525;", ";");
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
