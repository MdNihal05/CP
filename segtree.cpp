#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
using namespace std;

struct SegmentTree {
    typedef int T;
    static constexpr T unit = 1;        //change this
    T f(T a, T b) { return a * b / max(1LL, __gcd(a, b)); } // (any associative fn)
    vector<T> s; int n;
    SegmentTree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};
int32_t main()
{
    int T = 1; cin >> T;
    while (T--) {

        int n; cin >> n;
        SegmentTree arr(n, 0);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            arr.update(i, x);
        }
        cout << arr.query(3, 5);

        cout << endl;

    }
}
