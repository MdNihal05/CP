vector<int> primes(sp , 1);
void sieve() {
    primes[1] = 0;
    primes[0] = 0;
    for (ll i = 2; i * i <= sp; i++) {
        if (primes[i] == 1) {
            for (ll j = i * i; j <= sp; j += i) {
                primes[j] = 0;
            }
        }
    }
}
