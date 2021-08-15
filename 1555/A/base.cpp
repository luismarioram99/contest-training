#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi slices({6,8,10});
vi times({15,20,25});

void solve(){
  ll n; 
  cin >> n;

  ll ans = 0;

  for(int i = 0; i < 3; i++){

    ans += (n/slices[i])*times[i];

    n %= slices[i];

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
