#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define F first
#define S second

void solve(){
  int n, k, enemy;
  cin >> n;
  vector<ll> dif(n);
  vl caves(n);

  vector<pair<ll,ll>> dc(n);

  for(int i = 0; i < n; i++){
    cin >> k; 
    caves[i] = k;

    dif[i] = -1;
    for(int j = 0; j < k; j++){ 
      cin >> enemy;
      int q = dif[i];
      dif[i] = max(q, enemy - j);
    }

  }

  for(int i = 0; i < n; i++){
    dc[i] = {dif[i], caves[i]};
  }
  
  sort(dc.begin(), dc.end());

  for(auto x: dc) cout << x.F << " ";
  cout <<endl;

  

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
