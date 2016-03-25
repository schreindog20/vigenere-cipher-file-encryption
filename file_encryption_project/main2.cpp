#include <string>
#include <iostream>
#include "encryption.h"
using namespace std;

int main() {
	encryption e;
	string fileName;
	string key;
	cout << "Enter the name of the file you wish to encrypt\n";
	cin >> fileName;
	cout << "Enter your cipher key: ";
	cin >> key;
	e.encrypt(fileName, key);
	e.decrypt(fileName.substr(0,fileName.size() - 4) + "_encrypted.txt", key);
	return 0;
}