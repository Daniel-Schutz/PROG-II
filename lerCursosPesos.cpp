//Verficar porque esta imprimindo ÔÇô ao invés do hifen -
#include<stdio.h>  /*FILE, printf, scanf*/
#include <stdlib.h>  // malloc, calloc
#define MAX 60 //Qual o máximo que tem q definir??

struct tipoCurso{
    char nomeCurso[MAX];    /* nome do curso + bacharel/licenciatura */
    int codCurso, pesoRed, pesoMat, pesoLing, pesoHum, pesoNat;   
};

int main()
{
    
    FILE*  arq;         /* variavel para acessar um arquivo */
    char nome[MAX];     /* nome do arquivo a ser aberto*/
    int quant; /*pra alocar dinamicamente*/
    tipoCurso *curso;
    
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

        curso = (tipoCurso *) malloc(quant * sizeof(tipoCurso));

         if (curso != NULL){

             for(int i=0;i<quant;i++){
             fscanf(arq, "%d %[^0^1^2^3^4^5^6^7^8^9] %d %d %d %d %d", &curso[i].codCurso, curso[i].nomeCurso, &curso[i].pesoRed, &curso[i].pesoMat, &curso[i].pesoLing, &curso[i].pesoHum, &curso[i].pesoNat); //verificar como fazer a leitura do curso
                }
             for(int i=0;i<quant;i++){
            printf("%d %s %d %d %d %d %d\n", curso[i].codCurso, curso[i].nomeCurso, curso[i].pesoRed, curso[i].pesoMat, curso[i].pesoLing, curso[i].pesoHum, curso[i].pesoNat); 
        }    
        
         } else{
            printf("Impossível alocar espaço\n");
         }

       
        
        /*fechamento do arquivo*/
        fclose(arq);
        
    }
    printf("\n");    
    return 0;
}



