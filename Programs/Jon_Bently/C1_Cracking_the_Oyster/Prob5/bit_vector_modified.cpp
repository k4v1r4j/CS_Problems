#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

#define BITSPERINT 32
#define SHIFT 5
#define N 10000000
#define MASK 0x1F
int a[1+(N/(2*BITSPERINT))];

void set(int i) { a[i>>SHIFT]|=(1<<(i & MASK)); }
void clr(int i) { a[i>>SHIFT]&=~(1<<(i & MASK)); }
int test(int i) { return a[i>>SHIFT] & (1<<(i & MASK)); }

void bit_vector_mod(ifstream &in,ofstream &out,int l,int u) {
  int t;
  for(int i=0;i<N/2;i++) {
    clr(i);
  }
  
  while(in>>t) {
    if(t>=l && t<=u)
      set(t%(N+1/2));
  }
  for(int i=0;i<N/2;i++) {
    if(test(i))
      out<<i+l<<endl;
  }
}

int main() {
  ifstream in("input",ios::in);
  ofstream out("output",ios::out);
  bit_vector_mod(in,out,0,N/2-1);
  in.clear();
  in.seekg(0,ios::beg);
  bit_vector_mod(in,out,N/2,N);
  in.close();
  out.close();
  return 0;

}
