/*
Curso: Análise e Desenvolvimento de Sistemas
Disciplina: Programação Estruturada
Docente: Joyce Siqueira
Discente: Rafael Riki Ogawa Osiro (UC21100716)

10.Elabore um algoritmo que leia um conjunto de valores inteiros correspondentes a até 80 notas, variando de 0 a 
10, dos alunos de uma turma (vários alunos).  Calcule a frequência de cada nota e apresente uma tabela contendo 
os valores das notas e suas respectivas frequências.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ! MESSAGE OF THE SYSTEM______________________________________________________________________________________
void askUserMessage(int index);
void gradeErrorMessage();

// ! FUNCTIONS IN THE SYSTEM____________________________________________________________________________________
bool gradeValidation(float grade);
void report(float *grade, int quantityOfStudents);
// float *calculateFrequency(float *grade, int quantityOfStudents);

int main()
{
    int quantityOfGrade;
    float grade[80], *frequency;
    bool validation = false;

    quantityOfGrade = (sizeof(grade)/sizeof(float));

    for (int i = 0; i < quantityOfGrade; i++)
    {
        do
        {
            askUserMessage(i+1);
            scanf("%f", &grade[i]);
            validation = gradeValidation(grade[i]);
        } while (validation == false);
        validation = false;
    }

    // frequency = calculateFrequency(grade, quantityOfGrade);
    
    report(grade, quantityOfGrade);

    return 0;
}

// ! MESSAGE OF THE SYSTEM______________________________________________________________________________________
void askUserMessage(int index)
{
    printf("Digite a nota do aluno %d: \n", index);
}

void gradeErrorMessage()
{
    system("cls");
    printf("Erro!\n");
    printf("Nota invalida!\n\n\n");
}

// ! FUNCTIONS IN THE SYSTEM____________________________________________________________________________________
bool gradeValidation(float grade)
{
    if (grade >= 0 && grade <= 10)
    {
        system("cls");
        return true;
    }
    else
    {
        gradeErrorMessage();
        return false;
    }
}

void report(float *grade, int quantityOfStudents)
{
    int *frequencyArray;

    frequencyArray = (int*) malloc(quantityOfStudents*sizeof(int));

    for (int i = 0; i < quantityOfStudents; i++)
    {
        int frequency = 1;

        if (grade[i] != -1)
        {
            for (int j = (i+1); j < quantityOfStudents; j++)
            {
                if(grade[i] == grade[j])
                {
                    frequency++;
                    grade[j] = -1;
                }
            }

            frequencyArray[i] = frequency;
        }
    }

    printf("Notas:\tFrequencia\n");

    for (int i = 0; i < quantityOfStudents; i++)
    {
        if (grade[i] != -1)
        {
            printf("Nota %.2f:\t%d\n", grade[i], frequencyArray[i]);
        }
    }

    free(frequencyArray);
}