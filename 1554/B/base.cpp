#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve(){
  ll n, k;
  cin >> n >> k;

  vl a(n+1);
  
  for(int i = 1; i <= n; i++) cin >> a[i];


  ll ans = INT_MIN;

  ll l = max(1LL, n-2*k);

  for(ll i = l; i <= n; i++){
    for(ll j = i+1; j <= n; j++){
      ans = max(ans, i*j - k*(a[i]|a[j]));
    }
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
