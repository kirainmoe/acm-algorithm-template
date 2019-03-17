long long mod_power(long long a, long long n, long long mod) {
    long long ans = 1, base = a;
    while (n) {
        if (n & 1) {
            ans *= base % mod;
        }
        base = base * base % mod;
        n >>= 1;
    }
    return ans;
}
