#include "funcoes.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desenvolver funcoes
void menu() {
  printf("\n1 - Gerar arquivo de saída .txt");

  printf("\n2 - Pesquisar candidatos .txt");

  printf("\n3 - Gerar arquivo dos candidatos não aprovados");

  printf(
      "\n4 - Alterar nota de redação dos candidatos que entraram com recurso");

  printf("\n5 - Encerrar programa");
}

void intercalaTipoCurso(int p, int q, int r, tipoCurso *v) {
  int i, j, k;
  tipoCurso *w;
  w = (tipoCurso *)malloc(r * sizeof(tipoCurso));

  i = p;
  j = q;
  k = 0;
  while (i < q && j < r) {
    if (v[i].codCurso < v[j].codCurso) {
      w[k] = v[i];
      i++;
    } else {
      w[k] = v[j];
      j++;
    }
    k++;
  }
  while (i < q) {
    w[k] = v[i];
    i++;
    k++;
  }
  while (j < r) {
    w[k] = v[j];
    j++;
    k++;
  }
  for (i = p; i < r; i++) {
    v[i] = w[i - p];
  }
  free(w);
}

void mergesortTipoCurso(int p, int r, tipoCurso *v) {
  int q;
  if (p < r - 1) {
    q = (p + r) / 2;
    mergesortTipoCurso(p, q, v);
    mergesortTipoCurso(q, r, v);
    intercalaTipoCurso(p, q, r, v);
  }
}

int busca_binariaTipoCurso(int n, tipoCurso *v, int x) {
  int esq, dir, meio;
  esq = -1;
  dir = n;
  while (esq < dir - 1) {
    meio = (esq + dir) / 2;
    if (v[meio].codCurso < x)
      esq = meio;
    else
      dir = meio;
  }
  return dir;
}

void intercalaTipoAluno(int p, int q, int r, tipoAluno *v) {
  int i, j, k;
  tipoAluno *w;
  w = (tipoAluno *)malloc(r * sizeof(tipoAluno));

  i = p;
  j = q;
  k = 0;
  while (i < q && j < r) {
    if (v[i].codinscricao < v[j].codinscricao) {
      w[k] = v[i];
      i++;
    } else {
      w[k] = v[j];
      j++;
    }
    k++;
  }
  while (i < q) {
    w[k] = v[i];
    i++;
    k++;
  }
  while (j < r) {
    w[k] = v[j];
    j++;
    k++;
  }
  for (i = p; i < r; i++) {
    v[i] = w[i - p];
  }
  free(w);
}

void mergesortTipoAluno(int p, int r, tipoAluno *v) {
  int q;
  if (p < r - 1) {
    q = (p + r) / 2;
    mergesortTipoAluno(p, q, v);
    mergesortTipoAluno(q, r, v);
    intercalaTipoAluno(p, q, r, v);
  }
}

float mediaDaArea(
    float quant,
    float soma) { // passar valor correspondente a soma da materia no parametro

  float media; // variável q será retornada
  media = (soma / quant);
  return media;
}

float desvioPadrao(float media, int quant, tipoCurso *curso, int num,
                   int qtdAlunos) {
  float desvio = 0; // vai ser a variável a ser retornada, porém deve ser
                    // guardada em outra variável na main.
  int i;

  if (num == 0) {
    for (i = 0; i < quant; i++) {
      for (int j = 0; j < curso[i].qtd; j++) {
        if (curso[i].aluno[j].presente == true) {
          desvio = desvio + pow(curso[i].aluno[j].v_ling - media, 2);
        }
      }
    }
  }

  else if (num == 1) {
    for (i = 0; i < quant; i++) {
      for (int j = 0; j < curso[i].qtd; j++) {
        if (curso[i].aluno[j].presente == true) {
          desvio = desvio + pow(curso[i].aluno[j].v_mat - media, 2);
        }
      }
    }
  } else if (num == 2) {
    for (i = 0; i < quant; i++) {
      for (int j = 0; j < curso[i].qtd; j++) {
        if (curso[i].aluno[j].presente == true) {
          desvio = desvio + pow(curso[i].aluno[j].v_nat - media, 2);
        }
      }
    }
  } else if (num == 3) {
    for (i = 0; i < quant; i++) {
      for (int j = 0; j < curso[i].qtd; j++) {
        if (curso[i].aluno[j].presente == true) {
          desvio = desvio + pow(curso[i].aluno[j].v_hum - media, 2);
        }
      }
    }
  }

  desvio = sqrt(desvio / (qtdAlunos - 1)); 
  return desvio;
}

