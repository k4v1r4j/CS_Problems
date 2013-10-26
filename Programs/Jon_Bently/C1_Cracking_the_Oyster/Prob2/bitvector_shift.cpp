#include<iostream>
#include<fstream>
using namespace std;

#define BITSPERINT 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000
int a[1+N/BITSPERINT];

void set(int i) { a[i>>SHIFT]|=(1<<(i & MASK)); }
void clr(int i) { a[i>>SHIFT] &= ~(1<<(i & MASK)); }
int test(int i) { return a[i>>SHIFT] & 1<<(i & MASK);}

void bitvector_sort(ifstream &in,ofstream &out);

int main() {
  ifstream in("input");
  ofstream out("output");
  bitvector_sort(in,out);
  in.close();
  out.close();
  return 0;
}
void bitvector_sort(ifstream &in,ofstream &out) {
  int t;
  for(int i=0;i<N;i++)
    clr(i);
  while(in>>t) {
    set(t);
  }
  for(int i=0;i<N;i++)
    if(test(i))
      out<<i<<endl;
}
