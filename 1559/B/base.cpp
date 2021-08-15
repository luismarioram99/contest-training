#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

string alternate(int n){

  char op[] = {'R','B'};

  string res = "";

  for(int i = 0; i < n; i++){
    res += op[i%2];
  }
  return res;
}

void solve(){
  int n;
  cin >> n;
  string s; 
  cin >> s;

  if(n == 1){
    cout << (s=="?"?"B":s) << endl;
    return;
  }

  int first = 0;
  int flag = false;

  for(int i = 0; i < n; i++){
    if(s[i] != '?'){

      flag = true;      
      first = i;
      break;

    }
  }

  if(!flag){
    
    cout << alternate(n) << endl;
    return;

  }

  
  for(int i = first; i < n-1; i++){

    if(s[i+1] == '?'){
      
      s[i+1] = (s[i] == 'R'?'B':'R');

    }

  }

  for(int i = first; i > 0; i--){

    if(s[i-1] == '?'){
      s[i-1] = (s[i] == 'R'?'B':'R');
    }

  }

  cout << s << endl;  


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
