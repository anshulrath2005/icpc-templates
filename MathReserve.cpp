#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define mod 1000000007LL
#define int long long

//power 
    // with modulo
    int power(int a, int b, int m) {
        if (b == 0) return 1 % m;
        int p = power(a, b / 2, m);
        p = p * p % m;
        if (b % 2 == 1) p = p * a % m;
        return p;
    }
    // without modulo
    int power(int a, int b) {
        if (b == 0) return 1;
        int p = power(a, b / 2);
        p = p * p;
        if (b % 2 == 1) p = p * a;
        return p;
    }

//inverse wrt modulo
    int inverse(int x) {
        return power(x, mod-2,mod);
    }

// factorial-- check for precomputed factorial in the end of ncr
    //normal
    int fact(int x) {
        int ans = 1;
        for(int i=2; i<=x; i++) {
            ans = (ans * i) % mod;
        }
        return ans;
    }

//ncr
    //if n<=10^9 and r<=20 use this -
    int single_ncr(int n, int r) {    // O(r)
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);
        int num = 1, den = 1;
        for(int i=1; i<=r; i++) {
            num = (num * (n-i+1)) % mod;
            den = (den * i) % mod;
        }
        return (num * inverse(den)) % mod;
    }
    //if n<= 40 and r<=n use this(n consec prod is div by n ) - like we wont put mod cuz long long can handle these and wont overflow..
    int basic_ncr(int n, int r) { // hence since we wont have mod we need not take inverse so no need to do in the previous method
        int ans = 1;
        for(int i=1; i<=r; i++) {
            ans = ans * (n-i+1);
            ans = ans / i;
        }
        return ans;
    }
    
    //approach4 : pascals triangle recursive approach - if we have to do mod 1e9 which isnt prime so inverse doesnt exist so we cant do division operation
    int ncr[1001][1001];    // Stores Pascal's triangle
    //changed the following a bit to precompute values:
     void ncr_random_modulo(int n) {
        ncr[0][0] = 1;    
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=i; j++) {
                if(j == 0) ncr[i][j] = ncr[i-1][j] % mod;
                else ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % mod;
            }
        }
    }

    //Most common method used -TC (per query) : O(log(mod))
        int fact[1000100];
        int precompute() {
            fact[0] = 1;
            for(int i=1; i<=1000000; i++) {
                fact[i] = (fact[i-1] * i) % mod;
            }
        }

        int ncr_fact(int n, int r) {    // O(log(mod))
            int num = fact[n];
            int den = (fact[n-r] * fact[r]) % mod;
            return (num * inverse(den)) % mod;
        }

    //only works if n,q,r <= 10^6 // THE BELOW METHOD IS MANILY USED WHEN WE WILL HAVE MULTIPLE QUERIES
    int invfact[1000100];
    void precompute_for_faster() {    // O(n) + O(log(mod)) + O(n) ~ O(n + log(mod))
        fact[0] = 1;
        for(int i=0; i<=1000000; i++) {
            fact[i] = (fact[i-1] * i) % mod;
        }
        invfact[1000000] = inverse(fact[1000000]);
        for(int i=1000000; i>=1; i--) {
            invfact[i-1] = (invfact[i] * i) % mod;
        }
    }

    int ncr_fact_faster(int n, int r) {    // O(1)
        int num = fact[n];
        int den = (invfact[n-r] * invfact[r]) % mod;
        return (num * den) % mod;    // den is already inverted
    }

// dearrangements - O(2^N)implementation:
long long derangement(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    return (n - 1) * (derangement(n - 1) + derangement(n - 2));
}
//dearrangements - dp implementation:O(N)
long long der[1000001]; // DP array

void compute_derangements(int N, int MOD = mod) {
    der[1] = 0, der[2] = 1;
    for (int i = 3; i <= N; i++) {
        der[i] = ((i - 1) * (der[i - 1] + der[i - 2])) % MOD;
    }
}

// gcd TC:O(log(min(a,b)))
int gcd(int a, int b) { // or can be done by stl's __gcd();
    if (a == 0) return b;
    return gcd(b % a, a);
}

// checking if a number is prime: works for n <= 10^12
bool is_prime(long long x) {
    for(long long i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}
// Finding all the divisors of a number :
vector<long long> divisors(long long x) {
    vector<long long> ans;
    for(long long i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            ans.push_back(i);
            if(i*i != x)
                ans.push_back(x/i);
        }
    }
    return ans;
}
// Prime factorization of a number:TC is O(root N)
using ii = pair<long long, long long>;

vector<ii> Factors(long long x) {
    vector<ii> ans;
    for(long long i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            int cnt = 0;
            while(x % i == 0) {
                cnt++;
                x /= i;
            }
            ans.push_back({i, cnt});
        }
    }
    if(x > 1) ans.push_back({x, 1}); // x is a prime > sqrt(N)
    return ans;
}

// Sieve of Eratosthenes ALL prime nos till 10^7; O(loglogN)
vector<int> sieve(int n) {
    vector<int> primes;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i=2; i<=n; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j=1LL*i*i; j<=n; j+=i) {
                is_prime[j] = false;
            }
        }
    }

    return primes;
}
// segmented sieve - TC: O(b^0.5loglogb^0.5)+O((b−a)loglogb)
vector<int> segmented_sieve(int L, int R) {
    // Phase 1 : use sieve to precompute primes in range [1...sqrt(R)] as base primes
    vector<int> base_primes = sieve(ceil(sqrt(R)));

    // Phase 2 : sieve the range [L...R] using the primes found in range [1...sqrt(R)]
    vector<bool> is_prime(R-L+1, true);
    if(L == 1) is_prime[0] = false;

    for(auto prime:base_primes) {
        int ceil_l_by_p = (L + prime - 1) / prime;
        int cur_mul = prime * ceil_l_by_p;
        cur_mul = max(prime * prime, cur_mul);

        while(cur_mul <= R) {
            is_prime[cur_mul-L] = false;
            cur_mul += prime;
        }
    }

    vector<int> primes_l_to_r;
    for(int i=0; i<R-L+1; i++) {
        if(is_prime[i]) {
            primes_l_to_r.push_back(i+L);
        }
    }

    return primes_l_to_r;
}
vector<int> sp(1e5+1);
//USING SPF Array for O(logx) prime factorization:
for (int i = 2; i <= N; i++) {
    sp[i] = i; // Initially assume each number is prime
}

for (int i = 2; i <= N; i++) {
    if (sp[i] == i) { // i is prime
        for (int j = i * i; j <= N; j += i) {
            if (sp[j] == j) {
                sp[j] = i; // set the smallest prime factor
            }
        }
    }
}
vector<int> primeFact(int x) {
    vector<int> ans;
    while (x > 1) {
        ans.push_back(sp[x]);
        x /= sp[x];
    }
    return ans;
}
