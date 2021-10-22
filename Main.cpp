#include <iostream>

#include "KeysGenerator.h"
#include "TranscriptorMessage.h"

using namespace std;

int main() {
    //Inicializa a semente da função aleatória
    srand(time(0));

    string entry;
    cin >> entry;

    cout << encode(entry) << endl;

    //genKeys();

    return 0;
}

