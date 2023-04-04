#ifndef FUNCS_H_INCLUDED
#define FUNCS_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include<windows.h>
#include<unistd.h>
#define TAM 3

typedef struct dados tabuleiro, *pTabs;
struct dados {
    char tab[TAM][TAM];
    int indexTab;
    char winner;
    bool tabOver;
    pTabs prox;
};

typedef struct jogadas jogadas, *pJogadas;
struct jogadas {
    int turno;
    char jogador;
    int nrTab;
    int pos;
    pJogadas prox;
    pJogadas prev;
};

// General use functions
int checkWin(pTabs a, int x);
char checkGameOver(pTabs a);
char pickWinner (pTabs a, int x);
int checkIfListaVazia(pTabs a);
int checkIfInvalidMove(pTabs listaTab, int index, int lin, int col, int gameMode, int x, bool vsPC);
void insertPlay(pTabs listaTab, int index, int lin, int col, int jogador);
void mostraInfoIndex(pTabs a, int index);
void preenche(pTabs a);
void mostraInfo(pTabs a);
void open8Tabs(pTabs a);

// List functions
pTabs insereInicio(pTabs a);
pTabs insereTab(pTabs a);
pTabs getListByIndex(pTabs lista, int index);

// List functions das jogodas
pJogadas insereInicioJogadas(pJogadas a, int x, int tab, int pos);
pJogadas insereJogadas(pJogadas a, int x, int tab, int pos);
pJogadas getJogadasByIndex(pJogadas lista, int index);
void mostraInfoJ(pJogadas a);
void mostraJogadasAnteriores(pJogadas a, int index, int x);
void writeJogadas(pJogadas a, int x);
pJogadas readJogadas(pJogadas a);

#endif