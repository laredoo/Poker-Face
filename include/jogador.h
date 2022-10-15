#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <string>
#include "../include/carta.h"

using namespace std;

class Jogador {
    public:
        string Nome;
        int Dinheiro;
        int Aposta;
        Carta Cartas[5];
        int RSF;
        int SF;
        int FK;
        int FH;
        int F;
        int S;
        int TK;
        int TP;
        int OP;
        int HC;
        int combNumber;
        int maisAltaFK;
        int maisAltaTK;
        int trincaFH, duplaFH;
        int maiorPar, menorPar;
        Jogador();
        void testaPares();
        void testaIguais();
        void testaFH();
        void testaStraight();
        void testaFlush();
        void testaSF();
        void testaRSF();
};

#endif