#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void inicializarTabuleiro(char tab[3][3])
{
    int i, j;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            tab[i][j]=' ';
        }
    }
}

void mostrarTabuleiro(char tab[3][3])
{
    int i;

    printf("\n");

    for(i=0;i<3;i++)
    {
        printf("| %c | %c | %c |\n",
               tab[i][0],
               tab[i][1],
               tab[i][2]);
    }

    printf("\n");
}

int jogadaValida(char tab[3][3], int linha, int coluna)
{
    if(linha < 0 || linha > 2)
        return 0;

    if(coluna < 0 || coluna > 2)
        return 0;

    if(tab[linha][coluna] != ' ')
        return 0;

    return 1;
}

void jogadaHumana(char tab[3][3], char simbolo)
{
    int linha, coluna;

    do
    {
        printf("Linha (1-3): ");
        scanf("%d",&linha);

        printf("Coluna (1-3): ");
        scanf("%d",&coluna);

        linha--;
        coluna--;

    }while(!jogadaValida(tab,linha,coluna));

    tab[linha][coluna]=simbolo;
}

void jogadaComputador(char tab[3][3], char simbolo)
{
    int linha,coluna;

    do
    {
        linha=rand()%3;
        coluna=rand()%3;
    }
    while(!jogadaValida(tab,linha,coluna));

    tab[linha][coluna]=simbolo;
}

int verificarVitoria(char tab[3][3], char s)
{
    int i;

    for(i=0;i<3;i++)
    {
        if(tab[i][0]==s &&
           tab[i][1]==s &&
           tab[i][2]==s)
           return 1;
    }

    for(i=0;i<3;i++)
    {
        if(tab[0][i]==s &&
           tab[1][i]==s &&
           tab[2][i]==s)
           return 1;
    }

    if(tab[0][0]==s &&
       tab[1][1]==s &&
       tab[2][2]==s)
       return 1;

    if(tab[0][2]==s &&
       tab[1][1]==s &&
       tab[2][0]==s)
       return 1;

    return 0;
}

int tabuleiroCheio(char tab[3][3])
{
    int i,j;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(tab[i][j]==' ')
                return 0;
        }
    }

    return 1;
}

void iniciarJogo(int argc, char *argv[])
{
    char jogador1;
    char jogador2;
    int autoMode = 0;

    char tab[3][3];

    srand(time(NULL));

    if(argc >= 2)
    {
        jogador1 = argv[1][0];
    }
    else
    {
        printf("Escolha X ou O: ");
        scanf(" %c",&jogador1);
    }

    if(jogador1=='X')
        jogador2='O';
    else
        jogador2='X';

    if(argc >= 3)
    {
        if(strcmp(argv[2],"auto")==0)
        {
            autoMode = 1;
        }
    }

    inicializarTabuleiro(tab);

    while(1)
    {
        if(autoMode)
            jogadaComputador(tab,jogador1);
        else
            jogadaHumana(tab,jogador1);

        mostrarTabuleiro(tab);

        if(verificarVitoria(tab,jogador1))
        {
            printf("O jogador 1 ganhou\n");
            return;
        }

        if(tabuleiroCheio(tab))
        {
            printf("O jogo terminou sem vencedores\n");
            return;
        }

        jogadaComputador(tab,jogador2);

        mostrarTabuleiro(tab);

        if(verificarVitoria(tab,jogador2))
        {
            printf("O jogador 2 ganhou\n");
            return;
        }

        if(tabuleiroCheio(tab))
        {
            printf("O jogo terminou sem vencedores\n");
            return;
        }
    }
}