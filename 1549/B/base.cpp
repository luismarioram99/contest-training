#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve(){
  int n; 
  cin >> n;
  string s, t;
  cin >> t >> s;

  t = "x"+ t + "x";
  s = "0" + s + "0";

  int ans = 0; 

  for(int i = 1; i <= n; i++){

    if(s[i] == '0') continue;

    if(t[i-1] == '1'){
      t[i-1] = 'x';
      ans++;
    }else if(t[i] == '0'){
      t[i] = 'x';
      ans++;
    }else if(t[i+1] == '1'){
      t[i+1] = 'x';
      ans++;
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
