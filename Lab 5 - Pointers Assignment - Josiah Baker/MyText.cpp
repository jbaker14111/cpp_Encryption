//Class that encrypts and decrypts a char pointer variable word and stores it in a string array. returns the encrypted/decrypted word as well
#include "MyText.h"

using namespace std;

MyText::MyText(string k){//default constructor. sets the key for Vigenere Cypher to k
	v.setKey(k);
}

std::string MyText::encryptWord(char* token) {//encrypts the character pointer variable word then stores it and returns it
	string word = token;
	word = v.encrypt(word);
	words.push_back(word);
	IncWordsEncrypted();
	return word;
}

std::string MyText::decryptWord(char* token) {//decrypts the character pointer variable word then stores it and returns it
	string word = token;
	word = v.decrypt(word);
	words.push_back(word);
	IncWordsDecrypted();
	return word;

}

void MyText::FileCreate(std::ofstream& outFile, string fileName) {//creates a new file with the name of fileName
	outFile.open(fileName);
}

void MyText::DisplayText() const {//displays the words encrypted/decrypted 
	for (string word : words) {
		cout << word << " ";
	}
}

void MyText::setWordsEncrypted(int value) {//sets the value of wordsEncrypted to the integer value entered
	wordsEncrypted = value;
}

int MyText::getWordsEncrypted() const {//returns the integer of the wordsEncrypted value
	return wordsEncrypted;
}

void MyText::setWordsDecrypted(int value) {//sets the value of wordsDecrypted to the integer value entered
	wordsDecrypted = value;
}

int MyText::getWordsDecrypted() const{//returns the integer of the wordsDecrypted value
	return wordsDecrypted;
}

void MyText::IncWordsEncrypted() {//increments words encrypted count
	wordsEncrypted++;
}

void MyText::IncWordsDecrypted() {//increments words decrypted count
	wordsDecrypted++;
}