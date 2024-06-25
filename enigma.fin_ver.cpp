#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

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

int main() {
    string data = "HELLO WORLD";
    string encrypted = enigma(data, true);
    cout << "Encrypted: " << encrypted << endl;

    string decrypted = enigma(encrypted, false);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}