int busca_binariaAcertos(int n, tipoAluno *v, int x) {
  int esq, dir, meio;
  esq = -1;
  dir = n;
  while (esq < dir - 1) {
    meio = (esq + dir) / 2;
    if (v[meio].codinscricao < x)
      esq = meio;
    else
      dir = meio;
  }

  return dir;
}

void eP_NotaFinal(tipoCurso curso[], int quant, float media[], float desvio[]){//quant = quantidade de candidatos int i = 0; int indicecurso;
    int aux;
    int j;
    for(int j=0;j<quant;j++){
      for (int i=0; i < curso[j].qtd; i++){
        if(curso[j].aluno[i].presente==true){
          curso[j].aluno[i].EP[0] = 500 + 100*((2*curso[j].aluno[i].v_ling - media[0])/desvio[0]);
          curso[j].aluno[i].EP[1] = 500 + 100*((2*curso[j].aluno[i].v_mat - media[1])/desvio[1]);
          curso[j].aluno[i].EP[2] = 500 + 100*((2*curso[j].aluno[i].v_nat - media[2])/desvio[2]);
          curso[j].aluno[i].EP[3] = 500 + 100*((2*curso[j].aluno[i].v_hum - media[3])/desvio[3]);

           curso[j].aluno[i].notaFinal = (curso[j].aluno[i].red * curso[j].pesoRed + curso[j].aluno[i].EP[3] * curso[j].pesoHum + curso[j].aluno[i].EP[0] * curso[j].pesoLing +
            curso[j].aluno[i].EP[1] * curso[j].pesoMat + curso[j].aluno[i].EP[2] * curso[j].pesoNat)/(curso[j].pesoRed + curso[j].pesoHum + curso[j].pesoLing +
            curso[j].pesoMat + curso[j].pesoNat); 
        }
      }
    }
}
    

void intercalaAlfabetica(int p, int q, int r, tipoCurso *v){
  int i, j, k;
  tipoCurso *w;
  w = (tipoCurso *) malloc(r * sizeof(tipoCurso));

  i = p; j = q; k = 0;
  while(i < q && j < r) {
    v[i].nomeCurso[0] = toupper(v[i].nomeCurso[0]);
    v[j].nomeCurso[0] = toupper(v[j].nomeCurso[0]);

    if(strcmp(v[i].nomeCurso, v[j].nomeCurso) < 0){
      w[k] = v[i]; i++;
    }
    else{
      w[k] = v[j]; j++;
    }
    k++;
  }
  while(i < q){
    w[k] = v[i]; i++; k++;
    }
  while(j < r){
    w[k] = v[j]; j++; k++;
  }
  for(i = p; i < r; i++) {
    v[i] = w[i - p];
  }
  free(w);
}

void mergesortAlfabetica(int p, int r, tipoCurso *v){
  int q;
  if(p < r - 1){
    q = (p + r) / 2;
    mergesortAlfabetica(p, q, v);
    mergesortAlfabetica(q, r, v);
    intercalaAlfabetica(p, q, r, v);
  }
}    

void intercalaVaga(int p, int q, int r, tipoCurso v){
  int i, j, k;
  tipoAluno *w;
  w = (tipoAluno *) malloc(r * sizeof(tipoAluno));

  i = p; j = q; k = 0;
  while(i < q && j < r) {


    if(strcmp(v.aluno[i].tipovaga, v.aluno[j].tipovaga) < 0){
      w[k] = v.aluno[i]; i++;
    }
    else{
      w[k] = v.aluno[j]; j++;
    }
    k++;
  }
  while(i < q){
    w[k] = v.aluno[i]; i++; k++;
    }
  while(j < r){
    w[k] = v.aluno[j]; j++; k++;
  }
  for(i = p; i < r; i++) {
    v.aluno[i] = w[i - p];
  }
  free(w);
}

void mergesortVaga(int p, int r, tipoCurso v){
  int q;
  if(p < r - 1){
    q = (p + r) / 2;
    mergesortVaga(p, q, v);
    mergesortVaga(q, r, v);
    intercalaVaga(p, q, r, v);
  }
}

