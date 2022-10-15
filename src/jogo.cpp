#include "../include/jogo.h"
#include "../include/jogador.h"
#include "../include/lista.h"


#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

#define Troca(A, B) {Carta c = A; A = B; B = c; }
#define rocaNome(A, B) {Jogador c = A; A = B; B = c; }

void Jogo::Bolha(Carta *v, int n) {
    int i, j;
    for(i = 0; i < n-1; i++)
        for(j = 1; j < n-i; j++)
            if (v[j].Numero < v[j-1].Numero)
                Troca(v[j-1], v[j]);
}

void iniciaCombinacao(int* Combinacao) {
    for(int i = 0; i < 10; i++) 
        Combinacao[i] = 0;
}

int getHigherCombination(int* Combinacao, int combNumber) {
    combNumber = 0;
    for(int i = 0; i < 10; i++)
        if(Combinacao[i] == 1)
            combNumber = i;
    return combNumber;
}

int preencheCombinacao(int* Combinacao, Jogador aux) {
    if(aux.RSF == 1)
        Combinacao[9] = 1;
    else if(aux.SF == 1)
        Combinacao[8] = 1;
    else if(aux.FK == 1)
        Combinacao[7] = 1;
    else if(aux.FH == 1)
        Combinacao[6] = 1;
    else if(aux.F == 1)
        Combinacao[5] = 1;
    else if(aux.S == 1)
        Combinacao[4] = 1;
    else if(aux.TK == 1)
        Combinacao[3] = 1;
    else if(aux.TP == 1)
        Combinacao[2] = 1;
    else if(aux.OP == 1)
        Combinacao[1] = 1;
    else if(aux.HC == 1)
        Combinacao[0] = 1;
    int combNumber = 0;
    combNumber = getHigherCombination(Combinacao, combNumber);

    return combNumber;
        
}

