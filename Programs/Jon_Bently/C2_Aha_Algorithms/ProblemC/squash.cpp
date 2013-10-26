#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

int main() {
  string word,sign,oldsign;
  oldsign=string("");
  int linenumb=0;
  while(cin>>sign>>word) {
    if(sign!=oldsign && linenumb)
      cout<<endl;
    oldsign=sign;
    linenumb++;
    cout<<word<<" ";
  }
  cout<<endl;
  return 0;
}
