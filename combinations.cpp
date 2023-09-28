namespace combi {
    using ll = long long;
    const int MAXN = 1000005; // Adjust the maximum value of n as needed
    const ll MOD = 1000000007; // Change the MOD value as needed
    ll fac[MAXN], inv[MAXN], finv[MAXN];

    ll power(ll b, ll n) {
        ll result = 1;
        b %= MOD;
        while (n > 0) {
            if (n % 2 == 1) {
                result = (result * b) % MOD;
            }
            b = (b * b) % MOD;
            n /= 2;
        }
        return result;
    }

    void init(int n) {
        fac[0] = fac[1] = 1;
        inv[0] = inv[1] = 1;
        finv[0] = finv[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            fac[i] = (fac[i - 1] * i) % MOD;
            inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
            finv[i] = (finv[i - 1] * inv[i]) % MOD;
        }
    }

    ll C(ll x, ll y) {
        if (x < 0 || y > x) {
            return 0;
        }
        return (fac[x] * ((finv[y] * finv[x - y]) % MOD)) % MOD;
    }

    ll Inv(int x) {
        return power(x, MOD - 2);
    }
};
