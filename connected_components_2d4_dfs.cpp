#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#define Md_Nihal ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod9 1e9+7
#define endl "\n"
#define all(x) x.begin(),x.end()
#define ll long long
vector<int> dx = { -1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
int n, m, ans = 0, sum;
void dfs(vector<vector<int>>& lake, int i, int j) {
    sum += lake[i][j];
    lake[i][j]=0;

    for (int k = 0; k < 4; k++) {
        int r = i + dx[k];
        int c = j + dy[k];
        if (r<n and r >= 0 and c<m and c >= 0 and lake[r][c] != 0) {
            dfs(lake, r, c);
        }
    }
}
void solve() {
    cin >> n >> m;
    ans=0;
    vector<vector<int>>lake(n, vector<int>(m));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> lake[i][j];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(lake[i][j]) {
                sum=0;
                dfs(lake, i, j);
                ans=max(ans,sum);
            }
        }
    }
    cout << ans;

}


signed main()
{
    Md_Nihal;
    int testcases = 1, i = 0;   cin >> testcases;
    while ((i++) < testcases) {
        //cout<<"case# : "<<testcases<<endl;
        solve() ;
        cout << endl;
    }
}
