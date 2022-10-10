#include <stdio.h>
int cont = 0;
  //fiz um contador pra so na primeira que rodar aparecer a opção 0 (leitura) mas deve ter um jeito melhor
while (n!=5){
  int opcao; //numero que vai por no menu
  if(cont==0){
    printf("0 - Carregar os arquivos de entrada")
      /*Carregar os arquivos de entrada: o programa lê os dados dos arquivos de
entrada e os armazena em registros adequadamente. Essa opção deverá ser
executada apenas uma vez. Após ser executada, ela não deverá mais aparecer no
menu*/
      
    printf("1 - Gerar arquivo de saída .txt");
      /*Gerar arquivo de saída contendo as informações dos candidatos ordenados
      crescentemente por nome do curso e dentro de cada curso, listar os
      candidatos ordenados por vaga e de acordo com a vaga, ordenado
       decrescentemente por pontuação. Use um algoritmo de ordenação passado
      em aula. (Exemplo de arquivo de saída: saida1.txt)*/  
      
    printf("2 - Pesquisar candidatos .txt");
      /*Imprimir na tela as informações de um candidato (inscrição, nome do
candidato, data de nascimento e curso desejado), cujo número de inscrição é
informado pelo usuário.*/
      
    printf("3 - Gerar arquivo dos candidatos não aprovados");
      /*Lista dos candidatos que não passaram no vestibular. Crie um arquivo de
saída contendo os dados, conforme exemplo de arquivo (Exemplo de arquivo
de saída: saida2.txt).*/
      
    printf("4 - Alterar nota de redação dos candidatos que entraram com recurso");
      /*Alterar notas da Redação dos candidatos que entraram com recurso. O
usuário informa um nome de arquivo (ex: alteraNotaRedacao.txt), o programa
lê o arquivo e altera a nota de redação dos alunos contidos no arquivo. A
primeira linha do arquivo contém o número de alunos que tiveram a nota da
Redação alterada. A seguir, em cada linha, vem os dados dos alunos
conforme mostrado abaixo*/
    printf("5 - Encerrar programa");  
      
    scanf("%d",opcao);  
  }
  else{
       printf("1 - Gerar arquivo de saída .txt");
       printf("2 - Pesquisar candidatos .txt");
       printf("3 - Gerar arquivo dos candidatos não aprovados");
       printf("4 - Alterar nota de redação dos candidatos que entraram com recurso");
       printf("5 - Encerrar programa");
       scanf("%d",opcao);     
    
  
  
  }
  cont++;
}
