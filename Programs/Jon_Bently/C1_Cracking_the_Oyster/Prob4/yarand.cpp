#include<iostream>
#include<cstdlib>
#include<unistd.h>
#include<vector>
using namespace std;

int randint(int l,int u) {
  return l+rand()%(u-l+1);
}

void help() {
  cout<<"usage: yarand -m<count> -n <upper_range>\n";
}

void yarand(int m,int n) {
  vector<int>a;
  for(int i=0;i<n;i++) {
    a.push_back(i);
  }
  for(int i=0;i<m;i++) {
    int t=i;
    int r=randint(i,n-1);
    swap(t,r);
    cout<<a[t]<<endl;
  }
}

int main(int argc,char **argv) {
  if(argc<3){
    help();
    exit(0);
  }
  int ret,m,n;
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
      exit(0);
    }
  }
  yarand(m,n);
  return 0;
}
