#include "funcoes.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  tipoCurso *curso;    // tipocurso
  int opcao;           // opção que a pessoa irá digitar no menu
  int quant;           // quantidade total de cursos
  int qtdAlunos;       // quantidade total de candidatos que fizeram a prova
  float media[4];      // ling / mat / nat / hum
  float desvio[4];     // ling / mat / nat / hum
  int soma[4];         // ling / mat / nat / hum
  char nomeArq[MAX];   // nome do arquivo que será lido
  int indiceTipoCurso; // variavel para achar a posição que o codigo está no
  int codTemporario;   // variavel para salvar temporariamente o codigo do curso
  int qtdTemporaria;   // variavel para salvar temporariamente a quantidade de
  int totalParticipantes = 0; // numero de candidatos inscritos

  while (opcao != 0) {
    printf("\n0 - Carregar os arquivos de entrada\n");
    printf("Digite a opcao desejada:");
    scanf("%d", &opcao);
  }

  if (opcao == 0) {
    printf("\nEscreva o nome do arquivo dos cursos e pesos:");
    scanf("%s", nomeArq);
    FILE *arq; /* variavel para acessar um arquivo */

    /*abertura de um arquivo*/
    arq = fopen(nomeArq, "r");

    /* verificando se arquivo foi aberto */
    if (arq == NULL) {
      printf("\n\n Arquivo %s nao pode ser aberto.\n\n", nomeArq);
    } else {

      fscanf(arq, "%d", &quant);

      curso = (tipoCurso *)malloc(quant * sizeof(tipoCurso));

      if (curso != NULL) {

        for (int i = 0; i < quant; i++) {
          fscanf(arq, "%d %[^0-9] %d %d %d %d %d", &curso[i].codCurso, curso[i].nomeCurso, &curso[i].pesoRed, &curso[i].pesoMat, &curso[i].pesoLing, &curso[i].pesoHum, &curso[i].pesoNat);
        }

      } else {
        printf("Impossível alocar espaço\n");
      }

      /*fechamento do arquivo*/
      fclose(arq);
    }

    mergesortTipoCurso(0, quant, curso); // ordena por codigo

    /*TESTE
    for(int i=0;i<quant;i++){
             printf("%d %s %d %d %d %d %d\n", curso[i].codCurso,
    curso[i].nomeCurso, curso[i].pesoRed, curso[i].pesoMat, curso[i].pesoLing,
    curso[i].pesoHum, curso[i].pesoNat);
                }
    FIM DO TESTE*/

    // ler e armazenar cursos e vagas
    printf("\nEscreva o nome do arquivo dos cursos e vagas:");
    scanf("%s", nomeArq);

    /*abertura de um arquivo*/
    arq = fopen(nomeArq, "r");

    /* verificando se arquivo foi aberto */
    if (arq == NULL) {
      printf("\n\n Arquivo %s nao pode ser aberto.\n\n", nomeArq);
    } else {
      fscanf(arq, "%d", &quant);
      for (int i = 0; i < quant; i++) {
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
      printf("%d %d %d %d %d %d %d %d %d %d %d
    %d\n",curso[indiceTipoCurso].codCurso, curso[indiceTipoCurso].AC,
    curso[indiceTipoCurso].L1, curso[indiceTipoCurso].L3,
    curso[indiceTipoCurso].L4, curso[indiceTipoCurso].L5,
    curso[indiceTipoCurso].L7, curso[indiceTipoCurso].L8,
    curso[indiceTipoCurso].L9, curso[indiceTipoCurso].L11,
    curso[indiceTipoCurso].L13, curso[indiceTipoCurso].L15);  } FIM DO TESTE*/

    // ler e armazenar os dados dos inscritos
    printf("\nEscreva o nome do arquivo dos dados dos inscritos:");
    scanf("%s", nomeArq);

    // abertura do arquivo
    arq = fopen(nomeArq, "r");

    if (arq == NULL) {
      printf("\n\nO arquivo %s não pode ser aberto\n\n", nomeArq);
    }

    // executar leitura do arquivo
    else {

      while ((fscanf(arq, "%d", &codTemporario)) !=
             EOF) { // ler até acabar o arquivo

        fscanf(arq, "%d", &qtdTemporaria); // a primeira linha tem duas entradas

        int index = busca_binariaTipoCurso(quant, curso, codTemporario);

        if (curso[index].qtd == 0) {
          curso[index].qtd = qtdTemporaria;
          curso[index].aluno = (tipoAluno *)malloc(curso[index].qtd * sizeof(tipoAluno));
          // verificar se alocou
          if (curso[index].aluno == NULL) {
            printf("Não foi possível alocar na memória");
            break;
          }

          else {
            // executar a leitura dos dados de forma correta para cada bloco;
            for (int x = 0; x < curso[index].qtd; x++) {
              fscanf(arq, "%d %[^0-9] %d/%d/%d %s", &curso[index].aluno[x].codinscricao, curso[index].aluno[x].nomecandidato, &curso[index].aluno[x].datanasc.dia, &curso[index].aluno[x].datanasc.mes,
                     &curso[index].aluno[x].datanasc.ano, curso[index].aluno[x].tipovaga);
              curso[index].aluno[x].presente = false;
               if(strcmp(curso[index].aluno[x].tipovaga,"AC")==0){
                            curso[index].quantAC+=1;
                        }
                        else if(strcmp(curso[index].aluno[x].tipovaga,"L1")==0){
                            curso[index].quantL1+=1;
                        }
                        else if(strcmp(curso[index].aluno[x].tipovaga,"L3")==0){
                            curso[index].quantL3+=1;
                        }
                        else if(strcmp(curso[index].aluno[x].tipovaga,"L4")==0){
                            curso[index].quantL4+=1;
                        }
                        else if(strcmp(curso[index].aluno[x].tipovaga,"L5")==0){
                            curso[index].quantL5+=1;
                        }
                        else if(strcmp(curso[index].aluno[x].tipovaga,"L7")==0){
                            curso[index].quantL7+=1;
                        }
                        else if(strcmp(curso[index].aluno[x].tipovaga,"L8")==0){
                            curso[index].quantL8+=1;
                        }
                        else if(strcmp(curso[index].aluno[x].tipovaga,"L9")==0){
                            curso[index].quantL9+=1;
                        }
                        else if(strcmp(curso[index].aluno[x].tipovaga,"L11")==0){
                            curso[index].quantL11+=1;
                        }
                        else if(strcmp(curso[index].aluno[x].tipovaga,"L13")==0){
                            curso[index].quantL13+=1;
                        }
                        else if(strcmp(curso[index].aluno[x].tipovaga,"L15")==0){
                            curso[index].quantL15+=1;
                        }
            }
          }
        }

        else {

          tipoAluno *alunoAuxiliar;

          alunoAuxiliar = (tipoAluno *)malloc(curso[index].qtd * sizeof(tipoAluno));

          for (int x = 0; x < curso[index].qtd; x++) {
            alunoAuxiliar[x] = curso[index].aluno[x];
          }
          curso[index].qtd = curso[index].qtd + qtdTemporaria;
          curso[index].aluno = (tipoAluno *)malloc(
              curso[index].qtd *
              sizeof(tipoAluno)); // aloca dinâmicamente as linhas diretamente
          for (int x = 0; x < curso[index].qtd - qtdTemporaria; x++) {
            curso[index].aluno[x] = alunoAuxiliar[x];
          }
          free(alunoAuxiliar);
          for (int x = curso[index].qtd - qtdTemporaria; x < curso[index].qtd;
               x++) {
            fscanf(arq, "%d %[^0-9] %d/%d/%d %s",
                   &curso[index].aluno[x].codinscricao,
                   curso[index].aluno[x].nomecandidato,
                   &curso[index].aluno[x].datanasc.dia,
                   &curso[index].aluno[x].datanasc.mes,
                   &curso[index].aluno[x].datanasc.ano,
                   curso[index].aluno[x].tipovaga);
            curso[index].aluno[x].presente = false;
             if(strcmp(curso[index].aluno[x].tipovaga,"AC")==0){
                            curso[index].quantAC+=1;
                        }
                        else if(strcmp(curso[index].aluno[x].tipovaga,"L1")==0){
                            curso[index].quantL1+=1;
                        }
                        else if(strcmp(curso[index].aluno[x].tipovaga,"L3")==0){
                            curso[index].quantL3+=1;
                        }
                        else if(strcmp(curso[index].aluno[x].tipovaga,"L4")==0){
                            curso[index].quantL4+=1;
                        }
                        else if(strcmp(curso[index].aluno[x].tipovaga,"L5")==0){
                            curso[index].quantL5+=1;
                        }
                        else if(strcmp(curso[index].aluno[x].tipovaga,"L7")==0){
                            curso[index].quantL7+=1;
                        }
                        else if(strcmp(curso[index].aluno[x].tipovaga,"L8")==0){
                            curso[index].quantL8+=1;
                        }
                        else if(strcmp(curso[index].aluno[x].tipovaga,"L9")==0){
                            curso[index].quantL9+=1;
                        }
                        else if(strcmp(curso[index].aluno[x].tipovaga,"L11")==0){
                            curso[index].quantL11+=1;
                        }
                        else if(strcmp(curso[index].aluno[x].tipovaga,"L13")==0){
                            curso[index].quantL13+=1;
                        }
                        else if(strcmp(curso[index].aluno[x].tipovaga,"L15")==0){
                            curso[index].quantL15+=1;
                        }
          }
        }
      }

      fclose(arq);
    }

    for (int i = 0; i < quant; i++) {
      mergesortTipoAluno(
          0, curso[i].qtd,
          curso[i].aluno); // ordena dentro de cada curso por codInscrição
    }

    printf("\nEscreva o nome do arquivo dos acertos dos inscritos:");
    scanf("%s", nomeArq);

    arq = fopen(nomeArq, "r"); // abrindo arquivo;

    if (arq == NULL) {
      printf("\n\nO arquivo %s não pode ser aberto\n\n", nomeArq);
    }

    else {
      // fazer alocação dinâmica e leitura das entradas

      fscanf(arq, "%d", &qtdAlunos); // guarda a quantidade de alunos;
      int inscTemporaria;            // cod insc temporario
      int i, j;

      for (int x = 0; x < qtdAlunos; x++) {
        fscanf(arq, "%d", &inscTemporaria);

        for (j = 0; j < quant; j++) {
          i = busca_binariaAcertos(curso[j].qtd, curso[j].aluno,
                                   inscTemporaria);
          if (curso[j].aluno[i].codinscricao == inscTemporaria) {

            break;
          }
        }

        fscanf(arq, "%d %d %d %d %f", &curso[j].aluno[i].v_ling, &curso[j].aluno[i].v_mat, &curso[j].aluno[i].v_nat,&curso[j].aluno[i].v_hum,&curso[j].aluno[i].red); // leitura dos dados
        curso[j].aluno[i].presente = true;

        // printf("%d %d %d %d %d %f\n",curso[j].aluno[i].codinscricao,
        // curso[j].aluno[i].v_ling, curso[j].aluno[i].v_mat,
        // curso[j].aluno[i].v_nat, curso[j].aluno[i].v_hum,
        // curso[j].aluno[i].red);
        if (x == 0) {
          soma[0] = curso[j].aluno[i].v_ling;
          soma[1] = curso[j].aluno[i].v_mat;
          soma[2] = curso[j].aluno[i].v_nat;
          soma[3] = curso[j].aluno[i].v_hum;
        } else {
          soma[0] = soma[0] + curso[j].aluno[i].v_ling;
          soma[1] = soma[1] + curso[j].aluno[i].v_mat;
          soma[2] = soma[2] + curso[j].aluno[i].v_nat;
          soma[3] = soma[3] + curso[j].aluno[i].v_hum;
        }
      }

      fclose(arq);
    }
  }

  // printf("A soma de linguagens e %d",soma[0]);

  // calculo da media multiplicando por 2 para dar o EP correto
  media[0] = 2 * mediaDaArea(qtdAlunos, soma[0]); // media da area Linguagens
  media[1] = 2 * mediaDaArea(qtdAlunos, soma[1]); // media da area matemática
  media[2] = 2 * mediaDaArea(qtdAlunos, soma[2]); // media da area naturezas
  media[3] = 2 * mediaDaArea(qtdAlunos, soma[3]); // media da area humanas

  // calculo desvio padrao, divide a media por 2 para passar a media correta e
  // multiplca o DP para dar o EP correto
  desvio[0] = 2 * desvioPadrao(media[0] / 2, quant, curso, 0, qtdAlunos);
  desvio[1] = 2 * desvioPadrao(media[1] / 2, quant, curso, 1, qtdAlunos);
  desvio[2] = 2 * desvioPadrao(media[2] / 2, quant, curso, 2, qtdAlunos);
  desvio[3] = 2 * desvioPadrao(media[3] / 2, quant, curso, 3, qtdAlunos);

  printf("a soma das notas de linguagens e %d e qtd de alunos e %d\n", soma[0],
         qtdAlunos);
  printf("A media de linguagens e %.2f e o desvio padrao e %.2f\n", media[0],
         desvio[0]);

  /*-------------------------------------------ATE AQUI TA
   * CERTO-------------------------------------------------------------------------------------------------------------------*/

  // calculo EP / NF
  eP_NotaFinal(curso, quant, media, desvio); // função que calcula EP e Nota Final



 
     mergesortAlfabetica(0,quant,curso);//para ordenar os cursos por ordem  alfabetica 

     for(int i=0;i<quant;i++){
         mergesortVaga(0,curso[i].qtd,curso[i]);//ordena os candidatos dentro do curso pelo tipo da vaga
     }
     

   
      /*
     printf("\nnome do segundo curso %s\n",curso[1].nomeCurso); for(int
  i=0;i<curso[1].qtd;i++){ printf("nome do aluno %s e tipo de vaga e
  %s\n",curso[1].aluno[i].nomecandidato,curso[1].aluno[i].tipovaga);
     } */
     
 

   while(true){

         menu();
         printf("\nDigite a opção desejada:");
         scanf("%d", &opcao);

          if (opcao==1){
            listaParticipantes(quant,curso);


          }

         else if (opcao == 2){
              int codinscr;
              printf("\nInforme o número de inscrição do candidato ou digite 0 para retornar ao menu: \n"); scanf("%d", &codinscr); 
              if (codinscr == 0)
              {
                  continue;
                  //para sair e consultar o menu novamente
              }
              else
              {
                  buscaImprimeCandidato( quant, curso, codinscr);
              }


          }
 
          else if (opcao == 3){
              naoAprovados(quant,curso);

      }




          else if (opcao == 4){
           printf("\nEscreva o nome do arquivo dos acertos dos inscritos:");
    scanf("%s", nomeArq);

    arq = fopen(nomeArq, "r"); // abrindo arquivo;

    if (arq == NULL) {
      printf("\n\nO arquivo %s não pode ser aberto\n\n", nomeArq);
    }

    else {
          int numAlteracoes, codInsc,y;
          float notaAntiga, notaNova;
                  fscanf(arq,"%d", &numAlteracoes);
          for(int i=0;i<numAlteracoes;i++){
            fscanf(arq, "%d %f %f", &codInsc, &notaAntiga, &notaNova);
            for(int x=0;x<quant;x++){
                y = busca_binariaAcertos(curso[x].qtd,curso[x].aluno,codInsc);
                if(curso[x].aluno[y].codinscricao==codInsc){
                  curso[x].aluno[y].red = notaNova;
                   curso[x].aluno[y].notaFinal = (curso[x].aluno[y].red * curso[x].pesoRed + curso[x].aluno[y].EP[3] * curso[x].pesoHum + curso[x].aluno[y].EP[0] * curso[x].pesoLing +
            curso[x].aluno[y].EP[1] * curso[x].pesoMat + curso[x].aluno[y].EP[2] * curso[x].pesoNat)/(curso[x].pesoRed + curso[x].pesoHum + curso[x].pesoLing +
            curso[x].pesoMat + curso[x].pesoNat);
                  break;
                }
              
            }
            fclose(arq);
          }          
        }
      }

          else if (opcao == 5){
              break;
          }

          else{ 
            printf("\n você digitou uma opção inexistente, por favor, tente novamente!\n");
          }



 
 } 
  return 0;
}



 
    
