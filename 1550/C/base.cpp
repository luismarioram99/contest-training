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

bool check_non_decreasing(vi &a, int p, int q){
  int last = 0;
  for(int i = p; i <= q; i++){
    if(a[i] < last){
      return false;
    }
    last = a[i];
  }
  return true;
}

bool check_non_increasing(vi &a, int p, int q){
  int last = INT_MAX;
  for(int i = p; i <= q; i++){
    if(a[i] > last){
      return false;
    }
    last = a[i];
  }
  return true;
}

bool check_4_non_decreasing(vi &arr, int p){
  int a = arr[p];
  int b = arr[p+1];
  int c = arr[p+2];
  int d = arr[p+3];


  bool res = false;

  res = res || (a <= b && b <= c);
  res = res || (a <= b && b <= d);
  res = res || (a <= c && c <= d);
  res = res || (b <= c && c <= d);

  return res;

}

bool check_4_non_increasing(vi &arr, int p){
  int a = arr[p];
  int b = arr[p+1];
  int c = arr[p+2];
  int d = arr[p+3];

  bool res = false;

  res = res || (a >= b && b >= c);
  res = res || (a >= b && b >= d);
  res = res || (a >= c && c >= d);
  res = res || (b >= c && c >= d);

  return res;

}

void solve() {

  int n;
  cin >> n;

  vi a(n);

  int cont = n + (n - 1); 

  for(auto &x: a) cin >> x;


  for(int i = 0; i <= n-3; i++){
    if(!check_non_decreasing(a, i, i + 2) && !check_non_increasing(a, i, i+2)){
      // cout << a[i] << " " << a[i+1] << " " << a[i+2] << endl;
      cont++;
    }else{
    }
  }

  for(int i = 0; i <= n-4; i++){
    
    if(!check_4_non_decreasing(a, i) && !check_4_non_increasing(a, i)){
      // cout << a[i] << " " << a[i+1] << " " << a[i+2] << " " << a[i+3] << endl;
      cont++;
    }else{
    }
  }  

  cout << cont << endl;

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