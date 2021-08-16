#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve(){
  int n, m;
  cin >> n >> m;

  vi a(n); 
  int ans = 0; 

  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    if(u > v) swap(u, v);
    a[u]++;
    if(a[u] == 1) ans++;
  }

  int q;
  cin >> q;
  
  while(q--){

    int t; 
    cin >> t;
    if(t == 1){
      int u, v;
      cin >> u >> v;
      if(u > v) swap(u, v);
      a[u]++;
      if(a[u] == 1) ans++;  
    } else if(t == 2){
      int u, v;
      cin >> u >> v;
      if(u > v) swap(u, v);
      a[u]--;
      if(a[u] == 0) ans--;
    }else{
      cout << n - ans << endl;
    }
  }

}

int main() {

  //make cin and cout input and output faster
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
