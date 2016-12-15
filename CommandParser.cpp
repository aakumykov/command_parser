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
    int counter = 0;
    int* data_storage = new int;
    
    this->the_command = strtok(inputData, this->command_delimiter);
    Serial.println("the_command: "+String(this->the_command));

      token = strtok(NULL, this->data_delimiter);

      while (token != NULL) {
        data_storage[counter] = atoi(token);

        Serial.println( String(counter) + ": " + String(data_storage[counter]) + "|" + String(token==NULL) );
        
        counter++;
        
        token = strtok(NULL, this->data_delimiter);
      }
  }

  String command(){
    return this->the_command;
  }

  int* data() {
    return this->the_data;
  }

  private:
    char* command_delimiter;
    char* data_delimiter;

    char* the_command;
    int* the_data = new int;
};


