#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
Data schema is organized as follows:
- First 15 characters bytes represent field name counting \0
- Next 1 character byte the type of the field (S string, C character and I integer)
- Next int bytes, the lenght of the field

The schema is located in the header of data file and a header can have
at most 10 field definitions.
In the case that there are less than 10 field definitions, the next empty
definition will have character # in the name of the field.
*/

#define MFIELD 10

void buildHeader(){
	char fname[15], ftype;
	int flen;
	FILE *f;
	f=fopen("agenda.dat","w+");
	if(f==NULL){
		printf("File could not be created\n");
		exit(0);
    }
    /// first field (attribute Name)
    strcpy(fname,"codigo");
    ftype='S';
    flen=5;
    fwrite(fname,15,1,f);
    fwrite(&ftype,1,1,f);
    fwrite(&flen,sizeof(int),1,f);
    /////
    strcpy(fname,"nome");
    ftype = 'S';
    flen = 20;
    fwrite(fname,15,1,f);
    fwrite(&ftype,1,1,f);
    fwrite(&flen,sizeof(int),1,f);
    /// second field (attribute email)
    strcpy(fname,"idade");
    ftype='I';
    flen=sizeof(int);
    fwrite(fname,15,1,f);
    fwrite(&ftype,1,1,f);
    fwrite(&flen,sizeof(int),1,f);
    /// third field (attribute age)
    //strcpy(fname,"age");
    //ftype='I';
    //flen=sizeof(int);
    //fwrite(fname,15,1,f);
    //fwrite(&ftype,1,1,f);
    //fwrite(&flen,sizeof(int),1,f);
    //// the other 7 must have the flag #
    strcpy(fname,"#");
    fwrite(fname,15+1+sizeof(int),MFIELD-3,f);
    fclose(f);
}

struct theader{
	char name[15];
	char type;
	int  len;
};

union tint{
	char cint[sizeof(int)];
	int vint;
};

////
struct theader *readHeader(){
	FILE *f;
	struct theader *th=(struct theader*) malloc(sizeof(struct theader)*MFIELD);
	int i;
	////
	f = fopen("agenda.dat","r");
	if(f == NULL){
		printf("File not found\n");
		exit(0);
    }
    ///
	for(i=0;i<MFIELD;i++){
		fread(th[i].name,15,1,f);
		fread(&th[i].type,1,1,f);
		fread(&th[i].len,sizeof(int),1,f);
	}
	fclose(f);
	return th;
}

void insert(){
    FILE *f;
	struct theader *t;
	int i;
	char opt, buf[100],c;
	union tint eint;
	////
	t = readHeader();
	f = fopen("agenda.dat","a+");
	if(f == NULL){
		printf("File not found\n");
		exit(0);
    }
    do{
		i=0;
		while(i<10 && t[i].name[0] != '#'){
			printf("\n%s :",t[i].name);
			switch (t[i].type){
				case 'S':
					fgets(buf,t[i].len+1,stdin);
				    if(buf[strlen(buf)-1]!='\n')  
				    	c = getchar();
				    else 
				    	buf[strlen(buf)-1]=0;
					fwrite(buf,t[i].len,1,f);
				break; 
				case 'C': 
					buf[0] = fgetc(stdin); 
				    while((c = getchar()) != '\n' && c != EOF); /// garbage collector
				        fwrite(buf,t[i].len,1,f);
				break;
				case 'I': 
					scanf("%d",&eint.vint);
				    while((c = getchar()) != '\n' && c != EOF); /// garbage collector
				        fwrite (&eint.vint,t[i].len,1,f);
				break;
		    }
		    
		    i++;
	    }
		printf("Continuar (S/N): "); 
		opt=getchar();
		while((c = getchar()) != '\n' && c != EOF); /// garbage collector
	}while(opt=='S' || opt=='s');
	fclose(f);
}

void selectAll(){
    FILE *f;
	struct theader *t;
	int hlen,i,j,space;
	char buf[100];
	union tint eint;
	////
	t = readHeader();
	f = fopen("agenda.dat","r");
	if(f == NULL){
		printf("File not found\n");
		exit(0);
    }
    ///
	//    hlen=MFIELD*(15+1+sizeof(int));
	//    fseek(f,hlen,SEEK_SET);
    /// read record a record
    i = 0;
    while(i<10 && t[i].name[0]!='#'){
        printf("%s ",t[i].name);
        space = t[i].len-strlen(t[i].name);
        for (j=1; j<=space; j++)
        	printf(" ");
        i++;
    }
    printf("\n");
    ///
    hlen = MFIELD*(15+1+sizeof(int));
    /// skip file's header
    fseek(f,hlen,SEEK_SET);
    do {
		i=0;
		while(i<10 && t[i].name[0]!='#'){
  			if(!fread(buf,t[i].len,1,f)) break;
			switch (t[i].type){
			    case 'S': 
				    for(j=0; j<t[i].len && buf[j]!=0; j++)
				        printf("%c", buf[j]);
				    
				        space = t[i].len-j;
	                for(j=0; j<=space; j++)
	                    printf(" ");
					break;
				case 'C': 
					printf("%c ", buf[0]);
					break;
				case 'I': 
					for(j=0; j< t[i].len; j++) eint.cint[j] = buf[j];
				    	printf("%d", eint.vint); 
					break;
		    }
		    i++;
	    }
	    printf("\n");
    }while(!feof(f));

}

int main(void){
	///buildHeader();
	//insert();	
    selectAll();	
	
	return 0;
}