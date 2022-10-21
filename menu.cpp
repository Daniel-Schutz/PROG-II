#include <stdio.h>


void menu(){
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
}