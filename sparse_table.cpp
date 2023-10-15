#include<bits/stdc++.h>
using namespace std;
const int LOG = 17, N = 1e5 + 10;
vector<int>lg(100);
vector<vector<int>>dp(LOG + 1, vector<int>(100));
vector<vector<int>>st(LOG + 1, vector<int>(100));
// space complexity O(nlogn) , Time complexity O(1)
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
