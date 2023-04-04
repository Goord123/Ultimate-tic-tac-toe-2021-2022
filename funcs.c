#include <stdio.h>
#include "funcs.h"

int checkIfListaVazia(pTabs a) {
    if (a == NULL) {
        printf("Lista vazia!\n");
        return 1;
    } else return 0;
}

char pickWinner(pTabs a, int x) {
    a->tabOver = true;
    if (x%2 == 0) {
        a->winner = 'B';
        return 'B';
    }
    else {
        a->winner = 'A';
        return 'A';
    }
}

char checkGameOver(pTabs a) {

    if (a->winner == 'A' && a->prox->winner == 'A' && a->prox->prox->winner == 'A')
        return 'A';
    if (a->winner == 'A' && a->prox->prox->prox->winner == 'A' && a->prox->prox->prox->prox->prox->prox->winner == 'A')
        return 'A';
    if (a->winner == 'A' && a->prox->prox->prox->winner == 'A' && a->prox->prox->prox->prox->prox->prox->prox->prox->winner == 'A')
        return 'A';
    if (a->prox->prox->prox->winner == 'A' && a->prox->prox->prox->prox->winner == 'A' && a->prox->prox->prox->prox->prox->winner == 'A')
        return 'A';
    if (a->prox->prox->winner == 'A' && a->prox->prox->prox->prox->prox->winner == 'A' && a->prox->prox->prox->prox->prox->prox->prox->prox->winner == 'A')
        return 'A';
    if (a->prox->prox->prox->prox->prox->prox->winner == 'A' && a->prox->prox->prox->prox->prox->prox->prox->winner == 'A' && a->prox->prox->prox->prox->prox->prox->prox->prox->winner == 'A')
        return 'A';
    if (a->prox->winner == 'A' && a->prox->prox->prox->prox->winner == 'A' && a->prox->prox->prox->prox->prox->prox->prox->winner == 'A')
        return 'A';

    if (a->winner == 'B' && a->prox->winner == 'B' && a->prox->prox->winner == 'B')
        return 'B';
    if (a->winner == 'B' && a->prox->prox->prox->winner == 'B' && a->prox->prox->prox->prox->prox->prox->winner == 'B')
        return 'B';
    if (a->winner == 'B' && a->prox->prox->prox->winner == 'B' && a->prox->prox->prox->prox->prox->prox->prox->prox->winner == 'B')
        return 'B';
    if (a->prox->prox->prox->winner == 'B' && a->prox->prox->prox->prox->winner == 'B' && a->prox->prox->prox->prox->prox->winner == 'B')
        return 'B';
    if (a->prox->prox->winner == 'B' && a->prox->prox->prox->prox->prox->winner == 'B' && a->prox->prox->prox->prox->prox->prox->prox->prox->winner == 'B')
        return 'B';
    if (a->prox->prox->prox->prox->prox->prox->winner == 'B' && a->prox->prox->prox->prox->prox->prox->prox->winner == 'B' && a->prox->prox->prox->prox->prox->prox->prox->prox->winner == 'B')
        return 'B';
    if (a->prox->winner == 'B' && a->prox->prox->prox->prox->winner == 'B' && a->prox->prox->prox->prox->prox->prox->prox->winner == 'B')
        return 'B';
}

int checkWin(pTabs a, int x) {

    for (int i = 0; i < TAM*TAM; i++) {
        if (a == NULL) {
            printf("Index not found in the linked list\n");
            return 0;
        }

    //Check-win HORIZONTAL
    if (a->tab[0][0] == a->tab[0][1] && a->tab[0][0] == a->tab[0][2]) {
        printf("\nJogador %c faz 3 em linha horizontal!\n", pickWinner(a, x));

    }if (a->tab[1][0] == a->tab[1][1] && a->tab[1][0] == a->tab[1][2]) {
        printf("\nJogador %c faz 3 em linha horizontal!\n", pickWinner(a, x));
        return 1;
    }if (a->tab[2][0] == a->tab[2][1] && a->tab[2][0] == a->tab[2][2]) {
        printf("\nJogador %c faz 3 em linha horizontal!\n", pickWinner(a, x));
        return 1;
    }
    //Check-win VERTICAL
    if (a->tab[0][0] == a->tab[1][0] && a->tab[0][0] == a->tab[2][0]) {
        printf("\nJogador %c faz 3 em linha vertical!\n", pickWinner(a, x));
        return 1;
    }if (a->tab[0][1] == a->tab[1][1] && a->tab[0][1] == a->tab[2][1]) {
        printf("\nJogador %c faz 3 em linha vertical!\n", pickWinner(a, x));
        return 1;
    }if (a->tab[0][2] == a->tab[1][2] && a->tab[0][2] == a->tab[2][2]) {
        printf("\nJogador %c faz 3 em linha vertical!\n", pickWinner(a, x));
        return 1;
    }
    //Check-win DIAGONAL
    if (a->tab[0][0] == a->tab[1][1] && a->tab[0][0] == a->tab[2][2]) {
        printf("\nJogador %c faz 3 em linha diagonal!\n", pickWinner(a, x));
        return 1;
    }
    if (a->tab[2][0] == a->tab[1][1] && a->tab[2][0] == a->tab[0][2]) {
        printf("\nJogador %c faz 3 em linha diagonal!\n", pickWinner(a, x));
        return 1;
    }
    a = a->prox;
    }
    return 0;
}

