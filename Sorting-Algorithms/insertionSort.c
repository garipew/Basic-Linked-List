void insertionSort(Lista* l){
	
	Item* i = l->primeiro->proximo;
	Item* j;

	while(i != l->ultimo->proximo){

		j = i;
		while(j != l->primeiro->proximo){
			if(j->chave > j->anterior->chave){
				troca(l, j, j->anterior);
			}
			else{
				j = j->anterior;
			}
		}
		
		i = i->proximo;
		
	}
}
