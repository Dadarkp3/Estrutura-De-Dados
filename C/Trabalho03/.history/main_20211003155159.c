#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "auxiliar.h"
#include "alunos.h"
#include "menu.h"

typedef struct
{
    int id;
    char nome[50];
    int idade;
} Aluno;

int main()
{
    abertura();
    return 0;
}