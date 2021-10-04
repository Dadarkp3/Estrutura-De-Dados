#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "alunos.h"
#include "auxiliar.h"
#include "menu.h"

typedef struct
{
    int id;
    char nome[50];
    int idade;
} Aluno;