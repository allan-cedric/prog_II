/*
  Implementação das funções p/ realizar 
  o trabalho : Verificador Ortográfico simples.
  Ainda está em desenvolvimento.
*/

#include "dicionario.h"

/*
   Variáveis globais
*/
int Q_PALAVRAS = 275502 ;
int TAM_DICIO = 0 ;

void carrega_dicionario (FILE* arq, dicio_t *d)
{

   d->palavra = aloca_dicionario (Q_PALAVRAS) ;
   if (!d->palavra)
   {
     perror ("Memória insuficiente! - 'aloca_dicionario'") ;
     exit (1) ;
   }

   aloca_caracteres (d, 0) ;

   /* Aloca cada palavra do dicionário */
   int i = 0 ;
   while ( fgets (d->palavra[i], 50, arq) )
   {
      /* Remove o caractere '\n' lido pelo fgets */   
      d->palavra[i][strcspn (d->palavra[i],"\n")] = 0 ;

      /* Limita o índice para não acessar posições de memória desconhecidas */
      if ( i < Q_PALAVRAS-1 )
	      i++ ;
   }

   TAM_DICIO = i+1 ;
			
}

void *aloca_dicionario (int tam)
{
   return (malloc (sizeof(char *)*tam)) ;
}

/* Em testes */
void *realoca_dicionario (dicio_t *d, int tam)
{
   return (realloc (d->palavra, sizeof(char *)*tam)) ;
}

void aloca_caracteres (dicio_t *d ,int ini)
{
   int i ;

   for (i = ini; i < Q_PALAVRAS; i++)
   {
      /* Margem segura de 50 caracteres p/ cada palavra*/
      d->palavra[i] = malloc (sizeof(char)*50) ;

      if (!d->palavra[i])
      {
	 perror ("Memória insuficiente! - 'aloca_caracteres'") ;
	 exit (1) ;
      }
   }
}

void desaloca_dicionario (dicio_t *d)
{
   int i ;
   for (i = 0; i < TAM_DICIO; i++)
      free (d->palavra[i]) ;
   free (d->palavra) ;
}

/* Função teste */
void impressao_dicionario (dicio_t *d)
{
	int i ;
	for (i = 0; i < TAM_DICIO; i++)
		fprintf (stdout,"%s\n",d->palavra[i]) ;

}

