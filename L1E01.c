/*
Curso: Análise e Desenvolvimento de Sistemas
Disciplina: Programação Estruturada
Docente: Joyce Siqueira
Discente: Rafael Riki Ogawa Osiro (UC21100716)

Exercício: 1. Escrever um programa que declare um vetor de reais e leia as notas de 30 alunos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool validateGrade(float grade)
{
    if(grade >= 0 && grade <= 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    float grade[30];
    char *cleanBuffer;
    bool validation = false;

    for (int i = 0; i <30; i++)
    {
        do 
        {
            printf("Digite a nota do aluno %d: \n", (i+1));
            scanf("%f", &grade[i]);
            scanf("%c", &cleanBuffer);
            validation = (validateGrade(grade[i]));
            
        } while (validation == false);
        validation = false;
    }

    for (int i = 0; i < 30; i++)
    {
        printf("Aluno %d: %.2f\n", (i+1),grade[i]);
    }

    return 0;
}