#include "bits/stdc++.h"
using namespace std;
#define all(x) x.begin(),x.end()
#define ALL(x) x.rbegin(),x.rend()
#define int long long
const int mod = 1e9 + 7, MAX = 1e7 + 7, N = 1e5 + 5;

#ifndef ONLINE_JUDGE
    #include "/home/anonymous/Templates/debug.hpp"
#else
    #define debug(x...);
#endif

/*=========================================== SOLUTION ===========================================*/

void __solve() {
    int n, q; cin >> n >> q;
    vector<int>a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    multiset<int>mnset, mxset;
    vector<int>ans(n + 1);
    int sum1 = 0, sum2 = 0;

    for (int i = 1; i <= n; i++) {
        mxset.insert(a[i - 1]);
        sum1 += a[i - 1];

        if (i % 2 == 0) continue;

        // remove elements from max set to min set
        while (mxset.size() > (i + 1) / 2) {
            int x = *mxset.begin();
            sum1 -= x, sum2 += x;
            mnset.insert(x);
            mxset.extract(x);
        }

        // remove elements from minset to max set
        while (mnset.size()  and * mxset.begin() < *mnset.rbegin()) {
            int x = *mxset.begin();
            int y = *mnset.rbegin();
            sum1 -= x, sum1 += y;
            sum2 -= y, sum2 += x;
            mxset.extract(x), mxset.insert(y);
            mnset.extract(y), mnset.insert(x);
        }

        ans[i] = sum1 - sum2;
    }

    while (q--) {
        int x; cin >> x;
        cout << ans[x] << " ";
    }
}

/*============================================= MAIN =============================================*/

int32_t main() {
    int T = 1;  cin >> T;

    for (int i = 0; i < T; i++, __solve(), cout << endl);
}

