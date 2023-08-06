#include<bits/stdc++.h>
using namespace std;
template<typename typC> ostream &operator<<(ostream &cout,unordered_map<typC,typC> &a) { cout<<endl;for (auto &x:a) cout<<"[ "<<x.first<<" , "<<x.second<<" ]"<<endl; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,map<typC,typC> &a) {cout<<endl; for (auto &x:a) cout<<"[ "<<x.first<<" "<<x.second<<" ]"<<endl; return cout; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) {return cout<<"[ "<<a.first<<" , "<<a.second<<" ]"; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD> > &a) { for (auto &x:a) cout<<x<<endl; return cout; }
template<typename T> ostream &operator<<(ostream &ostream,vector<vector<T>>&v){for(auto &i:v){for(auto &j:i) cout<<j<<" ";cout<<endl;}return ostream;}
template<typename typC> ostream &operator<<(ostream &cout,vector<typC> &a) { for (auto &x:a) cout<<x<<" "; return cout; }
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
void __print(int x) {cout << x <<" ";}
void __print(unsigned x) {cout << x<<" ";}
void __print(pair<int,int> &x) {cout<<x.first<<" "<<x.second<<" ";}
void __print(unsigned long x) {cout << x<<" ";}
void __print(unsigned long long x) {cout << x<<" ";}
void __print(float x) {cout << x<<" ";}
void __print(double x) {cout << x<<" ";}
void __print(long double x) {cout << x<<" ";}
void __print(char x) {cout << '\'' << x << '\''<<" ";}
void __print(const char *x) {cout << '\"' << x << '\"'<<" ";}
void __print(const string &x) {cout << '\"' << x << '\"'<<" ";}
void __print(bool x) {cout << (x ? "true" : "false")<<" ";}
void __print(vector<int>&v) {cout<<v;}
void __print(vector<pair<int,int>>&v) {cout<<v;}
void __print(unordered_map<int,int>&m){cout<<m;}
void __print(map<int,int>&m){cout<<m;}
#define debug(x...) cout << #x << " = [ "; __print(x); cout<<"]"; cout<<endl;
