#include <stdio.h>
#include <stdlib.h>
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

