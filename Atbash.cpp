#include <iostream>
#include <string>
#include <locale.h>
#include <windows.h>
using namespace std;

string cypher(string text,int max);
string decypher(string text,int max);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"russian");
    int step=0;
    int n=255;
    int var=0;
    string text;
    getline(cin, text);
    cout << "choose cypher(1) or decypher(2): ";
    cin>>var;
    switch(var){
        case 1:
        text=cypher(text,n);
        cout << text <<endl;
        break;
        case 2:
        text=decypher(text,n);
        cout << text <<endl;
        break;
        default:
        cout<<"You must make correct choice ";
        break;
    }

    return 0;
}
string cypher(string text, int max){
    for(int i=0;i<text.size();i++){
        text[i]=max-text[i]+1;
        text[i]=text[i]%max;
    }
    return text;
}
string decypher(string text, int max){
    for(int i=0;i<text.size();i++){
        text[i]=max-text[i]+1;;
        text[i]=text[i]%max;
    }
    return text;
}