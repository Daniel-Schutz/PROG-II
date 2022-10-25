#define MAX 60

//structs

struct tipoCurso{ //vamos ordenar por cod curso ---- planejo colocar esse struct dentro de outro Struct junto a cursoDados para evitar o retrabalho
    char nomeCurso[MAX];    /* nome do curso + bacharel/licenciatura */
    int codCurso, pesoRed, pesoMat, pesoLing, pesoHum, pesoNat;
    int AC, L1, L3, L4, L5, L7, L8, L9, L11, L13, L15;   
    int qtd;
    dadoEmLinhas *tuplas;//melhor por diretamente aqui
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

struct cursoDados{ //vamos ordenar por codcurso
    int codcurso, qtd;
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

float desvioPadrao(float media, int quant, acertos_notas *contagem, char nomeArea[7]);

void eP_NotaFinal(acertos_notas contagem[],cursoDados dadosNec[], tipoCurso pesos[], int quant, int qtdCursos, float media[], float desvio[]);

void menu();

void intercalaTipoCurso(int p, int q, int r, tipoCurso *v);

void mergesortTipoCurso(int p, int r, tipoCurso *v);

void intercalaTipoVaga(int p, int q, int r, tipoVaga *v);

void mergesortTipoVaga(int p, int r, tipoVaga *v);

int busca_binariaTipoCurso(int n, tipoCurso *v, int x);