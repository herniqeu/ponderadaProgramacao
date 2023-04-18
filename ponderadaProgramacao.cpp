#include <iostream>
#include <string>
#include <vector>

using namespace std;

string GodoySimilar(bool bIsTrue) {
    if(bIsTrue) 
        return "very similar to Godoy";
    else 
        return "not very similar to Godoy";
}

int main() {
    bool bIsTrue = true;
    string sName = "Henrique";
    string sLastName = "Godoy";
    int iAge = 18;
    float fWeight = 74.0f;
    float fHeight = 1.84f;

    int n;
    string sNameInput;
    string sLastNameInput; 
    int iAgeInput;
    cin >> n; 

    vector<string> name;
    vector<string> lastname;
    vector<int> age;

    for(int i = 0; i < n; i++){
		cout << "Write your First Name \n";
        cin >> sNameInput; 
		cout << "Write your Last Name \n";
        cin >> sLastNameInput; 
		cout << "Put your Age \n";
        cin >> iAgeInput;

       name.push_back(sNameInput);
        lastname.push_back(sLastNameInput);
        age.push_back(iAgeInput);
    }

    for (int i = 0; i < n; i++){
        bIsTrue = ((name[i] == "Henrique") && (lastname[i] == "Godoy") && (age[i] == 18));
        cout << GodoySimilar(bIsTrue) << endl;
    }

    return 0;
}

