#include <iostream>
#include <string>
#include <locale.h>
#include <windows.h>
#include <functional>

#include "functions.h"

using namespace std;

unsigned int simple_hash(const string &str);
bool is_password_correct();
function<void(string)> choice_method();
string read_file(const string& filename);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"russian");
    // Сравнение хэшей
    if (!is_password_correct()) {
        cout << "Password incorrect. Application closed." << endl;
        return 1;
    }

    while (true) {
        function<void(string)> method;
        string content, nl;
        bool process, error = 1;
        do
        {
            // Выбор метода
            method = choice_method();
            if (method == nullptr) {
                cout << "Method incorrect. Try again." << endl;
                continue;
            }
            else {
                break;
            }
        } while (true);
        
        getline(cin, nl);
        cout << "Select input type: console(1) or file(2)" << endl;
        getline(cin, type_inp);
        cout << endl;

        if (type_inp == "1") {
            cout << "Enter text ";
            getline(cin, content);
        }
        else if (type_inp == "2") {
            do
            {
                string filename;
                cout << "Input file name: ";
                cin >> filename;
                content = read_file(filename);
                if (content.length() == 0) {
                    cout << "File not found. Try again." << endl;
                    continue;
                }
                else {
                    break;
                }
            } while (true);
        }
        else {
            error = 0;
            cout << "You must make correct choice" << endl;
        }
        if (error == 1) {
            int var;
            cout << "Choice ecrypt(1) or decrypt(2)?" << endl;
            cin >> var;
            cout << endl;
            switch(var) {
                case 1:
                    cout << "Choicecrypt: " << var << endl;
                    cout << "Method work: ";
                    act_cel = 0;
                    method(content);
                break;
                case 2:
                    cout << "Choicecrypt: " << var << endl;
                    cout << "Method work: ";
                    act_cel = 1;
                    method(content);
                break;
                default:
                    cout << "You must make correct choice";
                break;
            }
            
            // Тестирование работы
        }
            //method(content);
        cout << endl;
            // Тестирование работы

        int is_not_exit;
        cout << "Do you want to exit?" << endl;
        cout << "1 - No" << endl << "other input - Yes" << endl;
        cin >> is_not_exit;
        if (is_not_exit == 1) {
            cout << "Bzzzz... Restart system... bzzz" << endl;
            continue;
        }
        break; // Завершение цикла после успешного выбора
    }
    return 0;
}

// Функция проверки пароля на корректность
bool is_password_correct() {
    // Пример зашифрованного (хэшированного) пароля для сравнения
    const unsigned int stored_hash = 1216985755;

    // Ввод пароля
    string input_password;
    cout << "Password: ";
    cin >> input_password;

    // Хэширование введенного пароля
    unsigned int input_hash = simple_hash(input_password);

    return (stored_hash == input_hash);
}

// Функция для простого хэширования пароля с помощью XOR и сложения
unsigned int simple_hash(const string &str) {
    unsigned int hash = 0;
    for (char c : str) {
        hash = hash * 31 + c; // Хэширование с помощью умножения и сложения
    }
    return hash;
}

function<void(string)> choice_method() {
    pair<string, function<void(string)>> menu[] = {
        {"First", first},
        {"Second", second},
        {"Third", third},
        {"Fourth", fourth},
        {"Fifth", fifth},
        {"Sixth", sixth},
        {"Seventh", seventh},
        {"Eighth", eighth},
        {"Ninth", ninth}
    };
    int count = sizeof(menu)/sizeof(menu[0]);

    cout << "Input (1 - " << count << ") method:" << endl;
    for (int i = 0; i < count; i++) {
        cout << i+1 << " - " << menu[i].first << endl;
    }

    int num_method;
    cin >> num_method;

    if (num_method < 1 || num_method > count) {
        return nullptr;
    }

    return menu[num_method-1].second;
}

// Функция для чтения содержимого файла
string read_file(const string& filename) {
    ifstream file(filename); // Пытаемся открыть файл для чтения
    if (!file.is_open()) {
        return ""; // Возвращаем пустую строку в случае ошибки
    }

    // Считываем содержимое файла в строку
    string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
    file.close(); // Закрываем файл

    return content;
}