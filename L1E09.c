/*
Curso: Análise e Desenvolvimento de Sistemas
Disciplina: Programação Estruturada
Docente: Joyce Siqueira
Discente: Rafael Riki Ogawa Osiro (UC21100716)

9. Uma grande empresa deseja saber quais os três empregados mais recentes. Fazer um algoritmo para  ler  um  
número indeterminado  de  informações  (máximo  de  50)  contendo  a  matrícula funcional  do  empregado  e  o  
número  de  meses  de  trabalho  deste  empregado.  Mostre  os  três empregados  mais  recentes. Não  existem  
dois  empregados  admitidos  no  mesmo  mês  e  a matrícula igual a zero ‘0’ encerra a leitura.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//! MESSAGES OF THE SYSTEM______________________________________________________________________________________
void printRegistrationMessage(int index);
void printMonthHiredMessage(int index);
void printReportMessage(int *arrayRegistrationId, int *arrayMonthHired);

//! ERROR MESSAGES OF THE SYSTEM________________________________________________________________________________
void errorEmployeeRegistrationIsRepeated();
void errorEmployeeMonthRegistrationIsRepeated();

//! FUNCTIONS OF THE SYSTEM_____________________________________________________________________________________
bool verifyEmployeeRegistration(int numberEntered, int *employeeRegistration,int index);
bool verifyMonthHired(int monthHired, int *arrayMonthHired, int index);
void bubleSort(int *arrayRegistrationId, int *arrayMonthHired, int quantityOfElements);

int main() 
{
    int registrationId[5], monthHired[5], idAux, hiredAux, quantityOfEmployee;
    bool validation = false;

    quantityOfEmployee = (sizeof(registrationId)/sizeof(int));

    for (int i = 0; i < quantityOfEmployee; i++)
    {
        do
        {
            printRegistrationMessage(i);
            scanf("%d", &idAux);
            validation = verifyEmployeeRegistration(idAux, registrationId, i);
            
            if (validation == true && idAux != 0)
            {
                registrationId[i] = idAux;
            }
            else if (idAux == 0)
            {
                break;
            }

        } while (validation != true);
        
        if (idAux == 0)
        {
            break;
        }

        validation = false;

        if (registrationId != 0)
        {
            do
            {
                printMonthHiredMessage(i);
                scanf("%d", &hiredAux);
                validation = verifyMonthHired(hiredAux, monthHired, i);
                
            if (validation == true)
            {
                monthHired[i] = hiredAux;
            }
                
            } while (validation != true);
        }
    }

    bubleSort(registrationId, monthHired, quantityOfEmployee);

    printReportMessage(registrationId, monthHired);

    return 0;
}

//! MESSAGE OF THE SYSTEM_______________________________________________________________________________________

//Print a message that will ask user to input employee registration
void printRegistrationMessage(int index)
{
    printf("Digite a matricula do funcionario %d: ", (index + 1));
}

//Print a message that will ask user to input employee month hired 
void printMonthHiredMessage(int index)
{
    printf("Digite o mes de registro do funcionario %d: ", (index + 1));
}

void printReportMessage(int *arrayRegistrationId, int *arrayMonthHired)
{
    system("cls");
    printf("Os tr\210s funcion\240rios mais novos da empresa: \n");
    printf("Matricula\tMeses\n");
    for (int i = 0; i < 3; i++)
    {
        printf("  %d\t\t%d\n", arrayRegistrationId[i], arrayMonthHired[i]);
    }
}

//! ERROR MESSAGE OF THE SYSTEM__________________________________________________________________________________

//Prints a message that employee registration is repeated
void errorEmployeeRegistrationIsRepeated()
{
    system("cls");
    printf("Erro!\n");
    printf("A matricula do funcionario esta repetdio!\n\n\n");
}

void errorEmployeeMonthRegistrationIsRepeated()
{
    system("cls");
    printf("Erro!\n");
    printf("O mes contratado esta repetido!\n\n\n");
}

//! FUNCTIONS OF THE SYSTEM______________________________________________________________________________________

//Verify a person 
bool verifyEmployeeRegistration(int registrationId, int *arrayRegistrationId,int index)
{
    bool validation = false;

    if (index == 0)
    {
        system("cls");
        return true;
    }
    else
    {
        for(int i = 0; i < index; i++)
        {
            if (registrationId != arrayRegistrationId[i])
            {
                validation = true;
            }
            else
            {
                errorEmployeeRegistrationIsRepeated();
                return false;
            }
        }

        if(validation == true)
        {
            system("cls");
            return true;
        }
        else
        {
            errorEmployeeRegistrationIsRepeated();
            return false;
        }
    }
}

//Verify 
bool verifyMonthHired(int monthHired, int *arrayMonthHired, int index)
{
    bool validation = false;

    if (index == 0)
    {
        system("cls");
        return true;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            if (monthHired != arrayMonthHired[i])
            {
                validation = true;
            }
            else
            {
                errorEmployeeMonthRegistrationIsRepeated();
                return false;
            }
        }
        
        if (validation == true)
        {
            system("cls");
            return true;
        }
        else
        {
            errorEmployeeRegistrationIsRepeated();
            return false;
        }
    }    
}

void bubleSort(int *arrayRegistrationId, int *arrayMonthHired, int quantityOfElements)
{
    for (int i = 0; i < (quantityOfElements-1); i++)
    {
        for (int j = (i+1); j < quantityOfElements; j++)
        {
            if (arrayMonthHired[i]>arrayMonthHired[j])
            {
                int aux1 = 0;
                int aux2 = 0;

                aux1 = arrayMonthHired[i];
                arrayMonthHired[i] = arrayMonthHired[j];
                arrayMonthHired[j] = aux1;

                aux2 = arrayRegistrationId[i];
                arrayRegistrationId[i] = arrayRegistrationId[j];
                arrayRegistrationId[j] = aux2;
            }
        }
    }
}