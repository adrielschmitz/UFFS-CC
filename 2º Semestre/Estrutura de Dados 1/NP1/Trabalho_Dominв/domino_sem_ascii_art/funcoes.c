/*	UNIVERSIDADE FEDERAL DA PRONTEIRA SUL - UFFS
	ADRIEL SCHMITZ e MAICON BRANDÃO
	TRABALHO NP1 - ESTRUTURA DE DADOS - 2016/02
	CIÊNCIA DA COMPUTAÇÃO
*/

TppecaDomino *inicializa(){
	return NULL;
}

TppecaDomino *cria_pecas(){
	int i, j;
	TppecaDomino *novo = (TppecaDomino *)malloc(sizeof(TppecaDomino));
	novo->left = NULL;
	TppecaDomino *aux = novo, *anterior = novo;
	novo->numberRight = 0;
	novo->numberLeft  = 0;

	for(i=1; i<=6; i++){
		for(j=0; j<=i; j++){
			aux = (TppecaDomino *)malloc(sizeof(TppecaDomino));
			aux->numberRight = j;
			aux->numberLeft = i;
			aux->left = anterior;
			anterior->right = aux;
			anterior = aux;
		}
	}

	aux->right = NULL;
	return novo;
}

TppecaDomino *insere_inicio(TppecaDomino *l, int num1, int num2){
	TppecaDomino *aux = l, *novo = (TppecaDomino *)malloc(sizeof(TppecaDomino));
	if(aux == NULL){
		novo->numberLeft = num1;
		novo->numberRight = num2;
		novo->left = NULL;
		novo->right = NULL;
		return novo;
	}
	while(aux != NULL){
		aux = aux->right;
	}
	novo->numberLeft = num1;
	novo->numberRight = num2;
	novo->right = l;
	novo->left = NULL;
	l->left = novo;
	return novo;
}

TppecaDomino *insere_fim(TppecaDomino *l, int m, int n){
	TppecaDomino *novo = (TppecaDomino *)malloc(sizeof(TppecaDomino));
	if(l == NULL){
		novo->right = NULL;
		novo->left = NULL;
		novo->numberLeft = m;
		novo->numberRight = n;
		return novo;
	}
	TppecaDomino *aux = l;
	novo->right = NULL;
	novo->numberLeft = m;
	novo->numberRight = n;
	while(aux->right!= NULL){
		aux = aux->right;
	}
	novo->left = aux;
	aux->right = novo;
	return l;
}

TppecaDomino *excluir(TppecaDomino *l, int num1, int num2){
	TppecaDomino *aux = l, *prox = NULL, *anterior;
	if(num1 == aux->numberLeft && num2 == aux->numberRight && aux->left == NULL){
		int tamanho = contar_elementos(aux);
		if(tamanho>1){
			aux = l->right;
			aux->left = NULL;
			free(l);
			return aux;
		}else{
			free(l);
			return NULL;
		}
	}
	while(num1 != aux->numberLeft || num2 != aux->numberRight){
		anterior = aux;
		aux = aux->right;
		prox = aux->right;		
	}
	if(aux->right == NULL){
		anterior = aux->left;
		anterior->right = NULL;
		free(aux);
		return l;
	}
	anterior->right = prox;
	prox->left = anterior;
	free(aux);
	return l;
}

TppecaDomino *copiar(TppecaDomino *l, int num){
	TppecaDomino *aux = l;
	int i;
	for(i = 0; i<num; i++){
		aux = aux->right;
	}
	return aux;
}

TppecaDomino *insere_mesa(TppecaDomino *mesa, TppecaDomino *jogada, int lado){
   TppecaDomino *aux = mesa;
	if(lado == 1 || lado == 0){ //LADO DIREITO DA MESA SE POSSÍVEL
		if(jogada->numberLeft == 0 && jogada->numberRight == 0){ // verifica se é o coringa que o jogador tem na mao
			aux = insere_inicio(aux, 0, 0); // se sim, insere no lado esquerdo da mesa a peça |0||0|
			return aux;
		}else if(jogada->numberRight == aux->numberLeft){
			aux = insere_inicio(aux, jogada->numberLeft, jogada->numberRight);
			return aux;
		}else if(jogada->numberLeft == aux->numberLeft){
			aux = insere_inicio(aux, jogada->numberRight, jogada->numberLeft);
			return aux;
		}
	}
	if(lado == 2 || lado == 0){ //LADO ESQUERDO DA MESA SE POSSÍVEL
		while(aux->right != NULL){ // vai até o final da mesa;
			aux = aux->right;
		}
		if(jogada->numberLeft == 0 && jogada->numberRight == 0){ // verifica se é o coringa que será jogado
			aux = insere_fim(aux, 0, 0); // insere o coringa no final da mesa
			return mesa;
		}else if(jogada->numberLeft == aux->numberRight){
			aux = insere_fim(aux, jogada->numberLeft, jogada->numberRight);
			return mesa;
		}else if(jogada->numberRight == aux->numberRight){
			aux = insere_fim(aux, jogada->numberRight, jogada->numberLeft);
		}	return mesa;
	}
	return mesa;
}

