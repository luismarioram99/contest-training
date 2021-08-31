#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pl;
typedef vector<pl> vll;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define F first
#define S second

bool is_prime(int n){

  if(!(n%2)) return false;

  for(int i = 3; i*i <= n; i+=2){
    if(!(n%i)) return false;
  }
  return true;

}

void solve() {

  int k; 
  cin >> k;

  string s; 
  cin >> s; 

  for(auto c: s){
    if(c == '4' || c == '6' || c == '8' || c == '9' || c == '1'){
      cout << 1 << endl << c << endl;
      return;
    }
  }

  for(int i = 0; i < k; i++){
    for(int j = i+1; j < k; j++){

      // cout << (s[i] - '0') << " " << (s[j] - '0');

      int num = 10*(s[i] - '0') + (s[j] - '0');
      if(!is_prime(num)){
        cout << 2 << endl;
        cout << num << endl;
        return;
      }

    }
  }


  
}

int main() {
  // make cin and cout input and output faster
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--)
    solve();
}