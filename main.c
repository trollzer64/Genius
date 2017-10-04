#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef enum { false, true } bool;
void menu ();
void jogo_base(int modo);
void jogador_1(int modo);
void jogador_2();
int main (){

  unsigned short int op;
  bool saida=false;

  while (saida!=true) {
    menu();
    scanf("%hu", &op);
    setbuf(stdin, NULL);
    if ((op==1)||(op==2)) {
      jogo_base(op);
    } else if (op==3) {
      system("cls");
      printf("OBRIGADO POR JOGAR\n");
      saida=true;
    } else {
      printf("ENTRADA INVÁLIDA\n");
    }
    printf("\nPressione qualquer tecla para continuar\n");
    getchar();
  }
}
void menu(){
  system("cls");
  printf("\nBEM VINDO\n\n");
  printf("(1) 1 Jogador\n");
  printf("(2) 2 Jogadores\n");
  printf("(3) Sair\n");
  printf("\nSua escolha: ");
}
void jogo_base(int modo){

  int i;
  unsigned short int proposta[50], resposta[50], sequencia=1, nivel=1, cont=0;
  bool turno=true, erro_resposta=false;

  srand(time(NULL));

  while (erro_resposta==false) {
    for (i = cont; i < sequencia; i++) {
      proposta[i] = 1+rand()%(nivel*3);
    }
    cont++;
    for (i = 0; i < sequencia; i++) {
      printf("\nCOMPUTADOR\nNivel %d\n", nivel);
      sleep(1);
      printf("%d", proposta[i]);
      sleep(1.25);
      system("cls");
    }
    if (turno==true) {
      i=0;
			while ((erro_resposta==false)&&(i<sequencia)) {
        printf("\nJOGADOR 1\nNivel %d\n", nivel);
        sleep(0.25);
				scanf("%hu", &resposta[i]);
				setbuf(stdin, NULL);
        system("cls");

				if (proposta[i]!=resposta[i]) {
					erro_resposta=true;
					printf("RESPOSTA INCORRETA\n");
          if (modo==2) {
            printf("Jogador 2 venceu\n");
          } else {
            printf("Perdeu no Nível %d\n", nivel);
          }
        }
				i++;
			}
      if (sequencia%10==0) {
        nivel++;
      }
      sequencia++;
      if (modo==2) {
        turno=false;
      }
    } else {
      i=0;
			while ((erro_resposta==false)&&(i<sequencia)) {
        printf("\nJOGADOR 2\nNivel %d\n", nivel);
        sleep(0.25);
				scanf("%hu", &resposta[i]);
				setbuf(stdin, NULL);
        system("cls");
				if (proposta[i]!=resposta[i]) {
					erro_resposta=true;
          printf("RESPOSTA INCORRETA\n");
					printf("Jogador 1 venceu\n");
        }
				i++;
			}
      if (sequencia%10==0) {
        nivel++;
      }
      sequencia++;
      turno=true;
    }
  }
}
