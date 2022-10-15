#include "../include/lista.h"
#include <fstream>

TipoItem::TipoItem()
{
    
    /* Jogador aux;
    chave = aux; // indica um item vazio */
    
}
TipoItem::TipoItem(TipoChave c)
{
    chave = c;
}
void TipoItem::SetChave(TipoChave c)
{
    chave = c;
}
TipoChave TipoItem::GetChave()
{
    return chave;
}
    void TipoItem::Imprime()
{
    ofstream fileOut("saida.txt", std::ios::app);
    fileOut << chave.Nome << " " << chave.Dinheiro << endl;

}
TipoItem ListaArranjo::GetItem(int pos){
    if ( (pos > tamanho) || (pos <= 0) )
        cout << "ERRO: Posicao Invalida!" << pos << endl;
    return itens[pos-1];
}
void ListaArranjo::SetItem(TipoItem item, int pos){
    if ( (pos > tamanho) || (pos <= 0) )
    cout << "ERRO: Posicao Invalida!" << endl;
    itens[pos-1] = item;
}
void ListaArranjo::InsereInicio(TipoItem item) {
    int i;
    if (tamanho == MAXTAM)
    cout << "ERRO: Lista cheia!" << endl;
    tamanho++;
    for(i=tamanho;i>0;i--)
    itens[i] = itens[i-1];
    itens[0] = item;
}
void ListaArranjo::InsereFinal(TipoItem item) {
    if (tamanho == MAXTAM)
    cout << "ERRO: Lista cheia!" << endl;
    itens[tamanho] = item;
    tamanho++;
}
void ListaArranjo::InserePosicao(TipoItem item, int pos) {
    int i;
    //cout << tamanho << endl;
    if (tamanho == MAXTAM)
        //cout << "ERRO: Lista cheia!" << endl;
    if ( (pos > tamanho) || (pos <= 0) )
        cout << "ERRO: Posicao Invalida!" << endl;
    pos--; // posição no vetor = pos-1 (vetor começa em 0)
    tamanho++;
    for(i=tamanho;i>pos;i--)
    itens[i] = itens[i-1];
    itens[pos] = item;
}
TipoItem ListaArranjo::RemoveInicio() {
    int i;
    TipoItem aux;
    if (tamanho == 0)
    cout << "ERRO: Lista vazia!" << endl;
    aux = itens[0];
    for(i=0;i<tamanho;i++)
    itens[i] = itens[i+1];
    tamanho--;
    return aux;
}
TipoItem ListaArranjo::RemoveFinal() {
    TipoItem aux;
    if (tamanho == 0)
    cout << "ERRO: Lista vazia!" << endl;
    tamanho--;
    aux = itens[tamanho];
    return aux;
}
TipoItem ListaArranjo::RemovePosicao(int pos) {
    int i; TipoItem aux;
    if ( (pos > tamanho) || (pos <= 0) )
    cout << "ERRO: Posicao Invalida!" << endl;
    pos--; // posição no vetor = pos-1 (vetor começa em 0)
    aux = itens[pos];
    for(i=pos;i<tamanho;i++)
    itens[i] = itens[i+1];
    tamanho--;
    return aux;
}
    void ListaArranjo::Imprime() {
    int i;
    for(i=0;i<tamanho;i++)
        itens[i].Imprime();
    printf("\n");
}
void ListaArranjo::Limpa() {
    tamanho = 0;
}

PilhaArranjo::PilhaArranjo() : Pilha()
{
    topo = -1;
}

void PilhaArranjo::Empilha(TipoItem item){
    if(tamanho == MAXTAM)
        cout <<  "A pilha está cheia!" << endl;
    topo++;
    itens[topo] = item;
    tamanho++;
};

TipoItem PilhaArranjo::Desempilha(){
    TipoItem aux;
    if(tamanho == 0)
        cout << "A pilha está vazia!" << endl;
    aux = itens[topo];
    topo--;
    tamanho--;
    return aux;;
};

void PilhaArranjo::Limpa(){
    topo = -1;
    tamanho = 0;
};