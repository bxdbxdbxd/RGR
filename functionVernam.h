#ifndef FUNCTIONVERNAM_H
#define FUNCTIONVERNAM_H

#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

void readingFile(string &text, const string &filename);
void writeToFile(const string &text, const string &filename);
int xorS(char a, char b);
void encryptMessageVernam(string &encryptText, const string &message, const string &key);
void decryptMessageVernam(string &encryptText, const string &encryptedMessage, const string &key);
string generateKeyVernam(const string &message);

#endif