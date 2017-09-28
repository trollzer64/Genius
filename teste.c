#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void umJogador();
void doisJogadores();

void tempo(int seg) {
    int tQ = time(0) + seg;
    while (time(0) < tQ);
}

main (){
	int x;

	printf("--- BEM VINDO AO JOGO GENIUS ---\n");

	do {
		printf("Deseja jogar como?\n");
		printf("1. Um jogador\n");
		printf("2. Dois jogadores\n");
		printf("3. Sair\n");

		scanf("%d", &x);
		system("cls");

		switch(x) {
			case 1:
				umJogador();
				break;
			case 2:
				doisJogadores();
				break;
		}
	} while(x != 3);

}

void umJogador() {
	int level = 1, lost = 0, j = 10, k, count = 0;

	while (lost == 0) {
		printf("Nivel %d:\n", level);
		int num[10];
		srand(time(NULL));
		for (k = 0; k < 10; k++) {
			int r = rand() % (4+count);
			while (r == 0)
				r = rand() % (4+count);
			num[k] = r;
			//printf("%d ", num[k]);
		}
		printf("\n");
		//for (j = 1; j <= 10 && lost == 0; j++) {
			for (k = 0; k < 10; k++) {
				printf("%d", num[k]);
				//tempo(2);
				//printf("\b* ");

			}
			printf("\n");

			for (k = 0; k < 10; k++) {
				int y;
				scanf("%d", &y);
				printf("\b ");
				if(y != num[k]) {
					lost = 1;
				}
				system("cls");
				if(lost==1){
					printf("voce perdeu no nivel %d\n", level);
				}
			}

			printf("\n");
		//}
		if (j == 10) {
			level++;
			count += 3;
		}
	}
}

void doisJogadores() {

}