ListaArranjo testaEmpate(Jogador aux, ListaArranjo possibleWinners) {

    Jogador p;
    Jogador ref = possibleWinners.GetItem(1).GetChave();
    ListaArranjo winners;
    if(possibleWinners.GetTamanho() > 0)
        for(int i = 1; i <= possibleWinners.GetTamanho(); i++) {
            p = possibleWinners.GetItem(i).GetChave();
            switch (p.combNumber)
            {
                case 0:
                    if(ref.Cartas[4].Numero == p.Cartas[4].Numero){
                        if(ref.Cartas[3].Numero == p.Cartas[3].Numero){
                            if(ref.Cartas[2].Numero == p.Cartas[2].Numero){
                                if(ref.Cartas[1].Numero == p.Cartas[1].Numero){
                                    if(ref.Cartas[0].Numero == p.Cartas[0].Numero){
                                        winners.InsereFinal(p);
                                    }
                                    else if(ref.Cartas[0].Numero < p.Cartas[0].Numero){
                                        ref = p;
                                        if(winners.GetTamanho() > 0)
                                            winners.Limpa();
                                        winners.InsereFinal(ref);
                                    }
                                }
                                else if(ref.Cartas[1].Numero < p.Cartas[1].Numero){
                                    ref = p;
                                    if(winners.GetTamanho() > 0)
                                        winners.Limpa();
                                    winners.InsereFinal(ref);
                                }
                            }
                            else if(ref.Cartas[2].Numero < p.Cartas[2].Numero){
                                ref = p;
                                if(winners.GetTamanho() > 0)
                                    winners.Limpa();
                                winners.InsereFinal(ref);
                            }
                        }
                        else if(ref.Cartas[3].Numero < p.Cartas[3].Numero){
                            ref = p;
                            if(winners.GetTamanho() > 0)
                                winners.Limpa();
                            winners.InsereFinal(ref);
                        }
                    }
                    else if(ref.Cartas[4].Numero < p.Cartas[4].Numero){
                        ref = p;
                        if(winners.GetTamanho() > 0)
                            winners.Limpa();
                        winners.InsereFinal(ref);
                    }    
                    break;
                case 1:
                    if(ref.maiorPar == p.maiorPar){
                        if(ref.Cartas[4].Numero == p.Cartas[4].Numero){
                            if(ref.Cartas[3].Numero == p.Cartas[3].Numero){
                                if(ref.Cartas[2].Numero == p.Cartas[2].Numero){
                                    winners.InsereFinal(p);
                                }
                            else if(ref.Cartas[2].Numero < p.Cartas[2].Numero){
                                    ref = p;
                                    if(winners.GetTamanho() > 0)
                                        winners.Limpa();
                                    winners.InsereFinal(ref);
                                }
                            }
                            else if(ref.Cartas[3].Numero < p.Cartas[3].Numero){
                                ref = p;
                                if(winners.GetTamanho() > 0)
                                    winners.Limpa();
                                winners.InsereFinal(ref);
                            }
                        }
                        else if(ref.Cartas[4].Numero < p.Cartas[4].Numero){
                            ref = p;
                            if(winners.GetTamanho() > 0)
                                winners.Limpa();
                            winners.InsereFinal(ref);
                        }  
                    }
                    else if(ref.maiorPar < p.maiorPar){
                        ref = p;
                        if(winners.GetTamanho() > 0)
                            winners.Limpa();
                        winners.InsereFinal(ref);
                    }
                    break;
                case 2:
                    if(ref.maiorPar == p.maiorPar){
                        if(ref.menorPar == p.menorPar){
                            if(ref.Cartas[4].Numero == p.Cartas[4].Numero){
                                winners.InsereFinal(p);
                            }
                            else if(ref.Cartas[4].Numero < p.Cartas[4].Numero){
                                ref = p;
                                if(winners.GetTamanho() > 0)
                                    winners.Limpa();
                                winners.InsereFinal(ref);
                            }
                        }
                        else if(ref.menorPar < p.menorPar){
                            ref = p;
                            if(winners.GetTamanho() > 0)
                                winners.Limpa();
                            winners.InsereFinal(ref);
                        }
                    }
                    else if(ref.maiorPar < p.maiorPar){
                        ref = p;
                        if(winners.GetTamanho() > 0)
                            winners.Limpa();
                        winners.InsereFinal(ref);
                    }
                    break;
                case 3:
                    if(ref.maisAltaTK == p.maisAltaTK){
                        if(ref.Cartas[4].Numero == p.Cartas[4].Numero){
                            if(ref.Cartas[3].Numero == p.Cartas[3].Numero){
                                winners.InsereFinal(p);
                            }
                            else if(ref.Cartas[3].Numero < p.Cartas[3].Numero){
                                ref = p;
                                if(winners.GetTamanho() > 0)
                                    winners.Limpa();
                                winners.InsereFinal(ref);
                            }
                        }
                        else if(ref.Cartas[4].Numero < p.Cartas[4].Numero){
                            ref = p;
                            if(winners.GetTamanho() > 0)
                                winners.Limpa();
                            winners.InsereFinal(ref);
                        }  
                    }
                    else if(ref.maisAltaTK < p.maisAltaTK){
                        ref = p;
                        if(winners.GetTamanho() > 0)
                            winners.Limpa();
                        winners.InsereFinal(ref);
                    }
                    break;
                case 4:
                    if(ref.Cartas[4].Numero == p.Cartas[4].Numero){
                        winners.InsereFinal(p);
                    }
                    else if(ref.Cartas[4].Numero < p.Cartas[4].Numero){
                        ref = p;
                        if(winners.GetTamanho() > 0)
                            winners.Limpa();
                        winners.InsereFinal(ref);
                    }
                    break;
                case 5:
                    if(ref.Cartas[4].Numero == p.Cartas[4].Numero){
                        if(ref.Cartas[3].Numero == p.Cartas[3].Numero){
                            if(ref.Cartas[2].Numero == p.Cartas[2].Numero){
                                if(ref.Cartas[1].Numero == p.Cartas[1].Numero){
                                    if(ref.Cartas[0].Numero == p.Cartas[0].Numero){
                                        winners.InsereFinal(p);
                                    }
                                    else if(ref.Cartas[0].Numero < p.Cartas[0].Numero){
                                        ref = p;
                                        if(winners.GetTamanho() > 0)
                                            winners.Limpa();
                                        winners.InsereFinal(ref);
                                    }
                                }
                                else if(ref.Cartas[1].Numero < p.Cartas[1].Numero){
                                    ref = p;
                                    if(winners.GetTamanho() > 0)
                                        winners.Limpa();
                                    winners.InsereFinal(ref);
                                }
                            }
                            else if(ref.Cartas[2].Numero < p.Cartas[2].Numero){
                                ref = p;
                                if(winners.GetTamanho() > 0)
                                    winners.Limpa();
                                winners.InsereFinal(ref);
                            }
                        }
                        else if(ref.Cartas[3].Numero < p.Cartas[3].Numero){
                            ref = p;
                            if(winners.GetTamanho() > 0)
                                winners.Limpa();
                            winners.InsereFinal(ref);
                        }
                    }
                    else if(ref.Cartas[4].Numero < p.Cartas[4].Numero){
                        ref = p;
                        if(winners.GetTamanho() > 0)
                            winners.Limpa();
                        winners.InsereFinal(ref);
                    }
                    break;
                case 6:
                    if(ref.maisAltaTK == p.maisAltaTK){
                        if(ref.maiorPar == p.maiorPar){
                            winners.InsereFinal(p);
                        }
                        else if(ref.maiorPar < p.maiorPar){
                            ref = p;
                            if(winners.GetTamanho() > 0)
                                winners.Limpa();
                            winners.InsereFinal(ref);
                        }  
                    }
                    else if(ref.maisAltaTK < p.maisAltaTK){
                        ref = p;
                        if(winners.GetTamanho() > 0)
                            winners.Limpa();
                        winners.InsereFinal(ref);
                    }
                    break;
                case 7:
                    if(ref.maisAltaFK == p.maisAltaFK){
                        if(ref.Cartas[4].Numero == p.Cartas[4].Numero){
                            winners.InsereFinal(p);
                        }
                        else if(ref.Cartas[4].Numero < p.Cartas[4].Numero){
                            ref = p;
                            if(winners.GetTamanho() > 0)
                                winners.Limpa();
                            winners.InsereFinal(ref);
                        }  
                    }
                    else if(ref.maisAltaFK < p.maisAltaFK){
                        ref = p;
                        if(winners.GetTamanho() > 0)
                            winners.Limpa();
                        winners.InsereFinal(ref);
                    }
                    break;
                case 8:
                    if(ref.Cartas[4].Numero == p.Cartas[4].Numero){
                        winners.InsereFinal(p);
                    }
                    else if(ref.Cartas[4].Numero < p.Cartas[4].Numero){
                        ref = p;
                        if(winners.GetTamanho() > 0)
                            winners.Limpa();
                        winners.InsereFinal(ref);
                    }
                    break;
                case 9:
                    winners.InsereFinal(p);
                    break;
                
            }
        }
        
    return winners;
}

