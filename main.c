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
    char codigo;

    char buffer[90];
    char buffer2[90];
    char buffer3[30];

 int cod,tam,tam2,tam3,tam_campo,cont,pos;
int oft,oft2,header,oft3;

printf("INSERÇÂO DE AMIGUINHO\n");
        if((arq=fopen("amigos.dad","r+b")==NULL)){
            arq=fopen("amigos.dad","w+b");
            printf("criando header\n");

            oft=-1;
            fwrite(&oft,sizeof(long),1,arq);
             printf("criando header\n");
            fprintf(arq,"|");
            }
          else{arq=fopen("amigos.dad","r+b");}
        oft=ftell(arq);
        printf("COMECO%d\n",oft);
        printf("Digite o codigo do amiguinho\n");
        scanf("%d",&cod);
        fflush(stdin);
        printf("Digite o nome do amiguinho\n");
        scanf("%s",&nome);
        fflush(stdin);
        printf("Digite o telefone do amiguinho\n");
        scanf("%s",&telefone);
        fflush(stdin);




        sprintf(buffer,"%d|%s|%s|",cod,nome,telefone);
        tam = strlen(buffer);
printf("tamanho %d\n",tam);

      fseek(arq,0,SEEK_SET);
      oft3=ftell(arq);
fread(&header,sizeof(long),1,arq);
printf("ENDERECO NO HEADER%d\n",header);
if(header==-1){
    printf("IMPIMINDO NO FIM\n");
       fseek(arq,0,SEEK_END);
      fwrite(&tam,sizeof(int),1,arq);
        fwrite(buffer, sizeof(char), tam, arq);
        fclose(arq);
        return;
}
else{
    while(header!=-1){

    fseek(arq,header,SEEK_SET);
    fread(&tam2,sizeof(int),1,arq);
    printf("Tamanho disponivel na posicao:%d\n",tam2);
     fseek(arq,1,SEEK_CUR);

    fread(&oft,sizeof(int),1,arq);
    printf("Proxima pos:%d\n",oft);
        if(tam<=tam2){
            tam3=tam2-tam;
            if(tam3>=9){
        fseek(arq,header,SEEK_SET);
            fwrite(&tam,sizeof(int),1,arq);
        fwrite(buffer, sizeof(char), tam, arq);
        oft2=ftell(arq);
        fwrite(&tam3,sizeof(int),1,arq);
        fprintf(arq,"*");
        fwrite(&oft,sizeof(int),1,arq);
        fseek(arq,oft3,SEEK_SET);
        fwrite(&oft2,sizeof(int),1,arq);
        fclose(arq);
            return;
            }
            else{
                fwrite(&tam2,sizeof(int),1,arq);
                fwrite(buffer,sizeof(char),tam2,arq);
                fseek(arq,oft3,SEEK_SET);
                fwrite(&oft,sizeof(int),1,arq);
                fclose(arq);
                return;
            }
        }
    oft3=ftell(arq);
    header=oft;
    }
printf("IMPRIMINDO NO FIM MESMO\n");
       fseek(arq,0,SEEK_END);
      fwrite(&tam,sizeof(int),1,arq);
      printf("%s\n",buffer);
        fwrite(buffer, sizeof(char), tam, arq);
        fclose(arq);
        return;

}
}
     /*   tam2= pega_registro(arq,buffer2);
oft=ftell(arq);

         while (tam2> 0)
   {    printf("\n%s\n",buffer2);
        printf("Tamanho2 : %d\n",tam2);

        pos=0;
        tam_campo = pega_campo(buffer2,&pos,buffer3);
        printf("\n comparacao%c\n",buffer3[0]);
        printf("\n codigo %c\n",codigo);
        printf("batata");

        if((codigo==buffer3[0]) &&(tam<=tam2)){

printf("ORRAAAAAAA\n");
            oft2=ftell(arq);
            fseek(arq,oft,SEEK_SET);
            tam3=tam2 - tam;
             if(tam3>=4){

           fwrite(&tam,sizeof(int),1,arq);
        fwrite(buffer, sizeof(char), tam, arq);


            fwrite(&tam3,sizeof(int),1,arq);

            fprintf(arq,"*");

            fwrite(&oft2,sizeof(int),1,arq);
            fprintf(arq,"|");
             }
           else{

           fwrite(&tam2,sizeof(int),1,arq);
        fwrite(buffer, sizeof(char), tam, arq);

           }
           fclose(arq);
        return;
        }


    oft=ftell(arq);

        tam2= pega_registro(arq,buffer2);

   }
  fwrite(&tam,sizeof(int),1,arq);
        fwrite(buffer, sizeof(char), tam, arq);


fclose(arq);
       // fseek(arq,i,SEEK_CUR);


      // while
        // printf("%d",&cod);

*/



void leitura(){

FILE *arq;

    char nome[50];
    char telefone[20];
    char codigo;

    char buffer[90];
    char buffer2[30];
    arq=fopen("amigos.dad","r+b");
        fseek(arq,5,SEEK_SET);

 int cod,tam,tam_campo,cont,pos;
offset(arq);
         tam= pega_registro(arq,buffer);
codigo='*';

         while (tam> 0)
   {        printf("Tamanho do registro:%d\n",tam);
            pos = 0;
        tam_campo = pega_campo(buffer,&pos,buffer2);
        //printf("%d %d  %d",tam,tam_campo,pos);

       // while (pos <= tam){
            if(codigo!=buffer2[0]){

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

            }
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


 int cod,tam,tam_campo,cont,pos;
 int oft,oft2,header;

fseek(arq,0,SEEK_SET);
fread(&header,sizeof(long),1,arq);
printf("ENDERECO NO HEADER%d\n",header);
fseek(arq,5,SEEK_SET);
printf("Digite o codigo do amiguinho a ser removido");
scanf("%s",&codigo);
         tam= pega_registro(arq,buffer);
oft=ftell(arq);

         while (tam> 0)
   {
             pos=0;
        tam_campo = pega_campo(buffer,&pos,buffer2);
        //printf("%d %d  %d",tam,tam_campo,pos);


                if(!strcmp(codigo,buffer2)){
                oft2=ftell(arq);
            printf("tamanho: %d\n",tam_campo);
            printf("Codigo: %s\n\n",buffer2);
            printf("Posicao no registro:%d\n",pos);

            fseek(arq,oft,SEEK_SET);

            fwrite(&tam,sizeof(int),1,arq);

            fprintf(arq,"*");

            fwrite(&header,sizeof(int),1,arq);
            fseek(arq,0,SEEK_SET);
            fwrite(&oft,sizeof(int),1,arq);
        fseek(arq,oft2,SEEK_SET);
        }
    oft=ftell(arq);

        tam= pega_registro(arq,buffer);
       // getch();

    }

}





