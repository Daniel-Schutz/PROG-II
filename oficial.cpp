#include <stdio.h>
#include <stdlib.h>  // malloc, calloc
#include "funcoes.h"
#define MAX 60 //definir um valor


int main(){
tipoCurso *curso; //tipocurso
int cont = 0;
int opcao;
int quant; // quantidade total de cursos
int qtdAlunos; // quantidade total de candidatos
float media[4]; // ling / mat / nat / hum
float desvio[4]; // ling / mat / nat / hum
int soma[4]; // ling / mat / nat / hum
char nomePeso[MAX],nomeVaga[MAX],nomeDados[MAX],nomeAcertos[MAX]; //vai precisar mesmo disso ou vai ler direto?


while (opcao!=0){
  printf("0 - Carregar os arquivos de entrada\n");
  printf("Digite a opcao desejada:");
  scanf("%d", &opcao);  
  }

if (opcao==0){
printf("\nEscreva o nome do arquivo dos cursos e pesos:");
scanf("%s",nomePeso);
 FILE*  arq;         /* variavel para acessar um arquivo */

    /*abertura de um arquivo*/
    arq = fopen(nomePeso, "r");
    
    /* verificando se arquivo foi aberto */
    if( arq == NULL )
    {
        printf("\n\n Arquivo %s nao pode ser aberto.\n\n", nomePeso);
    }
    else
    {

        fscanf(arq, "%d", &quant);

        curso = (tipoCurso *) malloc(quant * sizeof(tipoCurso));

         if (curso != NULL){

             for(int i=0;i<quant;i++){
             fscanf(arq, "%d %[^0^1^2^3^4^5^6^7^8^9] %d %d %d %d %d", &curso[i].codCurso, curso[i].nomeCurso, &curso[i].pesoRed, &curso[i].pesoMat, &curso[i].pesoLing, &curso[i].pesoHum, &curso[i].pesoNat); //verificar como fazer a leitura do curso
                }
            
         } else{
            printf("Impossível alocar espaço\n");
         }


        
        /*fechamento do arquivo*/
        fclose(arq);
        
    }




//ler e armazenar cursos e vagas
printf("\nEscreva o nome do arquivo dos cursos e vagas:");
scanf("%s",nomeVaga);
tipoVaga *vaga;
    
    /*abertura de um arquivo*/
    arq = fopen(nomeVaga, "r");
    
    /* verificando se arquivo foi aberto */
    if( arq == NULL )
    {
        printf("\n\n Arquivo %s nao pode ser aberto.\n\n", nomeVaga);
    }
    else
    {
        fscanf(arq, "%d", &quant);
  
        vaga = (tipoVaga *) malloc(quant * sizeof(tipoVaga));

         if (vaga != NULL){

             for(int i=0;i<quant;i++){
             fscanf(arq, "%d %d %d %d %d %d %d %d %d %d %d %d", &vaga[i].codvaga, &vaga[i].AC, &vaga[i].L1, &vaga[i].L3, &vaga[i].L4, &vaga[i].L5, &vaga[i].L7, &vaga[i].L8, &vaga[i].L9, &vaga[i].L11, &vaga[i].L13, &vaga[i].L15); //verificar como fazer a leitura do vaga
             }}
            
         else{
            printf("Impossível alocar espaço\n");
         }

       
        
        /*fechamento do arquivo*/     
        fclose(arq);
        
    }
   







//ler e armazenar os dados dos inscritos
printf("\nEscreva o nome do arquivo dos dados dos inscritos:");
scanf("%s",nomeDados);
cursoDados *titulo;

    //abertura do arquivo
    arq = fopen(nomeDados,"r");

    if (arq == NULL){
        printf("\n\nO arquivo não pode ser aberto\n\n");
    }


    //executar leitura do arquivo
    else{     
        

        titulo = (cursoDados *) malloc(quant * sizeof(cursoDados));

        for (int i=0;i<quant;i++){ //ler até acabar o arquivo

            fscanf(arq, "%d %d", &titulo[i].codcurso, &titulo[i].qtd); // a primeira linha tem duas entradas

            //alocar memória pra cada bloco            
            titulo[i].tuplas = (dadoEmLinhas *) malloc (titulo[i].qtd * sizeof(dadoEmLinhas)); //aloca dinâmicamente as linhas


            //verificar se alocou
            if (titulo[i].tuplas == NULL){
                printf("Não foi possível alocar na memória");
                break;
            }


            else{
                //executar a leitura dos dados de forma correta para cada bloco;
                int x;
                for (x=0; x < titulo[i].qtd; x++){
                    fscanf(arq, "%d %[^0^1^2^3^4^5^6^7^8^9] %d/%d/%d %[^\n]", &titulo[i].tuplas[x].codinscricao, titulo[i].tuplas[x].nomecandidato, &titulo[i].tuplas[x].datanasc.dia, &titulo[i].tuplas[x].datanasc.mes, &titulo[i].tuplas[x].datanasc.ano, titulo[i].tuplas[x].tipovaga);
                }

            
                
            }
            fclose(arq);
        }
    }




printf("\nEscreva o nome do arquivo dos acertos dos inscritos:");
scanf("%s",nomeAcertos);
//void lerAcertos(nomeAcertos);//passar mais argumentos

    acertos_notas *contagem; //registro a ser alocado dinâmicamente
    
    //
    arq = fopen(nomeAcertos,"r"); //abrindo arquivo;
    

    if (nomeAcertos==NULL){
        printf("\n\nO arquivo não pode ser aberto\n\n");
    }


    else{
        //fazer alocação dinâmica e leitura das entradas
        
        fscanf(arq, "%d", &qtdAlunos); //guarda a quantidade de alunos;
        
        contagem = (acertos_notas*) malloc(qtdAlunos*sizeof(acertos_notas)); //alocação
        
        int i;
        for (i = 0; i < qtdAlunos; i++){
            fscanf(arq, "%d %d %d %d %d %.2f", &contagem[i].insc, &contagem[i].v_ling, &contagem[i].v_mat, &contagem[i].v_nat, &contagem[i].v_hum, &contagem[i].red); //leitura dos dados
            if (i == 0){
                soma[0] = contagem[i].v_ling;
                soma[1] = contagem[i].v_mat;
                soma[2] = contagem[i].v_nat;
                soma[3] = contagem[i].v_hum;
                }
            else{
                soma[0] = soma[0] + contagem[i].v_ling;
                soma[1] = soma[1] + contagem[i].v_mat;
                soma[2] = soma[2] + contagem[i].v_nat;
                soma[3] = soma[3] + contagem[i].v_hum;
            }
        }
            //OPERAÇÕES
            // -----------------------------
            /*Nessa parte de operações, temos que calcular a média dos acertos em determinada área considerando todos os candidatos, para assim calcular o desvio padrão através da formula indicada no documento do trabalho.
            Como aqui será uma função ler, não vai ser adequado realizar as operações aqui, uma vez que não será possível retornar mais de um valor e temos diversas áreas, logo, isso explica a criação da função média, desvio padrao, EP(q condiz com o escore final de cada área) e notaFinal.*/
    }
    fclose(arq);
  // calculo da media
    media[0] = mediaDaArea(qtdAlunos, soma[0]);
    media[1] = mediaDaArea(qtdAlunos, soma[1]);
    media[2] = mediaDaArea(qtdAlunos, soma[2]);
    media[3] = mediaDaArea(qtdAlunos, soma[3]);

    // calculo desvio padrao
    desvio[0] = desvioPadrao( media[0], qtdAlunos, contagem, "v_ling");
    desvio[1] = desvioPadrao( media[1], qtdAlunos, contagem, "v_mat");
    desvio[2] = desvioPadrao( media[2], qtdAlunos, contagem, "v_nat");
    desvio[3] = desvioPadrao( media[3], qtdAlunos, contagem, "v_hum");
    // calculo EP / NF
    eP_NotaFinal(contagem,titulo[], curso[], qtdAlunos, quant, media, desvio); //estarão guardados em acertos_Notas
}
 



while(opcao!=5){
       menu();
       printf("Digite a opção desejada:");
       scanf("%d", &opcao);     
} 




    
return 0;
}  
  
















    
    
