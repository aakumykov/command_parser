#include <Arduino.h>

class CommandParser
{
  public:
    CommandParser(char* command_delimiter, char* data_delimiter){
      this->command_delimiter = command_delimiter;
      this->data_delimiter = data_delimiter;
    }
    
  void parse(char* inputData) {
    char* token;
    
    this->the_command = strtok(inputData, this->command_delimiter);
      Serial.println("command: "+String(this->the_command) );

    token = strtok(NULL, this->data_delimiter);
    while (token != NULL)
    {
      this->data2[this->data_counter++] = token;
      token = strtok(NULL, this->data_delimiter);
    }

      for (int i=0; i<this->data_counter; i++) {
        Serial.println( "data: "+String(this->data2[i]) );
      }
      Serial.println("-------------");
      Serial.println("data count: "+String(this->data_counter));
  }

  char* command(){
    return this->the_command;
  }

  char* data() {
    return this->data2;
  }

  private:
    char* command_delimiter;
    char* data_delimiter;

    char* the_command;
    char* data2 = new char;
    int data_counter = 0;
};
