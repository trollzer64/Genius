#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef enum { false, true } bool;
main (){
	int i;
	int random[50], resposta[50], seq, nivel, cont;
	bool turno=true, erro=false;

	srand(time(NULL));
	cont=0;
	seq=1;
	nivel=1;
	while (erro==false) {
		printf("Nivel %d\n", nivel);
		if (turno==true) {
			for (i = cont; i < seq; i++) {
				random[i] = 1+rand()%(nivel*3);
			}
			cont++;
			for (i = 0; i < seq; i++) {
				printf("%d", random[i]);
			}
			printf("\n");
			turno=false;
		}
		else {
			i=0;
			while ((erro==false)&&(i<seq)) {
				scanf("%d", &resposta[i]);
				setbuf(stdin, NULL);
				if (random[i]!=resposta[i]) {
					erro=true;
					printf("EH COM S DE SADIA, SEU ANIMAL\n");
				}
				i++;
			}
			turno=true;
			seq++;
			if (seq%10==0) {
				nivel++;
			}
		}
	}
}
