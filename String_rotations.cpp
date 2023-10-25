// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/1703/E
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



void __solve() {

	int n; cin >> n;
	vector<vector<char>> a(n, vector<char>(n));
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
			char c;
			cin >> c;
			a[j][k] = c - '0';
		}
	}
	int ans = 0;
	for (int i = 0; i < (n + 1) / 2; i++) {
		for (int j = 0; j < n / 2; ++j) {
			vector<char>vc;
			vc.push_back(a[i][j]);
			vc.push_back(a[n - j - 1][i]);
			vc.push_back(a[j][n - i - 1]);
			vc.push_back(a[n - i - 1][n - j - 1]);
			sort(all(vc));
			for (auto &i : vc) {
				ans += vc.back() - i;
			}
		}
	}
	cout << ans;
}



/*============================================= MAIN =============================================*/

signed  main()
{
	Md_Nihal;
	int testcases = 1;    cin >> testcases;
	for (int i = 1; i <= testcases; ++i, cout << endl) __solve();
}


































// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/1703/E
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



void __solve() {

	int n; cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
			char c;
			cin >> c;
			a[j][k] = c - '0';
		}
	}
	int ans = 0;
	for (int i = 0; i < (n + 1) / 2; i++) {
		for (int j = 0; j < n / 2; ++j) {
			int ch = a[i][j] + a[j][n - i - 1] + a[n - i - 1][n - j - 1] + a[n - j - 1][i];
			ans += min(ch, 4 - ch);
		}
	}
	cout << ans;
}



/*============================================= MAIN =============================================*/

signed  main()
{
	Md_Nihal;
	int testcases = 1;    cin >> testcases;
	for (int i = 1; i <= testcases; ++i, cout << endl) __solve();
}
