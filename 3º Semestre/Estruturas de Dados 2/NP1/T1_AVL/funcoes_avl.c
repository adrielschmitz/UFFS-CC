/* 	UNIVERSIDADE FEDERAL DA PRONTEIRA SUL - UFFS
	3º FASE DO CURSO DE CIÊNCIA DA COMPUTAÇÃO
	Trabalho I da desciplina de ESTRUTURA DE DADOS II - 2017
	Implementação da Arvore AVL com valores positivos em C Ansi
	Alunos: ADRIEL SCHMITZ e MAICON BRANDÃO
	Professor: Doglas André Finco
*/
TpArvore *inicializa(){
	TpArvore *arvore = (TpArvore*)malloc(sizeof(TpArvore));
	arvore->raiz = NULL;
	return arvore;
}

TpNodo *inserir_nodo(TpNodo *arvore, int numero){
	if(arvore == NULL){
		arvore = (TpNodo*)malloc(sizeof(TpNodo));
		arvore->chave = numero;
		arvore->altesquerda = 0;
		arvore->altdireita = 0;
		arvore->nivel = 0;
		arvore->altura = 0;
		arvore->esq = NULL;
		arvore->dir = NULL;
		arvore->pai = NULL;		
	}else{
		TpNodo *aux = arvore;
		TpNodo *pai = NULL;
		while(aux != NULL){
			pai = aux; // guarda o endereço do pai do novo nó criado
			if(numero < aux->chave)
				aux = aux-> esq;
			else if(numero > aux->chave)
				aux = aux->dir;
			else{
				printf("\tElemento já existe na arvore.\n");
				return arvore;
			}
		}

	  	TpNodo *filho = (TpNodo*)malloc(sizeof(TpNodo));
	 	filho->chave = numero;
	  	filho->esq = NULL;
	  	filho->dir = NULL;
	  	filho->pai = pai; // filho recebe o endereço do seu pai
	  	if(pai->chave < numero)
	  		pai->dir = filho;
	  	else if(pai->chave > numero)
			pai->esq = filho;
	  	
  		Busca_altura(arvore); //atualiza cada nó da arvore com suas alturas em relação aos seus filhos
  		arvore = Balanceamento(filho); // passa o filho pra ver se precisa de balanceamento, caso seu avo esteja desbalanceado, dai sim acontece a rotação necessária
  		Busca_altura(arvore); //novamente atualiza cada nodo com sua altura respectiva 
  		Busca_nivel(arvore, 0);
	}
  printf("Elemento inserido na Arvore!\n");
  return arvore;
}

TpNodo *Nodo_com_problema(TpNodo *folha){ // função para verificar qual nó que deve ser tratado
	while(folha){//recebe a folha que acabou de ser inserida na arvore e vai subindo até acha algum nó com problema
		if((folha->altesquerda - folha->altdireita) >= 2 || (folha->altesquerda - folha->altdireita) <= -2)
			return folha; // Retorna o avo da folha passada como parâmetro
		
	  folha = folha->pai;
	}
  return NULL; // caso nao tenha nenhum nó com problema, retorna NULL.
}

TpNodo *RetornarRaiz(TpNodo *raiz){ //função feita para que sempre se tenha o endereço da raiz da arvore
	while(raiz->pai)
		raiz = raiz->pai;
	
  return raiz;
}

int Busca_altura(TpNodo *arvore){
	if(arvore == NULL) 
		return -1;
	
	int esq = Busca_altura(arvore->esq);
	int dir = Busca_altura(arvore->dir);

	arvore->altdireita = dir + 2;
	arvore->altesquerda = esq + 2;

	if(esq > dir){
		arvore->altura = esq + 1;
		return esq + 1;
	}else{
		arvore->altura = dir + 1;
		return dir + 1;
	}
}

