#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// Aliases
#define int long long
using ll=long long;
using ld=long double;
using i32=int32_t;
using u32=unsigned int;
using u64=unsigned long long;
using i128=__int128;
using u128=unsigned __int128;
 
using pii=pair<int,int>;
using pll=pair<ll,ll>;
 
template<typename T> using vc=vector<T>;
template<typename T> using vvc=vc<vc<T>>;
template<typename T> using vvvc=vc<vvc<T>>;

using mii = map<int,int>;
using vi=vc<int>;
using vll=vc<ll>;
using vvi=vc<vi>;
using vvll=vc<vll>;
using pqb = priority_queue<int>;
using pqs = priority_queue<int,vi,greater<int>>;

// Constants
constexpr int MAX_N = 1e5 + 5;
constexpr int MAX_N2 = 1e6 + 5;
constexpr ll MOD = 1e9 + 7;
constexpr ll MOD2 = 998244353;
constexpr int INF = INT_MAX;
constexpr ll INFL = LLONG_MAX;
constexpr ld EPS = 1e-9;

// Macros
#define fastio                     \
    ios::sync_with_stdio(false);   \
    cin.tie(nullptr);              

#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define maxe(a) *max_element(all(a))
#define mine(a) *min_element(all(a))
#define maxp(a) max_element(all(a)) - a.begin()
#define minp(a) min_element(all(a)) - a.begin()
#define sum(a) accumulate(all(a), 0LL)
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
 
#define setbits(x) __builtin_popcountll(x)
#define mid(a,b,c) ((a>=b && a<=c) || (a>=c && a<=b) ? a : (b>=a && b<=c) || (b>=c && b<=a) ? b : c)
 
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define ff first
#define ss second
#define mp make_pair

#define gc getchar_unlocked

#define fi(i, a, b) for (ll i = (a); i < (b); i++)
#define fd(i, a, b) for (ll i = (a); i >= (b); i--)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
 
#define yn(x) cout << (x ? "YES\n" : "NO\n")
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define Yn(x) cout << (x ? "Yes\n" : "No\n")
#define Yes cout << "Yes\n"
#define No cout << "No\n"

#define ps(x,y) fixed<<setprecision(y)<<x
#define w(x) int x; cin>>x; while(x--)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// Custom hash map
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T1, typename T2> // Key should be integer type
using safe_map = unordered_map<T1, T2, custom_hash>;

// cin >> pair<T1, T2>
template <typename T1, typename T2>
istream& operator>>(istream& istream, pair<T1, T2>& p)
{
    return (istream >> p.first >> p.second);
}

// cin >> vector<T>
template <typename T> 
istream& operator>>(istream& istream, vector<T>& v)
{
    for (auto& it : v)
        cin >> it;
    return istream;
}

// cout << pair<T1, T2>
template <typename T1, typename T2>
ostream& operator<<(ostream& ostream, const pair<T1, T2>& p)
{
    return (ostream << p.first << " " << p.second);
}

// cout << vector<T>
template <typename T> 
ostream& operator<<(ostream& ostream, const vector<T>& c)
{
    for (auto& it : c)
        cout << it << " ";
    return ostream;
}

// Returns the size in 32-bit signed integer
template <typename T>
int32_t size_i(T& container) { return static_cast<int32_t>(container.size()); }

// Extended Euclidean Algorithm
int gcd_extended(int a, int b, int& x, int& y)
{
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int lcm(int a, int b)
{
    return ((ll)a * b) / __gcd(a, b);
}

// Modular Exponentiation \
Returns a^b mod m
ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// Modular inverse \
x * x_inv ≡ 1 mod m
int modinv(int x, int m = MOD)
{
    return binpow(x, m - 2, m);
}

mt19937 rng; // Mersenne Twister type Random number generator
int getRandomNumber(int l, int r)
{   
    uniform_int_distribution<int> dist(l, r);
    return dist(rng);
}
void preSolve()
{
    // Initializes the random number generator with a seed based on the current time.
    rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
    // allocateStackMax();
}

void precompute() {
 
}

void solve(){
    
}

signed main(){
    fastio;
    cout << setprecision(12) << fixed;
    preSolve();    precompute();

    int tests = 1;
    cin >> tests;
    
    while(tests--){
        solve();
    }

    return 0; 
}