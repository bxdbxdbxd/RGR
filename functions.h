#include <string>
#include <iostream>
#include <fstream>

#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#include <bits/stdc++.h>
#include "functionVernam.h"
#include "functionVernam.cpp"

using namespace std;

int LEN = 255;
int act_cel = -1;
string type_inp;
set<int> prime;
int public_key;
int private_key;
int n;
struct Rotor;

string funCrypGro(string word, string key);
string funEncrypGro(string word, string key);
int funMod(int simbl, int numkey, int quaAlp);

int createdPubKey(int pub[], int a, int p, int b);
int generVal(int a, int y, int p);
int greatest_com_div(int a, int b);
bool funPrimRoot(vector<int>& vec, int a, int p);
int funModul(int a, int x, int p);
string funCrypElGam(string word, int p, int a, int b, int y);
string funEncrypElGam(string word, int x, int p, int tran_val);

void primefiller();
int pickrandomprime();
void setkeys();
long long int encrypt(double message);
long long int decrypt(int encrpyted_text);
vector<int> encoder(string message);
string decoder(vector<int> encoded);

string cypher(string text, int step,int max);
string decypher(string text, int step,int max);

string cypherAtb(string text,int max);
string decypherAtb(string text,int max);

string enigma(string data, bool flag);

string cypherRot(string text, int step,int max);
string decypherRot(string text, int step,int max);

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

