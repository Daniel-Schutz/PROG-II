//Talvez seja meljhor usar matriz ao invés de struct
//verificar erro da impressão (imprimindo varios 0 entre os campos)
#include<stdio.h>  /*FILE, printf, scanf*/
#include <stdlib.h>  // malloc, calloc
#define MAX 60 //Qual o máximo que tem q definir??

struct tipoVaga{
    int codvaga, AC, L1, L3, L4, L5, L7, L8, L9, L11, L13, L15;   
};

int main()
{
    
    FILE*  arq;         /* variavel para acessar um arquivo */
    char nome[MAX];     /* nome do arquivo a ser aberto*/
    int quant; /*pra alocar dinamicamente*/
    tipoVaga *vaga;
    
    printf("Digite o nome do arquivo:");//entrada
    scanf(" %s", nome);
    
    /*abertura de um arquivo*/
    arq = fopen(nome, "r"); //conferir se usa o "r" mesmo
    
    /* verificando se arquivo foi aberto */
    if( arq == NULL )
    {
        printf("\n\n Arquivo %s nao pode ser aberto.\n\n", nome);
    }
    else
    {
        printf("Arquivo foi aberto!\n\n");
        
        fscanf(arq, "%d", &quant);
  
        vaga = (tipoVaga *) malloc(quant * sizeof(tipoVaga));

         if (vaga != NULL){

             for(int i=0;i<quant;i++){
             fscanf(arq, "%d %d %d %d %d %d %d %d %d %d %d %d", &vaga[i].codvaga, &vaga[i].AC, &vaga[i].L1, &vaga[i].L3, &vaga[i].L4, &vaga[i].L5, &vaga[i].L7, &vaga[i].L8, &vaga[i].L9, &vaga[i].L11, &vaga[i].L13, &vaga[i].L15); //verificar como fazer a leitura do vaga
             }
             for(int i=0;i<quant;i++){
            printf("%d %d %d %d %d %d %d %d %d %d %d %d \n", vaga[i].codvaga, vaga[i].AC, vaga[i].L1, vaga[i].L3, vaga[i].L4, vaga[i].L5, vaga[i].L7, vaga[i].L8, vaga[i].L9, vaga[i].L11, vaga[i].L13, vaga[i].L15); 
        }   
        free(vaga);
        
        }
         else{
            printf("Impossível alocar espaço\n");
         }

       
        
        /*fechamento do arquivo*/     
        fclose(arq);
        
    }
    printf("\n");    
    return 0;
}


