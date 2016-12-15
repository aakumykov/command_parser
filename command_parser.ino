#include "CommandParser.cpp"

CommandParser cmdParser(":", ",");

void setup() {
  Serial.begin(9600); while(!Serial);
  Serial.println("setup()");
  delay(100);

  cmdParser.parse("command:11,22,33");
  
  char* command = cmdParser.command();
  int* data = cmdParser.data();
  int count = cmdParser.count();

  //Serial.println("command: "+String(command)); //раскомментирование этой строки нарушает (?) работу
  Serial.println(command);
  Serial.println("---------");
  for (int i=0; i<count; i++) {
    Serial.println(data[i]);
  }
}

void loop() {
  
}
