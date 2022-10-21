#define MAX 60

//structs

struct tipoCurso{
    char nomeCurso[MAX];    /* nome do curso + bacharel/licenciatura */
    int codCurso, pesoRed, pesoMat, pesoLing, pesoHum, pesoNat;   
};

struct tipoVaga{
    int codvaga, AC, L1, L3, L4, L5, L7, L8, L9, L11, L13, L15;   
};

struct data{

    int dia, mes, ano;

};
struct dadoEmLinhas{

    int codinscricao; // referente ao participante;
    char nomecandidato[MAX]; 
    data datanasc; // será utilizado para calcular o caso de empate;
    char tipovaga[5]; // no arquivo em questão aparece com letras e números, como no exemplo dado na DescriçãoTrabalho;

};
struct curso{
    int codcurso, qtd;
    dadoEmLinhas *tuplas;
};

struct acertos_notas{
    int insc, v_ling, v_mat, v_nat, v_hum;
    float red;
    float EP[4];// EP guardado de acordo com a sequencias das áreas discutidas anteriormente
    float notaFinal;
}; //apenas para não dar erro, faremos diferente para disposição de todas as funções


// colocar o nome das funções
void lerCursoPesos(tipoCurso curso[]);

//função referente a CursosVagas aqui

void lerDados(int quant); //falta definir qual função ira retornar o valor de quantCursos pra essa

int lerAcertos(acertos_notas dadosacertos[], int *soma); //retorna a qtd de pessoas que fizeram a prova

float mediaDaArea(acertos_notas dadosacertos[], int quant, int soma);

float desvioPadrao(float media, int quant, acertos_notas dadosacertos[], char nomeArea[7]);

void eP_NotaFinal(acertos_notas dadosacertos[],tipoCurso pesos[], int quant, float media[], float desvio[]);

void menu();