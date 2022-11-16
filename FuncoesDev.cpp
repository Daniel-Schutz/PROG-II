#include "funcoes.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desenvolver funcoes
void menu() {
  printf("\n.+*****+.MENU.+*****+.\n");
  printf("1 - Gerar arquivo de saída .txt\n");

  printf("2 - Pesquisar candidatos .txt\n");

  printf("3 - Gerar arquivo dos candidatos não aprovados\n");

  printf("4- Alterar nota de redação dos candidatos que entraram com recurso\n");

  printf("5 - Encerrar programa\n");
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

void intercalaNota(int p, int q, int r, tipoAluno *v) {
  int i, j, k;
  tipoAluno *w;
  w = (tipoAluno *)malloc(r * sizeof(tipoAluno));

  i = p;
  j = q;
  k = 0;
  while (i < q && j < r) {
    if (v[i].notaFinal > v[j].notaFinal) {
      w[k] = v[i];
      i++;} 

    else if(v[i].notaFinal == v[j].notaFinal) {
      tipoAluno maior;
      maior = verificaEmpate(v[i],v[j]);
      if(maior.codinscricao==v[i].codinscricao){
        w[k] = v[i];
      i++;
      } else{
        w[k] = v[j];
      j++;
      }
    } 
    else {
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

void mergesortNota(int p, int r, tipoAluno *v) {
  int q;
  if (p < r - 1) {
    q = (p + r) / 2;
    mergesortNota(p, q, v);
    mergesortNota(q, r, v);
    intercalaNota(p, q, r, v);
  }
}

void listaParticipantes(int quant, tipoCurso *curso){
          FILE*  arqsaida;   
          arqsaida = fopen("listaParticipantes.txt", "w");
          fprintf(arqsaida, "/*LISTA GERAL CLASSIFICADO POR NOTA*/\n");
          for(int i=0;i<quant;i++){
            fprintf(arqsaida, "\n%d %s\n",curso[i].codCurso,curso[i].nomeCurso);
             fprintf(arqsaida, "INSC	  V_LIN	  V_MAT	  V_NAT	  V_HUM	  RED	 COTA	 NOTA FINAL	 CLASSIFICAÇÃO\n");
             tipoAluno *auxiliar;
             int cont=0;
             int acumulo=curso[i].quantAC;
             int primeiro=0;
            auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));         

              }
             }
             mergesortNota(0,cont,auxiliar);
            for(int x=0;x<cont;x++){
                 fprintf(arqsaida, "%d  %.2f  %.2f  %.2f  %.2f  %.2f  %s  %.2f  %d\n",auxiliar[x].codinscricao,auxiliar[x].EP[0],auxiliar[x].EP[1],auxiliar[x].EP[2],auxiliar[x].EP[3],auxiliar[x].red,auxiliar[x].tipovaga,auxiliar[x].notaFinal,x+1);

              }
              free(auxiliar);//TERMINOU

              primeiro=acumulo;
              acumulo+=curso[i].quantL1;
              cont=0;
              auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));         

              }
             }
             mergesortNota(0,cont,auxiliar);
            for(int x=0;x<cont;x++){
                 fprintf(arqsaida, "%d  %.2f  %.2f  %.2f  %.2f  %.2f  %s  %.2f  %d\n",auxiliar[x].codinscricao,auxiliar[x].EP[0],auxiliar[x].EP[1],auxiliar[x].EP[2],auxiliar[x].EP[3],auxiliar[x].red,auxiliar[x].tipovaga,auxiliar[x].notaFinal,x+1);

              }
              free(auxiliar);//TERMINOU

              primeiro=acumulo;
              acumulo+=curso[i].quantL3;
              cont=0;
              auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));         

              }
             }
             mergesortNota(0,cont,auxiliar);
            for(int x=0;x<cont;x++){
                 fprintf(arqsaida, "%d  %.2f  %.2f  %.2f  %.2f  %.2f  %s  %.2f  %d\n",auxiliar[x].codinscricao,auxiliar[x].EP[0],auxiliar[x].EP[1],auxiliar[x].EP[2],auxiliar[x].EP[3],auxiliar[x].red,auxiliar[x].tipovaga,auxiliar[x].notaFinal,x+1);

              }
              free(auxiliar);//TERMINOU

              primeiro=acumulo;
              acumulo+=curso[i].quantL4;
              cont=0;
              auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));         

              }
             }
             mergesortNota(0,cont,auxiliar);
            for(int x=0;x<cont;x++){
                 fprintf(arqsaida, "%d  %.2f  %.2f  %.2f  %.2f  %.2f  %s  %.2f  %d\n",auxiliar[x].codinscricao,auxiliar[x].EP[0],auxiliar[x].EP[1],auxiliar[x].EP[2],auxiliar[x].EP[3],auxiliar[x].red,auxiliar[x].tipovaga,auxiliar[x].notaFinal,x+1);

              }
              free(auxiliar);//TERMINOU

              primeiro=acumulo;
              acumulo+=curso[i].quantL5;
              cont=0;
              auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));         

              }
             }
             mergesortNota(0,cont,auxiliar);
            for(int x=0;x<cont;x++){
                 fprintf(arqsaida, "%d  %.2f  %.2f  %.2f  %.2f  %.2f  %s  %.2f  %d\n",auxiliar[x].codinscricao,auxiliar[x].EP[0],auxiliar[x].EP[1],auxiliar[x].EP[2],auxiliar[x].EP[3],auxiliar[x].red,auxiliar[x].tipovaga,auxiliar[x].notaFinal,x+1);

              }
              free(auxiliar);//TERMINOU

              primeiro=acumulo;
              acumulo+=curso[i].quantL7;
              cont=0;
              auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));         

              }
             }
             mergesortNota(0,cont,auxiliar);
            for(int x=0;x<cont;x++){
                 fprintf(arqsaida, "%d  %.2f  %.2f  %.2f  %.2f  %.2f  %s  %.2f  %d\n",auxiliar[x].codinscricao,auxiliar[x].EP[0],auxiliar[x].EP[1],auxiliar[x].EP[2],auxiliar[x].EP[3],auxiliar[x].red,auxiliar[x].tipovaga,auxiliar[x].notaFinal,x+1);

              }
              free(auxiliar);//TERMINOU

              primeiro=acumulo;
              acumulo+=curso[i].quantL8;
              cont=0;
              auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));         

              }
             }
             mergesortNota(0,cont,auxiliar);
            for(int x=0;x<cont;x++){
                 fprintf(arqsaida, "%d  %.2f  %.2f  %.2f  %.2f  %.2f  %s  %.2f  %d\n",auxiliar[x].codinscricao,auxiliar[x].EP[0],auxiliar[x].EP[1],auxiliar[x].EP[2],auxiliar[x].EP[3],auxiliar[x].red,auxiliar[x].tipovaga,auxiliar[x].notaFinal,x+1);

              }
              free(auxiliar);//TERMINOU

              primeiro=acumulo;
              acumulo+=curso[i].quantL9;
              cont=0;
              auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));         

              }
             }
             mergesortNota(0,cont,auxiliar);
            for(int x=0;x<cont;x++){
                 fprintf(arqsaida, "%d  %.2f  %.2f  %.2f  %.2f  %.2f  %s  %.2f  %d\n",auxiliar[x].codinscricao,auxiliar[x].EP[0],auxiliar[x].EP[1],auxiliar[x].EP[2],auxiliar[x].EP[3],auxiliar[x].red,auxiliar[x].tipovaga,auxiliar[x].notaFinal,x+1);

              }
              free(auxiliar);//TERMINOU

              primeiro=acumulo;
              acumulo+=curso[i].quantL11;
              cont=0;
              auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));         

              }
             }
             mergesortNota(0,cont,auxiliar);
            for(int x=0;x<cont;x++){
                 fprintf(arqsaida, "%d  %.2f  %.2f  %.2f  %.2f  %.2f  %s  %.2f  %d\n",auxiliar[x].codinscricao,auxiliar[x].EP[0],auxiliar[x].EP[1],auxiliar[x].EP[2],auxiliar[x].EP[3],auxiliar[x].red,auxiliar[x].tipovaga,auxiliar[x].notaFinal,x+1);

              }
              free(auxiliar);//TERMINOU

              primeiro=acumulo;
              acumulo+=curso[i].quantL13;
              cont=0;
              auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));         

              }
             }
             mergesortNota(0,cont,auxiliar);
            for(int x=0;x<cont;x++){
                 fprintf(arqsaida, "%d  %.2f  %.2f  %.2f  %.2f  %.2f  %s  %.2f  %d\n",auxiliar[x].codinscricao,auxiliar[x].EP[0],auxiliar[x].EP[1],auxiliar[x].EP[2],auxiliar[x].EP[3],auxiliar[x].red,auxiliar[x].tipovaga,auxiliar[x].notaFinal,x+1);

              }
              free(auxiliar);//TERMINOU

              primeiro=acumulo;
              acumulo+=curso[i].quantL15;
              cont=0;
              auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));         

              }
             }
             mergesortNota(0,cont,auxiliar);
            for(int x=0;x<cont;x++){
                 fprintf(arqsaida, "%d  %.2f  %.2f  %.2f  %.2f  %.2f  %s  %.2f  %d\n",auxiliar[x].codinscricao,auxiliar[x].EP[0],auxiliar[x].EP[1],auxiliar[x].EP[2],auxiliar[x].EP[3],auxiliar[x].red,auxiliar[x].tipovaga,auxiliar[x].notaFinal,x+1);

              }
              free(auxiliar);//TERMINOU
       
            




            }
           fclose(arqsaida);
          }
 

  tipoAluno verificaEmpate(tipoAluno aluno1, tipoAluno aluno2){
    int idade1 = 738375 - (365 *aluno1.datanasc.ano - 30 * aluno1.datanasc.mes - aluno1.datanasc.dia);
    int idade2 =  738375 - (365 *aluno2.datanasc.ano - 30 * aluno2.datanasc.mes - aluno2.datanasc.dia);
    if(idade1>=21900 && idade1>idade2){
      return aluno1;
    }
    else if(idade2>21900 && idade2>idade1){
      return aluno2;
    } else{
      if(aluno1.red>aluno2.red){
        return aluno1;
      }
      else if(aluno2.red>aluno1.red){
        return aluno2;
      } else{
        if(aluno1.EP[0]>aluno2.EP[0]){
        return aluno1;
      }
      else if(aluno2.EP[0]>aluno1.EP[0]){
        return aluno2;
      } else{
        if(aluno1.EP[1]>aluno2.EP[1]){
        return aluno1;
      }
      else if(aluno2.EP[1]>aluno1.EP[1]){
        return aluno2;
      } else{
        if(aluno1.EP[3]>aluno2.EP[3]){
        return aluno1;
      }
      else if(aluno2.EP[3]>aluno1.EP[3]){
        return aluno2;
      } else{
        if(aluno1.EP[2]>aluno2.EP[2]){
        return aluno1;
      }
      else if(aluno2.EP[2]>aluno1.EP[2]){
        return aluno2;
      }
      else{
        return aluno1;//se nao teve desempate
      }
      }
        

      }

      }


    }
  }   
  }

