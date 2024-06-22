#include <iostream>
#include <string>
#include <locale.h>
#include <windows.h>

using namespace std;

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  setlocale(LC_ALL, "Russian");
  string plaintext;
  cout << "Введите текст для шифрования: ";
  getline(cin, plaintext);

  string ciphertext;
  for (char c : plaintext) {
    if (isalpha(c)) {
      int num = (tolower(c) - 'a' + 1)%255;
      ciphertext += to_string(num) + " ";
    } else {
      ciphertext += c;
    }
  }

  cout << "Зашифрованный текст: " << ciphertext << endl;

  return 0;
}