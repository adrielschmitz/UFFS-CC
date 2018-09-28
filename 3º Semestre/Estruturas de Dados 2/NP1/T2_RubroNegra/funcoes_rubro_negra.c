/* 	UNIVERSIDADE FEDERAL DA PRONTEIRA SUL - UFFS
	3º FASE DO CURSO DE CIÊNCIA DA COMPUTAÇÃO
	Trabalho II da desciplina de ESTRUTURA DE DADOS II - 2017
	Implementação da Arvore RUBRO NEGRA com valores positivos em C Ansi
	Alunos: ADRIEL SCHMITZ e MAICON BRANDÃO
	Professor: Doglas André Finco
*/
TpArvore *inicializa(){//aloca memoria para inicializar a arvore
	TpArvore *arvore = (TpArvore *)malloc(sizeof(TpArvore));
	TpNodo *sentinela = (TpNodo *)malloc(sizeof(TpNodo));
	arvore->raiz = NULL;
	arvore->sentinela = sentinela;
	arvore->sentinela->chave = -1;
	arvore->sentinela->cor = BLACK;
	arvore->sentinela->pai = NULL;
	arvore->sentinela->esq = NULL;
	arvore->sentinela->dir = NULL;

	return arvore;
}


TpNodo *insere_nodo(TpNodo *arvore, int numero){
	if(arvore == NULL){
		arvore = (TpNodo*)malloc(sizeof(TpNodo));
		arvore->chave = numero;
		arvore->cor = BLACK;
		arvore->esq = NULL;
		arvore->dir = NULL;
		arvore->pai = NULL;
	}else{
		TpNodo *aux = arvore;
		TpNodo *pai = NULL; //auxiliar guarda o endereço do pai do novo nodo...
		while(aux != NULL){
			pai = aux;
			if(numero == aux->chave){
				printf("\tElemento já existe na arvore.\n");
				return arvore;
			}else if(numero < aux->chave){
				aux = aux-> esq;
			}else{
				aux = aux->dir;
			}
		}

	  	TpNodo *filho = (TpNodo*)malloc(sizeof(TpNodo));
	 	filho->chave = numero;
	  	filho->esq = NULL;
	  	filho->dir = NULL;
	  	filho->pai = pai;
	  	filho->cor = RED;
	  	pai->chave < numero ? (pai->dir = filho) : (pai->esq = filho);

  		arvore = verifica_propriedades(filho);
	}
  	printf("\n\tValor inserido.\n");
  	return arvore;
}

TpNodo *caso_1(TpNodo *nodo){
	TpNodo *pai = nodo->pai, *avo = busca_avo(nodo), *tio = busca_tio(nodo);

	inverte_cor(pai);
	if(avo->pai) 
		inverte_cor(avo);
	if(avo->esq == pai) 
		inverte_cor(tio);
	else if(avo->esq) 
		inverte_cor(tio);
	
	return avo;
}

TpNodo *caso_2(TpNodo *filho){
	TpNodo *pai = filho->pai, *avo = busca_avo(filho);

	if(pai->dir == filho && avo->esq == pai){
		filho->pai = avo;
		avo->esq = filho;
		pai->pai = filho;
		pai->dir = filho->esq;
		filho->esq = pai;
	}else{
		filho->pai = avo;
		avo->dir = filho;
		pai->pai = filho;
		pai->esq = filho->dir;
		filho->dir = pai;
	}
	return pai;
}

TpNodo *caso_3(TpNodo *filho){
	TpNodo *pai = filho->pai, *avo = busca_avo(filho);
	inverte_cor(pai);
	inverte_cor(avo);
	if(avo->pai){// se o avô for positivo, significa que tem mais nodos acima desse avô...
		pai->pai = avo->pai;
		if(avo->pai->esq == avo)
			avo->pai->esq = pai;
		else
		 	avo->pai->dir = pai;
	}else// se nao significa que o avô é a raiz...
		pai->pai = NULL;

	if(avo->esq == pai){
		avo->esq = pai->dir;
		pai->dir = avo;
	}else{
		avo->dir = pai->esq;
		pai->esq = avo;
	}

	avo->pai = pai;
	return pai;
}

TpNodo *retorna_raiz(TpNodo *raiz){
	while(raiz->pai){
		raiz = raiz->pai;
	}
	return raiz;
}

void inverte_cor(TpNodo *nodo){
	nodo->cor = !nodo->cor;
}

int busca_cor(TpNodo *nodo){
	return nodo == NULL ? BLACK : nodo->cor;
}

TpNodo *busca_avo(TpNodo *filho){
	return (filho->pai != NULL) ? filho->pai->pai : NULL;
}

TpNodo *busca_tio(TpNodo *filho){
	TpNodo *avo = busca_avo(filho);
	if(avo == NULL) 
		return NULL;
	return avo->esq == filho->pai ? avo->dir : avo->esq;
}

TpNodo *verifica_propriedades(TpNodo *filho){
	TpNodo *pai = filho->pai, *avo = busca_avo(filho), *tio = busca_tio(filho);

	if(!pai->cor){ // se o pai for preto, nao faz nada só retorna o filho normal
		filho = retorna_raiz(filho);
	}else{ // caso o pai for vermelho, verifica qual caso é e aplica as soluções
		if(busca_cor(tio)){ // se a função retornar 1 é porque o tio é RED
			filho = caso_1(filho);
			if(filho->pai != NULL){//pode ser que tenha mais nodos pra cima
				if( busca_cor(filho->pai) && busca_cor(filho) ){// se as duas funções retornarem 1, pai e filho sao vermelhos
					filho = verifica_propriedades(filho); // chama a função recursivamente, mas agr passa o avô o ex filho como parametro
				}
			}
			filho = retorna_raiz(filho);
			return filho;
		}else{ // caso o tio for BLACK
			if((pai->dir == filho && avo->esq == pai) || (pai->esq == filho && avo->dir == pai)){
				filho = caso_2(filho);
				filho = caso_3(filho);
				filho = retorna_raiz(filho);
				return filho;
			}
			if(pai->esq == filho || pai->dir == filho){
				filho = caso_3(filho);
				filho = retorna_raiz(filho);
				return filho;
			}
		}		
	}
	return filho;	
}

void menu(){
		system("clear");
		printf("\t========= RED BLACK =========\n");
		printf("\t1. Inserir um elemento\n");
		printf("\t2. Listar os elementos\n");
		printf("\t0. Sair\n");
		printf("\t-> ");
}

void imprime_arvore(TpNodo *arvore){
	if(arvore){
		printf("Elemento: %d Cor: ", arvore->chave);
		if(busca_cor(arvore)){
			printf("RED  ");
			printf("  ENDEREÇO: %p  PAI: %p\n", arvore, arvore->pai);
		}else{
			printf("BLACK  ");
			printf("ENDEREÇO: %p  PAI: %p\n", arvore, arvore->pai);
		}
		
		imprime_arvore(arvore->esq);
		imprime_arvore(arvore->dir);
	}
}