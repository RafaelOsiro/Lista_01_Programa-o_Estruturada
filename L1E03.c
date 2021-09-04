/*
Curso: Análise e Desenvolvimento de Sistemas
Disciplina: Programação Estruturada
Docente: Joyce Siqueira
Discente: Rafael Riki Ogawa Osiro (UC21100716)

3. Faça um algoritmo que calcule e escreva o somatório dos valores armazenados numa variável
composta unidimensional, chamada dados, de até 100 elementos numéricos a serem lidos.
*/

//Libraries in C

#include <stdio.h>
#include <stdlib.h>

/*
    Function that scan numbers of user and sum them
*/
double sumOfArrays()
{
    double sum, array[100];

    for (int i = 0; i < 100; i++)
    {
        printf("Digite o n\243mero %d: \n", (i+1));
        scanf("%lf", &array[i]);
        system("cls");
    }

    for (int i = 0; i < 100; i++)
    {
        sum += array[i];
    }

    return sum;
}

//Main of the project
int main ()
{
    //Variable declaration
    double totalSum;    

    totalSum = sumOfArrays();

    printf("Os total dos n\243meros: %lf\n", totalSum);
    return 0;
}