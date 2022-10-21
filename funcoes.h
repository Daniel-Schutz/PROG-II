#define MAX 60

//structs
struct tipoCurso{
    char nomeCurso[MAX];    /* nome do curso + bacharel/licenciatura */
    int codCurso, pesoRed, pesoMat, pesoLing, pesoHum, pesoNat;   
};
struct acertos_notas{
    int insc, v_ling, v_mat, v_nat, v_hum;
    float red;
    float EP[4];// EP guardado de acordo com a sequencias das áreas discutidas anteriormente
    float notaFinal;
}; //apenas para não dar erro, faremos diferente para disposição de todas as funções


// colocar o nome das funções
void lerCursoPesos(tipoCurso curso[]);

void lerDados();

int lerAcertos(acertos_notas dadosacertos[], int *soma); //retorna a qtd de pessoas que fizeram a prova

float desvioPadrao(float media, int quant, acertos_notas dadosacertos[], char nomeArea[7]);

void eP_NotaFinal(acertos_notas dadosacertos[],tipoCurso pesos[], int quant, float media[], float desvio[])