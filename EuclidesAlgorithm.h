// Desenvolver os dois Algorimos de Euclides

// Para n1 > n2
int euclidesDefault(unsigned int n1, unsigned int n2) {
    unsigned int res = n1%n2;
    
    if(res == 1) return res;// Poupa +1 chamada desnecessária
    if(res == 0) return n2; // retorna o divisor

    return euclidesDefault(n2, res);
}

int euclidesExtended(int n1, int n2) {
    
    return 0;
}
