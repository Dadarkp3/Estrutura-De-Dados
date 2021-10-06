#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "operacoes.h"

int main()
{
    int opcao_menu = -1, quantidade_cadeiras_disponiveis = 0, quantidade_alunos_cadastrados = 0;
    char ch;
    Aluno *alunos = NULL;
    abertura();
    menu_iniciar_sala(&alunos, &quantidade_cadeiras_disponiveis);
    printf("%d", quantidade_cadeiras_disponiveis);
    do
    {
        menu(&opcao_menu);
        switch (opcao_menu)
        {
        case 1:
            menu_adicionar_novo_aluno(&alunos, &quantidade_cadeiras_disponiveis, &quantidade_alunos_cadastrados);
            break;
        case 2:
            menu_modificar_quantidade_cadeiras(&alunos, &quantidade_cadeiras_disponiveis, &quantidade_alunos_cadastrados);
            break;
        case 3:
            menu_libera_sala(&alunos, &quantidade_cadeiras_disponiveis, &quantidade_alunos_cadastrados);
            break;
        case 4:
            imprimir(alunos, quantidade_alunos_cadastrados);
            break;
        case 5:
            break;
        default:
            printf("Número inválido! Aperte qualquer tecla para voltar ao menu de opções...");
            fflush(stdin);
            scanf("%c", &ch);
        }
    }
    while (opcao_menu != 5);

    return 0;
}
