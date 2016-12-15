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
    int a_size = 3;
    int* data_storage = new int[a_size];
    
    this->the_command = strtok(inputData, this->command_delimiter);
    Serial.println("the_command: "+String(this->the_command));

      token = strtok(NULL, this->data_delimiter);

      for (int i=0; i<a_size; i++) {
        data_storage[i] = atoi(token);
        
        //Serial.println( "t: "+String(token)+ ", int: "+String(int(token))+ ", atoi: " + String(atoi(token)) );
        //Serial.println( String(i) + ": " + String(token) + "|" + String(token==NULL) );
        
        Serial.println( String(i) + ": " + String(data_storage[i]) + "|" + String(token==NULL) );
        
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