ListaArranjo imprimeVencedores(ListaArranjo winners, int totalVencedor) {

    ofstream fileOut("saida.txt", std::ios::app);

    for(int j = 1; j <= winners.GetTamanho(); j++){
        fileOut << winners.GetItem(j).GetChave().Nome << endl;
    }
    
    return winners;
}

ListaArranjo imprimeCombinacao(int numVencedores, int totalVencedor, int combNumber, ListaArranjo winners) {
    ofstream fileOut("saida.txt", std::ios::app);
    switch(combNumber)
    {
        case 0:
            fileOut << numVencedores << " " << totalVencedor << " " << "HC" << endl;
            imprimeVencedores(winners, totalVencedor);
            break;
        case 1:
            fileOut << numVencedores << " " << totalVencedor << " " << "OP" << endl;
            imprimeVencedores(winners, totalVencedor);
            break;
        case 2:
            fileOut << numVencedores << " " << totalVencedor << " " << "TP" << endl;
            imprimeVencedores(winners, totalVencedor);
            break;
        case 3:
            fileOut << numVencedores << " " << totalVencedor << " " << "TK" << endl;
            imprimeVencedores(winners, totalVencedor);
            break;
        case 4:
            fileOut << numVencedores << " " << totalVencedor << " " << "S" << endl;
            imprimeVencedores(winners, totalVencedor);
            break;
        case 5:
            fileOut << numVencedores << " " << totalVencedor << " " << "F" << endl;
            imprimeVencedores(winners, totalVencedor);
            break;
        case 6:
            fileOut << numVencedores << " " << totalVencedor << " " << "FH" << endl;
            imprimeVencedores(winners, totalVencedor);
            break;
        case 7:
            fileOut << numVencedores << " " << totalVencedor << " " << "FK" << endl;
            imprimeVencedores(winners, totalVencedor);
            break;
        case 8:
            fileOut << numVencedores << " " << totalVencedor << " " << "SF" << endl;
            imprimeVencedores(winners, totalVencedor);
            break;
        case 9:
            fileOut << numVencedores << " " << totalVencedor << " " << "RSF" << endl;
            imprimeVencedores(winners, totalVencedor);
            break;
    }

    return winners;
}

