#include <Arduino.h>

class CommandParser
{
  public:
    CommandParser(char* command_delimiter, char* data_delimiter){
      this->command_delimiter = command_delimiter;
      this->data_delimiter = data_delimiter;
    }
    
  void parse(char* inputData) {
    Serial.println("CommandParser.parse('"+String(inputData)+"')");
    
    char* token;
    String cmd[50];
    int data_counter = 0;
    
    this->the_command = strtok(inputData, this->command_delimiter);
      Serial.println("command: "+String(this->the_command) );

    token = strtok(NULL, this->data_delimiter);
    while (token != NULL)
    {
      cmd[data_counter++] = String(token);
        Serial.println( "data token: "+String(token) );
      token = strtok(NULL, this->data_delimiter);
    }

      Serial.println("-------------");
      Serial.println("data count: "+String(data_counter));
    
//    for (int i=0; i<data_counter; i++) {
//      Serial.println(String(i)+": "+String(cmd[i]));
//    }
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

    char* the_command;
    String* the_data;
};
