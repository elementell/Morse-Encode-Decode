#ifndef _MORSE_H
#define _MORSE_H 3710201612

#define MORSE_SET 45

#include <string>
#include <unordered_map>

using namespace std;

class MorseCode
{
  public:
    MorseCode ();

    string enCode(const char&) const;
    char   deCode(const string&) const;

  private:
    unordered_map<char,string> encodeMap;
    unordered_map<string,char> decodeMap;
};

#endif

