// complexity $O(nm)$ -- $n$ variables, $m$ clauses
//
// INPUT
//    sat -- vector of conjuncts; $i$ denotes variable $v_i$ and $-i$ denotes $\lnot{v_i}$
//            (ex. $\{\{-a,b\},\{b,-c\},\{-c,-a\}\}$  $a,b,c\in[1,n]$)
//    n -- number of boolean variables
//    x[i] -- initial assignment computed by sucessive force()ing, or const -1
// 
//  force() and two_sat() are passed
//    g -- graph describing the situation, computed by mkgraph()
//
//  force() is passed
//    v -- variable to force true, can be negative;
//
// OUTPUT
//    x -- satisfying assignment if possible, otherwise garbage
//    returns whether or not a contradiction was found

#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

void mkgraph(const vpii &sat, int n, vvi &g) {
  g.assign(2*n+1,vi()); // index n not used
  for (int i=0; i < sat.size(); i++) {
    g[n-sat[i].first].push_back(n+sat[i].second);
    g[n-sat[i].second].push_back(n+sat[i].first);
  }
}

bool force(const vvi &g, vi &x, int v) {
  int n=x.size()-1; stack<int> S; S.push(v);
  while (!S.empty()) {
    v = S.top(); S.pop();
    if (x[abs(v)] == (v > 0)) continue;
    if (x[abs(v)] >= 0 && x[abs(v)] != (v > 0)) return false;
    x[abs(v)] = v > 0;
    for (int i=0; i<g[n+v].size(); i++)
      S.push(g[n+v][i]-n);
  }
  return true;
}


bool two_sat(const vvi &g, vi &x) {
  for (int i=1; i<=x.size(); i++)
    if (x[i] == -1) {
      vi xc(x);
      if (force(g,x,i)) continue;
      x=xc; if (force(g,x,-i)) continue;
      return false;
    }
  return true;
}

// solution to nwerc 2012 "Idol"
int main() {
  int n,m; 
  while (cin >> n >> m) {
    vpii sat;
    while (m--) {
      int s,t; cin >> s >> t;
      sat.push_back(make_pair(s,t));
    }
    vvi g; mkgraph(sat,n,g);
    vi x(n+1,-1);
    if (force(g,x,1) && two_sat(g,x)) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}
