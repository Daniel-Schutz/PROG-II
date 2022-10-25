#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funcoes.h"

// Desenvolver funcoes
void menu(){
  printf("\n1 - Gerar arquivo de saída .txt");
  
  printf("\n2 - Pesquisar candidatos .txt");
    
    
  printf("\n3 - Gerar arquivo dos candidatos não aprovados");
  
  printf("\n4 - Alterar nota de redação dos candidatos que entraram com recurso");
  
  printf("\n5 - Encerrar programa");
}

void intercalaTipoCurso(int p, int q, int r, tipoCurso *v){
  int i, j, k;
  tipoCurso *w;
  w = (tipoCurso *) malloc(r * sizeof(tipoCurso));

  i = p; j = q; k = 0; 
  while(i < q && j < r) {
    if(v[i].codCurso < v[j].codCurso){
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

void mergesortTipoCurso(int p, int r, tipoCurso *v){
  int q;
  if(p < r - 1){
    q = (p + r) / 2;
    mergesortTipoCurso(p, q, v);
    mergesortTipoCurso(q, r, v);
    intercalaTipoCurso(p, q, r, v);
  }
}

int busca_binariaTipoCurso(int n, tipoCurso *v, int x)
{
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

float mediaDaArea(int quant, int soma){ //passar valor correspondente a soma da materia no parametro

    float media; //variável q será retornada
    media = 2*(soma / quant); // precisa multiplicar por dois para receber o valor correto do EP
    return media;
}

float desvioPadrao(float media, int quant, acertos_notas contagem[], char nomeArea[7]){ 
    int x = 0;
    int somatorio = 0;
    float desvio; //vai ser a variável a ser retornada, porém deve ser guardada em outra variável na main.
    int i = 0;

    //realizar o somatório de (0) até (n-1) e no final calcular o desvio e o retornar.
    for (i; i < quant; i++){ 
            //dadosacertos[i] significa acerto individual.
            //x atualiza para o valor correto em cada chamda do for
            x = (contagem[i].nomeArea - media); //significa a operação básica para o somatório.
            somatorio = somatorio + x*x;
        }

    desvio = sqrt((somatorio/quant-1)); //uso de math.h , acho q é permitido usar
    return 2*desvio; //lembrar de guardar em variável respectiva à area de conhecimento quando for implementar na main.
}

void eP_NotaFinal(acertos_notas contagem[], tipoCurso curso[], int quant, int qtdCursos, float media[], float desvio[]){//quant = quantidade de candidatos
    int i = 0;
    for (i; i < quant; i++){
        contagem[i].EP[0] = 500 + 100*((2*contagem[i].v_ling - media[0])/desvio[0]);
        contagem[i].EP[1] = 500 + 100*((2*contagem[i].v_mat - media[1])/desvio[1]);
        contagem[i].EP[2] = 500 + 100*((2*contagem[i].v_nat - media[2])/desvio[2]);
        contagem[i].EP[3] = 500 + 100*((2*contagem[i].v_hum - media[3])/desvio[3]);

        // Pro calculo da notaFinal, aqui ainda ta errado, pois precisamos procurar por codcurso pra definir o peso
        // Vou precisar de ajudar pra entender como ta seu código, aqui a gente precisa fazer junto
        contagem[i].notaFinal = (contagem[i].red * curso[i].pesoRed + contagem[i].EP[3] * curso[i].pesoHum + contagem[i].EP[0] * curso[i].pesoLing + contagem[i].EP[1] * curso[i].pesoMat + contagem[i].EP[2] * curso[i].pesoNat)/(curso[i].pesoRed + curso[i].pesoHum + curso[i].pesoLing + curso[i].pesoMat + curso[i].pesoNat);
    }
}