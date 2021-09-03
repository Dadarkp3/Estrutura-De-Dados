#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_QTD_ALUNOS 100
#define MAX_QTD_PROVAS 4
#define TAMANHO(vetor) (sizeof(vetor) / sizeof((vetor)[0]))

int qtd_alunos, qtd_provas, opcao_menu = -1;

struct aluno
{
        char nome_aluno[50];
        float notas_provas[MAX_QTD_PROVAS];
};

void vermelho();
void verde();
void reset();
void imprimir(char messagem[]);
void abertura();
void pegar_quantidade(char mensagem[], int* quantidade, int maximo, char mensagem_erro[]);
void pegar_peso_provas(int pesos[], int tamanho_vetor);

int main(){
	abertura();
	
	pegar_quantidade("\nDigite a quantidade de alunos a serem cadastrados: ", &qtd_alunos, MAX_QTD_ALUNOS, "\nNúmero de alunos excedido.\nTente novamente...");
	
	pegar_quantidade("\nDigita a quantidade de provas: ", &qtd_provas, MAX_QTD_PROVAS, "\nNúmero de provas excedido.\nTente novamente...");
	
	int pesos_provas[qtd_provas];
	pegar_peso_provas(pesos_provas, qtd_provas);
	
	
	struct aluno alunos[qtd_alunos];
	

	return 0; 
}

void vermelho() {
  printf("\033[1;31m");
}

void verde() {
  printf("\033[0;32m");
}

void amarelo(){
  printf("\033[1;33m");
}

void reset (){
  printf("\033[0m");
}


void imprimir(char messagem[]){
	  printf("%s", messagem);
}

void abertura(){
	verde();
    printf("/******************************************/\n");
    printf("/*            Sistema de Notas            */\n");
    printf("/******************************************/\n\n");
    reset();
}

void pegar_quantidade(char mensagem[], int* quantidade, int maximo, char mensagem_erro[]){
	do{
		imprimir(mensagem);
		scanf("%d", quantidade);
		if(*quantidade < 0 || *quantidade >= maximo){
			vermelho();
			imprimir(mensagem_erro);
			reset();
		}		
	}while(*quantidade < 0 || *quantidade >= maximo);
}

void pegar_peso_provas(int pesos[], int tamanho_vetor){
	verde();
	
	printf("\n");
    printf("/*****************************************/\n");
    printf("/*           CADASTRO DE PESOS           */\n");
    printf("/*****************************************/\n\n");
    
    reset();
    
	for(int i = 0; i < tamanho_vetor; i++){
		printf("Digite o peso da prova %d: ", i + 1);
		scanf("%d", &pesos[i]);
	}
	reset();
} 

