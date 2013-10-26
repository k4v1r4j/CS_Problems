#include<iostream>
#include<set>
#include<fstream>

using namespace std;
int main() {
  ifstream in("input_cpp");
  ofstream out("output_cpp");
  set<int>s;
  int t;
  while(in>>t) {
    s.insert(t);
  }
  for(set<int>::iterator it=s.begin();it!=s.end();it++) {
    out<<*it<<endl;
  }
  return 0;
}
