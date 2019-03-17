#include <stdio.h> 
#include <string.h>
#include <math.h>
#define MAXN 10000

typedef struct Double_Hash {
    unsigned long long hash1, hash2;
} Double_Hash;

unsigned long long hash[MAXN], hash2[MAXN];

int idx(char x) {
    return x - 'a' + 1;
}

// natural overflow hash
unsigned long long overflow_hash(char str[], unsigned long long p) {
    int len = strlen(str), i;
    hash[0] = idx(str[0]);
    for (i = 1; i < len; i++) {
        hash[i] = hash[i - 1] * p + idx(str[i]);
    }
    return hash[len - 1];
}

// p and mod should be primes, p < mod
unsigned long long single_hash(char str[], unsigned long long p, unsigned long long mod) {
    int len = strlen(str), i;
    hash[0] = idx(str[0]) % mod;
    for (i = 1; i < len; i++) {
        hash[i] = hash[i - 1] * p + idx(str[i]) % mod;
    }
    return hash[len - 1];
}

Double_Hash double_hash(char str[], unsigned long long p,
                               unsigned long long mod1, unsigned long long mod2) {
    int len = strlen(str), i;
    hash[0] = idx(str[0]) % mod1;
    hash2[0] = idx(str[0]) % mod2;
    for (i = 1; i < len; i++) {
        hash[i] = hash[i - 1] * p + idx(str[i]) % mod1;
        hash2[i] = hash2[i - 1] * p + idx(str[i]) % mod2;
    }
    Double_Hash t;
    t.hash1 = hash[len - 1], t.hash2 = hash2[len - 1];
    return t;
}

// get the hash of subsequence [l, r]
unsigned long long subsequence_hash(int left, int right, long long p, long long mod) {
    // return hash[right] - hash[left - 1] * pow(p, right - left + 1);
    return ((unsigned long long)(hash[right] - hash[left - 1] * pow(p, right - left + 1)) % mod + mod) % mod;
}

int main() {
    return 0;
}
