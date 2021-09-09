#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_QTD_ALUNOS 100
#define MAX_QTD_PROVAS 4
#define TAMANHO(vetor) (sizeof(vetor) / sizeof((vetor)[0]))

int qtd_alunos, qtd_provas, opcao_menu = -1, peso_total_provas = 0, total_alunos = 0;
char ch;
float media_aritmetica;

struct Aluno
{
	char nome[50];
	float notas_provas[MAX_QTD_PROVAS];
	float media_ponderada;
};

void vermelho();
void verde();
void reset();
void abertura();
void pegar_quantidade(char mensagem[], int *quantidade, int maximo, char mensagem_erro[]);
void pegar_peso_provas(int pesos[], int tamanho_vetor);
void menu();
void menu_adicionar_aluno(struct Aluno alunos[], int pesos[], float medias_provas[]);
void menu_relatorio_notas_alunos(struct Aluno alunos[]);
void menu_relatorio_notas_provas(float medias_provas[]);
void adicionar_aluno(struct Aluno alunos[], int pesos[], float medias_provas[]);
void iniciar_medias_provas(float medias_provas[]);
void relatorio_notas_provas(float medias_provas[]);
void relatorio_notas_alunos(struct Aluno alunos[]);
void sair_menu();
void error_alunos(char mensagem[]);

int main()
{
	abertura();

	pegar_quantidade("Digite a quantidade de alunos a serem cadastrados: ", &qtd_alunos, MAX_QTD_ALUNOS, "\nNúmero de alunos excedido.\nTente novamente...");

	pegar_quantidade("Digite a quantidade de provas: ", &qtd_provas, MAX_QTD_PROVAS, "\nNúmero de provas excedido.\nTente novamente...");

	int pesos_provas[qtd_provas];
	float media_classe_provas[qtd_provas];
	pegar_peso_provas(pesos_provas, qtd_provas);

	struct Aluno alunos[qtd_alunos];

	iniciar_medias_provas(media_classe_provas);

	do
	{
		menu();
		switch (opcao_menu)
		{
		case 1:
			menu_adicionar_aluno(alunos, pesos_provas, media_classe_provas);
			break;

		case 2:
			menu_relatorio_notas_alunos(alunos);
			break;

		case 3:
			menu_relatorio_notas_provas(media_classe_provas);
			break;
		case 4:
			break;

		default:
			printf("Número inválido! Aperte qualquer tecla para voltar ao menu de opções...");
			fflush(stdin);
			scanf("%c", &ch);
		}
	} while (opcao_menu != 4);

	return 0;
}

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
	printf("/*            SISTEMAS DE NOTAS            */\n");
	printf("/******************************************/\n\n");
	reset();
}

void pegar_quantidade(char mensagem[], int *quantidade, int maximo, char mensagem_erro[])
{
	do
	{
		printf("%s", mensagem);
		scanf("%d", quantidade);
		if (*quantidade < 0 || *quantidade >= maximo)
		{
			vermelho();
			printf("%s", mensagem_erro);
			reset();
		}
	} while (*quantidade < 0 || *quantidade >= maximo);
}

void pegar_peso_provas(int pesos[], int tamanho_vetor)
{
	verde();

	printf("\n");
	printf("/*****************************************/\n");
	printf("/*           CADASTRO DE PESOS           */\n");
	printf("/*****************************************/\n\n");

	reset();

	for (int i = 0; i < tamanho_vetor; i++)
	{
		printf("Digite o peso da prova %d: ", i + 1);
		fflush(stdin);
		scanf("%d", &pesos[i]);
		peso_total_provas += pesos[i];
	}
	reset();
}

void menu()
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
	printf("4. Sair\n\n");
	printf("/*****************************************/\n\n");
	reset();
	printf("Digite a opção desejada: ");
	fflush(stdin);
	scanf("%d", &opcao_menu);
}

void menu_adicionar_aluno(struct Aluno alunos[], int pesos[], float medias_provas[])
{
	system("clear");
	verde();
	printf("/******************************************/\n");
	printf("/*            ADICIONAR ALUNO             */\n");
	printf("/******************************************/\n\n");
	reset();
	adicionar_aluno(alunos, pesos, medias_provas);
	sair_menu();
}

void menu_relatorio_notas_alunos(struct Aluno alunos[])
{
	system("clear");
	verde();
	printf("/******************************************/\n");
	printf("/*            NOTAS DOS ALUNOS            */\n");
	printf("/******************************************/\n\n");
	reset();
	relatorio_notas_alunos(alunos);
	sair_menu();
}

void menu_relatorio_notas_provas(float medias_provas[])
{
	system("clear");
	verde();
	printf("/******************************************/\n");
	printf("/*            RELATÓRIO PROVAS            */\n");
	printf("/******************************************/\n\n");
	reset();
	relatorio_notas_provas(medias_provas);
	sair_menu();
}

void adicionar_aluno(struct Aluno alunos[], int pesos[], float medias_provas[])
{
	if (total_alunos >= qtd_alunos)
	{
		error_alunos("Quantidade máxima de alunos cadastrados.");
	}
	else
	{
		system("clear");
		verde();
		printf("/******************************************/\n");
		printf("/*          ADICIONAR NOVO ALUNO          */\n");
		printf("/******************************************/\n\n");
		reset();
		printf("Digite o nome do novo aluno: ");
		while (getchar() != '\n')
			;
		scanf("%50[0-9a-zA-Z ]", alunos[total_alunos].nome);
		for (int i = 0; i < qtd_provas; i++)
		{
			printf("Digite a nota da %dº prova: ", i + 1);
			while (getchar() != '\n')
				;
			scanf("%f", &alunos[total_alunos].notas_provas[i]);
			alunos[total_alunos].media_ponderada += (alunos[total_alunos].notas_provas[i] * pesos[i]) / peso_total_provas;
			medias_provas[i] += alunos[total_alunos].notas_provas[i] / qtd_alunos;
		}
		printf("\nO aluno de nome %s de média ponderada %.2f foi adicionado com sucesso.\n\n", alunos[total_alunos].nome, alunos[total_alunos].media_ponderada);
		total_alunos++;
	}
}

void iniciar_medias_provas(float medias_provas[])
{
	for (int i = 0; i < qtd_provas; i++)
	{
		medias_provas[i] = 0.0;
	}
}

void relatorio_notas_provas(float medias_provas[])
{
	if (total_alunos == 0)
	{
		error_alunos("Nenhum aluno cadastrado neste momento.");
	}
	else
	{
		for (int i = 0; i < qtd_provas; i++)
		{
			printf("A prova %d, teve como média da turma: %.2f\n", i + 1, medias_provas[i]);
		}
	}
}

void relatorio_notas_alunos(struct Aluno alunos[])
{
	if (total_alunos == 0)
	{
		error_alunos("Nenhum aluno cadastrado neste momento.");
	}
	else
	{
		for (int i = 0; i < total_alunos; i++)
		{
			printf("%d. Nome: %s. Média Final: %.2f\n", i + 1, alunos[i].nome, alunos[i].media_ponderada);
		}
	}
}

void sair_menu()
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
}

void error_alunos(char mensagem[])
{
	vermelho();
	printf("%s\n\n", mensagem);
	reset();
}
