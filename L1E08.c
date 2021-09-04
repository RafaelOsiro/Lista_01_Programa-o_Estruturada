/*
Curso: Análise e Desenvolvimento de Sistemas
Disciplina: Programação Estruturada
Docente: Joyce Siqueira
Discente: Rafael Riki Ogawa Osiro (UC21100716)

8. Faça um algoritmo que leia a idade de até 100 pessoas e apresente a média entre todas, além de  identificar  a  mais  
velha  e  a  posição  em  que  ela  se  encontra  no  vetor.  A  idade  mais  velha pode aparecer em mais de uma posição.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//MARK: MESSAGE IN THE SYSTEM
void printAskAgeMessage(int index);
void printAgeErrorMessage(int age);
void printResult(int highestAge, float averageAge, int *peopleAge,int quantityOfPeople);

//MARK: Functions in the system
bool validatePeopleAge(int age);
float ageAverageCalculate(int *peopleAge, int quantityOfPeople);
int findHighestAge(int *peopleAge, int quantityOfPeople);

int main()
{
    int peopleAge[100], quantityOfPeople, highestAge;
    float ageAverage;
    bool ageValidation = false;

    quantityOfPeople = (sizeof(peopleAge)/sizeof(int));

    for (int i = 0; i < quantityOfPeople; i++)
    {
        do
        {
            printAskAgeMessage(i);
            scanf("%d", &peopleAge[i]);
            ageValidation = validatePeopleAge(peopleAge[i]);
        } while (ageValidation != true); 
        
        ageValidation = false; 
        system("cls");
    }
    
    ageAverage = ageAverageCalculate(peopleAge, quantityOfPeople);
    highestAge = findHighestAge(peopleAge, quantityOfPeople);
    printResult(highestAge, ageAverage, peopleAge, quantityOfPeople);

    return 0;
}

/*
    !FUNCTIONS IN THE SYSTEM
*/

/*MARK: MESSAGE IN THE SYSTEM
------------------------------------------------------------------------------------------------------------------------*/

//Will print messagem in the system
void printAskAgeMessage(int index)
{
    printf("Digite a idade da pessoa %d\n", (index+1));
    printf(": ");
}

void printAgeErrorMessage(int age)
{
    printf("Erro!\n");
    printf("A idade %d nao e valida!\n\n\n", age);
}

void printResult(int highestAge, float averageAge, int *peopleAge,int quantityOfPeople)
{
    int quantityOfHighestAge = 0;

    for (int i = 0; i < quantityOfPeople; i++)
    {
        if (peopleAge[i] == highestAge)
        {
            quantityOfHighestAge++;
        }
    }

    system("cls");
    printf("A media de idade das pessoas e: %.2f\n", averageAge);
    printf("A maior idade e: %d\n", highestAge);
    quantityOfHighestAge == 1? printf("Se encontra na seguinte posicao: ") : printf("Se encontra nas seguintes posicoes: ");

    for (int i = 0; i < quantityOfPeople; i++)
    {
        if (peopleAge[i] == highestAge && (i+1) != quantityOfPeople)
        {
            printf("%d, ", (i+1));
        }
        else if (peopleAge[i] == highestAge && (i+1) == quantityOfPeople)
        {
            printf("%d.\n", (i+1));
        }
    }
}

/*MARK: FUNCTIONS
------------------------------------------------------------------------------------------------------------------------*/

//Will validate user's age
bool validatePeopleAge(int age)
{
    if (age > 0)
    {
        return true;
    }
    else
    {
        system("cls");
        printAgeErrorMessage(age);
        return false;
    }
}

//Will calculate people age average
float ageAverageCalculate(int *peopleAge, int quantityOfPeople)
{
    float average = 0;
    for (int i = 0; i < quantityOfPeople; i++)
    {
        average = average + peopleAge[i];
    }
    return (average/quantityOfPeople);
}

//Will find the highest age of the array
int findHighestAge(int *peopleAge, int quantityOfPeople)
{
    int highestAge = 0;
    for (int i = 0; i < quantityOfPeople; i++)
    {
        if (peopleAge[i] > highestAge)
        {
            highestAge = peopleAge[i];
        }
    }
    return highestAge;
}
