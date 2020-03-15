/*
  Implementação das funções p/ realizar 
  o trabalho : Verificador Ortográfico simples.
  Ainda está em desenvolvimento.
*/

#include "dicionario.h"

void carrega_dicionario (FILE* arq, dicio_t *d)
{

   d->tam_aloc = MAX_ALOC ;
   d->palavra = aloca_dicionario (d) ;

   if (!d->palavra)
   {
      perror ("Memória insuficiente! - 'aloca_dicionario'") ;
      exit (1) ;
   }

   aloca_caracteres (d, 0) ;

   /* Aloca cada palavra do dicionário */
   int i = 0 ;
   while (fgets (d->palavra[i], 50, arq))
   {
      /* Remove o caractere '\n' lido pelo fgets */
      d->palavra[i][strcspn (d->palavra[i],"\n")] = 0 ;

      /* Limita o índice para não acessar posições de memória desconhecidas */
      if ( i >= d->tam_aloc-1 )
      {
         d->tam_aloc += MAX_ALOC ;
	 d->palavra = realoca_dicionario (d) ;
	 if (!d->palavra)
	 {
	    perror ("Memória insuficiente! - 'realoca_dicionario'") ;
	    exit (1) ;
	 }		
	 aloca_caracteres (d, ++i) ;
      }else
        i++ ;
   }
      
   d->tam_dicio = i ;
			
}

void *aloca_dicionario (dicio_t *d)
{
   return (malloc (sizeof(char *)*(d->tam_aloc))) ;
}

void *realoca_dicionario (dicio_t *d)
{
   return (realloc (d->palavra, sizeof(char *)*(d->tam_aloc))) ;
}

void aloca_caracteres (dicio_t *d ,int ini)
{
   int i ;

   for (i = ini; i < d->tam_aloc; i++)
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
   for (i = 0; i < d->tam_aloc; i++)
      free (d->palavra[i]) ;
   free (d->palavra) ;
}

void impressao_dicionario (dicio_t *d)
{
   int i ;
   for (i = 0; i < d->tam_dicio; i++)
      fprintf (stdout,"%s:%i\n",d->palavra[i],i) ;
}
