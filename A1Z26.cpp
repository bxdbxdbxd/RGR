#include <iostream>

using namespace std;

int main() {
  string plaintext;
  cout << "Введите текст для шифрования: ";
  getline(cin, plaintext);

  string ciphertext;
  for (char c : plaintext) {
    if (isalpha(c)) {
      int num = (tolower(c) - 'a' + 1);
      ciphertext += to_string(num) + " ";
    } else {
      ciphertext += c;
    }
  }

  cout << "Зашифрованный текст: " << ciphertext << endl;

  return 0;
}