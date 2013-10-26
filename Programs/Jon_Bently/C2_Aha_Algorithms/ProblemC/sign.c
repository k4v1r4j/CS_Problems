#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXCOUNT 100
int comp(const void *a,const void *b){
  return *(char*)a-*(char*)b;
}
int main() {
  char sign[MAXCOUNT],word[MAXCOUNT];
  while(scanf("%s",word)!=EOF) {
    strcpy(sign,word);
    qsort(sign,strlen(sign),sizeof(char),comp);
    printf("%s %s\n",sign,word);
  }
  return 0;
}
