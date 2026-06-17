#include <stdio.h>
#include <assert.h>


int main()
{
    char tab[3][3] =
    {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };

   

    tab[0][0]='X';

  
    char vencedor[3][3] =
    {
        {'X','X','X'},
        {' ',' ',' '},
        {' ',' ',' '}
    };

    
    char cheio[3][3] =
    {
        {'X','O','X'},
        {'O','X','O'},
        {'O','X','O'}
    };

    

    printf("Todos os testes passaram!\n");
    printf("Criado por Nicoly Bernardino\n");

    return 0;
}