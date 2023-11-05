class SegmentTree {
    typedef int T;
    static constexpr T unit = 0;        //change this {INT_MAX,INT_MIN,0}
    T fun(T a, T b) { return a + b; } // (any associative fn)
    vector<T> s; int n;
public:
    SegmentTree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = fun(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = fun(ra, s[b++]);
            if (e % 2) rb = fun(s[--e], rb);
        }
        return fun(ra, rb);
    }
};
