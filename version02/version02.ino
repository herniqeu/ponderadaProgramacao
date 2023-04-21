String groupMembers[6] = {"Rafael", "Fabio", "Godoy", "Giuliano", "Yuri", "Marcelo"};
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

void loop() {
  Serial.println("Escreva o seu nome para saber se você participa do melhor grupo: ");
//Esse while consegue parar a função void até o serial available receber alguma informação
  while (Serial.available() == 0) {
  }

  String userInputName = Serial.readStringUntil('\n');
  if (verifyMember(userInputName)) {
    Serial.println("\nVocê faz parte do grupo!\nSeja bem vindo senhor.");
  } else {
    Serial.println("\nVocê não faz parte do Grupo :(");
  }

  Serial.println(Serial.available());
  
  Serial.println("Agora eu preciso de um valor float, então me fale sua altura em metros: ");
  while (Serial.available() == 0) {
  }

  float userInputHigh = Serial.parseFloat();
  Serial.println("\nOlá " + userInputName + ", você tem " + String(userInputHigh) + " de altura!");

  Serial.println(Serial.available());
}
