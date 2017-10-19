#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef enum { false, true } bool; //Usando bool por ser mais prático//

void menu ();
void jogo_base (unsigned short int modo);	//Aqui acontece quase todo o jogo//
void entrada (unsigned short int nivel, unsigned short int resposta[], unsigned short int i, bool turno);	//Entrada de dados durante a partida//
void main () {

	unsigned short int op;	//Nessa e em muitas situações não há necessidade de números negativos e muito grandes//
	bool saida=false;

	while (saida != true) {
		menu();	//O menu com as opções//

		scanf("%hu", &op);
		setbuf(stdin, NULL);	//Prevenir problemas com buffer//
		if ((op == 1)||(op == 2)) {
			jogo_base(op);	//A variável "op" define dentro da função qual modo de jogo será//
		} else if (op==3) {
			system("cls");
			printf("OBRIGADO POR JOGAR\n");
			saida=true;
		} else {
			printf("ENTRADA INV%cLIDA\n", 181);	//Usando o código ASCII porque locale.h não funcionava//
		}

		printf("Pressione qualquer tecla para continuar\n");
		getchar();	//Para dar tempo do usuário ler//
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

	int i;	//Única variável de contagem utilizada//
	unsigned short int proposta[50], resposta[50], sequencia = 1, nivel = 1;
	bool turno = true, erro = false;
	//Limite de 50 nos vetores da sequência por seer humanamente impossível//
	srand(time(NULL));	//Gera uma sequência de numeros aleatórios toda vez que for executado//
	system("cls");

	while (erro == false) {	//O jogo vai ser interrompido imediatamente após erro//
		proposta[sequencia-1] = 1 + rand()%(nivel*3);	//Número aleatório entre 1 e 3*nivel preenchendo//
		for (i = 0; i < sequencia; i++) {
			printf("COMPUTADOR\nN%cvel %d\n", 161, nivel);
			sleep(1);	//Tempo de 1 segundo regulado para diferenciar um número do outro//
			printf("%d", proposta[i]);
			sleep(1);
			usleep(250000);	//Nanosegundos//
			system("cls");
		}

		if (turno == true) {	//Turno do jogador 1//
			i=0;
			while ((erro == false)&&(i < sequencia)){
				entrada(nivel, resposta, i, turno);	//O jogador responde uma posição//

				if (proposta[i] != resposta[i]) {	//Detectar diferença entre o que o computador gerou e o jogador//
					printf("RESPOSTA INCORRETA\n");
					if (modo == 2) {	//Puxando o "op" do menu para ver que modo é//
						printf("Jogador 2 venceu\n");
					} else {
						printf("Perdeu no N%cvel %d\n", 161, nivel);
					}
					erro = true;
				}

				i++;
			}

			if (sequencia%10 == 0) {	//Esse if precisa acontecer antes da sequência prosseguir//
				nivel++;
			}
			sequencia++;
		} else {
			i=0;
			while ((erro == false)&&(i < sequencia)){	//Mesma lógica do outro turno//
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
		if (modo == 2) {	//Troca de turno caso seja o segundo modo//
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
	} else {	//Avisar qual jogador é//
		printf("JOGADOR 2\nN%cvel %d\n", 161, nivel);
	}

	scanf("%hu", &resposta[i]);
	setbuf(stdin, NULL);

	system("cls");
}