TpNodo *Balanceamento(TpNodo *arvore){
	TpNodo *aux;

	aux = Nodo_com_problema(arvore);
	if(aux){// caso a função nao retorne NULL, significa que o avo da folha está desbalanceado
		if((aux->altesquerda - aux->altdireita) >= 2){// verifica se a arvore está pendendo para a esquerda
			if((aux->esq->altesquerda - aux->esq->altdireita) >= 1){ //verifica se tem um joelho
				aux = Rotacao_Simples_Direita(aux); // como nao tem, ele só faz um rotaçao simples para a direita
				aux = RetornarRaiz(aux);
				return aux;
			}else{
				aux = Rotacao_joelho_esquerda_direita(aux); // caso tenha um nó para a esquerda e um para a direita
				aux = RetornarRaiz(aux);
				return aux;
			}
		}else if((aux->altesquerda - aux->altdireita) <= -2){ // verifica se a arvore está pendendo para a direita
			if((aux->dir->altesquerda - aux->dir->altdireita) <= -1){ 
				aux = Rotacao_Simples_Esquerda(aux); // nao tem um joelho, faz um rotaçao simples para a esquerda
				aux = RetornarRaiz(aux);
				return aux;
			}else{
				aux = Rotacao_joelho_direita_esquerda(aux); // caso tenha um nó para a direita e um para a esquerda
				aux = RetornarRaiz(aux);
				return aux;
			}
		}
	}
  arvore = RetornarRaiz(arvore);
  return arvore; //retorna a raiz da arvore
}

void Busca_nivel(TpNodo *arvore, int n){
	if(arvore){
		arvore->nivel = n;
		Busca_nivel(arvore->esq, n + 1);
		Busca_nivel(arvore->dir, n + 1);
	}
}

TpNodo *Rotacao_Simples_Direita(TpNodo *nodo){
	TpNodo *aux = nodo->esq;
	aux->pai = nodo->pai;

	if(nodo->pai){
		if(nodo->pai->chave < nodo->chave){
			nodo->pai->dir = aux;
		}else{
			nodo->pai->esq = aux;
		}
	}
	
	nodo->esq = aux->dir;

	if(aux->dir) 
		aux->dir->pai = nodo;

	nodo->pai = aux;
	aux->dir = nodo;
	nodo = aux;

  return nodo;
}

TpNodo *Rotacao_Simples_Esquerda(TpNodo *nodo){
	TpNodo *aux = nodo->dir;
	aux->pai = nodo->pai;

	if(nodo->pai){
		if(nodo->pai->chave < nodo->chave)
			nodo->pai->dir = aux;
		else
			nodo->pai->esq = aux;
	}

	nodo->dir = aux->esq;

	if(aux->esq) 
		aux->esq->pai = nodo;

	nodo->pai = aux;
	aux->esq = nodo;
	nodo = aux;

  return nodo;	
}

TpNodo *Rotacao_joelho_esquerda_direita(TpNodo *avo){
	TpNodo *pai = avo->esq, *neto = pai->dir;

	pai->pai = neto;
	neto->pai = avo;
	avo->esq = neto;
	pai->dir = neto->esq;
	neto->esq = pai;
	avo = Rotacao_Simples_Direita(avo);
  return avo;
}

TpNodo *Rotacao_joelho_direita_esquerda(TpNodo *avo){
	TpNodo *pai = avo->dir, *neto = pai->esq;

	pai->pai = neto;
	neto->pai = avo;
	avo->dir = neto;
	pai->esq = neto->dir;
	neto->dir = pai;
	avo = Rotacao_Simples_Esquerda(avo);
  return avo;
}

void Imprime_arvore(TpNodo *arvore){
	if(arvore){
		printf("Elemento: %d  Alt_dir: %d  Alt_esq: %d  Nivel: %d  Endereço: %p\n", arvore->chave, arvore->altdireita, arvore->altesquerda, arvore->nivel, arvore);
		Imprime_arvore(arvore->esq);
		Imprime_arvore(arvore->dir);
	}
}

void menu(){
	printf("\n\t----------AVL---------\n");
	printf("\t1. Inserir um elemento\n");
	printf("\t2. Listar os elementos\n");
	printf("\t3. Altura da Arvore\n");
	printf("\t0. Sair\n");
	printf("\t-> ");
}