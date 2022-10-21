#include <stdio.h>
int cont = 0;
int n;
float mediaLing, mediaMat, mediaNat, mediaHum;
float dpLing, dpMat, dpNat, dpHum;
int soma[4];


//lerCursosVagas();
//lerCursosPesos();
//lerDados(quant);
//lerAcertos(quant);

  // calculo da media
mediaLing = mediaDaArea(dadosacertos, quant, soma[0]);
mediaMat = mediaDaArea(dadosacertos, quant, soma[1]);
mediaNat = mediaDaArea(dadosacertos, quant, soma[2]);
mediaHum = mediaDaArea(dadosacertos, quant, soma[3]);

  // calculo desvio padrao
dpLing = desvioPadrao( mediaLing, quant, dadosacertos, "v_ling");
dpMat = desvioPadrao( mediaMat, quant, dadosacertos, "v_mat");
dpNat = desvioPadrao( mediaNat, quant, dadosacertos, "v_nat");
dpHum = desvioPadrao( mediaHum, quant, dadosacertos, "v_hum");
  // calculo EP / NF


  //fiz um contador pra so na primeira que rodar aparecer a opção 0 (leitura) mas deve ter um jeito melhor
while (n!=5){
  int opcao; //numero que vai por no menu
  if(cont==0){
    printf("\n0 - Carregar os arquivos de entrada");
      /*Carregar os arquivos de entrada: o programa lê os dados dos arquivos de
entrada e os armazena em registros adequadamente. Essa opção deverá ser
executada apenas uma vez. Após ser executada, ela não deverá mais aparecer no
menu*/

    /* ----MENU------ */
    printf("\n1 - Gerar arquivo de saída .txt");
      /*Gerar arquivo de saída contendo as informações dos candidatos ordenados
      crescentemente por nome do curso e dentro de cada curso, listar os
      candidatos ordenados por vaga e de acordo com a vaga, ordenado
       decrescentemente por pontuação. Use um algoritmo de ordenação passado
      em aula. (Exemplo de arquivo de saída: saida1.txt)*/  
      
    printf("\n2 - Pesquisar candidatos .txt");
      /*Imprimir na tela as informações de um candidato (inscrição, nome do
candidato, data de nascimento e curso desejado), cujo número de inscrição é
informado pelo usuário.*/
      
    printf("\n3 - Gerar arquivo dos candidatos não aprovados");
      /*Lista dos candidatos que não passaram no vestibular. Crie um arquivo de
saída contendo os dados, conforme exemplo de arquivo (Exemplo de arquivo
de saída: saida2.txt).*/
      
    printf("\n4 - Alterar nota de redação dos candidatos que entraram com recurso");
      /*Alterar notas da Redação dos candidatos que entraram com recurso. O
usuário informa um nome de arquivo (ex: alteraNotaRedacao.txt), o programa
lê o arquivo e altera a nota de redação dos alunos contidos no arquivo. A
primeira linha do arquivo contém o número de alunos que tiveram a nota da
Redação alterada. A seguir, em cada linha, vem os dados dos alunos
conforme mostrado abaixo*/
    printf("\n5 - Encerrar programa");  
      
    scanf("%d", &opcao);  
  }
  else{
      /* ---MENU--- */
      //menu();
       printf("\n1 - Gerar arquivo de saída .txt");
       printf("\n2 - Pesquisar candidatos .txt");
       printf("\n3 - Gerar arquivo dos candidatos não aprovados");
       printf("\n4 - Alterar nota de redação dos candidatos que entraram com recurso");
       printf("\n5 - Encerrar programa");
       scanf("%d", &opcao);     
    
  
  
  }
  cont++;
}
