#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> 
#include <random>
#include <chrono>
#include <stdlib.h> 
#include <fstream>
#include <map>
#include <string>
using std::vector;
using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::string;

// Então temos que o orcamento nao pode passar de 100.000 - impostos e valor dos lotes não podem exceder.
// Além disso, o valor retornado tem que ser o máximo possível

struct Acao{
    string nome;
    int valor_lote;
    int retorno_lote;
    int imposto;
};

int valor_lotes_imposto(vector<Acao> resposta){
    int pagar = 0;
    for (int i = 0; i < int(resposta.size()); i++){
        pagar += resposta[i].valor_lote + resposta[i].imposto;
    }
    return pagar;
}

int retorno_lote(vector<Acao> resposta){
    int valor = 0;
    for (int i = 0; i < int(resposta.size()); i++){
        valor += resposta[i].retorno_lote;
    }
    return valor;
}

vector<Acao> exaustiva(int i, vector<Acao> &acoes, int &orcamento, vector<Acao> resposta){
    if (valor_lotes_imposto(resposta) > orcamento){
        return resposta;
    }
    if (i == 0){
        return resposta;
    }

    vector<Acao> resposta1 = exaustiva(i-1, acoes, orcamento, resposta); // sem a acao na lista
    resposta.push_back(acoes[i]);
    vector<Acao> resposta2 = exaustiva(i-1, acoes, orcamento, resposta); // com a acao na lista

    if (valor_lotes_imposto(resposta1) <= orcamento && valor_lotes_imposto(resposta2) <= orcamento){
        if (retorno_lote(resposta1) > retorno_lote(resposta2)){
            return resposta1;
        }
        else{
            return resposta2;
        }
    }
    else if (valor_lotes_imposto(resposta1) <= orcamento){
        return resposta1;
    }
    else if (valor_lotes_imposto(resposta2) <= orcamento){
        return resposta2;
    }
    else{
        return resposta;
    }


}


int main(){
    int orcamento = 100000;
    // map<string, Acao> acoes= {{"PETR4", {30000, 2700, 640}},
    //                         {"DELL6", {60000, 4500, 900}},
    //                         {"MICR7", {30000, 6400, 1200}},
    //                         {"IBMC3", {40000, 4600, 940}}};
    // vector <Acao> acoes = {{"PETR4", 30000, 2700, 640}, {"DELL6", 60000, 4500, 900}, {"MICR7", 30000, 6400, 1200}, {"IBMC3", 40000, 4600, 940}};
    int n;
    cin >> n;
    vector <Acao> acoes;


    for (int i = 0; i < n; i++){
		Acao acao;
        cin >> acao.nome;
        cin >> acao.valor_lote;
        cin >> acao.retorno_lote;
        cin >> acao.imposto;
		acoes.push_back(acao);
	}

    vector<Acao> resposta;
    resposta = exaustiva(n-1, acoes, orcamento, resposta);

    int retorno_lote = 0;
    for (int i = 0; i < int(resposta.size()); i++){
        cout << resposta[i].nome << " " << resposta[i].valor_lote << " " << resposta[i].retorno_lote << " " << resposta[i].imposto << endl;
        retorno_lote += resposta[i].retorno_lote;
    }

    cout << "Retorno: " << retorno_lote << endl;
}


