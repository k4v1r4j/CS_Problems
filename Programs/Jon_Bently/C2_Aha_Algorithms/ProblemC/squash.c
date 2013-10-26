#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int main() {
  char word[MAX],sig[MAX],oldsig[MAX];
  strcpy(oldsig,"");
  int linenumb=0;
  while(scanf("%s%s",sig,word)!=EOF){
    if(strcmp(oldsig,sig)!=0 && linenumb) {
      printf("\n");
    }
    strcpy(oldsig,sig);
    linenumb++;
    printf("%s ",word);
  }
  printf("\n");
  return 0;
}
