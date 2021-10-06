#define MAX_ALUNOS 200

typedef struct aluno{
    char nome[50];
    int idade;
} Aluno;


void menu_iniciar_sala(Aluno **alunos, int * quantidade_cadeiras_disponiveis);
void iniciar_sala(Aluno **alunos, int * quantidade_cadeiras_disponiveis);

void menu_adicionar_aluno(Aluno **alunos, int * quantidade_cadeiras_disponiveis, int * quantidade_alunos_cadastrados);
void adicionar_aluno(Aluno **alunos, int * quantidade_cadeiras_disponiveis, int * quantidade_alunos_cadastrados);

void menu_modificar_quantidade_cadeiras(Aluno * alunos, int * quantidade_cadeiras_disponiveis, int * quantidade_alunos_cadastrados);
void modificar_quantidade_cadeiras(Aluno * alunos, int * quantidade_cadeiras_disponiveis, int * quantidade_alunos_cadastrados);

void menu_libera_sala(Aluno * alunos, int * quantidade_cadeiras_disponiveis, int * quantidade_alunos_cadastrados);
