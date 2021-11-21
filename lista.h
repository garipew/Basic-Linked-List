

typedef struct item{

	int chave;
	char caractere;
	struct item *proximo;

} Item;

typedef struct lista{

	Item *primeiro;
	Item *ultimo;
	int tamanho;

}Lista;

Lista* criaListaVazia();
Item* criaItem(int, char);
void inserir(Lista*, Item*);
void troca(Lista*, Item*, Item*);
int listaVazia(Lista*);
int removeElemento(Lista*, int);
void imprimeLista(Lista*);
Item* buscarElemento(Lista*, char);
void moverInicio(Lista*, int);
void deletaLista(Lista*);
