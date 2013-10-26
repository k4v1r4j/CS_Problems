#include<stdio.h>
#include<stdlib.h>
int a[1000000];
int n;
int i;
int comp(int *a,int *b) {
  return *a-*b;
}
int main() {
  FILE *fi,*fo;
  fi=fopen("input","r");
  fo=fopen("output","w");
  while(fscanf(fi,"%d",&a[n])!=EOF)
    n++;
  qsort(a,n,sizeof(int),comp);
  for(i=0;i<n;i++) {
    fprintf(fo,"%d\n",a[i]);
    //    printf("%d\n",a[i]);
  }
  fclose(fi);
  fclose(fo);
  return 0;
}