TppecaDomino *remove_peca_jogada(TppecaDomino *mao, TppecaDomino *jogada){
	TppecaDomino *ant, *prox, *aux = mao;
	if(aux->left == NULL && aux->right == NULL){
		free(mao);
		mao = inicializa();
		return mao;
	}
	while(aux != jogada){
		aux = aux->right;
	}
	if(aux->right == NULL){
		ant = aux->left;
		ant->right = NULL;
		free(aux);
		return mao;
	}
	if(aux->left == NULL){
		prox = aux->right;
		prox->left = NULL;
		mao = prox;
		free(aux);
		return mao;
	}
	ant = aux->left;
	prox = aux->right;
	ant->right = prox;
	prox->left = ant;
	free(aux);
	return mao;
}

int valida_jogada(TppecaDomino *mesa, TppecaDomino *jogada){
  TppecaDomino *aux = jogada, *aux_mesa = mesa;
  int inicio = 0, final = 0;
	if(aux_mesa == NULL){ // caso nao tenha nenhuma peça na mesa, para a função, indicando o final do jogo
		return 0;
	}
	if(jogada->numberLeft == 0 && jogada->numberRight == 0){ // retorna 2, indicando que a peça pode ser posta nos dois lados da mesa
		return 2; //Valida a jogada em ambos os lados pois 0:0 = Coringa.
	}
	if(aux->numberLeft == aux_mesa->numberLeft){
		inicio++;
	}else if(aux->numberRight == aux_mesa->numberLeft){
		inicio++;
	}
	
	while(aux_mesa->right != NULL){ //Encontra o último elemento da lista.
		aux_mesa = aux_mesa->right;
	}
	if(aux->numberLeft == aux_mesa->numberRight){
		final++;
	}else if(aux->numberRight == aux_mesa->numberRight){
		final++;
	}
	if(inicio > 0 && final > 0){ // verifica em qual lado da mesa a peça deve ser inserida
		return 2; // retorna 2 para o lado direito da mesa
	}else if(inicio > 0 || final > 0){
		return 1; // returna 1 para o lado esquerdo da mesa
	} 
  return 0;
}

int testa_pecas(TppecaDomino *l, TppecaDomino *mesa){ //Função que passa a vez caso o jogador não tenha peças compatíveis com a mesa.
	TppecaDomino *aux = l;
	while(aux != NULL){
		if(valida_jogada(mesa, aux) == 0){
			aux = aux->right;
		}else{
			return 1;
		}
	}
	return 0;
}

void imprime(TppecaDomino *l){
	TppecaDomino *p = l;
	int aux = 0;
	while(p != NULL){
		printf(":|%d|%d|:", p->numberLeft, p->numberRight);
		aux++;
		if(aux == 10) printf("\n");
		if(aux == 10) aux = 0;
		p = p->right;
	}
	printf("\n");
}

int contar_elementos(TppecaDomino *l){
	TppecaDomino *aux = l;
	int elementos = 0;
	while(aux != NULL){
		elementos++;
		aux = aux->right;		
	}
	return elementos;
}

int conta_pontos(TppecaDomino *l){
	TppecaDomino *aux = l;
	int pontos = 0;
	while(aux != NULL){
		pontos = aux->numberLeft+aux->numberRight;
		aux = aux->right;
	}
	return pontos;
}

void imprime_info(TppecaDomino *mesa, TppecaDomino *mao_jogador, TppecaDomino *mao_bot, TppecaDomino *monte){
	system("clear");
	printf("PEÇAS DO MONTE: [%d]", contar_elementos(monte));
	printf("\tPEÇAS DA SUA MAO: [%d]\tPEÇAS NA MAO DO BOT: [%d]\n\n", contar_elementos(mao_jogador), contar_elementos(mao_bot));
}

void quem_ganhou(TppecaDomino *jogador, TppecaDomino *bot, TppecaDomino *monte){
	int pontos_jogador = 0, pontos_bot = 0;
	while(jogador != NULL){
		pontos_jogador += jogador->numberLeft + jogador->numberRight;
		jogador = jogador->right;
	}
	while(bot != NULL){
		pontos_bot += bot->numberLeft + bot->numberRight;
		bot = bot->right;
	}
	if( pontos_jogador > pontos_bot ){
		system("clear");
		printf("\n\tQUE PENA. VOCÊ PERDEU!\n\n");
		printf("Pontos do bot: [%d].\nSeus pontos: [%d].\n", pontos_bot, pontos_jogador);
	}else if( pontos_jogador < pontos_bot ){
		system("clear");
		printf("\tPARABÉNS! VOCÊ GANHOU!\n\n");
		printf("Seus pontos: [%d].\nPontos do bot: [%d].\n", pontos_jogador, pontos_bot);
	}else{
		printf("\tHOUVE UM EMPATE!\n");
		printf("Seus pontos: [%d].\nPontos do bot: [%d].\n", pontos_jogador, pontos_bot);
	}
	if(monte){
		printf("\nPEÇAS QUE RESTARAM NO MONTE:\n");
		imprime(monte);
	}

	sleep(15);
	system("clear");
	creditos();
}

void creditos(){
    printf("\e[H\e[2J");
    printf("\n\t|-------------------------------------------------------|\n");
    printf("\t|                    CREDITS                            |\n");
    printf("\t|-------------------------------------------------------|\n");
    printf("\t|University: UNIVERSISADADE FEDERAL DA FRONTEIRA SUL    |\n");
    printf("\t|Author: Adriel Schmitz e Maicon Brandão                |\n");
    printf("\t|Course: Ciência da Computação                          |\n");
    printf("\t|Phase: 2ª                                              |\n");
    printf("\t|Discipline: Estruturas de Dados I                      |\n");
    printf("\t|Teacher: Jacson Luiz Matte                             |\n");
    printf("\t|-------------------------------------------------------|\n\n");
}
