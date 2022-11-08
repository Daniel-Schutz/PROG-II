#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funcoes.h"



int main(){
tipoCurso *curso; //tipocurso
acertos_notas *contagem;
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
  printf("\n0 - Carregar os arquivos de entrada\n");
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
             fscanf(arq, "%d %[^0-9] %d %d %d %d %d", &curso[i].codCurso, curso[i].nomeCurso, &curso[i].pesoRed, &curso[i].pesoMat, &curso[i].pesoLing, &curso[i].pesoHum, &curso[i].pesoNat);
                }
            
         } else{
            printf("Impossível alocar espaço\n");
         }


        
        /*fechamento do arquivo*/
        fclose(arq);
        
    }

    mergesortTipoCurso(0,quant,curso);//ordena por codigo
    /*TESTE
    for(int i=0;i<quant;i++){
             printf("%d %s %d %d %d %d %d\n", curso[i].codCurso, curso[i].nomeCurso, curso[i].pesoRed, curso[i].pesoMat, curso[i].pesoLing, curso[i].pesoHum, curso[i].pesoNat);
                }
    FIM DO TESTE*/            




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
   
   /*TESTE
   for(int indiceTipoCurso=0;indiceTipoCurso<quant;indiceTipoCurso++){
     printf("%d %d %d %d %d %d %d %d %d %d %d\n", curso[indiceTipoCurso].AC, curso[indiceTipoCurso].L1, curso[indiceTipoCurso].L3, curso[indiceTipoCurso].L4, curso[indiceTipoCurso].L5, curso[indiceTipoCurso].L7,
              curso[indiceTipoCurso].L8, curso[indiceTipoCurso].L9, curso[indiceTipoCurso].L11, curso[indiceTipoCurso].L13, curso[indiceTipoCurso].L15);  }
   FIM DO TESTE*/          
  


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

                int index = busca_binariaTipoCurso(quant,curso,codTemporario);

                if(curso[index].qtd = 0){

                curso[index].qtd = qtdTemporaria; //quantidade de inscritos no curso

                //alocar memória pra cada bloco            
                curso[index].tuplas = (dadoEmLinhas *) malloc (curso[index].qtd * sizeof(dadoEmLinhas)); //aloca dinâmicamente as linhas diretamente no tipoCurso


                //verificar se alocou
                if (curso[index].tuplas == NULL){
                    printf("Não foi possível alocar na memória");
                    break;
                }


                else{
                    //executar a leitura dos dados de forma correta para cada bloco;
                    for (int x=0; x < curso[index].qtd; x++){
                        fscanf(arq, "%d %[^0-9] %d/%d/%d %[^\n] ", &curso[index].tuplas[x].codinscricao, curso[index].tuplas[x].nomecandidato, &curso[index].tuplas[x].datanasc.dia, &curso[index].tuplas[x].datanasc.mes, &curso[index].tuplas[x].datanasc.ano, curso[index].tuplas[x].tipovaga);
                    }
                /*TESTE
                for (int x=0; x < curso[index].qtd; x++){    
                printf("%d %s %d/%d/%d %s\n",curso[index].tuplas[x].codinscricao, curso[index].tuplas[x].nomecandidato, curso[index].tuplas[x].datanasc.dia, curso[index].tuplas[x].datanasc.mes, curso[index].tuplas[x].datanasc.ano, curso[index].tuplas[x].tipovaga);
                    }
                FIM DO TESTE*/    
                }

                } else /*se ja tem quantidade !=0*/{

                    dadoEmLinhas *tuplasAuxiliar;
                    tuplasAuxiliar = (dadoEmLinhas *) malloc (curso[index].qtd * sizeof(dadoEmLinhas));
                    for(int x=0;i<curso[index].qtd ;x++){
                        tuplasAuxiliar[x] = curso[index].tuplas[x];
                    }
                    curso[index].qtd = curso[index].qtd + qtdTemporaria;
                    curso[index].tuplas = (dadoEmLinhas *) malloc (curso[index].qtd * sizeof(dadoEmLinhas)); //aloca dinâmicamente as linhas diretamente no tipoCurso
                    for(int x=0;x<curso[index].qtd - qtdTemporaria;i++){
                        curso[index].tuplas[i]=tuplasAuxiliar[i]; 
                    }
                    free(tuplasAuxiliar);
                    for(int x=curso[index].qtd - qtdTemporaria; x<curso[index].qtd;x++){
                        fscanf(arq, "%d %[^0-9] %d/%d/%d %[^\n] ", &curso[index].tuplas[x].codinscricao, curso[index].tuplas[x].nomecandidato, &curso[index].tuplas[x].datanasc.dia, &curso[index].tuplas[x].datanasc.mes, &curso[index].tuplas[x].datanasc.ano, curso[index].tuplas[x].tipovaga);
                    }


                }
                
                
            
        }
        fclose(arq);
    }
 






