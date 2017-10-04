#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef enum { false, true } bool;
void menu ();
void manual(); //As instruções são opcionais, ainda a discutir//
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
      printf("\e[H\e[2J");
      printf("OBRIGADO POR JOGAR\n");
      saida=true;
    } else if (op==4) {
      manual();
    } else {
      printf("ENTRADA INVÁLIDA\n");
    }
    printf("\nPressione qualquer tecla para continuar\n");
    getchar();
  }
}
void menu(){
  printf("\e[H\e[2J");
  printf("\nBEM VINDO\n\n");
  printf("1 - Modo de 1 Jogador\n");
  printf("2 - Modo de 2 Jogadores\n");
  printf("3 - Sair\n");
  printf("4 - Instruções\n");
  printf("\nSua escolha: ");
}
void manual(){
  printf("\e[H\e[2J");
  printf("INSTRUÇÕES\n");
  printf("1) O computador apresentará uma sequência de números\n");
  printf("2) O jogador deverá repetir a sequência\n");
  printf("3) A sequência começará com apenas um número e aumentará a cada acerto\n");
  printf("4) A cada 10 acertos, o jogador passará para o nível seguinte\n");
  printf("5) A cada novo nível, a variedade de valores possíveis aumenta em 3\n");
  printf("\tNível 1: 1 a 3\n\tNível 2: 1 a 6 e assim por diante\n");
  printf("O modo de dois jogadores troca o computador por outro usuário\n");
}
void jogo_base(int modo){

  int i;
  unsigned short int proposta[50], resposta[50], sequencia=1, nivel=1, cont=0;
  bool turno=true, erro_resposta=false, erro_proposta;

  printf("\e[H\e[2J");
  printf("JOGO\n");
  if (modo==1) {
    printf("Modo 1 Jogador\n");
  } else {
    printf("Modo 2 Jogadores\n");
  }

  srand(time(NULL));

  while (erro_resposta==false) {
    printf("Nivel %d\n", nivel);
    if (turno==true) {

      for (i = cont; i < sequencia; i++) {
				if (modo==1) {
				  proposta[i] = 1+rand()%(nivel*3);
				} else {
          do {
            erro_proposta=false;

            scanf("%hu", &proposta[i]);
            if ((proposta[i]<1)||(proposta[i]>nivel*3)) {
              erro_proposta=true;
            }
          } while(erro_proposta=true);
        }
			}
			cont++;

			for (i = 0; i < sequencia; i++) {
				printf("%d", proposta[i]);
			}
			printf("\n");

      turno=false;
    } else {
      //proposta aqui//

      if (sequencia%10==0) {
        nivel++;
      }
      sequencia++;
      turno=true;
    }
  }
}
