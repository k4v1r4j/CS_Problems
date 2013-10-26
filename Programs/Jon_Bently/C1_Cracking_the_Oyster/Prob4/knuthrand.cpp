#include<iostream>
#include<cstdlib>
#include<unistd.h>

using namespace std;

int randint(int l,int u) {
  return l+(rand()%(u-l+1));
}
void knuthrand(int m,int n) {
  int remaining=n;
  int select=m;
  for(int i=0;i<n;i++) {
    if(rand()%remaining<select){ // statement representing the probabilty of choosing select (s) in remaining(r) i.e s/r
      cout<<i<<endl;
      select--;
    }
    remaining--;
  }
}
void help() {
  cout<<"Usage: krand -m<count> -n<upper_rangd>\n ";
}
int main(int argc,char **argv) {
  int ret,m,n;
  if(argc<3){
    help();
    exit(0);
  }
  while((ret=getopt(argc,argv,"m:n:"))!=-1) {
    switch(ret) {
    case 'm':
      m=atoi(optarg);
      break;
    case 'n':
      n=atoi(optarg);
      break;
    case '?':
      help();
      exit(1);
    }
  }
  knuthrand(m,n);
  return 0;
}
