#ifndef MODULAR_POWER
#define MODULAR_POWER
// Algoritmo recursivo para calcular Exponenciação Modular Rápida  
// Baseado em algoritmo disponível em: https://blog.emptyq.net/base?id=00012-cfb2d726-e395-41ed-base840-0401bfb4f0be

// Terminar de comentar o código
long long modPow( long long base, long long exp, long long mod) {
    // Casos base
    if (base == 0) return 0;
    if (exp == 0) return 1;

    long long step;
    
    if (exp % 2 == 0) {
        step = modPow(base, exp / 2, mod);
        step = (step * step) % mod;
    } else {
        step = base % mod;
        step = (step * modPow(base, exp - 1, mod) % mod) % mod;
    }

    return ((step + mod) % mod);
}

#endif
