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

   int i = 0 ;
   while ( fgets (d->palavra[i], 50, arq) )
   {
      d->palavra[i][strcspn (d->palavra[i],"\n")] = 0 ;
      if ( i < Q_PALAVRAS-1 )
	      i++ ;
   }

   TAM_DICIO = i+1 ;
			
}

void *aloca_dicionario (int tam)
{
   return (malloc (sizeof(char *)*tam)) ;
}

void *realoca_dicionario (dicio_t *d, int tam)
{
   return (realloc (d->palavra, sizeof(char *)*tam)) ;
}

void aloca_caracteres (dicio_t *d ,int ini)
{
   int i ;

   for (i = ini; i < Q_PALAVRAS; i++)
   {
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

void impressao_dicionario (dicio_t *d)
{
	int i ;
	for (i = 0; i < TAM_DICIO; i++)
		fprintf (stdout,"%s\n",d->palavra[i]) ;

}

