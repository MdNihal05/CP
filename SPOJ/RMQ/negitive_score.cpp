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
const int mod = 1e9 + 7, inf = LONG_LONG_MAX, N = 1e5 + 1;

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


vector<int>lg(N);
const int LOG = 20;
void __solve() {

	int n, q; cin >> n >> q;
	vi v(n);
	vector<vector<int>>RMQ(LOG, vector<int>(N));
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		RMQ[0][i] = v[i];
	}
	for (int i = 1; i <= LOG; i++) {
		for (int j = 0; j + (1 << i) - 1 < n; ++j) {
			RMQ[i][j] = min(RMQ[i - 1][j], RMQ[i - 1][j + (1 << (i - 1))]);
		}
	}
	auto query = [&](int l, int r)->int {
		int k = lg[r - l + 1];
		return min(RMQ[k][l], RMQ[k][r - (1 << k) + 1]);
	};
	while (q--) {
		int l, r; cin >> l >> r;
		l--, r--;
		cout << query(l, r) << endl;
	}
}



/*============================================= MAIN =============================================*/

signed  main()
{
	Md_Nihal;
	for (int i = 2; i < N; i++) lg[i] = lg[i / 2] + 1;
	int testcases = 1;    cin >> testcases;
	for (int i = 1; i <= testcases; ++i) {
		cout << "Scenario #" << i << ":" << endl;
		__solve();
	}
}
