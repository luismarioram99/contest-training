#include <bits/stdc++.h>
#include <algorithm>

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

  vi arr(n);
  for(auto &x: arr)cin >> x;

  ll i = 1;
  while(true){

    if(is_sorted(arr.begin(), arr.end())){
      cout << i - 1 << endl;
      return;
    }

    if(i%2){
      for(int j = 0; j < n-1; j+=2){
        if(arr[j] > arr[j+1]){
          swap(arr[j], arr[j+1]);
        }
      }
    }else{
      for(int j = 1; j < n-1; j+=2){
        if(arr[j] > arr[j+1]){
          swap(arr[j], arr[j+1]);
        }
      }
    }

    i++;

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