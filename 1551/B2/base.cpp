#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve(){
  int n, k;
  cin >> n >> k;

  vector<int> ans(n, 0);
  vector<vector<int>> indices(n+1);

  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    if(indices[x].size() < k) indices[x].push_back(i);
  }

  int m = 0; 
  for(auto e: indices) m += e.size();
  m -= m%k;

  int color = 0;
  for(auto e: indices){
    for(auto i: e){
      ans[i] = ++color;
      color %= k;
      if(!(--m)) goto print;
    }
  }

  print:
    for(auto x: ans)
      cout << x << " ";
    cout << endl;
}

int main() {

  //make cin and cout input and output faster
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
