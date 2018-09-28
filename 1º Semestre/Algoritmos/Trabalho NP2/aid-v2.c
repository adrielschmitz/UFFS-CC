#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define Dados "dados.txt"
#define Temp "binario.bin"

/*
Para comipilar usar 'gcc -c main.c convert.c -Wall' vai gerar arquivos .o;
Para linkar usar 'gcc -o programa aid.o convert.o' gera o arquivo executavel;
Para executar './programa';
*/

//Estrutura de dados.
typedef struct pessoa{
  char nome[30];
  char idade[3];
  char fone[20];
  char email[51];
  char estado[30];
  char cidade[50];
  char rua[51];
  char numero[10];
}dados;

int menu();
int incluir();
int excluir();
dados* buscar();
int exibir();
int creditos();
int grava(dados *registra);
int conf();
int Erro();
char* convert(char l[]);

int main(){
  int ops = 0;
  printf("\t                      Agenda!\n");
  ops = menu();
  switch (ops) {
    case 1:
        printf("\e[H\e[2J");
        printf("\nIncluir novo cadastro!\n");
        incluir();
        main();
        break;
    case 2:
        printf("\e[H\e[2J");
        printf("\nExcluir um cadastro!\n");
        excluir();
        main();
        break;
    case 3:
        printf("\e[H\e[2J");
        printf("\nBuscar cadastro!");
        buscar();
        main();
        break;
    case 4:
        printf("\e[H\e[2J");
        printf("\nExibir todos os cadastros!");
        printf("\n");
        exibir();
        break;
    case 5:
        printf("\e[H\e[2J");
        creditos();
        break;
    case 6:
        printf("\e[H\e[2J");
        printf("Saindo!\n");
        exit(0);
        break;
    default:
        printf("Opção inválida!");
        break;
  }
  return 0;
}

int incluir(){
      dados in;
      dados *pt;
      pt = &in;
      setbuf(stdin,NULL);
      printf("\nNome:");
      scanf("%[^\n]s", pt->nome);
      setbuf(stdin,NULL);
      printf("Idade:");
      scanf("%[^\n]s", pt->idade);
      setbuf(stdin,NULL);
      printf("Telefone:");
      scanf("%[^\n]s", pt->fone);
      setbuf(stdin,NULL);
      printf("E-mail:");
      scanf("%[^\n]s", pt->email);
      setbuf(stdin,NULL);
      printf("Estado:");
      scanf("%[^\n]s",pt->estado);
      setbuf(stdin,NULL);
      printf("Cidade:");
      scanf("%[^\n]s",pt->cidade);
      setbuf(stdin,NULL);
      printf("Rua:");
      scanf("%[^\n]s",pt->rua);
      setbuf(stdin,NULL);
      printf("Numero:");
      scanf("%[^\n]s",pt->numero);
      setbuf(stdin,NULL);
      if(conf() != 0)
        grava(pt);
    
  return 0;
}

int excluir(){
        dados *registro;
        dados *temp_registro;
        FILE *arquivo;
        FILE *arq_temp;
        char confirma[10];
        temp_registro = (dados *)calloc(1,sizeof(dados));

        registro = buscar();
        // testa para ver se eh possivel excluir
        if (!registro)
            return(0);

        printf("\n\nDeseja excluir este registro? (Sim/Nao)");
        scanf("%s",confirma);


        if ((strcmp(convert(confirma),"SIM")) == 0){
            arquivo = fopen(Dados, "r");
            arq_temp = fopen(Temp, "wb");
            do{
                fread(temp_registro, sizeof(*temp_registro),1, arquivo);
                if (!feof(arquivo))
                    if (strcmp(temp_registro->nome,registro->nome)){
                        fwrite(temp_registro, sizeof(*temp_registro), 1, arq_temp);
                    }
            }while(!feof(arquivo));
            fclose(arquivo);
            fclose(arq_temp);
            remove(Dados);
            rename(Temp, Dados);
            remove(Temp);
            // testa para ver se o arquvivo ainda possui alguma existencia
            arquivo = fopen(Dados, "r");
            if (arquivo == NULL){
                // no caso de estar  vazio, apaga!
                fclose(arquivo);
                remove(Dados);
            }
            printf("\e[H\e[2J");
            printf("\n\nRegistro Deletado com sucesso!\n");
            main();
        }else if((strcmp(convert(confirma),"NAO")) == 0){
                printf("\e[H\e[2j");
                printf("Exclusão cancelada!\n");
                main();
        }else{
            printf("\e[H\e[2J");
            printf("\n\nEntrada invalida!\n");
            excluir();
      }
      free(temp_registro);
      free(registro);
      return 0;
}

int menu(){
      int ops = 0,aux = 1;
      while(aux > 0){
        ops = 0;
        printf("\n\t\t|****************************************|\n");
        printf("\t\t|                Menu                    |\n");
        printf("\t\t|****************************************|\n");
        printf("\t\t|[1] Incluir                             |\n");
        printf("\t\t|[2] Excluir                             |\n");
        printf("\t\t|[3] Buscar                              |\n");
        printf("\t\t|[4] Exibir todo o registro              |\n");
        printf("\t\t|[5] Creditos                            |\n");
        printf("\t\t|[6] Sair                                |\n");
        printf("\t\t|****************************************|\n");
        printf("Opcao:");
        scanf("%d",&ops);
        if(ops <= 6 && ops > 0){
          aux = 0;
        }else{
          printf("Opcao Invalida!");
          aux++;
        }
      }
      return ops;
}

