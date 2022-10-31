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

float desvioPadrao(float media, int quant, acertos_notas contagem[], int num){ 
    int x = 0;
    int somatorio = 0;
    float desvio; //vai ser a variável a ser retornada, porém deve ser guardada em outra variável na main.
    int i = 0;

   if(num==0){
    for (i; i < quant; i++){ 
            //dadosacertos[i] significa acerto individual.
            //x atualiza para o valor correto em cada chamda do for
            x = (contagem[i].v_ling - media); //significa a operação básica para o somatório.
            somatorio = somatorio + x*x;
        }}
    else if(num==1){
    for (i; i < quant; i++){ 
            //dadosacertos[i] significa acerto individual.
            //x atualiza para o valor correto em cada chamda do for
            x = (contagem[i].v_mat - media); //significa a operação básica para o somatório.
            somatorio = somatorio + x*x;
        }}
     else if(num==2){
    for (i; i < quant; i++){ 
            //dadosacertos[i] significa acerto individual.
            //x atualiza para o valor correto em cada chamda do for
            x = (contagem[i].v_nat - media); //significa a operação básica para o somatório.
            somatorio = somatorio + x*x;
        } }   
      else {
    for (i; i < quant; i++){ 
            //dadosacertos[i] significa acerto individual.
            //x atualiza para o valor correto em cada chamda do for
            x = (contagem[i].v_hum - media); //significa a operação básica para o somatório.
            somatorio = somatorio + x*x;
        } }             

    desvio = sqrt((somatorio/quant-1)); //uso de math.h , acho q é permitido usar
    return 2*desvio; //lembrar de guardar em variável respectiva à area de conhecimento quando for implementar na main.
}

void eP_NotaFinal(acertos_notas contagem[], tipoCurso curso[], int quant, int qtdCursos, float media[], float desvio[]){//quant = quantidade de candidatos
    int i = 0;
    int indicecurso;
    int aux;
    int j;
    for (i; i < quant; i++){
        contagem[i].EP[0] = 500 + 100*((2*contagem[i].v_ling - media[0])/desvio[0]);
        contagem[i].EP[1] = 500 + 100*((2*contagem[i].v_mat - media[1])/desvio[1]);
        contagem[i].EP[2] = 500 + 100*((2*contagem[i].v_nat - media[2])/desvio[2]);
        contagem[i].EP[3] = 500 + 100*((2*contagem[i].v_hum - media[3])/desvio[3]);

        //temos que realizar uma busca sequencial no struct Curso.tuplas[aux=Curso.qtd] para localizar o codInsc do candidato e assim aferir sua nota Final
        j = 0; //sempre zera para percorrer tudo novamente
        while (j<qtdCursos){ 
          aux = 0;//zera para percorrer as tuplas de forma correta a cada Curso[j].tuplas
          while (aux < curso[j].qtd){
              
              if (curso[j].tuplas[aux].codinscricao == contagem[i].insc){
                  
                contagem[i].notaFinal = (contagem[i].red * curso[j].pesoRed + contagem[i].EP[3] * curso[j].pesoHum + contagem[i].EP[0] * curso[j].pesoLing + contagem[i].EP[1] * curso[j].pesoMat + contagem[i].EP[2] * curso[j].pesoNat)/(curso[j].pesoRed + curso[j].pesoHum + curso[j].pesoLing + curso[j].pesoMat + curso[j].pesoNat);
                aux = curso[j].qtd; //para finalizar a estrutura de repetição
                j = qtdCursos; //para finalizar a outra estrutura de repetição
                //impede a percorrimento desnecessário
              }
              aux++;
          }
          j++;
        }
    }
}

void buscaImprimeCandidato(int numerodecursos, tipoCurso curso[], int codinscr){
    int i, aux;
    i = 0;
    while (i < numerodecursos){
      aux = 0;
      while (aux < curso[i].qtd){ //refere-se a quantidade de tuplas no vetor
        if (codinscr == curso[i].tuplas[aux].codinscricao){
          printf("%d %s    %d/%d/%d %d %s", curso[i].tuplas[aux].codinscricao, curso[i].tuplas[aux].nomecandidato, curso[i].tuplas[aux].datanasc.dia, curso[i].tuplas[aux].datanasc.mes, curso[i].tuplas[aux].datanasc.ano, curso[i].codCurso, curso[i].nomeCurso);
          break;
        }
        aux++;
      }
      i++;
    }
}

/*void troca(tipoCurso curso[], int indiceTroca, int indiceA_Trocar){ //utilizar em verifica empate entre outras ocasiões
                                  //i               //j
  tipoCurso *aux; //criar struct tipoCurso auxiliar pra realizar troca
  aux = (tipocurso*) malloc(1 * sizeof(tipoCurso)); //alocou na memória
  if (aux == NULL){
    printf("\nImpossível realizar alocação de memória para registro auxiliar na função troca.\n");
  }
  else{
    //Realizar troca
    aux = curso[indiceTroca];
    curso[indiceTroca] = curso[indiceA_Trocar];
    curso[indiceA_Trocar] = aux;
  }
}

void verificaEmpate(){ //verificar casos de empate e realizar a troca ordenando a lista dos candidatos em cada (Curso[j].tuplas[Curso.qtd])

}*/
