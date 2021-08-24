#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ll mod;
vl dp;

ll ways(ll x){
  cout << x << endl;
  if(dp[x] != -1) return dp[x];

  if(x == 1){
    dp[x] = 1;
    return 1;
  }

  ll sum_ways = 0;
  for(ll i = 1; i <= x-1; i++){
    sum_ways += ways(x - i)%mod; 
    sum_ways %= mod;
  }

  ll div_ways = 0;
  for(ll i = 2; i <= x; i++){
    div_ways += ways(x/i)%mod;
    div_ways %= mod;
  }

  dp[x] = (div_ways + sum_ways)%mod;
  return dp[x];

}


void solve(){
  ll n;
  cin >> n >> mod;
  // cout << "here" << endl;

  dp.resize(n+1, -1);
  // cout << n << endl;

  for(int i = 1; i <= n; i++){
    ways(i);
  }

  cout << ways(n) << endl;

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
