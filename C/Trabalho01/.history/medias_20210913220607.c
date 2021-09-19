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
int Adicionar_Quantidade_Provas(int quantidade, int maximo);

void adicionar_aluno_no_menu(int Quantidade_Alunos, int Quantidade_Provas, int Total_alunos, Aluno alunos[], int Numero_Aluno);

void Relatorio(Aluno alunos[], int pesos[], int Quantidade_Alunos, int Quantidade_Provas, int Peso_total);

int main(void)
{
	int Quantidade_Alunos, Quantidade_Provas;

	Configuracao();

	Quantidade_Alunos = adicionar_quantidade_alunos(quantidade_de_alunos, MAXIMO_DE_ALUNOS);
	//Com uma função int, eu consigo jogar o valor de retorno, no caso o número de alunos para uma variável.

	Quantidade_Provas = Adicionar_Quantidade_Provas(quantidade_de_provas, MAXIMO_DE_PROVAS);

	int Pesos_prova[Quantidade_Provas];
	int Peso_total = 0;
	for (int i = 0; i < Quantidade_Provas; i++)
	{
		printf("Digite o peso da prova %d: ", i + 1);
		scanf("%d", &Pesos_prova[i]);
		Peso_total = Pesos_prova[i] + Peso_total;
	}

	Aluno alunos[Quantidade_Alunos];

	printf("%d", Pesos_prova[1]);
	int Total_alunos = 0;
	for (int i = 0; i < Quantidade_Alunos; i++)
	{
		adicionar_aluno_no_menu(Quantidade_Alunos, Quantidade_Provas, Total_alunos, alunos, i);
	}

	Relatorio(alunos, Pesos_prova, Quantidade_Alunos, Quantidade_Provas, Peso_total);

	return 0;
}

void verde() //Definir a cor das letras
{
	printf("\033[0;32m");
}

void Configuracao() // Mensagem inicial do sistema
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
int Adicionar_Quantidade_Provas(int quantidade, int maximo)
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

void adicionar_aluno_no_menu(int Quantidade_Alunos, int Quantidade_Provas, int Total_alunos, Aluno alunos[], int Numero_Aluno)
{
	system("clear");
	printf("\nADICIONAR ALUNO NÚMERO: %d ", Numero_Aluno + 1);

	printf("\nDigite o nome do aluno: ");
	while (getchar() != '\n')
		;
	scanf("%30[0-9a-zA-Z ]", alunos[Quantidade_Alunos].nome);
	printf("%s", alunos[0].nome);

	printf("Digite a idade do novo aluno: ");
	scanf("%d", &alunos[Quantidade_Alunos].idade);

	for (int i = 0; i < Quantidade_Provas; i++)
	{
		printf("Digite a nota da prova %d: ", i + 1);
		scanf("%f", &alunos[Quantidade_Alunos].notas_da_prova[i]);
	}
	printf("\nAlunos adicionado com sucesso! \n");
}

void Relatorio(Aluno alunos[], int pesos[], int Quantidade_Alunos, int Quantidade_Provas, int Peso_total)
{
	if (Quantidade_Alunos == 0)
	{
		printf("Erro, nenhum aluno cadastrado.");
	}
	else
	{
		for (int i = 0; i < Quantidade_Alunos; i++)
		{
			float media_ponderada = 0;
			for (int j = 0; j < Quantidade_Provas; j++)
			{
				media_ponderada = (alunos[i].notas_da_prova[j] * pesos[j] / Peso_total);
			}
			printf("%d. nome: %s. Média Ponderada: %.2f\n", i + 1, alunos[i].nome, media_ponderada);
		}
	}
}