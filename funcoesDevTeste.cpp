#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funcoes.h"
#include <ctype.h>

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

float mediaDaArea(float quant, float soma){ //passar valor correspondente a soma da materia no parametro

    float media; //variável q será retornada
    media = (soma / quant); 
    return media;
}

float desvioPadrao(float media, int quant, acertos_notas *aluno, int num){ 
    float desvio=0; //vai ser a variável a ser retornada, porém deve ser guardada em outra variável na main.
    int i;

   if(num==0){
    for (i = 0; i < quant; i++){ 
          desvio = desvio + pow(aluno[i].v_ling - media,2);
        }
      }
    else if(num==1){
     for (i = 0; i < quant; i++){ 
          desvio = desvio + pow(aluno[i].v_mat- media,2);
        }
      }
     else if(num==2){
     for (i = 0; i < quant; i++){ 
          desvio = desvio + pow(aluno[i].v_nat - media,2);
        } 
      }   
      else if(num==3) {
     for (i = 0; i < quant; i++){ 
          desvio = desvio + pow(aluno[i].v_hum - media,2);
        }
      }             

    desvio = sqrt(desvio/(quant-1)); //uso de math.h , acho q é permitido usar
    return desvio; 
}

void eP_NotaFinal(acertos_notas aluno[], tipoCurso curso[], int quant, int qtdCursos, float media[], float desvio[]){//quant = quantidade de candidatos
    int i = 0;
    int indicecurso;
    int aux;
    int j;
    for (i; i < quant; i++){
        aluno[i].EP[0] = 500 + 100*((2*aluno[i].v_ling - media[0])/desvio[0]);
        aluno[i].EP[1] = 500 + 100*((2*aluno[i].v_mat - media[1])/desvio[1]);
        aluno[i].EP[2] = 500 + 100*((2*aluno[i].v_nat - media[2])/desvio[2]);
        aluno[i].EP[3] = 500 + 100*((2*aluno[i].v_hum - media[3])/desvio[3]);

        //temos que realizar uma busca sequencial no struct Curso.tuplas[aux=Curso.qtd] para localizar o codInsc do candidato e assim aferir sua nota Final
        j = 0; //sempre zera para percorrer tudo novamente
        while (j<qtdCursos){ 
          aux = 0;//zera para percorrer as tuplas de forma correta a cada Curso[j].tuplas
          while (aux < curso[j].qtd){
              
              if (curso[j].tuplas[aux].codinscricao == aluno[i].insc){
                  
                aluno[i].notaFinal = (aluno[i].red * curso[j].pesoRed + aluno[i].EP[3] * curso[j].pesoHum + aluno[i].EP[0] * curso[j].pesoLing + aluno[i].EP[1] * curso[j].pesoMat + aluno[i].EP[2] * curso[j].pesoNat)/(curso[j].pesoRed + curso[j].pesoHum + curso[j].pesoLing + curso[j].pesoMat + curso[j].pesoNat);
                curso[j].tuplas[aux].notaFinal=aluno[i].notaFinal;
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

void intercalaAcertos(int p, int q, int r, acertos_notas *v){
  int i, j, k;
  acertos_notas *w;
  w = (acertos_notas *) malloc(r * sizeof(acertos_notas));

  i = p; j = q; k = 0; 
  while(i < q && j < r) {
    if(v[i].insc < v[j].insc){
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

void mergesortAcertos(int p, int r, acertos_notas *v){
  int q;
  if(p < r - 1){
    q = (p + r) / 2;
    mergesortAcertos(p, q, v);
    mergesortAcertos(q, r, v);
    intercalaAcertos(p, q, r, v);
  }
}

int busca_binariaAcertos(int n, acertos_notas *v, int x)
{
int esq, dir, meio;
esq = -1;
dir = n;
while (esq < dir - 1) {
  meio = (esq + dir) / 2;
  if (v[meio].insc < x)
    esq = meio;
  else
    dir = meio;
}
return dir;
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
  dadoEmLinhas *w;
  w = (dadoEmLinhas *) malloc(r * sizeof(dadoEmLinhas));

  i = p; j = q; k = 0; 
  while(i < q && j < r) {


    if(strcmp(v.tuplas[i].tipovaga, v.tuplas[j].tipovaga) < 0){  
      w[k] = v.tuplas[i]; i++;
    }
    else{
      w[k] = v.tuplas[j]; j++;
    }
    k++;
  }
  while(i < q){
    w[k] = v.tuplas[i]; i++; k++;
    }
  while(j < r){
    w[k] = v.tuplas[j]; j++; k++;  
  }
  for(i = p; i < r; i++) {
    v.tuplas[i] = w[i - p];
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

dadoEmLinhas verificaEmpate(dadoEmLinhas aluno1, acertos_notas notasAluno1,dadoEmLinhas aluno2, acertos_notas notasAluno2){ 
  dadoEmLinhas maior;
  /*a) ver idade igual ou superior a sessenta anos, dentre estes o de maior idade;
  b) ver maior escore na Prova de Redação;
  c) ver maior escore padronizado (VL) na competência Linguagem, Códigos e suas
  Tecnologias na Prova Objetiva;
  d) ver maior escore padronizado (VM) na competência Matemática e suas
  Tecnologias na Prova Objetiva;
  e) ver maior escore padronizado (VH) na competência Ciências Humanas e suas
  Tecnologias na Prova Objetiva; e
  f) ver maior escore padronizado (VN) na competência Ciências da Natureza e suas
  Tecnologias na Prova Objetiva;*/
  return maior;
}


void intercalaNota(int p, int q, int r, tipoCurso v){
  int i, j, k,x,y;
  dadoEmLinhas *w;
  w = (dadoEmLinhas *) malloc(r * sizeof(dadoEmLinhas));

  i = p; j = q; k = 0; 
  while(i < q && j < r) {

    if(v.tuplas[i].notaFinal >v.tuplas[j].notaFinal){  
      w[k] = v.tuplas[i]; i++;
    }
    /*else if(aluno[x].notaFinal=aluno[y].notaFinal){
      dadoEmLinhas maior;
      maior =  verificaEmpate(v.tuplas[i], aluno[x], v.tuplas[j], aluno[y]);
      if(maior==v.tuplas[i]){
         w[k] = v.tuplas[i]; i++;
      } else{
        w[k] = v.tuplas[j]; j++;;
      }
      
    }*/
    else{
      w[k] = v.tuplas[j]; j++;
    }
    k++;
  }
  while(i < q){
    w[k] = v.tuplas[i]; i++; k++;
    }
  while(j < r){
    w[k] = v.tuplas[j]; j++; k++;  
  }
  for(i = p; i < r; i++) {
    v.tuplas[i] = w[i - p];
  }
  free(w);
}

void mergesortNota(int p, int r, tipoCurso v)/*ao inves de passar qtdalunos tem q passar a quantidade que ta concorrendo no msm tipo de vaga*/{
  int q;
  if(p < r - 1){
    q = (p + r) / 2;
    mergesortNota(p, q, v);
    mergesortNota(q, r, v);
    intercalaNota(p, q, r, v);
  }
}

void naoAprovados(int quant, tipoCurso *curso){
  FILE*  arqsaida;    /* variavel para manip arquivo de saida*/ 
  arqsaida = fopen("saidaNaoAprovados.txt", "a");
  for(int i=0;i<quant;i++){
    fprintf(arqsaida, "%d %s\n",curso[i].codCurso,curso[i].nomeCurso);
    //percorrer os candidatos e ver quem não passou
       
           
           
      

  }
   fclose(arqsaida);
}

/*void listaGeral(int quant, tipoCurso *curso,acertos_notas *aluno){
  arqsaida = fopen("listaGeral.txt", "a");
  int x;
  for(int i=0;i<quant;i++){
    fprintf(arqsaida,"%d %s\n",curso[i].codCurso,curso[i].nomeCurso);
     fprintf(arqsaida,"INSC	V_LIN	V_MAT	V_NAT	V_HUM	RED	COTA	NOTA FINAL	CLASSIFICAÇÃO\n");
     for(int j=0;j<curso[i].qtd;i++){
      //ao inves de passar qtdalunos tem q passar a quantidade que ta concorrendo no msm tipo de vaga
      x = busca_binariaAcertos(qtdAlunos, aluno, curso.tuplas[j].codinscricao);
      fprintf(arqsaida,"%d %.2f %.2f %.2f %.2f %.2f %s %.2f %d\n",aluno[x].insc,aluno[x].EP[0],aluno[x].EP[1],aluno[x].EP[2],aluno[x].EP[3],aluno[x].red,curso[i].tuplas[j].tipovaga,aluno[x].notaFinal,j);

     }


  }
}
*/




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

*/

