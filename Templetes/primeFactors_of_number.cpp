vector<int> primeFactor(int n) {
    vector<int> a;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            a.push_back(i);
            n /= i;
        }
    }
    if (n > 1)a.push_back(n);
    return a;
}
