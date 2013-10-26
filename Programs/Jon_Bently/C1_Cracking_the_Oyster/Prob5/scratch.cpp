#include<iostream>
#include<fstream>
using namespace std;

void handle(ifstream &in) {
  int t;
  in>>t;
  cout<<t<<endl;

  in>>t;
  cout<<t<<endl;
}

int main() {
  ifstream in("in.txt",ios::in);
  handle(in);
  in.clear();
  in.seekg(0,ios::beg);
  handle(in);
  return 0;
}
