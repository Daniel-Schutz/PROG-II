#define MAX 80

//-----------------------------STRUCTS
//AUXILIARES-------------------------------//
struct data {

  int dia, mes, ano;
};

struct tipoAluno {
  char nomecandidato[MAX];
  data datanasc;    // será utilizado para calcular o caso de empate;
  char tipovaga[4]; // no arquivo em questão aparece com letras e números, como
                    // no exemplo dado na DescriçãoTrabalho;
  int codinscricao, v_ling, v_mat, v_nat, v_hum;
  float red;
  float EP[4]; // 0=ling; 1=mat; 2=nat; 3=hum;
  float notaFinal;
  bool presente;
};

//-----------------------------STRUCTS
//PRINCIPAIS-------------------------------//

struct tipoCurso {
  char nomeCurso[MAX]; /* nome do curso + bacharel/licenciatura */
  int codCurso, pesoRed, pesoMat, pesoLing, pesoHum, pesoNat;
  int AC, L1, L3, L4, L5, L7, L8, L9, L11, L13, L15; // quantidade de vagas para cada tipo
   int quantAC, quantL1, quantL3, quantL4, quantL5, quantL7, quantL8, quantL9, quantL11, quantL13, quantL15; 
  int qtd; // quantidade de inscritos por curso;
  tipoAluno *aluno;
};

//-----------------------------FUNÇÕES-------------------------------//
void menu();

void intercalaTipoCurso(int p, int q, int r, tipoCurso *v);

void mergesortTipoCurso(int p, int r, tipoCurso *v);

int busca_binariaTipoCurso(int n, tipoCurso *v, int x);

void intercalaAcertos(int p, int q, int r, tipoAluno *v);

void mergesortAcertos(int p, int r, tipoAluno *v);

void mergesortTipoAluno(int p, int r, tipoAluno *v);

void intercalaTipoAluno(int p, int q, int r, tipoAluno *v);

int busca_binariaAcertos(int n, tipoAluno *v, int x);

float mediaDaArea(float quant, float soma);

float desvioPadrao(float media, int quant, tipoCurso *curso, int num, int qtdAlunos);

void eP_NotaFinal(tipoCurso curso[], int quant, float media[], float desvio[]);

void buscaImprimeCandidato(int numerodecursos, tipoCurso curso[], int codinscr);

void troca(tipoCurso curso[], int indiceTroca, int indiceA_Trocar);

void intercalaAlfabetica(int p, int q, int r, tipoCurso *v);

void mergesortAlfabetica(int p, int r, tipoCurso *v);

void mergesortVaga(int p, int r, tipoCurso v);

void intercalaVaga(int p, int q, int r, tipoCurso v);

void mergesortNota(int p, int r, tipoAluno v);

void intercalaNota(int p, int q, int r, tipoAluno v);

void naoAprovados(int quant, tipoCurso *curso);

void listaParticipantes(int quant, tipoCurso *curso);

tipoAluno verificaEmpate(tipoAluno aluno1, tipoAluno aluno2);

void mergesortReprovados(int p, int r, tipoAluno v);

void intercalaReprovados(int p, int q, int r, tipoAluno v);
