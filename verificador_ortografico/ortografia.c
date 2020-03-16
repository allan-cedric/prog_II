#include "dicionario.h"

int main ()
{

   /* Locale */
   char *locale = setlocale (LC_CTYPE,"pt_BR.ISO-8859-1") ;
   if (!locale)
   {
      perror ("Erro ao especificar a locale!") ;
      exit (1) ;	
   } 

   /* Alocação dinâmica do dicionário */
   FILE* arq ;
   dicio_t dicionario ;

   arq = fopen ("/home/bcc/acgbas19/usr/share/dict/brazilian","r") ;
   if (!arq)
   {
      perror ("Erro ao abrir o arquivo!") ;
      exit (1) ;
   }

   carrega_dicionario (arq, &dicionario) ;

   /* Verificador ortográfico simples */
   unsigned char ch ;
   unsigned char palavra[TAM_PALAVRA+1] ;
   unsigned char palavra_aux[TAM_PALAVRA+1] ;
   int i ;

   ch = getchar () ;
   while (!feof(stdin))
   {
      /* Impressão de caracteres (não-letras) */
      while (!eh_letra(ch) && !feof(stdin))
      {
         printf ("%c",ch) ;
	 ch = getchar () ;
      }

      i = 0 ;
      /* Armazenamento de uma palavra (composta por letras) */
      while (eh_letra(ch) && !feof(stdin))
      {
	 palavra[i] = ch ;
	 palavra_aux[i++] = ch ;
         ch = getchar () ;
      }
      palavra[i] = '\0' ;
      palavra_aux[i] = '\0' ;

      /* Busca binária no dicionário */ 
      if (!feof(stdin))
      {
         if (bsearch_dicionario (minuscula(palavra_aux),&dicionario))
	   printf ("%s",palavra) ;
	 else
         {
            palavra_aux[0] = toupper (palavra_aux[0]) ;
	    if (bsearch_dicionario (palavra_aux, &dicionario))
	      printf ("%s",palavra) ;
	    else
	      printf ("[%s]",palavra) ;
	 }
      }
   }
   
   /* Desalocação do dicionário carregado */
   desaloca_dicionario (&dicionario) ;
   fclose (arq) ;

   return 0 ;
}
