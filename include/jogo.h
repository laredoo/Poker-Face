#ifndef RODADA_H
#define RODADA_H

#include <iostream>
#include <string>
#include "../include/jogador.h"
#include "../include/lista.h"

using namespace std;

class Jogo {
    public:
        int quantiaRodada;
        int numeroRodadas;
        Jogo(){quantiaRodada = 0; numeroRodadas = 0;};
        void Bolha(Carta *v, int n);
        ListaArranjo iniciaRodada(ListaArranjo listaJogadores, string nomeArquivo);
        void leArquivo(string nomeArquivo, ListaArranjo listaJogadores);
        ListaArranjo testaVitoria(ListaArranjo listaJogadores, int poteRodada, ListaArranjo listaJogo);
        
};

#endif