#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#define TAMP 200
using namespace std;

template <typename T>
struct Pilha {
    char sinal[TAMP];
    float valor[TAMP];
    char expressao[TAMP];
    int topo1; // topo da pilha para sinal 
    int topo2; // topo da pilha para valor
};

template <typename T>
void inicializarPilha(Pilha<T>& p) {
    for (int i = 0; i < TAMP - 1; i++) {
        p.sinal[i] = 0;
        p.valor[i] = 0;
        p.expressao[i] = 0;
    }
    p.topo1 = -1; // pilha para sinal vazia
    p.topo2 = -1; // pilha para valor vazia
    return;
}

template <typename T>
bool inserirSinal(Pilha<T>& p, T valor) { // para inserir caractere (sinal)
    if (p.topo1 == TAMP - 1) { // se a pilha de sinais estiver cheia
        return false;
    }
    p.topo1++;
    p.sinal[p.topo1] = valor;
    return true;
}

template <typename T>
bool inserirValor(Pilha<T>& p, T valor) { // para inserir caractere (valor) 
    if (p.topo2 < TAMP - 1) { // insere
        p.topo2++;
        p.valor[p.topo2] = valor;
        return true;
    }
    return false; // se a pilha de valores estiver cheia
}

template <typename T>
bool retirarSinal(Pilha<T>& p, T& valor) { // para retirar um caractere (sinal) 
    if (p.topo1 <= -1) return false; // se a pilha de sinais  estiver vazia
    valor = p.sinal[p.topo1]; // retorna o sinal através de "valor"
    p.sinal[p.topo1] = 0;
    p.topo1--;
    return true; // se retirar
}

bool ehOperador(char c) { // verifica se o caractere é um operador
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^'; 
}

int preferencia(char op) { // indica a ordem, de prioridade das operacoes
    if (op == '^')  return 3; // prioridade
    else if (op == '*' || op == '/')  return 2; // media prioridade
    else if (op == '+' || op == '-')    return 1; // baixa prioridade
    else  return 0;
}

float operacoes(char op, int a, int b) { // retorna o resultado das operacoes
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '^': return pow(a, b);
    default: return 0;
    }
}

bool alfanumerico(char c) { // verifica se é alfanumérico (combinação de letras do alfabeto e números)
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

string infixaParaPolonesa(const string& infixa) { // ex: 3 + 4 * (2 - 1) vira: 3 4 2 1 - * +
    string notacaoPolonesa;
    Pilha<char> operadores; // armazena operadores e parenteses enquanto sao processados

    return notacaoPolonesa;
}

float calculaExpressaoPolonesa(const string& polonesa) { // recebe notação polonesa reversa ex: 3 4 2 1 - * + e calcula
    Pilha<float> valores; // armazena os valores numericos enquanto sao processados
    
    float resultadoFinal = 0;
    retirarSinal(valores, resultadoFinal);
    return resultadoFinal;
}

int main() {
    Pilha<float> p;
    string notacaoPolonesa;

    cout << "\t\t\tConversor de Notacao Polonesa Inversa\n" << endl;

    cout << "Digite a expressao infixa sem espacamento, ex: a+b ou (a+b)/c ou ((a*b)-(c*d))/(e*f): ";
    cin.getline(p.expressao, TAMP);

    inicializarPilha(p); 
    notacaoPolonesa = infixaParaPolonesa(p.expressao); // calcula a notação

    cout << "\n\n\t\t\tNotacao Polonesa Inversa: " << notacaoPolonesa << endl << endl;

    float resultado = calculaExpressaoPolonesa(notacaoPolonesa);
    cout << "Resultado da Expressao: " << resultado << endl << endl;

    return 0;
}
