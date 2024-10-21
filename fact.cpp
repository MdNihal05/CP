vector<ll> fact (N), inv_fact (N);


ll power (ll x, ll y) {
    ll res = 1;

    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % MOD;
        }

        x = (x * x) % MOD;
        y /= 2;
    }

    return res;
}


ll solve (int n, int k) {
    if (k > n || k < 0) return 0;

    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}
auto pre = []() {
    fact[0] = 1;

    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    inv_fact[N - 1] = power (fact[N - 1], MOD - 2);

    for (int i = N - 2; i >= 0; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
    return 0;
}();
