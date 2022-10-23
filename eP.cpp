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

void eP_NotaFinal(acertos_notas contagem[],cursoDados dadosNec[], tipoCurso pesos[], int quant, int qtdCursos, float media[], float desvio[]){//quant = quantidade de candidatos
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
    i = 0;
    int aux;
    int j;
    int k;
    for (i; i < qtdCursos; i++){ //percorre todos os cursos, logo, todas as tuplas de cada curso
        for (j=0; j < qtdCursos; j++){ //acha os pesos correspondentes para cada curso 'i'
            aux = 0;
            if (dadosNec[i].codcurso == pesos[j].codCurso){ //indice j para acessar pesos e i para Notafinal
                
                while (aux < dadosNec[i].qtd){ //só permite a leitura até achar o correspondete a cada tupla
                    for (k=0; k < quant; k++){ //para percorrer todos os inscritos
                            if (dadosNec[i].tuplas[aux].codinscricao == contagem[k].insc){ //achou o inscrito
                            
                            //calculo da notaFinal --- add diretamente ao Struct Acerto_notas na posição correspondente
                            contagem[k].notaFinal = (contagem[k].red * pesos[j].pesoRed + contagem[k].EP[3] * pesos[j].pesoHum + contagem[k].EP[0] * pesos[j].pesoLing + contagem[k].EP[1] * pesos[j].pesoMat + contagem[k].EP[2] * pesos[j].pesoNat)/(pesos[j].pesoRed + pesos[j].pesoHum + pesos[j].pesoLing + pesos[j].pesoMat + pesos[j].pesoNat);
                            
                            
                            aux++;//pula pra próxima tupla a ser comparada
                        }
                    }
                }
                j = qtdCursos - 1; //para sair do segundo for na proxima chamada, uma vez que o curso é único
            }
        }
    }



}