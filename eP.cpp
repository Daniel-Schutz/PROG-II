#include <stdio.h>
#include <string.h>
#define MAX 60 //esse max ta certo? peguei do seu código
struct tipoCurso{
    char nomeCurso[MAX];    /* nome do curso + bacharel/licenciatura */
    int codCurso, pesoRed, pesoMat, pesoLing, pesoHum, pesoNat;   
};
struct data{

    int dia, mes, ano;

};

struct dadoEmLinhas{ //precisaria criar um vetor de registro;

    int codinscricao; // referente ao participante;
    char nomecandidato[MAX]; 
    data datanasc; // será utilizado para calcular o caso de empate;
    char tipovaga[5]; // no arquivo em questão aparece com letras e números, como no exemplo dado na DescriçãoTrabalho;

};

struct cursoDados{
    int codcurso, qtd;
    dadoEmLinhas *tuplas;
};
struct acertos_notas{
    int insc, v_ling, v_mat, v_nat, v_hum;
    float red;
    float EP[4];// EP guardado de acordo com a sequencias das áreas discutidas anteriormente
    float notaFinal;
};

void eP_NotaFinal(acertos_notas contagem[],tipoCurso pesos[], int quant, float media[], float desvio[]){
    int i = 0;
    for (i; i < quant; i++){
        contagem[i].EP[0] = 500 + 100*((2*contagem[i].v_ling - media[0])/desvio[0]);
        contagem[i].EP[1] = 500 + 100*((2*contagem[i].v_mat - media[1])/desvio[1]);
        contagem[i].EP[2] = 500 + 100*((2*contagem[i].v_nat - media[2])/desvio[2]);
        contagem[i].EP[3] = 500 + 100*((2*contagem[i].v_hum - media[3])/desvio[3]);

        // Pro calculo da notaFinal, aqui ainda ta errado, pois precisamos procurar por codcurso pra definir o peso
        // Vou precisar de ajudar pra entender como ta seu código, aqui a gente precisa fazer junto
        contagem[i].notaFinal = (contagem[i].red * pesos[i].pesoRed + contagem[i].EP[3] * pesos[i].pesoHum + contagem[i].EP[0] * pesos[i].pesoLing + contagem[i].EP[1] * pesos[i].pesoMat + contagem[i].EP[2] * pesos[i].pesoNat)/(pesos[i].pesoRed + pesos[i].pesoHum + pesos[i].pesoLing + pesos[i].pesoMat + pesos[i].pesoNat);
    }
}