#ifndef EuclidesAlgorithm
#define EuclidesAlgorithm

unsigned int euclidesDefault(unsigned int n1, unsigned int n2) {
    unsigned int res = n1 % n2;
    
    if(res == 1) return res;// Poupa +1 chamada desnecessária
    if(res == 0) return n2; // retorna o divisor

    return euclidesDefault(n2, res);
}

unsigned int euclidesExtended(unsigned int n1, unsigned int n2, unsigned int &s, unsigned int &t) {
    s = 1;
    t = 0;

    unsigned int newS = 0, newT = 1;
    unsigned int aux, q;

    do {
        q = (int) n1 / n2;

        aux = s-(newS * q);
        s = newS;
        newS = aux;

        aux = t-(newT * q);
        t = newT;
        newT = aux;

        aux = n1 % n2;

        if(aux == 0) return n2;

        n1 = n2;
        n2 = aux; 

    } while(true);
}

#endif