/*
Curso: Análise e Desenvolvimento de Sistemas
Disciplina: Programação Estruturada
Docente: Joyce Siqueira
Discente: Rafael Riki Ogawa Osiro (UC21100716)

7. Desenvolva um algoritmo que cadastre os preços de até 100 diferentes CDs em uma loja. Após este cadastro, o algoritmo 
deverá possibilitar a execução de uma de duas funções para aumento dos preços cadastrados, sendo a primeira de 10% para 
todos os CDs, enquanto a segunda aumenta o percentual informado pelo vendedor para todos os CDs. Será o vendedor que 
escolherá o tipo de aumento desejado. Após os cálculos deverá ser apresentado o percentual de aumento e, para cada CD, o 
valor sem aumento e o valor com aumento.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//MARK: Error Handling
void errorPriceIsLessThan0();   //Print error message if price is less than 0
void errorOption();
void printOptionInConsole();

//MARK: Functions in the sytem
bool validationPriceDisk(float price);  //Validate is less than 0
bool validationOption(int option);
bool validationPercentageInDiskPrice(float percentage);
void increseDiskPrice(float *diskPrice, float percentage, int quantityOfDisks);
void printPrice(float *diskPrice, int quantityOfDisks);

int main()
{
    //Variable declaration
    int optionToIncreasePrice, quantityOfDisks;
    float diskPrice[100], increasePrice;
    bool validatePrice = false, validateOption = false, validatePercentage = false;

    quantityOfDisks = (sizeof(diskPrice)/sizeof(float));

    for (int i = 0; i < quantityOfDisks; i++)
    {
        do
        {
            printf("Digite o preco do disco %d:\n", (i+1));
            scanf("%f", &diskPrice[i]);
            validatePrice = validationPriceDisk(diskPrice[i]);
        
        } while (validatePrice != true);
        validatePrice = false;
    }

    do
    {
        printOptionInConsole();
        scanf("%d", &optionToIncreasePrice);
        validateOption = validationOption(optionToIncreasePrice);
    } while (validateOption != true);

    switch (optionToIncreasePrice)
    {
    case 1:
        increasePrice = 10.00/100;
        // for (int i = 0; i < (sizeof(diskPrice)/sizeof(float)); i++)
        // {
        //     diskPrice[i] = diskPrice[i] + (diskPrice[i] * increasePrice);
        // }
        increseDiskPrice(diskPrice, increasePrice, quantityOfDisks);
        printPrice(diskPrice, quantityOfDisks);
        break;
    case 2:
        do
        {
            printf("Digite o percentual a ser aumentado: \n");
            scanf("%f", &increasePrice);
            validatePercentage = validationPercentageInDiskPrice(increasePrice);
        } while (validatePercentage != true);
        
        increasePrice = (increasePrice/100);
        increseDiskPrice(diskPrice, increasePrice, quantityOfDisks);
        printPrice(diskPrice, quantityOfDisks);
        break;
    }
    return 0;
}

/*
    !FUNCTIONS IN THE SYSTEM
*/

//MARK: Messages of the system

void errorPriceIsLessThan0()
{
    printf("Erro!\n");
    printf("O preco deve ser maior ou igual a 0!\n\n\n");
}

void errorOption()
{
    printf("Erro!\n");
    printf("Opcao selecionada e invalida!\n");
    printf("Digite a opcao 1 ou 2\n\n\n");
}

//Function that will print options in the system
void printOptionInConsole()
{
    printf("Digite a opcao desejada:\n");
    printf("1 - Aumentar 10%%.\n");
    printf("2 - Aumentar o percentual manualmente.\n");
    printf(": ");
}

void errorPercentage()
{
    printf("Erro!\n");
    printf("O percentual deve ser maior do que 0\n\n\n");
}

//MARK: Functions in the sytem

//
bool validationPriceDisk(float price)
{

    if (price >= 0)
    {
        system("cls");
        return true;
    }
    else
    {
        system("cls");
        errorPriceIsLessThan0();
        return false;
    }
}

//Function that will pick 
bool validationOption(int option)
{
    switch (option)
    {
    case 1:
        system("cls");
        return true;
        break;
    case 2:
        system("cls");
        return true;
        break;
    default:
        system("cls");
        errorOption();
        return false;
        break;
    }
}

//Function that will validate if user's percentage is valid
bool validationPercentageInDiskPrice(float percentage)
{
    if (percentage > 0)
    {
        system("cls");
        return true;
    }
    else
    {
        system("cls");
        void errorPercentage();
        return false;
    }
}

//Function that will increase all disk's prices
void increseDiskPrice(float *diskPrice, float percentage, int quantityOfDisks)
{
 for (int i = 0; i < quantityOfDisks; i++)
    {
        diskPrice[i] = diskPrice[i] + (diskPrice[i] * percentage);
    }
}

//
void printPrice(float *diskPrice, int quantityOfDisks)
{
    for (int i = 0; i < quantityOfDisks; i++)
    {
        printf("Disco %d - R$ %.2f\n", (i+1), diskPrice[i]);
    }
}