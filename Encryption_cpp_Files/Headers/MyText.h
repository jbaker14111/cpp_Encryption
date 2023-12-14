//Class that encrypts and decrypts a char pointer variable word and stores it in a string array. returns the encrypted/decrypted word as well

#ifndef MyTextH
#define MyTextH

#include <vector>
#include <string>
#include "Vigenere.h"
#include <fstream>
#include <iostream>
#include <limits>

class MyText {
	
public:

	MyText(std::string k = "");
	//default constructor
		
	std::string encryptWord(char* token);
	//function that encrypts the word contained in the character pointer array variable and then returns it

	std::string decryptWord(char* token);
	//function that decrypts the word contained in the character pointer array variable and then returns it

	void FileCreate(std::ofstream& outFile, std::string fileName);
	//function that creates a file with the name fileName
	//Postcondition: NEW FILE = fileName

	void DisplayText() const;
	//function that prints words encrypted/decrypted

	void setWordsEncrypted(int value);
	//function that sets the value of the words encrypted value
	//Postcondition: wordsEncrypted = value

	int getWordsEncrypted() const;
	//function that returns the integer value of wordsEncrypted

	void setWordsDecrypted(int value);
	//function that sets the value of the words decrypted value
	//Postcondition: wordsDecrypted = value

	int getWordsDecrypted() const;
	//function that returns the integer value of wordsDecrypted

	void IncWordsEncrypted();
	//function that increments words encrypted value
	//Postcondition: wordsEncrypted++

	void IncWordsDecrypted();
	//function that increment words decrypted value
	//Postcondition: wordsDecrypted++

private:
	int wordsEncrypted = 0;//integer variable that stores ammount of words encrypted
	int wordsDecrypted = 0;//integer variable that stores ammount of words decrypted
	std::vector<std::string> words;//vector variable of type string that stores words encrypted/decrypted
	Vigenere v;//Vigenere variable that stores the key and contains the functions for computing the encryption/decryption
};


#endif