void mostraInfo(pTabs a) {
    pTabs aux = a;
    pTabs aux2 = aux;

    // check for nulls
    for (int i=0; i<9; i++) {
        if (aux2 == NULL){
            printf("Erro! Lista nao contem 9 tabuleiros\n");
            return;
        }
            aux2 = aux2->prox;
    }

        printf("%c %c %c  |  %c %c %c  |  %c %c %c\n"
               "%c %c %c  |  %c %c %c  |  %c %c %c\n"
               "%c %c %c  |  %c %c %c  |  %c %c %c\n"
               "-------------------------\n"
               "%c %c %c  |  %c %c %c  |  %c %c %c\n"
               "%c %c %c  |  %c %c %c  |  %c %c %c\n"
               "%c %c %c  |  %c %c %c  |  %c %c %c\n"
               "-------------------------\n"
               "%c %c %c  |  %c %c %c  |  %c %c %c\n"
               "%c %c %c  |  %c %c %c  |  %c %c %c\n"
               "%c %c %c  |  %c %c %c  |  %c %c %c",

               aux->tab[0][0], aux->tab[0][1], aux->tab[0][2],
               aux->prox->tab[0][0], aux->prox->tab[0][1], aux->prox->tab[0][2],
               aux->prox->prox->tab[0][0], aux->prox->prox->tab[0][1], aux->prox->prox->tab[0][2],
               aux->tab[1][0], aux->tab[1][1], aux->tab[1][2],
               aux->prox->tab[1][0], aux->prox->tab[1][1], aux->prox->tab[1][2],
               aux->prox->prox->tab[1][0], aux->prox->prox->tab[1][1], aux->prox->prox->tab[1][2],
               aux->tab[2][0], aux->tab[2][1], aux->tab[2][2],
               aux->prox->tab[2][0], aux->prox->tab[2][1], aux->prox->tab[2][2],
               aux->prox->prox->tab[2][0], aux->prox->prox->tab[2][1], aux->prox->prox->tab[2][2],

               aux->prox->prox->prox->tab[0][0], aux->prox->prox->prox->tab[0][1], aux->prox->prox->prox->tab[0][2],
               aux->prox->prox->prox->prox->tab[0][0], aux->prox->prox->prox->prox->tab[0][1], aux->prox->prox->prox->prox->tab[0][2],
               aux->prox->prox->prox->prox->prox->tab[0][0], aux->prox->prox->prox->prox->prox->tab[0][1], aux->prox->prox->prox->prox->prox->tab[0][2],
               aux->prox->prox->prox->tab[1][0], aux->prox->prox->prox->tab[1][1], aux->prox->prox->prox->tab[1][2],
               aux->prox->prox->prox->prox->tab[1][0], aux->prox->prox->prox->prox->tab[1][1], aux->prox->prox->prox->prox->tab[1][2],
               aux->prox->prox->prox->prox->prox->tab[1][0], aux->prox->prox->prox->prox->prox->tab[1][1], aux->prox->prox->prox->prox->prox->tab[1][2],
               aux->prox->prox->prox->tab[2][0], aux->prox->prox->prox->tab[2][1], aux->prox->prox->prox->tab[2][2],
               aux->prox->prox->prox->prox->tab[2][0], aux->prox->prox->prox->prox->tab[2][1], aux->prox->prox->prox->prox->tab[2][2],
               aux->prox->prox->prox->prox->prox->tab[2][0], aux->prox->prox->prox->prox->prox->tab[2][1], aux->prox->prox->prox->prox->prox->tab[2][2],

               aux->prox->prox->prox->prox->prox->prox->tab[0][0], aux->prox->prox->prox->prox->prox->prox->tab[0][1], aux->prox->prox->prox->prox->prox->prox->tab[0][2],
               aux->prox->prox->prox->prox->prox->prox->prox->tab[0][0], aux->prox->prox->prox->prox->prox->prox->prox->tab[0][1], aux->prox->prox->prox->prox->prox->prox->prox->tab[0][2],
               aux->prox->prox->prox->prox->prox->prox->prox->prox->tab[0][0], aux->prox->prox->prox->prox->prox->prox->prox->prox->tab[0][1], aux->prox->prox->prox->prox->prox->prox->prox->prox->tab[0][2],
               aux->prox->prox->prox->prox->prox->prox->tab[1][0], aux->prox->prox->prox->prox->prox->prox->tab[1][1], aux->prox->prox->prox->prox->prox->prox->tab[1][2],
               aux->prox->prox->prox->prox->prox->prox->prox->tab[1][0], aux->prox->prox->prox->prox->prox->prox->prox->tab[1][1], aux->prox->prox->prox->prox->prox->prox->prox->tab[1][2],
               aux->prox->prox->prox->prox->prox->prox->prox->prox->tab[1][0], aux->prox->prox->prox->prox->prox->prox->prox->prox->tab[1][1], aux->prox->prox->prox->prox->prox->prox->prox->prox->tab[1][2],
               aux->prox->prox->prox->prox->prox->prox->tab[2][0], aux->prox->prox->prox->prox->prox->prox->tab[2][1], aux->prox->prox->prox->prox->prox->prox->tab[2][2],
               aux->prox->prox->prox->prox->prox->prox->prox->tab[2][0], aux->prox->prox->prox->prox->prox->prox->prox->tab[2][1], aux->prox->prox->prox->prox->prox->prox->prox->tab[2][2],
               aux->prox->prox->prox->prox->prox->prox->prox->prox->tab[2][0], aux->prox->prox->prox->prox->prox->prox->prox->prox->tab[2][1], aux->prox->prox->prox->prox->prox->prox->prox->prox->tab[2][2]
        );

        printf("\n");
}

