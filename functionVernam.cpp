#include "functionVernam.h"

void readingFile(string &text, const string &filename)
{
    ifstream file(filename, ios::binary);
    if (!file.is_open())
    {
        cerr << "Unable to open file " << filename << endl;
        throw "Unable to open file ";
    }

    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    text = move(content);
    file.close();
}

void writeToFile(const string &text, const string &filename)
{
    ofstream file(filename, ios::binary | ios::trunc);
    if (!file.is_open())
    {
        throw "Unable to open file: " + filename;
        return;
    }

    file << text;
    file.close();
}

int xorS(char a, char b)
{
    return static_cast<int>(a) ^ static_cast<int>(b);
}

void encryptMessageVernam(string &encryptText, const string &message, const string &key)
{

    for (size_t i = 0; i < message.size(); ++i)
    {
        encryptText += static_cast<unsigned char>(xorS(message[i], key[i % key.size()]));
    }
}

void decryptMessageVernam(string &encryptText, const string &encryptedMessage, const string &key)
{
    return encryptMessageVernam(encryptText, encryptedMessage, key); // Дешифрование - то же самое, что и шифрование в шифре Вернама
}

string generateKeyVernam(const string &message)
{
    string key = " ";
    int rd;

    for (size_t i = 0; i < message.size(); i++)
    {
        rd = 66 + (rand() % 55);
        key += static_cast<char>(rd);
    }

    return key;
}