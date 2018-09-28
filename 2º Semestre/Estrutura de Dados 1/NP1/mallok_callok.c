printf("Informe a quantidade de inteiros que deseja alocar: ");
scanf("%d", &n);

int *v;
v = (int*) malloc(n*sizeof(int));
free(v);

int *v; // criando um ponteiro do tipo inteiro;
v = (int*) calloc(n, sizeof(int)); // agora o ponteiro criado aponta pra primeira posição da memória que foi alocada. Marcando o início do array;
free(v);

int *nvtr;
nv = (int *) realloc(v, n*sizeof(int)); // realoca um novo valor, tendo como referencia o v que ja tinha uma certa quantidade de bytes alocados; 
v = nv; // v está recebendo nvt que contém o novo valor alocado com a função realloc;
free(v);
free(nv); // libera memória;