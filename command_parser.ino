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
  
  Serial.print("command: "); // а эта комбинация НЕ нарушает (1)
  Serial.println(command); // а эта комбинация НЕ нарушает (2)
  
  Serial.println("---------");
  for (int i=0; i<count; i++) {
    Serial.println(data[i]);
  }
}

void loop() {
  
}