void mostraInfoIndex(pTabs a, int index) {
    int i;
    pTabs aux = a;
    for (i = 0; i < index; i++) {
        aux = aux->prox;
        if (aux == NULL) {
            printf("Index not found in the linked list\n");
            return;
        }
    }
        for(i=0; i<TAM; i++) {
            printf("\n");
            for(int j=0; j<TAM; j++){
                printf("%c ", aux->tab[i][j]);
            }
        }
}

void preenche(pTabs a){
    char cont= '1';
    a->tabOver = false;

    for (int i=0; i<TAM; i++){
        for (int j=0; j<TAM; j++){
            a->tab[i][j] = cont++;
        }
    }
}

pTabs insereInicio(pTabs a){
    pTabs novo;

    novo = malloc(sizeof(tabuleiro));
    if (novo == NULL) {
        printf("Erro na alocacao de memoria\n");
    } else {
        preenche(novo);
        novo->prox = a;
        a = novo;
    }
    return a;
}

pJogadas insereInicioJogadas(pJogadas a, int x, int tab, int pos){
    pJogadas novo;
    char jogador;

    novo = malloc(sizeof(jogadas));
    if (novo == NULL) {
        printf("Erro na alocacao de memoria\n");
        return 0;
    } else {
        if (x % 2 == 0)
            jogador = 'A';
        else jogador = 'B';
        novo->jogador = jogador;
        novo->turno = x;
        novo->nrTab = tab;
        novo->pos = pos;
        novo->prox = NULL;
        a = novo;
    }
    return a;
}

pJogadas insereJogadas(pJogadas a, int x, int tab, int pos){
    pJogadas novo = NULL, aux = NULL;
    char jogador;

    novo = malloc(sizeof(jogadas));
    if (novo == NULL) {
        printf("Erro na alocacao de memoria\n");
        return a;
    } else {
        if (x % 2 == 0)
            jogador = 'A';
        else jogador = 'B';
        novo->jogador = jogador;
        novo->turno = x;
        novo->nrTab = tab;
        novo->pos = pos;
        novo->prox = NULL;
    }


    if (a == NULL) { // Se a lista estiver vazia
        a = novo;
        a->prev = NULL;
    }
    else {
        aux = a;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
        novo->prev = aux;
    }
    return a;
}

