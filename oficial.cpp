#include <stdio.h>
#include <stdlib.h>  // malloc, calloc
#include "funcoes.h"
#define MAX 60 //definir um valor


struct tipoCurso{
    char nomeCurso[MAX];    /* nome do curso + bacharel/licenciatura */
    int codCurso, pesoRed, pesoMat, pesoLing, pesoHum, pesoNat;   
};

struct curso{
    int codcurso, qtd;
    dadoEmLinhas *tuplas;
};


struct tipoVaga{
    int codvaga, AC, L1, L3, L4, L5, L7, L8, L9, L11, L13, L15;   
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






int main(){
tipoCurso *curso;
int cont = 0;
int opcao;
int quant; // quantidade total de candidatos
int quantCursos; // quantidade total de cursos
float media[4]; // ling / mat / nat / hum
float desvio[4]; // ling / mat / nat / hum
int soma[4]; // ling / mat / nat / hum
char nomePeso[MAX],nomeVaga[MAX],nomeDados[MAX],nomeAcertos[MAX]; //vai precisar mesmo disso ou vai ler direto?


while (opcao!=0){
  printf("0 - Carregar os arquivos de entrada\n");
  printf("Digite a opcao desejada:");
  scanf("%d", &opcao);  
  }

//if opcao for 0, entrar na leitura
//ler e armazenar cursos e pesos  
printf("\nEscreva o nome do arquivo dos cursos e pesos:");
scanf("%s",nomePeso);
 FILE*  arq;         /* variavel para acessar um arquivo */

    /*abertura de um arquivo*/
    arq = fopen(nomePeso, "r");
    
    /* verificando se arquivo foi aberto */
    if( arq == NULL )
    {
        printf("\n\n Arquivo %s nao pode ser aberto.\n\n", nomePeso);
    }
    else
    {

        fscanf(arq, "%d", &quant);

        curso = (tipoCurso *) malloc(quant * sizeof(tipoCurso));

         if (curso != NULL){

             for(int i=0;i<quant;i++){
             fscanf(arq, "%d %[^0^1^2^3^4^5^6^7^8^9] %d %d %d %d %d", &curso[i].codCurso, curso[i].nomeCurso, &curso[i].pesoRed, &curso[i].pesoMat, &curso[i].pesoLing, &curso[i].pesoHum, &curso[i].pesoNat); //verificar como fazer a leitura do curso
                }
            
         } else{
            printf("Impossível alocar espaço\n");
         }


        
        /*fechamento do arquivo*/
        fclose(arq);
        
    }




//ler e armazenar cursos e vagas
printf("\nEscreva o nome do arquivo dos cursos e vagas:");
scanf("%s",nomeVaga);
tipoVaga *vaga;
    
    /*abertura de um arquivo*/
    arq = fopen(nomeVaga, "r");
    
    /* verificando se arquivo foi aberto */
    if( arq == NULL )
    {
        printf("\n\n Arquivo %s nao pode ser aberto.\n\n", nomeVaga);
    }
    else
    {
        fscanf(arq, "%d", &quant);
  
        vaga = (tipoVaga *) malloc(quant * sizeof(tipoVaga));

         if (vaga != NULL){

             for(int i=0;i<quant;i++){
             fscanf(arq, "%d %d %d %d %d %d %d %d %d %d %d %d", &vaga[i].codvaga, &vaga[i].AC, &vaga[i].L1, &vaga[i].L3, &vaga[i].L4, &vaga[i].L5, &vaga[i].L7, &vaga[i].L8, &vaga[i].L9, &vaga[i].L11, &vaga[i].L13, &vaga[i].L15); //verificar como fazer a leitura do vaga
             }}
            
         else{
            printf("Impossível alocar espaço\n");
         }

       
        
        /*fechamento do arquivo*/     
        fclose(arq);
        
    }
   







//ler e armazenar os dados dos inscritos
printf("\nEscreva o nome do arquivo dos dados dos inscritos:");
scanf("%s",nomeDados);
curso *titulo;
    
    //abertura do arquivo
    arq = fopen(nomeDados,"r");

    if (arq == NULL){
        printf("\n\nO arquivo não pode ser aberto\n\n");
    }


    //executar leitura do arquivo
    else{     
        

        titulo = (curso *) malloc(quant * sizeof(curso));

        for (int i=0;i<quant;i++){ //ler até acabar o arquivo

            fscanf(arq, "%d %d", &titulo[i].codcurso, &titulo[i].qtd); // a primeira linha tem duas entradas

            //alocar memória pra cada bloco            
            titulo[i].tuplas = (dadoEmLinhas *) malloc (titulo[i].qtd * sizeof(dadoEmLinhas)); //aloca dinâmicamente as linhas


            //verificar se alocou
            if (titulo[i].tuplas == NULL){
                printf("Não foi possível alocar na memória");
                break;
            }


            else{
                //executar a leitura dos dados de forma correta para cada bloco;
                int x;
                for (x=0; x < titulo[i].qtd; x++){
                    fscanf(arq, "%d %[^0^1^2^3^4^5^6^7^8^9] %d/%d/%d %[^\n]", &titulo[i].tuplas[x].codinscricao, titulo[i].tuplas[x].nomecandidato, &titulo[i].tuplas[x].datanasc.dia, &titulo[i].tuplas[x].datanasc.mes, &titulo[i].tuplas[x].datanasc.ano, titulo[i].tuplas[x].tipovaga);
                }


                
            }
        }
    }






















printf("\nEscreva o nome do arquivo dos acertos dos inscritos:");
scanf("%s",nomeAcertos);
//void lerAcertos(nomeAcertos);//passar mais argumentos

while(opcao!=5){
       printf("1 - Gerar arquivo de saída .txt\n");
       printf("2 - Pesquisar candidatos .txt\n");
       printf("3 - Gerar arquivo dos candidatos não aprovados\n");
       printf("4 - Alterar nota de redação dos candidatos que entraram com recurso\n");
       printf("5 - Encerrar programa\n");
       printf("Digite a opção desejada:");
       scanf("%d", &opcao);     
}
    

    //um das duas funções suas fica de passar essa quantidade de cursos?
//lerCursosVagas();
//lerCursosPesos();
//lerDados(quantCursos);
//quant = lerAcertos(quant); essa função retorna a quantidade total de candidatos que fizeram a prova

  // calculo da media
/*
media[0] = mediaDaArea(dadosacertos, quant, soma[0]);
media[1] = mediaDaArea(dadosacertos, quant, soma[1]);
media[2] = mediaDaArea(dadosacertos, quant, soma[2]);
media[3] = mediaDaArea(dadosacertos, quant, soma[3]);

  // calculo desvio padrao
desvio[0] = desvioPadrao( media[0], quant, dadosacertos, "v_ling");
desvio[1] = desvioPadrao( media[1], quant, dadosacertos, "v_mat");
desvio[2] = desvioPadrao( media[2], quant, dadosacertos, "v_nat");
desvio[3] = desvioPadrao( media[3], quant, dadosacertos, "v_hum");
  // calculo EP / NF
void eP_NotaFinal( dadosacertos, pesos, quant, media[], desvio[]);
  */     




    
return 0;
}  
  
















    
    
