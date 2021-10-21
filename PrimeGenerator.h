#include <ctime>
#include <cstdlib>
#include <cmath>

#include <iostream>

// Capaz de gerar números de até 32 bits
unsigned int genRandomNumberOfNBits(int n) {
    unsigned int min = pow(2, n - 1) + 1;
    unsigned int range = pow(2, n) - 1 - min;
    srand(time(NULL));

    unsigned int randomNumber = (rand() % min + 1) + range;

    return randomNumber%2 != 0 ? randomNumber : ++randomNumber ;
}

bool verifyPrime(unsigned int possiblePrime) {
    unsigned int initialPrimes[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,
    71, 73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,
    179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281 };

    int primesLength = sizeof(initialPrimes)/sizeof(int);

    for(int i = 0; i < primesLength; i++) {
        // Ver como foi aplicada a aritmética modular no teorema de fermat

        // Substituir pela condição do teste de fermat
        if(true) return false;
    }

    return true;
}

unsigned int genPrimeOfNBits(int n) {
    unsigned int num;

    do {
        num = genRandomNumberOfNBits(n);
    } while(!verifyPrime(num));   

    return num; 
}