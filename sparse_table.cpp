#include<bits/stdc++.h>
using namespace std;
const int LOG = 17, N = 1e5 + 10;
vector<int>lg(100);
vector<vector<int>>dp(100, vector<int>(LOG + 1));
// space complexity O(nlogn) , Time complexity O(1)
int main()
{
	int n; cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		dp[0][i] = v[i];
	}
	for (int i = 2; i <= 100; ++i) {
		lg[i] = lg[i / 2] + 1;
	}
	for (int i = 1; i <= LOG; ++i) {
		for (int  j = 0; j + (1 << i) - 1 <= n; ++j) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
		}
	}
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; ++j) cout << dp[i][j] << " ";
		cout << endl;
	}
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		l--, r--;
		int k = lg[r - l + 1];
		cout << max(dp[k][l], dp[k][r - (1 << k) + 1]) << endl;
	}
}
