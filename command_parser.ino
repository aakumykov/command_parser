
String* qwerty(char* str, char* delimiter) {
  //char str[] = "command;data;3245234;23525;";
  //char delimiter[] = ";";
  
  char* pch;
  String cmd[50];
  int cmd_index = 0;
  
  pch = strtok(str, delimiter);
  while (pch != NULL)
  {
    cmd[cmd_index++] = String(pch);
      //Serial.println( String(pch) );
    pch = strtok (NULL, delimiter);
  }

  String cmd2[cmd_index];
  Serial.println("cmd_index: "+String(cmd_index));
  
  for (int i=0; i<cmd_index; i++) {
    cmd2[i] = cmd[i];
    Serial.println(String(i)+": "+String(cmd[i]));
  }
  
  return cmd2;
}

void setup() {
  Serial.begin(9600); while(!Serial);

  String data[] = qwerty("command;data;3245234;23525;", ";");
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
