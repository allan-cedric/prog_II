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
	unsigned char palavra[50] ;
	unsigned char palavra_aux[50] ;
	int i ;

	ch = getchar () ;
	while (!feof(stdin))
	{
		while (!eh_letra(ch) && !feof(stdin))
		{
			fprintf (stdout,"%c",ch) ;
			ch = getchar () ;
		}

		i = 0 ;
		while (eh_letra(ch) && !feof(stdin))
		{
			palavra[i] = ch ;
			palavra_aux[i++] = ch ;
			ch = getchar () ;
		}
		palavra[i] = '\0' ;
		palavra_aux[i] = '\0' ;

		if (!feof(stdin))
		{
			if (bsearch_dicionario (minuscula(palavra_aux, 50),&dicionario))
				fprintf (stdout,"%s",palavra) ;
			else
				fprintf (stdout,"[%s]",palavra) ;
		}
	}			
   
   /* Desalocação do dicionário carregado */
   desaloca_dicionario (&dicionario) ;

   fclose (arq) ;

   return 0 ;
}
