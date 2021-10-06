#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "operacoes.h"

void menu_iniciar_sala(Aluno **alunos, int * quantidade_cadeiras_disponiveis)
{
    amarelo();
    printf("/******************************************/\n");
    printf("/*        CRIAR NOVA SALA DE AULA         */\n");
    printf("/******************************************/\n\n");
    reset();

    do
    {
        printf("Digite a quantidade inicial de cadeiras disponíveis: ");
        scanf("%d", quantidade_cadeiras_disponiveis);
        if(*quantidade_cadeiras_disponiveis < 0 || *quantidade_cadeiras_disponiveis >= MAX_ALUNOS)
        {
            system("clear");
            printf("Digite um valor válido entre 1 e %d\n\n", MAX_ALUNOS - 1);
        }
        else
        {
            *alunos = (Aluno *) malloc(*quantidade_cadeiras_disponiveis * sizeof(Aluno));
            printf("\nUma nova sala foi criada com uma quantidade inicial de ");
            amarelo();
            printf("%d cadeiras ", *quantidade_cadeiras_disponiveis);
            reset();
            printf("disponíveis.\n");
            reset();
        }
    }
    while(*quantidade_cadeiras_disponiveis < 0 || *quantidade_cadeiras_disponiveis >= MAX_ALUNOS);

    sair_sub_menu();
}

void menu_adicionar_novo_aluno(Aluno ** alunos, int * quantidade_cadeiras_disponiveis, int * quantidade_alunos_cadastrados)
{
    system("clear");
    amarelo();
    printf("/******************************************/\n");
    printf("/*           ADICIONAR ALUNO NOVO         */\n");
    printf("/******************************************/\n\n");
    reset();

    if(*quantidade_alunos_cadastrados >= MAX_ALUNOS - 1)
    {
        mensagem_error_geral("A quantidade máxima de alunos já foi alcançada.");
    }
    else
    {
        if(*quantidade_alunos_cadastrados >= *quantidade_cadeiras_disponiveis)
        {
            *quantidade_cadeiras_disponiveis = *quantidade_cadeiras_disponiveis + 1;
            *alunos = realloc(*alunos, *quantidade_cadeiras_disponiveis * sizeof(Aluno));

        }
        printf("Digite o nome do novo aluno: ");
        while (getchar() != '\n');
        scanf("%50[0-9a-zA-Z ]", (*alunos)[*quantidade_alunos_cadastrados].nome);
        while (getchar() != '\n');
        printf("Digite a idade do novo aluno: ");
        scanf("%d", &(*alunos)[*quantidade_alunos_cadastrados].idade);
        printf("\nO aluno %s foi adicionado com sucesso.\n", (*alunos)[*quantidade_alunos_cadastrados].nome);
        *quantidade_alunos_cadastrados = *quantidade_alunos_cadastrados + 1;
    }

    sair_sub_menu();
}

void menu_modificar_quantidade_cadeiras(Aluno ** alunos, int * quantidade_cadeiras_disponiveis, int * quantidade_alunos_cadastrados)
{
    system("clear");
    amarelo();
    printf("/******************************************/\n");
    printf("/*      MODIFICAR QUANTIDADE CADEIRAS     */\n");
    printf("/******************************************/\n\n");
    reset();

    int nova_quantidade_cadeiras = -1;
    do
    {
        printf("Digite a nova quantidade de cadeiras disponíveis: ");
        scanf("%d", &nova_quantidade_cadeiras);
        if(nova_quantidade_cadeiras < 0 || nova_quantidade_cadeiras >= MAX_ALUNOS)
        {
            system("clear");
            printf("Digite um valor válido entre 1 e %d\n\n", MAX_ALUNOS - 1);
        }
        else
        {
            if(nova_quantidade_cadeiras < *quantidade_alunos_cadastrados)
            {
                *quantidade_alunos_cadastrados = nova_quantidade_cadeiras;
            }
            *quantidade_cadeiras_disponiveis = nova_quantidade_cadeiras;
            *alunos = realloc(*alunos, nova_quantidade_cadeiras * sizeof(Aluno));
        }
    }
    while(nova_quantidade_cadeiras < 0 || nova_quantidade_cadeiras >= MAX_ALUNOS);
    printf("A nova quantidade de cadeiras disponíveis é de %d cadeiras.\n", *quantidade_cadeiras_disponiveis);

    sair_sub_menu();
}

void menu_libera_sala(Aluno ** alunos, int * quantidade_cadeiras_disponiveis, int * quantidade_alunos_cadastrados)
{
    system("clear");
    amarelo();
    printf("/******************************************/\n");
    printf("/*           LIBERAR SALA DE AULA           */\n");
    printf("/******************************************/\n\n");
    reset();
    free(*alunos);
    *alunos = NULL;
    *quantidade_alunos_cadastrados = 0;
    *quantidade_cadeiras_disponiveis = 0;
    printf("A sala foi liberada, não temos mais cadeiras disponíveis nem alunos cadastrados.\n");
    sair_sub_menu();
}

void imprimir(Aluno * alunos, int quantidade_alunos_cadastrados)
{
    system("clear");
    amarelo();
    printf("/******************************************/\n");
    printf("/*             LISTA DE ALUNOS            */\n");
    printf("/******************************************/\n\n");
    reset();
    for(int i = 0; i < quantidade_alunos_cadastrados; i++)
    {
        printf("Nome: %s, Idade: %d\n", alunos[i].nome, alunos[i].idade);
    }
    sair_sub_menu();
}
