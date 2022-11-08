#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <locale.h>
//Declaração de variáveis
int cont=1, presidente, calcular_votos, contagem, calc_presidente=0, menu, cadastro;
char nome[12][100], cargo[12][100];
int numero[12], votos[12]={0,0,0,0,0,0,0,0,0,0,0,0};

//Cadastro da quantidade de candidatos a presidência
void cadastroPresidente(){
  switch(cadastro){
    case 1:
      cont=1;
      for(calc_presidente=0;calc_presidente<3;calc_presidente++){
        printf("\nDigite o nome do %dº candidato a presidente.\n", cont, setlocale(LC_ALL,""));
        scanf("%s",&nome[calc_presidente]);
        printf("Digite o número %dº candidato a presidente:\n", cont); 
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
  memset(votos, 0, sizeof (votos));
  votarpresidente:; 
    printf("Digite o seu voto para PRESIDENTE:\n");
    scanf("%d", &presidente); 
    if(presidente==numero[0]){
      
      printf("Confirma o voto?\n  (1) SIM    (2) NÃO\n");
      scanf("%d", &contagem);
      switch(contagem){
        case 1:
          votos[0]++;
          printf("Voto Computado.\n");
          break;
        case 2:
          goto votarpresidente;
        }
    }else if (presidente==numero[1]) {
      
      printf("Confirma o voto?\n  (1) SIM    (2) NÃO\n", nome[1]);
      scanf("%d", &contagem);
      switch(contagem){
        case 1:
          votos[1]++;
          printf("Voto Computado.\n");
          //sleep(2);
          break;
        case 2:
          goto votarpresidente;
        }
    }else if (presidente==numero[2]) {
      
      printf("Confirma o voto no candidato %s?\n  (1) SIM    (2) NÃO\n", nome[2]);
      scanf("%d", &contagem);
        switch(contagem){
          case 1:
            votos[2]++;
            printf("Voto Computado.\n");
            break;
          case 2:
            goto votarpresidente;
          }
    }else if (presidente=='\n') {
      printf("Confirmar voto em BRANCO?\n  (1) SIM    (2) NÃO\n");
      scanf("%d", &contagem);
      switch(contagem){
        case 1:
          votos[9]++;
          printf("Voto Computado.\n");
          break;
        case 2:
          goto conf;
        } 
    }else if (presidente==-1) {
        printf("Votação encerrada.\n Obrigado!\n");
        exit(0);
    }else if(presidente != votos){
        printf("Confirmar voto NULO?\n  (1) SIM    (2) NÃO\n");
        scanf("%d", &contagem);
        switch(contagem){
          case 1:
            votos[10]++;
            printf("Voto Computado.\n");
          case 2:
            goto conf;
          }
    }
        
  return 0;}
  
//Boletim de urna
int Boletim(void){
  if (calcular_votos > 0){
    presidenteeleito: 
      if(votos[0]>votos[1]){
        if(votos[0]>votos[2]){
          printf("O PRESIDENTE eleito é %s. Com %d votos.\n\n", nome[0],votos[0]);
          }else if(votos[2]>votos[0]){
          if(votos[2]>votos[1]){
            printf("O PRESIDENTE eleito é %s. Com %d votos.\n\n", nome[2],votos[2]);
            }else if(votos[1]>votos[0]){
            printf("O PRESIDENTE eleito é %s. Com %d votos.\n\n", nome[1],votos[1]);
            }else printf("O PRESIDENTE eleito é %s. Com %d votos.\n\n", nome[0],votos[0]);}

      } else if(votos[1]>votos[0]){
          if(votos[1]>votos[2]){
            printf("O PRESIDENTE eleito é %s. Com %d votos.\n\n", nome[1],votos[1]);
            }else if(votos[2]>votos[0]){
              printf("O PRESIDENTE eleito é %s. Com %d votos.\n\n", nome[2],votos[2]);}
              }else printf("O PRESIDENTE eleito é %s. Com %d votos.\n\n", nome[2],votos[2]);
  } else printf("Nenhum voto foi registrado.\n");
  return 0;}
//Função Principal
int main(void){
  strcpy(nome[9], "Branco");
  strcpy(nome[10], "Nulo");
  sleep(1);
  opcao:;
  printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
  printf("\t \tMENU DE URNA");
  printf("\n1. CADASTRAR CANDIDATOS A PRESIDENTE", setlocale(LC_ALL,""));
  printf("2. CANDIDATOS CADASTRADOS");
  printf("3. INICIAR VOTAÇÃO");
  printf("4. BOLETIM DE URNA");
  printf("5. APURAÇÃO DE VOTOS");
  scanf("%d", &menu);
  printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

  switch(menu){
    case 1: //Acesso a função de cadastro de candidatos a presidência
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
    case 3: //Início da votação
      votacao();
      goto opcao;
      break;
    case 4: //Boletim
      //CLassificação de votos por presidente
      printf("\n%s - %d.\n", nome[0],votos[0]);
      printf("\n%s - %d.\n", nome[1],votos[1]);
      printf("\n%s - %d.\n", nome[2],votos[2]);
      
      //Votos BRANCOS ou NULOS
      printf("\n%s - %d.\n", nome[9],votos[9]);
      printf("%s - %d.\n", nome[10],votos[10]);
      //Totalização de votos
      ContagemVotos();
      
      goto opcao;
    case 5: //Apuração de votos - Final
      ContagemVotos();
      Boletim();
      printf("VOTAÇÕES ENCERRADAS\n", setlocale(LC_ALL,""));
      goto opcao;
  }
return 0;}
