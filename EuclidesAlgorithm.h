#ifndef EUCLIDES_ALGORITHM
#define EUCLIDES_ALGORITHM

long long euclidesDefault(long long n1, long long n2) {
    if(!n2) return 1;
    
    long long res = n1 % n2;

    if (res == 1) return res;// Poupa +1 chamada desnecessária
    if (res == 0) return n2; // retorna o divisor

    return euclidesDefault(n2, res);
}

long long euclidesExtended(long long n1, long long n2, long long& s, long long& t) {
    s = 1;
    t = 0;

    long long newS = 0, newT = 1;
    long long aux, q;

    do {
        q = (long long)n1 / n2;

        aux = s - (newS * q);
        s = newS;
        newS = aux;

        aux = t - (newT * q);
        t = newT;
        newT = aux;

        aux = n1 % n2;

        if (aux == 0) return n2;

        n1 = n2;
        n2 = aux;

    } while (true);
}

#endif
