#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <locale.h>
//Declara��o de vari�veis
int cont=1, presidente, calcular_votos, contagem, calc_presidente=0, menu, cadastro;
char nome[12][100], cargo[12][100];
int numero[12], votos[12]={0,0,0,0,0,0,0,0,0,0,0,0};

//Cadastro da quantidade de candidatos a presid�ncia
void cadastroPresidente(){
  switch(cadastro){
    case 1:
      cont=1;
      for(calc_presidente=0;calc_presidente<3;calc_presidente++){
        printf("\nDigite o nome do %d� candidato a presidente.\n", cont, setlocale(LC_ALL,""));
        scanf("%s",&nome[calc_presidente]);
        printf("Digite o n�mero %d� candidato a presidente:\n", cont); 
        scanf("%d", &numero[calc_presidente]);
        cont++;}
      break;}}
//Soma dos votos computados por candidato
int ContagemVotos(){
    int cont2;
    calcular_votos = 0;
    for(cont2 = 10; cont2 >= 0; cont2--){
      calcular_votos = calcular_votos + votos[cont2];
    }printf("TOTAL DE VOTOS: %d\n\n", calcular_votos);
    return 0;}
//Categoria de voto: CONFIRMA - BRANCO - NULO
int votacao(void){
  	conf:;
  	memset(votos, 0, sizeof(votos));
  	votarpresidente:; 
    printf("Digite o seu voto para PRESIDENTE:\n");
    scanf("%d", &presidente); 
    if(presidente == numero[0]){
    	printf("CONFIRMAR?\n  1. SIM    2. N�O\n");
    	scanf("%d", &contagem);
      	switch(contagem){
        	case 1:
        		votos[0]++;
        		printf("Voto Computado.\n");
        		break;
        	case 2:
          		goto votarpresidente;
        }}
	else if(presidente == numero[1]){
      
    	printf("Confirma o voto?\n  1. SIM    2. N�O\n");
      	scanf("%d", &contagem);
      	switch(contagem){
        	case 1:
				votos[1]++;
            	printf("Voto Computado.\n");
        		break;
        	case 2:
    			goto votarpresidente;
        }
    }else if(presidente == numero[2]) {
    	
      	printf("Confirma o voto?\n  1. SIM    2. N�O\n");
      	scanf("%d", &contagem);
        switch(contagem){
        	case 1:
            	votos[2]++;
            	printf("Voto Computado.\n");
            	break;
          	case 2:
            	goto votarpresidente;
          }
    }else if (presidente==-1) {
        printf("Vota��o encerrada\n");
        exit(0);
    }else if(presidente != votos){
        printf("Confirmar voto NULO?\n  1. SIM    2. N�O\n");
        scanf("%d", &contagem);
        switch(contagem){
          case 1:
            votos[10]++;
            printf("Voto Computado.\n");
          case 2:
            goto conf;
          }}
	else if (presidente =='\n') {
      printf("Confirmar voto em BRANCO?\n  (1) SIM    (2) N�O\n");
      scanf("%d", &contagem);
      switch(contagem){
        case 1:
        	votos[9]++;
        	printf("Voto Finalizado.\n");
        	break;
        case 2:
          	goto conf;
        } 
    }else if (presidente == -1) {
      	printf("Vota��o encerrada.\n ");
      	exit(0);
    }return 0;}
  
//Boletim de urna
int Boletim(void){
  if (calcular_votos > 0){
    presidenteeleito: 
      if(votos[0]>votos[1]){
        if(votos[0]>votos[2]){
          printf("O PRESIDENTE eleito � %s. Com %d votos.\n\n", nome[0],votos[0]);
          }else if(votos[2]>votos[0]){
          if(votos[2]>votos[1]){
            printf("O PRESIDENTE eleito � %s. Com %d votos.\n\n", nome[2],votos[2]);
            }else if(votos[1]>votos[0]){
            printf("O PRESIDENTE eleito � %s. Com %d votos.\n\n", nome[1],votos[1]);
            }else printf("O PRESIDENTE eleito � %s. Com %d votos.\n\n", nome[0],votos[0]);}

      } else if(votos[1]>votos[0]){
          if(votos[1]>votos[2]){
            printf("O PRESIDENTE eleito � %s. Com %d votos.\n\n", nome[1],votos[1]);
            }else if(votos[2]>votos[0]){
              printf("O PRESIDENTE eleito � %s. Com %d votos.\n\n", nome[2],votos[2]);}
              }else printf("O PRESIDENTE eleito � %s. Com %d votos.\n\n", nome[2],votos[2]);
  } else printf("Nenhum voto foi registrado.\n");
  return 0;}
//Fun��o Principal
int main(void){
  strcpy(nome[9], "Branco");
  strcpy(nome[10], "Nulo");
  sleep(1);
  opcao:;
  printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
  printf("\t \tMENU DE URNA");
  printf("\n\n1. CADASTRAR CANDIDATOS A PRESIDENTE\n2. CANDIDATOS CADASTRADOS.\n3. INICIAR VOTA��O.\n4. BOLETIM DE URNA\n5. APURA��O DE VOTOS - FINAL\n\n", setlocale(LC_ALL,""));
  scanf("%d", &menu);
  printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

  switch(menu){
    case 1: //Acesso a fun��o de cadastro de candidatos a presid�ncia
      printf("Digite 1 para entrar na no cadastro de candidatos a presidente: ");
      scanf("%d", &cadastro);
      cadastroPresidente();
      goto opcao;
      break;
    case 2: //Listar candidatos
      printf("Candidatos a PRESIDENTE:\n");
      for(calc_presidente = 0; calc_presidente < 3;calc_presidente++) {
      printf("%d - %s\n", numero[calc_presidente], nome[calc_presidente]);
      }
      goto opcao;
    case 3: //In�cio da vota��o
      votacao();
      goto opcao;
      break;
    case 4: //Boletim
      //CLassifica��o de votos por presidente
      printf("\n%s - %d.\n", nome[0],votos[0]);
      printf("\n%s - %d.\n", nome[1],votos[1]);
      printf("\n%s - %d.\n", nome[2],votos[2]);
      
      //Votos BRANCOS ou NULOS
      printf("\n%s - %d.\n", nome[9],votos[9]);
      printf("%s - %d.\n", nome[10],votos[10]);
      //Totaliza��o de votos
      ContagemVotos();
      
      goto opcao;
    case 5: //Apura��o de votos - Final
      ContagemVotos();
      Boletim();
      printf("VOTA��ES ENCERRADAS\n", setlocale(LC_ALL,""));
      goto opcao;
  }
return 0;}
