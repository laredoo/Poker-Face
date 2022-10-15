#include "../include/carta.h"
#include "../include/jogador.h"
#include "../include/lista.h"
#include "../include/jogo.h"

#include <iostream>
#include <string>

int main () {

    ListaArranjo listaJogadores;
    Jogo round;
    round.leArquivo("entrada.txt", listaJogadores);
    //listaJogadores.Imprime();

    return 0;
}
