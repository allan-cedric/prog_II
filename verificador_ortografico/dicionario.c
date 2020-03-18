/*
  Implementação das funções p/ realizar 
  o trabalho : Verificador Ortográfico simples.
  Ainda está em desenvolvimento.
*/

#include "dicionario.h"

void carrega_dicionario (FILE* arq, dicio_t *d)
{
   d->tam_aloc = MAX_ALOC ;
   d->palavra = aloca_palavras (d) ;

   if (!d->palavra)
   {
      perror ("Memória insuficiente! - 'aloca_palavras'") ;
      exit (1) ;
   }

   aloca_caracteres (d, 0, TAM_PALAVRA) ;

   /* Aloca cada palavra do dicionário */
   int i = 0 ;
   while (fscanf(arq,"%s",d->palavra[i]) != EOF)
   {
      /* Limita o índice para não acessar posições de memória desconhecidas */
      if ( i >= d->tam_aloc-1 )
      {
	 /* Realocação de memória do dicionário */
         d->tam_aloc += MAX_ALOC ;
	 d->palavra = realoca_palavras (d) ;
	 if (!d->palavra)
	 {
	    perror ("Memória insuficiente! - 'realoca_palavras'") ;
	    exit (1) ;
	 }		
	 aloca_caracteres (d, ++i, TAM_PALAVRA) ;
      }else
        i++ ;
   }
      
   d->tam_dicio = i ;
}

void *aloca_palavras (dicio_t *d)
{
   return (malloc (sizeof(unsigned char *)*(d->tam_aloc))) ;
}

void *realoca_palavras (dicio_t *d)
{
   return (realloc (d->palavra, sizeof(unsigned char *)*(d->tam_aloc))) ;
}

void aloca_caracteres (dicio_t *d, int ini, int tam)
{
   int i ;

   for (i = ini; i < d->tam_aloc; i++)
   {
      d->palavra[i] = malloc (sizeof(unsigned char)*(tam+1)) ;

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

int eh_letra (unsigned char ch)
{
   if (ch >= 'A' && ch <= 'Z')
     return 1 ;
   if (ch >= 'a' && ch <= 'z')
     return 1 ;
   if (ch >= 192 && ch <= 221)
     return 1 ;
   if (ch >= 224 && ch <= 253)
     return 1 ;

   return 0 ;
}

int bsearch_dicionario (unsigned char *p, dicio_t *d)
{
   int ini = 0 ;
   int fim = d->tam_dicio - 1 ;
   int meio = (ini+fim)/2 ;
   int valor = ustrcmp (p,d->palavra[meio]) ;

   while ((valor != 0) && (ini <= fim))
   {
      if (valor > 0)
      	ini = meio + 1 ;
      else
	fim = meio - 1 ;

      meio = (ini+fim)/2 ;

      valor = ustrcmp(p,d->palavra[meio]) ;
   }

   if (ini <= fim)
	   return 1 ;
   return 0 ;
}

int ustrcmp (unsigned char *p, unsigned char *p1)
{
   int tam_p = ustrlen (p) ;
   int tam_p1 = ustrlen (p1) ;

   int i ;
   int j ;

   for (i = 0, j = 0; i < tam_p && j < tam_p1; i++, j++)
   {
      if (p[i] < p1[j])
	return -1 ;
      else if (p[i] > p1[j])
	return 1 ;
   }


   if (tam_p < tam_p1)
     return -1 ;	
   if (tam_p > tam_p1)
     return 1 ;

   return 0 ;
}

int ustrlen (unsigned char *p)
{
   int i = 0;
   while (p[i] != '\0')
	i++ ;
   return i ;	
}

unsigned char *minuscula (unsigned char *s)
{
   int i ;
   int tam = ustrlen (s) ;
   for (i = 0; i < tam; i++)
      s[i] = tolower (s[i]) ;
   return s ;
}

void impressao_dicionario (dicio_t *d)
{
   int i ;
   for (i = 0; i < d->tam_dicio; i++)
      fprintf (stdout,"%s:%i\n",d->palavra[i],i) ;
}
