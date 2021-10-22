#ifndef PRIME_GENERATOR
#define PRIME_GENERATOR

#include <cmath>
#include <ctime>
#include <cstdlib>

#include "ModularPower.h"

#include <iostream>

using namespace std;

// Gerador de números pseudo-aleatórios (restrito a 32 bits signed)
int genRandomNumberOfNBits(int n) {
    int min = pow(2, n - 2) + 1;
    min *= 1.2; // Vamos aumentar o mínimo em 20% reduzindo o intervalo
    int range = pow(2, n-1) - 1 - min;

    return (rand() % range+1) + min;
}

/*
* Aplicação do Pequeno Teorema de Fermat
* utilizando p como o pseudoprimo gerado e a como os primos conhecidos até 659,
* pois se dois números são primos também são coprimos, o contrário não é verdadeiro.
*/
bool verifyPrime(int possiblePrime) {
    unsigned int initialPrimes[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,
    59,61,67,71, 73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,
    163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,
    269,271,277,281, 283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,
    383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,
    499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,
    619,631,641,643,647,653,659 };

    int primesLength = sizeof(initialPrimes) / sizeof(int);
    long long a;

    for (int i = 0; i < primesLength; i++) {
        a = modPow(initialPrimes[i], possiblePrime - 1, possiblePrime);

        if (a != 1) return false;
    }

    return true;
}

// Retorna um número de n bits que provavelmente é primo
int genPrimeOfNBits(int n) {
    long long num;

    do {
        num = genRandomNumberOfNBits(n);
    } while (!verifyPrime(num));

    return num;
}

#endif
