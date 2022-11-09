//Discente: EMILY NICOLE AGUIAR NEPOMUCENO. Matrícula: 202002632402
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//VARIÁVEIS GLOBAIS
static int voto = 0, voto2 = 0, voto3= 0, voto4 = 0, voto5 = 0, branco = 0, nulo = 0, presidente = 7, invalido = 0;
static int candidato1 = 33, candidato2 = 34, candidato3 = 35, candidato4 = 36, candidato5 = 40;
//FUNÇÃO QUE MOSTRA OS 5 CANDIDATOS
int cadastro(){


	printf("\tCADASTRO DE CANDIDATOS\n\n ", setlocale(LC_ALL,""));
	printf("\n\tINFORMAÇÕES PERTINENTES AO CANDIDATO\n");
	printf("CANDIDATO 1: NÚMERO %d", candidato1);
	printf("\nCANDIDATO 2: NÚMERO %d", candidato2);
	printf("\nCANDIDATO 3: NÚMERO %d", candidato3);
	printf("\nCANDIDATO 4: NÚMERO %d", candidato4);
	printf("\nCANDIDATO 5: NÚMERO %d", candidato5);
//RETORNAR A FUNÇÃO PRINCIPAL
return(main());}
//FUNÇÃO PARA COMPUTAR OS VOTOS
int votacao(){
	
	printf("VOTAÇÃO PARA PRESIDENTE DA REPÚBLICA\n", setlocale(LC_ALL,""));
	printf("\n0 - ENCERRAR VOTAÇÃO");
	printf("\n10 - NULO");
	printf("\n6 - BRANCO");
	
	//LAÇO DE REPETIÇÃO PARA QUE A VOTAÇÃO SÓ FINALIZE SE O ELEITOR DESSEJAR
	while(presidente != 0){
		printf("\nDigite o número eleitoral do seu candidato: ");
		scanf("%d", &presidente);
	//CASE PARA ARMAZENAR O VOTO DO ELEITOR DE ACORDO COM O CANDIDATO
		switch(presidente){
			case 0:
				printf("Votação encerrada!");
				//ESPERAR 1S ANTES DE LIMPAR A TELA
				sleep(1);
				system("cls");
				break;
			case 33: 
				voto = voto + 1;
				printf("VOTO COMPUTADO!");
				sleep(1);
				system("cls");
				break;
				
			case 34:
				voto2 = voto2 + 1;
				printf("VOTO COMPUTADO!");
				sleep(1);
				system("cls");
				break;
			case 35:
				voto3 = voto3 + 1;
				printf("VOTO COMPUTADO!");
				sleep(1);
				system("cls");
				break;
			case 36: 
				voto4 = voto4 + 1;
				printf("VOTO COMPUTADO!");
				sleep(1);
				system("cls");
				break;
			case 40: 
				voto4 = voto4 + 1;
				printf("VOTO COMPUTADO!");
				sleep(1);
				system("cls");
				break;
			case 10:
				nulo = nulo + 1;
				printf("VOTO COMPUTADO!");
				sleep(1);
				system("cls");
				break;
			case 6:
				branco = branco + 1;
				printf("VOTO COMPUTADO!");
				sleep(1);
				system("cls");
				break;
			default:
				printf("INVÁLIDO!");
				invalido = invalido + 1;
				sleep(1);
				system("cls");
	}
}
getchar();
printf("\n\n");
system("pause");
return(main());
}
//FUNÇÃO QUE MOSTRA O RESULTADO FINAL DAS ELEIÇÕES
int resultado(){
	int total;
	total = voto + voto2 + voto3 + voto4 + voto5 + nulo + branco;
	printf("APURAÇÃO DE VOTOS\n");
	printf("CANDIDATO 1: NÚMERO %d", voto);
	printf("\nCANDIDATO 2: NÚMERO %d", voto2);
	printf("\nCANDIDATO 3: NÚMERO %d", voto3);
	printf("\nCANDIDATO 4: NÚMERO %d", voto4);
	printf("\nCANDIDATO 5: NÚMERO %d", voto5);
	printf("\nVOTOS NULOS: %d", nulo);
	printf("\nVOTOS EM BRANCO: %d", branco);
	printf("\nVOTOS INVÁLIDOS: %d", invalido);
	printf("\nTOTAL DE VOTOS: %d", total);
//ESTRUTURA DE DECISÃO QUE INFORMA QUEM FOI O VENCEDOR DAS ELEIÇÕES	
	if(voto > voto2 && voto > voto3 && voto > voto4 && voto > voto5){
		printf("\nCANDIDATO 1 É O VENCEDOR COM %d VOTOS", voto);
	}
	else if(voto2 > voto && voto2 > voto3 && voto2 > voto4 && voto2 > voto5){
		printf("\nCANDIDATO 2 É O VENCEDOR COM %d de VOTOS", voto2);
	}
	else if(voto3 > voto && voto3 > voto2 && voto3 > voto4 && voto3 > voto5){
		printf("\nCANDIDATO 3 É O VENCEDOR COM %d VOTOS", voto3);
	}
	else if(voto4 > voto && voto4 > voto3 && voto4 > voto2 && voto > voto5){
		printf("\nCANDIDATO 4 É O VENCEDOR COM %d VOTOS", voto4);
	}
	else if(voto5 > voto && voto5 > voto3 && voto5 > voto2 && voto5 > voto4){
		printf("\nCANDIDATO 5 É O VENCEDOR COM %d VOTOS", voto5);
	}
		
}
//FUNÇÃO PRINCIPAL
int main(){
//DECLARAÇÃO DE VARIÁVEL	
	int menu;
	opcao:;
	printf("URNA ELETRÔNICA", setlocale(LC_ALL,""));
	printf("\n1. VERIFICAR LISTA DE CANDIDATOS");
	printf("\n2. VOTAR");
	printf("\n3. ENCERRAR - APURAÇÃO");
	printf("\nDIGITE A OPÇÃO DESEJADA: ");
	scanf("%d", &menu);
	
//CASE PARA ACESSAR AS OUTRAS FUNÇÕES 	
		switch(menu){
			case 1:
				cadastro();
				break;
			case 2:
				votacao();
				break;
			case 3:
				resultado();
				break;
			}
	
return 0;}
