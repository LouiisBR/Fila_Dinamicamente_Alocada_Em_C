 //Fila Com Alocação Dinamica
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define clear() system("clear || cls");

typedef struct NodoAux{
	int dado;
	struct NodoAux *prox;
}Nodo;

typedef struct {
    Nodo *inicio;
    int tamanho;
} Fila;

void LimpaEntrada(){
    #ifdef WIN32
      fflush(stdin);
    #else
      __fpurge(stdin);
    #endif
}

void Pausar(){
    printf("Pressione qualquer tecla para continuar...");
    LimpaEntrada();
    getc(stdin);
}

Fila *create(){
    Fila *f;
    f = (Fila *) malloc(sizeof(Fila));
    f->inicio = NULL;
    f->tamanho = 0;
    return f;
}

void insere(Fila *f, int valor) {
	Nodo *novo, *aux;
	novo = (Nodo *) malloc(sizeof(Nodo));
	novo->dado = valor;
    novo->prox = NULL; 
	if(f->inicio == NULL) { 
		f->inicio = novo;
	}
    else
    {
        aux = f->inicio;
        while(aux->prox != NULL)
        {
           aux = aux->prox;
        }
        aux->prox = novo; 
    }
	f->tamanho++;
	printf("\nElemento inserido com sucesso\n");
}

void exibir_fila(Fila *f) {
	Nodo *aux;
	if(f->inicio==NULL) {
		printf("\nERRO: Fila vazia\n");
		return;
	}
	aux=f->inicio;
    printf("\nFila: ");
	while(aux!=NULL) {
		printf(" %d |", aux->dado);
		aux = aux->prox;
	}
    printf("\n");
}

void remover(Fila *f) {
	Nodo *aux;
	if(f->inicio==NULL) {
		printf("\nERRO: Fila vazia\n");
		return;
	}
	aux = f->inicio;
	f->inicio = f->inicio->prox; 
	f->tamanho--;
	printf("\nvalor dado: %d.\n\nElemento removido com sucesso\n", aux->dado);
    free(aux);
}

int menu() {
    int *result;
    result = (int *) malloc(sizeof(int));
    clear();
	printf("\n================================| MENU - FILA Linux |===============================");
	printf("\n1- Inserir elemento");
	printf("\n2- Remover elemento");
	printf("\n3- Exibir fila");
	printf("\n------------------------------------------------------------------------------------");
	printf("\nEsc- Sair");
    printf("\n====================================================================================");
	printf("\n\n");
    bool *controle;
    controle = (bool *) malloc(sizeof(bool *));
    do{
        *controle = false;
        printf("Escolha uma Opcao: ");
        *result = getc(stdin);
        printf("%c",*result);
        printf("%s", "  ");
        switch (*result)
        {
            case 49:
            case 50:  
            case 51:
            case 27:  
                break;
        
             default:
                    printf("\nOpcao Invalida!\n");
                    *controle = true;
                break;
        }
    }while(*controle == true);
    return *result;
}

int main() {
    Fila *f;
    f = create();
	int *opcao;
    opcao = (int *) malloc(sizeof(int));
    int *valor;
    valor = (int *) malloc(sizeof(int));
	int *controleMain;
    controleMain = (int *) malloc(sizeof(int));
	do { 
        *controleMain = 1;
        *opcao = menu();
		switch(*opcao) {
			case 49:
				printf("\nDigite o valor a ser inserido ");
				scanf("%d", valor);
				insere(f, *valor);
                Pausar();
				break;
			case 50:
				remover(f);
                Pausar();
				break;
			case 51:
				exibir_fila(f);
                Pausar();
				break;
			case 27:
				printf("\n\nAte logo !!");
                printf("\nAluno: Luis Antonio Gambatti Junior");
                printf(" | IFSP - Campus Catanduva - 2022 | CT3010864\n");
				*controleMain = false;
                Pausar();
                printf("\n\n");
				break;
		}
	}
	while(*controleMain == 1);
    free(valor);
    free(f);
    free(opcao);
    free(controleMain);
    return 0;
}