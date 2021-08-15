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

  vl a(n);
  for(auto &x: a) cin >> x;

  sort(a.begin(), a.end());

  double max_av = INT_MIN;

  vl partial(n, 0);

  int sum = 0;
  for(int i = 0; i < n; i++){

    sum += a[i];
    partial[i] = sum;

  }

  for(int i = 1; i < n ; i++){

    double s1 = partial[n - i - 1];
    double s2 = partial[n - 1] - partial[n - i - 1];

    double av1 = s1/(n - i);
    double av2 = s2/i;


    max_av = max(max_av, av1 + av2);

  }

  printf("%.8f\n", max_av);





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
