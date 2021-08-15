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
  vi a(n);
  for(auto &x:a) cin >> x;

  int count = 0;

  for(int i = 0; i < n-1; i++){

    if(a[i] > a[i+1]){
      count++;
    }

  }

  if(count <= k-1) cout << "YES" << endl;
  else cout << "NO" << endl;

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
