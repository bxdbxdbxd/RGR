#include <iostream>
#include <string>
#include <locale.h>
#include <windows.h>

int LEN = 255;

using namespace std;

int funMod(int simbl, int numkey, int quaAlp);
string funCryp(string word, string key);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"russian");

    string key = "12345";
    string newWord = "";
    int var;
    string word;
    cin >> word;
    cout << "choose cypher(1) or decypher(2): ";
    cin >> var;
    //int encrypNum = funMod();
    switch(var){
        case 1:
            newWord = funCryp(word, key);
            cout << "---" << newWord << "---";
        break;
        case 2:
            
        break;
        default:
            cout<<"You must make correct choice";
        break;
    }

    return 0;
}

int funMod(int simbl, int numkey, int quaAlp) {
    int sunNum = simbl + numkey;
    return sunNum % quaAlp;
}

string funCryp(string word, string key) {
    string new_word;
    for (int i = 0; i < word.size(); i++) {
        new_word.push_back(funMod((int)word[i], key[i%key.size()], LEN));
    }
    return new_word;
}