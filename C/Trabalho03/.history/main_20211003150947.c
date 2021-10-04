#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "alunos.h"
#include "auxiliar.h"
#include "menu.h"

typedef struct
{
    char nome[50];
    float notas_provas[MAX_QTD_PROVAS];
    int idade;
} Aluno;