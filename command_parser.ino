#include "CommandParser.cpp"

CommandParser cmdParser;

void setup() {
  Serial.begin(9600); while(!Serial);

  cmdParser.parse("command:11,22,33");
  
  char* command = cmdParser.command();
  int* data = cmdParser.data();
  int len = cmdParser.length();

  //Serial.println("command: "+String(command)); //раскомментирование этой строки нарушает (?) работу
  
  Serial.print("command: ");
  Serial.println(command);

  Serial.print("count: ");
  Serial.println(len);

  Serial.println("data: ");
  for (int i=0; i<len; i++) { Serial.println(data[i]); }
}

void loop() {
  
}