void intercalaNota(int p, int q, int r, tipoCurso v){ 
  int i, j, k,x,y; tipoAluno *w; 
  w = (tipoAluno *) malloc(r * sizeof(tipoAluno));

  i = p; j = q; k = 0;
  while(i < q && j < r) {

   if(v.aluno[i].notaFinal < v.aluno[y].notaFinal){ 
  w[k] = v.aluno[i]; i++;
    }
    /*else if(v.aluno[i].notaFinal==v.aluno[y].notaFinal){
      tipoAluno maior;
      maior =  verificaEmpate(v.aluno[i], aluno[x], v.aluno[j], aluno[y]);
      if(maior.codcodinscricaoricao=v.aluno[i].codcodinscricaoricao){
         w[k] = v.aluno[i]; i++;
      } else{
        w[k] = v.aluno[j]; j++;;
      }

    }*/
    else{
      w[k] = v.aluno[j]; j++;
    }
    k++;
  }
  while(i < q){
    w[k] = v.aluno[i]; i++; k++;
    }
  while(j < r){
    w[k] = v.aluno[j]; j++; k++;
  }
  for(i = p; i < r; i++) {
    v.aluno[i] = w[i - p];
  }
  free(w);
}

void mergesortNota(int p, int r, tipoCurso v){
  int q;
  if(p < r - 1){
    q = (p + r) / 2;
    mergesortNota(p, q, v);
    mergesortNota(q, r, v);
    intercalaNota(p, q, r,v);
  }
}

