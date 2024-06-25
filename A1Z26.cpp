#include <iostream>
#include <sstream>

using namespace std;

void A1Z26_decypher(){
        cout<<"ENTER UPPER CASE LETTERS"<<endl;
        char input_char;
        string input_string,decrypt;
        cin.ignore();
        getline(cin,input_string);
        stringstream input_stream(input_string);
        while(input_stream>>input_char){
            int number=input_char-64;
            cout<<number<<" ";
            if(number>26 or number<1) throw logic_error("Only upper case english letters");
            decrypt=static_cast<char>(number);
        }
    }
void A1Z26_cypher(){
        cout<<"Enter numbers from 1 to 26"<<endl;
        string input_string,decrypt;
        cin.get();
        getline(cin,input_string);
        stringstream input_stream(input_string);
        while(input_stream>>input_string){
            int number;
            number=stoi(input_string)+64;
            if(number>26+64 or number<65) throw logic_error("Numbers must be between 0 and 27");
            decrypt=static_cast<char>(number);
            cout<<decrypt;
}
}

