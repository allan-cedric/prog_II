# Verificador ortográfico simples
  * Trabalho da disciplina de Programação II (CI1002)
## Como funciona ?
  * É um programa que verifica se uma dada palavra de um arquivo texto(padrão ISO-8859-1) está presente em um dicionário(nesse caso foi utilizado o arquivo "brazillian").
  
  * Com o dicionário alocado na memória, a busca pela palavra é realizada a partir de um algoritmo de "Busca Binária"
  
  
## Arquivos:
  * header: dicionario.h
      - Protótipo das funções utilizadas
  
  * source: dicionario.c
      - Implementação das funções do arquivo dicionario.h
      
  * source: ortografica.c
      - Implementação do verificador ortográfico
      
  * makefile
      - Na pasta contém um makefile para facilitar na compilação :)
  
  
## Como executar ?
  * No terminal: ./ortografia < arquivo_para_verificar_ortografia.txt
  
  * Lembrando que o arquivo deve estar no padrão ISO-8859-1
  
