#include <iostream>
#include <fstream>
#include "Morse.h"
string engToMorse(const MorseCode& translator) {
	string output;
	string input;
	getline(cin, input);
	for(int i = 0; i < input.length(); i++) {
		output += translator.enCode(input[i]);
	}
	return output;
}
string morseToEng(const MorseCode& translator, string input="") {
	string output;
	if(input == "")
		getline(cin, input);
	int pos = 0;
	string morse = "";
	bool spaceAdded = false;
	while(pos < input.length()) {
		while(!isspace(input[pos]) && pos < input.length()) {
			spaceAdded = false;
			morse += input[pos];
			pos++;
		}
		if(morse != "") {
			output += translator.deCode(morse);
		} else if (morse == "" && !spaceAdded) {
			output += " ";
			spaceAdded = true;
		}
		morse = "";
		pos++;
	}
	return output;
}
void writeToFile(const MorseCode& translator) {
	ofstream outputFile("morse_code.txt", ofstream::out);
	cout << "Please enter a sentence to be translated into morse code and written to a file" << endl << ">";
	outputFile << engToMorse(translator) + "   ";
	outputFile.close();
}
string readFromFile(const MorseCode& translator) {
	ifstream inputFile ("morse_code.txt", ifstream::in);
	string output;
	output = "";
	char c;
	c = inputFile.get();
	while (inputFile.good()) {
		output += c;
		c = inputFile.get();
	}
	return output;
}
int main() {
	MorseCode translator;
	while(1) {
		cout << "Would you like to \n 1) Translate english to morse code \n 2) Translate morse code to english \n 3) Write morse code to a file \n 4) Read morse code from a file \n 0) Quit the program." << endl << ">";
		int a;
		cin >> a;
		cin.ignore();
		switch(a) {
			case 1:
				cout << "Please enter a sentence to be translated into morse code" << endl << ">";
				cout << "The translated sentence reads:" << endl << endl << engToMorse(translator) << endl << endl;
				break;
			case 2:
				cout << "Please enter morse code to be translated into english" << endl << ">";
				cout << "The translated morse code reads: " << morseToEng(translator) << endl << endl;
				break;
			case 3:
				writeToFile(translator);
				cout << "Morse code written successfully!" << endl << endl;
				break;
			case 4:
				cout << "The translated morse code inside the file reads:" << endl << endl << morseToEng(translator,readFromFile(translator)) << endl << endl;
				break;
			case 0: 
				cout << "Goodbye!" << endl;
				return 0;
			}
	}
	return 0;
}
