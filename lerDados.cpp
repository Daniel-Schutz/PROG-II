#include <stdio.h>
#include <stdlib.h>
#define MAX 80 //nome do candidato
struct data{

    int dia, mes, ano;

};

struct dadoEmLinhas{ //precisaria criar um vetor de registro;

    int codinscricao; // referente ao participante;
    char nomecandidato[MAX]; 
    data datanasc; // será utilizado para calcular o caso de empate;
    char tipovaga[5]; // no arquivo em questão aparece com letras e números, como no exemplo dado na DescriçãoTrabalho;

};



int main(){
    FILE *dados;
    char nome[20]; // nome do arquivo
    dadoEmLinhas *bloco; // não achei nome melhor / refere-se
    int codcurso, qtd;
    printf("Digite o nome do arquivo: ");
    scanf(" %s", nome);
    
    //abertura do arquivo
    dados = fopen(nome,"r");

    if (dados == NULL){
        printf("\n\nO arquivo não pode ser aberto\n\n");
    }


    //executar leitura do arquivo

    else{//a leitura deste arquivo provavelmente será diferente da forma atual

        printf("\n\nO arquivo foi aberto!\n\n");

        while (feof(dados)==0){ //ler até acabar o arquivo
            fscanf(dados, "%d %d", &codcurso, &qtd); // a primeira linha tem duas entradas, vou ajeitar ainda
            
            //alocar memória pra cada bloco              
            bloco = (dadoEmLinhas *) malloc (qtd * sizeof(dadoEmLinhas)); //aloca dinâmicamente apenas as linhas?
                                                                            // ou sizeof(bloco)? tive dúvida
                                                                            // pois na leitura vai ler apenas as linhas


            //verificar se alocou - caso saiba que vai alocar, pule para o else, pra facilitar leitura
            if (bloco == NULL){
                printf("Não foi possível alocar na memória");
            }


            else{
                //executar a leitura dos dados de forma correta para cada bloco;
                int i;
                for (i=0; i < qtd; i++){
                    fscanf(dados, "%d %s %d/%d/%d %s", &bloco[i].codinscricao, bloco[i].nomecandidato, &bloco[i].datanasc.dia, &bloco[i].datanasc.mes, &bloco[i].datanasc.ano, bloco[i].tipovaga);
                                                    //não sei se ta correta a leitura;
                }
            }
        }
    }

    return 0;
}