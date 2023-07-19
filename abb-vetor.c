#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int chave;
  struct no *esq, *dir;
} TNo;

void imprime(TNo *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%d\n", nodo->chave);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio");
}

TNo *busca(TNo *no, int chave) {
	if(no == NULL) return NULL;
    else if(no->chave == chave) return no;
    else if(no->chave > chave) return busca(no->esq, chave); 
    else return busca(no->dir, chave);
}

TNo *insere(TNo *no, int chave) {
    if (no == NULL) {
        no = (TNo *) malloc(sizeof(TNo));
        no->chave = chave;
        no->esq = NULL;
        no->dir = NULL;
    } else if (chave < (no->chave))
        no->esq = insere(no->esq, chave);
    else if (chave > (no->chave)) {
        no->dir = insere(no->dir, chave);
    }
    else {
        printf("Inserção inválida! ");
        exit(1);
    }
    return no;
}

TNo *criaArvoreBalanceada(TNo *raiz, int *v, int inicio, int fim) {
    if (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (raiz == NULL) {//se for primeiro nó a ser inserido tem que atualizar a raiz da arvore
        	/*FAZER CODIGO AQUI*/
          raiz = insere(raiz, v[meio]);
	}
        else insere(raiz, v[meio]);
        	//constroi subárvores esquerda e direita
		/*FAZER CODIGO AQUI*/
      
      
    }
    return raiz;
}

int main(void) {
    TNo *raiz, *no;
    raiz = NULL;
    raiz = insere(raiz, 500);
    insere(raiz, 600);
    insere(raiz, 550);
    insere(raiz, 400);
    imprime(raiz, 0);

    no = busca(raiz, 550);
    if (no != NULL) {
        printf("\n\nEncontrou no de chave %d.", no->chave);
    } else printf("Não encontrou!");

    no = busca(raiz, 400);
    if (no != NULL) {
        printf("\n\nEncontrou no de chave %d.\n", no->chave);
    } else printf("Não encontrou!\n");

    int tam = 7;
    int v[7] = {150, 300, 400, 500, 600, 800, 900};
    TNo *raiz3 = NULL;
    raiz = criaArvoreBalanceada(raiz3,v,0,tam-1);

    printf("\n");
    imprime(raiz, 0);

}