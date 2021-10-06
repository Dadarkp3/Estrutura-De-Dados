#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

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

void abertura()
{
    verde();
    printf("/******************************************/\n");
    printf("/*         SISTEMAS DE SALA DE AULA       */\n");
    printf("/******************************************/\n\n");
    reset();
}

void menu(int *opcao_menu)
{
    amarelo();

    printf("\n");
    printf("/*****************************************/\n");
    printf("/*            MENU DE SELEÇÃO            */\n");
    printf("/*****************************************/\n\n");

    printf("1. Adicionar um novo aluno.\n");
    printf("2. Modificar a quantidade disponível de cadeiras.\n");
    printf("3. Remover a sala inteira.\n");
    printf("4. Imprimir Lista de Alunos.\n");
    printf("4. Sair\n\n");
    printf("/*****************************************/\n\n");
    reset();
    printf("Digite a opção desejada: ");
    fflush(stdin);
    scanf("%d", opcao_menu);
}

void mensagem_error_geral(char mensagem[])
{
	vermelho();
	printf("%s\n\n", mensagem);
	reset();
}

void sair_sub_menu()
{
	printf("\n\nAperte qualquer tecla");
	vermelho();
	printf(" ENTER ");
	reset();
	printf("para voltar ao menu de opções...");
	while (getchar() != '\n')
		;
	getchar();
	printf("\n\n");
	system("clear");
}
