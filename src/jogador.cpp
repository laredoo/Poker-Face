#include "../include/jogador.h"

#include <iostream>
#include <string>

Jogador::Jogador() {

    Nome = "";
    Dinheiro = -1;
    Aposta = 0;

    for(int i = 0; i < 5; i++)  {
        Cartas[i].Numero = -1;
        Cartas[i].Naipe = 'Z';
    }

    RSF = 0;
    SF = 0;
    FK = 0;
    FH = 0;
    F = 0;
    S = 0;
    TK = 0;
    TP = 0;
    OP = 0;
    HC = 0;
    combNumber = 0;
    maisAltaFK = 0;
    maisAltaTK = 0;
    trincaFH = 0;
    maiorPar = 0;
    menorPar = 0;

}

void Jogador::testaPares() {

    int count = 0;
    int aux = Cartas[0].Numero;
    int pares = 0;
    for(int i = 0; i <= 5; i++) {
        if(aux != Cartas[i].Numero){
            if(count == 4){
                FK = 1;
                maisAltaFK = aux;
            }
            else if(count == 3){
                TK = 1;
                maisAltaTK = aux;
            }
            else if(count == 2){
                pares++;
                if(pares == 1)
                    maiorPar = aux;
                if(pares == 2) {
                    if(aux > maiorPar) {
                        menorPar = maiorPar;
                        maiorPar = aux;
                    }
                }
                
            }
            aux = Cartas[i].Numero;
            count = 0;
        }
        count++;
    }
    
    if(pares == 1)
        OP = 1;
    else if(pares == 2)
        TP = 1;
}

void Jogador::testaFH() {
    if(OP == 1 && TK == 1){
        trincaFH = maisAltaTK;
        duplaFH = maiorPar;
        FH = 1;
        OP = 0;
        TK = 0;
    }
}

void Jogador::testaStraight() {

    int count = 1;
    int aux = -1;

    for(int i = 0; i < 5; i++) {
        aux = Cartas[i].Numero+1;
        if(i <=4)
            if(Cartas[i+1].Numero == aux)
                count++;
    }
    if(count == 5)
        S = 1;
}

void Jogador::testaFlush() {

    int count = 1;

    for(int i = 0; i < 5; i++) {
        if(i <=4)
            if(Cartas[i].Naipe == Cartas[i+1].Naipe)
                count++;
    }
    if(count == 5)
        F = 1;
}

void Jogador::testaSF() {
    if(F == 1 && S == 1) {
        SF = 1;
        F = 0;
        S = 0;
    }
        
}

void Jogador::testaRSF() {

    char auxNaipe = Cartas[0].Naipe;
    int testaSeq = 0;
    int count = 1;
    int aux = -1;
    int royalStraight = 0;

    for(int i = 0; i < 5; i++) {
        aux = Cartas[i].Numero+1;
        if(i <=4)
            if(Cartas[i+1].Numero == aux)
                count++;
    }
    if(count == 4)
        testaSeq = 1;

    if(Cartas[0].Numero == 1 && testaSeq == 1 && Cartas[1].Numero == 10) {
        royalStraight = 1;
        for(int i = 0; i < 5; i++) {
            if(Cartas[i].Naipe != auxNaipe)
                royalStraight = 0;
        }
    }
    
    if(royalStraight == 1) {
        RSF = 1;
        F = 0;
    }

}

