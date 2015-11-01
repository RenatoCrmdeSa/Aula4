#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int pega_campo(char *p_registro, int *p_pos, char *p_campo);
int pega_registro(FILE *p_out, char *p_reg);


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
    char buffer[90];
    char buffer2[30];


    int sel,cod,tam,tam_campo,cont,pos;
    pipe='|';
    printf("OLA,SOU MENUZINHO SEU AMIGUINHO!!!\n");
    printf("VAMOS BRINCA!SELECIONE A OPÇÂO!\n");
    printf("1-INSERIR AMIGUINHO\n2-FICAR DE MAL\n3-COMPACTAR AQUIVO\n4-LISTAR AMIGUINHOS\n");
    scanf("%d",&sel);
    switch(sel){
    case 1:
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
        fwrite(&tam, sizeof(int), 1, arq);
        fwrite(buffer, sizeof(char), tam, arq);


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
        arq=fopen("amigos.dad","r+b");
        fseek(arq,0,SEEK_SET);
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

         tam= pega_registro(arq,buffer);


         while (tam> 0)
   {
        pos = 0;
        tam_campo = pega_campo(buffer,&pos,buffer2);
        //printf("%d %d  %d",tam,tam_campo,pos);

        while (pos <= tam)
          {

            printf("tamanho: %d\n",tam_campo);
            printf("campo: %s\n\n",buffer2);
            printf("Posicao:%d\n",pos);
            tam_campo = pega_campo(buffer,&pos,buffer2);
          }
        tam= pega_registro(arq,buffer);
       // getch();
   }

  fclose(arq);




        break;



    }

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
