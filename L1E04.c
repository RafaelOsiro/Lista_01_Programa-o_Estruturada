/*
Curso: Análise e Desenvolvimento de Sistemas
Disciplina: Programação Estruturada
Docente: Joyce Siqueira
Discente: Rafael Riki Ogawa Osiro (UC21100716)

4. Faça um algoritmo que leia até 30 letras e as escreva na ordem inversa (ou contrária) da que
foram lidas.
*/

//Libraries in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char word[30];

    fflush(stdin);
    printf("Digite uma palavra: \n");
    fgets(&word, 30, stdin);
    fflush(stdin);

    for (int i = strlen(word); i >= 0; i--)
    {
        if (word[i] != NULL && word[i] != "\n")
        {
            printf("%c", word[i]);
        }
        
    }

    return 0;
}