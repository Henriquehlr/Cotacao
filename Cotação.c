#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

 //ESTRUTA PARA  PRODUTOS.
 typedef struct Produtos{
	
      
     char nomeproduto[999][998]; 
     char descricaoproduto[999][998];      
     int codigobarras; 
     int quantunidades;
     float valor;
    }prod;
 
//ESTRUTURA PARA CADASTRO COTAÇÃO.    
typedef struct cadastroCotacao{
	char nomeFornecedor[50];
	char nomeRepresentante[50];
	char dataValidade[10];
	int quantProdutos;
	prod *produtos;
	
}cotacao;

	
int main(){
	char nomeusuario[50];
    int senha;
    FILE *arq;
    cotacao a[20];
	int i,j, cont=0;
	float soma = 0;
	char pergunta = 's';
	
	printf("USUARIO: ");
	 scanf("%s", &nomeusuario);
	  fflush(stdin);
	
	printf("SENHA: ");
	 scanf("%i", &senha); 
	 

	while ((pergunta == 's') || (pergunta == 'S')){ 
	system("cls");
          
	printf("SEJA BEM VINDO AO SISTEMA DE COTACAO: %s\n", nomeusuario);
	 fflush(stdin);

	printf("\nFORNECEDOR: ");
	 scanf("%[^\n]s", &a[cont].nomeFornecedor);
	 fflush(stdin);

    printf("\nREPRESENTANTE: ");
	 scanf("%[^\n]s", &a[cont].nomeRepresentante); 
	 fflush(stdin);

	printf("\nDATA VALIDADE DA COTACAO: ");
	 scanf("%s", &a[cont].dataValidade);
	 fflush(stdin);

	printf("\nQUANTIDADE DE PRODUTOS QUE VOCE DESEJA COTAR: ");
	 scanf("%i", &a[cont].quantProdutos); 
	 fflush(stdin);
	 
	// a[cont].produtos=(a[cont].quantProdutos * sizeof(prod));
	 a[cont].produtos=malloc(a[cont].quantProdutos * sizeof(prod));
	 
	 system("cls");
	
	
	for(i=0 ; i<a[cont].quantProdutos; i++){
	 	
		 printf("%i-NOME PRODUTO: ", i+1);
	 	  scanf("%s", &a[cont].produtos[i].nomeproduto);
	 	  fflush(stdin);
	 	  
	     printf("DESCRICAO PRODUTO(OPCIONALMENTE): "); 
		 scanf("%s", &a[cont].produtos[i].descricaoproduto); 
	 	 fflush(stdin);
	 	 
		 printf("CODIGO DE BARRAS: ");
		 scanf("%i", &a[cont].produtos[i].codigobarras);
		 fflush(stdin);
		 
		 printf("Unidades: ");
		  scanf("%i", &a[cont].produtos[i].quantunidades);
		 
		 printf("VALOR: ");
		 scanf("%f", &a[cont].produtos[i].valor);
		 fflush(stdin);
		 
		
		 soma = soma + a[cont].produtos[i].valor * a[cont].produtos[i].quantunidades;
	 	
	}
	
	system("cls");
	
	printf("Fonecedor: %s\n",a[cont].nomeFornecedor);			
	printf("Representante: %s\n", a[cont].nomeRepresentante);
	printf("Data de validade: %s\n",a[cont].dataValidade);
	printf("Quantidade de produtos cotados: %i",a[cont].quantProdutos);
	
	for(i=0 ; i<a[cont].quantProdutos; i++){	 
	     printf("\nProduto: %s\n", a[cont].produtos[i].nomeproduto);
	     printf("Descricao do produto: %s\n", a[cont].produtos[i].descricaoproduto);
	     printf("Codigo de barras: %i\n", a[cont].produtos[i].codigobarras);
	     printf("Unidades: %i\n", a[cont].produtos[i].quantunidades);	
	}
 
	printf("\n\nValor total da cotacao: %.2f\n", soma);
  
	printf("\nDESEJA ADICIONAR UMA NOVA COTACAO S/N? ");
	scanf("%c", &pergunta);
	cont++;
}


	system("cls");

	  //ARQUIVO PARA SALVAR AS COTAÇÕES.
	 
	  arq = fopen("ArquivoCotacao.txt", "wt");  
	  if (arq == NULL) 
	  {
	     printf("Problemas na CRIACAO do arquivo\n");
	     return;
	  }
     fprintf(arq,"Lista de Cotacao:\n\n");
	printf("Lista de Cotacao:\n\n");
	 for(j=0 ; j<cont ; j++){
	 		
	 		printf("Fornecedor: %s\n",a[j].nomeFornecedor);	 		
	 		printf("Representante: %s\n", a[j].nomeRepresentante);
	 		printf("Data de validade: %s\n",a[j].dataValidade);
	 		printf("Quantidade de produtos cotados: %i",a[j].quantProdutos);
	 		
	 		fprintf(arq,"Fornecedor: %s",a[j].nomeFornecedor);
	 		fprintf(arq,"Representante: %s", a[j].nomeRepresentante);
	 		fprintf(arq,"Data de validade: %s\n",a[j].dataValidade);
	 		fprintf(arq,"Quantidade de produtos cotados: %i\n",a[j].quantProdutos);
	 	
	 		for(i=0 ; i<a[j].quantProdutos; i++){
			 
			 printf("\nProduto: %s\n", a[j].produtos[i].nomeproduto);
		     printf("Descricao do produto: %s\n", a[j].produtos[i].descricaoproduto);
		     printf("Codigo de barras: %i\n", a[j].produtos[i].codigobarras);
		     printf("Unidades: %i\n", a[j].produtos[i].quantunidades);
			 	 
		     fprintf(arq,"Produto: %[^\n]s\n", a[j].produtos[i].nomeproduto);
		   	 fprintf(arq,"Descricao do produto: %s\n", a[j].produtos[i].descricaoproduto);
		   	 fprintf(arq,"Codigo de barras: %i\n", a[j].produtos[i].codigobarras);
		     fprintf(arq,"Unidades: %i\n\n", a[j].produtos[i].quantunidades); 	
	  		}
			free (a[j].produtos);
		 	printf("---------------------------------------------------\n");
		 	fprintf(arq,"---------------------------------------------------\n");
	 }
	printf("\nValor total da cotacao: %.2f\n", soma);
	fprintf(arq,"\nValor total da cotacao: %.2f\n", soma); 
	 
	system("pause>>null"); 
	return 0;
}
