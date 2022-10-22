#define MAX 60

//structs

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

struct tipoVaga{
    int codvaga, AC, L1, L3, L4, L5, L7, L8, L9, L11, L13, L15;   
};

struct acertos_notas{

    int insc, v_ling, v_mat, v_nat, v_hum;
    float red;
    float EP[4];// EP guardado de acordo com a sequencias das áreas discutidas anteriormente
    float notaFinal;
};


float mediaDaArea(int quant, int soma);

float desvioPadrao(float media, int quant, acertos_notas contagem[], char nomeArea[7]);

void eP_NotaFinal(acertos_notas contagem[],tipoCurso pesos[], int quant, float media[], float desvio[]);

void menu();