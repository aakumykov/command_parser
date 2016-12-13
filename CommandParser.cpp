#include <Arduino.h>

class CommandParser
{
  public:
    CommandParser(char* command_delimiter, char* data_delimiter){
      this->command_delimiter = command_delimiter;
      this->data_delimiter = data_delimiter;
    }
    
  void parse(char* inputData) {
    char* pch;
    String cmd[50];
    int cmd_index = 0;
    
    pch = strtok(inputData, command_delimiter);
    while (pch != NULL)
    {
      cmd[cmd_index++] = String(pch);
        //Serial.println( String(pch) );
      pch = strtok (NULL, command_delimiter);
    }
  
    Serial.println("cmd_index: "+String(cmd_index));
    
    for (int i=0; i<cmd_index; i++) {
      Serial.println(String(i)+": "+String(cmd[i]));
    }
  }

  String command(){
    return this->the_command;
  }

  String* data() {
    return this->the_data;
  }

  private:
    char* command_delimiter;
    char* data_delimiter;

    String the_command;
    String* the_data;
};
