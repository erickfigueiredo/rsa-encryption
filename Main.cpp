#include <iostream>
#include <vector>

#include "KeysGenerator.h"
#include "ModularPower.h"
#include "TranscriptorMessage.h"

using namespace std;

int main() {
    //Inicializa a semente da função aleatória
    srand(time(0));

    string entry, aux;

    long long n, e, d, cod;
    vector<long long> msgInRSA;
    vector<int> msgReversed;

    cout << "Informe a mensagem: ";
    cin >> entry;

    // Gera as chaves e atribui para os valores passados por referência
    genKeys(n, e, d);
    // Pega a string retornada e devolve encodada

    string enc = encode(entry);

    // Mensagem entry é criptografada
    for (int i = 0; i < enc.length(); i += 2) {
        aux += enc[i];
        aux += enc[i + 1];

        msgInRSA.push_back(exponentMod(stoi(aux), e, n));

        aux = "";
    }

    // Apenas demonstrativo
    cout << "Mensagem criptografada: ";
    for(const long long num: msgInRSA) cout << num;
    cout << endl;

    // Mensagem é descriptografada 
    for (auto v : msgInRSA) {
        msgReversed.push_back(exponentMod(v, d, n));
    }

    // Decodames a mensagem
    cout << "Mensagem descriptografada: " << decode(msgReversed) << endl;
    return 0;
}

