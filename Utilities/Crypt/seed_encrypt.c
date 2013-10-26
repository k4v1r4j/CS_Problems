#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

void Encrypt(FILE *in,FILE *out,FILE *cfg);
void Decrypt(FILE *in,FILE *out,FILE *cfg);
void Help();

size_t t_flag;
char *t_value;

size_t i_flag;
char *i_value;

size_t o_flag;
char *o_value;

size_t c_flag;
char *c_value;

size_t v_flag;

size_t s_flag;
size_t s_value;

int FLAG_SEED=1;
int main(int argc,char **argv) {
  int ret;
  while((ret=getopt(argc,argv,"t:i:o:c:vs:"))!=-1) {
    switch(ret) {
    case 't':
      t_flag=1;
      t_value=optarg;
      break;
    case 'i':
      i_flag=1;
      i_value=optarg;
      break;
    case 'o':
      o_flag=1;
      o_value=optarg;
      break;
    case 'c':
      c_flag=1;
      c_value=optarg;
      break;
    case 'v':
      v_flag=1;
      break;
    case 's':
      s_flag=1;
      s_value=atoi(optarg);
      if(s_value>255)
	FLAG_SEED=-1;
      break;
    default:
      Help();
      exit(EXIT_FAILURE);
    }
  }
  if(argc<2||t_value==NULL||i_value==NULL||o_value==NULL||c_value==NULL||s_value==0){
    Help();
    exit(EXIT_FAILURE);
  }
  if(strcmp("Decrypt",t_value) &&  strcmp("Encrypt",t_value)) {
    if(v_flag)
      printf("ERROR: invalid value for option -t\n");
    exit(EXIT_FAILURE);
  }
  FILE *in,*out,*cfg;
  in=fopen(i_value,"r");
  out=fopen(o_value,"w");
  cfg=fopen(c_value,"r");
  if(in==NULL || out==NULL || cfg==NULL){
    if(v_flag)
      printf("ERROR: unable to open file for reading or writing\n");
    exit(EXIT_FAILURE);
  }
  if(!strcmp("Encrypt",t_value))
    Encrypt(in,out,cfg);
  else
    Decrypt(in,out,cfg);
  
  return 0;
}
void Encrypt(FILE *in,FILE *out,FILE *cfg) {
  if(v_flag)
    printf("Encryption -------------------- Started.\n");
  char delim;
  delim=fgetc(cfg);
  fclose(cfg);
  char *line=NULL;
  short value;
  size_t len;
  unsigned char s=s_value;
  while(getline(&line,&len,in)!=-1) {
    if(!strcmp(line,"\n"))
      continue;
    int i=0;
    while(line[i]!='\0'){
      value=line[i]+s;
      if((FLAG_SEED==1 && s==255) ||(FLAG_SEED==-1 && s==0))
	s=s_value;
      else
	s+=(FLAG_SEED);
      fputc(value,out);
      i++;
    }
  }
  fclose(in);
  fclose(out);
  if(v_flag)
    printf("Encryption -------------------- Done.\n");
}
void Decrypt(FILE *in,FILE *out,FILE *cfg) {
  if(v_flag)
    printf("Decryption -------------------- Started.\n");
  char delim;
  delim=fgetc(cfg);
  fclose(cfg);
  char *line=NULL;
  short value;
  size_t len;
  unsigned char s=s_value;
  while(getline(&line,&len,in)!=-1) {
    int i=0;
    while(line[i]!='\0'){
      value=line[i]-s;
      if((FLAG_SEED==1 && s==255) || (FLAG_SEED==-1 && s==0))
	s=s_value;
      else
	s+=(FLAG_SEED);
      fputc(value,out);
      i++;
    }
  }
  fclose(in);
  fclose(out);
  if(v_flag)
    printf("Decryption -------------------- Done.\n");
}
void Help() {
  printf("Usage:\n=====\nseed_encrypt -t<Encrypt/Decrypt> -i<InputFile> -c<ConfigFile> -o<OutPutFile> -s<SeedValue> [-v]\n");
}
