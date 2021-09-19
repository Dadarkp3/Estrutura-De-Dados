#include <stdio.h>
#include <stdlib.h>

#define MAX_QTD_ALUNOS 100
#define MAX_QTD_PROVAS 4

int qtd_alunos, qtd_provas, peso_total_provas = 0, total_alunos = 0, opcao_menu = -1;
;
char ch;

typedef struct
{
	char nome[50];
	float notas_provas[MAX_QTD_PROVAS];
	int idade;
} Aluno;

void vermelho();
void verde();
void reset();
void abertura();
void menu();
void pegar_quantidade(char mensagem[], int *quantidade, int maximo, char mensagem_erro[]);
void pegar_peso_provas(int pesos[], int tamanho_vetor);
void sair_menu();
void error_alunos(char mensagem[]);

void menu_adicionar_aluno(Aluno alunos[]);
void adicionar_aluno(Aluno alunos[]);

void menu_relatorio_notas_alunos(Aluno alunos[], int pesos[]);
void relatorio_notas_alunos(Aluno alunos[], int pesos[]);

void menu_relatorio_notas_provas();
void iniciar_medias_provas(float medias_provas[]);
void relatorio_notas_provas(Aluno alunos[]);

void menu_lider_vice_lider(Aluno alunos[]);
void checar_idade_aluno(Aluno alunos[]);

int main()
{
	abertura();

	pegar_quantidade("Digite a quantidade de alunos a serem cadastrados: ", &qtd_alunos, MAX_QTD_ALUNOS, "\nNúmero de alunos excedido.\nTente novamente...");

	pegar_quantidade("Digite a quantidade de provas: ", &qtd_provas, MAX_QTD_PROVAS, "\nNúmero de provas excedido.\nTente novamente...");

	int pesos_provas[qtd_provas];
	pegar_peso_provas(pesos_provas, qtd_provas);

	Aluno alunos[qtd_alunos];

	do
	{
		menu();
		switch (opcao_menu)
		{
		case 1:
			menu_adicionar_aluno(alunos);
			break;

		case 2:
			menu_relatorio_notas_alunos(alunos, pesos_provas);
			break;

		case 3:
			menu_relatorio_notas_provas(alunos);
			break;
		case 4:
			menu_lider_vice_lider(alunos);
			break;
		case 5:
			break;

		default:
			printf("Número inválido! Aperte qualquer tecla para voltar ao menu de opções...");
			fflush(stdin);
			scanf("%c", &ch);
		}
	} while (opcao_menu != 5);

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
	printf("4. Imprimir líder e vice líder da classe.\n");
	printf("5. Sair\n\n");
	printf("/*****************************************/\n\n");
	reset();
	printf("Digite a opção desejada: ");
	fflush(stdin);
	scanf("%d", &opcao_menu);
}

void sair_menu()
{
	printf("\n\nAperte a tecla");
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

void menu_adicionar_aluno(Aluno alunos[])
{
	system("clear");
	verde();
	printf("/******************************************/\n");
	printf("/*            ADICIONAR ALUNO             */\n");
	printf("/******************************************/\n\n");
	reset();
	adicionar_aluno(alunos);
	sair_menu();
}

void adicionar_aluno(Aluno alunos[])
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
		while (getchar() != '\n')
			;
		printf("Digite a idade do novo aluno: ");
		scanf("%d", &alunos[total_alunos].idade);
		for (int i = 0; i < qtd_provas; i++)
		{
			printf("Digite a nota da %dº prova: ", i + 1);
			while (getchar() != '\n')
				;
			scanf("%f", &alunos[total_alunos].notas_provas[i]);
		}
		printf("\n O aluno foi adicionado com sucesso.\n");
		total_alunos++;
	}
}

void menu_relatorio_notas_alunos(Aluno alunos[], int pesos[])
{
	system("clear");
	verde();
	printf("/******************************************/\n");
	printf("/*            NOTAS DOS ALUNOS            */\n");
	printf("/******************************************/\n\n");
	reset();
	relatorio_notas_alunos(alunos, pesos);
	sair_menu();
}

void relatorio_notas_alunos(Aluno alunos[], int pesos[])
{
	if (total_alunos == 0)
	{
		error_alunos("Nenhum aluno cadastrado neste momento.");
	}
	else
	{
		for (int i = 0; i < total_alunos; i++)
		{
			float media_ponderada = 0;
			for (int j = 0; j < qtd_provas; j++)
			{
				media_ponderada += (alunos[i].notas_provas[j] * pesos[j]) / peso_total_provas;
			}
			printf("%d. Nome: %s. Média Final: %.2f\n", i + 1, alunos[i].nome, media_ponderada);
		}
	}
}

void menu_relatorio_notas_provas(Aluno alunos[])
{
	system("clear");
	verde();
	printf("/******************************************/\n");
	printf("/*            RELATÓRIO PROVAS            */\n");
	printf("/******************************************/\n\n");
	reset();
	relatorio_notas_provas(alunos);
	sair_menu();
}

void iniciar_medias_provas(float medias_provas[])
{
	for (int i = 0; i < qtd_provas; i++)
	{
		medias_provas[i] = 0.0;
	}
}

void relatorio_notas_provas(Aluno alunos[])
{
	float media_prova;
	if (total_alunos == 0)
	{
		error_alunos("Nenhum aluno cadastrado neste momento.");
	}
	else
	{
		for (int i = 0; i < qtd_provas; i++)
		{
			media_prova = 0;
			for (int j = 0; j < total_alunos; j++)
			{
				media_prova += (alunos[j].notas_provas[i]) / total_alunos;
			}
			printf("%dª Prova - Média da Turma: %.2f\n", i + 1, media_prova);
		}
	}
}

void menu_lider_vice_lider(Aluno alunos[])
{
	system("clear");
	verde();
	printf("/******************************************/\n");
	printf("/*           LIDER E VICE LIDER           */\n");
	printf("/******************************************/\n\n");
	reset();
	checar_idade_aluno(alunos);
	sair_menu();
}

void checar_idade_aluno(Aluno alunos[])
{
	Aluno lider;
	Aluno vice_lider;
	//Iniciando o lider e o vice lider com um valor inferior ao mínimo da idade
	lider.idade = vice_lider.idade = -1;

	if (total_alunos == 0)
	{
		error_alunos("Nenhum aluno cadastrado neste momento.");
	}
	else
	{
		if (total_alunos == 1)
		{
			printf("O líder da turma é %s. Não temos um vice líder ainda.", alunos[total_alunos - 1].nome);
		}
		else
		{
			for (int i = 0; i < total_alunos; i++)
			{
				if (alunos[i].idade > lider.idade)
				{
					vice_lider = lider;
					lider = alunos[i];
				}
				else if (alunos[i].idade > vice_lider.idade && alunos[i].idade <= lider.idade)
				{
					vice_lider = alunos[i];
				}
			}
			printf("Líder da turma é %s. Vice líder é %s", lider.nome, vice_lider.nome);
		}
	}
}
