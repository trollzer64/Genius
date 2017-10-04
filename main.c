#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef enum { false, true } bool;
void menu ();
int main (){

  unsigned short int op;
  bool saida=false;

  srand(time(NULL));

  while (saida!=true) {
    printf("\e[H\e[2J");
    menu();
    scanf("%hu", &op);
    setbuf(stdin, NULL);
    if (op==1) {
      printf("JOGO 1\n");
      sleep(2);
    } else if (op==2) {
      printf("JOGO 2\n");
      sleep(2);
    } else if (op==3) {
      printf("INSTRUÇÕES\n");
      sleep(2);
    } else if (op==4) {
      printf("OBRIGRADO POR JOGAR\n");
      saida=true;
      sleep(2);
    } else {
      printf("ENTRADA INVALIDA\n");
      sleep(2);
    }
  }
}
void menu(){
  printf("BEM VINDO\n");
  printf("1 - Modo 1 Jogador\n");
  printf("2 - Modo 2 Jogadores\n");
  printf("3 - Instruções\n");
  printf("4 - Sair\n");
  printf("\nSua escolha: \n");
}
