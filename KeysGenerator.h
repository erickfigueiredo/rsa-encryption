#include "PrimeGenerator.h"

int genKeys() {

    // Teremos dois números 2^32 => (2^32)^2 => 2^64, teremos um número de 64 bits
    // n =  p * q
    unsigned int p = genPrimeOfNBits(32);
    unsigned int q = genPrimeOfNBits(32);

    long long n = p * q ;

    // fi = (p-1)(q-1)
    long long fi = (p-1)*(q-1);

    // temos que gerar um e, de modo que mdc (e, fi) = 1
    // Podemos gerar números aleatórios até que um satisfaça a condição acima

    // Encontrar d com d e = 1(mod fi) (dificil e chato)

    return 0; 
}