void listaParticipantes(int quant, tipoCurso *curso){
          FILE*  arqsaida;   
          arqsaida = fopen("listaParticipantes.txt", "a");
          fprintf(arqsaida, "/*LISTA GERAL CLASSIFICADO POR NOTA*/\n");
          for(int i=0;i<quant;i++){
             fprintf(arqsaida, "INSC	V_LIN	V_MAT	V_NAT	V_HUM	RED	COTA	NOTA FINAL	CLASSIFICAÇÃO\n");
            int j=0,cont=0;
            tipoAluno *auxiliar;
            auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
            while(strcmp(curso[i].aluno[j].tipovaga,"AC")==0){
              if(curso[i].aluno[j].presente==true){
                  auxiliar[cont]=curso[i].aluno[j];
                  cont++;
                  auxiliar = (tipoAluno*) realloc(auxiliar, cont * sizeof(tipoAluno));
              }
              j++;
            }//termina o while aq
            //ordena auxiliar
              for(int x=0;x<cont;x++){
                 fprintf(arqsaida, "%d %.2f %.2f %.2f %.2f %.2f %s %.2f %d\n",auxiliar[x].codinscricao,auxiliar[x].v_ling,auxiliar[x].v_mat,auxiliar[x].v_nat,auxiliar[x].v_hum,auxiliar[x].red,auxiliar[x].tipovaga,auxiliar[x].notaFinal,x+1);

              }
              free(auxiliar);

               auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
            while(strcmp(curso[i].aluno[j].tipovaga,"L1")==0){
              if(curso[i].aluno[j].presente==true){
                  auxiliar[cont]=curso[i].aluno[j];
                  cont++;
                  auxiliar = (tipoAluno*) realloc(auxiliar, cont * sizeof(tipoAluno));
              }
              j++;
            }//termina o while aq
            //ordena auxiliar
               for(int x=0;x<cont;x++){
                 fprintf(arqsaida, "%d %.2f %.2f %.2f %.2f %.2f %s %.2f %d\n",auxiliar[x].codinscricao,auxiliar[x].v_ling,auxiliar[x].v_mat,auxiliar[x].v_nat,auxiliar[x].v_hum,auxiliar[x].red,auxiliar[x].tipovaga,auxiliar[x].notaFinal,x+1);

              }
              free(auxiliar);

               auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
            while(strcmp(curso[i].aluno[j].tipovaga,"L3")==0){
              if(curso[i].aluno[j].presente==true){
                  auxiliar[cont]=curso[i].aluno[j];
                  cont++;
                  auxiliar = (tipoAluno*) realloc(auxiliar, cont * sizeof(tipoAluno));
              }
              j++;
            }//termina o while aq
            //ordena auxiliar
               for(int x=0;x<cont;x++){
                 fprintf(arqsaida, "%d %.2f %.2f %.2f %.2f %.2f %s %.2f %d\n",auxiliar[x].codinscricao,auxiliar[x].v_ling,auxiliar[x].v_mat,auxiliar[x].v_nat,auxiliar[x].v_hum,auxiliar[x].red,auxiliar[x].tipovaga,auxiliar[x].notaFinal,x+1);

              }
              free(auxiliar);

               auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
            while(strcmp(curso[i].aluno[j].tipovaga,"L4")==0){
              if(curso[i].aluno[j].presente==true){
                  auxiliar[cont]=curso[i].aluno[j];
                  cont++;
                  auxiliar = (tipoAluno*) realloc(auxiliar, cont * sizeof(tipoAluno));
              }
              j++;
            }//termina o while aq
            //ordena auxiliar
               for(int x=0;x<cont;x++){
                 fprintf(arqsaida, "%d %.2f %.2f %.2f %.2f %.2f %s %.2f %d\n",auxiliar[x].codinscricao,auxiliar[x].v_ling,auxiliar[x].v_mat,auxiliar[x].v_nat,auxiliar[x].v_hum,auxiliar[x].red,auxiliar[x].tipovaga,auxiliar[x].notaFinal,x+1);

              }
              free(auxiliar);

               auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
            while(strcmp(curso[i].aluno[j].tipovaga,"L5")==0){
              if(curso[i].aluno[j].presente==true){
                  auxiliar[cont]=curso[i].aluno[j];
                  cont++;
                  auxiliar = (tipoAluno*) realloc(auxiliar, cont * sizeof(tipoAluno));
              }
              j++;
            }//termina o while aq
            //ordena auxiliar
               for(int x=0;x<cont;x++){
                 fprintf(arqsaida, "%d %.2f %.2f %.2f %.2f %.2f %s %.2f %d\n",auxiliar[x].codinscricao,auxiliar[x].v_ling,auxiliar[x].v_mat,auxiliar[x].v_nat,auxiliar[x].v_hum,auxiliar[x].red,auxiliar[x].tipovaga,auxiliar[x].notaFinal,x+1);

              }
              free(auxiliar);

               auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
            while(strcmp(curso[i].aluno[j].tipovaga,"L7")==0){
              if(curso[i].aluno[j].presente==true){
                  auxiliar[cont]=curso[i].aluno[j];
                  cont++;
                  auxiliar = (tipoAluno*) realloc(auxiliar, cont * sizeof(tipoAluno));
              }
              j++;
            }//termina o while aq
            //ordena auxiliar
               for(int x=0;x<cont;x++){
                 fprintf(arqsaida, "%d %.2f %.2f %.2f %.2f %.2f %s %.2f %d\n",auxiliar[x].codinscricao,auxiliar[x].v_ling,auxiliar[x].v_mat,auxiliar[x].v_nat,auxiliar[x].v_hum,auxiliar[x].red,auxiliar[x].tipovaga,auxiliar[x].notaFinal,x+1);

              }
              free(auxiliar);

               auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
            while(strcmp(curso[i].aluno[j].tipovaga,"L9")==0){
              if(curso[i].aluno[j].presente==true){
                  auxiliar[cont]=curso[i].aluno[j];
                  cont++;
                  auxiliar = (tipoAluno*) realloc(auxiliar, cont * sizeof(tipoAluno));
              }
              j++;
            }//termina o while aq
            //ordena auxiliar
               for(int x=0;x<cont;x++){
                 fprintf(arqsaida, "%d %.2f %.2f %.2f %.2f %.2f %s %.2f %d\n",auxiliar[x].codinscricao,auxiliar[x].v_ling,auxiliar[x].v_mat,auxiliar[x].v_nat,auxiliar[x].v_hum,auxiliar[x].red,auxiliar[x].tipovaga,auxiliar[x].notaFinal,x+1);

              }
              free(auxiliar);

               auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
            while(strcmp(curso[i].aluno[j].tipovaga,"L11")==0){
              if(curso[i].aluno[j].presente==true){
                  auxiliar[cont]=curso[i].aluno[j];
                  cont++;
                  auxiliar = (tipoAluno*) realloc(auxiliar, cont * sizeof(tipoAluno));
              }
              j++;
            }//termina o while aq
            //ordena auxiliar
               for(int x=0;x<cont;x++){
                 fprintf(arqsaida, "%d %.2f %.2f %.2f %.2f %.2f %s %.2f %d\n",auxiliar[x].codinscricao,auxiliar[x].v_ling,auxiliar[x].v_mat,auxiliar[x].v_nat,auxiliar[x].v_hum,auxiliar[x].red,auxiliar[x].tipovaga,auxiliar[x].notaFinal,x+1);

              }
              free(auxiliar);

               auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
            while(strcmp(curso[i].aluno[j].tipovaga,"L13")==0){
              if(curso[i].aluno[j].presente==true){
                  auxiliar[cont]=curso[i].aluno[j];
                  cont++;
                  auxiliar = (tipoAluno*) realloc(auxiliar, cont * sizeof(tipoAluno));
              }
              j++;
            }//termina o while aq
            //ordena auxiliar
               for(int x=0;x<cont;x++){
                 fprintf(arqsaida, "%d %.2f %.2f %.2f %.2f %.2f %s %.2f %d\n",auxiliar[x].codinscricao,auxiliar[x].v_ling,auxiliar[x].v_mat,auxiliar[x].v_nat,auxiliar[x].v_hum,auxiliar[x].red,auxiliar[x].tipovaga,auxiliar[x].notaFinal,x+1);

              }
              free(auxiliar);

               auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
            while(strcmp(curso[i].aluno[j].tipovaga,"L15")==0){
              if(curso[i].aluno[j].presente==true){
                  auxiliar[cont]=curso[i].aluno[j];
                  cont++;
                  auxiliar = (tipoAluno*) realloc(auxiliar, cont * sizeof(tipoAluno));
              }
              j++;
            }//termina o while aq
            //ordena auxiliar
               for(int x=0;x<cont;x++){
                 fprintf(arqsaida, "%d %.2f %.2f %.2f %.2f %.2f %s %.2f %d\n",auxiliar[x].codinscricao,auxiliar[x].v_ling,auxiliar[x].v_mat,auxiliar[x].v_nat,auxiliar[x].v_hum,auxiliar[x].red,auxiliar[x].tipovaga,auxiliar[x].notaFinal,x+1);

              }
              free(auxiliar);
                
            }
           
          }
 

     


 




