#include "Morse.h"

MorseCode::MorseCode() {
	char morseLookup[]={' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9','0','.',',',':','-','\'','/','?','_'};
	string characterLookup[]={"   ",".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",".----","..---","...--","....-",".....","-....","--...","---..","----.","-----",".-.-.-","--..--","---...","-....-",".----.","-..-.","..--..","-...-"};
	for(int i = 0; i < 45; i++) {
		decodeMap[characterLookup[i]] = morseLookup[i];
		encodeMap[morseLookup[i]] = characterLookup[i];
	}
}

string MorseCode::enCode(const char& c) const {
	unordered_map<char,string>::const_iterator pair;
	pair = encodeMap.find(toupper(c));
	return (pair->second) + " ";
}
char MorseCode::deCode(const string& s) const {
	unordered_map<string,char>::const_iterator pair;
	pair = decodeMap.find(s);
	return pair->second;
}
