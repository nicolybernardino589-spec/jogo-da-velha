#include <stdio.h>
#include <assert.h>

int jogadaValida(char tab[3][3], int linha, int coluna);
int verificarVitoria(char tab[3][3], char s);
int tabuleiroCheio(char tab[3][3]);

int main()
{
    char tab[3][3] =
    {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };

    assert(jogadaValida(tab,0,0)==1);

    tab[0][0]='X';

    assert(jogadaValida(tab,0,0)==0);

    char vencedor[3][3] =
    {
        {'X','X','X'},
        {' ',' ',' '},
        {' ',' ',' '}
    };

    assert(verificarVitoria(vencedor,'X')==1);

    char cheio[3][3] =
    {
        {'X','O','X'},
        {'O','X','O'},
        {'O','X','O'}
    };

    assert(tabuleiroCheio(cheio)==1);

    printf("Todos os testes passaram!\n");
    printf("Criado por Nicoly Bernardino\n");

    return 0;
}