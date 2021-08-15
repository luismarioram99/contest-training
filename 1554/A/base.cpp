#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve(){

  ll n;
  cin >> n;

  vl a(n);
  for(auto &x: a)
    cin >> x;

  ll ans = -1;

  for(int i = 1; i < n; i++){
    ans = max(ans, a[i]*a[i-1]);
  }

  cout << ans << endl;
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
