#include <iostream>
#include <string>
#include <locale.h>
#include <windows.h>
using namespace std;

wstring cypher(wstring text, int step);
wstring decypher(wstring text, int step);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"russian");
    int step=0;
    wstring text;
    wcin>>text;
    cout << "Enter the key value: ";
    cin >> step;
    text=cypher(text,step);
    wcout << text <<endl;
    return 0;
}
wstring cypher(wstring text, int step){
    for(int i=0;i<text.size();i++){
        text[i]=text[i]+step;
    }
    return text;
}
wstring decypher(wstring text, int step){
    for(int i=0;i<text.size();i++){
        text[i]=text[i]-step;
    }
    return text;
}