#include <iostream>
#include "PrimeGenerator.h"
#include "EuclidesAlgorithm.h"
#include "KeysGenerator.h"

#include <string>
#include <map>

using namespace std;

string encode(const string& entry) {
    map <char, string> alphabet = {{'A', "00"}, {'B', "01"}, {'C', "02"}, {'D', "03"}, {'E', "04"}, {'F', "05"}, {'G', "06"},
        {'H', "07"}, {'I', "08"}, {'J', "09"}, {'K', "10"}, {'L', "11"}, {'M', "12"}, {'N', "13"}, {'O', "14"}, {'P', "15"},
        {'Q', "16"}, {'R', "17"}, {'S', "18"}, {'T', "19"}, {'U', "20"}, {'V', "21"}, {'W', "22"}, {'X', "23"}, {'Y', "24"}, 
        {'Z', "25"} };

    map<char, string>::iterator it ;

    string encodedEntry;

    for(char word : entry) {
        it = alphabet.find(word);

        if(it != alphabet.end()) encodedEntry += it->second;
    }
    
    if(encodedEntry.length()) return encodedEntry;
    
    return entry;
}

int main() {
    srand(time(0));

    string entry;
    cin >> entry;

    unsigned int msg = stoi(encode(entry));

    cout << msg << endl;
    return 0;
}

