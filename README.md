## Verificador ortográfico simples
  * Trabalho da disciplina de Programação II (CI1002)
  
### Como funciona ?
  * É um programa que verifica se uma dada palavra de um arquivo texto (padrão ISO-8859-1) está presente em um dicionário (arquivo "brazillian").
  
  * Com o dicionário alocado na memória, a busca pela palavra é realizada a partir de um algoritmo de "Busca Binária". 
  * Se a palavra estiver no dicionário se imprime a palavra original na STDOUT (saída padrão), senão imprime a palavra entre colchetes [ ].
  
### Arquivos:
  * header: dicionario.h
      - Protótipos das funções utilizadas.
  
  * source: dicionario.c
      - Implementação das funções do arquivo dicionario.h.
      
  * source: ortografia.c
      - Implementação do verificador ortográfico.
      
  * makefile
      - Na pasta contém um makefile para facilitar na compilação. :)
      
### Compilação:
  * No terminal: make
  * Para retirar os arquivos objeto: make clean
  
### Como executar ?
  * No terminal: ./ortografia < arquivo_para_verificar_ortografia.txt
  
  * Lembrando que o arquivo deve estar no padrão ISO-8859-1.
