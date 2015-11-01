#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int pega_campo(char *p_registro, int *p_pos, char *p_campo);
int pega_registro(FILE *p_out, char *p_reg);
void offset(FILE *arq);
void insercao();
void leitura();
void menu();
void remocao();
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


   menu();

}






int pega_registro(FILE *p_out, char *p_reg)
{
     int bytes;

     if (!fread(&bytes, sizeof(int), 1, p_out))
       return 0;
     else {
            fread(p_reg, bytes, 1, p_out);
            return bytes;
          }
}

int pega_campo(char *p_registro, int *p_pos, char *p_campo)
{
     char ch;
     int i=0;

     p_campo[i] = '\0';

     ch = p_registro[*p_pos];
     while ((ch != '|') && (ch!=EOF))
      {
           p_campo[i] = ch;
           i++;
           ch = p_registro[++(*p_pos)];
      }
     ++(*p_pos);
     p_campo[i] = '\0';

     return strlen(p_campo);
}

void offset(FILE *arq){
int oft;
 oft=ftell(arq);
printf("Offset:%d\n",oft);

}


void insercao(){

     FILE *arq;

    char nome[50];
    char telefone[20];
    char codigo[5];

    char buffer[90];
    char buffer2[30];

 int cod,tam,tam_campo,cont,pos;


printf("INSERÇÂO DE AMIGUINHO\n");
        arq=fopen("amigos.dad","a+b");

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



        sprintf(buffer,"%d|%s|%s|",cod,nome,telefone);
        tam = strlen(buffer);
        fwrite(&tam,sizeof(int),1,arq);
        fwrite(buffer, sizeof(char), tam, arq);


       // fseek(arq,i,SEEK_CUR);


      // while
        // printf("%d",&cod);
fclose(arq);


}


void leitura(){

FILE *arq;

    char nome[50];
    char telefone[20];
    char codigo[5];

    char buffer[90];
    char buffer2[30];
    arq=fopen("amigos.dad","r+b");
        fseek(arq,0,SEEK_SET);

 int cod,tam,tam_campo,cont,pos;
offset(arq);
         tam= pega_registro(arq,buffer);


         while (tam> 0)
   {
            pos = 0;
        tam_campo = pega_campo(buffer,&pos,buffer2);
        //printf("%d %d  %d",tam,tam_campo,pos);

       // while (pos <= tam){


            printf("tamanho: %d\n",tam_campo);
            printf("Codigo: %s\n\n",buffer2);
            printf("Posicao no registro:%d\n",pos);

            tam_campo = pega_campo(buffer,&pos,buffer2);
               printf("tamanho: %d\n",tam_campo);
            printf("Nome: %s\n\n",buffer2);
            printf("Posicao no registro:%d\n",pos);

            tam_campo = pega_campo(buffer,&pos,buffer2);
               printf("tamanho: %d\n",tam_campo);
            printf("Telefone: %s\n\n",buffer2);
            printf("Posicao no registro:%d\n",pos);

            tam_campo = pega_campo(buffer,&pos,buffer2);
        //  }
          offset(arq);
        tam= pega_registro(arq,buffer);
       // getch();
   }

  fclose(arq);






}


void menu(){


int sel;

    printf("OLA,SOU MENUZINHO SEU AMIGUINHO!!!\n");
    printf("VAMOS BRINCA!SELECIONE A OPÇÂO!\n");
    printf("1-INSERIR AMIGUINHO\n2-FICAR DE MAL\n3-COMPACTAR AQUIVO\n4-LISTAR AMIGUINHOS\n0-Sair\n");
    scanf("%d",&sel);
    switch(sel){
    case 1:
        insercao();
        menu();
        break;
    case 2  :

        remocao();
        break;
    case 3:
        printf("COMPACTA ARQUIVO");
        break;
    case 4:
        leitura();
        menu();
    case 0:
        return;
/*
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
       }*/

        break;


    }



}





void remocao(){


FILE *arq;

    char nome[50];
    char telefone[20];
    char codigo[5];

    char buffer[90];
    char buffer2[30];
    arq=fopen("amigos.dad","r+b");
        fseek(arq,0,SEEK_SET);

 int cod,tam,tam_campo,cont,pos;


printf("Digite o codigo do amiguinho a ser removido");
scanf("%s",&codigo);
         tam= pega_registro(arq,buffer);


         while (tam> 0)
   {
             pos=0;
        tam_campo = pega_campo(buffer,&pos,buffer2);
        //printf("%d %d  %d",tam,tam_campo,pos);


                if(!strcmp(codigo,buffer2)){
            printf("tamanho: %d\n",tam_campo);
            printf("Codigo: %s\n\n",buffer2);
            printf("Posicao no registro:%d\n",pos);
            offset(arq);
        }


        tam= pega_registro(arq,buffer);
       // getch();
   }


}


