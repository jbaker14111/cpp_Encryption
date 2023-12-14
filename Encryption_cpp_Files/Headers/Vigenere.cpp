//class that manages the vigenere cypher functions to be used by the MyText class. has functions to set key, encrypt and decrypt words

#include "Vigenere.h"
#include <iostream>

using namespace std;

Vigenere::Vigenere(string k) {//default constructor/constructor with one parameter
	k = toUpperCase(k);
	key = k;
}
void Vigenere::setKey(string k) {//sets key for the vigenere cypher to the first parameter after converting all letters to upper case
	key = toUpperCase(k);

}
string Vigenere::getKey() const {//returns the key for the vigenere cypher
	return key;
}
string Vigenere::toUpperCase(std::string k){//capitalizes all text in a string
	for (int x = 0; x < k.size(); x++) {
		k[x] = toupper(k[x]);
	}
	return k;
}
string Vigenere::encrypt(std::string word) {//encrypts word string using Vigenere Cypher and the key provided, then returns it
	string output;
	for (int i = 0, j = 0; i < word.length(); ++i) {
		char c = word[i];
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;
		output += (c + key[j] - 2 * 'A') % 26 + 'A'; //added 'A' to bring it in range of ASCII alphabet[65 - 90 | A - Z]
			j = (j + 1) % key.length();
	}
	return output;
}

string Vigenere::decrypt(std::string word) {//decrypts word string using Vigenere Cypher and the key provided, then returns it
	string output;
	for (int i = 0, j = 0; i < word.length(); ++i) {
		char c = word[i];
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;
		output += (c - key[j] + 26) % 26 + 'A';//added 'A' to bring it in range of ASCII alphabet[65 - 90 | A - Z]
			j = (j + 1) % key.length();
	}
	return output;
}