void second(string data){
    string newWord = data;
    cout << "Elgamal" << endl;
    int primitive_root = 0, prime_num = 11, private_key = 6, public_key[3];
    vector<int> residues(prime_num - 1);
    bool result = false;
    int y = rand() % prime_num;
    for (int i = 1; i < prime_num; i++) {
        result = funPrimRoot(residues, i, prime_num);
        if (result == true) {
            primitive_root = i;
            cout << "Primitive root" << primitive_root << endl;
            break;
        }
    }
    if (primitive_root != 0) {
        createdPubKey(public_key, primitive_root, prime_num, funModul(primitive_root, private_key, prime_num));
        cout << "Public key " << public_key[0] << ", " << public_key[1] << ", " << public_key[2] << endl;
        if (act_cel == 0) {
            newWord = funCrypElGam(newWord, prime_num, primitive_root, public_key[2], y);
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
            newWord = funEncrypElGam(newWord, private_key, prime_num, generVal(public_key[0], y, public_key[1]));
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
    else {
        cout << "Error";
    }
}

void third(string data){
    string newWord = data;
    cout << "RSA" << endl;
    primefiller();
	setkeys();
    vector<int> coded = encoder(newWord);
    if (type_inp == "1") {
        cout << "\nThe encoded message\n";
	    for (auto& p : coded)
		    cout << p;
	    cout << "\n\nThe decoded message\n";
	    cout << decoder(coded) << endl;
    }
    if (type_inp == "2") {
        ofstream CrypFile("ciphertext.txt");
        ofstream EncrypFile("deciphertext.txt");
        for (auto& p : coded)
		    CrypFile << p;
        CrypFile.close();
        EncrypFile << decoder(coded);
        EncrypFile.close();
        cout << "Files created" << endl;
    }
}

void fourth(string data){
    string newWord = data;
    cout << "Cezar" << endl;
    int step=0;
    cout << "Enter the key value: ";
    cin >> step;
    if (act_cel == 0) {
        newWord = cypher(newWord,step,LEN);
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
        newWord = decypher(newWord,step,LEN);
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

void fifth(string data){
    string newWord = data;
    cout << "Atbash" << endl;
    if (act_cel == 0) {
        newWord = cypherAtb(newWord,LEN);
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
        newWord = decypherAtb(newWord,LEN);
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

void sixth(string data){
    string message = data;
    cout << "Vernam" << endl;
}

void seventh(string data){
    string newWord = data;
    cout << "Enigma" << endl;
    if (act_cel == 0) {
        newWord = enigma(newWord, true);
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
        newWord = enigma(newWord, false);
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

void eighth(string data){
    string newWord = data;
    cout << "ROT1" << endl;
    int step=1;
    if (act_cel == 0) {
        newWord = cypherRot(newWord,step,LEN);
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
        newWord = decypherRot(newWord,step,LEN);
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

void ninth(string data){
    string message = data;
    cout << "A1Z26" << endl;
    
}

//for Gronsfeld
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

//for Elgamal
int createdPubKey(int pub[], int a, int p, int b) {
    pub[0] = a;
    pub[1] = p;
    pub[2] = b;
}

int generVal(int a, int y, int p) {
    int val = funModul(a, y, p);
    return val;
}

int greatest_com_div(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool funPrimRoot(vector<int>& vec, int a, int p) {
    if (greatest_com_div(a, p) != 1) {
        return false;
    }
    for (int i = 1; i < p; i++) {
        vec[i - 1] = (int)pow(a, i) % p;
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < p - 1; i++) {
        if (vec[i] != i+1) {
            return false;
        }
    }
    return true;
}

int funModul(int a, int x, int p) {
    int pfi = p-1;
    int st = x % pfi;
    int result = 1;
    a = a % p;
    for (int i = 1; i <= st; i++) {
        result *= a;
        result %= p;
    }
    return result;
}

string funCrypElGam(string word, int p, int a, int b, int y) {
    string cryp_word;
    int k;
    k = funModul(b, y, p);
    for (int i = 0; i < word.size(); i++) {
        int value = (int)word[i] + k;
        if (value > -1 && value < 33) {
            cryp_word.push_back(value + 33);
        }
        else {
            cryp_word.push_back(value);
        }
    }
    return cryp_word;
}

string funEncrypElGam(string word, int x, int p, int tran_val) {
    string encryp_word;
    for (int i = 0; i < word.size(); i++) {
        int value = word[i] - funModul(tran_val, x, p);
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

//for RSA
void primefiller() {
	vector<bool> seive(250, true);
	seive[0] = false;
	seive[1] = false;
	for (int i = 2; i < 250; i++) {
		for (int j = i * 2; j < 250; j += i) {
			seive[j] = false;
		}
	} 
	for (int i = 0; i < seive.size(); i++) {
		if (seive[i])
			prime.insert(i);
	}
}

int pickrandomprime() {
	int k = rand() % prime.size();
	auto it = prime.begin();
	while (k--)
		it++;
	int ret = *it;
	prime.erase(it);
	return ret;
}

void setkeys() {
	int prime1 = pickrandomprime();
	int prime2 = pickrandomprime();
	//cout<<prime1<<" "<<prime2<<endl;
	n = prime1 * prime2;
	int fi = (prime1 - 1) * (prime2 - 1);
	int e = 2;
	while (1) {
		if (__gcd(e, fi) == 1)
			break;
		e++;
	}
	public_key = e;
	int d = 2;
	while (1) {
		if ((d * e) % fi == 1)
			break;
		d++;
	}
	private_key = d;
}

long long int encrypt(double message) {
	int e = public_key;
	long long int encrpyted_text = 1;
	while (e--) {
		encrpyted_text *= message;
		encrpyted_text %= n;
	}
	return encrpyted_text;
}

long long int decrypt(int encrpyted_text) {
	int d = private_key;
	long long int decrypted = 1;
	while (d--) {
		decrypted *= encrpyted_text;
		decrypted %= n;
	}
	return decrypted;
}

vector<int> encoder(string message) {
	vector<int> form;
	for (auto& letter : message)
		form.push_back(encrypt((int)letter));
	return form;
}

string decoder(vector<int> encoded) {
	string s;
	for (auto& num : encoded)
		s += decrypt(num);
	return s;
}

//for Cezar
string cypher(string text, int step,int max){
    for(int i=0;i<text.size();i++){
        text[i]=text[i]+step;
        text[i]=text[i]%max;
    }
    return text;
}
string decypher(string text, int step,int max){
    for(int i=0;i<text.size();i++){
        text[i]=text[i]-step;
        text[i]=text[i]%max;
    }
    return text;
}

//for Atbash
string cypherAtb(string text, int max){
    for(int i=0;i<text.size();i++){
        text[i]=max-text[i]+1;
        text[i]=text[i]%max;
    }
    return text;
}
string decypherAtb(string text, int max){
    for(int i=0;i<text.size();i++){
        text[i]=max-text[i]+1;;
        text[i]=text[i]%max;
    }
    return text;
}


//for Enigma
struct Rotor {
    int position;
    vector<char> wiring;
    vector<char> reverse_wiring;

    // Конструктор
    Rotor(int rotor_number, int index) : position(index) {
        switch (rotor_number)
        {
        case 1:
            wiring = { 'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J' };
            break;
        case 2:
            wiring = { 'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E' };
            break;
        case 3:
            wiring = { 'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O' };
            break;
        default:
            throw runtime_error("Rotor number incorrect");
        }

        reverse_wiring.resize(26);
        for (int i = 0; i < 26; ++i) {
            reverse_wiring[wiring[i] - 'A'] = 'A' + i;
        }
    }

    char encode(char c) {
        int index = (c - 'A' + position) % 26;
        return wiring[index];
    }

    char decode(char c) {
        int index = (find(wiring.begin(), wiring.end(), c) - wiring.begin() - position + 26) % 26;
        return 'A' + index;
    }

    void rotate() {
        position = (position + 1) % 26;
    }
};

string enigma(string data, bool flag) {
    // Выбор роторов и начальных позиций
    Rotor rotor1(1, 0);
    Rotor rotor2(2, 0);
    Rotor rotor3(3, 0);

    string result;
    for (char c : data) {
        if (isalpha(c)) {
            char upper = toupper(c);
            if (flag) {
                upper = rotor1.encode(upper);
                upper = rotor2.encode(upper);
                upper = rotor3.encode(upper);
            }
            else {
                upper = rotor3.decode(upper);
                upper = rotor2.decode(upper);
                upper = rotor1.decode(upper);
            }
            rotor1.rotate();
            if (rotor1.position == 0) {
                rotor2.rotate();
                if (rotor2.position == 0) {
                    rotor3.rotate();
                }
            }
            result += upper;
        }
        else {
            result += c;
        }
    }
    return result;
}

//fot ROT1
string cypherRot(string text, int step, int max){ //шифровщик
    for(int i=0;i<text.size();i++){
        text[i]=text[i]+step;
        text[i]=text[i]%max;
    }
    return text;
}
string decypherRot(string text, int step, int max){ // дешифровщик
    for(int i=0;i<text.size();i++){
        text[i]=text[i]-step;
        text[i]=text[i]%max;
    }
    return text;
}

//for A1Z26