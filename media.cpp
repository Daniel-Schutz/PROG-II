#include <stdio.h>
#include <string.h>
struct acertos{
    int insc, v_ling, v_mat, v_nat, v_hum;
    float red;
}; //Botei aqui por enquanto so pra ter a base direito e pra não dar erro

//dadosacertos deve ser um vetor
float mediaDaArea(acertos dadosacertos[], int quant, int soma){ //passar valor correspondente a soma da materia no parametro

    float media; //variável q será retornada
    media = 2*(soma / quant); // precisa multiplicar por dois para receber o valor correto do EP
    return media;
} // media implementada, farei outra função apenas para desvio padrão