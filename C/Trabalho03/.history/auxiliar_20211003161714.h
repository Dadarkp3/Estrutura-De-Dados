#include <stdio.h>

void vermelho();
void verde();
void reset();
void amarelo();

void vermelho()
{
    printf("\033[1;31m");
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
