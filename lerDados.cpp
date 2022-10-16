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
struct curso{
    int codcurso, qtd;
    dadoEmLinhas *tuplas;
};



int main(){
    FILE *dados;
    char nome[20]; // nome do arquivo
    curso titulo;
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
            fscanf(dados, "%d %d", &titulo.codcurso, &titulo.qtd); // a primeira linha tem duas entradas, vou ajeitar ainda
            
            //alocar memória pra cada bloco              
            titulo.tuplas = (dadoEmLinhas *) malloc (titulo.qtd * sizeof(dadoEmLinhas)); //aloca dinâmicamente apenas as linhas?
                                                                            // ou sizeof(bloco)? tive dúvida
                                                                            // pois na leitura vai ler apenas as linhas


            //verificar se alocou - caso saiba que vai alocar, pule para o else, pra facilitar leitura
            if (titulo.tuplas == NULL){
                printf("Não foi possível alocar na memória");
            }


            else{
                //executar a leitura dos dados de forma correta para cada bloco;
                int i;
                for (i=0; i < titulo.qtd; i++){
                    fscanf(dados, "%d %[^0^1^2^3^4^5^6^7^8^9] %d/%d/%d %[^\n]", &titulo.tuplas[i].codinscricao, titulo.tuplas[i].nomecandidato, &titulo.tuplas[i].datanasc.dia, &titulo.tuplas[i].datanasc.mes, &titulo.tuplas[i].datanasc.ano, titulo.tuplas[i].tipovaga);
                }
            }
        }
    }

    return 0;
}
