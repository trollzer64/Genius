#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>

typedef enum { false, true } bool;
main (){
  int i;
  int random[50], resposta[50], seq=1, nivel=1, tempo;
  bool turno=true, erro=false;

  srand(time(NULL));

  while (erro==false) {
    printf("Nivel %d\n", nivel);

    if (turno==true) {
      for (i = 0; i < seq; i++) {
        random[i] = 1+rand()%(nivel*3);
        printf("%d", random[i]);
        sleep(3);
        system("cls");
      }
      turno=false;
    }else{
      i=0;
      while ((erro==false)&&(i<seq)) {
        scanf("%d", &resposta[i]);
        setbuf(stdin, NULL);
        system("cls");
        i++;
        if (random[i]!=resposta[i]) {
          erro=true;
          printf("EH COM S DE SADIA, SEU ANIMAL\n");
          exit;
        }
      }
      turno=true;
    }
    if (seq%10==0) {
      nivel++;
    }
    seq++;
  }
}