pTabs insereTab(pTabs a){
    pTabs novo, aux;

    novo = malloc(sizeof(tabuleiro));
    if (novo == NULL) {
        printf("Erro na alocacao de memoria\n");
        return a;
    }
    preenche(novo);
    novo->prox = NULL;
    if (a == NULL)      // Se a lista estiver vazia
        a = novo;
    else {
        aux = a;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return a;
}

int checkIfInvalidMove(pTabs listaTab, int index, int lin, int col, int gameMode, int x, bool vsPc) {
    pTabs aux = listaTab;
    for (int i = 1; i < index; i++) {
        aux = aux->prox;
        if (aux == NULL) {
            printf("Index not found in the linked list\n");
            return 0;
        }
    }
    if ((aux->tab[lin][col] == 'X') || (aux->tab[lin][col] == 'O')) {
        if (gameMode != 1 || gameMode == 1 && x%2 != 0) {
            if (vsPc && x % 2 == 0)
            printf("\nJogada invalida!");
        }
        return 1;
    }
}

void insertPlay(pTabs listaTab, int index, int lin, int col, int jogador) {
    int i;
    pTabs aux = listaTab;
    for (i = 1; i < index; i++) {
        aux = aux->prox;
        if (aux == NULL) {
            printf("Index not found in the linked list\n");
            return;
        }
    }
    if( jogador%2 == 0 ) {
        aux->tab[lin][col] = 'X';
    } else {
        aux->tab[lin][col] = 'O';
    }
}

pTabs getListByIndex(pTabs a, int index) {
    // int = 1, pq estamos a trabalhar com o tabuleiro 1-9 em vez de index 0-8
    pTabs aux = a;
    for (int i = 1; i < index; i++) {
        aux = aux->prox;
        if (aux == NULL) {
            printf("Index not found in the linked list\n");
            return 0;
        }
    }
    return aux;
}

pJogadas getJogadasByIndex(pJogadas a, int index) {
    // int = 1, pq estamos a trabalhar com o tabuleiro 1-9 em vez de index 0-8
    pJogadas aux = a;
    for (int i = 1; i < index; i++) {
        aux = aux->prox;
        if (aux == NULL) {
            printf("Index not found in the linked list\n");
            return 0;
        }
    }
    return aux;
}

void open8Tabs(pTabs a) {

    getListByIndex(a, 0)->indexTab = 1;
    insereTab(a);
    getListByIndex(a, 1)->indexTab = 2;
    insereTab(a);
    getListByIndex(a, 2)->indexTab = 3;
    insereTab(a);
    getListByIndex(a, 3)->indexTab = 4;
    insereTab(a);
    getListByIndex(a, 4)->indexTab = 5;
    insereTab(a);
    getListByIndex(a, 5)->indexTab = 6;
    insereTab(a);
    getListByIndex(a, 6)->indexTab = 7;
    insereTab(a);
    getListByIndex(a, 7)->indexTab = 8;
    insereTab(a);
    getListByIndex(a, 8)->indexTab = 9;
}

void mostraInfoJ(pJogadas a) {
    while (a != NULL) {
        printf("Turno: %d\tJogador: %c\tTab: %d\tPos: %d\n", a->turno, a->jogador, a->nrTab, a->pos);
        a = a->prox;
    }
}

void mostraJogadasAnteriores(pJogadas a, int index, int x) {
    pJogadas aux = a;

    if (aux == NULL) {
        printf("Erro na alocacao de memoria\n");
        return;
    } else {
        while (aux->prox != NULL && aux->turno != x) {
            aux = aux->prox;
        }
        for (int i = 0; i < index; i++) {
            printf("Turno: %d\tJogador: %c\tTab: %d\tPos: %d\n", aux->turno, aux->jogador, aux->nrTab, aux->pos);
            if (aux->prev == NULL)
                return;
            aux = aux->prev;
        }

    }

}

void writeJogadas(pJogadas a, int x) {
    FILE *pf = fopen("test.bin", "ab");
    if (pf == NULL)
        printf("Erro a abrir o ficheiro\n");

    getJogadasByIndex(a, x);
    pJogadas aux = a;
    while (aux->prox != NULL) {
        fwrite(aux , sizeof(struct jogadas), 1 , pf );
        aux = aux->prox;
    }
    fclose(pf);

}

pJogadas readJogadas(pJogadas a) {
    FILE *pf = fopen("test.bin", "rb");
    if (pf == NULL)
        printf("Erro a abrir o ficheiro\n");
    jogadas ab;
    //bb = malloc(sizeof(struct jogadas));
    int turno=0, pos=0, tab=0;

    while (fread(&ab, sizeof(struct jogadas), 1, pf) == 1) {
    //    turno = a->turno ;
    //    tab = a->nrTab;
    //    pos = a->pos;
    // printf("turno: %d\n", ab.turno);
    // printf("nrTab: %d\n", ab.nrTab);
    // printf("pos: %d\n", ab.pos);
        a = insereJogadas(a, ab.turno, ab.nrTab, ab.pos);
        // passar só a lista
    }

    fclose(pf);
    return a;
}
