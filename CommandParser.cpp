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

        this->the_data[counter] = atoi(token);
        data_storage[counter] = atoi(token); // если закомментировать, в the_data попадают кривые данные
        

        Serial.print( String(counter) );
        //Serial.print(": " + String(data_storage[counter]));
        Serial.print("| " + String(this->the_data[counter]));
        Serial.print("| " + String(token==NULL) );
        Serial.println("");
        
        counter++;
        
        token = strtok(NULL, this->data_delimiter);
      }

      Serial.println("~~~~~~~~~");
      Serial.println("counter: "+String(counter));

      for (int i=0; i<counter; i++) {
        Serial.println(this->the_data[i]);
        Serial.println(data_storage[i]);
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


