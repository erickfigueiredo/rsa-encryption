#include <iostream>
#include <vector>
#include<string>

#include "KeysGenerator.h"
#include "ModularPower.h"
#include "TranscriptorMessage.h"

#include "PrimeGenerator.h"

using namespace std;

void encoding();
void decoding();
void sign();
void validateSign();

int main() {
     //Inicializa a semente da função aleatória
    srand(time(0));

    cout << "Ola, escolha a operacao desejada:\n\n";
    cout << "1) Codificacao\n";
    cout << "2) Decodificacao\n";
    cout << "3) Assinar mensagem\n\n";
    cout << "4) Verificar assinatura\n\n";

    int option;
    cin >> option;

    switch (option){
        case 1:
            encoding();
            break;
        case 2:
            decoding();
            break;
        case 3:
            sign();
            break;
        case 4:
            validateSign();
            break;
    }

    return 0;
}

void encoding(){
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
    cout << enc << endl;
    // Mensagem entry é criptografada
    for (int i = 0; i < enc.length(); i += 2) {
        aux += enc[i];
        aux += enc[i + 1];

        msgInRSA.push_back(modPow(stoi(aux), e, n));

        aux = "";
    }

    // Apenas demonstrativo
    cout << "Mensagem criptografada: ";
    for(const long long num: msgInRSA) cout << num << " ";
    cout << endl;

    // Mensagem é descriptografada 
    for (auto num : msgInRSA) {
        msgReversed.push_back(modPow(num, d, n));
    }

    // Decodames a mensagem
    cout << "Mensagem descriptografada: " << decode(msgReversed) << endl; 
}

void decoding(){
    long long d, n;
    vector<long long> msg;
    vector<int> msgReversed;

    string entry;
    cout << "Informe a mensagem criptografada separando as cifras por espaço, para finalizar a entrada digite -1: ";
    while(cin >> entry && entry != "-1"){
        msg.push_back(stoi(entry));
    }

    cout << "Informe a chave privada: ";
    cin >> d;

    cout << "informe o N: ";
    cin >> n;

    for (auto num : msg) {
        msgReversed.push_back(modPow(num, d, n));
    }

    // Decodames a mensagem
    cout << "Mensagem descriptografada: " << decode(msgReversed) << endl; 
}

void sign(){
    string entry, aux;

    long long n, d;
    vector<long long> msgInRSA;
    vector<int> msgReversed;

    cout << "Informe a mensagem: ";
    cin >> entry;

    cout << "Informe a chave privada para assinar: ";
    cin >> d;

    cout << "Informe o N para assinar: ";
    cin >> n;

    string enc = encode(entry);
    cout << enc << endl;

    // Mensagem enc é assinada
    long long signature = modPow(stoi(enc), d, n);

    cout << "Assinatura: " << signature << endl;
    
}

void validateSign(){
    string entry, sign;

    long long n, e, d;

    cout << "Informe a mensagem esperada: ";
    cin >> entry;

    cout << "Informe a mensagem assinada: ";
    cin >> sign;

    cout << "Informe o e para verificar a procedencia: ";
    cin >> e;
    cout << "Informe o n para verificar a procedencia: ";
    cin >> n;

    string hash = encode(entry);
    cout << "hash " << hash << endl;
    // Mensagem entry é assinada
    long long hashSign = modPow(stoi(sign), e, n);
    //string r = decode()

    cout << "hashSign " << hashSign << endl;

    cout << "Assinatura valida: " << (hash == to_string(hashSign)) ? "Sim!" : "Nao";
}