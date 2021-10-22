#ifndef KeysGenerator
#define KeysGenerator

#include "PrimeGenerator.h"
#include "EuclidesAlgorithm.h"

#include <iostream>

int genKeys() {

    // Teremos dois números 2^32 => (2^32)^2 => 2^64, teremos um número de 64 bits
    unsigned int p = genPrimeOfNBits(32);
    unsigned int q = genPrimeOfNBits(32);

    unsigned long long n = (unsigned long long)p * q ;
    unsigned long long fi = (unsigned long long)(p-1)*(q-1);


    std::cout << p << " " << q << " " << n << " " << fi;

    // temos que gerar um e, de modo que mdc (e, fi) = 1 
    unsigned int e;

    do{
        // Gera números até que encontre um coprimo à fi
        e = genRandomNumberOfNBits(20); // Não sei se precisa ser de 32 bits 
    }while(euclidesDefault(fi, e) != 1);

    // Calcular o inverso de e mod fi (euclides estendido)



    // Encontrar d com d e = 1(mod fi) (dificil e chato)

    return 0; 
}

#endif
