#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define QTD_TERRITORIOS 5
#define TAM_STR_NOME 30
#define TAM_STR_COR 10

struct Territorio {
	char nome[TAM_STR_NOME];
	char cor[TAM_STR_COR];
	int tropas;
};


void limparBufferEntrada(){
	int c;
	while((c = getchar()) != '\n' && c != EOF);
}

int main(){
	int indice = 0;

	struct Territorio territorios[QTD_TERRITORIOS];

	printf("----------                 NOVATO                    -------\n\n");
	printf("--- Vamos cadastrar os territorios inciais do nosso mundo.---\n\n");

	for(indice = 0; indice < QTD_TERRITORIOS; indice++){

		printf("--- Cadastrando Territorio %d ---\n", indice + 1);

		printf("Nome do Territorio: ");
		fgets(territorios[indice].nome, TAM_STR_NOME, stdin);

		printf("Cor do Exercito: ");
		fgets(territorios[indice].cor, TAM_STR_COR, stdin);

		printf("Numero de Tropas: ");
		scanf("%d", &territorios[indice].tropas);

		territorios[indice].nome[strcspn(territorios[indice].nome, "\n")] = '\0';
		territorios[indice].cor[strcspn(territorios[indice].cor, "\n")] = '\0';
		
		limparBufferEntrada();
		printf("\n");
	}

	printf("Cadastro inicial concludo com sucesso!");

	printf("\n\n======================================================\n");
	printf("	MAPA DO MUNDO - ESTADO ATUAL \n");
	printf("======================================================\n\n");
	
	for(indice = 0; indice < QTD_TERRITORIOS; indice++){
		printf("%d. %s (Exercito %s, Tropas: %d)\n", indice + 1, territorios[indice].nome,territorios[indice].cor, territorios[indice].tropas);
	}

	printf("\n\n");

	return 0;
}