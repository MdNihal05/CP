#include<bits/stdc++.h>
using namespace std;
const int LOG = 17, N = 1e5 + 10;
vector<int>lg(100);
vector<vector<int>>dp(LOG + 1, vector<int>(100));
vector<vector<int>>st(LOG + 1, vector<int>(100));
// space complexity O(nlogn) , Time complexity O(1) for min query o(logn) for sum query
int main()
{
	int n; cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		dp[0][i] = v[i];
		st[0][i] = v[i];
	}
	for (int i = 2; i <= 100; ++i) {
		lg[i] = lg[i / 2] + 1;
	}
	for (int i = 1; i <= LOG; ++i) {
		for (int  j = 0; j + (1 << i) - 1 <= n; ++j) {

			dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
			st[i][j] = st[i - 1][j] + st[i - 1][j + (1 << (i - 1))];
		}
	}
	auto querysum = [&](int l, int r)->int{
		int sum = 0;
		for (int i = LOG; i >= 0; i--) {
			if ((1 << i) <= r - l + 1) {
				sum += st[i][l];
				l += 1 << i;
			}
		}
		return sum;
	};
	auto querymin = [&](int l, int r)->int{
		int k = lg[r - l + 1];
		return min(dp[k][l], dp[k][r - (1 << k) + 1]);
	};
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		l--, r--;
		cout << querysum(l, r) << " " << querymin(l, r) << endl;
	}
}



















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
const int mod = 1e9 + 7, inf = LONG_LONG_MAX, N = 1e6;

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


const int LOG = 20;
void __solve() {

	int n; cin >> n;
	vector<vector<pair<int, int>>>sparse(LOG, vector<pair<int, int>>(n + 1));
	vi v(n), lg(n + 1);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sparse[0][i].first = sparse[0][i].second = v[i];
	}
	for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
	for (int i = 1; i <= LOG; i++) {
		for (int j = 0; j + (1 << i) - 1 < n; ++j) {
			sparse[i][j].first = min(sparse[i - 1][j].first, sparse[i - 1][j + (1 << (i - 1))].first);
			sparse[i][j].second = max(sparse[i - 1][j].second, sparse[i - 1][j + (1 << (i - 1))].second);

		}
	}
	auto query = [&](int l, int r)->pair<int, int> {
		int k = lg[r - l + 1];
		return {min(sparse[k][l].first, sparse[k][r - (1 << k) + 1].first), max(sparse[k][l].second, sparse[k][r - (1 << k) + 1].second)};
	};
	int i = 0, j = n - 1;
	while (i < j) {
		auto [mn, mx] = query(i, j);
		if (mn != v[i] and mx != v[i] and mn != v[j] and mx != v[j]) {
			cout << i + 1 << " " << j + 1;
			return;
		}
		if (mn == v[i] or mx == v[i]) i++;
		if (mn == v[j] or mx == v[j]) j--;
	}
	cout << -1;



}



/*============================================= MAIN =============================================*/

signed  main()
{
	Md_Nihal;
	int testcases = 1;    cin >> testcases;
	for (int i = 1; i <= testcases; ++i, cout << endl) __solve();
}
