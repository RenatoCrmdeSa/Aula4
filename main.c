#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reg{

int tam;

int cod;
char p1;
char nome;
char p2;
char telefone;
char p3;
} reg;


int main()
{
    FILE *arq;

    char nome[50];
    char telefone[20];
    char codigo[5];
    char pipe;
    char buffer[2];
    char buffer2;


    int sel,cod,tam,cont;
    pipe='|';
    printf("OLA,SOU MENUZINHO SEU AMIGUINHO!!!\n");
    printf("VAMOS BRINCA!SELECIONE A OPÇÂO!\n");
    printf("1-INSERIR AMIGUINHO\n2-FICAR DE MAL\n3-COMPACTAR AQUIVO\n4-LISTAR AMIGUINHOS\n");
    scanf("%d",&sel);
    switch(sel){
    case 1:
        printf("INSERÇÂO DE AMIGUINHO\n");
        arq=fopen("amigos.dad","a+");

        printf("Digite o codido do amiguinho\n");
        scanf("%d",&cod);
        fflush(stdin);
        printf("Digite o nome do amiguinho\n");
        scanf("%s",&nome);
        fflush(stdin);
        printf("Digite o telefone do amiguinho\n");
        scanf("%s",&telefone);
        fflush(stdin);
        itoa(cod,codigo,10);
       tam=strlen(nome)+strlen(telefone)+strlen(codigo)+3*sizeof(char);
       printf("Tamanho do registro:%d\/",tam);

       fprintf(arq,"%d",tam);
             printf("ORA");
       fprintf(arq,"%d",cod);
            printf("ORA");
       fprintf(arq,"|");
            printf("ORA");
       fprintf(arq,"%s",nome);
            printf("ORA");
       fprintf(arq,"|");
       fprintf(arq,"%s",telefone);
       fprintf(arq,"|");
       fprintf(arq,"\n");

       // fseek(arq,i,SEEK_CUR);


      // while
        // printf("%d",&cod);

        break;
    case 2  :
        printf("DIGA O AMIGUINHO FEIO");
        break;
    case 3:
        printf("COMPACTA ARQUIVO");
        break;
    case 4:
        arq=fopen("amigos.dad","r");
        fseek(arq,0,SEEK_SET);

       while(fread(&buffer,sizeof(char),2,arq)){
        //printf("%c",buffer);


            printf("Ora");

        //strcat(buffer,buffer2);
       // strncpy(buffer,buffer,2);
        cont=atoi(buffer);
        printf("%d\n",cont);
        fread(&buffer,sizeof(char),1,arq);
        while(buffer!="|"){
        if(buffer!="|"){
        printf("%d",buffer);
        fread(&buffer,sizeof(char),1,arq);

        }
        }
            cont--;
         cod=atoi(buffer);
        system("PAUSE");

        while(cont>0){
              fread(&buffer2,sizeof(char),1,arq);
        printf("%c",buffer2);
            cont--;
        }
        fread(&buffer2,sizeof(char),2,arq);
        printf("Ora");
        printf("%c",buffer2);
       }
        break;



    }

}
