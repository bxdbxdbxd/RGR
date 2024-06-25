#include "functionVernam.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Vernam cipher" << endl;

    string inputSelection;
    string message;
    string key;
    string decKey;

MetkaIntputText:
    while (true)
    {
        cout << "writing a text via the console or file" << endl;
        cout << ": ";

        getline(cin, inputSelection);
        cout << endl;

        if (inputSelection == "console")
        {
            cout << ": ";
            getline(cin, message);
            writeToFile(message, "inputConsoleMessage.txt");
            break;
        }
        else if (inputSelection == "file")
        {
            readingFile(message, "openText.txt");
            break;
        }
        else
        {
            cout << "unknown command, please try again" << endl;
            goto MetkaIntputText;
        }
    }
    cout << endl;

    cin.clear();
    cin.sync();

MetkaIntputKeyEncrypted:
    while (true)
    {
        cout << "recording key for encryption via the console or random" << endl;
        cout << ": ";
        getline(cin, inputSelection);

        if (inputSelection == "console")
        {
            cin.clear();
            cin.sync();
            cout << ": ";
            getline(cin, key);
            writeToFile(key, "keyEncrypt.txt");
            writeToFile(key, "keyDecrypt.txt");
            break;
        }
        else if (inputSelection == "random")
        {
            cin.clear();
            cin.sync();
            key = generateKeyVernam(message);
            writeToFile(key, "keyEncrypt.txt");
            writeToFile(key, "keyDecrypt.txt");
            break;
        }
        else
        {
            cout << "unknown command, please try again" << endl;
            goto MetkaIntputKeyEncrypted;
        }
    }
    cout << endl;

    // шифруем текст

    string encryptedMessage = "";
    encryptMessageVernam(encryptedMessage, message, key);
    writeToFile(encryptedMessage, "encryptedMessage.txt");

    // расшифровка текста

    cin.clear();
    cin.sync();

MetkaIntputKeyDecrypted:
    while (true)
    {
        cout << "recording key for decryption via the console or file(file is true)" << endl;
        cout << ": ";
        getline(cin, inputSelection);

        if (inputSelection == "console")
        {
            cout << "enter key decrypt\n :";
            cin >> decKey;
            writeToFile(decKey, "keyDecrypt.txt");
            break;
        }
        else if (inputSelection == "file")
        {
            readingFile(decKey, "keyDecrypt.txt");
            break;
        }
        else
        {
            cout << "unknown command, please try again" << endl;
            goto MetkaIntputKeyDecrypted;
        }
    }
    cout << endl;

    string decryptedMessage = "";
    decryptMessageVernam(decryptedMessage, encryptedMessage, decKey);
    writeToFile(decryptedMessage, "decryptedMessage.txt");

    cout << endl;
    // cin.get(); //для ожидания

    return 0;
}