/*
void buscaImprimeCandidato(int numerodecursos, tipoCurso curso[], int
codcodinscricaor){ int i, aux; i = 0; while (i < numerodecursos){ aux = 0; while
(aux < curso[i].qtd){ //refere-se a quantidade de aluno no vetor if
(codcodinscricaor == curso[i].aluno[aux].codcodinscricaoricao){ printf("%d %s
%d/%d/%d %d %s", curso[i].aluno[aux].codcodinscricaoricao,
curso[i].aluno[aux].nomecandidato, curso[i].aluno[aux].datanasc.dia,
curso[i].aluno[aux].datanasc.mes, curso[i].aluno[aux].datanasc.ano,
curso[i].codCurso, curso[i].nomeCurso); break;
        }
        aux++;
      }
      i++;
    }
}

void intercalaAcertos(int p, int q, int r, tipoAluno *v){
  int i, j, k;
  tipoAluno *w;
  w = (tipoAluno *) malloc(r * sizeof(tipoAluno));

  i = p; j = q; k = 0;
  while(i < q && j < r) {
    if(v[i].codinscricao < v[j].codinscricao){
      w[k] = v[i]; i++;
    }
    else{
      w[k] = v[j]; j++;
    }
    k++;
  }
  while(i < q){
    w[k] = v[i]; i++; k++;
    }
  while(j < r){
    w[k] = v[j]; j++; k++;
  }
  for(i = p; i < r; i++) {
    v[i] = w[i - p];
  }
  free(w);
}

void mergesortAcertos(int p, int r, tipoAluno *v){
  int q;
  if(p < r - 1){
    q = (p + r) / 2;
    mergesortAcertos(p, q, v);
    mergesortAcertos(q, r, v);
    intercalaAcertos(p, q, r, v);
  }
}




tipoAluno verificaEmpate(tipoAluno aluno1, tipoAluno
notasAluno1,tipoAluno aluno2, tipoAluno notasAluno2){ tipoAluno maior; a)
ver idade igual ou superior a sessenta anos, dentre estes o de maior idade; b)
ver maior escore na Prova de Redação; c) ver maior escore padronizado (VL) na
competência Linguagem, Códigos e suas Tecnologias na Prova Objetiva; d) ver
maior escore padronizado (VM) na competência Matemática e suas Tecnologias na
Prova Objetiva; e) ver maior escore padronizado (VH) na competência Ciências
Humanas e suas Tecnologias na Prova Objetiva; e f) ver maior escore padronizado
(VN) na competência Ciências da Natureza e suas Tecnologias na Prova Objetiva;
  return maior;
}






void naoAprovados(int quant, tipoCurso *curso){
  FILE*  arqsaida;
  arqsaida = fopen("saidaNaoAprovados.txt", "a");
  for(int i=0;i<quant;i++){
    fprintf(arqsaida, "%d %s\n",curso[i].codCurso,curso[i].nomeCurso);
    //percorrer os candidatos e ver quem não passou





  }
   fclose(arqsaida);
}







void troca(tipoCurso curso[], int indiceTroca, int indiceA_Trocar){ //utilizar
em verifica empate entre outras ocasiões
                                  //i               //j
  tipoCurso *aux; //criar struct tipoCurso auxiliar pra realizar troca
  aux = (tipocurso*) malloc(1 * sizeof(tipoCurso)); //alocou na memória
  if (aux == NULL){
    printf("\nImpossível realizar alocação de memória para registro auxiliar na
função troca.\n");
  }
  else{
    //Realizar troca
    aux = curso[indiceTroca];
    curso[indiceTroca] = curso[indiceA_Trocar];
    curso[indiceA_Trocar] = aux;
  }
}
*/

    
