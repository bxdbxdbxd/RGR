#include <iostream>
#include <string>
#include <locale.h>
#include <windows.h>

int LEN = 255;

using namespace std;

int funMod(int simbl, int numkey, int quaAlp);
string funCryp(string word, string key);
string funEncryp(string word, string key);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"russian");

    string key = "12945";
    string newWord = "";
    int var, error = 0;
    string word;
    getline(cin, word);
    cout << "choose cypher(1) or decypher(2): ";
    cin >> var;
    newWord = word;
    //int encrypNum = funMod();
    //while(error != 1) {
        switch(var){
            case 1:
                newWord = funCryp(word, key);
                cout << "---" << newWord << "---";
            break;
            case 2:
                newWord = funEncryp(newWord, key);
                cout << "---" << newWord << "---";
            break;
            default:
                cout<<"You must make correct choice";
                error = 1;
            break;
        }
    //}

    return 0;
}

int funMod(int simbl, int numkey, int quaAlp) {
    int sunNum = simbl + numkey;
    return sunNum % quaAlp;
}

string funCryp(string word, string key) {
    string cryp_word;
    for (int i = 0; i < word.size(); i++) {
        int value = funMod(word[i], key[i%key.size()] - 48, LEN);
        if (value > -1 && value < 33) {
            cryp_word.push_back(value + 33);
        }
        else {
            cryp_word.push_back(value);
        }
    }
    return cryp_word;
}

string funEncryp(string word, string key) {
    string encryp_word;
    for (int i = 0; i < word.size(); i++) {
        int key_val = key[i%key.size()] - 48;
        int value = word[i] - key_val;
        if (-64 <= (int)word[i] && (int)word[i] <= -1) {
            if (value < -64) {
                encryp_word.push_back(192 + (value + 64));
            }
            else {
                encryp_word.push_back(value);
            }
        }
        else {
        if (value < 32) {
            encryp_word.push_back(-1 - (33 - value) + 1);
        }
        else {
            if (value < 0) {
                encryp_word.push_back(255 + value);
            }
            else {
                encryp_word.push_back(value);
            }
        }
        }
    }
    return encryp_word;
}