printf("\nEscreva o nome do arquivo dos acertos dos inscritos:");
scanf("%s",nomeArq);
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
    /*TESTEfor (int i = 0; i < qtdAlunos; i++){
            printf("%d %d %d %d %d %.2f\n", contagem[i].insc, contagem[i].v_ling, contagem[i].v_mat, contagem[i].v_nat, contagem[i].v_hum, contagem[i].red); }
    FIM DO TESTE*/
    
} 

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
    printf("A media de linguagens e %.2f e o desvio padrao e %.2f\n",media[0],desvio[0]);
    
    // calculo EP / NF
    eP_NotaFinal(contagem, curso, qtdAlunos, quant, media, desvio); //função que calcula EP e Nota Final
    
 /*TESTE
    for(int i=0;i<qtdAlunos;i++){
        if (contagem[i].insc == 554840){
            printf("ep de ling: %f  ep de mat: %f  ep de nat: %f  ep de hum: %f\n",contagem[i].EP[0],contagem[i].EP[1],contagem[i].EP[2],contagem[i].EP[3]);
            printf("Acertos dele em ling %d  em mat %d  em nat %d em hum %d\n",contagem[i].v_ling,contagem[i].v_mat,contagem[i].v_nat,contagem[i].v_hum);
            printf("%f",contagem[i].notaFinal);

        }
    }
    FIM DO TESTE*/

    mergesortAlfabetica(0,quant,curso);//para ordenar os cursos por ordem alfabetica
    printf("\nnome do segundo curso %s\n",curso[1].nomeCurso);
    for(int i=0;i<curso[1].qtd;i++){
        printf("nome do aluno %s e tipo de vaga e %s\n",curso[1].tuplas[i].nomecandidato,curso[1].tuplas[i].tipovaga);
    }
    for(int i=0;i<quant;i++){
        mergesortVaga(0,curso[i].qtd,curso[i]);//ordena os candidatos dentro do curso pelo tipo da vaga
    }
    
    for(int i=0;i<quant;i++){
        mergesortNota(0,curso[i].qtd,curso[i]);//ordena os candidatos dentro do curso pela nota
   
   
    /*TESTE
    printf("\nnome do primeiro curso %s\n",curso[0].nomeCurso);
    for(int i=0;i<curso[0].qtd;i++){
        printf("nome do aluno %s e tipo de vaga e %s\n",curso[0].tuplas[i].nomecandidato,curso[0].tuplas[i].tipovaga);
    }
    FIM DO TESTE*/


while(true){
    
       menu();
       printf("Digite a opção desejada:");
       scanf("%d", &opcao);

        if (opcao==1){
            

        }

        else if (opcao == 2){
            int codinscr;
            printf("\nInforme o número de inscrição do candidato ou digite 0 para retornar ao menu: \n");
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

        /*else if (opcao == 3){
            FILE*  arqsaida;    variavel para manip arquivo de saida
            arqsaida = fopen("saidaNaoAprovados.txt", "a");
            fprintf(arqsaida, "Não Aprovados\n");
            naoAprovados(quant,curso);
            
    } */

            
        

        else if (opcao == 4){ //troquei o else por 4 para minimizar chances de erro caso ponha qualquer outro numero, seria estranho apertar 6 e alterar as notas de red
            mergesortAcertos(0, qtdAlunos, contagem); //ordena o struct Acerto_notas para ficar mais facil a busca pelo insc

            printf("\nDigite o nome do arquivo que contém as novas notas: \n");
            scanf("%s", nomeArq);
            FILE *file;
            int numalteracoes; //para ler o arquivo
            float novanota;
            float notaantiga;
            int inscricaoalterar;
            int indicecodinsc; //indice do vetor de registro struct pra alterar
            file = fopen(nomeArq, "r");
            if (file == NULL){
                printf("\n Não foi possível abrir o arquivo das notas de Redação, tente novamente.\n");
            }
            else{
                fscanf(file,"%d", &numalteracoes);
                int i = 0;
                while (i < numalteracoes){ //ler todo o arquivo e alterar enquanto lê
                    fscanf(file, "%d %f %f", &inscricaoalterar, &notaantiga, &novanota ); //leitura
                    indicecodinsc = busca_binariaAcertos(qtdAlunos, contagem, inscricaoalterar); //busca
                    // poderia se fazer uma checagem if (notaantiga == contagem[indicecodinsc].red) para dps realizar a troca
                    // porém, não achei necessário, uma vez que ja temos o indice
                    contagem[indicecodinsc].red = novanota; //alteração

                    //checar
                    printf("\n O aluno de %d que tinha a nota %0.f agr tem a nota %0.f", contagem[indicecodinsc].insc, notaantiga, contagem[indicecodinsc].red); //insc referente ao struct pra comparar com o arquivo se está tudo certo, notaantiga pois a alteração ja foi feita então não teria como chamar o struct ponto nota, e por fim o ultimo referente a nota atualizada.
                    //checado
                    i++;
                }
            }
            fclose(file);
        }

        else if (opcao == 5){
            break;
        }

        else{ //Adicionei para caso digite qualquer outro número e ter pelo menos uma explicação do erro
            printf("\n você digitou uma opção inexistente, por favor, tente novamente!\n");
        }



}

    
return 0;
} 
 
    
