#include <stdio.h>
#include <stdlib.h>
struct acertos{
    int insc, v_ling, v_mat, v_nat, v_hum;
    float red;
};
int main(){
    FILE *arq;
    int qtd; // qtd de alunos
    acertos *contagem; //registro a ser alocado dinâmicamente
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
        
        contagem = (acertos*) malloc(qtd*sizeof(acertos)); //alocação
        
        int i;

        for (i = 0; i < qtd; i++){
            fscanf(arq, "%d %d %d %d %d %.2f", &contagem[i].insc, &contagem[i].v_ling, &contagem[i].v_mat, &contagem[i].v_nat, &contagem[i].v_hum, &contagem[i].red); //leitura dos dados

            //OPERAÇÕES
            // -----------------------------
        }

    }

    return 0;
}