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
const int inf = LONG_LONG_MAX;


template<typename typC, typename typD> istream &operator>>(istream &cin, pair<typC, typD> &a) {
    return cin >> a.first >> a.second;
}
template<typename typC> istream &operator>>(istream &cin, vector<typC> &a) {
    for (auto &x : a) cin >> x;
    return cin;
}
template <class ...Args> auto &getm(Args &...args) {
    return (cin >> ... >> args);
}
#define get(...) __VA_ARGS__; getm(__VA_ARGS__)


#ifndef ONLINE_JUDGE
#include "/home/anonymous/nihal/others/CP/constest/debug.hpp"
#else
#define debug(x...);
#endif
vector<int> segtree;

void build(int s, int e, int i, vector<int> &a)
{
    if (s == e)
    {
        segtree[i] = a[s];
        return;
    }
    int mid = s + (e - s) / 2;
    build(s, mid, 2 * i + 1, a);
    build(mid + 1, e, 2 * i + 2, a);
    segtree[i] = __gcd(segtree[2 * i + 1] , segtree[2 * i + 2]); // change 
}

int range(int s, int e, int i, int qs, int qe)
{
    if (qs <= s && qe >= e)
        return segtree[i];
    if (qs > e || qe < s)
        return INT_MIN;
        /*------change--------*/
        //for and,min ->INT_MAX
        //for sum, xor,gcd -> 0
        //for max ->INT_MIN
        
    int mid = s + (e - s) / 2;
    int l = range(s, mid, 2 * i + 1, qs, qe);
    int r = range(mid + 1, e, 2 * i + 2, qs, qe);
    return __gcd(l,r);  //change 
}


/*=========================================== SOLUTION ===========================================*/



void solve() {

    int n;
    cin >> n;
    vi v(n);
    cin >> v;
    int q;
    cin >> q;
    segtree.resize(4 * n);
    build(0, n - 1, 0, v);
    while(q--) {
        int l,r;
        cin>>l>>r;
        cout<<range(0,n-1,0,l,r)<<endl;
    }

}



/*============================================= MAIN =============================================*/

signed   main()
{
    Md_Nihal;
    int testcases = 1, i = 0;
    cin >> testcases;
    while ((i++) < testcases) {
        solve() ;
        cout << endl;
    }
}
