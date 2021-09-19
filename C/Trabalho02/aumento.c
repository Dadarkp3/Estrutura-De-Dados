#include <stdio.h>
#include <stdlib.h>

#define MAX_FUNCIONARIOS 200

typedef struct
{
	char nome[30];
	int funcao;
	int idade;
	float salario;
} Funcionario;

int qtd_funcionarios_adicionados = 0, opcao_menu = -1;
char ch;

void vermelho();
void verde();
void reset();
void abertura();
void menu();
void sair_sub_menu();
void mensagem_error_geral(char mensagem[]);

void sub_menu_adicionar_funcionario(Funcionario funcionarios[]);
void adicionar_funcionaro(Funcionario funcionarios[]);

void sub_menu_dar_aumento_funcionario(Funcionario funcionarios[]);
void dar_aumento_funcionario(Funcionario funcionarios[]);

int main()
{
	abertura();
	Funcionario funcionarios[MAX_FUNCIONARIOS];

	do
	{
		menu();
		switch (opcao_menu)
		{
		case 1:
			sub_menu_adicionar_funcionario(funcionarios);
			break;

		case 2:
			sub_menu_dar_aumento_funcionario(funcionarios);
			break;
		case 3:
			break;

		default:
			printf("Número inválido! Aperte qualquer tecla para voltar ao menu de opções...");
			fflush(stdin);
			scanf("%c", &ch);
		}
	} while (opcao_menu != 3);

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
	printf("/*          SISTEMAS FUNCIONARIOS         */\n");
	printf("/******************************************/\n\n");
	reset();
}


void menu()
{
	amarelo();

	printf("\n");
	printf("/*****************************************/\n");
	printf("/*            MENU DE SELEÇÃO            */\n");
	printf("/*****************************************/\n\n");

	printf("1. Adicionar um novo funcionario.\n");
	printf("2. Dar aumento para funcionários por função.\n");
	printf("3. Sair\n\n");
	printf("/*****************************************/\n\n");
	reset();
	printf("Digite a opção desejada: ");
	fflush(stdin);
	scanf("%d", &opcao_menu);
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

void mensagem_error_geral(char mensagem[])
{
	vermelho();
	printf("%s\n\n", mensagem);
	reset();
}

void sub_menu_adicionar_funcionario(Funcionario funcionarios[])
{
	system("clear");
	verde();
	printf("/******************************************/\n");
	printf("/*         ADICIONAR FUNCIONARIO          */\n");
	printf("/******************************************/\n\n");
	reset();
	adicionar_funcionaro(funcionarios);
	sair_sub_menu();
}

void adicionar_funcionaro(Funcionario funcionarios[])
{
	if (MAX_FUNCIONARIOS <= qtd_funcionarios_adicionados)
	{
		mensagem_error_geral("Quantidade máxima de funcionarios cadastrados.");
	}
	else
	{
		printf("Digite o nome do novo funcionario: ");
		while (getchar() != '\n')
			;
		scanf("%50[0-9a-zA-Z ]", funcionarios[qtd_funcionarios_adicionados].nome);
		while (getchar() != '\n')
			;
		printf("Digite a idade do novo funcionario: ");
		scanf("%d", &funcionarios[qtd_funcionarios_adicionados].idade);
		printf("Digite o salário do novo funcionario: ");
		scanf("%f", &funcionarios[qtd_funcionarios_adicionados].salario);
		
		int funcao = -1;
		while(funcao != 1 && funcao !=2 && funcao !=3){
			system("clear");
			verde();
			printf("/*********************************************************************/\n\n");
			printf("/*  Digite o número correto para cadastrar a função do funcionario   */\n\n");
			printf("  1.Engenheiro\n  2.Arquiteto\n  3.Mestre de Obra\n  4.Pedreiro.\n\n");
			printf("/*********************************************************************/\n\n");
			reset();
			printf("Digite a função do novo funcionario: ");
			scanf("%d", &funcao);	
		}
		
		funcionarios[qtd_funcionarios_adicionados].funcao = funcao; 
		system("clear");
		printf("\nO funcionario foi adicionado com sucesso.\n");
		qtd_funcionarios_adicionados++;
	}
}

void sub_menu_dar_aumento_funcionario(Funcionario funcionarios[])
{
	system("clear");
	verde();
	printf("/******************************************/\n");
	printf("/*        DAR AUMENTO FUNCIONARIO         */\n");
	printf("/******************************************/\n\n");
	reset();
	dar_aumento_funcionario(funcionarios);
	sair_sub_menu();
}

void dar_aumento_funcionario(Funcionario funcionarios[]) {
	if(qtd_funcionarios_adicionados < 0) {
		mensagem_error_geral("Nenhum funcionário adicionado no momento...");	
	}else{
		verde();
		printf("/*********************************************************************/\n\n");
		printf("/*    Digite o número da função dos funcionários a ganhar aumento    */\n\n");
		printf("  1.Engenheiro\n  2.Arquiteto\n  3.Mestre de Obra\n  4.Pedreiro.\n\n");
		printf("/*********************************************************************/\n\n");
		reset();
		printf("Digite a função do novo funcionario: ");
		int funcao;
		scanf("%d", &funcao);
		
		float porcentagem_aumento;
		printf("Porcentagem de aumento ");
		vermelho();
		printf(" (Não digite o símbolo %%) ");
		reset();
		printf(": "); 
		scanf("%f", &porcentagem_aumento);
		system("clear");
		for(int i = 0; i < qtd_funcionarios_adicionados; i++){
			if(funcionarios[i].funcao == funcao){
				amarelo();
				printf("O salario antigo de %s é: %.2f ", funcionarios[i].nome, funcionarios[i].salario); 
				funcionarios[i].salario = funcionarios[i].salario * ( 1 + ( porcentagem_aumento / 100.00 ));
				printf("O salario atual é: %.2f\n", funcionarios[i].salario);
				reset();
			}
		}		
	}
}


