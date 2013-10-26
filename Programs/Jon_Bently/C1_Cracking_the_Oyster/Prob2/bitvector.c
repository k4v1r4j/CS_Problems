#include<stdio.h>
#include<stdlib.h>
#define N 10000000
int a[1+N/32];
void set(int i) {
  a[i/32]|=1<<(i%31);
}
void clr(int i) {
  a[i/32]&=~(1<<(i%31));
}
int test(int i) {
  return a[i/32] & 1<<(i%31);
}
int main() {
  FILE *fi,*fo;
  int i,t;
  fi=fopen("input","r");
  fo=fopen("output","w");
  for(i=0;i<N;i++) {
    clr(i);
  }
  while(fscanf(fi,"%d",&t)!=EOF) {
    set(t);
  }
  for(i=0;i<N;i++) {
    if(test(i))
      fprintf(fo,"%d\n",i);
  }
  fclose(fi);
  fclose(fo);
  return 0;
}
