#include <iostream>
#include <string>
#include <locale.h>
#include <windows.h>

using namespace std;
string cypher(string text);
string decypher(string text);

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  setlocale(LC_ALL, "Russian");
  string text;
  cout << "Enter text: ";
  getline(cin, text);
  string ciphertext;

  cout << "choose cypher(1) or decypher(2): ";
  int var=0;
  cin>>var;
    switch(var){
        case 1:
        ciphertext=cypher(text);
        cout << ciphertext <<endl;
        break;
        case 2:
        //text=decypher(text,step,n);
        cout << text <<endl;
        break;
        default:
        cout<<"You must make correct choice ";
        break;
    }

    return 0;
}
string cypher(string text){
  int check=0;
  string ciphertext;
  for (char c : text) {
    int a = static_cast<unsigned char>(c);
    if (isalpha(c)) {
      if(a>='A' && a<='z'){
        if(check>=0){
        int num = (tolower(c) - 'a' + 1)%255;
        ciphertext += to_string(num) + " ";
        check+=1;
        }
        else{
          cout<<"You can only use letters from 1 alphabet";
          return 0;
        }
      }
        else if(a>=192 && a<=255){
          if(check<=0){
        int num = (tolower(c)+1)%224;
        ciphertext += to_string(num) + " ";
        check-=1;
        }
        else{
          cout<<"You can only use letters from 1 alphabet";
          return 0;
        }
      }
    } else {
      cout << "The text must contain only letters";
      return 0;
    }

  }
  return ciphertext;
}
string decypher(string text){

}