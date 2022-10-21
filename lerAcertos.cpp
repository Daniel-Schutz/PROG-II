#include <stdio.h>
#include <stdlib.h>
struct acertos_notas{
    int insc, v_ling, v_mat, v_nat, v_hum;
    float red;
    float EP[4];
    float notaFinal;
};
int main(){ // parâmetros (int qtd, acertos dadosacertos[], int *soma)
    FILE *arq;
    int qtd; // qtd de alunos
    acertos_notas *contagem; //registro a ser alocado dinâmicamente
    char nome[20];
    printf("Digite o nome do arquivo: ");
    scanf(" %s", nome); //lendo nome do arquivo
    //
    fopen(nome,"r"); //abrindo arquivo;
    

    if (nome==NULL){
        printf("\n\nO arquivo não pode ser aberto\n\n");
    }


    else{
        //fazer alocação dinâmica e leitura das entradas
        
        fscanf(arq, "%d", &qtd); //guarda a quantidade de alunos;
        
        contagem = (acertos_notas*) malloc(qtd*sizeof(acertos_notas)); //alocação
        
        int i;
        for (i = 0; i < qtd; i++){
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
        return 0;
}   