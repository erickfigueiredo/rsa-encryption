#include <iostream>
#include "PrimeGenerator.h"
#include "EuclidesAlgorithm.h"
#include "KeysGenerator.h"

using namespace std;

// Pensei em armazenar em um MAP key = letra value = cod
//A -> 00
//  ...
//Z -> 25
int main() {
    srand(time(0));

    genKeys();

    return 0;
}

