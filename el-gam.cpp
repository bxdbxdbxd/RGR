#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>

using namespace std;

int generVal(int a, int y, int p);
int greatest_com_div(int a, int b);
bool funPrimRoot(vector<int>& vec, int a, int p);
int funMod(int a, int x, int p);
string funCryp(string word, int p, int a, int b, int y);
string funEncryp(string word, int x, int p, int tran_val);

int main() {
    int primitive_root = 0, prime_num = 11, private_key = 6, public_key[3];
    vector<int> residues(prime_num - 1);
    bool result = false;
    int y = rand() % prime_num;
    for (int i = 1; i < prime_num; i++) {
        result = funPrimRoot(residues, i, prime_num);
        if (result == true) {
            primitive_root = i;
            cout << primitive_root << "--" << endl;
            break;
        }
    }
    if (primitive_root != 0) {
        int var;
        string word, newWord;
        public_key[0] = primitive_root;
        public_key[1] = prime_num;
        public_key[2] = funMod(primitive_root, private_key, prime_num);
        cout << "Public key " << public_key[0] << ", " << public_key[1] << ", " << public_key[2] << endl;
        getline(cin, word);
        cout << "choose cypher(1) or decypher(2): ";
        cin >> var;
        newWord = word;
        switch(var) {
            case 1:
                newWord = funCryp(word, prime_num, primitive_root, public_key[2], y);
                cout << "---" << newWord << "---";
            break;
            case 2:
                newWord = funEncryp(newWord, private_key, prime_num, generVal(public_key[0], y, public_key[1]));
                cout << "---" << newWord << "---";
            break;
            default:
                cout<<"You must make correct choice";
            break;
        }
    }
    else {
        cout << "Error";
    }
    return 0;
}


int generVal(int a, int y, int p) {
    int val = funMod(a, y, p);
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

int funMod(int a, int x, int p) {
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

string funCryp(string word, int p, int a, int b, int y) {
    string cryp_word;
    int k;
    k = funMod(b, y, p);
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


string funEncryp(string word, int x, int p, int tran_val) {
    string encryp_word;
    cout << tran_val << "  " << x;
    for (int i = 0; i < word.size(); i++) {
        int value = word[i] - funMod(tran_val, x, p);
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