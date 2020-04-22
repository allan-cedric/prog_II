/* 
   Header file : 'dicionario.h'
   Escrito por : Allan Cedric G.B. Alves da Silva, desde 12/03/2020
   Profile : Aluno de graduação do curso de Ciência da Computação (UFPR)
   GRR : 20190351
*/

#ifndef __DICIONARIO_H__
#define __DICIONARIO_H__

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

/*
  Defines
*/
#define MAX_ALOC 20000
#define TAM_PALAVRA 50

/*
   Estrutura de dados p/ alocar o dicionário
*/
struct dicio_t
{
  unsigned char **palavra;
  int tam_dicio; /* Número de palavras */
  int tam_aloc;  /* Quantidade de alocações */
};
typedef struct dicio_t dicio_t;

/*
   Protótipos de funções de alocação do dicionário
*/
void carrega_dicionario(FILE *arq, dicio_t *d);

void *aloca_palavras(dicio_t *d);

void *realoca_palavras(dicio_t *d);

void aloca_caracteres(dicio_t *d, int ini, int tam);

void desaloca_dicionario(dicio_t *d);

/*
  Protótipos de funções de identificação de caracteres
  e de busca no dicionário
*/
int eh_letra(unsigned char ch);

int bsearch_dicionario(unsigned char *p, dicio_t *d);

/* (UNSIGNED) Verifica se a string *p é maior, menor ou igual a string *p1 (Ordem lexicográfica) */
int ustrcmp(unsigned char *p, unsigned char *p1);

/* (UNSIGNED) Tamanho da string *p */
int ustrlen(unsigned char *p);

/*
  Protótipos de funções de alteração de caracteres
*/
unsigned char *minuscula(unsigned char *s);

/*
  Função teste de impressão
*/
void impressao_dicionario(dicio_t *d);

#endif
