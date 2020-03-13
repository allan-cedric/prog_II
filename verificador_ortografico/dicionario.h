/* Header file : 'dicionario.h'
   Escrito por : Allan Cedric G.B. Alves da Silva
   Profile : Aluno de graduação do curso de Ciência da Computação (UFPR)
   GRR : 20190351
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
   Estrutura de dados p/ alocar o dicionário
*/
struct dicio_t
{
   char **palavra ;
} ;
typedef struct dicio_t dicio_t ;

/*
   Protótipos de funções de alocação do dicionário
*/
void carrega_dicionario (FILE *arq, dicio_t *d) ;

void aloca_caracteres (dicio_t *d, int tam) ;

void *aloca_dicionario (int tam) ;

void *realoca_dicionario (dicio_t *d, int tam) ;

void desaloca_dicionario (dicio_t *d) ;

void impressao_dicionario (dicio_t *d) ;
