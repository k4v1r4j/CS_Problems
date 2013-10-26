#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>

typedef struct _line_s line_s;
struct _line_s {
  char *line;
  size_t l_len;
  char **words;
  size_t w_count;
};
line_s *contents;
int f_flag,n_flag,f_value;
size_t t_lines;
void getContents(FILE *f);
size_t getWordsCount(char *p);
void dispContents();
int comp(const void* a,const void* b);
size_t getLineCount(FILE *fp);
void help() {
  fprintf(stdout,"usage: fsort [-fn] [-n] input_file\n");
}
int main(int argv,char **argc) {
  char c;
  if(argv<2) {
    help();
    exit(EXIT_FAILURE);
  }
  while((c=getopt(argv,argc,"f:n"))!=-1) {
    switch(c) {
    case 'f':
      f_flag=1;
      f_value=atoi((char*)optarg);
      break;
    case 'n':
      n_flag=1;
      break;
    case '?':
      help();
      exit(EXIT_FAILURE);
      break;
    default:
      fprintf(stdout,"Invalid option\n");
      exit(EXIT_FAILURE);
    }
    //    fprintf(stdout,"f_flag: %d, f_value: %d, n_flag: %d\n",f_flag,f_value,n_flag);
  }
  FILE *fp;
  fp=fopen(argc[argv-1],"r");
  if(fp==NULL){
    printf("Error reading input file\n");
    exit(EXIT_FAILURE);
  }
  getLineCount(fp);
  //  printf("lines: %d\n",t_lines);
  fclose(fp);
  fp=fopen(argc[argv-1],"r");
  if(fp==NULL){
    printf("Error reading input file\n");
    exit(EXIT_FAILURE);
  }
  getContents(fp);
  //  printf("before qsort\n");
  qsort(contents,t_lines,sizeof(line_s),comp);
  dispContents();
  free(contents);
  fclose(fp);
  return 0;
}
size_t getLineCount(FILE *fp) {
  char *buf;
  size_t len=0;
  while(getline(&buf,&len,fp)!=-1) {
    t_lines++;
  }
}
void getContents(FILE *f) {
  int ret=0;
  size_t len=0,i=0,l_trace;
  contents=(line_s *)malloc(sizeof(line_s)*t_lines);
  l_trace=2;
  while((ret=getline(&contents[i].line,&len,f))!=-1) {
    contents[i].l_len=len;
    contents[i].line=strtok(contents[i].line,"\n");
    if(contents[i].line ==NULL){
      contents[i].l_len=0;
      contents[i].w_count=0;
      contents[i].words=NULL;
      continue;
    }
    int k=0;char *temp;
    temp=(char*)malloc(strlen(contents[i].line)+1);
    strcpy(temp,contents[i].line);
    size_t wc_l=getWordsCount(contents[i].line);
    contents[i].words=(char **)malloc(sizeof(char*)*wc_l);
    contents[i].w_count=wc_l;
    contents[i].words[k]=strtok(temp," ");
    while(contents[i].words[k]!=NULL) {
      //      printf("words: %s\n",contents[i].words[k]);
      k++;
      contents[i].words[k]=strtok(NULL," ");
      //      if(contents[i].words[k++]==NULL) puts("Im screwed\n");
    }
    //    contents[i].w_count=k;
    //    contents=(line_s *)realloc(contents,sizeof(line_s)*l_trace);
    l_trace++;
    i++;
  }
}
size_t getWordsCount(char *p) {
  size_t wc=0;
  size_t i=0;
  while(p[i]!='\0') {
    if(p[i]==' ')
      wc++;
    i++;
  }
  return wc+1;
}
void dispContents() {
  int i;
  if(t_lines==0) {
    printf("Empty file\n");
    exit(0);
  }
  for(i=0;i<t_lines;i++) {
    printf("%s\n",contents[i].line);
    //  printf("%d\n",contents[i].w_count);
    //    printf("first Word: %s\n",contents[i].words[0]);
  }
}
int comp(const void *a,const void *b) {
  if(f_flag) {
    if(((line_s*)a)->w_count<f_value && ((line_s*)b)->w_count<f_value)
      return 0;
    else if(((line_s*)a)->w_count<f_value)
      return -1;
    else if(((line_s*)b)->w_count<f_value)
      return 1;
    else{
      if(n_flag){
        long long x=atoll(((line_s*)a)->words[f_value-1]);
        long long y=atoll(((line_s*)b)->words[f_value-1]);
        if(x==y)
          return 0;
        else if(x<y)
          return -1;
        else
          return 1;
      }else {
        return strcmp(((line_s*)a)->words[f_value-1],((line_s*)b)->words[f_value-1]);
      }
    }
  }
  else {
    return strcmp(((line_s*)a)->line,((line_s*)b)->line);
  }
}
