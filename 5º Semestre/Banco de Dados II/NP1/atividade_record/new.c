#include <stdio.h>
#include <string.h>

void insert(FILE *f){
    char nfield[50];
    unsigned char lfield;
    strcpy(nfield,"Nome");
    fwrite(nfield,strlen(nfield)+1,1,f);
    lfield=30;
    fwrite(&lfield, sizeof(char),1,f);
    strcpy(nfield,"Pretonmoyus Vicusis");
    fwrite(nfield,lfield,1,f);
    ///////////
    strcpy(nfield,"Local");
    fwrite(nfield,strlen(nfield)+1,1,f);
    lfield=20;
    fwrite(&lfield, sizeof(char),1,f);
    strcpy(nfield,"Mangue X");
    fwrite(nfield,lfield,1,f);
    ///
    strcpy(nfield,"Data");
    fwrite(nfield,strlen(nfield)+1,1,f);
    lfield=11;
    fwrite(&lfield, sizeof(char),1,f);
    strcpy(nfield,"05/12/2014");
    fwrite(nfield,lfield,1,f);
    ///
    lfield='#';
    fwrite(&lfield, sizeof(char),1,f);
    /// end of first record   
    ///
    strcpy(nfield,"Familia");
    fwrite(nfield,strlen(nfield)+1,1,f);
    lfield=10;
    fwrite(&lfield, sizeof(char),1,f);
    strcpy(nfield,"Lescia");
    fwrite(nfield,lfield,1,f);
    ///////////
    strcpy(nfield,"Filo");
    fwrite(nfield,strlen(nfield)+1,1,f);
    lfield=10;
    fwrite(&lfield, sizeof(char),1,f);
    strcpy(nfield,"Bacteria");
    fwrite(nfield,lfield,1,f);
    ///
    ///
    lfield='#';
    fwrite(&lfield, sizeof(char),1,f);
}

int main(void){
    FILE *f;
    char c, t;
    char buf[100];
    //unsigned char lfield;
    f=fopen("ex2.dat","w");
    insert(f);
    fclose(f);
    ////
    f=fopen("ex2.dat","r");
    fseek(f,0,SEEK_SET);
    fread(&c,1,1,f);
    while(!feof(f)){
        while(!feof(f) && c!='#'){
            while(c != 0){
                printf("%c",c);
                fread(&c,1,1,f);
            }
            fread(&t, sizeof(char),1,f);
            fread(buf,t,1,f);
            printf(": %s\n",buf);
            fread(&c,1,1,f);
        }
        printf("\n");
        fread(&c,1,1,f);
    }

    fclose(f);
	return 1;
}   