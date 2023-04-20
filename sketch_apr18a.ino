String getUserStringInput() {
  String userInput = "";

  if(Serial.available()){
    userInput = Serial.readStringUntil('\n');
  }
  
  return userInput;
}

String groupMembers[6] = {"rafael", "Fabio", "Godoi", "Giuliano", "Yuri", "Marcelo"};
boolean verifyMember(String name){
  boolean isInGroupMembers = false;
  for(int i = 0; i < sizeof(groupMembers); i++){
    if(groupMembers[i] == name){
       isInGroupMembers = true;
    }
  }

  return isInGroupMembers;
}

void setup() {
  Serial.begin(9600);
}

boolean waitingUserInput = false;
void printAndWait(String text){
  if(!waitingUserInput){
      Serial.print(text);
      waitingUserInput = true;   
   }
}

int state = 0;
String userName;
void loop() {
  if(state == 0){
    String userString = getUserStringInput();
    if(userString.length() > 0){
      userName = userString;
      Serial.print("\nNome:" + userName);
      if(verifyMember(userName)){
        Serial.print("\nEh parte do Grupo!");
        if(userString == "Godoi"){
          Serial.print("\nEh Godoi!");
        }
       } else {
          Serial.print("\nNão é parte do Grupo :(");
        }

      state = 1;
     }
  }else if(state == 1){
    printAndWait("\nDigite sua Altura: ");
    String userSecondString = getUserStringInput();
    if(userSecondString.length() > 0){
      waitingUserInput = false;
      float height = userSecondString.toFloat();
      Serial.print("\nOlá " + userName + ", você tem " + String(height) + " de altura!");
      state = 0;
    }
  }
}
