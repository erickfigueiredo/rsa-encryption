#ifndef KEYS_GENERATOR
#define KEYS_GENERATOR

#include "PrimeGenerator.h"
#include "EuclidesAlgorithm.h"

#include <iostream>

void genKeys(long long& a, long long& b, long long& c) {

    // Teremos dois números, variando de 2^(n-2)+1 à 2^(n-1)-1
    int p = genPrimeOfNBits(17);
    int q = genPrimeOfNBits(16);
    long long s, t;

    long long n = p * q;
    long long fi = (p - 1) * (q - 1);

    // temos que gerar um e, de modo que mdc (e, fi) = 1 
    int e;

    do {
        // Gera números até que encontre um coprimo à fi
        e = genRandomNumberOfNBits(18);
    } while (euclidesExtended(e, fi, s, t) != 1);

    // d é o coeficiente de bézout de e, no caso s
    if (s < 0) s += fi;

    std::cout << "Chave Publica  n:" << n << " e:" << e << std::endl;
    std::cout << "Chave Privada d: " << s << std::endl;

    //Retornamos os valores na referencia para evitar retornar um array
    a = n;
    b = e;
    c = s;
}

#endif
