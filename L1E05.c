/*
Curso: Análise e Desenvolvimento de Sistemas
Disciplina: Programação Estruturada
Docente: Joyce Siqueira
Discente: Rafael Riki Ogawa Osiro (UC21100716)

5. Faça um algoritmo que leia um vetor de até 80 elementos. Após a leitura de todos os dados, leia
um número e verifique se existem elementos no vetor iguais ao número lido. Se existirem,
escrever, em uma tela limpa, quantas vezes eles aparecem e quais as posições em que eles estão
armazenados no vetor.
*/

#include <stdio.h>
#include <ctype.h>

int main()
{
    int numberSearchCounter = 0, numberSearchIndex[80], y = 0;
    double elements[80], numberSearch;

    for (int i = 0; i < (sizeof(elements)/sizeof(double)); i++)
    {
        printf("Digite um numero: \n");
        scanf("%lf", &elements[i]);
        fflush(stdin);
        system("cls");
    }

    printf("Digite o numero que deseja pesquisar: \n");
    scanf("%lf", &numberSearch);
    system("cls");
    
    for (int i = 0; i < (sizeof(elements)/sizeof(double)); i++)
    {
        if(numberSearch == elements[i])
        {
            numberSearchIndex[y] = i;
            numberSearchCounter++;
            y++;
        }
    }
    
    numberSearchCounter > 1? printf("O numero %.2lf aparece %d vezes.\n", numberSearch, numberSearchCounter) : printf("O numero %.2lf aparece %d vez.\n", numberSearch, numberSearchCounter)  ;
    numberSearchCounter > 1? printf("Ele aparece nas seguintes posicoes: ") : printf("Ele aparece na seguinte posicao: ") ;
    
    for (int i = 0; i < numberSearchCounter; i++)
    {
        if(i != numberSearchCounter)
        {
            printf("%d, ", (numberSearchIndex[i]+1));
        }
        else
        {
            printf("%d.", (numberSearchIndex[i]+1));
        }
    }

    return 0;
}