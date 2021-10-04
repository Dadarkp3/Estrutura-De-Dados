#include <stdio.h>;
#include "menu.h";
#include "auxiliar.h";

void abertura()
{
    verde();
    printf("/******************************************/\n");
    printf("/*            SISTEMAS DE NOTAS            */\n");
    printf("/******************************************/\n\n");
    reset();
}

void menu(int opcao_menu)
{
    system("clear");
    amarelo();

    printf("\n");
    printf("/*****************************************/\n");
    printf("/*            MENU DE SELEÇÃO            */\n");
    printf("/*****************************************/\n\n");

    printf("1. Adicionar um novo aluno a lista.\n");
    printf("2. Imprimir Relatório de Notas Alunos.\n");
    printf("3. Imprimir média das provas.\n");
    printf("4. Imprimir líder e vice líder da classe.\n");
    printf("5. Sair\n\n");
    printf("/*****************************************/\n\n");
    reset();
    printf("Digite a opção desejada: ");
    fflush(stdin);
    scanf("%d", &opcao_menu);
}