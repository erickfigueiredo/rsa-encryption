// Algoritmo recursivo para calcular Exponenciação Modular Rápida  
// Baseado em algoritmo disponível em: https://blog.emptyq.net/base?id=00012-cfb2d726-e395-41ed-base840-0401bfb4f0be


// Terminar de comentar o código
unsigned int exponentMod(unsigned int base, unsigned int exp,  unsigned int mod) {
    // Casos base
    if (base == 0) return 0;
    if (exp == 0) return 1;

    unsigned long long step;
    
    if (exp % 2 == 0) {
        step = exponentMod(base, exp / 2, mod);
        step = (step * step) % mod;
    } else {
        step = base % mod;
        step = (step * exponentMod(base, exp - 1, mod) % mod) % mod;
    }

    return (unsigned int)((step + mod) % mod);
}
