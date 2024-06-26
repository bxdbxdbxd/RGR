#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int LEN = 255;
int act_cel = -1;
string type_inp;

string funCrypGro(string word, string key);
string funEncrypGro(string word, string key);
int funMod(int simbl, int numkey, int quaAlp);

void first(string data) {
    string newWord = data;
    cout << "Gronsfeld" << endl;
    string key = "12945";
    if (act_cel == 0) {
        newWord = funCrypGro(data, key);
        if (type_inp == "1") {
            cout << "The encoded message  " << newWord << endl;
        } 
        else {
            ofstream CrypFile("ciphertext.txt");
            CrypFile << newWord;
            CrypFile.close();
            cout << "File created" << endl;
        }
        act_cel = -1;
    }
    if (act_cel == 1) {
        newWord = funEncrypGro(newWord, key);
        if (type_inp == "1") {
            cout << "The decoded message  " << newWord << endl;
        }
        else {
            ofstream EncrypFile("deciphertext.txt");
            EncrypFile << newWord;
            EncrypFile.close();
            cout << "File created" << endl;
        }
        act_cel = -1;
    }
}

void second(std::string data){
    std::cout << "second" << std::endl << data << std::endl << "second";
}

void third(std::string data){
    std::cout << "third" << std::endl << data << std::endl << "third";
}

void fourth(std::string data){
    std::cout << "fourth" << std::endl << data << std::endl << "fourth";
}

void fifth(std::string data){
    std::cout << "fifth" << std::endl << data << std::endl << "fifth";
}

void sixth(std::string data){
    std::cout << "sixth" << std::endl << data << std::endl << "sixth";
}

void seventh(std::string data){
    std::cout << "seventh" << std::endl << data << std::endl << "seventh";
}

void eighth(std::string data){
    std::cout << "eighth" << std::endl << data << std::endl << "eighth";
}

void ninth(std::string data){
    std::cout << "ninth" << std::endl << data << std::endl << "ninth";
}

int funMod(int simbl, int numkey, int quaAlp) {
    int sunNum = simbl + numkey;
    return sunNum % quaAlp;
}

string funCrypGro(string word, string key) {
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

string funEncrypGro(string word, string key) {
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