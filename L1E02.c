/*
Curso: Análise e Desenvolvimento de Sistemas
Disciplina: Programação Estruturada
Docente: Joyce Siqueira
Discente: Rafael Riki Ogawa Osiro (UC21100716)

2. Altere o algoritmo anterior considerando que não se conhece quantos alunos esta turma tem (menos que 50). 
O número de aluno será informado pelo usuário.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Function to verify grades
validateGrade(float grade)
{
    if(grade >= 0 && grade <= 10)
    {
        if(grade <= 10)
        {
            return true;
        }
        else
        {
            system("cls");
            printf("A nota do aluno dever\240 ser menor ou igual a 10!\n\n\n");
            return false;
        }
    }
    else
    {
         system("cls");
        printf("A nota do aluno dever\240 ser maior ou igual a 0!\n\n\n");
        return false;
    }
}

//Function to verify positive numbers
validateQuantityOfStudets (int quantity)
{
    if (quantity >= 1)
    {
        if (quantity <= 50)
        {
            return true;
        }
        else
        {
            printf("Digite um n\243mero menor ou igual a 50 estudantes!\n\n\n");
            return false;
        }
    }
    else
    {
        printf("Digite um n\243mero maior ou igual a 1 estudante!\n\n\n");
        return false;
    }
}

//Main of the project
int main()
{
    int quantityOfStudents;
    float *grade;
    bool validation = false;

    do
    {
        printf("Digite a qunantidade de alunos: \n");
        scanf("%d", &quantityOfStudents);
        validation = (validateQuantityOfStudets(quantityOfStudents));

    } while (validation == false);

    validation = false;
    grade = (float*)malloc(quantityOfStudents * sizeof(float*));

    for (int i = 0; i < quantityOfStudents; i++)
    {
        do 
        {
            printf("Digite a nota do aluno %d: \n", (i+1));
            scanf("%f", &grade[i]);
            validation = (validateGrade(grade[i]));
            
        } while (validation == false);
        validation = false;
    }

    system("cls");

    for (int i = 0; i < quantityOfStudents; i++)
    {
        printf("Aluno %d: %.2f\n", (i+1),grade[i]);
    }

    free(grade);

    return 0;
}