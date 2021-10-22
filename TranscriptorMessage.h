#ifndef TRANSCRIPTOR_MESSAGE
#define TRANSCRIPTOR_MESSAGE

#include <map>
#include <string>

using namespace std;

string encode(const string& entry) {
    map <char, string> alphabet = { {'A', "00"}, {'B', "01"}, {'C', "02"}, {'D', "03"}, {'E', "04"}, {'F', "05"}, {'G', "06"},
        {'H', "07"}, {'I', "08"}, {'J', "09"}, {'K', "10"}, {'L', "11"}, {'M', "12"}, {'N', "13"}, {'O', "14"}, {'P', "15"},
        {'Q', "16"}, {'R', "17"}, {'S', "18"}, {'T', "19"}, {'U', "20"}, {'V', "21"}, {'W', "22"}, {'X', "23"}, {'Y', "24"},
        {'Z', "25"} };

    map<char, string>::iterator it;

    string encodedEntry;

    for (char word : entry) {
        it = alphabet.find(word);

        if (it != alphabet.end()) encodedEntry += it->second;
    }

    if (encodedEntry.length()) return encodedEntry;

    return entry;
}

string decode(const string& entry) {
    map <string, char> alphabet = {{"00", 'A'}, {"01", 'B'}, {"02", 'C'}, {"03", 'D'}, {"04", 'E'}, {"05", 'F'}, {"06", 'G'},
        {"07", 'H'}, {"08", 'I'}, {"09", 'J'}, {"10", 'K'}, {"11", 'L'}, {"12", 'M'}, {"13", 'N'}, {"14", 'O'}, {"15", 'P'},
        {"16", 'Q'}, {"17", 'R'}, {"18", 'S'}, {"19", 'T'}, {"20", 'U'}, {"21", 'V'}, {"22", 'W'}, {"23", 'X'}, {"24", 'Y'},
        {"25", 'Z'}};

    map<string, char>::iterator it;

    string decodedEntry;

    // Fazemos a decodificação da mensagem;

    return decodedEntry;
}

#endif
