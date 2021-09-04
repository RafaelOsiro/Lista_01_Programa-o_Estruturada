/*
Curso: Análise e Desenvolvimento de Sistemas
Disciplina: Programação Estruturada
Docente: Joyce Siqueira
Discente: Rafael Riki Ogawa Osiro (UC21100716)

6. Fazer um algoritmo/programa que leia a matricula e o salário dos funcionários de uma empresa (máximo de 100 
funcionários). Após a leitura de todos os dados, informe em uma tela limpa os dados lidos e o maior e menor salário dos 
funcionários. O maior e menor salário deverão ser obtidos, cada um, por uma função. Sabe-se ainda que não existe 
matrícula repetida na empresa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//! ERROR HANDLING OF THE SYSTEM
void errorEmployeeRegistrationIsLessThan0();
void errorEmployeeRegistrationIsRepeated();
void errorSalaryIsBelowOrEqual0();

//!FUNCTIONS OF THE SYSTEM
bool validateEmployeeRegistration (int number, int *employeeRegistration, int index);
bool validateSalary (float salary);
void sortingSalary (int *employeeRegistration, float *employeeSalary);
void employeeReport (int *employeeRegistration, float *employeeSalary, int sizeOfArray);

int main() 
{
    //Variable declaration
    int employeeRegistration[100];
    float salary[100];
    bool validationEmployeeRegistration = false, validationSalary = false;
    char *cleanBuffer;

    //Looping to interating all the arrays to fill with employee registration and salary
    for (int i = 0; i < (sizeof(employeeRegistration)/sizeof(int)); i++)
    {
        //This will validate if employee registration is valid and if it's not repeated
        do
        {
            printf("Digite a matricula do funcionario: \n");
            scanf("%d", &employeeRegistration[i]);
            scanf("%c", &cleanBuffer);
            fflush(stdin);
            validationEmployeeRegistration = validateEmployeeRegistration(employeeRegistration[i], employeeRegistration, i);

        } while (validationEmployeeRegistration == false);
        
        system("cls");
        validationEmployeeRegistration = false;

        //This will validate if employee salary it's not negative number
        do
        {
            printf("Digite o salario do funcionario: \n");
            scanf("%f", &salary[i]);
            fflush(stdin);
            validationSalary = validateSalary(salary[i]);

        } while (validationSalary == false);

        system("cls");
        validationSalary = false;
    }

    sortingSalary(employeeRegistration, salary);
    employeeReport(employeeRegistration, salary, (sizeof(employeeRegistration)/sizeof(int)));
    return 0;
}

//!------------------------------!\\
//! ERROR HANDLING OF THE SYSTEM !\\
//!------------------------------!\\

//Error Message of the system!
void errorEmployeeRegistrationIsLessThan0()
{
    system("cls");
    printf("Erro!\n");
    printf("A matricula devera ser maior do que 0!\n\n\n");
}

void errorEmployeeRegistrationIsRepeated()
{
    system("cls");
    printf("Erro!\n");
    printf("A matricula do funcionario esta repetido!\n\n\n");
}

void errorSalaryIsBelowOrEqual0()
{
    system("cls");
    printf("Erro!\n");
    printf("O Salario do funcionario devera ser maior do que 0!\n\n\n");
}

//!-------------------------!\\
//! FUNCTIONS OF THE SYSTEM !\\
//!-------------------------!\\

//Function that will validate employee registration
bool validateEmployeeRegistration (int number, int *employeeRegistration, int index)
{
    bool firstForValidation = false;

    if (number > 0)
    {
        if (index == 0)
        {
            return true;
        }
        else
        {
            for (int i = 0; i < index; i++)
            {
                if (number != employeeRegistration[i])
                {
                    firstForValidation = true;
                }
                else
                {
                    system("cls");
                    errorEmployeeRegistrationIsRepeated();
                    return false;
                }
            }

            if(firstForValidation == true)
            {
                return true;
            }
            else
            {
                system("cls");
                errorEmployeeRegistrationIsRepeated();
                return false;
            }
        }
    }
    else
    {
        errorEmployeeRegistrationIsLessThan0();
        return false;
    }
}

//Function that will validate employee salary
bool validateSalary (float salary)
{
    if (salary > 0)
    {
        return true;
    }
    else
    {
        errorSalaryIsBelowOrEqual0();
        return false;
    }
}

//Function that will sort registration and salary of the employee
void sortingSalary (int *employeeRegistration, float *employeeSalary)
{
int *registration;
float *salary;

    for (int i = 0; i < ((sizeof(employeeRegistration)/sizeof(int))-1); i++)
    {
        for (int j = i+1; j < (sizeof(employeeRegistration)/sizeof(int)); j++)
        {
            if(employeeSalary[i] > employeeSalary[j])
            {
                float tempSalary = 0;
                int tempRegistration = 0;

                tempSalary = employeeSalary[j];
                employeeSalary[j] = employeeSalary[i];
                employeeSalary[i] = tempSalary;

                tempRegistration = employeeRegistration[j];
                employeeRegistration[j] = employeeRegistration[i];
                employeeRegistration[i] = tempRegistration;
            }
        }
    }
}

//Function that will print employee registration and salary
void employeeReport (int *employeeRegistration, float *employeeSalary, int sizeOfArray)
{
    printf("\t  ============================  \n");
    printf("\t|| RELATORIO DOS FUNCIONARIOS ||\n");
    printf("\t  ============================  \n\n\n\n");
    printf("POSICAO\t\tMATRICULA\tSALARIO (R$)\n");

    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("   %d\t\t   %d\t\t  R$ %.2lf\n", (i+1), employeeRegistration[i], employeeSalary[i]);
    }

}