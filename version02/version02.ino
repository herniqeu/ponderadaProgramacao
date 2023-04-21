// C++ code
String groupMembers[7] = {"Rafael", "Fabio", "Godoy", "Giuliano", "Yuri", "Marcelo", "Jose"};
//verifica se o nome colocado no primeiro input faz parte da lista de membros do grupo 
boolean verifyMember(String name){
  boolean isInGroupMembers = false;
  for(int i = 0; i < sizeof(groupMembers); i++){
    if(groupMembers[i] == name){
       isInGroupMembers = true;
    }
  }

  return isInGroupMembers;
}
// void setup é um método utilizado para configurar a placa antes de iniciar o void loop
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Escreva o seu nome para saber se você participa do melhor grupo: ");
//Esse while consegue parar a função loop até o serial available receber alguma informação
  while (Serial.available() == 0) {
  }

  String userInputName = Serial.readStringUntil('\n');
  if (verifyMember(userInputName)) {
    Serial.println("\nVocê faz parte do grupo!\nSeja bem vindo senhor.");
  } else {
    Serial.println("\nVocê não faz parte do Grupo :(");
  }
  
  Serial.println("\nAgora eu preciso de um valor float, então me fale sua altura em metros\n(utilizando um ponto para representar o início das casas decimais): ");
  while (Serial.available() == 0) {
  }
  float userInputHeight = Serial.parseFloat();
   
  Serial.println("\n Preciso de mais um valor float, então me fale sua idade: ");
  while (Serial.available() == 0) {
  }
  int userInputAge = Serial.parseInt();
  
  Serial.println("\nOlá " + userInputName + ", você tem " + String(userInputHeight) + " de altura e "+ String(userInputAge) + " anos!");
  
  Serial.println("\nVocê torce para algum time do futebol brasileiro?\nResponda sim ou não: ");
  
  while (Serial.available() == 0) {
  }
  
  String supportsTeam = Serial.readStringUntil('\n');
  if (supportsTeam == "sim"){
    Serial.println("Pra qual time você torce?");
  	while (Serial.available() == 0) {
  	}
  	String favoriteTeam = Serial.readStringUntil('\n');
    if (favoriteTeam == "Palmeiras" || favoriteTeam == "palmeiras"){
      Serial.println("Parabéns campeão! Avanti Palestra!");
    }
    else{
      Serial.println("Sinto muito, mas você é pato do Palmeiras");
    }
  }else{
    Serial.println("Entendido," + userInputName + "não torce para nenhum time do Brasil");
  }
  delay(1000);
  Serial.println("\n\nRecomeçando o sistema...");
  delay(1000);
}