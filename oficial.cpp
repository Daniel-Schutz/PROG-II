#include <stdio.h>
#include <stdlib.h>  // malloc, calloc
#include "funcoes.h"



int main(){
tipoCurso *curso; //tipocurso
int opcao;//o~ção que a pessoa irá digitar no menu
int quant; // quantidade total de cursos
int qtdAlunos; // quantidade total de candidatos
float media[4]; // ling / mat / nat / hum
float desvio[4]; // ling / mat / nat / hum
int soma[4]; // ling / mat / nat / hum
char nomeArq[MAX]; //nome do arquivo que será lido
int indiceTipoCurso; //variavel para achar a posição que o codigo está no struct Curso
int codTemporario;//variavel para salvar temporariamente o codigo do curso
int qtdTemporaria;//variavel para salvar temporariamente a quantidade de alunos do curso


while (opcao!=0){
  printf("0 - Carregar os arquivos de entrada\n");
  printf("Digite a opcao desejada:");
  scanf("%d", &opcao);  
  }

if (opcao==0){
printf("\nEscreva o nome do arquivo dos cursos e pesos:");
scanf("%s",nomeArq);
 FILE*  arq;         /* variavel para acessar um arquivo */

    /*abertura de um arquivo*/
    arq = fopen(nomeArq, "r");
    
    /* verificando se arquivo foi aberto */
    if( arq == NULL )
    {
        printf("\n\n Arquivo %s nao pode ser aberto.\n\n", nomeArq);
    }
    else
    {

        fscanf(arq, "%d", &quant);

        curso = (tipoCurso *) malloc(quant * sizeof(tipoCurso));

         if (curso != NULL){

             for(int i=0;i<quant;i++){
             fscanf(arq, "%d %[^0^1^2^3^4^5^6^7^8^9] %d %d %d %d %d", &curso[i].codCurso, curso[i].nomeCurso, &curso[i].pesoRed, &curso[i].pesoMat, &curso[i].pesoLing, &curso[i].pesoHum, &curso[i].pesoNat);
                }
            
         } else{
            printf("Impossível alocar espaço\n");
         }


        
        /*fechamento do arquivo*/
        fclose(arq);
        
    }

    mergesortTipoCurso(0,quant,curso);//ordena por codigo
    /*TESTE*/
    for(int i=0;i<quant;i++){
             printf("%d %s %d %d %d %d %d\n", curso[i].codCurso, curso[i].nomeCurso, curso[i].pesoRed, curso[i].pesoMat, curso[i].pesoLing, curso[i].pesoHum, curso[i].pesoNat);
                }
    /*FIM DO TESTE*/            




//ler e armazenar cursos e vagas
printf("\nEscreva o nome do arquivo dos cursos e vagas:");
scanf("%s",nomeArq);
    
    /*abertura de um arquivo*/
    arq = fopen(nomeArq, "r");
    
    /* verificando se arquivo foi aberto */
    if( arq == NULL )
    {
        printf("\n\n Arquivo %s nao pode ser aberto.\n\n", nomeArq);
    }
    else
    {
        fscanf(arq, "%d", &quant);
             for(int i=0;i<quant;i++){
             fscanf(arq, "%d", &codTemporario);  
             indiceTipoCurso = busca_binariaTipoCurso(quant, curso, codTemporario);
              fscanf(arq, "%d %d %d %d %d %d %d %d %d %d %d", &curso[indiceTipoCurso].AC, &curso[indiceTipoCurso].L1, &curso[indiceTipoCurso].L3, &curso[indiceTipoCurso].L4, &curso[indiceTipoCurso].L5, &curso[indiceTipoCurso].L7,
              &curso[indiceTipoCurso].L8, &curso[indiceTipoCurso].L9, &curso[indiceTipoCurso].L11, &curso[indiceTipoCurso].L13, &curso[indiceTipoCurso].L15); 
             
         }
       
        
        /*fechamento do arquivo*/     
        fclose(arq);
        
    }
   
   /*TESTE*/
   for(int indiceTipoCurso=0;indiceTipoCurso<quant;indiceTipoCurso++){
     printf("%d %d %d %d %d %d %d %d %d %d %d\n", curso[indiceTipoCurso].AC, curso[indiceTipoCurso].L1, curso[indiceTipoCurso].L3, curso[indiceTipoCurso].L4, curso[indiceTipoCurso].L5, curso[indiceTipoCurso].L7,
              curso[indiceTipoCurso].L8, curso[indiceTipoCurso].L9, curso[indiceTipoCurso].L11, curso[indiceTipoCurso].L13, curso[indiceTipoCurso].L15); 
   /*FIM DO TESTE*/          
   }


/*-------------------------------------------------------------ATÉ AQUI TÁ CERTO----------------------------------------------------------------------------------------*/


//VERIFICAR SE TA CERTO PODER REPETIR O COD CURSO< AI VAI TER QUE CRIAR UM STRUCT AUXILIAR PRA SALVAR NESSES CASOS
//ler e armazenar os dados dos inscritos
printf("\nEscreva o nome do arquivo dos dados dos inscritos:");
scanf("%s",nomeArq);

    //abertura do arquivo
    arq = fopen(nomeArq,"r");

    if (arq == NULL){
        printf("\n\nO arquivo %s não pode ser aberto\n\n",nomeArq);
    }


    //executar leitura do arquivo
    else{    


            for (int i=0;i<quant;i++){ //ler até acabar o arquivo

                fscanf(arq, " %d %d", &codTemporario, &qtdTemporaria); // a primeira linha tem duas entradas
            
                curso[i].qtd = qtdTemporaria; //quantidade de inscritos no curso

                //alocar memória pra cada bloco            
                curso[i].tuplas = (dadoEmLinhas *) malloc (curso[i].qtd * sizeof(dadoEmLinhas)); //aloca dinâmicamente as linhas diretamente no tipoCurso


                //verificar se alocou
                if (curso[i].tuplas == NULL){
                    printf("Não foi possível alocar na memória");
                    break;
                }


                else{
                    //executar a leitura dos dados de forma correta para cada bloco;
                    for (int x=0; x < curso[i].qtd; x++){
                        fscanf(arq, "%d %[^0^1^2^3^4^5^6^7^8^9] %d/%d/%d %[^\n] ", &curso[i].tuplas[x].codinscricao, curso[i].tuplas[x].nomecandidato, &curso[i].tuplas[x].datanasc.dia, &curso[i].tuplas[x].datanasc.mes, &curso[i].tuplas[x].datanasc.ano, curso[i].tuplas[x].tipovaga);
                    }
                /*TESTE*/
                for (int x=0; x < curso[i].qtd; x++){    
                printf("%d %s %d/%d/%d %s\n",curso[i].tuplas[x].codinscricao, curso[i].tuplas[x].nomecandidato, curso[i].tuplas[x].datanasc.dia, curso[i].tuplas[x].datanasc.mes, curso[i].tuplas[x].datanasc.ano, curso[i].tuplas[x].tipovaga);
                    }
                /*FIM DO TESTE*/    
                }
                
            
        }
        fclose(arq);
    }
 






printf("\nEscreva o nome do arquivo dos acertos dos inscritos:");
scanf("%s",nomeArq);


    acertos_notas *contagem; //registro a ser alocado dinâmicamente
    
    //
    arq = fopen(nomeArq,"r"); //abrindo arquivo;
    

    if (arq ==NULL){
        printf("\n\nO arquivo %s não pode ser aberto\n\n",nomeArq);
    }


    else{
        //fazer alocação dinâmica e leitura das entradas
        
        fscanf(arq, "%d", &qtdAlunos); //guarda a quantidade de alunos;
        
        contagem = (acertos_notas*) malloc(qtdAlunos*sizeof(acertos_notas)); //alocação
        
        for (int i = 0; i < qtdAlunos; i++){
            fscanf(arq, "%d %d %d %d %d %f", &contagem[i].insc, &contagem[i].v_ling, &contagem[i].v_mat, &contagem[i].v_nat, &contagem[i].v_hum, &contagem[i].red); //leitura dos dados
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
    }
    fclose(arq);
    /*TESTE*/for (int i = 0; i < qtdAlunos; i++){
            printf("%d %d %d %d %d %.2f\n", contagem[i].insc, contagem[i].v_ling, contagem[i].v_mat, contagem[i].v_nat, contagem[i].v_hum, contagem[i].red); }
    /*FIM DO TESTE*/

  // calculo da media multiplicando por 2 para dar o EP correto
    media[0] = 2* mediaDaArea(qtdAlunos, soma[0]);//media da area Linguagens
    media[1] = 2* mediaDaArea(qtdAlunos, soma[1]);//media da area matemática
    media[2] = 2* mediaDaArea(qtdAlunos, soma[2]);//media da area naturezas
    media[3] = 2* mediaDaArea(qtdAlunos, soma[3]);//media da area humanas

    // calculo desvio padrao, divide a media por 2 para passar a media correta e multiplca o DP para dar o EP correto
    desvio[0] = 2*desvioPadrao( media[0]/2, qtdAlunos, contagem, 0);
    desvio[1] = 2*desvioPadrao( media[1]/2, qtdAlunos, contagem, 1);
    desvio[2] = 2*desvioPadrao( media[2]/2, qtdAlunos, contagem, 2);
    desvio[3] = 2*desvioPadrao( media[3]/2, qtdAlunos, contagem, 3);
    
    printf("a soma das notas de linguagens e %d e qtd de aluno s e %d\n",soma[0],qtdAlunos);
    printf("A media de linguagens e %.2f e o desvio padrao e %.2f",media[0],desvio[0]);

    // calculo EP / NF
    //eP_NotaFinal(contagem, curso, qtdAlunos, quant, media, desvio); //estarão guardados em acertos_Notas
}
 



/*do{
    
       menu();
       printf("Digite a opção desejada:");
       scanf("%d", &opcao);

        if (opcao==1){

        }

        else if (opcao == 2){
            int codinscr;
            printf("\nInforme o número de inscrição do candidato: \n")
            scanf("%d", &codinscr);
            if (codinscr == 0)
            {
                continue;
                //para sair e consultar o menu novamente
            }
            else
            {
                buscaImprimeCandidato( quant, curso, codinscr);
                // A função do tipo void deve buscar e ja imprimir diretamente as informações requeridas
            }
            

        }

        else if (opcao == 3){

        }

        else{

        }

}while(opcao!=5)

*/


    
return 0;
}  
 
    
