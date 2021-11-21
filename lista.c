#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

Lista* criaListaVazia(){

	Lista* l = (Lista*)malloc(sizeof(Lista));
	Item* cabeca = criaItem(-1, '.');

	l->primeiro = cabeca;
	l->ultimo = cabeca;
	l->tamanho = 0;

	l->primeiro->proximo = NULL;

	return l;

}

Item* criaItem(int chave, char caractere){

	Item* c = (Item*) malloc(sizeof(Item));
	c->proximo = NULL;

	c->chave = chave;
	c->caractere = caractere;

	return c;

}

void inserir(Lista* l, Item* i){

	l->ultimo->proximo = i;
	i->proximo = NULL;
	l->ultimo = i;
	l->tamanho++;

}

void trocaLateral(Item* esq, Item* dir){

        Item* auxp = dir->proximo;

        dir->anterior = esq->anterior;
        dir->proximo = esq;
        esq->anterior = dir;
        esq->proximo = auxp;

}

void atualiza(Lista* l, Item* j){

         if(j->proximo==NULL){
                 l->ultimo = j;
         } else{
                 j->proximo->anterior = j;
         }
         if(j->anterior == l->primeiro){
                 l->primeiro->proximo = j;
         } else{
                 j->anterior->proximo = j;
         }

}

void troca(Lista* l, Item* i, Item* j){

        if(i == NULL || j == NULL)
                return;


        if(i->anterior == j){

                trocaLateral(j, i);
		
        }else if(j->anterior == i){

                trocaLateral(i, j);

        } else{

	        Item* aux = i->anterior;
	        Item* auxp = i->proximo;

	        i->proximo = j->proximo;
	        i->anterior = j->anterior;
	        j->anterior = aux;
	        j->proximo = auxp;

    	}	

        atualiza(l, i);
        atualiza(l, j);

}

int listaVazia(Lista* l){

	if(l->primeiro == l->ultimo)
		return 1;
	return 0;

}

int removeElemento(Lista* l, int chave){
	if(listaVazia(l))
		return 0;

	int c;
	Item* atual = l->primeiro;
	Item* aux;

	while(atual->proximo != NULL){
		if(atual->proximo->chave == chave){
			aux = atual->proximo;
			atual->proximo = atual->proximo->proximo;
			if(aux->proximo == NULL)
				l->ultimo = atual;
			l->tamanho--;
			c = aux->chave;
			free(aux);
			return c;
		}

		atual = atual->proximo;

	}
}

void deletaLista(Lista* l){
	
	int tamanho = l->tamanho;
	for(int i = 0; i<tamanho; i++){
		removeElemento(l, l->ultimo->chave);
	}

	Item* cabeca = l->primeiro;
	free(cabeca);
	free(l);

}

void imprimeLista(Lista* l){

	if(listaVazia(l)){
		printf("Lista Vazia!\n");
		return;
	}

	Item* atual = l->primeiro->proximo;
	while(atual!=NULL){
		if(atual->proximo!=NULL){
			printf("%d, ", atual->chave);
			atual = atual->proximo;
		}
		if(atual->proximo == NULL){
			printf("%d", atual->chave);
			atual = atual->proximo;
		}
	}
	printf("\n");
}

Item* buscarElemento(Lista* l, char elemento){
	if(listaVazia(l))
		return NULL;

	Item* atual = l->primeiro->proximo;
	while(atual!=NULL){
		if(atual->caractere == elemento)
			return atual;
		atual = atual->proximo;
	}

	return NULL;
}

void moverInicio(Lista* l, int elemento){
	if(listaVazia(l))
		return;
	if(buscarElemento(l, elemento) == NULL)
		return;

	Item* primeiro = l->primeiro->proximo;
	Item* i = criaItem(elemento, '.');

	removeElemento(l, i->chave);

	l->primeiro->proximo = i;
	i->proximo = primeiro;
	l->tamanho++;
}
