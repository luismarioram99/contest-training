#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ll mod;
vl dp;
vl sum;

ll n;
void solve(){
  
  cin >> n >> mod;


  dp.resize(n+1, 0);
  sum.resize(n+1, 0);
  // cout << n << endl;

  dp[1] = 1;
  sum[1] = 1;

  for(int x = 1; x <= n; x++){

    cout << "-----" << x << "-----" << endl;
    
    if(x == 1){
      sum[x] = 1;
      dp[x] = 1;
    }else{
      dp[x] += sum[x-1];
      dp[x] %= mod;
      sum[x] = sum[x-1] + dp[x];
      sum[x] %= mod;
    }  

    int j2;

    for(int j = 2; j*x <= n; j++){

      j2 = (x*j)/(x+1);

      dp[j*x] += (dp[x]*abs(j - j2))%mod;
      dp[j*x] %= mod;

    }


  }

  for(auto x: sum) cout << x << " ";
  cout << endl;
  for(auto x: dp) cout << x << " ";
  cout << endl;
  
  cout << dp[n] << endl;

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
