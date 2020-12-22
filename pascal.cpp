#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int n = 15, mx = 1;
vector< int > v;
vector< vector< int > > out;

vector< int > new_layer(){
  vector< int > newl;
  newl.pb(1);
  for(auto i  = 1;i < v.size();++i){
    newl.pb(v[i] + v[i - 1]);
    mx = max(v[i] + v[i - 1], mx);
  }
  newl.pb(1);
  return newl;
}

signed main(){
  cout << "n = " << n << "\n";
  out.pb({1});
  v.pb(1);
  for (auto i = 2;i <= n;++i){
    v = new_layer();
    out.pb(v);
  }
  int k = log10(mx) + 2;
  for(int i = 0;i < out.size();++i){
    for(auto val : out[i]){
      cout << setw(k) << val;
    }
    puts("");
  }
}
