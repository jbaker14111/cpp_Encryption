// <Lab 5 - Pointer Assignment - Josiah Baker> -- encrypts and decrypts file provided by user
//CSIS 112-<D01>
/*REFERENCES

Williams, W. (n.d.).C++ Programming: Class Composition Assignment.Canvas.Retrieved
November 22, 2022, from https://libertyuniversity.instructure.com/courses/346823/assignments/6099827?module_item_id=41307137

c++ - How to read a file line by line or a whole text file at once? (n.d.). Stack Overflow. Retrieved 
December 1, 2022, from https://stackoverflow.com/questions/13035674/how-to-read-a-file-line-by-line-or-a-whole-text-file-at-once

strtok_s, _strtok_s_l, wcstok_s, _wcstok_s_l, _mbstok_s, _mbstok_s_l. (2022, October 26). 
Learn.microsoft.com. https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strtok-s-strtok-s-l-wcstok-s-wcstok-s-l-mbstok-s-mbstok-s-l?redirectedfrom=MSDN&view=msvc-170

toupper. (2022). Cplusplus.com. https://cplusplus.com/reference/cctype/toupper/‌‌

*/
/*
This program asks user if they want to encrypt or decrypt file. For either choice, the are asked to enter the name of the file
to encrypt/decrypt. Then asked what the key for encrypting or decrypting the file is, then asks for a name for the new file that 
the results will be printed to. The user has an option to end the program as well
*/

#include <iostream>
#include <vector>
#include <string>
#include "./Headers/MyText.h"
#include <iomanip>
#include <string.h>
#include <fstream>

using namespace std;

void encryptFile();//function to encrypt the file the user chooses
void decryptFile();//function to decrypt the file the user chooses
void returnFileName(string& fileName);//function to get the file name with error checking
int selectionMenu();//function to print the function menu, and return the user's choice


int main() {//main will run a while loop until the user has entered 3 as their selection on the menu screen. otherwise
	//user continues to encrypt/decrypt files 

	char** input = NULL;


	bool running = true;
	
	while (running) {
		system("cls");
		int mode = selectionMenu();
		switch (mode) {
		case 1:
			encryptFile();
			break;
		case 2:
			decryptFile();
			break;
		case 3:
			running = false;
			cout << endl << endl << "PROGRAM STOPPING..." << endl << endl;
			break;
		}

	}
	system("pause");
	return 0;
}
int selectionMenu() {//prints selection menu and gets user's selection with error handling. takes inputs 1-3
	int selection;
	cout << setw(20) << "Vigenere Cypher" << endl << endl;
	cout << setw(16) << "Main Menu" << endl << endl;
	cout << "1 - Encrypt File" << endl << endl << "2 - Decrypt File" << endl << endl << "3 - Quit Program" << endl << endl;
	cout << "Selection: ";
	cin >> selection;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (cin.fail()) {
		cout << endl << endl << "A number was not entered. Please try again." << endl << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("pause");
		system("cls");
		selectionMenu();//recursively runs until an allowed input is entered
	}
	else if (selection < 1 || selection > 3) {
		cout << endl << endl << "Number entered was not one of the options(1, 2, or 3). Please try again." << endl << endl;
		
		system("pause");
		system("cls");
		selectionMenu();//recursively runs until an allowed input is entered
	}
	else {
		return selection;//returns selection to be used in main
	}
	return 0;
}
void encryptFile(){//code to encrypt file of the user's choice then puts the encrypted information in a new file the user creates and names
	char* str;
	str = new char[1000];
	string fileName;
	system("cls");
	returnFileName(fileName);
	ifstream inFile;
	inFile.open(fileName);
	inFile.getline(str, 1000);
	inFile.close();
	cout << "Enter key: ";
	string key;
	getline(cin, key);
	MyText text(key);
	cout << endl << endl << "Enter new file name: ";
	string newFile;
	getline(cin, newFile);
	ofstream outFile;
	text.FileCreate(outFile, newFile);
	char* token = NULL;
	char* nextToken = NULL;
	char delim[] = " -., \t\n";
	token = strtok_s(str, delim, &nextToken);
	while (!(token == NULL)) {
		string encryptedWord = text.encryptWord(token);
		outFile << encryptedWord << " ";
		token = strtok_s(NULL, delim, &nextToken);
	}
	text.DisplayText();
	cout << endl << endl << "Words encrypted: " << text.getWordsEncrypted() << endl << endl;
	system("pause");
	outFile.close();
}
void decryptFile() {//code to decrypt file of the user's choice then puts the decrypted information in a new file the user creates and names
	char* str;
	str = new char[1000];
	string fileName;
	system("cls");
	returnFileName(fileName);
	ifstream inFile;
	inFile.open(fileName);
	inFile.getline(str, 1000);
	inFile.close();
	cout << "Enter key: ";
	string key;
	getline(cin, key);
	MyText text(key);
	cout << endl << endl << "Enter new file name: ";
	string newFile;
	getline(cin, newFile);
	ofstream outFile;
	text.FileCreate(outFile, newFile);
	char* token = NULL;
	char* nextToken = NULL;
	char delim[] = " ";
	token = strtok_s(str, delim, &nextToken);
	while (!(token == NULL)) {
		string decryptedWord = text.decryptWord(token);
		outFile << decryptedWord << " ";
		token = strtok_s(NULL, delim, &nextToken);
	}
	text.DisplayText();
	cout << endl << endl << "Words decrypted: " << text.getWordsDecrypted() << endl << endl;
	system("pause");
	outFile.close();
}


void returnFileName(string& fileName) {//returns file name after checking for errors in user input
	ifstream inFile;
	cout << "Enter file name: ";
	getline(cin, fileName);
	cout << endl << endl;
	inFile.open(fileName);
	if (inFile.fail()) {
		cout << "We could not find a file with that name. Please try again." << endl;
		
		returnFileName(fileName);
	}
	inFile.close();
}