void buscaImprimeCandidato(int quant, tipoCurso curso[], int codinscr)
{ 
int achou=0;
for(int i=0;i<quant;i++){  
  for (int j=0;j<curso[i].qtd;j++){
    if(curso[i].aluno[j].codinscricao==codinscr){
      printf("\n%d %s %d/%d/%d %d %s\n", curso[i].aluno[j].codinscricao,curso[i].aluno[j].nomecandidato, curso[i].aluno[j].datanasc.dia,
curso[i].aluno[j].datanasc.mes, curso[i].aluno[j].datanasc.ano,curso[i].codCurso, curso[i].nomeCurso);
achou=1;
 break;
  }

  }
  

  
}
if(achou==0){
    printf("\nCandidato não encontrado.\n");
  }
  


}


void intercalaReprovados(int p, int q, int r, tipoAluno *v){
   int i, j, k;
  tipoAluno *w;
  w = (tipoAluno *) malloc(r * sizeof(tipoAluno));

  i = p; j = q; k = 0;
  while(i < q && j < r) {
    if(strcmp(v[i].nomecandidato, v[j].nomecandidato) < 0){
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

void mergesortReprovados(int p, int r, tipoAluno *v){
  int q;
  if(p < r - 1){
    q = (p + r) / 2;
    mergesortReprovados(p, q, v);
    mergesortReprovados(q, r, v);
    intercalaReprovados(p, q, r, v);
  }
}




void naoAprovados(int quant, tipoCurso *curso){
  FILE*  arqsaida;
  arqsaida = fopen("NaoAprovados.txt", "w");
  fprintf(arqsaida, ".+*******+.NAO APROVADOS.+*******+.\n");
  for(int i=0;i<quant;i++){
    fprintf(arqsaida, "\n%d %s\n",curso[i].codCurso,curso[i].nomeCurso);

    tipoAluno *auxiliar, *reprovados;
             int cont=0,contReprovados=0;
             int acumulo=curso[i].quantAC;
             int primeiro=0;
            auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
            reprovados=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));        
              } else if(curso[i].aluno[j].presente==false){
                reprovados[contReprovados]=curso[i].aluno[j];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));
              } 
             }
             mergesortNota(0,cont,auxiliar);
            for(int x=0;x<cont;x++){
                if(x>=curso[i].AC){
                reprovados[contReprovados]=auxiliar[x];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));

                }
              }
              free(auxiliar);//TERMINOU

              primeiro=acumulo;
              acumulo+=curso[i].quantL1;
              cont=0;
              auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));         

              } else if(curso[i].aluno[j].presente==false){
                reprovados[contReprovados]=curso[i].aluno[j];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));
              } 
             }
             mergesortNota(0,cont,auxiliar);
            for(int x=0;x<cont;x++){
                if(x>=curso[i].L1){
                reprovados[contReprovados]=auxiliar[x];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));

                }
              }
              free(auxiliar);//TERMINOU

              primeiro=acumulo;
              acumulo+=curso[i].quantL3;
              cont=0;
              auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));         

              } else if(curso[i].aluno[j].presente==false){
                reprovados[contReprovados]=curso[i].aluno[j];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));
              } 
             }
             mergesortNota(0,cont,auxiliar);
            for(int x=0;x<cont;x++){
                if(x>=curso[i].L3){
                reprovados[contReprovados]=auxiliar[x];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));

                }
              }
              free(auxiliar);//TERMINOU

              primeiro=acumulo;
              acumulo+=curso[i].quantL4;
              cont=0;
              auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));         

              } else if(curso[i].aluno[j].presente==false){
                reprovados[contReprovados]=curso[i].aluno[j];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));
              } 
             }
             mergesortNota(0,cont,auxiliar);
            for(int x=0;x<cont;x++){
                if(x>=curso[i].L4){
                reprovados[contReprovados]=auxiliar[x];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));

                }
              }
              free(auxiliar);//TERMINOU

              primeiro=acumulo;
              acumulo+=curso[i].quantL5;
              cont=0;
              auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));         

              } else if(curso[i].aluno[j].presente==false){
                reprovados[contReprovados]=curso[i].aluno[j];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));
              } 
             }
             mergesortNota(0,cont,auxiliar);
            for(int x=0;x<cont;x++){
                if(x>=curso[i].L5){
                reprovados[contReprovados]=auxiliar[x];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));

                }
              }
              free(auxiliar);//TERMINOU

              primeiro=acumulo;
              acumulo+=curso[i].quantL7;
              cont=0;
              auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));         

              } else if(curso[i].aluno[j].presente==false){
                reprovados[contReprovados]=curso[i].aluno[j];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));
              } 
             }
             mergesortNota(0,cont,auxiliar);
            for(int x=0;x<cont;x++){
                if(x>=curso[i].L7){
                reprovados[contReprovados]=auxiliar[x];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));

                }
              }
              free(auxiliar);//TERMINOU

              primeiro=acumulo;
              acumulo+=curso[i].quantL8;
              cont=0;
              auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));         

              } else if(curso[i].aluno[j].presente==false){
                reprovados[contReprovados]=curso[i].aluno[j];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));
              } 
             }
             mergesortNota(0,cont,auxiliar);
            for(int x=0;x<cont;x++){
                if(x>=curso[i].L8){
                reprovados[contReprovados]=auxiliar[x];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));

                }
              }
              free(auxiliar);//TERMINOU

              primeiro=acumulo;
              acumulo+=curso[i].quantL9;
              cont=0;
              auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));         

              } else if(curso[i].aluno[j].presente==false){
                reprovados[contReprovados]=curso[i].aluno[j];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));
              } 
             }
             mergesortNota(0,cont,auxiliar);
            for(int x=0;x<cont;x++){
                if(x>=curso[i].L9){
                reprovados[contReprovados]=auxiliar[x];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));

                }
              }
              free(auxiliar);//TERMINOU

              primeiro=acumulo;
              acumulo+=curso[i].quantL11;
              cont=0;
              auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));         

              } else if(curso[i].aluno[j].presente==false){
                reprovados[contReprovados]=curso[i].aluno[j];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));
              } 
             }
             mergesortNota(0,cont,auxiliar);
            for(int x=0;x<cont;x++){
                if(x>=curso[i].L11){
                reprovados[contReprovados]=auxiliar[x];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));

                }
              }
              free(auxiliar);//TERMINOU

              primeiro=acumulo;
              acumulo+=curso[i].quantL13;
              cont=0;
              auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));         

              } else if(curso[i].aluno[j].presente==false){
                reprovados[contReprovados]=curso[i].aluno[j];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));
              } 
             }
             mergesortNota(0,cont,auxiliar);
             for(int x=0;x<cont;x++){
                if(x>=curso[i].L13){
                reprovados[contReprovados]=auxiliar[x];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));

                }
              }
              free(auxiliar);//TERMINOU

              primeiro=acumulo;
              acumulo+=curso[i].quantL15;
              cont=0;
              auxiliar=(tipoAluno *)malloc(sizeof(tipoAluno));
             for(int j=primeiro; j<acumulo;j++){
              if(curso[i].aluno[j].presente==true){
                auxiliar[cont]=curso[i].aluno[j];
                cont+=1;
                auxiliar = (tipoAluno*) realloc(auxiliar, (cont+1) * sizeof(tipoAluno));         

              } else if(curso[i].aluno[j].presente==false){
                reprovados[contReprovados]=curso[i].aluno[j];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));
              } 
             }
             mergesortNota(0,cont,auxiliar);
             for(int x=0;x<cont;x++){
                if(x>=curso[i].L15){
                reprovados[contReprovados]=auxiliar[x];
                contReprovados+=1;
                reprovados = (tipoAluno*) realloc(reprovados, (contReprovados+1) * sizeof(tipoAluno));

                }
              }
              free(auxiliar);//TERMINOU

              mergesortReprovados(0,contReprovados,reprovados);
              for(int x=0;x<contReprovados;x++){
                fprintf(arqsaida,"%d %s\n",reprovados[x].codinscricao,reprovados[x].nomecandidato);
              }
              free(reprovados);
       
            


    





  }
   fclose(arqsaida);
}
