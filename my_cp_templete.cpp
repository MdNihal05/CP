#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,fma")
#define Md_Nihal ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define mod9 1e9+7
#define endl "\n"
#define int long long
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vs vector<string>
#define all(x) x.begin(),x.end()

template<typename typC, typename typD> istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }
template<typename typC> istream &operator>>(istream &cin, vector<typC> &a) { for (auto &x : a) cin >> x; return cin; }


#ifndef ONLINE_JUDGE
#include "debug.h"
#define _print_testcase(x) cout<<"Test Case # "<<x<<endl;
#else
#define debug(x...);
#define _print_testcase(x...);
#endif
/**************************************************************************************************/



void solve() {
    
}



/**************************************************************************************************/
signed   main()
{
    Md_Nihal;
    int testcases = 1, i = 0;     cin >> testcases;
    while ((i++) < testcases) {
        _print_testcase(i) ; solve() ;
        cout << endl;
    }
}
