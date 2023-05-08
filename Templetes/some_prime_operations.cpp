//after this sieve:
// min_prime[x] = p > 0 means p is the smallest prime that divides x
// min_prime[x] = -1 means x is a prime
// min_prime[x] = -2 means x is either 0 or 1
const int N = 1e6+17;
int min_prime[N];
void sieve(int n) {
    memset(min_prime, -1, sizeof(min_prime));
    min_prime[0] = min_prime[1] = -2;
    for (int i = 2; i * i < n; i++) {
        if (min_prime[i] == -1) {
            for (int j = i * i; j < n; j += i)
                min_prime[j] = i;
        }
    }
}
