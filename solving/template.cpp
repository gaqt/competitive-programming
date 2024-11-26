// author: logemi
// github.com/atomoxetine

#include <cassert>
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
#define debugarr(x, n) ;
#endif
#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pdd;
#define hashmap unordered_map
#define hashset unordered_set
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
#define FLOAT_THRESHOLD 0.00000001l
#define FORI(x, n) for (ll i = (x); i < (n); i++)
#define FORJ(x, n) for (ll j = (x); j < (n); j++)
#define FORH(x, n) for (ll h = (x); h < (n); h++)
#define FORK(x, n) for (ll k = (x); k < (n); k++)
#define FORL(x, n) for (ll l = (x); l < (n); l++)
#define FORR(x, n) for (ll r = (x); r < (n); r++)
#define bflip(a, b) ((a) ^= (1ull) << (b))
#define bset(a, b) ((a) |= (1ull) << (b))
#define bclear(a, b) ((a) &= ~(1ull) << (b))
#define bcheck(a, b) (!!((a) & (1ull << (b))))
void yes() { cout << "YES" << "\n"; }
void no() { cout << "NO" << "\n"; }
#define newl "\n"
/// wraps value between vmin and vmax
template <typename T> constexpr T wrap(T value, const T vmin, const T vmax) {
#define DIFF (vmax - vmin)
    if (value < vmin)
        value += DIFF * (T)ceil((ld)(vmin - value) / (ld)DIFF);
    else if (value > vmax)
        value -= DIFF * (T)ceil((ld)(value - vmax) / (ld)DIFF);

    return value;
}
template <typename T>
constexpr bool in_range(const T value, const T vmin, const T vmax) {
    return vmin < value && value < vmax;
}
constexpr bool float_eq(const ld a, const ld b) {
    return in_range(a, b - FLOAT_THRESHOLD, b + FLOAT_THRESHOLD);
}
struct vec2 {
    ld x;
    ld y;
    constexpr ld angle() const { return atan2((ld)y, (ld)x); }
    constexpr ld magnitude() const { return this->diste({0, 0}); }
    static constexpr vec2 from_polar(pdd polar) {
        return {.x = polar.y * cos(polar.x), .y = polar.y * sin(polar.x)};
    }
    constexpr pdd to_polar() const { return make_pair(angle(), magnitude()); }
    /// euclidean distance squared
    constexpr ld diste2(const vec2 other) const {
        return pow(x - other.x, 2) + pow(y - other.y, 2);
    }
    /// euclidean distance
    constexpr ld diste(const vec2 other) const { return sqrt(diste2(other)); }
    /// manhattan distance
    constexpr ld distm(const vec2 other) const {
        return abs(x - other.x) + abs(y - other.y);
    }
    constexpr vec2 scale(const ld factor) const {
        return {.x = x * factor, .y = y * factor};
    }
    constexpr vec2 rotate(const ld angle) const {
        pdd polar = to_polar();
        polar.first = wrap(polar.first + angle, 0.0l, PI * 2.0l);
        return from_polar(polar);
    }
    constexpr vec2 add(const vec2 other) const {
        return {.x = x + other.x, .y = y + other.y};
    }
    constexpr vec2 sub(const vec2 other) const {
        return {.x = x - other.x, .y = y - other.y};
    }
    constexpr vec2 operator+(const vec2 other) const { return add(other); }
    constexpr vec2 operator-(const vec2 other) const { return sub(other); }
    constexpr bool operator==(const vec2 other) const {
        return float_eq(x, other.x) && float_eq(y, other.y);
    }
    constexpr bool operator<(const vec2 other) const {
        return x < other.x ? true : float_eq(x, other.x) ? y < other.y : false;
    }
    constexpr bool operator>(const vec2 other) const {
        return x > other.x ? true : float_eq(x, other.x) ? y > other.y : false;
    }
};
/// manhattan distance (integers)
constexpr ll distmi(const pii a, const pii b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}
/// euclidean distance squared (integers)
constexpr ll diste2i(const pii a, const pii b) {
    return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}
