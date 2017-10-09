#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef enum { false, true } bool;

void menu ();
void jogo_base (unsigned short int modo);
void entrada (unsigned short int nivel, unsigned short int resposta[], unsigned short int i, bool turno);
void main () {

	unsigned short int op;
	bool saida=false;

	while (saida != true) {
		menu();

		scanf("%hu", &op);
		setbuf(stdin, NULL);
		if ((op == 1)||(op == 2)) {
			jogo_base(op);
		} else if (op==3) {
			system("cls");
			printf("OBRIGADO POR JOGAR\n");
			saida=true;
		} else {
			printf("ENTRADA INV%cLIDA\n", 181);
		}

		printf("Pressione qualquer tecla para continuar\n");
		getchar();
	}
}
void menu () {
	system("cls");
	printf("(1) 1 Jogador\n");
	printf("(2) 2 Jogadores\n");
	printf("(3) Sair\n");
	printf("\nSua escolha: ");
}
void jogo_base (unsigned short int modo) {

	int i;
	unsigned short int proposta[50], resposta[50], sequencia = 1, nivel = 1;
	bool turno = true, erro = false;

	srand(time(NULL));
	system("cls");

	while (erro == false) {
		proposta[sequencia-1] = 1 + rand()%(nivel*3);
		for (i = 0; i < sequencia; i++) {
			printf("COMPUTADOR\nN%cvel %d\n", 161, nivel);
			sleep(1);
			printf("%d", proposta[i]);
			sleep(1);
			usleep(250000);
			system("cls");
		}

		if (turno == true) {
			i=0;
			while ((erro == false)&&(i < sequencia)){
				entrada(nivel, resposta, i, turno);

				if (proposta[i] != resposta[i]) {
					printf("RESPOSTA INCORRETA\n");
					if (modo == 2) {
						printf("Jogador 2 venceu\n");
					} else {
						printf("Perdeu no N%cvel %d\n", 161, nivel);
					}
					erro = true;
				}

				i++;
			}

			if (sequencia%10 == 0) {
				nivel++;
			}
			sequencia++;
		} else {
			i=0;
			while ((erro == false)&&(i < sequencia)){
				entrada(nivel, resposta, i, turno);

			 if (proposta[i] != resposta[i]) {
					printf("RESPOSTA INCORRETA\n");
					printf("Jogador 1 venceu\n");
					erro = true;
				}

				i++;
			}

			if (sequencia%10 == 0) {
				nivel++;
			}
			sequencia++;
		}
		if (modo == 2) {
			if (turno == true) {
				turno = false;
			} else {
				turno = true;
			}
		}
	}
}
void entrada(unsigned short int nivel, unsigned short int resposta[], unsigned short int i, bool turno) {
	if (turno == true) {
		printf("JOGADOR 1\nN%cvel %d\n", 161, nivel);
	} else {
		printf("JOGADOR 2\nN%cvel %d\n", 161, nivel);
	}

	scanf("%hu", &resposta[i]);
	setbuf(stdin, NULL);

	system("cls");
}