ListaArranjo atualizaDinheiro(ListaArranjo listaJogadores, ListaArranjo jogadoresRodada) {

    Jogador aux;
    Jogador p;

    for(int i = 1; i <= jogadoresRodada.GetTamanho(); i++) {
        aux = jogadoresRodada.GetItem(i).GetChave();
        for(int j = 1; j <= listaJogadores.GetTamanho(); j++) {
            if(listaJogadores.GetItem(j).GetChave().Nome == aux.Nome){
                p = listaJogadores.GetItem(j).GetChave();
                p.Dinheiro -= aux.Aposta;
                listaJogadores.RemovePosicao(j);
                listaJogadores.InserePosicao(p, j);
            }    
        }
    }

    return listaJogadores;
}

ListaArranjo atualizaDinheiroVitoria(ListaArranjo listaJogadores, ListaArranjo winners, int valorVencedor) {

    Jogador aux;
    Jogador p;

    for(int i = 1; i <= winners.GetTamanho(); i++) {
        aux = winners.GetItem(i).GetChave();
        for(int j = 1; j <= listaJogadores.GetTamanho(); j++) {
            if(listaJogadores.GetItem(j).GetChave().Nome == aux.Nome){
                p = listaJogadores.GetItem(j).GetChave();
                p.Dinheiro += valorVencedor;
                listaJogadores.RemovePosicao(j);
                listaJogadores.InserePosicao(p, j);
            }    
        }
    }

    return listaJogadores;
}

ListaArranjo Jogo::testaVitoria(ListaArranjo listaJogadores, int poteRodada, ListaArranjo listaJogo) {

    Jogador aux;
    int Combinacao[10];
    iniciaCombinacao(Combinacao);
    Jogador p;
    ListaArranjo possibleWinners;
    ListaArranjo winners;

    aux = listaJogadores.GetItem(1).GetChave(); //a referencia eh o primeiro jogador
    aux.combNumber = preencheCombinacao(Combinacao, aux); //qual eh a combinacao de aux

    for(int i = 1; i <= listaJogadores.GetTamanho(); i++) {
        p = listaJogadores.GetItem(i).GetChave(); //jogador da comparacao atual
        p.combNumber = preencheCombinacao(Combinacao, p); //combinacao do jogador atual
        if(p.combNumber == aux.combNumber) {
            possibleWinners.InsereFinal(p);
            aux = p;
        }
        else if(p.combNumber > aux.combNumber) {
            aux = p;
        }
        iniciaCombinacao(Combinacao);
    }

    int combNumberTest;
    if(possibleWinners.GetTamanho() >= 1)
        combNumberTest = possibleWinners.GetItem(possibleWinners.GetTamanho()).GetChave().combNumber;
    if(possibleWinners.GetTamanho() > 1 && aux.combNumber <= combNumberTest) {
        winners = testaEmpate(aux, possibleWinners);
        possibleWinners.Limpa();
    }

    float valorVencedor = 0;

    if(winners.GetTamanho() == 0) {
        winners.InsereFinal(aux);
        winners = imprimeCombinacao(winners.GetTamanho(), poteRodada, aux.combNumber, winners);
        listaJogo = atualizaDinheiroVitoria(listaJogo, winners, poteRodada);
        winners.Limpa();
    }

    else if(winners.GetTamanho() > 0){
        valorVencedor = poteRodada/winners.GetTamanho();
        winners = ordenaEmpate(winners);
        winners = imprimeCombinacao(winners.GetTamanho(), valorVencedor, aux.combNumber, winners);
        listaJogo = atualizaDinheiroVitoria(listaJogo, winners, valorVencedor);
    }

    return listaJogo;
}

