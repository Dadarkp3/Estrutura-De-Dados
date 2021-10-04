#include <stdio.h>
#include "auxiliar.h"

void vermelho()
{
    printf("\033[1;31m");
    printf("vermelho");
}

void verde()
{
    printf("\033[0;32m");
}

void amarelo()
{
    printf("\033[1;33m");
}

void reset()
{
    printf("\033[0m");
}
