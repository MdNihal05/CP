#include "bits/stdc++.h"
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,fma")
#define Md_Nihal ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef unsigned long long ull;
#define endl "\n"
#define int long long
#define sz(a) (int)a.size()
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vs vector<string>
#define all(x) x.begin(),x.end()
#define rep(i,n) for (int i = 0; i < (n); i++)
#define print(x) (x)?cout<<"YES":cout<<"NO";
const int mod = 1e9 + 7, inf = LONG_LONG_MAX, N = 1e6 + 7;

template<class T, class V>istream& operator>>(istream &in, pair<T, V> &a) {in >> a.first >> a.second; return in;}
template<class T>istream& operator>>(istream &in, vector<T> &a) {for (auto &i : a) {in >> i;} return in;}
template<class T, class V>ostream& operator<<(ostream &os, pair<T, V> &a) {os << a.first << " " << a.second; return os;}
template<class T>ostream& operator<<(ostream &os, vector<T> &a) {for (auto &i : a) {os << i << " ";} return os;}


#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(x...);
#endif

/*=========================================== SOLUTION ===========================================*/

vector<int> dx = { -1, 1, 0, 0, -1, -1, 1, 1};
vector<int> dy = {0, 0, -1, 1, 1, -1, -1, 1};
int n, m, ans = 0;
void dfs(vector<string>&v, int i, int j) {
	int count = 0;
	for (int k = 0; k < 8; k++) {
		int r = i + dx[k];
		int c = j + dy[k];
		if (r<n and r >= 0 and c<m and c >= 0 and v[r][c] == '#') {
			v[r][c] = '.';
			dfs(v, r, c);
		}
	}
}

void __solve() {

	cin >> n >> m;
	vs v(n); cin >> v;
	ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j] == '#') {
				ans++;
				dfs(v, i, j);
			}
		}
	}
	cout << ans;
}



/*============================================= MAIN =============================================*/

signed  main()
{
	Md_Nihal;
	int testcases = 1;    //cin >> testcases;
	for (int i = 1; i <= testcases; ++i, cout << endl) __solve();
}
