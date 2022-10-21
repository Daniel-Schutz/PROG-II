#include <stdio.h>
#include <string.h>
#define MAX 60 //esse max ta certo? peguei do seu código
struct tipoCurso{
    char nomeCurso[MAX];    /* nome do curso + bacharel/licenciatura */
    int codCurso, pesoRed, pesoMat, pesoLing, pesoHum, pesoNat;   
};
struct acertos_notas{
    int insc, v_ling, v_mat, v_nat, v_hum;
    float red;
    float EP[4];// EP guardado de acordo com a sequencias das áreas discutidas anteriormente
    float notaFinal;
};

void eP_NotaFinal(acertos_notas dadosacertos[],tipoCurso pesos[], int quant, float media[], float desvio[]){
    int i = 0;
    for (i; i < quant; i++){
        dadosacertos[i].EP[0] = 500 + 100*((2*dadosacertos[i].v_ling - media[0])/desvio[0]);
        dadosacertos[i].EP[1] = 500 + 100*((2*dadosacertos[i].v_mat - media[1])/desvio[1]);
        dadosacertos[i].EP[2] = 500 + 100*((2*dadosacertos[i].v_nat - media[2])/desvio[2]);
        dadosacertos[i].EP[3] = 500 + 100*((2*dadosacertos[i].v_hum - media[3])/desvio[3]);

        dadosacertos[i].notaFinal = (dadosacertos[i].red * pesos[i].pesoRed + dadosacertos[i].EP[3] * pesos[i].pesoHum + dadosacertos[i].EP[0] * pesos[i].pesoLing + dadosacertos[i].EP[1] * pesos[i].pesoMat + dadosacertos[i].EP[2] * pesos[i].pesoNat)/(pesos[i].pesoRed + pesos[i].pesoHum + pesos[i].pesoLing + pesos[i].pesoMat + pesos[i].pesoNat);
    }
}