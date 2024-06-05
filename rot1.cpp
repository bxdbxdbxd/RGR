#include <iostream>
#include <string>
#include <locale.h>
#include <windows.h>
using namespace std;

wstring cypher(wstring text, int step);
wstring decypher(wstring text, int step);
int main()
{
    SetConsoleCP(1251); // Русский язык в консоли
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"russian");
    int step = 1;
    wstring text; // символьный тип
    wcout << "Enter the text: ";
    wcin >> text;
    text = cypher(text,step);
    wcout << "Your text: " << text <<endl;
    wcout << "Decypher: " << decypher(cypher(text, step), step);
    return 0;
}
wstring cypher(wstring text, int step){ //шифровщик
    for(int i=0;i<text.size();i++){
        text[i]=text[i]+step;
    }
    return text;
}
wstring decypher(wstring text, int step){ // дешифровщик
    for(int i=0;i<text.size();i++){
        text[i]=text[i]-step;
    }
    return text;
}

