#ifndef VignereH
#define VignereH

//class that manages the vigenere cypher functions to be used by the MyText class. has functions to set key, encrypt and decrypt words

#include <string>

class Vigenere {

public:

	Vigenere(std::string k = "");
	//default constructor
	//Postcondition: key = k

	void setKey(std::string k);
	//function that sets the key for the Vigenere Cypher
	//Postcondition: key = k

	std::string getKey() const;
	//function that returns the key for the vigenere cypher

	std::string toUpperCase(std::string k);
	//function that turns the string passed as a parameter to upper case and returns it

	std::string encrypt(std::string word);
	//function that encrypts the string parameter passed using Vigenere Cypher and key

	std::string decrypt(std::string word);
	//function that decrypts the string parameter passed using Vigenere Cypher and key

private:

	std::string key;//string variable that holds the key for the Vigenere Cypher

};

#endif