int contaPalavras(string str)
{
    int count = 1;
    string word = "";
    for (auto x : str) 
    {
        if (x == ' ')
        {
            count++;
            word = "";
        }
        else {
            word = word + x;
        }
    }
    return count;
}

void imprimeInvalido() {
    ofstream fileOut("saida.txt", std::ios::app);
    fileOut << 0 << " " << 0 << " " << "I" << endl;
}

ListaArranjo preencheAposta(ListaArranjo listaJogo, int minPot, int* rodadaInvalida) {
    Jogador aux;
    for(int i = 1; i <= listaJogo.GetTamanho(); i++) {
        aux = listaJogo.GetItem(i).GetChave();
        if(aux.Dinheiro - minPot >= 0) {
            aux.Dinheiro = aux.Dinheiro - minPot; //tira da quantia do jogador o pingo
            listaJogo.RemovePosicao(i);
            listaJogo.InserePosicao(aux, i);
            //cout << aux.Nome << " " << aux.Dinheiro << endl;
        }
        else if(aux.Dinheiro - minPot < 0){
            *rodadaInvalida = 1;
            //cout << "O jogador " << aux.Nome << " está sem dinheiro, não consegue contribuir para o mínimo da rodada, ele está fora." << endl;
            //aux.Dinheiro = 0;
        }
    }
    return listaJogo;
}

int preencheDinheiro(ListaArranjo listaJogo, string Nome) {
    int Dinheiro = 0;
    for(int i = 1; i <= listaJogo.GetTamanho(); i++)
        if(listaJogo.GetItem(i).GetChave().Nome == Nome)
            Dinheiro = listaJogo.GetItem(i).GetChave().Dinheiro;
    return Dinheiro;
}