int grava(dados *registra){
     FILE *arquivo;
     FILE *arq_temp;
     dados *temp_registro;
     int inseriu = 0;

     // aloca a memoria da struct temporaria
     temp_registro = (dados *)calloc(1,sizeof(dados));
     if (!temp_registro) Erro();
     arquivo = fopen(Dados, "r");
     // se o arquivo existir
     if (!(arquivo==NULL)){
         // abre o arquivo temporario
         arq_temp = fopen(Temp, "wb");
         if (!arq_temp) Erro();
         fread(temp_registro, sizeof(*temp_registro),1, arquivo);
        do{
            if ((strcmp(registra->nome, temp_registro->nome) < 0) && (!inseriu)){
                fwrite(registra, sizeof(*registra),1, arq_temp);
                inseriu = 1;
            }
            fwrite(temp_registro, sizeof(*temp_registro), 1, arq_temp);
            fread(temp_registro, sizeof(*temp_registro),1, arquivo);
        }while (!feof(arquivo));
        if (!inseriu){
          fwrite(registra, sizeof(*registra), 1, arq_temp);
        }
        fclose(arquivo);
        fclose(arq_temp);
        remove(Dados);
        rename(Temp, Dados);
        remove(Temp);
     }else{
         arquivo = fopen(Dados, "w");
         fwrite(registra, sizeof(*registra), 1, arquivo);
         fclose(arquivo);
     }
      return 0;
}

int conf(){
    char con[25];
    int ret = 0;
    printf("Confirmar os dados(Sim/Nao/Cancelar):");
    scanf("%[^\n]s",con);
    if(strcmp(convert(con),"NAO") == 0){
        //Limpa o terminal ou tela;
        printf("\e[H\e[2J");
        printf("Preencha os campos novamente!\n");
        incluir();
        ret = 0;
    }else if(strcmp(convert(con),"CANCELAR") == 0){
        printf("\e[H\e[2J");
        printf("Operação cancelada!\n");
         main();
        ret = 0;
    }else if(strcmp(convert(con),"SIM") == 0){
        printf("\e[H\e[2J");
        printf("Contato Salvo!\n");
        ret++;
    }
    return ret;
}

dados* buscar(){
      char nome[80];
      int Achou = 0;
      FILE *arquivo;
      dados *registro;

      // aloca memoria para a struct
      registro = (dados *)calloc(1,sizeof(dados));
      if (!registro) Erro();

      arquivo = fopen(Dados, "r");
      if (arquivo==NULL){
          //printf("\e[H\e[2J");
          printf("Nao há pessoas cadastradas!\n");
          free(registro);
          return 0;
        }
        //printf("\e[H\e[2J");
        printf("\nDigite o nome para busca: ");
        setbuf(stdin,NULL);
        scanf("%[^\n]s",nome);
      do{
          fread(registro, sizeof(*registro),1, arquivo);
          if (!feof(arquivo))
            if (!(strcmp(registro->nome, nome))){
              Achou = 1;
              printf("\nNome:%s\n",registro->nome);
              printf("Idade:%s\n",registro->idade);
              printf("Telefone:%s\n",registro->fone);
              printf("Email:%s\n",registro->email);
              printf("Estado:%s\n",registro->estado);
              printf("Cidade:%s\n",registro->cidade);
              printf("Rua:%s\n",registro->rua);
              printf("Numero:%s\n",registro->numero);
              break;
            }
      }while(!feof(arquivo) && !Achou);
      fclose(arquivo);
      if (!Achou){
          printf("\e[H\e[2J");
          printf("\nNome '%s' nao pode ser encontrado!\n", nome);
          main();
          return 0;
      }
      return registro;
}

int creditos(){
    printf("\e[H\e[2J");
    printf("\n\t|*******************************************************|\n");
    printf("\t|                    Creditos                           |\n");
    printf("\t|*******************************************************|\n");
    printf("\t|University: UNIVERSISADADE FEDERAL DA FRONTEIRA SUL    |\n");
    printf("\t|Author: Vinicius Kaian Lira e Adriel Schmitz           |\n");
    printf("\t|Course: Ciência da Computação                          |\n");
    printf("\t|Half: 1º                                               |\n");
    printf("\t|Matter:Algoritimos e programacao                       |\n");
    printf("\t|*******************************************************|\n\n");
    main();
    return 0;
}

int Erro(){
    printf("\e[H\e[2J");
    printf("\nErro ao tentar executar!\n");
    exit(0);
    return 0;
}

int exibir(){
      FILE *arquivo;
      dados *registro;

      // aloca memoria para a struct
      registro = (dados *)calloc(1,sizeof(dados));
      if (!registro) Erro();

      arquivo = fopen(Dados, "r");
      if (arquivo == NULL){
          printf("\e[H\e[2J");
          printf("Nao há pessoas cadastradas!\n");
          free(registro);
          main();
          return 0;
        }
      do{
          fread(registro, sizeof(*registro),1, arquivo);
          if((feof(arquivo))){
             break;
             free(registro);
             fclose(arquivo);
             main();
         }else{
             printf("Nome:%s\n",registro->nome);
             printf("Idade:%s\n",registro->idade);
             printf("Telefone:%s\n",registro->fone);
             printf("Email:%s\n",registro->email);
             printf("Estado:%s\n",registro->estado);
             printf("Cidade:%s\n",registro->cidade);
             printf("Rua:%s\n",registro->rua);
             printf("Numero:%s\n\n",registro->numero);
         }
      }while(!(feof(arquivo)));
      free(registro);
      fclose(arquivo);
      main();
      return 0;
}

char* convert(char l[]){
	int tamanho_string = 0,i = 0;
	char *pt;
	//Pega o tamanho da string passada pelo parametro l[];
	tamanho_string = strlen(l);
	for(i = 0;i < tamanho_string;i++){
        l[i] = toupper(l[i]);
    }
	pt = l;
	return pt;
}
