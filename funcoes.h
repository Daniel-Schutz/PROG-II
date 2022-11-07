#define MAX 80

//-----------------------------STRUCTS AUXILIARES-------------------------------//
struct data{

    int dia, mes, ano;

};

struct dadoEmLinhas{ 

    int codinscricao; // referente ao participante;
    char nomecandidato[MAX]; 
    data datanasc; // será utilizado para calcular o caso de empate;
    char tipovaga[5]; // no arquivo em questão aparece com letras e números, como no exemplo dado na DescriçãoTrabalho;

};


//-----------------------------STRUCTS PRINCIPAIS-------------------------------//

struct tipoCurso{ 
    char nomeCurso[MAX];    /* nome do curso + bacharel/licenciatura */
    int codCurso, pesoRed, pesoMat, pesoLing, pesoHum, pesoNat;
    int AC, L1, L3, L4, L5, L7, L8, L9, L11, L13, L15;//quantidade de vagas para cada tipo  
    int qtd; // quantidade de inscritos por curso;
    dadoEmLinhas *tuplas;//dados dos inscritos
};

struct acertos_notas{

    int insc,v_ling, v_mat, v_nat, v_hum;
    float red;
    float EP[4];// 0=ling; 1=mat; 2=nat; 3=hum;
    float notaFinal;
};

//-----------------------------FUNÇÕES-------------------------------//
void menu();

void intercalaTipoCurso(int p, int q, int r, tipoCurso *v);

void mergesortTipoCurso(int p, int r, tipoCurso *v);

int busca_binariaTipoCurso(int n, tipoCurso *v, int x);

void intercalaAcertos(int p, int q, int r, acertos_notas *v);

void mergesortAcertos(int p, int r, acertos_notas *v);

int busca_binariaAcertos(int n, acertos_notas *v, int x);

float mediaDaArea(float quant, float soma);

float desvioPadrao(float media, int quant, acertos_notas *contagem, int num);

void eP_NotaFinal(acertos_notas contagem[], tipoCurso curso[], int quant, int qtdCursos, float media[], float desvio[]);

void buscaImprimeCandidato(int numerodecursos, tipoCurso curso[], int codinscr);

void troca(tipoCurso curso[], int indiceTroca, int indiceA_Trocar);

void verificaEmpate();

void intercalaAlfabetica(int p, int q, int r, tipoCurso *v);

void mergesortAlfabetica(int p, int r, tipoCurso *v);

void mergesortVaga(int p, int r, tipoCurso v);

void intercalaVaga(int p, int q, int r, tipoCurso v);


