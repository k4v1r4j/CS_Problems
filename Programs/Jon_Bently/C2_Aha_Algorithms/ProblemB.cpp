#include<iostream>
#include<cstdlib>

using namespace std;
void reverse(string &,int l,int u);
int main(int argc,char**argv) {
  string input=string(argv[1]);
  int i=atoi(argv[2]);
  reverse(input,0,i);
  cout<<input<<endl;
  reverse(input,i,input.length());
  cout<<input<<endl;
  reverse(input,0,input.length());
  cout<<input<<endl;
  return 0;
}
void reverse(string &s,int l,int u) {
  int len=s.length();
  for(int i=l,j=u-1;i<l+((u-l)/2);i++,j--) {
    char t=s[i];
    s[i]=s[j];
    s[j]=t;
  }
}