ListaArranjo Jogo::iniciaRodada(ListaArranjo listaJogo, string nomeArquivo) {

    int numRodadas;
    int dinInicial;
    int numJogRodada;
    int minPot; //pingo
    int acumulado = 0;
    int rodadaInvalida = 0;

    ListaArranjo jogadoresRodada;
    Jogador aux;

    string trash, linha;
    string Nome;

    stringstream s;
    
    int contador = 0;
    int tamNome = 0;

    ifstream myFile;

    myFile.open(nomeArquivo); 
    if(!myFile) {
        cout << "File could not be open" << endl;
        exit(1);
    }

    myFile >> numRodadas >> dinInicial;

    if(myFile.is_open()) {
        for(int i = 0; i < numRodadas; i++) {
            myFile >> numJogRodada >> minPot;
            getline(myFile, trash);

            listaJogo = preencheAposta(listaJogo, minPot, &rodadaInvalida);
            //cout << "rodada " << i << endl;

            if(rodadaInvalida == 0) {
                acumulado = listaJogo.GetTamanho() * minPot;
                //cout << "valor da premiacao " << acumulado << endl;

                for(int j = 0; j < numJogRodada; j++) {
                    getline(myFile, linha);
                    contador = contaPalavras(linha);
                    tamNome = contador - 6;
                    s.str(linha);
                    for(int t = 0; t < tamNome; t++) {
                        s >> Nome;
                        aux.Nome += Nome;
                        if(t == tamNome - 1)
                            break;
                        aux.Nome += " ";
                    }
                    s >> aux.Aposta;
                    for(int k = 0; k < 5; k++)
                        s >> aux.Cartas[k].Numero >> aux.Cartas[k].Naipe;
                    if(aux.Aposta < minPot) {
                        //cout << aux.Nome << " depositou uma aposta menor do que o pingo, desconsiderando-a" << endl;
                    }
                    else if(aux.Aposta >= minPot) {
                        if(i == 0) {
                            aux.Dinheiro =  dinInicial - minPot;   
                        }   
                        else {
                            aux.Dinheiro = preencheDinheiro(listaJogo, aux.Nome);
                        }
                        if(aux.Dinheiro < aux.Aposta || aux.Dinheiro - aux.Aposta < 0) {
                            //cout << aux.Dinheiro << endl;
                            rodadaInvalida = 1;
                            //cout << aux.Nome << " não possui dinheiro para esta aposta, desconsiderando-a" << endl;
                            acumulado = 0;
                        }
                        if(aux.Dinheiro >= aux.Aposta && rodadaInvalida == 0) {
                            aux.Dinheiro = aux.Dinheiro - aux.Aposta;
                            acumulado += aux.Aposta;
                            Bolha(aux.Cartas, 5);
                            aux.testaPares();
                            aux.testaFH();
                            aux.testaStraight();    
                            aux.testaFlush();
                            aux.testaSF();
                            aux.testaRSF();
                            jogadoresRodada.InsereFinal(aux);
                        }  
                    }
                    aux.Nome = "";
                    aux.OP = 0;
                    aux.TP = 0;
                    aux.TK = 0;
                    aux.FK = 0;
                    aux.FH = 0;
                    aux.S = 0;
                    aux.F = 0;
                    aux.SF = 0;
                    aux.RSF = 0;
                    aux.HC = 0;
                    aux.maisAltaFK = 0, aux.maisAltaTK = 0, aux.trincaFH = 0, aux.duplaFH = 0;
                    aux.Aposta = 0;
                    aux.Dinheiro = -1;
                }

                if(rodadaInvalida == 0) {
                    listaJogo = testaVitoria(jogadoresRodada, acumulado, listaJogo);
                    listaJogo = atualizaDinheiro(listaJogo, jogadoresRodada);
                }
                if(rodadaInvalida == 1) {
                    imprimeInvalido();
                    rodadaInvalida = 0;
                }
                jogadoresRodada.Limpa();
                acumulado = 0;
            } //rodada válida
            else if(rodadaInvalida == 1) {
                imprimeInvalido();
                acumulado = 0;
                rodadaInvalida = 0;
            }
        } 
        
    }
    myFile.close();

    return listaJogo;
}

void resetaOut() {
    ofstream fileOut("saida.txt");
    fileOut << "";
}

void Jogo::leArquivo(string nomeArquivo, ListaArranjo listaJogadores) {

    int numRodadas;
    int dinInicial;
    int numJogRodada;
    int minPot; //pingo
    int lixo;
    int tamNome = 0;

    resetaOut();

    Jogador aux;

    ifstream myFile; //cin

    myFile.open(nomeArquivo); 
    if(!myFile) {
        cout << "File could not be open" << endl;
        exit(1);
    }

    string trash, linha;
    string Nome;

    stringstream s;
    
    int contador;

    myFile >> numRodadas >> dinInicial;

    if(myFile.is_open()) {
        myFile >> numJogRodada >> minPot;
        getline(myFile, trash);
        for(int j = 0; j < numJogRodada; j++) {
                getline(myFile, linha);
                contador = contaPalavras(linha);
                tamNome = contador  - 6;
                s.str(linha);
            for(int i = 0; i < tamNome; i++) {
                s >> Nome;
                aux.Nome += Nome;
                if(i == tamNome - 1)
                    break;
                aux.Nome += " ";
            }
            s >> lixo;
            aux.Dinheiro = dinInicial;
            for(int k = 0; k < 5; k++)
                s >> aux.Cartas[k].Numero >> aux.Cartas[k].Naipe;
            Bolha(aux.Cartas, 5);
            listaJogadores.InsereFinal(aux);
            aux.Nome = "";
        }
    }
    
    myFile.close();

    ofstream fileOut("saida.txt", std::ios::app);

    if(!fileOut.is_open())
    {
        cout << "Unable to open file" << endl;
        exit(1);
    }

    listaJogadores = iniciaRodada(listaJogadores, nomeArquivo);
    fileOut << endl << "####" << endl << endl;
    listaJogadores.Imprime();

    fileOut.close();
}

