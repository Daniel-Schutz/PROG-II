#include <stdio.h>
#include <string.h>
struct acertos{
    int insc, v_ling, v_mat, v_nat, v_hum;
    float red;
}; //Botei aqui por enquanto so pra ter a base direito e pra não dar erro

//dadosacertos deve ser um vetor
float mediaDaArea(acertos dadosacertos[], int quant, char nomeArea[7]){ //quant refere-se a quantidade de participantes
    //percorrer vetor, realizar soma de determinada area, e dividir por quant no final
    float soma = 0;
    float media; //variável q será retornada
    int i = 0;
    //foi feita a comparação pra realizar a media correspondente
    //os ifs vieram primeiro por questão de eficiencia, assim ele é executado apenas uma vez como necessário
    //caso estivesse dentro do for, seria executado cada vez que fosse chamado
    if (!strcmp(nomeArea, "v_ling") == 1){
        for (i; i < quant; i++){
                soma = soma + dadosacertos[i].v_ling;
            }
    }
    else if (!strcmp(nomeArea, "v_mat") == 1){
        for (i; i < quant; i++){
            soma = soma + dadosacertos[i].v_mat;
        }
    }
        
    else if (!strcmp(nomeArea, "v_nat") == 1){
        for (i; i < quant; i++){
            soma = soma + dadosacertos[i].v_nat;
        }
    }
    else{
        for (i; i < quant; i++){
            soma = soma + dadosacertos[i].v_hum;
        }
    }
    //feita a soma, calcula-se e retorna a media correspondente, deve-se salvar em variável na main
    media = soma / quant;
    return media;
} // media implementada, farei outra função apenas para desvio padrão