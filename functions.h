#include <string>
#include <iostream>
#include <fstream>

#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#include <bits/stdc++.h>

using namespace std;

int LEN = 255;
int act_cel = -1;
string type_inp;
set<int> prime;
int public_key;
int private_key;
int n;

string funCrypGro(string word, string key);
string funEncrypGro(string word, string key);
int funMod(int simbl, int numkey, int quaAlp);

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
    cout << "Gronsfeld" << endl;
    std::cout << "second" << std::endl << data << std::endl << "second";
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
    cout << y << "  " << k << "   88   " << b << "  ";
    for (int i = 0; i < word.size(); i++) {
        int value = (int)word[i] + k;
        cout << "- " << (int)word[i] << "   " << k << "   " << value << endl;
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
    cout << tran_val << "  " << x;
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