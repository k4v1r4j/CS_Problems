#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

int main() {
  string word;
  while(cin>>word) {
    string sign=word;
    sort(sign.begin(),sign.end());
    cout<<sign<<" "<<word<<endl;
  }
  return 0;
}
