#include <iostream>
#include <vector>
#include <string>

#include "KeysGenerator.h"
#include "ModularPower.h"
#include "TranscriptorMessage.h"
#include "PrimeGenerator.h"

using namespace std;

void encoding();
void encodingRead(long long &n, long long &e, long long &d);
void decoding();
void sign();
void validateSign();
void generateMessage();

int main()
{
    //Inicializa a semente da função aleatória
    srand(time(0));

    cout << "Ola, escolha a operacao desejada:\n\n1) Codificacao\n2) Decodificacao\n3) Assinar mensagem\n4) Verificar assinatura\n5) Gerar mensagem dado n, e\n\nOpcao: ";

    int option;
    cin >> option;

    switch (option)
    {
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
    case 5:
        generateMessage();
        break;
    }

    return 0;
}

void encoding()
{
    string entry, aux = "";
    long long n, e, d, cod;
    vector<long long> msgInRSA;
    vector<string> msgReversed;
    int blockLength = 0;
    int option;

    cout << "Gostaria de gerar n, e, d? 0) Nao - 1) Sim" << endl;
    cin >> option;

    switch (option)
    {
    case 1:
        genKeys(n, e, d);
        break;
    case 0:
        encodingRead(n, e, d);
        break;
    default:
        return;
        break;
    }

    while (stoll(aux + "25") < n)
    {
        blockLength++;
        aux += "25";
    }

    cout << "Informe a mensagem: ";
    cin >> entry;

    // Pega a string retornada e devolve encodada
    string enc = encode(entry);
    string nString = to_string(n);
    cout << "Mensagem encodada: " << enc << endl;
    // Mensagem entry é criptografada
    for (int i = 0; i < enc.length();)
    {
        aux = "";

        int j = 0;
        while (j < blockLength && i < enc.length())
        {
            aux += enc[i];
            aux += enc[i + 1];
            i += 2;
            j++;
        }

        while (aux.length() != blockLength * 2)
        {
            aux += "25";
        }

        msgInRSA.push_back(modPow(stoi(aux), e, n));
        j = 0;
    }

    // Apenas demonstrativo
    cout << "Mensagem criptografada: ";
    for (const long long num : msgInRSA)
        cout << num << " ";
    cout << endl;

    // Mensagem é descriptografada
    for (auto num : msgInRSA)
    {
        string reverse = to_string(modPow(num, d, n));
        int qtdZero = 0;
        if (blockLength * 2 > reverse.length())
        {
            qtdZero = blockLength * 2 - reverse.length();
        };

        msgReversed.push_back((reverse.insert(0, qtdZero, '0')));
    }

    // Decodames a mensagem
    cout << "Mensagem descriptografada: " << decode(msgReversed) << endl;
}

void encodingRead(long long &n, long long &e, long long &d)
{
    cout << "Informe a chave privada: ";
    cin >> d;

    cout << "Informe o n: ";
    cin >> n;

    cout << "Informe o e: ";
    cin >> e;

    return;
}

void decoding()
{
    long long d, n;
    int blockLength = 0;
    string aux = "";
    vector<long long> msg;
    vector<string> msgReversed;

    string entry;
    cout << "Informe a mensagem criptografada separando as cifras por espaco, para finalizar a entrada digite -1: ";
    while (cin >> entry && entry != "-1")
    {
        msg.push_back(stoi(entry));
    }

    cout << "Informe a chave privada: ";
    cin >> d;

    cout << "informe o N: ";
    cin >> n;

    while (stoll(aux + "25") < n)
    {
        blockLength++;
        aux += "25";
    }

    string nString = to_string(n);
    for (auto num : msg)
    {
        string reverse = to_string(modPow(num, d, n));

        int qtdZero = 0;
        if (blockLength * 2 > reverse.length())
        {
            qtdZero = blockLength * 2 - reverse.length();
        };

        msgReversed.push_back((reverse.insert(0, qtdZero, '0')));
    }

    // Decodames a mensagem
    cout << "Mensagem descriptografada: " << decode(msgReversed) << endl;
}

void sign()
{
    string entry, aux;

    long long n, d;
    int blockLength = 0;
    vector<long long> msgInRSA;
    vector<int> msgReversed;
    vector<long long> signature;

    cout << "Informe a mensagem: ";
    cin >> entry;

    cout << "Informe a chave privada para assinar: ";
    cin >> d;

    cout << "Informe o N para assinar: ";
    cin >> n;

    while (stoll(aux + "25") < n)
    {
        blockLength++;
        aux += "25";
    }

    string enc = encode(entry);
    cout << "Mensagem encoded: " << enc << endl;

    for (int i = 0; i < enc.length();)
    {
        aux = "";

        int j = 0;
        while (j < blockLength && i < enc.length())
        {
            aux += enc[i];
            aux += enc[i + 1];
            i += 2;
            j++;
        }

        cout << aux << endl;

        signature.push_back(modPow(stoll(aux), d, n));
        j = 0;
    }

    cout << "Assinatura: ";
    for(auto num : signature){
        cout << num << " ";
    }
    cout << endl;
}

void validateSign()
{
    string sign, aux;
    vector<string> entry;
    int blockLength = 0;
    long long n, e, d;

    string msg;
    cout << "Informe a mensagem assinada separando as cifras por espaco, para finalizar a entrada digite -1: ";
    while (cin >> msg && msg != "-1")
    {
        entry.push_back(msg);
    }

    cout << "Informe a mensagem esperada: ";
    cin >> sign;

    cout << "Informe o e para verificar a assinatura: ";
    cin >> e;
    cout << "Informe o n para verificar a assinatura: ";
    cin >> n;

    while (stoll(aux + "25") < n)
    {
        blockLength++;
        aux += "25";
    }

    string hash = encode(sign);
    cout << "Hash esperado " << hash << endl;
    // Mensagem entry é assinada
    string hashSign = "";
    for(auto num : entry){
        string hashAux = to_string(modPow(stoi(num), e, n));
        int qtdZero = 0;
        if(hashAux.length() < blockLength * 2){
            qtdZero = blockLength * 2 - hashAux.length();
        }
        hashSign += hashAux.insert(0, qtdZero, '0');
    }

    cout << "Hash da assinatura " << hashSign << endl;

    string valid = (hash == hashSign) ? "Sim!" : "Nao!";

    cout << "Assinatura valida: " << valid;
}

void generateMessage()
{
    string entry, aux;
    long long n, e;
    int blockLength = 0;
    vector<long long> msgInRSA;

    cout << "Informe o e: ";
    cin >> e;
    cout << "Informe o n: ";
    cin >> n;
    cout << "Informe a mensagem: ";
    cin >> entry;

    while (stoll(aux + "25") < n)
    {
        blockLength++;
        aux += "25";
    }

    string enc = encode(entry);
    cout << "Mensagem encodada: " << enc << endl;
    // Mensagem entry é criptografada
    for (int i = 0; i < enc.length();)
    {
        aux = "";

        int j = 0;
        while (j < blockLength && i < enc.length())
        {
            aux += enc[i];
            aux += enc[i + 1];
            i += 2;
            j++;
        }

        while (aux.length() != blockLength * 2)
        {
            aux += "25";
        }

        msgInRSA.push_back(modPow(stoi(aux), e, n));
        j = 0;
    }

    // Apenas demonstrativo
    cout << "Mensagem criptografada: ";
    for (const long long num : msgInRSA)
        cout << num << " ";
    cout << endl;
}