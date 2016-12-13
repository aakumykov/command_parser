#include <Arduino.h>

class CommandParser
{
  public:
    CommandParser(char* delimiter){
      this->delimiter = delimiter;
    }
    
  void parse(char* inputData) {
    char* pch;
    String cmd[50];
    int cmd_index = 0;
    
    pch = strtok(inputData, delimiter);
    while (pch != NULL)
    {
      cmd[cmd_index++] = String(pch);
        //Serial.println( String(pch) );
      pch = strtok (NULL, delimiter);
    }
  
    String cmd2[cmd_index];
    Serial.println("cmd_index: "+String(cmd_index));
    
    for (int i=0; i<cmd_index; i++) {
      Serial.println(String(i)+": "+String(cmd[i]));
    }
  }
}
