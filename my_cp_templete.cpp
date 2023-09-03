#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,fma")
#define Md_Nihal ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


typedef unsigned long long ull;
#define endl "\n"
#define int long long
#define sz(a) (int)a.size()
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vs vector<string>
#define all(x) x.begin(),x.end()
const int mod = 1e9 + 7;
const int N = 1e6;


template<typename typC, typename typD> istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }
template<typename typC> istream &operator>>(istream &cin, vector<typC> &a) { for (auto &x : a) cin >> x; return cin; }
template <class ...Args> auto &getm(Args &...args) { return (cin >> ... >> args); }
#define get(...) __VA_ARGS__; getm(__VA_ARGS__)

#ifndef ONLINE_JUDGE
#include "/home/anonymous/nihal/others/CP/constest/debug.hpp"
#else
#define debug(x...);
#endif

/*=========================================== SOLUTION ===========================================*/



void solve() {

}



/*============================================= MAIN =============================================*/

signed   main()
{
	Md_Nihal;
	int testcases = 1, i = 0;    cin >> testcases;
	while ((i++) < testcases) {
		solve() ;
		cout << endl;
	}
}