/// euclidean distance (integers)
constexpr ld distei(const pii a, const pii b) { return sqrt(diste2i(a, b)); }
template <typename T> constexpr T _gcd_internal(const T a, const T b) {
    if (b == 0)
        return a;
    return _gcd_internal(b, a % b);
}
/// greatest common divisor of a and b
template <typename T> constexpr T gcd(const T a, const T b) {
    if (a > b)
        return _gcd_internal(a, b);
    if (a < b)
        return _gcd_internal(b, a);
    return a;
}
/// least common multiple of a and b
template <typename T> constexpr T lcm(const T a, const T b) {
    return a * (b / gcd(a, b));
}
void extended_gcd(ll a, ll b, ll *x, ll *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return;
    }
    ll x_, y_;
    extended_gcd(b % a, a, &x_, &y_);
    *x = y_ - x_ * (b / a);
    *y = x_;
}
/// modular inverse aka a^(-1) (mod m)
__attribute__((const)) ll mod_inv(const ll a, const ll m) {
    ll x, y;
    extended_gcd(a, m, &x, &y);
    x = (1 - y * m) / a;
    if (x < 0) {
        return x + m * (1 + abs(x) / m);
    } else {
        return x % m;
    }
}
/// generates integer exponentiation table
__attribute__((const)) const array<array<ll, 63>, 20> gen_ipow() {
    array<array<ll, 63>, 20> arr;
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
static const array<array<ll, 63>, 20> _ipow = gen_ipow();
/// fast integer exponentiation
constexpr ll ipow(ll b, ll e) {
    if (b < _ipow.size())
        return _ipow[b][e];
    ll r = 1;
    while (e) {
        if (e & 1)
            r *= b;
        b *= b;
        e >>= 1;
    }
    return r;
}
/// returns list of primes and the sieve
template <typename T>
__attribute__((const)) pair<vector<T>, vector<bool>> get_primes(const ll n) {
    vector<bool> sieve(n + 1, true);
    vector<T> primes;
    primes.reserve(1.1l * n / log((ld)n));
    sieve[0] = false;
    sieve[1] = false;
    for (int i = 2; i <= sqrt(n + 1); i++) {
        if (!sieve[i])
            continue;
        for (int x = i * i; x < n + 1; x += i)
            sieve[x] = false;
    }
    for (int i = 2; i < n + 1; i++) {
        if (sieve[i])
            primes.push_back(i);
    }
    return make_pair(primes, sieve);
}
/// returns true if x is prime
template <typename T>
constexpr bool is_prime(const ll x, const vector<T> &primes,
                        const vector<bool> &sieve) {

    if (x < sieve.size())
        return sieve[x];

    ll max_p = 1 + sqrt(x);
    for (T p : primes) {
        if (p > max_p)
            return true;
        if (x % p == 0)
            return false;
    }

    return true;
}
/// returns prime factorization of x
template <typename T>
constexpr multiset<T> prime_fact(ll x, const vector<T> &primes,
                                 const vector<bool> &sieve) {
    multiset<T> fact;
    ll max_p = 1 + sqrt(x);
    for (T p : primes) {
        if (p > max_p)
            break;
        while (x % p == 0) {
            fact.insert(p);
            x /= p;
        }
        max_p = 1 + sqrt(x);
    }

    if (is_prime(x, primes, sieve)) {
        fact.insert(x);
    }

    return fact;
}
/// counts number of inversions in T array
template <class T, class Compare = less_equal<T>>
constexpr int inversions(T arr[], const int l, const int r) {
    if (l == r - 1)
        return 0;
    int inv = 0, mid = (l + r) / 2;
    inv += inversions(arr, l, mid);
    inv += inversions(arr, mid, r);
    int szl = mid - l, szr = r - mid;
    T left[szl], right[szr];
    memcpy(left, arr + l, szl * sizeof(T));
    memcpy(right, arr + mid, szr * sizeof(T));
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
        i++;
        x++;
    }
    while (y < szr) {
        arr[i] = right[y];
        i++;
        y++;
    }
    return inv;
}

//     SOLUTION GOES HERE
//----------------------------------------------------------------------------------

/* <--- Notes --->



*/

inline void preprocess() {}

inline void test_case() {}

// #define INTERACTIVE
#define IGNORE_CSTDIO
#define USE_TEST_CASES

int main(void) {
#ifndef INTERACTIVE
    cin.tie(NULL);
#endif
#ifdef IGNORE_CSTDIO
    ios_base::sync_with_stdio(false);
#endif

    preprocess();
#ifdef USE_TEST_CASES
    int tt;
    cin >> tt;
    while (tt--) {
        test_case();
    }
#else
    test_case();
#endif

    return 0;
}
