#include <stdio.h>
#include <string.h>
#include <math.h>

struct acertos_notas{
    int insc, v_ling, v_mat, v_nat, v_hum;
    float red;
    float EP[4];// EP guardado de acordo com a sequencias das áreas discutidas anteriormente
    float notaFinal;
}; //apenas para não dar erro, faremos diferente para disposição de todas as funções


//nome area sempre deve corresponder aos nomes começados por v_ no struct, para comparação.
//media é a média da área de conhecimento(ling,mat,nat,hum).
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