#include <stdio.h>
#include <stdlib.h>

#define MAXIMO_DE_ALUNOS 100
#define MAXIMO_DE_PROVAS 4

//Declaro aqui, pois todas as funções vão usar isso.
int quantidade_de_alunos, quantidade_de_provas;

//Tipo primitivo de C, esse struct armazenas várias informações distintas de uma única pessoa/posição.
typedef struct
{
	char nome[30];
	float notas_da_prova[MAXIMO_DE_PROVAS];
	int idade;
} Aluno;

//Configuração Inicial do sistema
void configuracao();

//Cor do sistema
void verde();

//Método para adicionar Alunos e Provas
int adicionar_quantidade_alunos(int quantidade, int maximo);
int adicionar_quantidade_provas(int quantidade, int maximo);

void adicionar_aluno_no_menu(Aluno alunos[], int quantidade_alunos, int quantidade_provas);

void relatorio(Aluno alunos[], int pesos[], int quantidade_alunos, int quantidade_provas, int peso_total);

int main(void)
{
	int quantidade_alunos, quantidade_provas;

	configuracao();

	quantidade_alunos = adicionar_quantidade_alunos(quantidade_de_alunos, MAXIMO_DE_ALUNOS);
	//Com uma função int, eu consigo jogar o valor de retorno, no caso o número de alunos para uma variável.

	quantidade_provas = adicionar_quantidade_provas(quantidade_de_provas, MAXIMO_DE_PROVAS);

	int pesos_prova[quantidade_provas];
	int peso_total = 0;
	for (int i = 0; i < quantidade_provas; i++)
	{
		printf("Digite o peso da prova %d: ", i + 1);
		scanf("%d", &pesos_prova[i]);
		peso_total += pesos_prova[i];
	}

	printf("Quantiddade de Alunos: %d\n", quantidade_alunos);
	printf("Quantiddade de Provas: %d\n", quantidade_provas);
	printf("Peso total: %d\n", peso_total);

	Aluno alunos[quantidade_alunos];
	adicionar_aluno_no_menu(alunos, quantidade_alunos, quantidade_de_provas);

	relatorio(alunos, pesos_prova, quantidade_alunos, quantidade_provas, peso_total);

	return 0;
}

void verde() //Definir a cor das letras
{
	printf("\033[0;32m");
}

void configuracao() // Mensagem inicial do sistema
{
	verde();
	printf("/******************************************/\n");
	printf("/*            Configurando...           */\n");
	printf("/******************************************/\n\n");
}

//Pegar a quantidade de alunos...
int adicionar_quantidade_alunos(int quantidade, int maximo)
{

	do //Repetição, para o caso de erro, esse em especial, para o loop até aqui...
	{
		printf("Digite a quantidade de alunos a serem cadastrados: ");
		scanf("%d", &quantidade);
		if (quantidade < 0 || quantidade >= maximo)
		{
			printf("Número de alunos, incongruente, escolha um número de 1 à 99...\n");
		}
	}												// Fim do loop do "do"
	while (quantidade < 0 || quantidade >= maximo); //Repetir a função em caso de erro.
	return quantidade;
}

//Pegar a quantidade de alunos...
int adicionar_quantidade_provas(int quantidade, int maximo)
{
	do //Repetição, para o caso de erro, esse em especial, para o loop até aqui...
	{
		printf("Digite a quantidade de provas a serem cadastrados: ");
		scanf("%d", &quantidade);
		if (quantidade < 1 || quantidade > maximo)
		{
			printf("Número de provas, incongruente, escolha um número de 1 à 4...\n");
		}
	}											   // Fim do loop do "do"
	while (quantidade < 1 || quantidade > maximo); //Repetir a função em caso de erro.
	return quantidade;
}

void adicionar_aluno_no_menu(Aluno alunos[], int quantidade_alunos, int quantidade_provas)
{
	for (int i = 0; i < quantidade_de_alunos; i++)
	{
		system("clear");
		printf("\nADICIONAR ALUNO NÚMERO: %d ", i + 1);

		printf("\nDigite o nome do aluno: ");
		while (getchar() != '\n')
			;
		scanf("%30[0-9a-zA-Z ]", alunos[i].nome);
		printf("%s", alunos[0].nome);
		printf("Digite a idade do novo aluno: ");
		scanf("%d", &alunos[i].idade);
		for (int j = 0; j < quantidade_provas; j++)
		{
			printf("Digite a nota da prova %d: ", j + 1);
			scanf("%f", &alunos[i].notas_da_prova[j]);
		}
		printf("\nAluno: %s foi adicionado com sucesso.\n", alunos[quantidade_alunos]);
	}
}

void relatorio(Aluno alunos[], int pesos[], int quantidade_alunos, int quantidade_provas, int peso_total)
{
	if (quantidade_alunos == 0)
	{
		printf("Erro, nenhum aluno cadastrado.");
	}
	else
	{
		for (int i = 0; i < quantidade_alunos; i++)
		{
			float media_ponderada = 0;
			for (int j = 0; j < quantidade_provas; j++)
			{
				media_ponderada = (alunos[i].notas_da_prova[j] * pesos[j] / peso_total);
			}
			printf("%d. nome: %s. Média Ponderada: %.2f\n", i + 1, alunos[i].nome, media_ponderada);
		}
	}
}