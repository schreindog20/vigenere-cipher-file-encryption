#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include <fstream>
#include <string>
#include <cctype>
#include <iostream>
using namespace std;

class encryption {
private:
	// openReadFile: open a file with the passed in file name for reading - return the ifstream object
	ifstream openReadFile(string fileName) {
		ifstream inFile;
		inFile.open(fileName);
		return inFile;
	}

	// openWriteFile: open a file with the passed in file name for writing - return the ofstream object
	ofstream openWriteFile(string fileName) {
		ofstream outFile;
		outFile.open(fileName);
		return outFile;
	}

	// encryptChar: encrypt a particular character given the keyCharacter passed to it
	char encryptChar(char c, char keyC) {
		int shift = 0;
		switch (keyC) {
		case 'a':
			shift = 1;
			break;
		case 'b':
			shift = 2;
			break;
		case 'c':
			shift = 3;
			break;
		case 'd':
			shift = 4;
			break;
		case 'e':
			shift = 5;
			break;
		case 'f': 
			shift = 6;
			break;
		case 'g':
			shift = 7;
			break;
		case 'h':
			shift = 8;
			break;
		case 'i':
			shift = 9;
			break;
		case 'j': 
			shift = 10;
			break;
		case 'k':
			shift = 11;
			break;
		case 'l':
			shift = 12;
			break;
		case 'm':
			shift =13;
			break;
		case 'n':
			shift = 14;
			break;
		case 'o':
			shift = 15;
			break;
		case 'p':
			shift = 16;
			break;
		case 'q':
			shift = 17;
			break;
		case 'r':
			shift = 18;
			break;
		case 's':
			shift = 19;
			break;
		case 't':
			shift = 20;
			break;
		case 'u':
			shift = 21;
			break;
		case 'v':
			shift = 22;
			break;
		case 'w':
			shift = 23;
			break;
		case 'x':
			shift = 24;
			break;
		case 'y':
			shift = 25;
			break;
		default:
			shift = 0;
			break;
		}
		c = toupper(c);
		for (int i = 0; i < shift; i++) {
			if (c == 'Z')
				c = 'A';
			else 
				c++;
		}
		return c;
	}

	// decryptChar: decrypt a particular character given the keyCharacter passed to it
	char decryptChar(char c, char keyC) {
		int shift = 0;
		switch (keyC) {
		case 'a':
			shift = 1;
			break;
		case 'b':
			shift = 2;
			break;
		case 'c':
			shift = 3;
			break;
		case 'd':
			shift = 4;
			break;
		case 'e':
			shift = 5;
			break;
		case 'f': 
			shift = 6;
			break;
		case 'g':
			shift = 7;
			break;
		case 'h':
			shift = 8;
			break;
		case 'i':
			shift = 9;
			break;
		case 'j': 
			shift = 10;
			break;
		case 'k':
			shift = 11;
			break;
		case 'l':
			shift = 12;
			break;
		case 'm':
			shift =13;
			break;
		case 'n':
			shift = 14;
			break;
		case 'o':
			shift = 15;
			break;
		case 'p':
			shift = 16;
			break;
		case 'q':
			shift = 17;
			break;
		case 'r':
			shift = 18;
			break;
		case 's':
			shift = 19;
			break;
		case 't':
			shift = 20;
			break;
		case 'u':
			shift = 21;
			break;
		case 'v':
			shift = 22;
			break;
		case 'w':
			shift = 23;
			break;
		case 'x':
			shift = 24;
			break;
		case 'y':
			shift = 25;
			break;
		default:
			shift = 0;
			break;
		}
		c = toupper(c);
		for (int i = 0; i < shift; i++) {
			if (c == 'A')
				c = 'Z';
			else 
				c--;
		}
		return c;
	}
public:
	// constructor
	encryption() {
	}

	/* encrypt: Encrypt given file and create a new encrypted file w/ same filename + "_encrypted.txt" extension
	*/
	void encrypt(string fileName, string key) {
		int keyLength = 0;
		// keyLength = # of letters in key string passed into function
		for (int i = 0; i < key.size(); i++) {
			if (isalpha(key[i]))
				keyLength++;
		}
		char* cipherKey = new char[keyLength];
		int keyPosition = 0;
		// fill cipherKey (char array) w/ lower-case letters of key
		for (int i = 0; i < key.size(); i++) {
			if (isalpha(key[i])) {
				cipherKey[keyPosition] = tolower(key[i]);
				keyPosition++;
			}
		} 
		keyPosition = 0;
		//open input file and create and open output file
		ifstream inFile = openReadFile(fileName);
		string outFileName = fileName.substr(0,fileName.size() - 4) + "_encrypted.txt";
		ofstream outFile = openWriteFile(outFileName);
		char c;
		while (inFile.get(c)) {
			if (isalpha(c)) {
				c = encryptChar(c, cipherKey[keyPosition++]);
				if (keyPosition == keyLength)
					keyPosition = 0;
			} 
			outFile << c;
		} 
		outFile.close();
		inFile.close();
	}

	/* decrypt:	Decrypt the given file and create the decrypted file w/ the same filename - "_decrypted.txt" extension
	*/
	void decrypt(string fileName, string key) {
		int keyLength = 0;
		// keyLength = # of letters in key string passed into function
		for (int i = 0; i < key.size(); i++) {
			if (isalpha(key[i]))
				keyLength++;
		}
		char* cipherKey = new char[keyLength];
		int keyPosition = 0;
		// fill cipherKey (char array) w/ lower-case letters of key
		for (int i = 0; i < key.size(); i++) {
			if (isalpha(key[i])) {
				cipherKey[keyPosition] = tolower(key[i]);
				keyPosition++;
			}
		}
		keyPosition = 0;
		//open input file and create and open output file
		ifstream inFile = openReadFile(fileName);
		string outFileName = fileName.substr(0,fileName.size() - 14) + "_decrypted.txt";
		ofstream outFile = openWriteFile(outFileName);
		char c;
		while (inFile.get(c)) {
			if (isalpha(c)) {
				c = decryptChar(c, cipherKey[keyPosition++]);
				if (keyPosition == keyLength)
					keyPosition = 0;
			}
			outFile << c;
		}
		outFile.close();
		inFile.close();
	}
};
#endif