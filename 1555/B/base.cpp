#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve(){
  int W, H;
  cin >> W >> H;

  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2; 

  int w, h;
  cin >> w >> h;

  int nw, nh;
  nw = w + x2 - x1;
  nh = h + y2 - y1;

  int min_val = INT_MAX;
  bool flag = false;

  // cout << nw << " " << nh << endl;
  // cout << W << " " << H << endl;

  if(nw <= W){

    min_val = min(min_val, max(0, w - x1));
    min_val = min(min_val, max(0, x2 - (W - w)));

    flag = true;
  }

  if(nh <= H){

    min_val = min(min_val, max(0, h - y1));
    min_val = min(min_val, max(0, y2 - (H - h)));
    
    flag = true;
  }

  if(flag) printf("%.9f\n", (float)min_val);
  else printf("-1\n");

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
