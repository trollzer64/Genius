#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef enum { false, true } bool;

void menu ();
void jogo_base (int modo);
void main (){

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

		printf("Pressione qualquer tecla para continuar\n");
		getchar();
	}
}
