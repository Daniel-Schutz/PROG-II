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

struct curso{ //representa o bloco

    int codcurso, qtd;
    dadoEmLinhas tuplas[70]; //linhas do bloco, limite estipulado

};



int main(){
    FILE *dados;
    char nome[20]; // nome do arquivo
    curso *bloco; // não achei nome melhor / refere-se

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
            
            fscanf(dados, "%d %d", bloco->codcurso, bloco->qtd); // a primeira linha tem duas entradas, vou ajeitar ainda
            
            //alocar memória pra cada bloco              
            bloco = (curso *) malloc (bloco->qtd * syzeof(bloco -> tuplas)); //aloca dinâmicamente apenas as linhas?
                                                                            // ou sizeof(bloco)? tive dúvida
                                                                            // pois na leitura vai ler apenas as linhas


            //verificar se alocou - caso saiba que vai alocar, pule para o else, pra facilitar leitura
            if (bloco == NULL){
                printf("Não foi possível alocar na memória");
            }


            else{
                //executar a leitura dos dados de forma correta para cada bloco;
                int i;
                for (i=0; i<bloco -> qtd; i++){
                    fscanf("%d %s %d/%d/%d %s", &bloco.tuplas[i].codinscricao, bloco.tuplas[i].nomecandidato, &bloco.tuplas[i].dia, &bloco.tuplas[i].mes, &bloco.tuplas[i].ano, bloco.tuplas[i].tipovaga);
                                                    //não sei se ta correta a leitura;
                }
            }
        }
    }

    return 0;
}