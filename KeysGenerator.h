#ifndef KeysGenerator
#define KeysGenerator

#include "PrimeGenerator.h"
#include "EuclidesAlgorithm.h"

#include <iostream>

int genKeys() {

    // Teremos dois números 2^32 => (2^32)^2 => 2^64, teremos um número de 64 bits
    unsigned int p = genPrimeOfNBits(32);
    unsigned int q = genPrimeOfNBits(32);
    unsigned long long s, t;

    unsigned long long n = (unsigned long long) p * q ;
    unsigned long long fi = (unsigned long long) (p-1) * (q-1);

    std::cout << "p: " << p << " q:" << q << " n:" << n << " fi:" << fi << std::endl;

    // temos que gerar um e, de modo que mdc (e, fi) = 1 
    unsigned int e;

    do{
        // Gera números até que encontre um coprimo à fi
        e = genRandomNumberOfNBits(32); // Não sei se precisa ser de 32 bits 
    }while(euclidesDefault(fi, e) != 1); // Pode mudar para extended

    // Calcular o inverso de e mod fi (euclides estendido)
    euclidesExtended(e, fi, s, t);

    // d é o coeficiente de bézout de e, no caso s
    std::cout << "s: " << s << " t: " << t << std::endl;
    if(s < 0) s += fi;

    // d é a chave publica

    return 0; 
}

#endif
