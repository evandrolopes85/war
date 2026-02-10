#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

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

void atacar(struct Territorio *atacante, struct Territorio *defensor){
	int dadoAtacante = (rand() % QTD_TERRITORIOS) + 1;
	int dadoDefensor = (rand() % QTD_TERRITORIOS) + 1;

	printf("\n\t --- RESULTADO DA BATALHA ---\n");
	printf("O atacando %s rolou um dado e tirou: %d\n", atacante->nome, dadoAtacante);
	printf("O defensor %s rolou um dado e tirou: %d\n", defensor->nome, dadoDefensor);

	if(dadoAtacante > dadoDefensor){
		printf("VITORIA DO ATACANTE! O defensor perdeu 1 tropa.\n");
		defensor->tropas--;
		if(defensor->tropas == 0 ){
			printf("CONQUISTA! O terrirotorio %s foi dominado pelo exercito %s\n", defensor->nome, atacante->cor);
			strcpy(defensor->cor, atacante->cor);
			defensor->tropas++; 
		}
	}else {
		printf("VITORIA DO DEFENSOR! O atacante perdeu 1 tropa\n");
		atacante->tropas--;
		if(atacante->tropas == 0 ){
			printf("CONQUISTA! O terrirotorio %s foi dominado pelo exercito %s\n", atacante->nome, defensor->cor);
			strcpy(atacante->cor,defensor->cor);
			atacante->tropas++;
		}
	}

	printf("Pressione Enter para continuar para o proximo turno...");
	getchar();
}

void exibirMapa(struct Territorio *territorios){
	int indice = 0;

	printf("\n\n======================================================\n");
	printf("	MAPA DO MUNDO - ESTADO ATUAL \n");
	printf("======================================================\n\n");

	for(indice = 0; indice < QTD_TERRITORIOS; indice++){
		printf("%d. %s (Exercito %s, Tropas: %d)\n", indice + 1, territorios[indice].nome,territorios[indice].cor, territorios[indice].tropas);
	}
}

void liberarMemoria(struct Territorio *territorios){
	free(territorios);
	printf("\n--- Memoria liberada ---\n");
}

int main(){
	int indice = 0;

	struct Territorio *territorios;

	territorios = (struct Territorio *) malloc(QTD_TERRITORIOS * sizeof(struct Territorio));

	srand(time(NULL));

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

	// printf("\n\n======================================================\n");
	// printf("	MAPA DO MUNDO - ESTADO ATUAL \n");
	// printf("======================================================\n\n");
	
	// for(indice = 0; indice < QTD_TERRITORIOS; indice++){
	// 	printf("%d. %s (Exercito %s, Tropas: %d)\n", indice + 1, territorios[indice].nome,territorios[indice].cor, territorios[indice].tropas);
	// }

	do{
		exibirMapa(territorios);

		printf("\n\n");

		int opcao_territorio_atacante = 0;
		int opcao_territorio_defensor = 0;

		do{

			if(territorios[opcao_territorio_atacante-1].tropas == 0 || territorios[opcao_territorio_defensor-1].tropas ==0 ){
				printf("\nUm dos territorios nao tem mais tropa. Tente novamente\n");
			}

			printf("\t --- FASE DE ATAQUE ---\n");
			printf("Escolha o territorio atacante (1 a 5, ou 0 para sair):");
			scanf("%d", &opcao_territorio_atacante);

			if(opcao_territorio_atacante == 0){
				printf("\nFinalizando jogo....\n\n");
				exit(1);
			}

			printf("Escolha o territorio defensor (1 a 5):");
			scanf("%d", &opcao_territorio_defensor);

			limparBufferEntrada();
			
		}while(territorios[opcao_territorio_atacante-1].tropas == 0 || territorios[opcao_territorio_defensor-1].tropas == 0);
		printf("\n");
		atacar(&territorios[opcao_territorio_atacante-1], &territorios[opcao_territorio_defensor-1]);
	}while(1);

	liberarMemoria(territorios);
	return 0;
}