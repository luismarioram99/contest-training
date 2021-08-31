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

void solve() {

  int n; 
  cin >> n;

  string s; 
  cin >> s;

  for(int i = 0; i < n; i++){

    if(s[i] == '0'){

      if( i >= n/2){
        cout << 1 << " " << i+1 << " " << 1 << " " << i << endl;
        return;
      }else{
        cout << i+2 << " " << n << " " << i+1 << " " << n << endl;
        return;
      }


    }

  }

  cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;


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