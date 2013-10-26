#include<iostream>
#include<cstdlib>
#include<set>
#include<map>
#include<algorithm>
#include<utility>
#include<fstream>
#include<vector>

using namespace std;

vector<string> find_anagram(vector<string>& dict,string word) {
  multimap<string,string> dict_sig;
  vector<string>result;
  sort(word.begin(),word.end());
  for(int i=0;i<dict.size();i++) {
    string sig;
    sig=dict[i];
    sort(sig.begin(),sig.end());
    dict_sig.insert(pair<string,string>(sig,dict[i]));
  }
  pair<multimap<string,string>::iterator,multimap<string,string>::iterator> range;
  range=dict_sig.equal_range(word);
  multimap<string,string>::iterator it;
  for(it=range.first;it!=range.second;it++) {
    result.push_back(it->second);
  }
  return result;
}

int main() {
  vector<string>dict;
  string s;
  ifstream in("/usr/share/dict/words",ios::in);
  while(in>>s) {
    dict.push_back(s);
  }
  vector<string>anagrams;
  cin>>s;
  anagrams=find_anagram(dict,s);
  cout<<"size: "<<anagrams.size()<<endl;
  for(int i=0;i<anagrams.size();i++) {
    cout<<anagrams[i]<<endl;
  }
  return 0;
}
