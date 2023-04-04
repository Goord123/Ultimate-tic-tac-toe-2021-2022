#include <stdio.h>
#include "funcs.h"

int main() {
    srand(time(NULL));

    int x=0;
    int lin=0, col=0;
    int pos=0;
    int tab2Play=1;
    int gameMode, ant;
    bool vsPC = false;


    pTabs listaTab = NULL;
    pJogadas gameLog = NULL;
    listaTab = insereTab(listaTab);
    open8Tabs(listaTab);


    printf("\t\tBem Vindo!\n\n\tType 1 for Single-player\n\tType 2 for Multi-player\n\tType 3 to resume a game ");
    scanf("%d", &gameMode);
    if (gameMode == 1)
        vsPC = true;
    if (gameMode == 3) {
        gameLog = readJogadas(gameLog);
        printf("\nType 1 for Single-player\nType 2 for Multi-player");
        scanf("%d", &gameMode);
        if (gameMode == 1)
            vsPC = true;
        else
            vsPC = false;
    }
    mostraInfoJ(gameLog);

    printf("Selecione o tabuleiro em que pretende jogar: \n");
    scanf("%d", &tab2Play);
    /*
    listaTab->tab[0][1] = 'X';
    listaTab->tab[0][0] = 'X';
    listaTab->tab[0][2] = 'X';
    listaTab->prox->tab[0][1] = 'X';
    listaTab->prox->tab[0][0] = 'X';
    listaTab->prox->tab[0][2] = 'X';
    listaTab->prox->prox->tab[0][1] = 'X';
    listaTab->prox->prox->tab[0][0] = 'X';
    listaTab->prox->prox->tab[0][2] = 'X';
*/
    while (1) {

        char win = checkGameOver(listaTab);
        if (win == 'A') {
            printf("JOGO TERMINADO! O VENCEDOR E O JOGADOR A !!\n");
            return 0;
        }
        if (win == 'B') {
            printf("JOGO TERMINADO! O VENCEDOR E O JOGADOR B !!\n");
            return 0;
        }
        if (x != 0)
            tab2Play = pos;

        if (!vsPC || vsPC  && x%2 == 0) {
            printf("\n\nSelecione uma posicao (1-9) ou pressione '0' para ver jogadas anteriores ou '99' para sair: ");
            scanf("%d", &pos);
            if (pos == 0) {
                printf("Quantas posicoes atras deseja ver?\n");
                scanf("%d", &ant);
                mostraJogadasAnteriores(gameLog, ant, x);
                continue;
            }
            if (pos == 99)
                return 0;
        }

        if (vsPC == true && x%2 != 0) {
            pos = rand() % 9 + 1;
            sleep(1);
        }

        if (pos == 1) { lin = 0;col = 0; }
        if (pos == 2) { lin = 0;col = 1; }
        if (pos == 3) { lin = 0;col = 2; }
        if (pos == 4) { lin = 1;col = 0; }
        if (pos == 5) { lin = 1;col = 1; }
        if (pos == 6) { lin = 1;col = 2; }
        if (pos == 7) { lin = 2;col = 0; }
        if (pos == 8) { lin = 2;col = 1; }
        if (pos == 9) { lin = 2;col = 2; }

        if (checkIfInvalidMove(listaTab, tab2Play, lin, col, gameMode, x, vsPC) == 1 ) {
            continue;
        }

        // meter o X ou O no tabuleiro
        if(getListByIndex(listaTab, tab2Play)->tabOver == false)
            insertPlay(listaTab, tab2Play, lin, col,x);
        else {
            printf("Erro! O jogo nesse tabuleiro ja terminou!\nSelecione outro tabuleiro.");
            continue;
        }


        // GUARDA A JOGADA QUE FOI FEITA
        if (x == 0){
            gameLog = insereJogadas(gameLog, x, tab2Play, pos);
            mostraInfoJ(gameLog);
        } else {
            insereJogadas(gameLog, x, tab2Play, pos);
            mostraInfoJ(gameLog);
        }

        // variavel para saber quem está a jogar
        x++;

        writeJogadas(gameLog, x);

        // WIN-CON
        if (checkWin(listaTab, x)){
            mostraInfo(listaTab);
            return 0;
        }

        printf("\n");
        printf("####### JOGADA %d ########\n", x);
        mostraInfo(listaTab);

    }

    return 0;
}