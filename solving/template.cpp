// author: logemi

#pragma GCC diagnostic ignored "-Wc++11-extensions"
#pragma GCC diagnostic ignored "-Wc++17-extensions"
#ifdef __DEBUG__
    #pragma GCC optimize("O0,trapv")
    #include "../libdebug.cpp"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #ifdef __x86_64__
        #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
    #endif
    #define debug(x) ;
    #define debugarr(x,n) ;
#endif
#ifdef __clang__
    #include <cstdio>
    #include <ostream>
    #include <cstdint>
    #include <climits>
    #include <iostream>
    #include <map>
    #include <unordered_map>
    #include <set>
    #include <unordered_set>
    #include <vector>
    #include <queue>
    #include <deque>
    #include <algorithm>
    #include <numeric>
    #include <functional>
    #include <iomanip>
#else
    #include <bits/stdc++.h>
#endif
using namespace std;
typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ld> pdd;
#define hashmap unordered_map;
#define hashset unordered_set;
#define x first
#define y second
#define pushb push_back
#define pushf push_front
#define popb pop_back
#define popf pop_front
#define ins insert
#define bg begin
#define all(a) begin(a), end(a)
#define sz(a) ((a).size())
#define len(a) ((a).length())
#define mp make_pair
#define INF LLONG_MAX
#define PI 3.1415926535897932384626433832795l
#define MOD 1000000007ll
#define FORI(x,n) for(ll i=(x);i<(n);i++)
#define FORJ(x,n) for(ll j=(x);j<(n);j++)
#define FORH(x,n) for(ll h=(x);h<(n);h++)
#define FORK(x,n) for(ll k=(x);k<(n);k++)
#define FORL(x,n) for(ll l=(x);l<(n);l++)
#define FORR(x,n) for(ll r=(x);r<(n);r++)
#define FOR(k,x,n) for(ll (k)=(x);(k)<(n);(k)++)
#define bflip(a,b) ((a)^=(1ull)<<(b))
#define bset(a,b) ((a)|=(1ull)<<(b))
#define bclear(a,b) ((a)&=~(1ull)<<(b))
#define bcheck(a,b) (!!((a)&(1ull<<(b))))
void yes() {cout << "YES" << "\n";}
void no() {cout << "NO" << "\n";}
#define newl "\n"
__attribute__ ((const)) ld diste(const pdd a,const pdd b) {return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));}
__attribute__ ((const)) ld distm(const pdd a,const pdd b) {return abs(a.x-b.x)+abs(a.y-b.y);}
__attribute__ ((const)) ld diste(const pii a,const pii b) {return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));}
__attribute__ ((const)) ll distm(const pii a,const pii b) {return abs(a.x-b.x)+abs(a.y-b.y);}
template<typename T> __attribute__ ((const)) T _gcd_internal(const T a, const T b) {
    if (b == 0) return a;
    return _gcd_internal(b, a%b);
}
template<typename T> __attribute__ ((const)) T gcd(const T a, const T b) {
    if (a > b) return _gcd_internal(a,b);
    if (a < b) return _gcd_internal(b,a);
    return a;
}
template<typename T> __attribute__ ((const)) T lcm(const T a, const T b) {
    return a * (b/gcd(a,b));
}
void extended_gcd(ll a, ll b, ll* x, ll* y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return;
    }
    ll x_, y_;
    extended_gcd(b%a, a, &x_, &y_);
    *x = y_ - x_*(b/a);
    *y = x_;
}
__attribute__ ((const)) ll mod_inv(const ll a, const ll m) {
	ll x, y;
    extended_gcd(a, m, &x, &y);
    x = (1 - y*m) / a;
    if (x < 0) {
        return x + m*(1+ abs(x)/m);
    } else {
        return x % m;
    }
}
__attribute__ ((const)) const array<array<ll,63>,20> gen_ipow() {
    array<array<ll,63>,20> arr;
    fill(arr[0].begin(), arr[0].end(), 0ll);
    fill(arr[1].begin(), arr[1].end(), 1ll);

    for (ll i = 2; i <= arr.size(); i++) {
        ll acc = 1;
        arr[i][0] = 1;
        for (ll j = 1; LLONG_MAX / acc >= i; j++) {
            acc *= i;
            arr[i][j] = acc;
        }
    }

    return arr;
}
static const array<array<ll,63>,20> _ipow = gen_ipow();
__attribute__ ((pure)) ll ipow(ll b, ll e) {
    if (b < _ipow.size()) return _ipow[b][e];
    ll r = 1;
    while (e) {
        if (e & 1) r *= b;
        b *= b; e >>= 1;
    }
    return r;
}
template<typename T>
__attribute__ ((const)) pair<vector<T>, vector<bool> > get_primes(const ll n) {
    vector<bool> sieve(n+1, true);
    vector<T> primes;
    primes.reserve(1.1l*n/log((ld)n));
    sieve[0] = false;
    sieve[1] = false;
    for (int i = 2; i < n+1; i++) {
        if (!sieve[i]) continue;
        sieve[i] = true;
        primes.push_back(i);
        for (int x = 2*i; x < n+1; x += i) sieve[x] = false;
    }
    return make_pair(primes, sieve);
}
template<typename T>
__attribute__ ((const)) multiset<T> prime_fact(const ll x, const vector<T> &primes) {
    multiset<T> fact;
    ll max_p = 1+sqrt(x);
    for (T p: primes) {
        if (p >= max_p) break;
        if (x % p == 0) {
            fact.insert(p);
            if (x/p >= max_p) fact.merge(prime_fact(x/p, primes));
        }
    }
    return fact;
}
template<class T, class Compare = less_equal<T> >
int inversions(T arr[], const int l, const int r) {
    if (l == r-1) return 0;
    int inv = 0, mid = (l+r)/2;
    inv += inversions(arr, l, mid);
    inv += inversions(arr, mid, r);
    int szl = mid-l, szr = r-mid;
    T left[szl], right[szr];
    memcpy(left, arr+l, szl*sizeof(T));
    memcpy(right, arr+mid, szr*sizeof(T));
    int x = 0, y = 0, i = l;
    Compare cmp;
    while (x < szl && y < szr) {
        if (cmp(left[x], right[y])) {
            arr[i] = left[x];
            x++;
        } else {
            arr[i] = right[y];
            inv += szl - x;
            y++;
        }
        i++;
    }
    while (x < szl) {
        arr[i] = left[x];
        i++; x++;
    }
    while (y < szr) {
        arr[i] = right[y];
        i++; y++;
    }
    return inv;
}

//     SOLUTION GOES HERE
//----------------------------------------------------------------------------------

/* <--- Notes --->



*/

void _preprocess_() {}

void _solve_test_case_() {

}

#define USE_TEST_CASES

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    _preprocess_();
    #ifdef USE_TEST_CASES
        int tt;
        cin >> tt;
        while (tt--) {
            _solve_test_case_();
        }
    #else
        _solve_test_case_();
    #endif
    return 0;
}
